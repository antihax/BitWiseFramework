/*
 * BitWise Framework
 * https://github.com/antihax/BitWiseFramework
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International (CC BY-ND 4.0)
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-nd/4.0/
 *
 */

modded class DayZGame {
	void DayZGame() {
#ifdef BITWISEDEBUG
#ifdef SERVER
		GetBitWiseManager().RegisterEndpoint("BITWISE", "servertest1");
		GetBitWiseManager().RegisterEndpoint("BITWISE", "servertest2");
		GetBitWiseManager().RegisterEndpoint("BITWISE", "servertest3");
		GetBitWiseManager().RegisterEndpoint("BITWISE", "servertest4");
		GetBitWiseManager().RegisterEndpoint("BITWISE", "servertest1");
#endif
#endif
	}

	override void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
#ifdef BITWISEDEBUG
		int prev = TickCount(0);
#endif

		if (rpc_type == RPC_ANTIHAX_BITWISE)
			GetBitWiseManager()._OnRPC(sender, target, ctx);
		else
			super.OnRPC(sender, target, rpc_type, ctx);

#ifdef BITWISEDEBUG
		int time = TickCount(prev);
		int estimatedMil = (int)(time / 10000.0);
		Print("RPC: " + rpc_type + " took " + time + " ticks (" + estimatedMil + "ms) " + EnumTools.EnumToString(ERPCs, rpc_type));
	}
#endif

	void ~DayZGame() {}
}
