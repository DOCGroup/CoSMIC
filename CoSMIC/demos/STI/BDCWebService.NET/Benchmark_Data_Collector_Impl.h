#ifndef BENCHMARK_DATA_COLLECTOR_IMPL_H
#define BENCHMARK_DATA_COLLECTOR_IMPL_H

#include <exception>
#include <orbsvcs/orbsvcs/CosNamingC.h>
#include <string>
#include <ace/Auto_Functor.h>
#include <cuts/CUTSC.h>
#include <cuts/CUTSC.h>
#include <cuts/BDC/Benchmark_Data_CollectorC.h>
#include <Benchmark_Data_Collector.h>

namespace SLICE
{

  [WebService(Namespace="urn:SLICE")]

  public ref class Benchmark_Data_Collector
  	: public System::Web::Services::WebService,
  	  public SLICE::ICUTSBenchmark_Data_Collector_SE_online_measurements,
  	  public SLICE::ICUTSBenchmark_Data_Collector_SE_controls
  {

    public:

    Benchmark_Data_Collector();

    ~Benchmark_Data_Collector();

    virtual CUTSEvent_Time_Info^ execution_time(System::Int32 path_id);

    virtual System::Void unbind_to_path(System::Int32 path_id);

    virtual System::Int32 bind_to_path(cli::array<CUTSPath_Element^>^ path, 
                                       System::UInt16 flags);

    virtual System::Void collect_performance_data();

    private:

    CORBA::ORB_ptr orb_;

    CUTS::BDC_Control_Handle_ptr controls_;

    CUTS::Path_Measurement_ptr online_measurements_;

    CUTS::Benchmark_Data_Collector_ptr benchmark_data_collector_;
  };
}


#endif /* BENCHMARK_DATA_COLLECTOR_IMPL_H */
