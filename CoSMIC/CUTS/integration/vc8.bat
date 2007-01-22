@rem *********************************************
@rem ** Build the vc8 version of CUTS
@rem *********************************************

@setlocal
@call "%VS80COMNTOOLS%vsvars32.bat"

@ant -buildfile %CUTS_ROOT%\integration\autobuild.build ^
-Dmpc.type=vc8 ^
-Dresults.log=%CUTS_ROOT%\integration\logs\vc8.build.log ^
-logfile %CUTS_ROOT%\integration\logs\vc8.build.xml ^
-logger org.apache.tools.ant.DefaultLogger ^
build

@endlocal
