# Microsoft Developer Studio Project File - Name="SvcConfExporter" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=SvcConfExporter - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SvcConfExporter.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SvcConfExporter.mak" CFG="SvcConfExporter - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SvcConfExporter - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "SvcConfExporter - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SvcConfExporter - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\..\..\lib"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "$(XERCESCROOT)\include" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "SVC_CONF_EXPORTER_DLL_ENTRY_EXPORTS" /D "_USRDLL" /D "WXMAKINGDLL" /FD /c
# SUBTRACT CPP /YX
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "$(XERCESCROOT)\include" /d "NDEBUG" /d "SVC_CONF_EXPORTER_DLL_ENTRY_EXPORTS" /d "_USRDLL" /d "WXMAKINGDLL"
BSC32=bscmake.exe
# ADD BSC32 /nologo /o"$(PICML_ROOT)\lib\OCMLSvcConfExporter.bsc"
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 advapi32.lib user32.lib xerces-c_2.lib /nologo /version:1.0 /subsystem:windows /dll /pdb:"$(PICML_ROOT)\bin\OCMLSvcConfExporter.pdb" /machine:I386 /out:"..\..\..\..\..\PIM\PICML\bin\OCMLSvcConfExporter.dll" /libpath:"$(XERCESCROOT)\lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "SvcConfExporter - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\..\..\lib"
# PROP Intermediate_Dir "Debug\SvcConfExporter"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /Zi /Gy /I "$(XERCESCROOT)\include" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "SVC_CONF_EXPORTER_DLL_ENTRY_EXPORTS" /D "_USRDLL" /D "WXMAKINGDLL" /FD /c
# SUBTRACT CPP /Fr /YX
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409
# ADD RSC /l 0x409 /i "$(XERCESCROOT)\include" /d "_DEBUG" /d "SVC_CONF_EXPORTER_DLL_ENTRY_EXPORTS" /d "_USRDLL" /d "WXMAKINGDLL"
BSC32=bscmake.exe
# ADD BSC32 /nologo /o"$(PICML_ROOT)\lib\OCMLSvcConfExporter.bsc"
LINK32=link.exe
# ADD BASE LINK32 /machine:IX86
# ADD LINK32 advapi32.lib user32.lib xerces-c_2d.lib /nologo /version:1.0 /subsystem:windows /dll /incremental:no /pdb:"$(PICML_ROOT)\bin\OCMLSvcConfExporterd.pdb" /debug /machine:I386 /out:"..\..\..\..\..\PIM\PICML\bin\OCMLSvcConfExporterd.dll" /libpath:"$(XERCESCROOT)\lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "SvcConfExporter - Win32 Release"
# Name "SvcConfExporter - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE="SvcConfExporter.cpp"
# End Source File
# Begin Source File

SOURCE="..\Common\XercesHelpers.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE="extern_declarations.hpp"
# End Source File
# Begin Source File

SOURCE="..\Common\StringUtils.hpp"
# End Source File
# Begin Source File

SOURCE="..\Common\StringUtils.ipp"
# End Source File
# Begin Source File

SOURCE="SvcConfExporter.hpp"
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
