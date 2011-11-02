// $Id$

#include "stdafx.h"
#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"
#include "Interpret_App.h"

#define GAME_MGA_INTERPRET_APP \
  ACE_Singleton <GAME_Automation_App, ACE_Null_Mutex>::instance ()

//
// main
//
int main (int argc, char * argv [])
{
  try
  {
    return GAME_MGA_INTERPRET_APP->run_main (argc, argv);
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - caught unknown exception\n")));
  }

  return 1;
}
