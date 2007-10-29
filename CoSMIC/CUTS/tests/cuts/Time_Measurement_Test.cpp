// $Id$

#include "boost/test/unit_test.hpp"
#include "cuts/Time_Measurement.h"
#include "ace/OS_NS_unistd.h"
#include "ace/OS_NS_stdlib.h"

#include <algorithm>
#include <vector>
#include <numeric>

static CUTS_Time_Measurement tm_;

//=============================================================================
/*
 * Time_Measurement_Constructor
 */
//=============================================================================

void Time_Measurement_Constructor (void)
{
  BOOST_CHECK (tm_.maximum () == ACE_Time_Value::zero &&
               tm_.minimum () == ACE_Time_Value::zero &&
               tm_.total () == ACE_Time_Value::zero &&
               tm_.count () == 0);
}

//=============================================================================
/*
 * Time_Measurement_Add_Time
 */
//=============================================================================

void Time_Measurement_Add_Time (void)
{
  ACE_Time_Value tv;

  long msec = ACE_OS::rand () % 1000;
  tv.msec (msec);

  do
  {
    CUTS_Time_Measurement tm;
    tm += tv;

    BOOST_CHECK (tm.count () == 1);
    BOOST_CHECK (tm.total () == tv);
    BOOST_CHECK (tm.maximum () == tv);
    BOOST_CHECK (tm.minimum () == tv);
  } while (0);

  // randomly generate 50-100 numbers and verify the time measurement
  // object handles them correctly.

  size_t length = 50 + (ACE_OS::rand () % 50);

  typedef std::vector <long> Long_Vector;
  Long_Vector values (length);

  for (size_t i = 0; i < length; i ++)
  {
    msec = ACE_OS::rand () % 1000;
    tv.msec (msec);

    values[i] = msec;

    tm_ += tv;
  }

  Long_Vector::iterator min_iter =
    std::min_element (values.begin (), values.end ());
  Long_Vector::iterator max_iter =
    std::max_element (values.begin (), values.end ());
  long sum = std::accumulate (values.begin (), values.end (), 0);

  BOOST_CHECK (tm_.count () == length);
  BOOST_CHECK (tm_.minimum ().msec () == *min_iter);
  BOOST_CHECK (tm_.maximum ().msec () == *max_iter);
  BOOST_CHECK (tm_.total ().msec () == sum);
}

//=============================================================================
/*
 * Time_Measurement_Reset
 */
//=============================================================================

void Time_Measurement_Reset (void)
{
  tm_.reset ();

  BOOST_CHECK (tm_.maximum () == ACE_Time_Value::zero);
  BOOST_CHECK (tm_.minimum () == ACE_Time_Value::zero);
  BOOST_CHECK (tm_.total () == ACE_Time_Value::zero);
  BOOST_CHECK (tm_.count () == 0);
}

//=============================================================================
/*
 * Time_Measurement_Set
 */
//=============================================================================

void Time_Measurement_Set (void)
{
  // Verify setting the maximum value.
  ACE_Time_Value tv (ACE_OS::rand (), ACE_OS::rand ());
  tm_.maximum () = tv;

  BOOST_CHECK (tm_.maximum () == tv);

  // Verify setting the minimum value.
  tv.set (ACE_OS::rand (), ACE_OS::rand ());
  tm_.minimum () = tv;
  BOOST_CHECK (tm_.minimum () == tv);

  // Verify setting the total value.
  tv.set (ACE_OS::rand (), ACE_OS::rand ());
  tm_.total () = tv;

  BOOST_CHECK (tm_.total () == tv);

  // Verify setting the count value.
  size_t n = ACE_OS::rand ();
  tm_.count (n);

  BOOST_CHECK (tm_.count () == n);
}

//
// init_unit_test_suite
//
boost::unit_test::test_suite *
init_unit_test_suite (int argc, char * argv [])
{
  boost::unit_test::test_suite * ts =
    BOOST_TEST_SUITE ("CUTS_Time_Measurement");

  // Add the unit test to the test suite.
  ts->add (BOOST_TEST_CASE (&Time_Measurement_Constructor));
  ts->add (BOOST_TEST_CASE (&Time_Measurement_Add_Time));
  ts->add (BOOST_TEST_CASE (&Time_Measurement_Reset));
  ts->add (BOOST_TEST_CASE (&Time_Measurement_Set));

  return ts;
}
