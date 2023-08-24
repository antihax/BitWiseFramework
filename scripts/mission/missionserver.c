#ifdef SERVER
modded class MissionServer {

#ifdef BITWISEDEBUG
	override void OnInit() {

		auto b = BitWiseBenchmarks();
		b.Run();
		test_Bitstream();

		super.OnInit();
	}

	// Send RPC table to client very early
	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		GetBitWiseManager()._SendRPCTable(identity);
		super.OnClientPrepareEvent(identity, useDB, pos, yaw, preloadTimeout);
	}
	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		test_Endpoints();
		super.InvokeOnConnect(player, identity);
	}
}
#endif