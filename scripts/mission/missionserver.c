#ifdef SERVER
modded class MissionServer {
#ifdef DIAG_DEVELOPER
	override void OnInit() {
		auto b = BitWiseBenchmarks();
		b.Run();
		test_Bitstream();
		super.OnInit();
	}
#endif

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		super.InvokeOnConnect(player, identity);
	}

	/*
	ClientConnectedEventTypeID
	ClientPrepareEventTypeID  -  OnClientPrepareEvent
	ClientReadyEventTypeID - OnClientReadyEvent -  InvokeOnConnect
	*/

	override void OnEvent(EventType eventTypeId, Param params) {
		switch (eventTypeId) {
		case ClientConnectedEventTypeID:
			// OnClientConnectedEvent
			// send RPC table to client
			break;
		}
		super.OnEvent(eventTypeId, params);
	}
}
#endif
