/*
 * BitWise Framework
 * https://github.com/antihax/BitWiseFramework
 * © 2023 antihax
 *
 * This work is licensed under the Creative Commons Attribution-NoDerivatives 4.0 International (CC BY-ND 4.0)
 * To view a copy of this license, visit https://creativecommons.org/licenses/by-nd/4.0/
 *
 */
#ifdef BITWISEDEBUG
#ifdef SERVER
[BitWiseBenchmarkStart()]
class BitWiseBenchmarkStart {
	void BitWiseBenchmarkStart() {
		EnProfiler.Enable(true, true, false);
		EnProfiler.SetInterval(0, false);
		EnProfiler.SetFlags(EnProfilerFlags.RECURSIVE, false);
		EnProfiler.SetModule(EnProfilerModule.CORE, false);
		EnProfiler.SetTimeResolution(1000);
	}
}

class ProfileData {
	int count;
	float time;
	string name;
}
#endif
#endif