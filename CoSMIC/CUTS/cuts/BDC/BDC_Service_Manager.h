// -*- C++ -*-

//=============================================================================
/**
 * @class       BDC_Service_Manager.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BDC_SERVICE_MANAGER_H_
#define _CUTS_BDC_SERVICE_MANAGER_H_

#include "BDC_export.h"
#include "cuts/Component_Registry_Handler.h"
#include "tao/ORB.h"
#include "ace/Null_Mutex.h"
#include "ace/Thread_Manager.h"
#include "ace/Service_Gestalt.h"
#include "ace/Singleton.h"
#include "ace/Vector_T.h"
#include "ace/UUID.h"

// Forward decl.
class CUTS_System_Metric;

// Forward decl.
class CUTS_BDC_Service;

// Forward decl.
class CUTS_Testing_Service;

// Forward decl.
class ACE_Event;

/// Type decleration for a collection of service names.
typedef ACE_Vector <const char *>  CUTS_BDC_Service_Names;

//=============================================================================
/**
 * @class CUTS_BDC_Service_Manager
 *
 * Service object manager for the Benchmark Data Collector.
 */
//=============================================================================

class CUTS_BDC_Export CUTS_BDC_Service_Manager :
  public CUTS_Component_Registry_Handler,
  protected ACE_Service_Gestalt
{
public:
  /// Constructor.
  CUTS_BDC_Service_Manager (void);

  /// Destructor.
  virtual ~CUTS_BDC_Service_Manager (void);

  /**
   * Open the service manager. This will cause all services
   * opened in this manager to use the specified system metrics.
   *
   * @param[in]       orb         Target CORBA ORB.
   * @param[in]       metrics     Pointer to the system metrics.
   * @param[in]       tsvc        Target testing service.
   * @param[in]       notify      Notification event.
   */
  int open (::CORBA::ORB_ptr orb,
            CUTS_System_Metric * metrics,
            CUTS_Testing_Service * tsvc,
            ACE_Event * notify);

  /**
   * Load a service into the manager.
   *
   * @param[in]       name        Name of the service
   * @param[in]       path        Location of the service
   * @param[in]       args        Arguments for the service
   *
   * @retval          0           Successfully loaded the service.
   * @retval          other       Failed to load service.
   */
  int load_service (const char * name,
                    const char * path,
                    const char * args);

  /**
   * Unload a service from the manager.
   *
   * @param[in]       name        Name of the service.
   */
  int unload_service (const char * name);

  /**
   * Get a handle to a service.
   *
   * @param[in]     name      Name of the service.
   * @param[out]    svc       Pointer to the service.
   * @retval        0         Successfully found the service.
   * @retval        -1        Failed to locate the service.
   */
  int get_service (const char * name,
                   CUTS_BDC_Service * & svc);

  /**
   * Close the service manager. This will unload all the service
   * and release all its resources.
   *
   * @param[in]     timeout       Timeout value before forcing close.
   */
  int close (ACE_Time_Value * timeout = 0);

  int activate (void);

  int deactivate (void);

  int handle_component (const CUTS_Component_Info & info);

  /**
   * Get the number of services currently loaded.
   *
   * @return        The number of services.
   */
  size_t get_service_count (void) const;

  /**
   * Get a listing of all the loaded services. This method will
   * change the size of \a names.
   *
   * @param[in]       names         Target object for names.
   */
  void get_service_names (CUTS_BDC_Service_Names & names);

  /**
   * Get the ORB for the manager. The client must store this in
   * a _var since its reference count will be duplicated.
   *
   * @return      Pointer reference to the ORB.
   */
  ::CORBA::ORB_ptr get_orb (void) const;

  /**
   * Get a pointer to the system metrics.
   *
   * @return        Pointer to the metrics.
   */
  CUTS_System_Metric * metrics (void) const;

  /**
   * Get a pointer to the testing service.
   *
   * @return        Pointer to the testing service.
   */
  CUTS_Testing_Service * testing_service (void) const;

  /**
   * Get a pointer to the UUID for this manager.
   *
   * @return        Pointer to the UUID for the manager.
   */
  const ACE_Utils::UUID * get_uuid (void) const;

private:
  static ACE_THR_FUNC_RETURN thr_handle_metrics (void * param);

  /// The main ORB for this manager.
  ::CORBA::ORB_var orb_;

  /// Personal thread manager.
  ACE_Auto_Ptr <ACE_Thread_Manager> thr_mgr_;

  /// Pointer to the target metrics
  CUTS_System_Metric * metrics_;

  /// Pointer to the target testing service.
  CUTS_Testing_Service * tsvc_;

  /// Notificition condition for this manager.
  ACE_Event * notify_;

  /// UUID for the service manager.
  ACE_Auto_Ptr <ACE_Utils::UUID> uuid_;

  /// The active state of the manager.
  int active_;
};

// Singlton export decl.
CUTS_BDC_SINGLETON_DECLARE (ACE_Singleton,
                            CUTS_BDC_Service_Manager,
                            ACE_Null_Mutex);

// Macro definition for simplying access to singleton.
#define CUTS_BDC_SVC_MANAGER() \
  ACE_Singleton <CUTS_BDC_Service_Manager, ACE_Null_Mutex>::instance ()

#if defined (__CUTS_INLINE__)
#include "BDC_Service_Manager.inl"
#endif

#endif  // !defined _CUTS_BDC_SERVICE_MANAGER_H_
