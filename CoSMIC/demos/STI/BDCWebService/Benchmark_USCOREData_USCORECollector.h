#ifndef BENCHMARK_USCOREDATA_USCORECOLLECTOR_H
#define BENCHMARK_USCOREDATA_USCORECOLLECTOR_H

#include "cuts/CUTSC.h"
#include "cuts/CUTSC.h"
#include "SLICEH.h"

class SOAP_CMAC Benchmark_USCOREData_USCORECollector : public soap
{

  private:

  CUTS::BDC_Control_Handle_var controls_;

  CUTS::Path_Measurement_var online_measurements_;

  public:

  Benchmark_USCOREData_USCORECollector (CUTS::BDC_Control_Handle_ptr controls, CUTS::Path_Measurement_ptr online_measurements);

  Benchmark_USCOREData_USCORECollector();

  Benchmark_USCOREData_USCORECollector(soap_mode iomode);

  Benchmark_USCOREData_USCORECollector(soap_mode imode, soap_mode omode);

  virtual ~Benchmark_USCOREData_USCORECollector();

  virtual void Benchmark_USCOREData_USCORECollector_init (soap_mode imode, soap_mode omode);

  virtual int serve();

  virtual int dispatch();

  virtual int collect_USCOREperformance_USCOREdata (struct SLICE__collect_USCOREperformance_USCOREdataResponse& _param_1);

  virtual int execution_USCOREtime (int path_USCOREid, 
                                    struct SLICE__execution_USCOREtimeResponse& _param_1);

  virtual int unbind_USCOREto_USCOREpath (int path_USCOREid, 
                                          struct SLICE__unbind_USCOREto_USCOREpathResponse& _param_1);

  virtual int bind_USCOREto_USCOREpath (CUTS_x002e_USCORESE_USCOREPath_USCORESequence* path, 
                                        unsigned short flags, 
                                        int& _USCOREreturn);
};


#endif /* BENCHMARK_USCOREDATA_USCORECOLLECTOR_H */
