# Microsoft Developer Studio Project File - Name="Decorator" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=Decorator - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Decorator.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Decorator.mak" CFG="Decorator - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Decorator - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "Decorator - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Decorator - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../../lib"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_WINDLL" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../../../bin/Decorator.dll" /pdbtype:sept
# Begin Custom Build - Performing registration
OutDir=.\../lib
TargetPath=\CoSMIC\bin\Decorator.dll
InputPath=\CoSMIC\bin\Decorator.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ELSEIF  "$(CFG)" == "Decorator - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../../../lib"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /O1 /I "..\Interfaces" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_ATL_MIN_CRT" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_ATL_DLL" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386 /out:"../../../bin/Decorator.dll"
# Begin Custom Build - Performing registration
OutDir=.\../lib
TargetPath=\CoSMIC\bin\Decorator.dll
InputPath=\CoSMIC\bin\Decorator.dll
SOURCE="$(InputPath)"

"$(OutDir)\regsvr32.trg" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	regsvr32 /s /c "$(TargetPath)" 
	echo regsvr32 exec. time > "$(OutDir)\regsvr32.trg" 
	
# End Custom Build

!ENDIF 

# Begin Target

# Name "Decorator - Win32 Debug"
# Name "Decorator - Win32 Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\CommonError.cpp
# End Source File
# Begin Source File

SOURCE=.\Decorator.cpp

!IF  "$(CFG)" == "Decorator - Win32 Debug"

# ADD CPP /YX"stdafx.h"

!ELSEIF  "$(CFG)" == "Decorator - Win32 Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Decorator.rc
# End Source File
# Begin Source File

SOURCE=.\DecoratorApp.cpp

!IF  "$(CFG)" == "Decorator - Win32 Debug"

# ADD CPP /YX"stdafx.h"

!ELSEIF  "$(CFG)" == "Decorator - Win32 Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\DecoratorApp.def
# End Source File
# Begin Source File

SOURCE=.\DecoratorLib.idl
# ADD MTL /tlb "DecoratorLib.tlb" /h "DecoratorLib.h" /iid "DecoratorLib_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=.\DecoratorUtil.cpp

!IF  "$(CFG)" == "Decorator - Win32 Debug"

# ADD CPP /YX

!ELSEIF  "$(CFG)" == "Decorator - Win32 Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\IDMLDecorators.cpp

!IF  "$(CFG)" == "Decorator - Win32 Debug"

# ADD CPP /YX"stdafx.h"

!ELSEIF  "$(CFG)" == "Decorator - Win32 Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\MaskedBitmap.cpp

!IF  "$(CFG)" == "Decorator - Win32 Debug"

# ADD CPP /YX"stdafx.h"

!ELSEIF  "$(CFG)" == "Decorator - Win32 Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\CommonError.h
# End Source File
# Begin Source File

SOURCE=.\CommonSmart.h
# End Source File
# Begin Source File

SOURCE=.\Decorator.h
# End Source File
# Begin Source File

SOURCE=.\DecoratorConfig.h
# End Source File
# Begin Source File

SOURCE=.\DecoratorStd.h
# End Source File
# Begin Source File

SOURCE=.\DecoratorUtil.h
# End Source File
# Begin Source File

SOURCE=.\IDMLDecorators.h
# End Source File
# Begin Source File

SOURCE=.\MaskedBitmap.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resources"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Decorator.rgs
# End Source File
# End Group
# Begin Source File

SOURCE=.\hoy.htm
# End Source File
# Begin Source File

SOURCE=..\paradigms\icons\inherits.bmp
# End Source File
# End Target
# End Project
