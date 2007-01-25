// $Id$

#include "cuts/Benchmark_Agent_i.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Benchmark_Agent_i.inl"
#endif

#include "cuts/Port_Agent.h"
#include "cuts/Port_Measurement.h"
#include "cuts/Activation_Record.h"
#include "cuts/Benchmark_Collector_Visitor.h"
#include "ace/Time_Value.h"
#include "ace/OS_NS_time.h"
#include <algorithm>

//
// Benchmark_Agent_i
//
Benchmark_Agent_i::Benchmark_Agent_i (void)
{

}

//
// Benchmark_Agent_i
//
Benchmark_Agent_i::~Benchmark_Agent_i (void)
{

}

//
// performance_data
//
void Benchmark_Agent_i::
collect_performance_data (::CUTS::Benchmark_Data_out data
                          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
                          ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Allocate a new <CUTS::Benchmark_Data> object.
  ACE_NEW_THROW_EX (data,
                    ::CUTS::Benchmark_Data,
                    ::CORBA::NO_MEMORY ());

  // Initialize the <benchmark_data> object with informantion
  // from this compenent, e.g., ID.
  data->owner = this->parent ();
  data->timestamp = ACE_OS::gettimeofday ().msec ();

  // Gather all the data from the agents.
  CUTS_Benchmark_Collector_Visitor visitor (*data);
  this->accept (visitor);
}
