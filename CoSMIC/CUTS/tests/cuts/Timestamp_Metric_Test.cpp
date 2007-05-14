// $Id$

#include "Test_Suite.h"
#include "cuts/Timestamp_Metric.h"
#include "ace/OS_NS_sys_time.h"

//=============================================================================
/*
 * Unit_Test: CUTS_Timestamp_Metric_contructor
 */
//=============================================================================

CUTS_UNIT_TEST (CUTS_Timestamp_Metric_contructor)
{
  CUTS_Timestamp_Metric tma;

  CUTS_VERIFY_TEST ((tma.timestamp () != ACE_Time_Value::zero),
                    "default contructor failed\n");

  ACE_Time_Value current_time = ACE_OS::gettimeofday ();
  CUTS_Timestamp_Metric tmb (current_time);

  CUTS_VERIFY_TEST ((tmb.timestamp () != current_time),
                    "initializing constructor failed\n");
  return 0;
}

//=============================================================================
/*
 * Unit_Test: CUTS_Timestamp_Metric_setter
 */
//=============================================================================

CUTS_UNIT_TEST (CUTS_Timestamp_Metric_setter)
{
  CUTS_Timestamp_Metric metric;
  ACE_Time_Value current_time = ACE_OS::gettimeofday ();

  metric.timestamp (current_time);
  CUTS_VERIFY_TEST ((metric.timestamp () != current_time),
                    "timestamp setter failed\n");

  return 0;
}

//=============================================================================
/*
 * Unit_Test: CUTS_Timestamp_Metric_reset
 */
//=============================================================================

CUTS_UNIT_TEST (CUTS_Timestamp_Metric_reset)
{
  CUTS_Timestamp_Metric metric (ACE_OS::gettimeofday ());
  metric.reset ();

  CUTS_VERIFY_TEST ((metric.timestamp () != ACE_Time_Value::zero),
                    "reset method failed\n");

  return 0;
}

//=============================================================================
/*
 * Unit_Test: CUTS_Timestamp_Metric_is_valid
 */
//=============================================================================

CUTS_UNIT_TEST (CUTS_Timestamp_Metric_is_valid)
{
  CUTS_Timestamp_Metric metric;

  CUTS_VERIFY_TEST ((metric.is_valid ()),
                    "is_valid should be 'false'\n");

  metric.timestamp (ACE_OS::gettimeofday ());
  CUTS_VERIFY_TEST ((!metric.is_valid ()),
                    "is_valid should be 'true'\n");

  return 0;
}

//=============================================================================
/*
 * Test_Suite: CUTS_Timestamp_Metric
 */
//=============================================================================

CUTS_TEST_SUITE_BEGIN ("CUTS_Timestamp_Metric");
  CUTS_ADD_UNIT_TEST ("constructor", CUTS_Timestamp_Metric_contructor);
  CUTS_ADD_UNIT_TEST ("setter", CUTS_Timestamp_Metric_setter);
  CUTS_ADD_UNIT_TEST ("reset", CUTS_Timestamp_Metric_reset);
  CUTS_ADD_UNIT_TEST ("is_valid", CUTS_Timestamp_Metric_is_valid);
CUTS_TEST_SUITE_END ();
