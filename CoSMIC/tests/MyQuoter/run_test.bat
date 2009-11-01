@echo off
@echo This is a test for IDL importer (idl_to_picml.exe). 
@echo This script runs it as described in the CoSMIC tutorial available at 
@echo http://www.dre.vanderbilt.edu/cosmic/tutorials/index.html
@echo ====================================================================

if "%COSMIC_ROOT%!" == "!"                      goto no_cosmic_root
if not exist %COSMIC_ROOT%\bin\idl_to_picml.exe goto no_exe
if not exist %COSMIC_ROOT%\bin\sed.exe          goto no_sed

cd %COSMIC_ROOT%\tests\MyQuoter
copy Stock_Base\Stock_Base.idl .   > nul

REM Comment out #include from the idl files using sed's search and replace
%COSMIC_ROOT%\bin\sed.exe -e s,#include,//#include,g Broker\Broker.idl >  Broker.idl
%COSMIC_ROOT%\bin\sed.exe -e s,#include,//#include,g Distributor\Distributor.idl > Distributor.idl
%COSMIC_ROOT%\bin\idl_to_picml.exe -x MyQuoter Stock_Base.idl Broker.idl Distributor.idl
goto exit

:no_sed
echo Can't find %COSMIC_ROOT%\bin\sed.exe
goto exit

:no_exe
echo Can't find %COSMIC_ROOT%\bin\idl_to_picml.exe
goto exit

:no_cosmic_root
echo "Please set COSMIC_ROOT"
goto exit

:exit
