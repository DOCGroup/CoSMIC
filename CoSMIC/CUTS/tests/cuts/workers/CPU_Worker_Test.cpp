// -*- C++ -*-
// $Id$

#include "Test_Suite.h"
#include "cuts/CPUWorker.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/Log_Msg.h"
#include "ace/Time_Value.h"
#include "ace/High_Res_Timer.h"
#include "ace/Thread.h"
#include "ace/Malloc_T.h"
#include "ace/Null_Mutex.h"
#include <math.h>

CUTS_UNIT_TEST (Unit_Test_CPU_run)
{
  CUTS_CPU_Worker worker;
  ACE_High_Res_Timer timer;
  ACE_Time_Value elapsed;

  for (size_t i = 0; i < 100; i ++)
  {
    size_t msec = 500;
    size_t cycles;

    timer.start ();
    worker.run (msec);
    timer.stop ();

    timer.elapsed_time (elapsed);
    ACE_DEBUG ((LM_DEBUG,
                "proposed time = %d; elapsed time = %d; diff = %d msec "
                "(cycles = %d)\n",
                msec,
                elapsed.msec (),
                msec - elapsed.msec (),
                cycles));
  }

  return 0;
}

//=============================================================================
/*
 * CUTS_CPU_Worker_TS
 */
//=============================================================================

CUTS_TEST_SUITE_BEGIN (CUTS_CPU_Worker_TS, CUTS_CPU_Worker)
  CUTS_ADD_UNIT_TEST ("CPU_run", Unit_Test_CPU_run)
CUTS_TEST_SUITE_END (CUTS_CPU_Worker_TS)

