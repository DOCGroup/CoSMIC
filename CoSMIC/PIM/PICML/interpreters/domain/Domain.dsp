# Microsoft Developer Studio Project File - Name="Domain" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Domain - WIN32 DEBUG
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Domain.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Domain.mak" CFG="Domain - WIN32 DEBUG"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Domain - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Domain - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Domain - Win32 Debug"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../../../bin"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I ".\\" /I "$(GME_ROOT)/sdk/BON/" /I "$(XERCESCROOT)/include" /I "$(UDM_PATH)/include" /I "$(UDM_PATH)/3rdParty/stl" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR /FD /GZ /Zm200 /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 xerces-c_2_5D.lib xerces-c_2D.lib ZlibD.lib UdmBase_D.lib UdmDom_D.lib UdmUtil_D.lib UdmGme_D.lib rpcrt4.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept /libpath:"$(XERCESCROOT)/lib" /libpath:"$(UDM_PATH)\lib" /libpath:"$(UDM_PATH)\3rdParty\zlib" /libpath:"$(UDM_PATH)\3rdParty\xerces\xerces-c2_2_0-win32\lib"
# SUBTRACT LINK32 /pdb:none
# Begin Custom Build - Performing registration
OutDir=.\../../../../bin
TargetPath=\CoSMIC\bin\Domain.dll
InputPath=\CoSMIC\bin\Domain.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Domain - Win32 Release"

# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Domain___Win32_Release"
# PROP BASE Intermediate_Dir "Domain___Win32_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../../../../bin"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O1 /I ".\\" /I "C:/Program Files/GME/sdk/BON/" /I "$(UDM_PATH)\include" /I "$(UDM_PATH)\3rdParty\stl" /D "NDEBUG" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /D "GME_INTERPRETER_USED" /D "UML_CLASS_DIAGRAM" /FR /FD /Zm200 /c
# ADD CPP /nologo /MD /W3 /GR /GX /O1 /I ".\\" /I "$(GME_ROOT)/sdk/BON/" /I "$(XERCESCROOT)/include" /I "$(UDM_PATH)/include" /I "$(UDM_PATH)/3rdParty/stl" /D "NDEBUG" /D "_ATL_DLL" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /FR /FD /Zm200 /c
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 xerces-c_2.lib Zlib.lib /nologo /subsystem:windows /dll /machine:I386 /out:"Release/Component.dll" /libpath:"$(UDM_PATH)\3rdParty\zlib" /libpath:"$(UDM_PATH)\3rdParty\xerces\xerces-c2_2_0-win32\lib"
# ADD LINK32 xerces-c_2_5.lib xerces-c_2.lib Zlib.lib UdmBase.lib UdmDom.lib UdmUtil.lib UdmGme.lib rpcrt4.lib /nologo /subsystem:windows /dll /machine:I386 /libpath:"$(XERCESCROOT)/lib" /libpath:"$(UDM_PATH)\lib" /libpath:"$(UDM_PATH)\3rdParty\zlib" /libpath:"$(UDM_PATH)\3rdParty\xerces\xerces-c2_2_0-win32\lib"
# Begin Custom Build - Performing registration
OutDir=.\../../../../bin
TargetDir=\CoSMIC\bin
TargetName=Domain
InputPath=\CoSMIC\bin\Domain.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetDir)\$(TargetName)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "Domain - Win32 Debug"
# Name "Domain - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="C:\Program Files\GME\SDK\BON\ComHelp.cpp"
# End Source File
# Begin Source File

SOURCE=.\Component.def
# End Source File
# Begin Source File

SOURCE=.\Component.rc
# End Source File
# Begin Source File

SOURCE="c:\Program Files\GME\SDK\BON\ComponentDll.cpp"
# End Source File
# Begin Source File

SOURCE="C:\Program Files\GME\SDK\BON\ComponentLib.idl"

!IF  "$(CFG)" == "Domain - Win32 Debug"

# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath="C:\Program Files\GME\SDK\BON\ComponentLib.idl"

BuildCmds= \
	midl /I.\ /server none /client none "C:/Program Files/GME/sdk/BON/ComponentLib.idl"

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_p.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"dlldata.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ELSEIF  "$(CFG)" == "Domain - Win32 Release"

# PROP BASE Ignore_Default_Tool 1
# PROP Ignore_Default_Tool 1
# Begin Custom Build - MIDL $(InputPath))
InputPath="C:\Program Files\GME\SDK\BON\ComponentLib.idl"

BuildCmds= \
	midl /I.\ /server none /client none "C:/Program Files/GME/sdk/BON/ComponentLib.idl"

"ComponentLib.tlb" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib.h" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_i.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"ComponentLib_p.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)

"dlldata.c" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   $(BuildCmds)
# End Custom Build

!ENDIF 

# End Source File
# Begin Source File

SOURCE="C:\Program Files\GME\SDK\BON\ComponentObj.cpp"
# End Source File
# Begin Source File

SOURCE=.\DomainVisitor.cpp
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

SOURCE=.\UdmApp.cpp
# End Source File
# Begin Source File

SOURCE=.\UuidString.cpp
# End Source File
# Begin Source File

SOURCE=.\XercesString.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="C:\Program Files\GME\SDK\BON\ComHelp.h"
# End Source File
# Begin Source File

SOURCE=.\ComponentConfig.h
# End Source File
# Begin Source File

SOURCE="C:\Program Files\GME\SDK\BON\ComponentDll.h"
# End Source File
# Begin Source File

SOURCE="C:\Program Files\GME\SDK\BON\ComponentObj.h"
# End Source File
# Begin Source File

SOURCE=.\DomainVisitor.h
# End Source File
# Begin Source File

SOURCE="C:\Program Files\GME\SDK\BON\GMECOM.H"
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

SOURCE=.\UdmApp.h
# End Source File
# Begin Source File

SOURCE=.\UdmConfig.h
# End Source File
# Begin Source File

SOURCE=.\UuidString.h
# End Source File
# Begin Source File

SOURCE=.\XercesString.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\CompIcon.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\PICML.xsd
# End Source File
# End Target
# End Project
