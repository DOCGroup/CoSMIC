// $Id$

#include "cuts/Benchmark_Agent_i.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/Benchmark_Agent_i.inl"
#endif

#include "cuts/performance_i.h"

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
collect_performance_data (CUTS::Component_Metric_out data)
{
  // Allocate a new <CUTS::Benchmark_Data> object then call the
  // packing operation(s) for the collected operations.
  ACE_NEW_THROW_EX (data,
                    CUTS::Component_Metric,
                    ::CORBA::NO_MEMORY ());

  *data <<= *this;
}
