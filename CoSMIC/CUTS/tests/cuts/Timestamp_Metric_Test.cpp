// $Id$

#include "boost/test/unit_test.hpp"
#include "cuts/Timestamp_Metric.h"
#include "ace/OS_NS_sys_time.h"

//=============================================================================
/*
 * Unit_Test: CUTS_Timestamp_Metric_contructor
 */
//=============================================================================

void CUTS_Timestamp_Metric_contructor (void)
{
  // Test the default constructor.
  CUTS_Timestamp_Metric tma;
  BOOST_CHECK (tma.timestamp () == ACE_Time_Value::zero);

  // Test the initializing constructor.
  ACE_Time_Value current_time = ACE_OS::gettimeofday ();
  CUTS_Timestamp_Metric tmb (current_time);

  BOOST_CHECK (tmb.timestamp () == current_time);
}

//=============================================================================
/*
 * Unit_Test: CUTS_Timestamp_Metric_setter
 */
//=============================================================================

void CUTS_Timestamp_Metric_setter (void)
{
  CUTS_Timestamp_Metric metric;
  ACE_Time_Value current_time = ACE_OS::gettimeofday ();

  metric.timestamp (current_time);
  BOOST_CHECK (metric.timestamp () == current_time);
}

//=============================================================================
/*
 * Unit_Test: CUTS_Timestamp_Metric_reset
 */
//=============================================================================

void CUTS_Timestamp_Metric_reset (void)
{
  CUTS_Timestamp_Metric metric (ACE_OS::gettimeofday ());
  metric.reset ();

  BOOST_CHECK (metric.timestamp () == ACE_Time_Value::zero);
}

//=============================================================================
/*
 * Unit_Test: CUTS_Timestamp_Metric_is_valid
 */
//=============================================================================

void CUTS_Timestamp_Metric_is_valid (void)
{
  CUTS_Timestamp_Metric metric;
  BOOST_CHECK (!metric.is_valid ());

  metric.timestamp (ACE_OS::gettimeofday ());
  BOOST_CHECK (metric.is_valid ());
}

//
// init_unit_test_suite
//
boost::unit_test::test_suite *
init_unit_test_suite (int argc, char * argv [])
{
  boost::unit_test::test_suite * ts =
    BOOST_TEST_SUITE ("CUTS_Timestamp_Metric");

  // Add the unit test to the test suite.
  ts->add (BOOST_TEST_CASE (&CUTS_Timestamp_Metric_contructor));
  ts->add (BOOST_TEST_CASE (&CUTS_Timestamp_Metric_setter));
  ts->add (BOOST_TEST_CASE (&CUTS_Timestamp_Metric_reset));
  ts->add (BOOST_TEST_CASE (&CUTS_Timestamp_Metric_is_valid));

  return ts;
}
