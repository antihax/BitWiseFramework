@echo off
taskkill /im DayZDiag_x64.exe /F
rmdir /s /q p:\BitWiseFramework\docs\
mkdir p:\BitWiseFramework\docs\
doxygen
DayZInput.ps1
rem call npx moxygen --anchors --output="p:\BitWiseFramework\docs\README.md" "p:\BitWiseFramework\Source\tempdocs\xml"
doxybook2 --input=p:\BitWiseFramework\Source\tempdocs\xml --output=p:\BitWiseFramework\docs\ --config config.json

set modpath=%DAYZ%%\!Workshop
set srcpath=P:\BitWiseFramework
set path2=P:\BitWiseFramework\Source\dist
set exportPath=p:\BitWiseFramework\Source\dist\BitWiseFramework
set allclientmods=
set allclientmods=%modpath%\@CF;%modpath%\@VanillaPlusPlusMap;%modpath%\@VPPAdminTools;%modpath%\@BaseBuildingPlus;%modpath%\@MuchStuffPack;%modpath%\@RedFalcon Flight System Heliz;%modpath%\@Airdrop-Upgraded;%modpath%\@DNA_Keycards;%modpath%\@RUSForma_vehicles;%modpath%\@eAI;
set currentMod=%path2%\BitWiseFramework;

%DAYZTOOLS%\Bin\CfgConvert\CfgConvert.exe -bin -dst %srcpath%\config.bin  %srcpath%\config.cpp
pboProject.exe -P +e="dayzSA" +Z +C -B +K +J +T +M="%exportPath%" +K="%DAYZPRIVATEKEY%" "%srcpath%" 

set profileFolder=%DAYZ%\dayzOffline.chernarusplus\profiles
set profileFolderClient=%DAYZ%\mpmissions\dayzOffline.chernarusplus\profilesClient
set configPath=%DAYZ%\mpmissions\dayzOffline.chernarusplus\serverDZ.cfg

 start %DAYZ%\DayZDiag_x64.exe "-server" "-mod=%currentMod%%allclientmods%" "-cpuCount=32"  "-config=%configPath%" "-profiles=%profileFolder%" -doLogs -newErrorsAreWarnings=1 -nosplash -noPause -filePatching -scrDef=BITWISEDEBUG
rem start %DAYZSERVER%\DayZServer_x64.exe "-server" "-mod=%currentMod%%allclientmods%" "-cpuCount=32"  "-config=%configPath%" "-profiles=%profileFolder%" -doLogs -nosplash -noPause -filePatching 
 start %DAYZ%\DayZDiag_x64.exe "-mod=%currentMod%%allclientmods%" "-cpuCount=32" "-connect=127.0.0.1" "-port=2302" "-profiles=%profileFolderClient%" -dologs -newErrorsAreWarnings=1  -nosplash -noPause -filePatching -scrDef=BITWISEDEBUG