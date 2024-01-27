/*
 * BitWise Framework
 * https://github.com/antihax/BitWiseFramework
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International (CC BY-ND 4.0)
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-nd/4.0/
 *
 */

static const int BITWISE_RPC_SIZE = 17;

class BitWiseScriptRPC : BitStreamWriter {
	private autoptr ScriptRPC m_ScriptRPC;
	private int m_Index;

	/**
	 * @brief Initializes the BitWiseScriptRPC object.
	 * 
	 * This function creates a new ScriptRPC object.
	 * 
	 * @param serializer The serializer to be used for serialization (optional, default value is NULL).
	 */
	private void BitWiseScriptRPC(Serializer serializer = NULL) {
		m_ScriptRPC = new ScriptRPC();
		m_Context = m_ScriptRPC;
	}

	/**
	 * Sets the index value.
	 *
	 * @param index The new index value.
	 */
	private void SetIndex(int index) {
		m_Index = index;
	}

	void ~BitWiseScriptRPC() {
	}

	/**
	 * Creates a new BitWiseScriptRPC object from the given endpoint index.
	 * 
	 * @param index The index value for the new BitWiseScriptRPC object.
	 * @return The newly created BitWiseScriptRPC object.
	 */
	static BitWiseScriptRPC NewFromID(int index) {
		BitWiseScriptRPC rpc = new BitWiseScriptRPC();
		rpc.SetIndex(index);
		// Write the RPC index directly.
		rpc.WriteAligned(index);
		return rpc;
	}

	/**
	 * Creates a new BitWiseScriptRPC object with the specified mod and keyword that has been previously registered with `GetBitWiseManager().RegisterEndpoint`
	 * 
	 * @param mod The mod name.
	 * @param keyword The keyword.
	 * @return A pointer to the newly created BitWiseScriptRPC object, or NULL if an error occurred.
	 */
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

	/**
	 * @brief Resets the script and the ScriptRPC object.
	 * 
	 * Reset the buffer and the associated ScriptRPC object so the RPC can be reused.
	 */
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