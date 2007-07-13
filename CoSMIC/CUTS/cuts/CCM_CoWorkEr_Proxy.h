// -*- C++ -*-

//=============================================================================
/**
 * @file        CCM_CoWorkEr.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CCM_COWORKER_H_
#define _CUTS_CCM_COWORKER_H_

#include "cuts/CUTS_exec_export.h"
#include "cuts/Benchmark_Agent_i.h"
#include "tao/LocalObject.h"
//#include "tao/RTCORBA/RTCORBA.h"
//#include "tao/RTPortableServer/RT_POA.h"

//=============================================================================
/**
 * @class CUTS_CCM_CoWorkEr
 *
 * Base class that all CoWorkEr executors derive from.
 */
//=============================================================================

class CUTS_EXEC_Export CUTS_CCM_CoWorkEr_Proxy :
  public TAO_Local_RefCounted_Object
{
protected:
  /// Default constructor.
  CUTS_CCM_CoWorkEr_Proxy (void);

  /// Destructor.
  virtual ~CUTS_CCM_CoWorkEr_Proxy (void);

  /**
   * Initialize the real-time portion of the CoWorkEr.
   *
   * @param[in]     orb       Source ORB.
   * @param[in]     poa       Target POA.
   */
  void init_realtime (CORBA::ORB_ptr orb, PortableServer::POA_ptr poa);

  /**
   * Helper method for registering the benchmark agent with the
   * testing service.
   *
   * @param[in]     ts      Reference to the testing service.
   * @param[in]     agent   Agent to register with testing service.
   * @param[in]     name    Name to register agent.
   * @return        Registration id of the agent.
   */
  static long register_i (CUTS::Testing_Service_ptr ts,
                          CUTS::Component_Registration & reg);

  /// Pointer to the <Benchmark_Agent_i> implementation.
  Benchmark_Agent_i * agent_;

  ///// Reference to the RTCORBA orb.
  //RTCORBA::RTORB_var rt_orb_;

  ///// Reference to the RTCORBA POA.
  //RTPortableServer::POA_var benchmark_poa_;

  /// POA servant.
  PortableServer::ServantBase_var servant_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr_Proxy.inl"
#endif

#endif  // !defined _CUTS_CCM_COWORKER_H_
