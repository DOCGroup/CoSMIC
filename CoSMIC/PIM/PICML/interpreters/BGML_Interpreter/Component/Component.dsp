# Microsoft Developer Studio Project File - Name="Component" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Component - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Component.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Component.mak" CFG="Component - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Component - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Component - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Component - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Component - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "C:/Program Files/GME/sdk/BON/" /I "C:\Program Files\ISIS\UDM\include" /I "C:\Program Files\ISIS\UDM\3rdParty\stl" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "GME_INTERPRETER_USED" /D "UML_CLASS_DIAGRAM" /FD /GZ /Zm200 /c
# SUBTRACT CPP /Fr
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 mfcs42d.lib MSVCRTD.lib xerces-c_2D.lib ZlibD.lib UdmBase_D.lib UdmDom_D.lib UdmUtil_D.lib UdmGme_D.lib /nologo /subsystem:windows /dll /debug /machine:I386 /nodefaultlib:"MSVCRTD.lib" /nodefaultlib:"mfcs42d.lib" /pdbtype:sept /libpath:"C:\Program Files\ISIS\UDM\lib" /libpath:"C:\Program Files\ISIS\UDM\3rdParty\zlib" /libpath:"C:\Program Files\ISIS\UDM\3rdParty\xerces\xerces-c2_2_0-win32\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=.\Debug\Component.dll
InputPath=.\Debug\Component.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Component - Win32 Release MinSize"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinSize"
# PROP BASE Intermediate_Dir "ReleaseMinSize"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinSize"
# PROP Intermediate_Dir "ReleaseMinSize"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O1 /I ".\\" /I "C:/Program Files/GME/sdk/BON/" /I "C:\Program Files\ISIS\UDM\include" /I "C:\Program Files\ISIS\UDM\3rdParty\stl" /D "NDEBUG" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "GME_INTERPRETER_USED" /D "UML_CLASS_DIAGRAM" /FR /FD /Zm200 /c
# ADD CPP /nologo /MD /W3 /GX /O1 /I ".\\" /I "C:/Program Files/GME/sdk/BON/" /I "C:\Program Files\ISIS\UDM\include" /I "C:\Program Files\ISIS\UDM\3rdParty\stl" /D "NDEBUG" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "GME_INTERPRETER_USED" /D "UML_CLASS_DIAGRAM" /FR /FD /Zm200 /c
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 xerces-c_2.lib Zlib.lib /nologo /subsystem:windows /dll /machine:I386 /out:"Release/Component.dll" /libpath:"C:\Program Files\ISIS\UDM\3rdParty\zlib" /libpath:"C:\Program Files\ISIS\UDM\3rdParty\xerces\xerces-c2_2_0-win32\lib"
# ADD LINK32 xerces-c_2.lib Zlib.lib UdmBase.lib UdmDom.lib UdmUtil.lib UdmGme.lib /nologo /subsystem:windows /dll /machine:I386 /libpath:"C:\Program Files\ISIS\UDM\lib" /libpath:"C:\Program Files\ISIS\UDM\3rdParty\zlib" /libpath:"C:\Program Files\ISIS\UDM\3rdParty\xerces\xerces-c2_2_0-win32\lib"
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinSize
TargetPath=.\ReleaseMinSize\Component.dll
InputPath=.\ReleaseMinSize\Component.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Component - Win32 Release MinDependency"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinDependency"
# PROP BASE Intermediate_Dir "ReleaseMinDependency"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinDependency"
# PROP Intermediate_Dir "ReleaseMinDependency"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FD /c
# ADD CPP /nologo /MD /W3 /GX /I "C:\Program Files\ISIS\UDM\include" /I "C:\Program Files\ISIS\UDM\3rdParty\stl" /D "NDEBUG" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FD /GZ /Zm200 /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 xerces-c_2.lib zlib.lib UdmBase.lib UdmGme.lib UdmUtil.lib UdmDom.lib /nologo /subsystem:windows /dll /machine:I386 /libpath:"C:\Program Files\ISIS\UDM\Lib" /libpath:"C:\Program Files\ISIS\UDM\3rdParty\xerces\xerces-c2_2_0-win32\lib" /libpath:"C:\Program Files\ISIS\UDM\3rdparty\zlib"
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\ReleaseMinDependency\Component.dll
InputPath=.\ReleaseMinDependency\Component.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "Component - Win32 Debug"
# Name "Component - Win32 Release MinSize"
# Name "Component - Win32 Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Benchmark_Stream.cpp
# End Source File
# Begin Source File

SOURCE=.\BGML_Visitor.cpp
# End Source File
# Begin Source File

SOURCE=.\ComHelp.cpp
# End Source File
# Begin Source File

SOURCE=.\Component.def
# End Source File
# Begin Source File

SOURCE=.\Component.rc
# End Source File
# Begin Source File

SOURCE=.\ComponentDll.cpp
# End Source File
# Begin Source File

SOURCE=.\ComponentLib.idl

!IF  "$(CFG)" == "Component - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath=.\ComponentLib.idl

BuildCmds= \
	midl /server none /client none ComponentLib.idl

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Component - Win32 Release MinSize"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath=.\ComponentLib.idl

BuildCmds= \
	midl /server none /client none ComponentLib.idl

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Component - Win32 Release MinDependency"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath=.\ComponentLib.idl

BuildCmds= \
	midl /server none /client none ComponentLib.idl

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ComponentObj.cpp
# End Source File
# Begin Source File

SOURCE=.\IDL_Util.cpp
# End Source File
# Begin Source File

SOURCE=.\MetricEmitter.cpp
# End Source File
# Begin Source File

SOURCE=.\PICML.cpp
# End Source File
# Begin Source File

SOURCE=.\RawComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TypeEmitter.cpp
# End Source File
# Begin Source File

SOURCE=.\UdmApp.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Benchmark_Stream.h
# End Source File
# Begin Source File

SOURCE=.\BGML_Visitor.h
# End Source File
# Begin Source File

SOURCE=.\ComHelp.h
# End Source File
# Begin Source File

SOURCE=.\ComponentConfig.h
# End Source File
# Begin Source File

SOURCE=.\ComponentDll.h
# End Source File
# Begin Source File

SOURCE=.\ComponentObj.h
# End Source File
# Begin Source File

SOURCE=.\GMECOM.H
# End Source File
# Begin Source File

SOURCE=.\IDL_Util.h
# End Source File
# Begin Source File

SOURCE=.\MetricEmitter.h
# End Source File
# Begin Source File

SOURCE=.\PICML.h
# End Source File
# Begin Source File

SOURCE=.\RawComponent.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TypeEmitter.h
# End Source File
# Begin Source File

SOURCE=.\UdmApp.h
# End Source File
# Begin Source File

SOURCE=.\UdmConfig.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\CompIcon.ico
# End Source File
# End Group
# End Target
# End Project
