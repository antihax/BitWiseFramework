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

void assert (bool condition, int value = 0, int expected = 0) {
	if (!condition) {
		string str;
		DumpStackString(str);
		if (value != 0)
			Print("Asset failed! " + value.ToString() + " != " + expected.ToString() + "\n" + str);
		else
			Print("Asset failed! Value: " + value + "\n" + str);
	}
}

void test_Bitstream() {

	int prev = TickCount(0);

	// Initialize BitStream
	FileSerializer fs = new FileSerializer();

	fs.Open("$profile:\BitWiseTest", FileMode.WRITE);
	BitStreamWriter bs = new BitStreamWriter(fs);

	assert (bs.WritePacked(true) == true);
	assert (bs.GetIndex() == 1, bs.GetIndex(), 1);
	assert (bs.WritePacked(true) == true);
	assert (bs.GetIndex() == 2, bs.GetIndex(), 2);
	assert (bs.WritePacked(false) == true);
	assert (bs.GetIndex() == 3, bs.GetIndex(), 3);

	// Test writing a 32-bit integer
	assert (bs.WriteUInt(2147483646, 31) == true);
	assert (bs.GetIndex() == 34, bs.GetIndex(), 34);

	// Test writing a 16-bit integer
	assert (bs.WriteUInt(65535, 16) == true);
	assert (bs.GetIndex() == 50, bs.GetIndex(), 50);

	// Test writing a 8-bit integer
	assert (bs.WriteUInt(255, 8) == true);
	assert (bs.GetIndex() == 58, bs.GetIndex(), 58);

	// Test writing a 1-bit integer
	assert (bs.WriteUInt(1, 1) == true);
	assert (bs.GetIndex() == 59, bs.GetIndex(), 59);

	assert (bs.WriteUInt(10, 31) == true);
	assert (bs.GetIndex() == 90, bs.GetIndex(), 90);

	assert (bs.WriteUInt(21474837, 31) == true);
	assert (bs.GetIndex() == 121, bs.GetIndex(), 121);

	vector vec = "1.3 2.4 2.7";

	assert (bs.WriteRangedInt(5, 1, 10) == true);
	assert (bs.WriteHalfFloat(1.2345) == true);
	assert (bs.WriteHalfVector(vec) == true);
	assert (bs.WriteSInt(-2147483648, 32) == true);
	assert (bs.WritePacked(true) == true);
	assert (bs.WritePacked(1.23456) == true);
	assert (bs.WritePacked(vec) == true);
	assert (bs.WritePacked("because my nostrils are quite sensitive") == true);

	while ((bs.GetIndex() - 1) % 32 != 0) {
		Print("Aligning...");
		bs.WritePacked(false);
	}

	for (int i = 0; i < 127; i++) {
		assert (bs.WriteUInt(i, 7) == true);
		if (i % 4)
			assert (bs.WritePacked(true) == true);
	}

	for (i = 0; i < 255; i++) {
		assert (bs.WriteUInt(i, 8) == true);
		if (i % 3)
			assert (bs.WritePacked(true) == true);
	}

	for (i = 0; i < 255; i++) {
		bool pk = i % 3;
		bs.WritePacked(pk);
	}

	// Test writing more than 31 bits
	// assert (bs.WriteUInt(2147483647, 32) == false);
	bs.Align();
	// bs.Dump();

	fs.Close();

	int written;
	fs.Open("$profile:\BitWiseTest", FileMode.READ);

	BitStreamReader bsr = new BitStreamReader(fs);

	int v;
	bool b;
	bsr.ReadBool(v);
	if (v == true) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadBool(v);
	if (v == true) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadBool(v);
	if (v == false) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadUInt(v, 31);
	if (v == 2147483646) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadUInt(v, 16);
	if (v == 65535) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadUInt(v, 8);
	if (v == 255) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadUInt(v, 1);
	if (v == 1) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadUInt(v, 31);
	if (v == 10) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadUInt(v, 31);
	if (v == 21474837) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}
	int f;
	float fval;
	vector vec2;

	bsr.ReadRangedInt(v, 1, 10);
	if (v == 5) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadHalfFloat(fval);
	if (fval.ToString() == "1.23438") {
		Print("Passed " + fval.ToString());
	} else {
		Print("Failed " + fval.ToString());
	}

	// We lose presicion here
	// Original value:  "1.3 2.4 2.7";
	bsr.ReadHalfVector(vec2);
	if (vec2.ToString() == "<1.299805, 2.398438, 2.699219>") {
		Print("Passed " + vec2.ToString());
	} else {
		Print("Failed " + vec2.ToString());
	}

	bsr.ReadSInt(v, 32);
	if (v == -2147483648) {
		Print("Passed " + v.ToString());
	} else {
		Print("Failed " + v.ToString());
	}

	bsr.ReadPacked(b);
	if (b == true) {
		Print("Passed " + b.ToString());
	} else {
		Print("Failed " + b.ToString());
	}

	bsr.ReadPacked(fval);
	if (fval == 1.23456) {
		Print("Passed " + fval.ToString());
	} else {
		Print("Failed " + fval.ToString());
	}

	bsr.ReadPacked(vec2);
	if (vec2 == vec) {
		Print("Passed " + vec2.ToString());
	} else {
		Print("Failed " + vec2.ToString());
	}

	string str;
	bsr.ReadPacked(str);
	if (str == "because my nostrils are quite sensitive") {
		Print("Passed " + str);
	} else {
		Print("Failed " + str);
	}

	// Align
	while ((bsr.GetIndex() - 1) % 32 != 0) {
		Print("Aligning...");
		bsr.ReadBool(v);
	}

	for (i = 0; i < 127; i++) {
		bsr.ReadUInt(v, 7);
		if (v == i) {
			Print("Passed " + v.ToString());
		} else {
			f++;
			Print("Failed " + v.ToString());
		}
		if (i % 4) {
			bsr.ReadBool(v);
			if (v != true) {
				f++;
				Print("Failed bool " + v.ToString());
			}
		}
	}

	for (i = 0; i < 255; i++) {
		bsr.ReadUInt(v, 8);
		if (v == i) {
			Print("Passed " + v.ToString());
		} else {
			f++;
			Print("Failed " + v.ToString());
		}
		if (i % 3) {
			bsr.ReadBool(v);
			if (v != true) {
				f++;
				Print("Failed bool " + v.ToString());
			}
		}
	}

	for (i = 0; i < 255; i++) {
		bsr.ReadBool(v);
		if (v == !!(i % 3)) {
			Print("Passed " + v.ToString());
		} else {
			f++;
			Print("Failed " + v.ToString());
		}
	}

	Print("Total failed: " + f.ToString());

	int time = TickCount(prev);
	int estimatedMil = (int)(time / 10000.0);
	Print("Tests took " + time + " ticks (" + estimatedMil + "ms)");
}
#endif
