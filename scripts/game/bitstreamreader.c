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
 */

class BitStreamReader {
	private int m_BitIndex = 0;
	private Serializer m_Context;
	private int m_Working;
	private int m_WorkingIndex;

	/**
	 *
	 */

	void BitStreamReader(Serializer _ctx) {
		m_Context = _ctx;
		m_BitIndex = 0;
		m_WorkingIndex = -1; // Force a read on the first read.
	}

	void ~BitStreamReader() {
	}

	int GetIndex() {
		return m_BitIndex;
	}

	bool ReadBool(out bool value) {
		return ReadUInt(value, 1);
	}

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
	 * @brief Aligns the bitstream to the next integer boundary.
	 *
	 * Generally, this function is only called at the end of a message to ensure proper alignment.
	 */
	void Align() {
		// If we need to align, skip to next int.
		if (m_BitIndex % SIZE_OF_INT_BITS != 0) {
			++m_WorkingIndex;
			m_BitIndex += m_BitIndex % SIZE_OF_INT_BITS;
		}
	}

	bool ReadPacked(out bool value) {
		return ReadBool(value);
	}

	bool ReadPacked(out int value) {
		return ReadSInt(value, 32);
	}

	bool ReadPacked(out float value) {
		return ReadSInt(value, 32);
	}

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

	bool ReadAligned(out int value) {
		Align();
		return m_Context.Read(value);
	}
	bool ReadAligned(out bool value) {
		Align();
		return m_Context.Read(!!value);
	}
	bool ReadAligned(out Class value) {
		Align();
		return m_Context.Read(value);
	}
	bool ReadAligned(out string value) {
		Align();
		return m_Context.Read(value);
	}
}