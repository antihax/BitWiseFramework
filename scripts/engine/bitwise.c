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
/// @brief  A framework for creating RPCs (Remote Procedure Calls) in DayZ in an optimized way to minimize bandwidth usage and resolve collisions.
///
/// @details This framework is designed to be used by modders to create RPCs in DayZ.

/// @brief Helper functions for the RPC framework held within a namespace to avoid collisions with other mods.
class BitWiseHelpers {

	/// @brief Binary representation of the value, useful for debugging.
	/// @param value
	/// @return string of the value in binary.
	string BitRepresentation(int value) {
		string result = "";
		for (int i = 0; i < 32; i++) {
			if (value & (1 << i))
				result = "1" + result;
			else
				result = "0" + result;
		}
		return result;
	}

	/// @brief Helper function to dump the stack to a string with a message.
	/// @param str Message before the stack dump.
	void WarningWithStack(string message) {
		string str;
		DumpStackString(str);
		Print("BitStream: " + message + "\n" + str);
	}
}