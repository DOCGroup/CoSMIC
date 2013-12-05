# Microsoft Developer Studio Project File - Name="SvcConfExporterTest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=SvcConfExporterTest - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE run the tool that generated this project file and specify the
!MESSAGE nmake output type.  You can then use the following command:
!MESSAGE
!MESSAGE NMAKE /f "SvcConfExporterTest.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "SvcConfExporterTest.mak" CFG="SvcConfExporterTest - Win32 Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "SvcConfExporterTest - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "SvcConfExporterTest - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SvcConfExporterTest - Win32 Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release\SvcConfExporterTest"
# PROP Target_Dir ""
# ADD CPP /nologo /O2 /W3 /GX /MD /GR /D NDEBUG /D WIN32 /D _CONSOLE /FD /c
# SUBTRACT CPP /YX

# ADD MTL /D "NDEBUG" /nologo /mktyplib203 /win32
# ADD RSC /l 0x409 /d NDEBUG
BSC32=bscmake.exe
# ADD BSC32 /nologo 
LINK32=link.exe
# ADD LINK32 advapi32.lib user32.lib /INCREMENTAL:NO OCMLSvcConfExporter.lib /libpath:"$(PICML_ROOT)\lib" /libpath:"$(PICML_ROOT)\bin" /nologo /version:1.0 /subsystem:console /pdb:"Release\svc_conf_exporter.pdb"  /machine:I386 /out:"Release\svc_conf_exporter.exe"

!ELSEIF  "$(CFG)" == "SvcConfExporterTest - Win32 Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "."
# PROP Intermediate_Dir "Debug\SvcConfExporterTest"
# PROP Target_Dir ""
# ADD CPP /nologo /Ob0 /W3 /Gm /GX /Zi /MDd /GR /Gy /D _DEBUG /D WIN32 /D _CONSOLE /FD /c
# SUBTRACT CPP /YX

# ADD MTL /D "_DEBUG" /nologo /mktyplib203 /win32
# ADD RSC /l 0x409 /d _DEBUG
BSC32=bscmake.exe
# ADD BSC32 /nologo 
LINK32=link.exe
# ADD LINK32 advapi32.lib user32.lib /INCREMENTAL:NO OCMLSvcConfExporterd.lib /libpath:"$(PICML_ROOT)\lib" /libpath:"$(PICML_ROOT)\bin" /nologo /version:1.0 /subsystem:console /pdb:".\svc_conf_exporter.pdb" /debug /machine:I386 /out:".\svc_conf_exporter.exe"

!ENDIF

# Begin Target

# Name "SvcConfExporterTest - Win32 Release"
# Name "SvcConfExporterTest - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE="main.cpp"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE="..\SvcConfExporter.hpp"
# End Source File
# End Group
# End Target
# End Project
