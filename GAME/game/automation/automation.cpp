// $Id$

#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"
#include "Automation_App.h"

#define GAME_AUTOMATION_APP \
  ACE_Singleton <GAME_Automation_App, ACE_Null_Mutex>::instance ()

//
// main
//
int main (int argc, char * argv [])
{
  try
  {
    return GAME_AUTOMATION_APP->run_main (argc, argv);
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - caught unknown exception (%n:%l)\n")));
  }

  return 1;
}
