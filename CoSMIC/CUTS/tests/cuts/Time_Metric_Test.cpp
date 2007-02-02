// $Id$

#include "Test_Suite.h"
#include "Test_Macros.h"
#include "cuts/Time_Metric.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_sys_time.h"

static CUTS_Time_Metric time_metric_;

//=============================================================================
/*
 * Unit_Test_TM_Time_Value
 */
//=============================================================================

CUTS_UNIT_TEST (Unit_Test_TM_Time_Value)
{
  // Verify the default values for the <time_metric_>.
  CUTS_VERIFY_TEST (time_metric_.count () != 0,
                    "expected count () = 0");
  CUTS_VERIFY_TEST (time_metric_.best_time () != 0,
                    "expected best_time () = 0");
  CUTS_VERIFY_TEST (time_metric_.avg_time () != 0,
                    "expected avg_time () = 0");
  CUTS_VERIFY_TEST (time_metric_.worse_time () != 0,
                    "expected worse_time () = 0");

  // Update the <time_metric_> with arbitrary metrics.
  int count = ACE_OS::rand () % 50;
  long min = ACE_OS::rand () % 1000;
  long max = min + ACE_OS::rand () % 1000;

  time_metric_.update (count, (min + max), min, max);

  CUTS_VERIFY_TEST (time_metric_.count () != count,
                    "expected count () = " << count);

  CUTS_VERIFY_TEST (time_metric_.best_time () != min,
                    "expected best_time () = " << min);

  double avg = (max + min) / count;
  CUTS_VERIFY_TEST (time_metric_.avg_time () != avg,
                    "expected avg_time () = " << avg);

  CUTS_VERIFY_TEST (time_metric_.worse_time () != max,
                    "expected worse_time () = " << max);

  // Check the <timestamp> operation.
  ACE_Time_Value now = ACE_OS::gettimeofday ();
  time_metric_.timestamp (now);

  CUTS_VERIFY_TEST (time_metric_.timestamp () != now,
                    "set/get timestamp () is not equivalent");
  return 0;
}

//=============================================================================
/*
 * Unit_Test_TM_Operators
 */
//=============================================================================

CUTS_UNIT_TEST (Unit_Test_TM_Operators)
{
  do
  {
    // testing the copy constructor.
    CUTS_Time_Metric tm (time_metric_);

    CUTS_VERIFY_TEST ((tm.count () != time_metric_.count () ||
                       tm.avg_time () != time_metric_.avg_time () ||
                       tm.best_time () != time_metric_.best_time () ||
                       tm.worse_time () != time_metric_.worse_time ()),
                      "copy constructor failed");
  } while (0);

  do
  {
    // testing the assignment operator.
    CUTS_Time_Metric tm;
    tm = time_metric_;

    CUTS_VERIFY_TEST ((tm.count () != time_metric_.count () ||
                       tm.avg_time () != time_metric_.avg_time () ||
                       tm.best_time () != time_metric_.best_time () ||
                       tm.worse_time () != time_metric_.worse_time ()),
                      "assignment operator failed");
  } while (0);

  do
  {
    // testing the self-assigning addition operator
    CUTS_Time_Metric tm;
    tm += time_metric_;

    CUTS_VERIFY_TEST ((tm.avg_time () != time_metric_.avg_time () ||
                       tm.best_time () != time_metric_.best_time () ||
                       tm.worse_time () != time_metric_.worse_time ()),
                      "self-assigning addition operation failed");
  } while (0);
  return 0;
}

//=============================================================================
/*
 * Unit_Test_TM_Reset
 */
//=============================================================================

CUTS_UNIT_TEST (Unit_Test_TM_Reset)
{
  time_metric_.reset ();

  CUTS_VERIFY_TEST ((time_metric_.count () != 0 ||
                     time_metric_.avg_time () != 0 ||
                     time_metric_.best_time () != 0 ||
                     time_metric_.worse_time () != 0),
                    "all values of time metric not 0");
  return 0;
}

//=============================================================================
/*
 * CUTS_Time_Metric_TS
 */
//=============================================================================

CUTS_TEST_SUITE_BEGIN (CUTS_Time_Metric_TS, CUTS_Time_Metric)
  CUTS_ADD_UNIT_TEST ("TM_Time_Value", Unit_Test_TM_Time_Value)
  CUTS_ADD_UNIT_TEST ("TM_Operators", Unit_Test_TM_Operators)
  CUTS_ADD_UNIT_TEST ("TM_Reset", Unit_Test_TM_Reset)
CUTS_TEST_SUITE_END (CUTS_Time_Metric_TS)

