/** @example RPC
* Endpoints should be registered in the OnInit() function of the MissionServer class for the server.
* Including both endpoints on the server and client as the server coordinates synchronization of the indexes.
* `RegisterEndpoint` creates an index for the endpoint used to synchronize the endpoint name between client and server.

* @code
modded class MissionServer {
	protected int m_RPC_SENDMESSAGE;
	override void OnInit() {

		// Outbound RPCs
		// Cache the index for the endpoint since we will use it locally to send RPCs.
		m_RPC_SENDMESSAGE = GetBitWiseManager().RegisterEndpoint("MyAmazingMod", "SendMessage");

		// Inbound RPCs
		// Register and connect the AskForMessage endpoint to a function that will be called when the client sends the RPC to us.
		GetBitWiseManager().RegisterEndpoint("MyAmazingMod", "AskForMessage");
		GetBitWiseManager().ConnectEndpoint("MyAmazingMod", "AskForMessage", ScriptCaller.Create(RPC_AskForMessage));

		super.OnInit();
	}

	// This is the function that will be called when the client sends the RPC that we connected to the `AskForMessage` endpoint.
	bool RPC_AskForMessage(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		// wrap the context into a BitStreamReader
		BitStreamReader br = new BitStreamReader(ctx);

		// Read a 20 bit integer. Return false on any error.
		int id;
		if (!br.ReadUInt(id, 20))
			return false;

		// Send a message back to the client.
		autoptr BitWiseScriptRPC rpc = BitWiseScriptRPC.NewFromID(m_RPC_SENDMESSAGE);
		rpc.WritePacked("Hello World!");
		rpc.Send(target, true, sender.GetIdentity());

		return true; // Return successful read.
	}
}
* @endcode

* On the client side
 * We connect the endpoints to functions on the client that will be called when the server sends the RPCs.
 * We can also get our synchronized client -> server RPC index from the BitWiseManager using `GetIndexForKeyword`.
 * @code
modded class MissionBase {
	protected int m_RPC_ASKFORMESSAGE;
	void MissionBase() {
		GetBitWiseManager().ConnectEndpoint("MyAmazingMod", "SendMessage", ScriptCaller.Create(RPC_SendMessage));
		m_RPC_ASKFORMESSAGE = GetBitWiseManager().GetIndexForKeyword("MyAmazingMod", "AskForMessage");
	}

	bool RPC_SendMessage(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		BitStreamReader br = new BitStreamReader(ctx);

		// Read and pring the packed message
		string message;
		if (!br.ReadPacked(message))
			return false;
		print(message);
	
		return true;
	}
};
* @endcode
*/
