#ifdef BITWISEDEBUG
#ifdef SERVER
[BitWiseBenchmarkStart()] class BitWiseBenchmarkStart {
	void BitWiseBenchmarkStart() {
		EnProfiler.Enable(true, true, false);
		EnProfiler.SetInterval(0, false);
		EnProfiler.SetFlags(EnProfilerFlags.RECURSIVE, false);
		EnProfiler.SetModule(EnProfilerModule.CORE, false);
		EnProfiler.SetTimeResolution(1000);
	}
}
#endif
#endif