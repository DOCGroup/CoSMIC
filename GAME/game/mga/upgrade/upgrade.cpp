// $Id$

#include "stdafx.h"
#include "Model_Upgrade.h"
#include "ace/Log_Msg.h"

//
// main
//
int main (int argc, char * argv [])
{
  try
  {
    GME_Model_Upgrade upgrade;
    return upgrade.run_main (argc, argv);
  }
  catch (...)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - caught unknown exception\n")));
  }

  return 1;
}
