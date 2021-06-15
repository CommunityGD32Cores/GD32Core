rem: @echo off
rem: Note %~dp0 get path of this batch file
rem: Need to change drive if My Documents is on a drive other than C:
set driverLetter=%~dp0
set driverLetter=%driverLetter:~0,2%
%driverLetter%
cd %~dp0
rem: the two line below are needed to fix path issues with incorrect slashes before the bin file name
set tmpBinFilePath=%1
set tmpBinFilePath=%tmpBinFilePath:/=\%

rem: create commander script file with the tmp bin that the Arduino IDE creates

@echo erase > %tmpbinfilepath%.jlink
@echo loadbin %tmpbinfilepath% , 0x8000000 >> %tmpbinfilepath%.jlink
@echo setpc 0x8000000 >> %tmpbinfilepath%.jlink
:: @echo rx 100 >> %tmpbinfilepath%.jlink
@echo g >> %tmpbinfilepath%.jlink
@echo q >> %tmpbinfilepath%.jlink

jlink_V6.50b\JLink.exe -device GD32VF103VBT6 -if JTAG -JTAGConf -1,-1 -speed auto -CommanderScript %tmpBinFilePath%.jlink