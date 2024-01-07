/*
 * BitWise Framework
 * https://github.com/antihax/BitWiseFramework
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International (CC BY-ND 4.0)
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-nd/4.0/
 *
 */

enum BitWiseRPC {
	LookupEndpoint = 0,
	RPCTable = 1,
	RPCEndpoint = 2,
	RPCTEST = 3,
	MAX_BITWISE_RPC
}

private ref BitWiseManager gBitWiseManager = new BitWiseManager();
/**
 * @brief Returns the BitWiseManager used to interface with the RPC registration.
 */
BitWiseManager GetBitWiseManager() {
	return gBitWiseManager;
}

/**
 * @class BitWiseManager handles the RPC registration and invokation for BitWise RPCs.
 * This class is not accessible to developers and should be accessed through GetBitWiseManager().
 */

class BitWiseManager {
	protected autoptr map<int, ref ScriptCaller> m_Endpoints;
	protected autoptr map<string, ref ScriptCaller> m_PendingEndpoints;
	protected autoptr map<string, int> m_EndpointNames;
	protected bool m_DirtyRPCTable = true;
	protected autoptr BitWiseScriptRPC m_RPCTableRPC;
	protected int m_EndpointIndex;

	/**
	 * @brief Initializes a BitWiseManager object. Access through `GetBitWiseManager()`
	 */
	void BitWiseManager() {
		m_Endpoints = new map<int, ref ScriptCaller>();
		m_EndpointNames = new map<string, int>();
#ifdef SERVER
		m_EndpointIndex = BitWiseRPC.MAX_BITWISE_RPC; // Jump over our endpoints
		m_RPCTableRPC = BitWiseScriptRPC.NewFromID(BitWiseRPC.RPCTable);
#else
		m_PendingEndpoints = new map<string, ref ScriptCaller>();
#endif
	}

	void ~BitWiseManager() {
	}

	/**
	 * @brief Internal function to handle RPCs.
	 */
	void _OnRPC(PlayerIdentity sender, Object target, ParamsReadContext ctx) {
		int index;
		if (!ctx.Read(index)) {
			Error("BitWiseManager::OnRPC: Failed to read index.");
			return;
		}
		switch (index) {
		case BitWiseRPC.RPCTable:
			_RPC_RPCTable(ctx);
			break;
		default: // Invoke endpoint
			m_Endpoints.Get(index).Invoke(sender, target, ctx);
		}
	}

	/**
	 * @brief Internal function decode RPCTable
	 */
	private void _RPC_RPCTable(ParamsReadContext ctx) {
		BitStreamReader br = new BitStreamReader(ctx);

		int count;
		if (!br.ReadUInt(count, BITWISE_RPC_SIZE)) {
			Error("BitWiseManager::RPC_RPCTable: Failed to read count.");
			return;
		}

		// Only use as many bits as needed for the index
		int bits = BitWiseHelpers.BitSize(count + BitWiseRPC.MAX_BITWISE_RPC);
		while (count--) {
			string name;
			int index;
			if (!br.ReadPacked(name)) {
				Error("BitWiseManager::RPC_RPCTable: Failed to read name.");
				return;
			}

			if (!br.ReadUInt(index, bits)) {
				Error("BitWiseManager::RPC_RPCTable: Failed to read index.");
				return;
			}

			m_EndpointNames.Insert(name, index);
			// If the endpoint is pending, connect the invoker
			if (m_PendingEndpoints.Contains(name)) {
				m_Endpoints[index] = m_PendingEndpoints.Get(name);
				m_PendingEndpoints.Remove(name);
			}
		}
	}

#ifdef SERVER
	/**
	 * @brief Internal function to send RPCTable to a client.
	 */
	void _SendRPCTable(PlayerIdentity identity) {
		if (m_DirtyRPCTable) {
			m_RPCTableRPC.Reset();
			m_RPCTableRPC.WriteUInt(m_EndpointNames.Count(), BITWISE_RPC_SIZE);
			int bits = BitWiseHelpers.BitSize(m_EndpointNames.Count() + BitWiseRPC.MAX_BITWISE_RPC);

			foreach (string name, int id: m_EndpointNames) {
				m_RPCTableRPC.WritePacked(name);
				m_RPCTableRPC.WriteUInt(id, bits);
			}
			m_DirtyRPCTable = false;
		}
		m_RPCTableRPC.Send(NULL, true, identity);
	}
#endif

	/**
	 * @brief Returns the endpoint index for a given mod and keyword.
	 * @param mod The mod name.
	 * @param keyword The keyword.
	 * @return The endpoint index.
	 */
	int GetIndexForKeyword(string mod, string keyword) {
		return m_EndpointNames.Get(EndPointName(mod, keyword));
	}

#ifdef SERVER
	/**
	 * @brief Registers an endpoint for a mod and keyword for either client or server reception. Must be called on the server as early as possible.
	 * @param mod The mod name.
	 * @param keyword The keyword.
	 * @return The endpoint index.
	 * @note This function is only available on the server.
	 */
	int RegisterEndpoint(string mod, string keyword) {
		string name = EndPointName(mod, keyword);

		// Check if endpoint already exists
		if (m_EndpointNames.Contains(name)) {
			return m_EndpointNames.Get(name);
		}

		// Mark table dirty to rebuild
		m_DirtyRPCTable = true;
		m_EndpointNames.Insert(EndPointName(mod, keyword), ++m_EndpointIndex);
		return m_EndpointIndex;
	}
#endif

	/**
	 * @brief Connects an endpoint to a script caller. The endpoint is invoked when the RPC is called.
	 * @param mod The mod name.
	 * @param keyword The keyword.
	 * @param caller The script caller to run on RPC.
	 * @return The endpoint index.
	 */
	int ConnectEndpoint(string mod, string keyword, ScriptCaller caller) {
		if (!caller) {
			Error("BitWiseManager::RegisterEndpoint: caller is NULL.");
			return -1;
		}
		int index = -1;
#ifdef SERVER
		index = RegisterEndpoint(mod, keyword);
		// Register endpoint if it doesn't exist or get the ID
		m_Endpoints.Insert(index, caller);
#else
		// Connect the caller to the endpoint or add to the pending list
		if (m_EndpointNames.Find(EndPointName(mod, keyword), index))
			m_Endpoints.Insert(index, caller);
		else
			m_PendingEndpoints.Insert(EndPointName(mod, keyword), caller);
#endif
		return index;
	}

	/***
	 * @brief Returns the endpoint name for a given mod and keyword.
	 * @param mod The mod name.
	 * @param keyword The keyword.
	 * @return The endpoint name.
	 */
	private string EndPointName(string mod, string keyword) {
		return mod + ":" + keyword;
	}
}
