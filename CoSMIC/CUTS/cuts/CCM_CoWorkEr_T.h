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

template <typename COMPONENT, typename COMPONENT_CONTEXT>
class CUTS_CCM_CoWorkEr_T :
  public virtual COMPONENT,
  public virtual CUTS_CCM_CoWorkEr
{
public:
  /// Type of component wrapped by this class.
  typedef COMPONENT Component_Type;

  /// Type definition for component type.
  typedef COMPONENT_CONTEXT Component_Context;

  /// Constructor.
  CUTS_CCM_CoWorkEr_T (void);

  /// Destructor.
  virtual ~CUTS_CCM_CoWorkEr_T (void);

  /// Set the session context for the component.
  virtual void set_session_context (
    ::Components::SessionContext_ptr ctx
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((::CORBA::SystemException,
                     ::Components::CCMException));

  /// Get the benchmark agent for the component.
  ::CUTS::CCM_Benchmark_Agent_ptr get_cuts_benchmark_agent (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
  {
    return CUTS_CCM_CoWorkEr::get_cuts_benchmark_agent ();
  }

  /// Get the unique ID of the CoWorkEr.
  ::CORBA::Long cuts_coworker_id (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return CUTS_CCM_CoWorkEr::cuts_coworker_id ();
  }

  /// Set the unique ID of the CoWorkEr.
  void cuts_coworker_id (
    ::CORBA::Long coworker_id
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    CUTS_CCM_CoWorkEr::cuts_coworker_id (coworker_id);
  }

  /// Get the name of the server used by this CoWorkEr component.
  char * cuts_coworker_database (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    return CUTS_CCM_CoWorkEr::cuts_coworker_database ();
  }

  /// Change the name of the server used by this CoWorkEr component.
  void cuts_coworker_database (
    const char * database
    ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException))
  {
    CUTS_CCM_CoWorkEr::cuts_coworker_database (database);
  }

protected:
  /// Context for the component.
  COMPONENT_CONTEXT * context_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr_T.inl"
#endif

#include "cuts/CCM_CoWorkEr_T.cpp"

#endif // !define _CUTS_COWORKER_T_H_
