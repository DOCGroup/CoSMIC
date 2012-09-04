#!/usr/bin/env python
# $Id$

import getopt
import sys
import string
import uuid
import os
import re

#
# generate_mwc_file
#
def generate_mwc_file (filename, pathname):
    filename_mwc = filename + ".mwc"

    #Creating string template for .mwc file
    temp_mwc = string.Template ("""

workspace (${filename}) {
  cmdline += -include $$GAME_ROOT/MPC/config
             
  ${filename}.mpc
}""")

    replace_mwc = {'filename' : filename}

    #Creating a file object in write mode.
    FILE_mwc = open (pathname + filename_mwc, "w")
    FILE_mwc.write (temp_mwc.substitute (replace_mwc))
    FILE_mwc.close ()

#
# generate_mpc_file
#
def generate_mpc_file (filename, pathname, comp_guid, paradigm, has_icon):
    filename_mpc = filename + ".mpc"

    ico = ""

    if has_icon:
        ico = "gme_has_icon    = 1"

    #Creating string template for .mpc file
    temp_mpc = string.Template ("""// $$Id$$

project (${project_name}) : game_mga_interpreter, game_lib {
  sharedname = $project_name

  pch_header = StdAfx.h
  pch_source = StdAfx.cpp

  Source_Files {
    $idl_filename
    $cpp_filename
    $module_filename
  }

  Resource_Files {
    Component.rc
  }
  
  specific (wix) {
    gme_install     = 1
    gme_progid      = $paradigm.Interpreter.$filename
    gme_uuid        = $uuid_value
    gme_paradigms   = $paradigm
    gme_description = GAME $filename Interpreter
    gme_tooltip     = GAME $filename Interpreter
    $icon
  }

}""")

    replace_mpc = {'project_name' : filename + '_Component',
                   'filename' : filename,
                   'cpp_filename' : filename + '_Component_Impl.cpp',
                   'module_filename' : filename + '_Component_Module.cpp',
                   'idl_filename' : filename + '_Component.idl',
                   'uuid_value' : comp_guid,
                   'paradigm' : paradigm,
                   'icon' : ico}

    #Creating a file object in write mode.
    FILE_mpc = open (pathname + filename_mpc, "w")
    FILE_mpc.write (temp_mpc.substitute (replace_mpc))
    FILE_mpc.close ()

#
# generate_stdafx_hfile
#
def generate_stdafx_hfile (filename, pathname):
    filename_stdafx_h = "StdAfx.h"

    #Creating string template for StdAfx.h file
    temp_stdafx_h = string.Template ("""// -*- C++ -**

#ifndef _STDAFX_H_
#define _STDAFX_H_

#include "game/config.h"

#include <afxwin.h>
#include <afxdisp.h>
#include <atlbase.h>
#include <atlcom.h>

#include "${filename}_Component.h"

#endif""")

    replace_stdafx_h = {'filename' : filename}

    #Creating a file object in write mode.
    FILE_stdafx_h = open (pathname + filename_stdafx_h, "w")
    FILE_stdafx_h.write (temp_stdafx_h.substitute (replace_stdafx_h))
    FILE_stdafx_h.close ()

#
# generate_stdafx_cppfile
#
def generate_stdafx_cppfile (pathname):
    filename_stdafx_cpp = "StdAfx.cpp"

    #Creating file contents of StdAfx.cpp file
    temp_stdafx_cpp = ("""// $Id$

#include "StdAfx.h"

#ifdef _ATL_STATIC_REGISTRY

#include <statreg.h>

#if _ATL_VER < 0x0700
#include <statreg.cpp>
#endif // _ATL_VER < 0x0700

#endif // _ATL_STATIC_REGISTRY

#if _ATL_VER < 0x0700

#include <atlimpl.cpp>

#endif
""")

    #Creating a file object in write mode.
    FILE_stdafx_cpp = open (pathname + filename_stdafx_cpp, "w")
    FILE_stdafx_cpp.write (temp_stdafx_cpp)
    FILE_stdafx_cpp.close ()

#
# generate_resource_hfile
#
def generate_resource_hfile (pathname):
    filename_resource = "Resource.h"

    #Creating file contents for Resource.h file
    temp_resource = ("""//{{NO_DEPENDENCIES}}
// Microsoft Visual C++ generated include file.
// Used by Component.rc
//
#define IDS_PROJNAME 100

// Next default values for new objects
// 
#ifdef APSTUDIO_INVOKED
#ifndef APSTUDIO_READONLY_SYMBOLS
#define _APS_NEXT_RESOURCE_VALUE        201
#define _APS_NEXT_COMMAND_VALUE         32768
#define _APS_NEXT_CONTROL_VALUE         201
#define _APS_NEXT_SYMED_VALUE           101
#endif
#endif
""")

    #Creating a file object in write mode.
    FILE_resource = open (pathname + filename_resource, "w")
    FILE_resource.write (temp_resource)
    FILE_resource.close ()

#
# generate_component_rcfile
#
def generate_component_rcfile (pathname, has_icon):
    filename_componentrc = "Component.rc"

    ico = ""
    if has_icon:
        ico = "IDI_COMPICON            ICON    DISCARDABLE     \"compicon.ico\""
        
    #Creating file contents for Component.rc file
    temp_componentrc = string.Template ("""
//Microsoft Developer Studio generated resource script.
//
#include "resource.h"

#define APSTUDIO_READONLY_SYMBOLS
/////////////////////////////////////////////////////////////////////////////
//
// Generated from the TEXTINCLUDE 2 resource.
//
#include "afxres.h"

/////////////////////////////////////////////////////////////////////////////
#undef APSTUDIO_READONLY_SYMBOLS

/////////////////////////////////////////////////////////////////////////////
// English (U.S.) resources

#if !defined(AFX_RESOURCE_DLL) || defined(AFX_TARG_ENU)
#ifdef _WIN32
LANGUAGE LANG_ENGLISH, SUBLANG_ENGLISH_US
#pragma code_page(1252)
#endif //_WIN32

#ifdef APSTUDIO_INVOKED
/////////////////////////////////////////////////////////////////////////////
//
// TEXTINCLUDE
//

1 TEXTINCLUDE DISCARDABLE 
BEGIN
    "resource.h\\0"
END

2 TEXTINCLUDE DISCARDABLE 
BEGIN
    "#include ""afxres.h""\\r\\n"
    "\\0"
END

#endif    // APSTUDIO_INVOKED


#ifndef _MAC
/////////////////////////////////////////////////////////////////////////////
//
// Version
//

VS_VERSION_INFO VERSIONINFO
 FILEVERSION 1,0,0,1
 PRODUCTVERSION 1,0,0,1
 FILEFLAGSMASK 0x3fL
#ifdef _DEBUG
 FILEFLAGS 0x1L
#else
 FILEFLAGS 0x0L
#endif
 FILEOS 0x4L
 FILETYPE 0x2L
 FILESUBTYPE 0x0L
BEGIN
    BLOCK "StringFileInfo"
    BEGIN
        BLOCK "040904B0"
        BEGIN
            VALUE "CompanyName", "\\0"
            VALUE "FileDescription", "Interpreter Module\\0"
            VALUE "FileVersion", "1, 0, 0, 1\\0"
            VALUE "InternalName", "Interpreter\\0"
            VALUE "LegalCopyright", "Copyright 2000\\0"
            VALUE "OriginalFilename", "Interpreter.DLL\\0"
            VALUE "ProductName", "Interpreter Module\\0"
            VALUE "ProductVersion", "1, 0, 0, 1\\0"
            VALUE "OLESelfRegister", "\\0"
        END
    END
    BLOCK "VarFileInfo"
    BEGIN
        VALUE "Translation", 0x409, 1200
    END
END

#endif    // !_MAC


/////////////////////////////////////////////////////////////////////////////
//
// Icon
//$icon

// Icon with lowest ID value placed first to ensure application icon
// remains consistent on all systems.
//

/////////////////////////////////////////////////////////////////////////////
//
// String Table
//

STRINGTABLE DISCARDABLE 
BEGIN
    IDS_PROJNAME            "Component"
END

#endif    // English (U.S.) resources
/////////////////////////////////////////////////////////////////////////////



#ifndef APSTUDIO_INVOKED
/////////////////////////////////////////////////////////////////////////////
//
// Generated from the TEXTINCLUDE 3 resource.
//

/////////////////////////////////////////////////////////////////////////////
#endif    // not APSTUDIO_INVOKED

""")

    replace_componentrc = {'icon' : ico}

    #Creating a file object in write mode.
    FILE_componentrc = open (pathname + filename_componentrc, "w")
    FILE_componentrc.write (temp_componentrc.substitute (replace_componentrc))
    FILE_componentrc.close ()

#
# generate_idl_file
#
def generate_idl_file (filename, pathname, comp_guid, lib_guid):
    filename_idl = filename + "_Component.idl"

    #Creating string template for .idl file
    temp_idl = string.Template ("""// -*- IDL -*-

//=============================================================================
/**
 * @file      ${filename}_Component.idl
 *
 * $$Id$$
 *
 * @author    Tanumoy Pati
 */
//=============================================================================

#ifndef $idl_filename_caps
#define $idl_filename_caps

#include <Gme.idl>

[
	uuid (${lib_guid}),
	version (1.0),
]
library ${filename}_Component
{
	importlib ("stdole32.tlb");

	[uuid (${comp_guid})]
	coclass ${filename}_Component
	{
		[default] interface IMgaComponentEx;
		interface IMgaComponent;
		interface IMgaVersionInfo;
	};
};

#endif  // !defined $idl_filename_caps
""")

    replace_idl = {'idl_filename_caps' : '_' + filename.upper() + '_COMPONENT_IDL_',
                   'filename' : filename,
                   'lib_guid' : lib_guid,
                   'comp_guid' : comp_guid }

    #Creating a file object in write mode.
    FILE_idl = open (pathname + filename_idl, "w")
    FILE_idl.write (temp_idl.substitute (replace_idl))
    FILE_idl.close ()   
    
#
# generate_impl_h_file
#
def generate_impl_h_file (filename, pathname):
    filename_impl_h = filename + "_Component_Impl.h"

    #Creating string template for .h file
    temp_impl_h = string.Template ("""// -*- C++ -*-

//=============================================================================
/**
 * @file       ${class_name}.h
 *
 * $$Id$$
 *
 * @author     Tanumoy Pati
 */
//=============================================================================

#ifndef $h_filename_caps
#define $h_filename_caps

#include "game/mga/component/Interpreter_Impl_Base.h"



class $class_name :
 public GAME::Mga::Interpreter_Impl_Base
{
public:
  /// Default constructor.
  $class_name (void);

  /// Destructor.
  virtual ~$class_name (void);

  /// Handle the InvokeEx callback.
  int invoke_ex (GAME::Mga::Project project,
                 GAME::Mga::FCO_in focus,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags);
};

#endif""")

    replace_impl_h = {'h_filename_caps' : '_' + filename.upper() + '_COMPONENT_IMPL_H_',
                      'class_name' : filename + '_Component_Impl'}

    #Creating a file object in write mode.
    FILE_impl_h = open (pathname + filename_impl_h, "w")
    FILE_impl_h.write (temp_impl_h.substitute (replace_impl_h))
    FILE_impl_h.close ()

#
# generate_module_cpp_file
#
def generate_module_cpp_file (filename, pathname, lib_guid):
    filename_module_cpp = filename + "_Component_Module.cpp"

    #Creating string template for _Module.cpp file
    temp_module_cpp = string.Template ("""// $$Id$$

#include "StdAfx.h"
#include "game/mga/component/Component_Module.h"
#include "${filename}_Component_i.c"

DECLARE_COMPONENT_MODULE ("$filename",
                          LIBID_${filename}_Component,
                          1000,
                          "{${lib_guid}}");
""")

    replace_module_cpp = {'filename' : filename,
                          'lib_guid' : lib_guid }

    #Creating a file object in write mode.
    FILE_module_cpp = open (pathname + filename_module_cpp, "w")
    FILE_module_cpp.write (temp_module_cpp.substitute (replace_module_cpp))
    FILE_module_cpp.close ()
    
#
# generate_impl_cpp_file
#
def generate_impl_cpp_file (filename, pathname, paradigm):
    filename_impl_cpp = filename + "_Component_Impl.cpp"

    #Creating string template for .cpp file
    temp_impl_cpp = string.Template ("""// $$Id$$

#include "StdAfx.h"
#include "$comp_header
#include "$path_header
#include "game/mga/utils/Project_Settings.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/component/Interpreter_T.h"

#include <iostream>

GAME_DECLARE_INTERPRETER (${filename}_Component, ${classname});

//
//$classname
//
${classname}::${classname} (void)
: GAME::Mga::Interpreter_Impl_Base ("GAME ${filename} Generator",
                                    "${paradigm}",
                                    "GAME.Interpreter.${filename}")
{

}

//
//~$classname
//
$classname::~$classname (void)
{

}

//
//invoke ex
//
int ${classname}::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           std::vector <GAME::Mga::FCO> & selected,
           long flags)
{
   AfxMessageBox (" ${filename} Interpreter works");
   return 0;
}

""")

    replace_impl_cpp = {'path_header' : filename + '_Component_Impl.h"',
                        'comp_header' : filename + '_Component.h"',
                        'classname' : filename + '_Component_Impl',
                        'filename' : filename,
                        'paradigm' : paradigm}

    #Creating a file object in write mode.
    FILE_impl_cpp = open (pathname + filename_impl_cpp, "w")
    FILE_impl_cpp.write (temp_impl_cpp.substitute (replace_impl_cpp))
    FILE_impl_cpp.close ()

#
# validity_check
#
def validity_check (guid):
    if re.match ('^(\{){0,1}[0-9a-fA-F]{8}\-[0-9a-fA-F]{4}\-[0-9a-fA-F]{4}\-[0-9a-fA-F]{4}\-[0-9a-fA-F]{12}(\}){0,1}$', guid):
        return True
    
    print ('*** error:', guid, 'is invalid')
    
#
# generate_reg_file
#
def generate_reg_file (filename, pathname, comp_guid, paradigm, has_icon):
    filename_reg = filename + '_Component.reg'

    ico = ""
    if has_icon:
        ico = "\"Icon\"=\",IDI_COMPICON\""

    #Creating string template for *.reg file
    temp_reg = string.Template ("""REGEDIT4

[HKEY_CURRENT_USER\Software\Classes]

[HKEY_CURRENT_USER\Software\Classes\CLSID]

[HKEY_CURRENT_USER\Software\Classes\CLSID\{${comp_guid}}]
@="GAME.Interpreter.${filename}"

[HKEY_CURRENT_USER\Software\Classes\CLSID\{${comp_guid}}\ProgID]
@="GAME.Interpreter.${filename}"

[HKEY_CURRENT_USER\Software\Classes\CLSID\{${comp_guid}}\InProcServer32]
@="${filename}_Component.dll"

[HKEY_CURRENT_USER\Software\Classes\GAME.Interpreter.${filename}]
@="GAME.Interpreter.${filename}"

[HKEY_CURRENT_USER\Software\Classes\GAME.Interpreter.${filename}\CLSID]
@="{${comp_guid}}"

[HKEY_CURRENT_USER\Software\GME\Components\GAME.Interpreter.${filename}]
"Tooltip"="${filename} Interpreter"
"Paradigm"="${paradigm}"
"Type"=dword:00000001
"Description"="${filename}"
$icon

[HKEY_CURRENT_USER\Software\GME\Components\GAME.Interpreter.${filename}\Associated]
"${paradigm}"=""

""")

    replace_reg = {'filename' : filename,
                   'comp_guid' : comp_guid,
                   'paradigm' : paradigm,
                   'icon' : ico}

    #Creating a file object in write mode.
    FILE_reg = open (pathname + filename_reg, "w")
    FILE_reg.write (temp_reg.substitute (replace_reg))
    FILE_reg.close ()

#
# generate_dreg_file
#
def generate_dreg_file (filename, pathname, comp_guid, paradigm, has_icon):
    filename_dreg = filename + '_Componentd.reg'

    ico = ""
    if has_icon:
        ico = "\"Icon\"=\",IDI_COMPICON\""

    #Creating string template for *d.reg file
    temp_dreg = string.Template ("""REGEDIT4

[HKEY_CURRENT_USER\Software\Classes]

[HKEY_CURRENT_USER\Software\Classes\CLSID]

[HKEY_CURRENT_USER\Software\Classes\CLSID\{${comp_guid}}]
@="GAME.Interpreter.${filename}"

[HKEY_CURRENT_USER\Software\Classes\CLSID\{${comp_guid}}\ProgID]
@="GAME.Interpreter.${filename}"

[HKEY_CURRENT_USER\Software\Classes\CLSID\{${comp_guid}}\InProcServer32]
@="${filename}_Componentd.dll"

[HKEY_CURRENT_USER\Software\Classes\GAME.Interpreter.${filename}]
@="GAME.Interpreter.${filename}"

[HKEY_CURRENT_USER\Software\Classes\GAME.Interpreter.${filename}\CLSID]
@="{${comp_guid}}"

[HKEY_CURRENT_USER\Software\GME\Components\GAME.Interpreter.${filename}]
"Tooltip"="${filename} Interpreter"
"Paradigm"="${paradigm}"
"Type"=dword:00000001
"Description"="${filename}"
$icon

[HKEY_CURRENT_USER\Software\GME\Components\GAME.Interpreter.${filename}\Associated]
"${paradigm}"=""

""")

    replace_dreg = {'filename' : filename,
                   'comp_guid' : comp_guid,
                    'paradigm' : paradigm,
                    'icon' : ico}

    #Creating a file object in write mode.
    FILE_dreg = open (pathname + filename_dreg, "w")
    FILE_dreg.write (temp_dreg.substitute (replace_dreg))
    FILE_dreg.close ()

#
# main
#    
def main (*argv):
    #Initializing the variable values
    comp_guid = uuid.uuid4 ()
    lib_guid = uuid.uuid4 ()
    pathname = os.getcwd () + '/'
    filename = 'Default'
    has_icon = False
    paradigm = None
    filename = None
    
    #setting options and corresponding argument values
    options, remainder = getopt.getopt (sys.argv[1:], 'o:',['name=',
                                                            'component-guid=',
                                                            'library-guid=',
                                                            'paradigm=',
                                                            'has-icon'])

    for opt, arg in options:
        if opt == '--name' :
            filename = arg
        elif opt == '-o' :
            pathname = arg
        elif opt == '--paradigm' :
            paradigm = arg
        elif opt == '--has-icon' :
            has_icon = True
        elif opt == '--component-guid' :
            if (not validity_check (arg)):
                return 1
            comp_guid = arg
        elif opt == '--library-guid' :
            if (not validity_check (arg)):
                return 1
            lib_guid = arg
            
    if filename is None:
        print ('*** error: missing --name argument')
        sys.exit (1)
    
    if paradigm is None:
        print ('*** error: missing --paradigm argument')
        sys.exit (1)
                        
    #Calling respective function for creating .mwc file
    generate_mwc_file (filename, pathname)

    #Calling respective function for creating .mpc file
    generate_mpc_file (filename, pathname, comp_guid, paradigm, has_icon)

    #Calling respective function for creating .idl file
    generate_idl_file (filename, pathname, comp_guid, lib_guid)

    #Calling respective function for creating stdafx.h file
    generate_stdafx_hfile (filename, pathname)

    #Calling respective function for creating stdafx.cpp file
    generate_stdafx_cppfile (pathname)

    #Calling respective function for creating Resource.h file
    generate_resource_hfile (pathname)

    #Calling respective function for creating Component.rc file
    generate_component_rcfile (pathname, has_icon)

    #Calling respective function for creating _Module.cpp file
    generate_module_cpp_file (filename, pathname, lib_guid)

    #Calling respective function for creating *d.reg file
    generate_dreg_file (filename, pathname, comp_guid, paradigm, has_icon)

    #Calling respective function for creating *.reg file
    generate_reg_file (filename, pathname, comp_guid, paradigm, has_icon)

    #Calling respective function for creating _Impl.h file
    generate_impl_h_file (filename, pathname)

    #Calling respective function for creating _Impl.cpp file
    generate_impl_cpp_file (filename, pathname, paradigm)

#
# __name__
#
if __name__ == "__main__":
    SystemExit (main ())
        
    



        
        
    
    
