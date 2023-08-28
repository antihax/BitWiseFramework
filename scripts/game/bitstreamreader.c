/*
 * BitWise Framework
 * https://github.com/antihax/BitWiseFramework
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International (CC BY-ND 4.0)
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-nd/4.0/
 *
 */

/**
 * @class BitStreamReader
 *
 * This class is responsible for reading data into a bitstream.
 * It provides methods to read various types of data (like integers, floats, etc.) from the bitstream.

 * @brief A class for reading bits from a stream.
 */
class BitStreamReader {
	private int m_BitIndex = 0;
	private Serializer m_Context;
	private int m_Working;
	private int m_WorkingIndex;

	/**
	 * @brief Initializes a BitStreamReader object with the given Serializer context.
	 * @param _ctx The Serializer context to use for reading bits.
	 */
	void BitStreamReader(Serializer _ctx) {
		m_Context = _ctx;
		m_BitIndex = 0;
		m_WorkingIndex = -1; // Force a read on the first read.
	}

	void ~BitStreamReader() {
	}

	/**
	 * @brief Returns the current bit index.
	 * @return The current bit index.
	 */
	int GetIndex() {
		return m_BitIndex;
	}

	/**
	 * @brief Reads a boolean value from the bitstream.
	 * @param[out] value - The boolean value read from the bitstream.
	 * @return True if the boolean value was successfully read, false otherwise.
	 */
	bool ReadBool(out bool value) {
		return ReadUInt(value, 1);
	}

	/**
	 * @brief Reads an unsigned integer value from the bitstream.
	 * @param[out] value - The integer value read from the bitstream.
	 * @param[in] bits - The number of bits to read from the bitstream.
	 * @return true if the value was successfully read, false otherwise.
	 */
	bool ReadUInt(out int value, int bits) {
		if (bits > SIZE_OF_INT_BITS || bits <= 0) {
			return false;
		}

		int down = m_BitIndex % SIZE_OF_INT_BITS;
		int up = SIZE_OF_INT_BITS - down;
		int index = m_BitIndex / SIZE_OF_INT_BITS;

		// Get the next integer if we need to.
		if (m_BitIndex / SIZE_OF_INT_BITS != m_WorkingIndex) {
			if (!m_Context.Read(m_Working))
				return false;
			m_WorkingIndex = m_BitIndex / SIZE_OF_INT_BITS;
		}

		if (down == 0) {
			// Aligned.
			value = m_Working & ((1 << bits) - 1);
		} else if (down + bits <= SIZE_OF_INT_BITS) {
			// Unaligned but only in one integer.
			value = (m_Working >> down) & ((1 << bits) - 1);
		} else {
			// Unaligned between two integers.
			// Read ahead.
			int nextWorking;
			if (!m_Context.Read(nextWorking))
				return false;

			m_WorkingIndex = (m_BitIndex + bits) / SIZE_OF_INT_BITS;

			// Depack the value from the two integers.
			value = ((m_Working >> down) & ((1 << up) - 1)) | ((nextWorking & ((1 << (bits - up)) - 1)) << up);
			m_Working = nextWorking;
		}

		m_BitIndex += bits;

		return true;
	}

	/**
	 * @brief Reads a signed integer value from the bitstream.
	 * @param[out] value The integer value read from the bitstream.
	 * @param[in] bits The number of bits to read for the integer value.
	 * @return True if the integer value was successfully read, false otherwise.
	 */
	bool ReadSInt(out int value, int bits) {
		bool isNegative;
		if (!ReadBool(isNegative))
			return false;

		if (!ReadUInt(value, bits))
			return false;

		if (isNegative)
			value = -value;

		return true;
	}

	/**
	 * @brief Reads a ranged integer value from the bitstream.
	 * @param[out] value The integer value read from the bitstream.
	 * @param[in] min The minimum value for the integer.
	 * @param[in] max The maximum value for the integer.
	 * @return True if the integer value was successfully read, false otherwise.
	 */
	bool ReadRangedInt(out int value, int min, int max) {
		int bits = BitWiseHelpers.BitSize(max - min + 1);
		if (!ReadUInt(value, bits))
			return false;
		value += min;
		return true;
	}

	/**
	 * @brief Reads a half-precision floating-point value from the bit stream.
	 * @param[out] value The half-precision floating-point value read from the bit stream.
	 * @return True if the read operation was successful, false otherwise.
	 */
	bool ReadHalfFloat(out float value) {
		int v;
		if (!ReadUInt(v, 16))
			return false;
		value = BitWiseHelpers.HalfToFloat(v);
		return true;
	}

	/**
	 * @brief Reads a half vector from the bitstream.
	 * @param[out] value The vector to store the read value.
	 * @return True if the read was successful, false otherwise.
	 */
	bool ReadHalfVector(out vector value) {
		float x, y, z;
		if (!ReadHalfFloat(x))
			return false;
		if (!ReadHalfFloat(y))
			return false;
		if (!ReadHalfFloat(z))
			return false;
		value[0] = x;
		value[1] = y;
		value[2] = z;
		return true;
	}

	/**
	 * @brief Reads a packed vector value from the bitstream.
	 * @param[out] value The vector value to be read.
	 * @return True if the value was successfully read, false otherwise.
	 */
	bool ReadPacked(out vector value) {
		float x, y, z;
		if (!ReadPacked(x))
			return false;
		if (!ReadPacked(y))
			return false;
		if (!ReadPacked(z))
			return false;
		value[0] = x;
		value[1] = y;
		value[2] = z;
		return true;
	}

	/**
	 * @brief Reads a packed boolean value from the bitstream.
	 * @param[out] value The boolean value to be read.
	 * @return True if the value was read successfully, false otherwise.
	 */
	bool ReadPacked(out bool value) {
		return ReadBool(value);
	}

	/**
	 * @brief Reads a packed integer value from the bitstream.
	 * @param[out] value The integer value read from the bitstream.
	 * @return True if the integer value was successfully read, false otherwise.
	 */
	bool ReadPacked(out int value) {
		return ReadSInt(value, 32);
	}

	/**
	 * @brief Reads a packed float value from the bitstream.
	 * @param[out] value The float value read from the bitstream.
	 * @return True if the value was successfully read, false otherwise.
	 */
	bool ReadPacked(out float value) {
		int v;
		if (!ReadUInt(v, 32))
			return false;
		value = BitWiseHelpers.IntToFloat(v);
		return true;
	}

	/**
	 * @brief Reads a packed string from the bitstream.
	 * @param[out] value The string value read from the bitstream.
	 * @return True if the string was successfully read, false otherwise.
	 */
	bool ReadPacked(out string value) {
		int length;
		if (!ReadUInt(length, 10))
			return false;

		value = "";

		for (int i = 0; i < length; ++i) {
			int v;
			if (!ReadUInt(v, 8))
				return false;

			value += v.AsciiToString();
		}
		return true;
	}

	/**
	 * @brief Aligns the bitstream to the next integer boundary.
	 */
	void Align() {
		// If we need to align, skip to next int.
		if (m_BitIndex % SIZE_OF_INT_BITS != 0) {
			++m_WorkingIndex;
			m_BitIndex += m_BitIndex % SIZE_OF_INT_BITS;
		}
	}

	/**
	 * @brief Reads an aligned integer value from the bitstream.
	 * @param[out] value The integer value read from the bitstream.
	 * @return True if the read operation was successful, false otherwise.
	 */
	bool ReadAligned(out int value) {
		Align();
		return m_Context.Read(value);
	}

	/**
	 * @brief Reads a boolean value from the bitstream.
	 * @param[out] value - The boolean value to be read.
	 * @return Returns true if the read operation was successful, false otherwise.
	 */
	bool ReadAligned(out bool value) {
		Align();
		return m_Context.Read(!!value);
	}

	/**
	 * @brief Reads a value from the bitstream in an aligned manner.
	 * @param[out] value The value to be read from the bitstream.
	 * @return Returns true if the value was successfully read, false otherwise.
	 */
	bool ReadAligned(out Class value) {
		Align();
		return m_Context.Read(value);
	}

	/**
	 * @brief Reads a string value from the bitstream in an aligned manner.
	 * @param[out] value The string value read from the bitstream.
	 * @return True if the read operation was successful, false otherwise.
	 */
	bool ReadAligned(out string value) {
		Align();
		return m_Context.Read(value);
	}
}