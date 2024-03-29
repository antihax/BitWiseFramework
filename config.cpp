class CfgPatches {
	class BitWiseFramework {
		requiredAddons[] = {};
	};
};

class CfgMods {
	class BitWiseFramework {
		type = "mod";

		class defs {
			// Keep these in order of execution for reference.
			class engineScriptModule {
				files[] = { "BitWiseFramework\scripts\engine" };
			};
			class gameLibScriptModule {
				files[] = { "BitWiseFramework\scripts\gamelib" };
			};
			class gameScriptModule {
				files[] = { "BitWiseFramework\scripts\game" };
			};
			class worldScriptModule {
				files[] = { "BitWiseFramework\scripts\world" };
			};
			class missionScriptModule {
				files[] = { "BitWiseFramework\scripts\mission" };
			};
		};
	};
};
