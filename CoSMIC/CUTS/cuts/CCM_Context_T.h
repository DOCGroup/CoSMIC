// -*- C++ -*-

//=============================================================================
/**
 * @file      CCM_Context_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CCM_CONTEXT_H_
#define _CUTS_CCM_CONTEXT_H_

#include "ciao/CCM_ContainerC.h"

class CUTS_Benchmark_Agent;

template <typename T>
class CUTS_CCM_Context_T : public T
{
public:
  /// Destructor.
  virtual ~CUTS_CCM_Context_T (void);

  ::Components::Principal_ptr get_caller_principal (void);

  ::Components::CCMHome_ptr get_CCM_home (void);

  ::CORBA::Boolean get_rollback_only (void);

  ::Components::Transaction::UserTransaction_ptr
    get_user_transaction (void);

  ::CORBA::Boolean is_caller_in_role (const char * role);

  void set_rollback_only (void);

  ::CORBA::Object_ptr get_CCM_object (void);

  ::CORBA::Object_ptr resolve_service_reference (const char * service_id);

protected:
  /**
   * Initializing constuctor.
   *
   * @param[in]     ctx       Source context.
   */
  CUTS_CCM_Context_T (::Components::SessionContext::_ptr_type ctx,
                      CUTS_Benchmark_Agent * agent);

  /// The variable type context.
  typename T::_var_type ctx_;

  /// Pointer to a benchmark agent.
  CUTS_Benchmark_Agent * agent_;
};

#if defined (__CUTS_INLINE__)
#include "CCM_Context_T.inl"
#endif

#include "CCM_Context_T.cpp"

#endif  // !defined _CUTS_CCM_CONTEXT_H_
