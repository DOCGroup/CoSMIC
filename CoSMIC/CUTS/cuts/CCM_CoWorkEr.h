#ifndef _CUTS_CCM_COWORKER_H_
#define _CUTS_CCM_COWORKER_H_

#include "cuts/config.h"
#include "cuts/CUTS_exec_export.h"
#include "cuts/Benchmark_Agent_i.h"
#include "ComponentsC.h"
#include "tao/RTCORBA/RTCORBA.h"
#include "tao/RTPortableServer/RT_POA.h"

#include <string>

class CUTS_EXEC_Export CUTS_CCM_CoWorkEr
{
public:
  /// Constructor.
  CUTS_CCM_CoWorkEr (void);

  /// Destructor.
  virtual ~CUTS_CCM_CoWorkEr (void);

protected:
  void init (void);

  void init_realtime (CORBA::ORB_ptr orb, PortableServer::POA_ptr poa);

  static long register_i (::CUTS::Testing_Service_ptr ts,
                          ::CUTS::Benchmark_Agent_ptr agent,
                          const char * name);

  /// Pointer to the <Benchmark_Agent_i> implementation;
  Benchmark_Agent_i * benchmark_agent_;

  /// Registration ID for the CoWorkEr.
  long registration_id_;

  RTCORBA::RTORB_var rt_orb_;

  RTPortableServer::POA_var benchmark_poa_;

  PortableServer::ServantBase_var servant_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr.inl"
#endif

#endif  // !defined _CUTS_CCM_COWORKER_H_
