# Microsoft Developer Studio Project File - Name="OCMLConfigurator" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=OCMLConfigurator - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OCMLConfigurator.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OCMLConfigurator.mak" CFG="OCMLConfigurator - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OCMLConfigurator - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "OCMLConfigurator - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "OCMLConfigurator - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\..\lib"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "$(XERCESCROOT)\include" /I "$(WXWINDOWS_ROOT)\include" /I "$(WXWINDOWS_ROOT)\lib\mswd" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "OCML_CONFIGURATOR_DLL_ENTRY_EXPORTS" /D "_USRDLL" /D "WXMAKINGDLL" /FD /c
# SUBTRACT CPP /YX
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "$(XERCESCROOT)\include" /i "$(WXWINDOWS_ROOT)\include" /i "$(WXWINDOWS_ROOT)\lib\mswd" /d "NDEBUG" /d "OCML_CONFIGURATOR_DLL_ENTRY_EXPORTS" /d "_USRDLL" /d "WXMAKINGDLL"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 xerces-c_2_5.lib shell32.lib Comdlg32.lib Advapi32.lib ole32.lib user32.lib gdi32.lib comctl32.lib wsock32.lib rpcrt4.lib wxmsw.lib /nologo /version:1.0 /subsystem:windows /dll /pdb:"$(COSMIC_ROOT)\bin\OCMLConfigurator.pdb" /machine:I386 /out:"..\..\..\..\..\bin\OCMLConfigurator.dll" /libpath:"$(XERCESCROOT)\lib" /libpath:"$(WXWINDOWS_ROOT)\lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "OCMLConfigurator - Win32 Debug"

# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\..\lib"
# PROP Intermediate_Dir "Debug\OCMLConfigurator"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Gy /I "$(XERCESCROOT)\include" /I "$(WXWINDOWS_ROOT)\include" /I "$(WXWINDOWS_ROOT)\lib\mswd" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "OCML_CONFIGURATOR_DLL_ENTRY_EXPORTS" /D "_USRDLL" /D "WXMAKINGDLL" /D "_WINDLL" /D "_AFXDLL" /FD /c
# SUBTRACT CPP /Fr /YX
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "$(XERCESCROOT)\include" /i "$(WXWINDOWS_ROOT)\include" /i "$(WXWINDOWS_ROOT)\lib\mswd" /d "_DEBUG" /d "OCML_CONFIGURATOR_DLL_ENTRY_EXPORTS" /d "_USRDLL" /d "WXMAKINGDLL" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 xerces-c_2_5D.lib shell32.lib Comdlg32.lib Advapi32.lib ole32.lib user32.lib gdi32.lib comctl32.lib wsock32.lib rpcrt4.lib wxmswd.lib /nologo /version:1.0 /subsystem:windows /dll /incremental:no /pdb:"$(COSMIC_ROOT)\bin\OCMLConfiguratord.pdb" /debug /machine:I386 /out:"..\..\..\..\..\bin\OCMLConfiguratord.dll" /libpath:"$(XERCESCROOT)\lib" /libpath:"$(WXWINDOWS_ROOT)\lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "OCMLConfigurator - Win32 Release"
# Name "OCMLConfigurator - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE="Options\BasicOptions.cpp"
# End Source File
# Begin Source File

SOURCE="EditControls\BooleanEditControl.cpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\BooleanOptionEditor.cpp"
# End Source File
# Begin Source File

SOURCE="EditControls\ClearButton.cpp"
# End Source File
# Begin Source File

SOURCE="Configurator.cpp"
# End Source File
# Begin Source File

SOURCE="..\Common\Debug.cpp"
# End Source File
# Begin Source File

SOURCE="Options\DescribedItem.cpp"
# End Source File
# Begin Source File

SOURCE="DllEntry.cpp"
# End Source File
# Begin Source File

SOURCE="EditControls\EnumEditControl.cpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\EnumOptionEditor.cpp"
# End Source File
# Begin Source File

SOURCE="EditControls\IntegerEditControl.cpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\IntegerOptionEditor.cpp"
# End Source File
# Begin Source File

SOURCE="MainApp.cpp"
# End Source File
# Begin Source File

SOURCE="MainFrame.cpp"
# End Source File
# Begin Source File

SOURCE="Options\Option.cpp"
# End Source File
# Begin Source File

SOURCE="Options\OptionCategory.cpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\OptionEditorPanel.cpp"
# End Source File
# Begin Source File

SOURCE="EditControls\StringEditControl.cpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\StringOptionEditor.cpp"
# End Source File
# Begin Source File

SOURCE="Options\TreeParser.cpp"
# End Source File
# Begin Source File

SOURCE="Options\ValueParser.cpp"
# End Source File
# Begin Source File

SOURCE="..\Common\XercesHelpers.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE="Options\BasicOptions.hpp"
# End Source File
# Begin Source File

SOURCE="EditControls\BooleanEditControl.hpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\BooleanOptionEditor.hpp"
# End Source File
# Begin Source File

SOURCE="EditControls\ClearButton.hpp"
# End Source File
# Begin Source File

SOURCE="Configurator.hpp"
# End Source File
# Begin Source File

SOURCE="..\Common\Debug.hpp"
# End Source File
# Begin Source File

SOURCE="Options\DescribedItem.hpp"
# End Source File
# Begin Source File

SOURCE="DllEntry.hpp"
# End Source File
# Begin Source File

SOURCE="EditControls\EnumEditControl.hpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\EnumOptionEditor.hpp"
# End Source File
# Begin Source File

SOURCE="EditControls\IntegerEditControl.hpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\IntegerOptionEditor.hpp"
# End Source File
# Begin Source File

SOURCE="main.hpp"
# End Source File
# Begin Source File

SOURCE="MainApp.hpp"
# End Source File
# Begin Source File

SOURCE="MainFrame.hpp"
# End Source File
# Begin Source File

SOURCE="Options\Option.hpp"
# End Source File
# Begin Source File

SOURCE="Options\OptionCategory.hpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\OptionEditor.hpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\OptionEditorPanel.hpp"
# End Source File
# Begin Source File

SOURCE="Options\Options.hpp"
# End Source File
# Begin Source File

SOURCE="EditControls\StringEditControl.hpp"
# End Source File
# Begin Source File

SOURCE="OptionEditors\StringOptionEditor.hpp"
# End Source File
# Begin Source File

SOURCE="..\Common\StringUtils.hpp"
# End Source File
# Begin Source File

SOURCE="..\Common\StringUtils.ipp"
# End Source File
# Begin Source File

SOURCE="Options\TreeParser.hpp"
# End Source File
# Begin Source File

SOURCE="Options\ValueParser.hpp"
# End Source File
# Begin Source File

SOURCE="..\Common\XercesHelpers.hpp"
# End Source File
# Begin Source File

SOURCE="..\Common\XercesHelpers.ipp"
# End Source File
# End Group
# End Target
# End Project
