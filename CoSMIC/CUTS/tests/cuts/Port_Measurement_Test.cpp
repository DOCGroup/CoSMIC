// $Id$

#include "Test_Suite.h"
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

CUTS_UNIT_TEST (CUTS_Port_Measurement_contructor)
{
  CUTS_Port_Measurement pm;

  CUTS_VERIFY_TEST ((pm.endpoints ().current_size () != 0),
                    "default contructor failed\n");

  return 0;
}

//=============================================================================
/*
 * Unit_Test: CUTS_Port_Measurement_prepare
 */
//=============================================================================

CUTS_UNIT_TEST (CUTS_Port_Measurement_prepare)
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
  CUTS_VERIFY_TEST (port_template.endpoints ().current_size () != keyset.size (),
                    "endpoint size ("
                    << port_template.endpoints ().current_size ()
                    << ") != keyset size ("
                    << keyset.size () << ")\n");

  // Prepare a new global_port_ measurement based on the template.
  port_template.prepare (global_port_);

  CUTS_VERIFY_TEST (global_port_.endpoints ().current_size () != keyset.size (),
                    "endpoint size ("
                    << global_port_.endpoints ().current_size ()
                    << ") != keyset size ("
                    << keyset.size () << ")\n");

  // First, we need to verify that all the keys in the key set
  // are in the endpoints for the global_port_ measurement.
  for (keyset_iter.first (); !keyset_iter.done (); keyset_iter.advance ())
  {
    keyset_iter.next (keyval_ptr);

    CUTS_VERIFY_TEST (global_port_.endpoints ().find (*keyval_ptr) != 0,
                      "failed to locate one of the keys\n");
  }

  // Now, we need to verify that all the endpoints where initialized
  // properly, i.e., have storage space for time measurements.
  CUTS_Port_Measurement_Endpoint_Map::
    CONST_ITERATOR port_iter (global_port_.endpoints ());

  for ( ; !port_iter.done (); port_iter ++)
  {
    CUTS_VERIFY_TEST (port_iter->item () == 0,
                      "failed to initialize a key\n");
  }

  return 0;
}

//=============================================================================
/*
 * Unit_Test: CUTS_Port_Measurement_record_exitpoint
 */
//=============================================================================

CUTS_UNIT_TEST (CUTS_Port_Measurement_record_exitpoint)
{
  // Record the for the <global_key_>.
  ACE_Time_Value tv = ACE_OS::gettimeofday ();
  global_port_.record_exitpoint (global_key_, tv);

  // Verify we are able to find the global key. Then verify that we
  // stored the time value in the global key.
  CUTS_Time_Measurement * tm;
  CUTS_VERIFY_TEST (global_port_.endpoints ().find (global_key_, tm) != 0,
                    "failed to located the global key\n");

  CUTS_VERIFY_TEST (tm->total () != tv,
                    "record_exitpoint failed to store the time value\n");

  return 0;
}

//=============================================================================
/*
 * Test_Suite: CUTS_Port_Measurement
 */
//=============================================================================

CUTS_TEST_SUITE_BEGIN ("CUTS_Port_Measurement");
  CUTS_ADD_UNIT_TEST ("constructor", CUTS_Port_Measurement_contructor);
  CUTS_ADD_UNIT_TEST ("prepare", CUTS_Port_Measurement_prepare);
  CUTS_ADD_UNIT_TEST ("record_exitpoint", CUTS_Port_Measurement_record_exitpoint);
CUTS_TEST_SUITE_END ();
