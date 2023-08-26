#ifdef SERVER

modded class MissionServer {
	/**
	 * @brief Overrides the OnClientPrepareEvent method to send the RPCTable to the player's identity.
	 */
	override void OnClientPrepareEvent(PlayerIdentity identity, out bool useDB, out vector pos, out float yaw, out int preloadTimeout) {
		GetBitWiseManager()._SendRPCTable(identity);
		super.OnClientPrepareEvent(identity, useDB, pos, yaw, preloadTimeout);
	}

#ifdef BITWISEDEBUG
	override void OnInit() {
		auto b = BitWiseBenchmarks();
		b.Run();
		test_Bitstream();
		super.OnInit();
	}

	override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity) {
		test_Endpoints();
		super.InvokeOnConnect(player, identity);
	}

	override void InvokeOnDisconnect(PlayerBase player) {
		super.InvokeOnDisconnect(player);
		EnProfiler.Dump();
		array<ref EnProfilerTimeFuncPair> timePerFunc = {};
		array<ref EnProfilerCountFuncPair> countPerFunc = {};
		map<string, ref ProfileData> data = new map<string, ref ProfileData>();
		EnProfiler.GetTimePerFunc(timePerFunc);
		EnProfiler.GetCountPerFunc(countPerFunc);

		// clang-format off
		foreach(auto pair : timePerFunc) {
			// clang-format on
			ProfileData d;
			if (data.Find(pair.param2, d)) {
				d.time += pair.param1;
			} else {
				d = new ProfileData();
				d.count = 0;
				d.time = pair.param1;
				d.name = pair.param2;
				data.Insert(d.name, d);
			}
		}

		// clang-format off
		foreach(auto pairc : countPerFunc) {
			// clang-format on

			if (data.Find(pairc.param2, d)) {
				d.count += pairc.param1;
			} else {
				d = new ProfileData();
				d.count = pairc.param1;
				d.name = pairc.param2;
				data.Insert(d.name, d);
			}
		}

		// clang-format off
		foreach(string name, ProfileData x : data) {
			// clang-format on
			Print(MiscGameplayFunctions.Truncate((x.time / x.count), 4).ToString() + " " + name + " took " + x.time.ToString() + "ms and was called " + x.count.ToString() + " times.");
		}
	}
#endif // BITWISEDEBUG
}
#endif // SERVER