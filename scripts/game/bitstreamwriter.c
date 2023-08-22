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
	protected Serializer m_Context;
	private int m_Working; // The current integer we are packing to.
	private int m_WorkingIndex = 0;

	void BitStreamWriter(Serializer context = NULL) {
		m_Context = context;
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
	bool Align() {
		// If we need to align, write the working integer to the bitstream.
		if (m_BitIndex % SIZE_OF_INT_BITS != 0) {
			if (!m_Context.Write(m_Working))
				return false;
			++m_WorkingIndex;
			m_BitIndex += m_BitIndex % SIZE_OF_INT_BITS;
		}
		return true;
	}

	/**
	 * @brief Resets the bitstream to the beginning.
	 * Should not be called by a developer.
	 */
	protected void Reset() {
		m_WorkingIndex = 0;
		m_BitIndex = 0;
	}

	/**
	 * @brief Writes a boolean value to the bitstream and returns the original value.
	 *
	 * @param value The boolean value to be written to the bitstream.
	 * @return Returns true if the operation is successful, false otherwise.
	 */

	bool WritePacked(bool value) {
		return WriteUInt(!!value, 1); // Because a bool is an int.
	}

	bool WritePacked(float value) {
		// Write the float as an int.
		int intVal = (int)value;
		return WriteUInt(intVal, 32);
	}

	/***
	 * @brief Writes a string to the bitstream. This is an expensive call for large strings. You should avoid sending strings or use WriteAligned.
	 * @param s The string to be written to the bitstream.
	 * @return Returns true if the operation is successful, false otherwise.
	 */
	bool WritePacked(string value) {
		// If you need to send more, you need to rethink your design.
		if (value.Length() > 1023) {
			Print("String too long, must be under 1023 bytes.");
			return false;
		}
		// Write length of string, 10 bit.
		if (!WriteUInt(value.Length(), 10))
			return false;

		// Write bytes, inclusive of UTF-8.
		for (int i = 0; i < value.Length(); ++i) {
			if (!WriteUInt(value.Get(i).ToAscii(), 8))
				return false;
		}

		return true;
	}

	/***
	 * @brief Writes an object by network ID to the bitstream.
	 * @param object The object to be written to the bitstream.
	 * @return Returns true if the operation is successful, false otherwise.
	 */
	bool WritePacked(Object object) {
		int high, low;
		if (!object)
			return false;

		// Get the network ID.
		object.GetNetworkID(high, low);
		if (!WriteSInt(high, 32))
			return false;
		if (!WriteSInt(low, 32))
			return false;
		return true;
	}

	/**
	 * WriteUInt is a function that writes an unsigned integer value to a bitstream.
	 *
	 * @param value The integer value to be written to the bitstream.
	 * @param bits The number of bits to be written from the value to the bitstream.
	 *
	 * @return Returns true if the operation is successful, false otherwise.
	 *
	 */
	bool WriteUInt(int value, int bits) {
		if (bits <= 0 || bits > SIZE_OF_INT_BITS) {
			return false;
		}

		int up = m_BitIndex % SIZE_OF_INT_BITS;
		int down = SIZE_OF_INT_BITS - up;
		int mask;

		if (up == 0 || down >= bits) { // Aligned or fits one int just Write.
			mask = ((1 << bits) - 1) << up;
			m_Working = (m_Working & ~mask) | ((value << up) & mask);

		} else { // We cross two ints
			m_Working |= ((value << up) & ~((1 << up) - 1));
			if (!m_Context.Write(m_Working))
				return false;
			++m_WorkingIndex;
			m_Working = (value >> down) & ((1 << bits - down) - 1);
		}

		// Check if we need to write the working integer to the bitstream.
		m_BitIndex += bits;
		if (m_BitIndex / SIZE_OF_INT_BITS > m_WorkingIndex) {
			if (!m_Context.Write(m_Working))
				return false;
			++m_WorkingIndex;
			m_Working = 0;
		}
		return true;
	}

	/**
	 * WriteSInt is a function that writes a signed integer value to a bitstream.
	 * @param value The integer value to be written to the bitstream.
	 * @param bits The number of bits to be written from the value to the bitstream.
	 * @return Returns true if the operation is successful, false otherwise.
	 */
	bool WriteSInt(int value, int bits) {
		// Write sign bit.
		bool negative = value < 0;
		if (!WriteUInt(negative, 1))
			return false;

		bool ok;
		if (negative)
			ok = WriteUInt(-value, bits);
		else
			ok = WriteUInt(value, bits);
		return ok;
	}

	/*********** ALIGNED WRITING ***********/
	/**
	 * @note Aligned writes should not be used unless needed such as deep serialization
	 * however no compression takes place with these style of writes. Use sparingly.
	 */

	/**
	 * @brief Write a value to the RPC stream, aligns to next int and writes the value.
	 */
	bool WriteAligned(int value) {
		Align();
		return m_Context.Write(value);
	}
	bool WriteAligned(bool value) {
		Align();
		return m_Context.Write(!!value);
	}
	bool WriteAligned(Class value) {
		Align();
		return m_Context.Write(value);
	}
	bool WriteAligned(string value) {
		Align();
		return m_Context.Write(value);
	}
};
