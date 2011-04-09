// $Id$

#include "StdAfx.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include "Client_App.h"

typedef ACE_Singleton <Client_App, ACE_Null_Mutex> CLIENT_APP;

//
// main
//
int ACE_TMAIN (int argc, char * argv [])
{
  try
  {
    return 0 == CLIENT_APP::instance ()->run_main (argc, argv) ? 0 : 1;
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - caught unknown exception\n")));
  }

  return 1;
}
