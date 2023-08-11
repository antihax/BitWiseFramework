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
 * @class BitStreamWriter
 *
 * This class is responsible for writing data into a bitstream.
 * It provides methods to write various types of data (like integers, floats, etc.) into the bitstream.
 * The data can then be read from the bitstream using a BitStreamReader.
 */

class BitStreamWriter {
	private int m_BitIndex;
	private Serializer ctx;
	private int m_Working; // The current integer we are packing to.
	private int m_WorkingIndex = 0;

	void BitStreamWriter(Serializer _ctx) {
		ctx = _ctx;
		m_BitIndex = 0;
	}

	void ~BitStreamWriter() {
	}

	/// GetIndex returns the current bit index.
	int GetIndex() {
		return m_BitIndex;
	}

	/**
	 * @brief Aligns the bitstream to the next integer boundary.
	 *
	 * Generally, this function is only called at the end of a message to ensure proper alignment.
	 */
	void Align() {
		ctx.Write(m_Working);
		m_WorkingIndex++;
		m_BitIndex += m_BitIndex % SIZE_OF_INT_BITS;
	}

	/**
	 * @brief Writes a boolean value to the bitstream and returns the original value.
	 *
	 * @param value The boolean value to be written to the bitstream.
	 * @return The original boolean value that was written to the bitstream.
	 */
	bool WriteBool(bool value) {
		WriteUint(!!value, 1); // Because a bool is an int.
		return value;
	}

	/***
	 * @brief Writes an object by network ID to the bitstream.
	 * @param object The object to be written to the bitstream.
	 * @return Returns true if the operation is successful, false otherwise.
	 */
	bool WriteObject(Object object) {
		int high, low;
		if (!object)
			return false;

		// Get the network ID.
		object.GetNetworkID(high, low);
		writeSInt(high, 32);
		writeSInt(low, 32);
		return true;
	}

	/**
	 * WriteUint is a function that writes an unsigned integer value to a bitstream.
	 *
	 * @param value The integer value to be written to the bitstream.
	 * @param bits The number of bits to be written from the value to the bitstream.
	 *
	 * @return Returns true if the operation is successful, false otherwise.
	 *
	 */

	bool WriteUint(int value, int bits) {
		if (bits <= 0 || bits > SIZE_OF_INT_BITS - 1) {
			return false;
		}

		int up = m_BitIndex % SIZE_OF_INT_BITS;
		int down = SIZE_OF_INT_BITS - up;
		int mask;

		if (up == 0 || down >= bits) {
			mask = ((1 << bits) - 1) << up;
			m_Working = (m_Working & ~mask) | ((value << up) & mask);

		} else {
			m_Working |= ((value << up) & ~((1 << up) - 1));
			ctx.Write(m_Working);
			m_WorkingIndex++;
			m_Working = (value >> down) & ((1 << bits - down) - 1);
		}

		m_BitIndex += bits;
		if (m_BitIndex / SIZE_OF_INT_BITS > m_WorkingIndex) {
			ctx.Write(m_Working);
			m_WorkingIndex++;
			m_Working = 0;
		}
		return true;
	}

	void writeSInt(int value, int bits) {
		if (WriteBool(value < 0)) // Write sign bit.
			WriteUint(-value, bits);
		else
			WriteUint(value, bits);
	}
};
