set driverLetter=%~dp0
set driverLetter=%driverLetter:~0,2%
%driverLetter%
cd %~dp0
set str=%2
set str=%str:/=\%
set commport=%1
set commportnum=%commport:COM=%
GD32_ISP_CLI\GD32_ISP_CLI.exe  -c --pn %commportnum% --br 57600 --db 8 --pr EVEN --sb 1 --to 5000 -p --dwp -d --a 8000000 --fn %str% --v
