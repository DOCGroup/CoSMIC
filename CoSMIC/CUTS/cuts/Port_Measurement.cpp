// $Id$

#include "cuts/Port_Measurement.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Port_Measurement.inl"
#endif

#include "cuts/Metrics_Visitor.h"

//
// ~CUTS_Port_Measurement
//
CUTS_Port_Measurement::~CUTS_Port_Measurement (void)
{
  CUTS_Port_Measurement_Endpoint_Map::ITERATOR iter (this->endpoints_);

  for (; !iter.done (); iter ++)
    delete iter->item ();
}

//
// reset
//
void CUTS_Port_Measurement::reset (void)
{
  // Reset the <process_time_> and <transmit_time_> values
  this->process_time_.reset ();
  this->queuing_time_.reset ();

  // Reset all the exit times via this port.
  CUTS_Port_Measurement_Endpoint_Map::ITERATOR iter (this->endpoints_);

  for (; !iter.done (); iter ++)
    iter->item ()->reset ();
}

//
// accept
//
void CUTS_Port_Measurement::
accept (CUTS_Metrics_Visitor & visitor) const
{
  visitor.visit_port_measurement (*this);
}

//
// record_exitpoint
//
void CUTS_Port_Measurement::
record_exitpoint (size_t uid, const ACE_Time_Value & tv)
{
  CUTS_Time_Measurement * measure = 0;

  if (this->endpoints_.find (uid, measure) == 0)
  {
    *measure += tv;
  }
  else
  {
    ACE_ERROR ((LM_ERROR,
                "*** error (CUTS_Port_Measurement): unable to find port "
                "with id = %u\n",
                uid));
  }
}

//
// prepare
//
int CUTS_Port_Measurement::prepare (CUTS_Port_Measurement & pm)
{
  if (pm.endpoints ().current_size () != 0)
  {
    ACE_ERROR_RETURN ((LM_ERROR,
                       "*** error (CUTS_Port_Measurement): cannot prepare "
                       "an non-empty object\n"), -1);
  }

  CUTS_Time_Measurement * tm = 0;
  CUTS_Port_Measurement_Endpoint_Map::ITERATOR iter (this->endpoints_);

  for ( ; !iter.done (); iter ++)
  {
    ACE_NEW_RETURN (tm, CUTS_Time_Measurement, -1);

    pm.endpoints ().bind (iter->key (), tm);
  }

  return 0;
}
