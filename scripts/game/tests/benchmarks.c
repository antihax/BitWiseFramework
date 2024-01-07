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
class BitWiseBenchmarks {
	autoptr ScriptInvoker ReusetestInvoker;
	autoptr ScriptCaller ReusetestCaller;

	void BitWiseBenchmarks() {
		// Initialize BitStream
		FileSerializer fsbw = new FileSerializer();
		FileSerializer fs = new FileSerializer();
		FileSerializer fscf = new FileSerializer();
		fsbw.Open("$profile:\FSWiseTestBW", FileMode.WRITE);
		fs.Open("$profile:\FSWiseTest", FileMode.WRITE);
		fscf.Open("$profile:\FSWiseTestCF", FileMode.WRITE);

		// Simulate RPC
		fs.Write(10000);

		// Simulate RPC
		fscf.Write(10042);
		fscf.Write("ModName");
		fscf.Write("FuncName");

		// Simulate RPC
		fsbw.Write(RPC_ANTIHAX_BITWISE);
		fsbw.Write(123);

		BitStreamWriter bs = new BitStreamWriter(fsbw);
		for (int i = 0; i < 10; i++) {
			bs.WritePacked(true);
			fs.Write(true);
			fscf.Write(true);
		}
		for (i = 0; i < 10; i++) {
			bs.WriteRangedInt(i, 0, 10);
			fs.Write(i);
			fscf.Write(i);
		}
		bs.WritePacked("Test String");
		fs.Write("Test String");
		fscf.Write("Test String");

		fsbw.Close();
		fscf.Close();
		fs.Close();
	}
	void Run() {
		ReusetestCaller = ScriptCaller.Create(CallMeMaybe);
		ReusetestInvoker = new ScriptInvoker();
		ReusetestInvoker.Insert(CallMeMaybe);

		float time;
		int i;

		for (i = 0; i < 1000000; ++i) {
			BenchmarkScriptInvoker();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkScriptInvoker", Type(), true);
		Print("BenchmarkScriptInvoker took " + time.ToString());

		for (i = 0; i < 1000000; ++i) {
			BenchmarkScriptCaller();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkScriptCaller", Type(), true);
		Print("BenchmarkScriptCaller took " + time.ToString());

		for (i = 0; i < 1000000; ++i) {
			BenchmarkCallFunction();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkCallFunction", Type(), true);
		Print("BenchmarkCallFunction took " + time.ToString());

		for (i = 0; i < 1000000; ++i) {
			BenchmarkReuseScriptCaller();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkReuseScriptCaller", Type(), true);
		Print("BenchmarkReuseScriptCaller took " + time.ToString());

		for (i = 0; i < 1000000; ++i) {
			BenchmarkReuseScriptInvoke();
		}
		time = EnProfiler.GetTimeOfFunc("BenchmarkReuseScriptInvoke", Type(), true);
		Print("BenchmarkReuseScriptInvoke took " + time.ToString());
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
		autoptr ScriptInvoker testCaller = new ScriptInvoker();
		testCaller.Insert(CallMeMaybe);
		testCaller.Invoke(1234);
	}

	void BenchmarkScriptCaller() {
		autoptr ScriptCaller testCaller = ScriptCaller.Create(CallMeMaybe);
		testCaller.Invoke(1234);
	}
	void BenchmarkReuseScriptCaller() {
		ReusetestCaller.Invoke(1234);
	}
	void BenchmarkReuseScriptInvoke() {
		ReusetestInvoker.Invoke(1234);
	}
}
#endif
