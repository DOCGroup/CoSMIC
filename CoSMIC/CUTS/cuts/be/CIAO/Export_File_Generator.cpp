// $Id$

#include "Export_File_Generator.h"
#include <algorithm>
#include <fstream>
#include <sstream>

//
// CUTS_Export_File_Generator
//
CUTS_Export_File_Generator::
CUTS_Export_File_Generator (const std::string & export)
: export_ (export)
{
  this->export_macro_ = this->export_macro (this->export_);
  this->export_file_ = this->export_file (this->export_);
  this->build_flag_ = this->build_flag (this->export_);
}

//
// ~CUTS_Export_File_Generator
//
CUTS_Export_File_Generator::~CUTS_Export_File_Generator (void)
{

}

//
// export_macro
//
std::string
CUTS_Export_File_Generator::export_macro (const std::string & export)
{
  std::string macro = export;
  std::transform (macro.begin (),
                  macro.end (),
                  macro.begin (),
                  toupper);

  macro.append ("_Export");
  return macro;
}

//
// export_file
//
std::string
CUTS_Export_File_Generator::export_file (const std::string & export)
{
  std::string filename = export;
  filename.append ("_export.h");

  return filename;
}

//
// export
//
const std::string &
CUTS_Export_File_Generator::export (void) const
{
  return this->export_;
}

//
// export_macro
//
const std::string &
CUTS_Export_File_Generator::export_macro (void) const
{
  return this->export_macro_;
}

//
// export_file
//
const std::string &
CUTS_Export_File_Generator::export_file (void) const
{
  return this->export_file_;
}

//
// generate
//
bool CUTS_Export_File_Generator::generate (const std::string & outdir)
{
  std::string export = this->export_;
  std::transform (export.begin (),
                  export.end (),
                  export.begin (),
                  toupper);

  std::string hasdll = export;
  hasdll.append ("_HAS_DLL");

  std::string ntrace = export;
  ntrace.append ("_NTRACE");

  // Construct the full path of the export file.
  std::ostringstream pathname;
  pathname << outdir << "\\" << this->export_file_ << std::ends;

  // Open the file for writing.
  std::ofstream exportfile;
  exportfile.open (pathname.str ().c_str ());

  if (!exportfile.is_open ())
    return false;

  // Generate the export file.
  exportfile
    << "// -*- C++ -*-" << std::endl
    << "// $Id$" << std::endl
    << std::endl
    << "// Definition for Win32 Export directives" << std::endl
    << "// ---------------------------------------------" << std::endl
    << std::endl
    << "#ifndef _" << export << "_EXPORT_H_" << std::endl
    << "#define _" << export << "_EXPORT_H_" << std::endl
    << std::endl
    << "#include \"ace/config-all.h\"" << std::endl
    << std::endl
    << "#if !defined (" << hasdll << ")" << std::endl
    << "#  define " << hasdll << " 1" << std::endl
    << "#endif /* !"<< hasdll << " */" << std::endl
    << std::endl
    << "#if defined ("<< hasdll << ") && (" << export << "_HAS_DLL == 1)" << std::endl
    << "#  if defined (" << this->build_flag_ << ")" << std::endl
    << "#    define " << this->export_macro_ << " ACE_Proper_Export_Flag" << std::endl
    << "#    define " << export << "_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)" << std::endl
    << "#    define " << export << "_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)" << std::endl
    << "#  else  /* " << this->build_flag_ << " */" << std::endl
    << "#    define " << this->export_macro_ << " ACE_Proper_Import_Flag" << std::endl
    << "#    define " << export << "_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)" << std::endl
    << "#    define " << export << "_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)" << std::endl
    << "#  endif /* " << this->build_flag_ << " */" << std::endl
    << "#else  /* " << hasdll << " == 1 */" << std::endl
    << "#  define " << this->export_macro_ << std::endl
    << "#  define " << export << "_SINGLETON_DECLARATION(T)" << std::endl
    << "#  define " << export << "_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)" << std::endl
    << "#endif /* " << hasdll << " == 1 */" << std::endl
    << std::endl
    << "// Set " << ntrace << " = 0 to turn on library specific " << std::endl
    << "// tracing even if tracing is turned off for ACE." << std::endl
    << std::endl
    << "#if !defined (" << ntrace << ")" << std::endl
    << "#  if (ACE_NTRACE == 1)" << std::endl
    << "#    define " << ntrace << " 1" << std::endl
    << "#  else /* (ACE_NTRACE == 1) */" << std::endl
    << "#    define " << ntrace << " 0" << std::endl
    << "#  endif /* (ACE_NTRACE == 1) */" << std::endl
    << "#endif /* !" << ntrace << " */" << std::endl
    << std::endl
    << "#if (" << ntrace << " == 1)" << std::endl
    << "#  define " << export << "_TRACE(X)" << std::endl
    << "#else /* (" << ntrace << " == 1) */" << std::endl
    << "#  if !defined (ACE_HAS_TRACE)" << std::endl
    << "#    define ACE_HAS_TRACE" << std::endl
    << "#  endif /* ACE_HAS_TRACE */" << std::endl
    << "#  define " << export << "_TRACE(X) ACE_TRACE_IMPL(X)" << std::endl
    << "#  include \"ace/Trace.h\"" << std::endl
    << "#endif /* (" << ntrace << " == 1) */" << std::endl
    << std::endl
    << "#endif /* " << export << "_EXPORT_H_ */" << std::endl;

  exportfile.close ();
  return true;
}

//
// build_flag
//
std::string
CUTS_Export_File_Generator::build_flag (const std::string & export)
{
  std::string buildflag = export;
  std::transform (buildflag.begin (),
                  buildflag.end (),
                  buildflag.begin (),
                  toupper);

  buildflag.append ("_BUILD_DLL");
  return buildflag;
}

//
// build_flag
//
const std::string &
CUTS_Export_File_Generator::build_flag (void) const
{
  return this->build_flag_;
}
