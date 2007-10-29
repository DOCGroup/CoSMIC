// -*- C++ -*-
// $Id$

#include "boost/test/unit_test.hpp"
#include "cuts/workers/CPU/CPU_Worker.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/Log_Msg.h"
#include "ace/Time_Value.h"
#include "ace/High_Res_Timer.h"
#include "ace/Thread.h"
#include "ace/Malloc_T.h"
#include "ace/Null_Mutex.h"
#include <math.h>

void Unit_Test_CPU_run (void)
{
  CUTS_CPU_Worker worker;
  ACE_High_Res_Timer timer;
  ACE_Time_Value elapsed;

  for (size_t i = 0; i < 100; i ++)
  {
    size_t msec = 500;

    timer.start ();
    worker.run (msec);
    timer.stop ();

    timer.elapsed_time (elapsed);
    ACE_DEBUG ((LM_DEBUG,
                "proposed time = %d; elapsed time = %d; diff = %d msec\n",
                msec,
                elapsed.msec (),
                msec - elapsed.msec ()));
  }
}

//
// init_unit_test_suite
//
boost::unit_test::test_suite *
init_unit_test_suite (int argc, char * argv [])
{
  boost::unit_test::test_suite * ts =
    BOOST_TEST_SUITE ("CUTS_CPU_Worker");

  // Add the unit test to the test suite.
  ts->add (BOOST_TEST_CASE (&Unit_Test_CPU_run));

  return ts;
}
