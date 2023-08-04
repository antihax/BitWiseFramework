/*
 * BitWise Framework
 * https://github.com/antihax/BitWiseFramework
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International (CC BY-ND 4.0)
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-nd/4.0/
 *
 */

#ifdef DIAG_DEVELOPER
modded class DayZGame {
	void DayZGame() {
		test_Bitstream();
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		int prev = TickCount(0);
		super.OnRPC(sender, target, rpc_type, ctx);
		int time = TickCount(prev);
		int estimatedMil = (int)(time / 10000.0);
		Print("RPC: " + rpc_type + " took " + time + " ticks (" + estimatedMil + "ms) " + EnumTools.EnumToString(ERPCs, rpc_type));
	}

	void ~DayZGame() {}
}

#endif