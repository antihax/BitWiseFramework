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
void test_Endpoints() {
#ifdef SERVER
	BitWiseScriptRPC rpc1 = BitWiseScriptRPC.New("BITWISE", "servertest1");
	BitWiseScriptRPC rpc2 = BitWiseScriptRPC.New("BITWISE", "servertest2");
	BitWiseScriptRPC rpc3 = BitWiseScriptRPC.New("BITWISE", "servertest3");
	BitWiseScriptRPC rpc4 = BitWiseScriptRPC.New("BITWISE", "servertest4");
	rpc1.Send(NULL, true);
	rpc2.Send(NULL, true);
	rpc3.Send(NULL, true);
	rpc4.Send(NULL, true);
#else
	BitWiseScriptRPC rpc = BitWiseScriptRPC.New("BITWISE", "clienttest1");
	rpc.Send(NULL, true);
#endif
}
#endif