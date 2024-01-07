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
[BitWiseScratchPad()]
class BitWiseScratchPad {
	void BitWiseScratchPad() {
		// Initialize BitStream
		FileSerializer fs = new FileSerializer();
		fs.Open("$profile:\FSWiseTest", FileMode.WRITE);
		for (int i = 0; i < 10; i++) {
			fs.Write(!!true);
		}
		for (i = 0; i < 10; i++) {
			fs.Write(i);
		}
		fs.Write("Test String");
		fs.Close();
	}
}
#endif
#endif