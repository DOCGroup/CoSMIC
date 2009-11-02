@echo off
@echo This is a test for IDL importer (idl_to_picml.exe). 
@echo This script runs it as described in the CoSMIC tutorial available at 
@echo http://www.dre.vanderbilt.edu/cosmic/tutorials/index.html
@echo ====================================================================

if "%COSMIC_ROOT%!" == "!"                      goto no_cosmic_root
if not exist %COSMIC_ROOT%\bin\idl_to_picml.exe goto no_exe
if not exist %COSMIC_ROOT%\bin\sed.exe          goto no_sed

cd %COSMIC_ROOT%\tests\MyQuoter

if exist Broker.idl                 del Broker.idl
if exist Distributor.idl            del Distributor.idl
if exist Stock_Base.idl             del Stock_Base.idl 
if exist PICML_default_xme_file.xme del PICML_default_xme_file.xme
if exist MyQuoter.xme               del MyQuoter.xme

@echo Running Test #1: idl_to_picml -r .
%COSMIC_ROOT%\bin\idl_to_picml.exe -r .
@echo ====================================================================

@echo Running Test #2: idl_to_picml -x MyQuoter Stock_Base.idl Broker.idl Distributor.idl
copy Stock_Base\Stock_Base.idl .   > nul

REM Comment out Components.idl include file using sed's search and replace
%COSMIC_ROOT%\bin\sed.exe -e   s,#include,//#include,   Stock_Base\Stock_Base.idl >  Stock_Base.idl

REM Remove unwanted directory paths using sed's search and replace
%COSMIC_ROOT%\bin\sed.exe -e   s,../Stock_Base/,,       Broker\Broker.idl >  Broker.idl
%COSMIC_ROOT%\bin\sed.exe -e   s,../Stock_Base/,,       Distributor\Distributor.idl > Distributor.idl

REM Run idl_to_picml.exe on the preprocessed idl files.
%COSMIC_ROOT%\bin\idl_to_picml.exe -x MyQuoter Stock_Base.idl Broker.idl Distributor.idl

goto exit

:no_sed
echo Can't find %COSMIC_ROOT%\bin\sed.exe
goto exit

:no_exe
echo Can't find %COSMIC_ROOT%\bin\idl_to_picml.exe
goto exit

:no_cosmic_root
echo Please set COSMIC_ROOT
goto exit

:exit
