// $Id: Benchmark_Data_Collector_Impl.inl,v 1.1.4.1 2006/03/12 01:48:06 hillj Exp $

namespace CUTS
{
  //
  // testing_service
  //
  CUTS_INLINE
  Testing_Service_exec_i *
  Benchmark_Data_Collector_Impl::testing_service (void)
  {
    return this->testing_service_.get ();
  }
}
