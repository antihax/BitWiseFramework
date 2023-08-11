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
 * BitStreamReader allows you to read bits to an array of integers from
 * network transmission.
 */

class BitStreamReader {
	private int m_BitIndex = 0;
	private Serializer ctx;
	private int m_Working;
	private int m_WorkingIndex;

/** 
 * 
*/

	void BitStreamReader(Serializer _ctx) {
		ctx = _ctx;
		m_BitIndex = 0;
		m_WorkingIndex = -1; // Force a read on the first read.
	}

	void ~BitStreamReader() {
	}

	int GetIndex() {
		return m_BitIndex;
	}

	bool ReadBool() {
		return ReadUint(1);
	}

	int ReadUint(int bits) {
		if (bits > SIZE_OF_INT_BITS - 1 || bits <= 0) {
			return -1;
		}

		int down = m_BitIndex % SIZE_OF_INT_BITS;
		int up = SIZE_OF_INT_BITS - down;
		int index = m_BitIndex / SIZE_OF_INT_BITS;
		int value;

		// Get the next integer if we need to.
		if (m_BitIndex / SIZE_OF_INT_BITS != m_WorkingIndex) {
			ctx.Read(m_Working);
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
			ctx.Read(nextWorking);
			m_WorkingIndex = (m_BitIndex + bits) / SIZE_OF_INT_BITS;

			// Depack the value from the two integers.
			value = ((m_Working >> down) & ((1 << up) - 1)) | ((nextWorking & ((1 << (bits - up)) - 1)) << up);
			m_Working = nextWorking;
		}

		m_BitIndex += bits;
		return value;
	}

	int ReadSInt(int bits) {
		bool isNegative = ReadBool();
		int value = ReadUint(bits);
		if (isNegative) {
			return -value;
		} else {
			return value;
		}
	}
}