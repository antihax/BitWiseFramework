/*
 * BitWise Framework
 * https://github.com/antihax/BitWiseFramework
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International (CC BY-ND 4.0)
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-nd/4.0/
 *
 */

#define BITWISEFRAMEWORK
static const int SIZE_OF_INT_BITS = 32;
static const int RPC_ANTIHAX_BITWISE = -1456746571;

/**
 * @brief A class that contains helper functions for bitwise operations.
 */
class BitWiseHelpers {

	/**
	 * Returns the binary representation of an integer value as a string.
	 *
	 * @param value The integer value to be converted to binary.
	 * @return The binary representation of the integer value as a string.
	 */
	static string BitRepresentation(int value) {
		string result = "";
		for (int i = 0; i < 32; ++i) {
			if (value & (1 << i))
				result = "1" + result;
			else
				result = "0" + result;
		}
		return result;
	}

	/**
	 * Calculates the number of bits required to represent a given integer.
	 *
	 * @param n The integer to calculate the number of bits for.
	 * @return The number of bits required to represent the given integer.
	 */
	static int BitSize(int n) {
		int bits = 0;
		while (n != 0) {
			n >>= 1;
			bits++;
		}
		return bits;
	}

	/**
	 * Converts float to float bits in an integer.
	 *
	 * @param value The float value to be converted.
	 * @return The integer value of the given float.
	 */
	static int FloatToInt(float value) {
		int v[1];
		float f[1] = {value};
		copyarray(v, f);
		return v[0];
	}

	/**
	 * Converts integer float bits to float.
	 *
	 * @param value The integer value to be converted.
	 * @return The float value of the given integer.
	 */
	static float IntToFloat(int value) {
		float f[1];
		int v[1] = {value};
		copyarray(f, v);
		return f[0];
	}

	/**
	 * Converts float to half-float stored as int.
	 *
	 * @param fi The float value to be converted.
	 * @return The half value of the given float.
	 */
	static int FloatToHalf(float fi) {
		int v = FloatToInt(fi);
		return ((v & 0x80000000) >> 16) | (((v & 0x7F800000) - 0x38000000) >> 13) | ((v & 0x007FFFFF) >> 13);
	}

	/**
	 * Converts half-float stored as int to float.
	 *
	 * @param h The half value to be converted.
	 * @return The float value of the given half.
	 */
	static float HalfToFloat(int h) {
		return IntToFloat(((h & 0x8000) << 16) | (((h & 0x7C00) + 0x1C000) << 13) | ((h & 0x03FF) << 13));
	}
}

/**
@note Netcode statistics of DayZ for reference. No fragmentation occurred indicating MTU discovery and boundaries.
==================================================================================================================================
Packet Lengths:
Topic / Item       Count         Average       Min Val       Max Val       Rate (ms)     Percent       Burst Rate    Burst Start
----------------------------------------------------------------------------------------------------------------------------------
Packet Lengths     8826          296.14        44            1456          0.0791        100%          0.3200        42.774
 0-19              0             -             -             -             0.0000        0.00%         -             -
 20-39             0             -             -             -             0.0000        0.00%         -             -
 40-79             8             52.00         44            76            0.0001        0.09%         0.0200        8.981
 80-159            4493          132.09        84            159           0.0402        50.91%        0.1600        42.807
 160-319           872           198.47        160           318           0.0078        9.88%         0.0900        11.569
 320-639           2929          402.28        321           639           0.0262        33.19%        0.1900        42.501
 640-1279          173           1032.82       647           1279          0.0015        1.96%         0.0600        27.485
 1280-2559         351           1395.56       1281          1456          0.0031        3.98%         0.0800        40.779
----------------------------------------------------------------------------------------------------------------------------------
*/