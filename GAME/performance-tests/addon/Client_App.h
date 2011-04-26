// -*- C++ -*-

//=============================================================================
/**
 * @file      Client_App.h
 *
 * $Id$
 *
 * @author    James H. Hill <hillj@cs.iupui.edu>
 *            Tanumoy Pati <tpati@cs.iupui.edu>
 */
//=============================================================================

#ifndef _CLIENT_APP_H_
#define _CLIENT_APP_H_

#include "ace/SString.h"
#include "game/mga/Project.h"

/**
 * @class Client_App
 *
 * Wrapper class for the main entry point.
 */
class Client_App
{
public:
  /// Default constructor.
  Client_App (void);

  /// Destructor.
  ~Client_App (void);

  /// Main entry point for the application.
  int run_main (int argc, char * argv []);

private:
  /// Helper method to parse command-line arguments.
  int parse_args (int argc, char * argv []);

  /// Helper method to execute the test.
  int execute_test (GAME::Mga::Project p);

  /// The program id of the automated add-on.
  ACE_CString addon_progid_;

  /// The test to execute.
  ACE_CString test_;

  /// Number of iterations in test.
  size_t iterations_;

  /// Size of test block
  int block_size_;
};

#endif
