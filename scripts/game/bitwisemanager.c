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
	MAX_BITWISE_RPC
}

private ref BitWiseManager gBitWiseManager = new BitWiseManager();
BitWiseManager GetBitWiseManager() {
	return gBitWiseManager;
}

/**
 * @class BitwiseManager handles the RPC registration and invokation for BitWise RPCs.
 * This class is not accessible to developers and should be accessed through GetBitWiseManager().
 */

class BitWiseManager {
	protected ref map<int, ref ScriptCaller> m_Endpoints;
	protected ref map<string, ref ScriptCaller> m_PendingEndpoints;
	protected ref map<string, int> m_EndpointNames;
	protected int m_EndpointIndex;

	void BitWiseManager() {
		m_Endpoints = new map<int, ref ScriptCaller>();
		m_EndpointNames = new map<string, int>();
		m_EndpointIndex = BitWiseRPC.MAX_BITWISE_RPC; // Jump over our endpoints
	}

	void ~BitWiseManager() {
		delete m_Endpoints;
		delete m_EndpointNames;
	}

	int RegisterEndpoint(string mod, string keyword, func fn) {
		if (GetGame().IsClient()) {
			Print("BitWiseManager::RegisterEndpoint: Called on client.");
			return -1;
		}
		int index = m_EndpointIndex++;
		ScriptCaller caller = ScriptCaller.Create(fn);
		m_Endpoints.Insert(index, caller);
		m_EndpointNames.Insert(EndPointName(mod, keyword), index);
		return index;
	}

	/***
	 * @brief Returns the endpoint name for a given mod and keyword.
	 * @param mod The mod name.
	 * @param keyword The keyword.
	 * @return The endpoint name.
	 *
	 */
	private string EndPointName(string mod, string keyword) {
		return mod + ":" + keyword;
	}

	/*void LookupEndpoint(string mod, string keyword) {
		ScriptRPC rpc = new ScriptRPC();
		auto bs = new BitStreamWriter(rpc);

		bs.WriteString(EndPointName(mod, keyword));
	}*/

	void OnRPC(PlayerIdentity sender, Object target, int rpc_type, ParamsReadContext ctx) {
		int index;
		if (!ctx.Read(index)) {
			Print("BitWiseManager::OnRPC: Failed to read index.");
			return;
		}
		m_Endpoints.Get(index).Invoke(sender, target, ctx);
	}
}