static const int BITWISE_RPC_SIZE = 17;
class BitWiseScriptRPC : BitStreamWriter {
	private ref ScriptRPC m_ScriptRPC;
	private int m_Index;

	private void BitWiseScriptRPC(Serializer serializer = NULL) {
		m_ScriptRPC = new ScriptRPC();
		m_Context = m_ScriptRPC;
	}

	private void SetIndex(int index) {
		m_Index = index;
	}

	void ~BitWiseScriptRPC() {
		delete m_ScriptRPC;
	}

	static BitWiseScriptRPC NewFromID(int index) {
		BitWiseScriptRPC rpc = new BitWiseScriptRPC();
		rpc.SetIndex(index);
		// Write the RPC index directly.

		rpc.WriteAligned(index);
		return rpc;
	}

	static BitWiseScriptRPC New(string mod, string keyword) {
		auto g = GetBitWiseManager();
		if (!g) {
			Error("BitWiseScriptRPC::New - BitWiseManager not available yet");
			return NULL;
		}

		int id = g.GetIndexForKeyword(mod, keyword);
		if (id <= 0) {
			Error("BitWiseScriptRPC::New - index not found for mod " + mod + " and keyword " + keyword);
			return NULL;
		}

		BitWiseScriptRPC rpc = new BitWiseScriptRPC();
		rpc.SetIndex(id);
		// Write the RPC index directly.
		rpc.WriteAligned(id);

		return rpc;
	}

	override void Reset() {
		super.Reset();
		m_ScriptRPC.Reset();

		// Write our RPC index
		WriteAligned(m_Index);
	}

	/**
	 * @brief Send the RPC on the wire, can be saved and repeated if needed.
	 * @param target The target object of the RPC
	 * @param guaranteed boolean to resend the RPC if it is lost in transit
	 * @param recipient The player to send the RPC to, NULL for all players
	 */
	void Send(Object target, bool guaranteed, PlayerIdentity recipient = NULL) {
		// Align the stream to the next integer
		Align();

		// Send the RPC
		m_ScriptRPC.Send(target, RPC_ANTIHAX_BITWISE, guaranteed, recipient);
	}
}