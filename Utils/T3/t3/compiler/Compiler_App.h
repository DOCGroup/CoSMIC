// -*- C++ -*-

//=============================================================================
/**
 * @file      T3_Compiler_App.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_COMPILER_APP_H_
#define _T3_COMPILER_APP_H_

#include "ace/SString.h"
#include "ace/Unbounded_Set.h"

// Forward decl.
class T3_Parse_Tree;

/**
 * @class T3_Compiler_App
 */
class T3_Compiler_App
{
public:
  /// Default constructor.
  T3_Compiler_App (void);

  /// Destructor.
  ~T3_Compiler_App (void);

  int run_main (int argc, char * argv []);

private:
  struct opts_t
  {
    ACE_Unbounded_Set <ACE_CString> t3_files_;
  };

  int generate_parser (const ACE_CString & t3_file);

  /// Print the help
  void print_help (void);

  void get_basename (const ACE_CString & filename, ACE_CString & basename);

  // Helper for parsing command-line arguments.
  int parse_args (int argc, char * argv []);

  /// Options for the application.
  opts_t opts_;
};

#endif  // !defined _T3_COMPILER_APP_H_
