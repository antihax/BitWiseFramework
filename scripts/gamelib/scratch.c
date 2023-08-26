#ifdef BITWISEDEBUG
#ifdef SERVER
[BitWiseScratchPad()] class BitWiseScratchPad {
	void BitWiseScratchPad() {
		int h = BitWiseHelpers.FloatToHalf(1.2345);
		Print(BitWiseHelpers.BitRepresentation(h));
		float f = BitWiseHelpers.HalfToFloat(h);
		Print((1.2345).ToString() + " " + f.ToString());
	}
}
#endif
#endif