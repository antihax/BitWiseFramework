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
/// @brief  A framework for creating RPCs (Remote Procedure Calls) in DayZ in an optimized way to minimize bandwidth usage and resolve collisions.
///
/// @details This framework is designed to be used by modders to create RPCs in DayZ.

/// @brief Helper functions for the RPC framework held within a namespace to avoid collisions with other mods.
class BitWiseHelpers {

	/// @brief Binary representation of the value, useful for debugging.
	/// @param value
	/// @return string of the value in binary.
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
	 * @brief Determine how many bits are used by a value
	 * @param n The value to check.
	 * @return The number of bits used.
	 */

	static int BitSize(int n) {
		int bits = 0;
		while (n != 0) {
			n >>= 1;
			bits++;
		}
		return bits;
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