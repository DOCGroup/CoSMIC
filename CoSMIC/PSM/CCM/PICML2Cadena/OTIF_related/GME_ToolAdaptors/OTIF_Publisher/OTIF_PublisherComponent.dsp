# Microsoft Developer Studio Project File - Name="OTIF_Publisher" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=OTIF_Publisher - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "OTIF_PublisherComponent.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "OTIF_PublisherComponent.mak" CFG="OTIF_Publisher - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "OTIF_Publisher - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe
# PROP BASE Use_MFC 2
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /Od /I ".\\" /I "C:/Program Files/GME/sdk/BON/" /I "D:\programs\OTIF\Include\UdmCORBA" /I "D:\programs\UDM\include" /I "D:\programs\UDM\3rdParty\stl" /I "d:\programs\OTIF\Lib\ToolAdaptor" /D "NDEBUG" /D "_ATL_STATIC_REGISTRY" /D "WIN32" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 ace.lib tao.lib tao_PortableServer.lib udmbase.lib udmcorba.lib udmutil.lib xerces-c_2.lib zlib.lib udmdom.lib udmGME.lib shlwapi.lib TA_MFC_Support.lib /nologo /subsystem:windows /dll /machine:I386 /out:"Release/OTIF_Publisher.dll" /libpath:"d:\programs\OTIF\Lib\ToolAdaptor" /libpath:"D:\programs\OTIF\Lib\tao" /libpath:"D:\programs\OTIF\Lib\UdmCORBA" /libpath:"D:\programs\UDM\lib" /libpath:"D:\programs\UDM\3rdParty\xerces\xerces-c2_2_0-win32\lib" /libpath:"D:\programs\UDM\3rdParty\zlib"
# Begin Custom Build - Performing registration
OutDir=.\Release
TargetPath=.\Release\OTIF_Publisher.dll
InputPath=.\Release\OTIF_Publisher.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build
# Begin Target

# Name "OTIF_Publisher - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComHelp.cpp"
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
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComponentObj.cpp"
# End Source File
# Begin Source File

SOURCE=.\DialogPublishCompletion.cpp
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Exceptions.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# Begin Source File

SOURCE=.\RawComponent.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/Utils.cpp"
# SUBTRACT CPP /YX /Yc /Yu
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/ComHelp.h"
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

SOURCE=.\DialogPublishCompletion.h
# End Source File
# Begin Source File

SOURCE="C:/Program Files/GME/sdk/BON/GMECOM.h"
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
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\CompIcon.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ConfigureComponent.exe
# End Source File
# End Target
# End Project
