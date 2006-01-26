// -*- C++ -*-

//=============================================================================
/**
 * @file    CUTS_CCM_CoWorkEr_T.h
 *
 * $Id$
 *
 * This file contains the base templates for defining CoWorkEr components.
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_COWORKER_T_H_
#define _CUTS_COWORKER_T_H_

#include "cuts/CCM_CoWorkEr.h"
#include "cuts/CCM_BenchmarkAgent_T.h"
#include "cuts/PortAgent.h"
#include <string>

//=============================================================================
/**
 * @class CUTS_CCM_CoWorkEr_T
 *
 * @brief CoWorkEr aspect for benchmarking components in CUTS
 *
 * This class contains methods and declarations that are needed begin
 * transforming a component into a CoWorkEr component. Once this class
 * has been parameterized by the target component, the next step is
 * to overload the methods you want to benchmark. The final step is to
 * program the behavior of the component and use the provided benchmarking
 * methods in the to collect the performance data.
 *
 * This entire process is handle by the Workload Modeling Language (WML).
 */
//=============================================================================

template <typename COMPONENT_EXEC, typename BENCHMARK_AGENT_EXEC>
class CUTS_CCM_CoWorkEr_T :
  virtual public CUTS_CCM_CoWorkEr,
  virtual public COMPONENT_EXEC
{
public:
  /// Type definition for component type.
  typedef COMPONENT_EXEC Component_Type;

  /// Constructor.
  CUTS_CCM_CoWorkEr_T (void);

  /// Destructor.
  virtual ~CUTS_CCM_CoWorkEr_T (void);

  ::CUTS::CCM_Benchmark_Agent_ptr get_benchmark_agent (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Get the unique ID of the CoWorkEr.
  ::CORBA::Long unique_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Set the unique ID of the CoWorkEr.
  void unique_id (::CORBA::Long unique_id ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Set the session context for the component.
  virtual void set_session_context (::Components::SessionContext_ptr ctx
                                    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,::Components::CCMException));

  /// Enter the preactivate state.
  virtual void ciao_preactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,::Components::CCMException));

  /// Enter the activate state.
  virtual void ccm_activate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException));

  /// Enter the postactivate state.
  virtual void ciao_postactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException));

  /// Enter the passivate state.
  virtual void ccm_passivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException));

  /// The component is being remove from the system.
  virtual void ccm_remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException));

protected:
  /// The benchmark agent for the CoWorkEr.
  typedef CUTS_CCM_Benchmark_Agent_T <
    BENCHMARK_AGENT_EXEC> This_Benchmark_Agent;

  ACE_Auto_Ptr <This_Benchmark_Agent> benchmark_agent_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr_T.inl"
#endif

#include "cuts/CCM_CoWorkEr_T.cpp"

#endif // !define _CUTS_COWORKER_T_H_
