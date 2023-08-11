#ifdef DIAG_DEVELOPER

class BitWiseBenchmarks {
	ref ScriptInvoker ReusetestInvoker;
	ref ScriptCaller ReusetestCaller;

	void BitWiseBenchmarks() {
	}
	void Run() {

		ReusetestCaller = ScriptCaller.Create(CallMeMaybe);
		ReusetestInvoker = new ScriptInvoker();
		ReusetestInvoker.Insert(CallMeMaybe);

		float time;
		int i;
		EnProfiler.Enable(true, true);
		EnProfiler.SetTimeResolution(1000);

		for (i = 0; i < 1000000; i++) {
			BenchmarkScriptInvoker();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkScriptInvoker", Type(), true);
		Print("BenchmarkScriptInvoker took " + time.ToString());

		for (i = 0; i < 1000000; i++) {
			BenchmarkScriptCaller();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkScriptCaller", Type(), true);
		Print("BenchmarkScriptCaller took " + time.ToString());

		for (i = 0; i < 1000000; i++) {
			BenchmarkCallFunction();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkCallFunction", Type(), true);
		Print("BenchmarkCallFunction took " + time.ToString());

		for (i = 0; i < 1000000; i++) {
			BenchmarkReuseScriptCaller();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkReuseScriptCaller", Type(), true);
		Print("BenchmarkReuseScriptCaller took " + time.ToString());

		for (i = 0; i < 1000000; i++) {
			BenchmarkReuseScriptInvoke();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkReuseScriptInvoke", Type(), true);
		Print("BenchmarkReuseScriptInvoke took " + time.ToString());

		EnProfiler.Enable(false);
	}

	void CallMeMaybe(int number) {
		int x = 0;
		number++;
		number--;
		number += 4;
		x = number;
		number = x;
	}

	void BenchmarkCallFunction() {
		GetGame().GameScript.CallFunction(this, "CallMeMaybe", NULL, new Param1<int>(1234));
	}

	void BenchmarkScriptInvoker() {
		ScriptInvoker testCaller = new ScriptInvoker();
		testCaller.Insert(CallMeMaybe);
		testCaller.Invoke(1234);
		delete testCaller;
	}

	void BenchmarkScriptCaller() {
		ScriptCaller testCaller = ScriptCaller.Create(CallMeMaybe);
		testCaller.Invoke(1234);
		delete testCaller;
	}
	void BenchmarkReuseScriptCaller() {
		ReusetestCaller.Invoke(1234);
	}
	void BenchmarkReuseScriptInvoke() {
		ReusetestInvoker.Invoke(1234);
	}
}

#endif