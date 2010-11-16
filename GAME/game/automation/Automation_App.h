// -*- C++ -*-

//=============================================================================
/**
 * @file        Executor_App.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_AUTOMATION_APP_H_
#define _GAME_AUTOMATION_APP_H_

#include "game/Project.h"
#include "Automation_App_Options.h"

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

  int run_main (int argc, char * argv []);

private:
  int run (const std::string & progid);

  int parse_args (int argc, char * argv []);

  int open_gme_project (void);

  int save_gme_project (void);

  /// Print the help screen for the application.
  void print_help (void);

  /// The GAME project managed by this application.
  GAME::Project project_;

  GAME_Automation_App_Options opts_;

  bool is_mga_file_;
};

#if defined (__GAME_INLINE__)
#include "Automation_App.inl"
#endif

#endif  // !defined _GME_T2M_EXECUTOR_APP_H_
