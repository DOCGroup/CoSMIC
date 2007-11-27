// -*- C++ -*-

//=============================================================================
/**
 * @file        CCM_CoWorkEr_Proxy_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CCM_COWORKER_PROXY_T_H_
#define _CUTS_CCM_COWORKER_PROXY_T_H_

#include "cuts/CCM_CoWorkEr_Proxy.h"
#include "cuts/Event_Handler_Manager_T.h"
#include "cuts/Pending_Op_List_T.h"
#include "ace/SStringfwd.h"
#include "ace/String_Base.h"
#include "ace/Unbounded_Set.h"

//=============================================================================
/**
 * @class CUTS_CCM_CoWorkEr_Proxy_T
 *
 * Template base class class for CoWorkEr proxies. This simplifies
 * the generation/creation of a proxy by abstracting away the necessary
 * parameters that are need to successfully load and manage a component.
 * Currently, this component can only handle SessionComponent types.
 *
 * @todo Add support for other component types (e.g., entity).
 */
//=============================================================================

template <typename PROXY_EXEC, typename CTX_TYPE,
          typename CCM_TYPE, typename CCM_HOME>
class CUTS_CCM_CoWorkEr_Proxy_T :
  public virtual PROXY_EXEC,
  public CUTS_CCM_CoWorkEr_Proxy
{
public:
  /// Type definition for the implementation type.
  typedef CCM_TYPE _impl_type;

  /// Type definition for the home type.
  typedef CCM_HOME _home_type;

  /// Type definition for the proxy executor type.
  typedef PROXY_EXEC _proxy_exec_type;

  /// Destructor.
  virtual ~CUTS_CCM_CoWorkEr_Proxy_T (void);

  /**
   * Method for setting the proxy implementation. The format of the
   * implementation string is as follows: [module]:[entry]. The \a module
   * field is the location of the component on disk (i.e., shared library).
   * The \a entry field is the entry point for the module (i.e., exported
   * method used to create) the home.
   *
   * @param[in]       impl        Implementation to load.
   */
  virtual void cuts_proxy_impl (const char * impl);

  /**
   * Get the implementation string used during deployment time.
   *
   * @return    The orginal string.
   */
  virtual char * cuts_proxy_impl (void);

  /**
   * Set the name of the proxy. This maps to the cuts_name attribute
   * of the proxy component.
   *
   * @param[in]       str         Name of the component.
   */
  virtual void cuts_name (const char * str);

  /**
   * Get the name of the component. This is the accessor method for
   * the cuts_name attribute of the proxy component.
   *
   * @return          Name of the component.
   */
  virtual char * cuts_name (void);

  virtual void ciao_preactivate (void);

  virtual void ccm_activate (void);

  virtual void ciao_postactivate (void);

  virtual void ccm_passivate (void);

  virtual void ccm_remove (void);

protected:
  /// Default constructor.
  CUTS_CCM_CoWorkEr_Proxy_T (void);

  /// Context for the proxy.
  ACE_Auto_Ptr <CTX_TYPE> context_;

  /// Reference to the home for the component.
  typename CCM_TYPE::_var_type type_impl_;

  /// Session component aspect of the real component.
  ::Components::SessionComponent_var sc_;

  /// Instance name of the hosted component.
  ACE_CString instance_;

  /// Original implementation string.
  ACE_CString cuts_proxy_impl_;

  /// Type definition for a collection of event handlers.
  typedef ACE_Unbounded_Set <
    CUTS_Event_Handler_Manager_Component_T <CCM_TYPE> * >
    Event_Handler_Set;

  /// Collection of event handlers in this component.
  Event_Handler_Set event_handlers_;

private:
  /// Type definition for a list of pending operations.
  typedef CUTS_Pending_Op_List_T <CCM_TYPE> Pending_Op_List;

  /// Collection of pending operations.
  Pending_Op_List pending_ops_;

  /**
   * Helper method for loading the proxy with an implemenation.
   *
   * @param[in]       module        Location of shared library.
   * @param[in]       entry         Entry point for implementation.
   */
  int load_implementation (const char * module,
                           const char * entry);

  /// Reset the state of the proxy.
  void reset (void);

  void init_component_registration (CUTS::Component_Registration & reg);

  // prevent the following operations
  CUTS_CCM_CoWorkEr_Proxy_T (const CUTS_CCM_CoWorkEr_Proxy_T &);
  CUTS_CCM_CoWorkEr_Proxy_T & operator = (const CUTS_CCM_CoWorkEr_Proxy_T &);
};

#if defined (__CUTS_INLINE__)
#include "CCM_CoWorkEr_Proxy_T.inl"
#endif

#include "CCM_CoWorkEr_Proxy_T.cpp"

#endif  // !defined _CUTS_CCM_COWORKER_PROXY_T_H_
