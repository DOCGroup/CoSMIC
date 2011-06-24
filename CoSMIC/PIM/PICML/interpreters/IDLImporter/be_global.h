/* -*- c++ -*- */
// $Id$

// ============================================================================
//
// = LIBRARY
//    IDL_TO_PICML_BE_DLL
//
// = FILENAME
//    be_global.h
//
// = DESCRIPTION
//    Header file for class containing compiler back end global data.
//
// = AUTHOR
//    Jeff Parsons <parsons@cs.wustl.edu>
//
// ============================================================================

#ifndef IDL_TO_PICML_BE_GLOBAL_H
#define IDL_TO_PICML_BE_GLOBAL_H

#include "IDL_TO_PICML_BE_Export.h"
#include "ast_type.h"
#include "ace/SString.h"
#include "game/xme/Project.h"
#include "File_Creator.h"

#include <string>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

// Forward decl.
class AST_Generator;

/**
 * @class BE_GlobalData
 *
 * Defines a class containing all back end global data.
 */
class IDL_TO_PICML_BE_Export BE_GlobalData
{
public:
  // Constructor.
  BE_GlobalData (void);

  // Destructor.
  virtual ~BE_GlobalData (void);

  const ACE_CString & output_dir (void) const;
  void output_dir (const char* s);

  // Accessors for the member.
  const ACE_CString & output_file (void) const;
  void output_file (const char *val);

  const ACE_CString & input_file (void) const;
  void input_file (const char *val);

  // Utility methods.

  // Command line passed to ACE_Process::spawn. Different
  // implementations in different backends.
  ACE_CString spawn_options (void);

  // Parse args that affect the backend.
  void parse_args (long &i, char **av);

  void initialize (void);
  // Initialize all the Xerces stuff.

  // Cleanup.
  void destroy (void);

  // Utility methods.

  PICML_File_Creator & files (void);
  const PICML_File_Creator & files (void) const;

  GAME::XME::Project & project (void);

  bool overwrite (void) const;

  bool is_debugging_enabled (void) const;
  void is_debugging_enabled (bool flag);

  bool is_tracing_enabled (void) const;

private:
  // Get the version of GME by looking into
  // $GME_ROOT\Interfaces\Interfaces\GMEVersion.h
  std::string get_GME_version (std::string path);

  // Directory where the generated file is to be
  // kept. Default value is 0 for this string which means the current
  // directory from which the <idl_to_picml> is called.
  ACE_CString output_dir_;

  /// Target output file.
  ACE_CString output_file_;

  /// Input file to use as starting point.
  ACE_CString input_file_;

  // Location of the DTD for GME's XML format.
  ACE_CString schema_path_;

  /// The GME project.
  GAME::XME::Project proj_;

  /// Collection of files in this parsing.
  PICML_File_Creator files_;

  std::vector <std::string> libs_;

  bool debugging_enabled_;

  bool trace_enabled_;
};

#endif /* IDL_TO_PICML_BE_GLOBAL_H */
