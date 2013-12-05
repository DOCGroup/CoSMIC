# Microsoft Developer Studio Project File - Name="CADML" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=CADML - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "CADMLBONComponent.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "CADMLBONComponent.mak" CFG="CADML - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CADML - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CADML - Win32 Release MinSize" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "CADML - Win32 Release MinDependency" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "CADML - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I ".\\" /I "$(GME_ROOT)/sdk/BON/" /I "$(UDM_ROOT)/3rdParty/stl" /I "$(UDM_ROOT)/include" /I "$(XERCES_ROOT)/include" /I "$(XALAN_ROOT)/src" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "BUILDER_OBJECT_NETWORK" /FR /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 xerces-c_2D.lib UdmBase_D.lib UdmGME_D.lib UdmDom_D.lib UdmUtil_D.lib Xalan-C_1D.lib /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../bin/CADML.dll" /pdbtype:sept /libpath:"$(UDM_ROOT)/lib" /libpath:"$(XERCES_ROOT)/lib" /libpath:"$(XALAN_ROOT)\Build\Win32\VC6\Debug"
# SUBTRACT LINK32 /incremental:no /nodefaultlib
# Begin Custom Build - Performing registration
OutDir=.\Debug
TargetPath=\Documents and Settings\tao lou\My Documents\CADML\bin\CADML.dll
InputPath=\Documents and Settings\tao lou\My Documents\CADML\bin\CADML.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "CADML - Win32 Release MinSize"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMinSize"
# PROP BASE Intermediate_Dir "ReleaseMinSize"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMinSize"
# PROP Intermediate_Dir "ReleaseMinSize"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O1 /I ".\\" /I "$(GME_ROOT)/sdk/BON/" /I "$(UDM_ROOT)/3rdParty/stl" /I "$(UDM_ROOT)/include" /I "$(XERCES_ROOT)/include" /I "$(XALAN_ROOT)/src" /D "NDEBUG" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "BUILDER_OBJECT_NETWORK" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 xerces-c_2.lib UdmBase.lib UdmGME.lib UdmDom.lib UdmUtil.lib Xalan-C_1.lib /nologo /subsystem:windows /dll /machine:I386 /out:"release/CADML_minisize.dll" /libpath:"$(UDM_ROOT)/lib" /libpath:"$(XERCES_ROOT)/lib" /libpath:"$(XALAN_ROOT)\Build\Win32\VC6\Release"
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinSize
TargetPath=.\release\CADML_minisize.dll
InputPath=.\release\CADML_minisize.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "CADML - Win32 Release MinDependency"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MDd /W3 /GX /O1 /I ".\\" /I "$(GME_ROOT)/sdk/BON/" /I "$(UDM_ROOT)/3rdParty/stl" /I "$(UDM_ROOT)/include" /I "$(XERCES_ROOT)/include" /I "$(XALAN_ROOT)/src" /D "NDEBUG" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "BUILDER_OBJECT_NETWORK" /D "_WINDLL" /D "_AFXDLL" /FD /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 xerces-c_2.lib UdmBase.lib UdmGME.lib UdmDom.lib UdmUtil.lib Xalan-C_1.lib /nologo /subsystem:windows /dll /machine:I386 /out:"release/CADML_minidep.dll" /libpath:"$(UDM_ROOT)/lib" /libpath:"$(XERCES_ROOT)/lib" /libpath:"$(XALAN_ROOT)\Build\Win32\VC6\Release"
# Begin Custom Build - Performing registration
OutDir=.\ReleaseMinDependency
TargetPath=.\release\CADML_minidep.dll
InputPath=.\release\CADML_minidep.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "CADML - Win32 Debug"
# Name "CADML - Win32 Release MinSize"
# Name "CADML - Win32 Release MinDependency"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Builder.cpp"
# End Source File
# Begin Source File

SOURCE=.\ccm_assembly.cpp
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComHelp.cpp"
# End Source File
# Begin Source File

SOURCE=.\Component.cpp
# End Source File
# Begin Source File

SOURCE=.\Component.def
# End Source File
# Begin Source File

SOURCE=.\Component.rc
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentDll.cpp"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentLib.idl"

!IF  "$(CFG)" == "CADML - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath="C:/Program Files/GME/sdk/BON/ComponentLib.idl"

BuildCmds= \
	midl /I.\ /server none /client none "C:/Program Files/GME/sdk/BON/ComponentLib.idl"

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CADML - Win32 Release MinSize"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath="C:/Program Files/GME/sdk/BON/ComponentLib.idl"

BuildCmds= \
	midl /I.\ /server none /client none "C:/Program Files/GME/sdk/BON/ComponentLib.idl"

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "CADML - Win32 Release MinDependency"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath="C:/Program Files/GME/sdk/BON/ComponentLib.idl"

BuildCmds= \
	midl /I.\ /server none /client none "C:/Program Files/GME/sdk/BON/ComponentLib.idl"

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

SOURCE="C:/Program Files/GME/sdk/BON/ComponentObj.cpp"
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\XSLTransformer.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Builder.h"
# End Source File
# Begin Source File

SOURCE=.\ccm_assembly.h
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComHelp.h"
# End Source File
# Begin Source File

SOURCE=.\Component.h
# End Source File
# Begin Source File

SOURCE=.\ComponentConfig.h
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentDll.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentObj.h"
# End Source File
# Begin Source File

SOURCE=.\GMECOM.H
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\XSLTransformer.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\compicon.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ConfigureComponent.exe
# End Source File
# End Target
# End Project
