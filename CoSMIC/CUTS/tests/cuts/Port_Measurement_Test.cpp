// $Id$

#include "boost/test/unit_test.hpp"
#include "cuts/Port_Measurement.h"
#include "ace/Containers_T.h"
#include "ace/OS_NS_sys_time.h"

static CUTS_Port_Measurement global_port_;
static size_t global_key_;

//=============================================================================
/*
 * Unit_Test: CUTS_Port_Measurement_contructor
 */
//=============================================================================

void CUTS_Port_Measurement_contructor (void)
{
  CUTS_Port_Measurement pm;
  BOOST_CHECK (pm.endpoints ().current_size () == 0);
}

//=============================================================================
/*
 * Unit_Test: CUTS_Port_Measurement_prepare
 */
//=============================================================================

void CUTS_Port_Measurement_prepare (void)
{
  size_t * keyval_ptr;
  size_t max_size = ACE_OS::rand () % 50;

  // Create a set of 10 - 60 unique keys.
  typedef ACE_Bounded_Set <size_t> keyset_t;
  keyset_t keyset (max_size);

  // Randomly select a key for later.
  size_t index = ACE_OS::rand () % max_size;

  while (!keyset.is_full ())
  {
    if (keyset.size () != index)
    {
      keyset.insert (ACE_OS::rand ());
    }
    else
    {
      global_key_ = ACE_OS::rand ();
      keyset.insert (global_key_);
    }
  }

  // Insert all the keys into the endpoint map as a template.
  CUTS_Port_Measurement port_template;
  keyset_t::ITERATOR keyset_iter (keyset);

  for ( ; !keyset_iter.done (); keyset_iter.advance ())
  {
    keyset_iter.next (keyval_ptr);
    port_template.endpoints ().bind (*keyval_ptr, 0);
  }

  // Verify the template has the correct number of keys.
  BOOST_CHECK (port_template.endpoints ().current_size () == keyset.size ());

  // Prepare a new global_port_ measurement based on the template.
  port_template.prepare (global_port_);
  BOOST_CHECK (global_port_.endpoints ().current_size () == keyset.size ());

  // First, we need to verify that all the keys in the key set
  // are in the endpoints for the global_port_ measurement.
  for (keyset_iter.first (); !keyset_iter.done (); keyset_iter.advance ())
  {
    keyset_iter.next (keyval_ptr);
    BOOST_CHECK (global_port_.endpoints ().find (*keyval_ptr) == 0);
  }

  // Now, we need to verify that all the endpoints where initialized
  // properly, i.e., have storage space for time measurements.
  CUTS_Port_Measurement_Endpoint_Map::
    CONST_ITERATOR port_iter (global_port_.endpoints ());

  for ( ; !port_iter.done (); port_iter ++)
  {
    BOOST_CHECK (port_iter->item () != 0);
  }
}

//=============================================================================
/*
 * Unit_Test: CUTS_Port_Measurement_record_exitpoint
 */
//=============================================================================

void CUTS_Port_Measurement_record_exitpoint (void)
{
  // Record the for the <global_key_>.
  ACE_Time_Value tv = ACE_OS::gettimeofday ();
  global_port_.record_exitpoint (global_key_, tv);

  // Verify we are able to find the global key. Then verify that we
  // stored the time value in the global key.
  CUTS_Time_Measurement * tm;
  BOOST_CHECK (global_port_.endpoints ().find (global_key_, tm) == 0);
  BOOST_CHECK (tm->total () == tv);
}

//
// init_unit_test_suite
//
boost::unit_test::test_suite *
init_unit_test_suite (int argc, char * argv [])
{
  boost::unit_test::test_suite * ts =
    BOOST_TEST_SUITE ("CUTS_Port_Measurement");

  // Add the unit test to the test suite.
  ts->add (BOOST_TEST_CASE (&CUTS_Port_Measurement_contructor));
  ts->add (BOOST_TEST_CASE (&CUTS_Port_Measurement_prepare));
  ts->add (BOOST_TEST_CASE (&CUTS_Port_Measurement_record_exitpoint));

  return ts;
}
