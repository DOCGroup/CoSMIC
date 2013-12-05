// $Id$

#include "Compiler_App.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#define T3_COMPILER_APP \
  ACE_Singleton <T3_Compiler_App, ACE_Null_Mutex>::instance ()

//
// main
//
int main (int argc, char * argv [])
{
  try
  {
    return T3_COMPILER_APP->run_main (argc, argv);
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - caught unknown exception\n")));
  }

  return 1;
}
