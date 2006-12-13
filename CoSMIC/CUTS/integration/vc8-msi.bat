@call "%VS80COMNTOOLS%vsvars32.bat"

@rem *********************************************
@rem ** Build the vc8 version of CUTS
@rem *********************************************

"%NANT_ROOT%\bin\nant" -buildfile:%CUTS_ROOT%\integration\autobuild.build ^
-D:ACE_ROOT=%ACE_ROOT% ^
-D:TAO_ROOT=%TAO_ROOT% ^
-D:CIAO_ROOT=%CIAO_ROOT% ^
-D:COSMIC_ROOT=%COSMIC_ROOT% ^
-D:CUTS_ROOT=%CUTS_ROOT% ^
-D:mpc.type=vc8 ^
-D:results.log=%CUTS_ROOT%\integration\logs\vc8-msi.build.log ^
-logfile:%CUTS_ROOT%\integration\logs\vc8-msi.build.xml ^
-nologo -verbose ^
-logger:NAnt.Core.XmlLogger ^
build.installers
