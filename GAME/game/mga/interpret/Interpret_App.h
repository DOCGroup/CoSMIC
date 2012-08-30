// -*- C++ -*-

//=============================================================================
/**
 * @file        Interpret_App.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_INTERPRET_APP_H_
#define _GAME_MGA_INTERPRET_APP_H_

#include "game/mga/Project.h"
#include "Interpret_App_Options.h"

/**
 * @class GAME_Automation_App
 *
 * Main abstraction and entry point for the application.
 */
class GAME_Automation_App
{
public:
  /// Default constructor.
  GAME_Automation_App (void);

  /// Destructor.
  ~GAME_Automation_App (void);

  /**
   * Main entry point for the wrapper application.
   *
   * @param[in]     argc          Number of command-line arguments
   * @param[in]     argv          The command-line arguments
   */
  int run_main (int argc, char * argv []);

private:
  /// Process the specified file.
  int process_file (const std::string & file);

  /// List interpreters associated with the specified file.
  int list_interpreters (const std::string & file);

  /// Run the specified interpreter.
  int run (const std::string & progid);

  /// Parse the command-line arguments.
  int parse_args (int argc, char * argv []);

  /// Open a GME project.
  int open_gme_project (const std::string & file);

  /// Save the previously open GME project.
  int save_gme_project (void);

  /// Print the help screen for the application.
  void print_help (void);

  /// The GAME project managed by this application.
  GAME::Mga::Project project_;

  /// Options for the application.
  GAME_Automation_App_Options opts_;

  /// The project is an MGA file.
  bool is_mga_file_;

  std::string current_file_;
};

#if defined (__GAME_INLINE__)
#include "Interpret_App.inl"
#endif

#endif  // !defined _GAME_MGA_INTERPRET_APP_H_
