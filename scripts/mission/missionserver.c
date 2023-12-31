/*
 * BitWise Framework
 * https://github.com/antihax/BitWiseFramework
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International (CC BY-ND 4.0)
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-nd/4.0/
 *
 */
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
		EnProfiler.Enable(true, true, true);
		EnProfiler.SetInterval(0, false);
		EnProfiler.SetFlags(EnProfilerFlags.RECURSIVE, false);
		EnProfiler.SetModule(EnProfilerModule.CORE, false);
		EnProfiler.SetTimeResolution(1000);
		EnProfiler.ResetSession(true);
	}

	override void InvokeOnDisconnect(PlayerBase player) {
		super.InvokeOnDisconnect(player);
		EnProfiler.Dump();
		array<ref EnProfilerTimeFuncPair> timePerFunc = {};
		array<ref EnProfilerCountFuncPair> countPerFunc = {};
		map<string, ProfileData> data = new map<string, ProfileData>();
		EnProfiler.GetTimePerFunc(timePerFunc);
		EnProfiler.GetCountPerFunc(countPerFunc);

		foreach (auto pair: timePerFunc) {
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
			Print(pair.param1.ToString() + " " + pair.param2);
		}

		foreach (auto pairc: countPerFunc) {
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

		foreach (string name, ProfileData x: data) {
			Print(MiscGameplayFunctions.Truncate((x.time / x.count), 4).ToString() + " " + name + " took " + x.time.ToString() + "ms and was called " + x.count.ToString() + " times.");
		}
	}
#endif // BITWISEDEBUG
}
#endif // SERVER