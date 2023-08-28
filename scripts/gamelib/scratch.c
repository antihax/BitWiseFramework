#ifdef BITWISEDEBUG
#ifdef SERVER
[BitWiseScratchPad()] class BitWiseScratchPad {
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