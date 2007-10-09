// -*- C++ -*-

//=============================================================================
/**
 * @file        Component_Registry.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_COMPONENT_REGISTRY_H_
#define _CUTS_COMPONENT_REGISTRY_H_

#include "cuts/Component_Registry_Node.h"
#include "cuts/Host_Table.h"

#include "ace/Condition_Thread_Mutex.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Synch_Traits.h"
#include "ace/Message_Queue_T.h"
#include "ace/Unbounded_Set.h"
#include "ace/SString.h"

// Forward decl.
class CUTS_Component_Registry_Handler;

/// Type definition for the mapping of component types.
typedef
  ACE_Hash_Map_Manager <
  ACE_CString, CUTS_Component_Type *, ACE_RW_Thread_Mutex>
  CUTS_Component_Type_Map;

/// Type definition of the component registry map.
typedef
  ACE_Hash_Map_Manager <ACE_CString,
                        CUTS_Component_Registry_Node *,
                        ACE_RW_Thread_Mutex>
                        CUTS_Component_Registry_Map;

//=============================================================================
/**
 * @class CUTS_Component_Registry
 *
 * Collection of registered components. This is mainly used by the
 * testing service to keep track of the components that are present
 * in the testing environment.
 */
//=============================================================================

class CUTS_Export CUTS_Component_Registry
{
public:

  /// Type definition of the registry const iterator.
  typedef CUTS_Component_Registry_Map::CONST_ITERATOR CONST_ITERATOR;

  /// Default constructor.
  CUTS_Component_Registry (void);

  /// Destructor.
  virtual ~CUTS_Component_Registry (void);

  /**
   * Open the registry. This allows the active object stored
   * internally to signal registered handlers when a component's
   * state changes.
   *
   * @retval          0         Successfully opened the registry.
   * @retval          -1        Failed to open the registry.
   */
  int open (void);

  /**
   * Close the component registry. This actually causes the
   * service thread to stop, but you can still register components.
   */
  int close (void);

  /**
   * Determine if the registry is open, or closed. If the registry
   * is open, then it signals registered handlers when a components
   * registration information changes.
   *
   * @retval          0         The registry is not open.
   * @retval          1         The registry is open.
   */
  int is_open (void);

  /**
   * Register an callback with the registry. This allows an
   * object to receive notifications when a components status
   * changes.
   *
   * @param[in]       handler   The target handler.
   * @retval          0         Succcessfully registered \a handler.
   * @retval          -1        Failed to register \a handler.
   */
  int register_handler (CUTS_Component_Registry_Handler * handler);

  /**
   * Unregister a callback handler. If the \a handler is not registered
   * the nothing happens.
   *
   * @param[in]       handler   Target handler.
   * @retval          0         Successfully unregistered \a handler.
   * @retval          -1        Failed to unregister \a handler.
   */
  int unregister_handler (CUTS_Component_Registry_Handler * handler);

  /**
   * Register a component. This stores the node information internally.
   * The \a info must be a dynamically allocated object. Once the \a info
   * is registered, the caller does not have to manage the memory. If
   * the registration fails, then the caller is responsible for cleaning
   * up the allocated memory.
   *
   * @param[in]       info        The component information.
   * @retval          0           Successfully registered component.
   * @retval          1           Component already registered.
   * @retval          -1          Failed to register component.
   */
  int register_component (CUTS_Component_Registry_Node * info);

  /**
   * Unregister a component. This will remove the component information
   * from the registry as well as delete the registration information.
   * If the component cannot be found, then nothing happens.
   *
   * @param[in]       inst        The component instance name.
   * @param[in]       remove      Completely remove the node.
   */
  void unregister_component (const ACE_CString & inst);

  /**
   * Determine if a component instance is registered.
   *
   * @param[in]       uuid        The component instance.
   * @retval          true        The component is registered.
   * @retval          false       The component is not registered.
   */
  bool is_registered (const char * inst);

  /**
   * Get the number of component registered.
   *
   * @return      Number of components registered.
   */
  size_t registry_size (void) const;

  /**
   * Get a reference to the host table. This table contains all the
   * hosts that have been registered with this object.
   *
   * @return      Refernce to host table.
   */
  CUTS_Host_Table & hosts (void);

  /// @overload
  const CUTS_Host_Table & hosts (void) const;

  /**
   * Get a read-only reference to the entry table.
   *
   * @return      Read-only reference to entries.
   */
  const CUTS_Component_Registry_Map & entries (void) const;

  /**
   * Get the registeration information for a component.
   *
   * @param[in]   uid     The component's unique id.
   * @param[out]  info    Pointer to the components info.
   * @retval      0       \a info contains the component's info.
   * @retval      -1      Failed to locate \a uid component info.
   */
  int get_component_info (size_t uid,
                          const CUTS_Component_Info ** info) const;

  /**
   * Get all the component types that have been registered
   * with this object.
   *
   * @return      Reference to component types.
   */
  CUTS_Component_Type_Map & component_types (void);

  /// @overload
  const CUTS_Component_Type_Map & component_types (void) const;

protected:
  /// Type defintion of registration queue.
  typedef ACE_Message_Queue_Ex <
          CUTS_Component_Registry_Node,
          ACE_MT_SYNCH> CUTS_Message_Queue;

  CUTS_Component_Registry_Map registry_;

  /// Queue that contains the component information.
  CUTS_Message_Queue info_queue_;

private:
  /// Service thread for the registry. It is responsible for
  /// signaling registered objects when components changes
  /// their registration information.
  static ACE_THR_FUNC_RETURN thr_svc (void * param);

  /// Type definition for a collection of registered handlers.
  typedef ACE_Unbounded_Set <
          CUTS_Component_Registry_Handler *>
          CUTS_Handler_Set;

  /// Open state for the registry.
  int open_;

  /// Group id of the service thread.
  int grp_id_;

  /// Collection of registered handlers.
  CUTS_Handler_Set handlers_;

  /// The host tables for the registry.
  CUTS_Host_Table hosts_;

  /// Mapping of typenames to type information.
  CUTS_Component_Type_Map component_types_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Component_Registry.inl"
#endif

#endif  // !defined _CUTS_COMPONENT_REGISTRY_H_
