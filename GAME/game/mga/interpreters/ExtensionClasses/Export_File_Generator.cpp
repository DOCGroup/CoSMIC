// $Id$

#include "StdAfx.h"
#include "Export_File_Generator.h"
#include "Functors.h"

#include "game/mga/Utils.h"

#include <fstream>

namespace GAME
{
namespace Mga
{

//
// Export_File_Generator
//
Export_File_Generator::Export_File_Generator (void)
{

}

//
// Export_File_Generator
//
Export_File_Generator::~Export_File_Generator (void)
{

}

//
// generate
//
void Export_File_Generator::
generate (const std::string & location, const Project & proj)
{
  // Open the .mpc file for writing.
  Folder root = proj.root_folder ();
  const std::string name = GAME::Utils::normalize (root->name ());
  const std::string filename = location + "/" + name + "/" + name + "_export.h";

  std::string macro_guard = "_" + name + "_EXPORT_H_";
  std::transform (macro_guard.begin (),
                  macro_guard.end (),
                  macro_guard.begin (),
                  &::toupper);

  std::ofstream hfile;
  hfile.open (filename.c_str ());

  std::string export_basename = name;
  std::transform (export_basename.begin (),
                  export_basename.end (),
                  export_basename.begin (),
                  &::toupper);

  const std::string export_name = export_basename + "_Export";

  if (hfile.is_open ())
  {
    // Generate the contents of the .mpc file.
    hfile
      << "// -*- C++ -*-" << std::endl
      << std::endl
      << "#ifndef " << macro_guard << std::endl
      << "#define " << macro_guard << std::endl
      << std::endl
      << include_t ("ace/config.h")
      << std::endl
      << "#if defined (ACE_AS_STATIC_LIBS) && !defined (" << export_basename << "_HAS_DLL)" << std::endl
      << "#  define " << export_basename << "_HAS_DLL 0" << std::endl
      << "#endif /* ACE_AS_STATIC_LIBS && " << export_basename << "_HAS_DLL */" << std::endl
      << std::endl
      << "#if !defined (" << export_basename << "_HAS_DLL)" << std::endl
      << "#  define " << export_basename << "_HAS_DLL 1" << std::endl
      << "#endif /* ! " << export_basename << "_HAS_DLL */" << std::endl
      << std::endl
      << "#if defined (" << export_basename << "_HAS_DLL) && (" << export_basename << "_HAS_DLL == 1)" << std::endl
      << "#  if defined (" << export_basename << "_BUILD_DLL)" << std::endl
      << "#    define " << export_basename << "_Export ACE_Proper_Export_Flag" << std::endl
      << "#    define " << export_basename << "_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)" << std::endl
      << "#    define " << export_basename << "_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)" << std::endl
      << "#  else /* " << export_basename << "_BUILD_DLL */" << std::endl
      << "#    define " << export_basename << "_Export ACE_Proper_Import_Flag" << std::endl
      << "#    define " << export_basename << "_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)" << std::endl
      << "#    define " << export_basename << "_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)" << std::endl
      << "#  endif /* " << export_basename << "_BUILD_DLL */" << std::endl
      << "#else /* " << export_basename << "_HAS_DLL == 1 */" << std::endl
      << "#  define " << export_basename << "_Export" << std::endl
      << "#  define " << export_basename << "_SINGLETON_DECLARATION(T)" << std::endl
      << "#  define " << export_basename << "_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)" << std::endl
      << "#endif /* " << export_basename << "_HAS_DLL == 1 */" << std::endl
      << std::endl
      << "// Set " << export_basename << "_NTRACE = 0 to turn on library specific tracing even if" << std::endl
      << "// tracing is turned off for ACE." << std::endl
      << "#if !defined (" << export_basename << "_NTRACE)" << std::endl
      << "#  if (ACE_NTRACE == 1)" << std::endl
      << "#    define " << export_basename << "_NTRACE 1" << std::endl
      << "#  else /* (ACE_NTRACE == 1) */" << std::endl
      << "#    define " << export_basename << "_NTRACE 0" << std::endl
      << "#  endif /* (ACE_NTRACE == 1) */" << std::endl
      << "#endif /* !" << export_basename << "_NTRACE */" << std::endl
      << std::endl
      << "#if (" << export_basename << "_NTRACE == 1)" << std::endl
      << "#  define " << export_basename << "_TRACE(X)" << std::endl
      << "#else /* (" << export_basename << "_NTRACE == 1) */" << std::endl
      << "#  if !defined (ACE_HAS_TRACE)" << std::endl
      << "#    define ACE_HAS_TRACE" << std::endl
      << "#  endif /* ACE_HAS_TRACE */" << std::endl
      << "#  define " << export_basename << "_TRACE(X) ACE_TRACE_IMPL(X)" << std::endl
      << "#  include \"ace/Trace.h\"" << std::endl
      << "#endif /* (" << export_basename << "_NTRACE == 1) */"
      << std::endl
      << "#endif  // !defined " << macro_guard << std::endl;

    hfile.close ();
  }
}


}
}
