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

#include <string>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "idl_defines.h"

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
  // = TITLE
  //    BE_GlobalData
  //
  // = DESCRIPTION
  //    Storage of global data specific to the compiler back end
  //
  BE_GlobalData (void);
  // Constructor.

  virtual ~BE_GlobalData (void);
  // Destructor.

  // Empty DOMElements are created for forward declarations, then
  // looked up and completed when the full definition is seen.
  // Data accessors.

  const char *filename (void) const;
  void filename (const char *fname);

  const char* output_dir (void) const;
  void output_dir (const char* s);

  const char* input_xme (void) const;
  void input_xme (const char* s);

  long nfiles (void) const;
  void nfiles (long val);
  // Accessors for the member.

  bool first_file (void) const;
  void first_file (bool val);
  // Accessors for the member.

  ACE_CString output_file (void) const;
  void output_file (const char *val);
  // Accessors for the member.

  bool do_removal (void) const;
  void do_removal (bool val);
  // Accessors for the member.

  // Utility methods.

  // Command line passed to ACE_Process::spawn. Different
  // implementations in different backends.
  ACE_CString spawn_options (void);

  // Parse args that affect the backend.
  void parse_args (long &i, char **av);

  // Special BE arg call factored out of DRV_args.
  void prep_be_arg (char *s);

  // Checks made after parsing args.
  void arg_post_proc (void);

  // Display usage of BE-specific options.
  void usage (void) const;

  // Create an AST node generator.
  AST_Generator *generator_init (void);

  void xerces_init (void);
  // Initialize all the Xerces stuff.

  // Cache the list of files from the command line.
  void cache_files (char *files[], long nfiles);

  // Cleanup.
  void destroy (void);

  // Utility methods.

  // Accessor.
  const char * const * allfiles (void) const;

  GAME::XME::Project project (void) const;

private:
  // Get the version of GME by looking into
  // $GME_ROOT\Interfaces\Interfaces\GMEVersion.h
  std::string get_GME_version (std::string path);

  ACE_CString filename_;
  // Name of the IDL file we are processing.

  char *output_dir_;
  // Directory where the generated file is to be
  // kept. Default value is 0 for this string which means the current
  // directory from which the <idl_to_picml> is called.

  // URL of the XME file to input, if any.
  char *input_xme_;

  // All files in the command line.
  const char *allfiles_[NFILES];

  // Actual length of the above list.
  long nfiles_;

  // Are we processing the first file on the command line?
  bool first_file_;

  // Set from command line or had default value.
  ACE_CString output_file_;

  // Location of the DTD for GME's XML format.
  ACE_CString schema_path_;

  /// The GME project.
  GAME::XME::Project proj_;
};

#endif /* IDL_TO_PICML_BE_GLOBAL_H */
