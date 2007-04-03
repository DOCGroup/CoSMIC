// $Id$

#include "cuts/Port_Measurement.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Port_Measurement.inl"
#endif

#include "cuts/Benchmark_Visitor.h"
#include <algorithm>

//
// Reset_Exit_Times
//
struct Reset_Exit_Times
{
  inline
  void operator () (CUTS_Port_Measurement::Exit_Points::value_type & item)
  {
    item.second.reset ();
  }
};

//
// reset
//
void CUTS_Port_Measurement::reset (void)
{
  // Reset the <process_time_> and <transmit_time_> values
  this->process_time_.reset ();
  this->queuing_time_.reset ();

  // Reset all the exit times via this port.
  std::for_each (this->exitpoints_.begin (),
                 this->exitpoints_.end (),
                 Reset_Exit_Times ());
}

//
// accept
//
void CUTS_Port_Measurement::accept (CUTS_Benchmark_Visitor & visitor)
{
  visitor.visit_port_measurement (*this);
}
