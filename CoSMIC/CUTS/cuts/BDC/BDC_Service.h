// -*- C++ -*-

//=============================================================================
/**
 * @file      BDC_Service.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#include "BDC_export.h"
#include "serviceC.h"
#include "cuts/Component_Registry_Handler.h"
#include "ace/Service_Object.h"
#include "ace/Thread_Mutex.h"
#include "tao/ORB.h"

// Forward decl.
class CUTS_System_Metric;

// Forward decl.
class CUTS_BDC_Service_Manager;

// Forward decl.
class ACE_Event;

//=============================================================================
/**
 * @class CUTS_BDC_Service
 *
 * Base class for all BDC service objects. It defines the interface
 * for the service object that allows the Benchmark Data Collector (BDC)
 * to interact with it.
 */
//=============================================================================

class CUTS_BDC_Export CUTS_BDC_Service :
  public ACE_Service_Object,
  public CUTS_Component_Registry_Handler
{
  // Friend decl.
  friend class CUTS_BDC_Service_Manager;

public:
  /**
   * Initialize the service object. During this time the object
   * has not been initailized with the system metrics.
   *
   * @param[in]       argc      Number of command-line arguments.
   * @param[in]       argv      The command-line arguments.
   */
  virtual int init (int argc, ACE_TCHAR * argv []);

  /**
   * Cleanup callback method for the service object. During this
   * time the object has no reference to the system metrics.
   */
  virtual int fini (void);

  /**
   * Activate the service object. This allows the service object
   * to perform any initial operations on the system metrics.
   */
  virtual int handle_activate (void);

  /**
   * Deactivate the service object. This allows the service object
   * to perform any final operations on the system metrics.
   */
  virtual int handle_deactivate (void);

  /**
   * Handle the state change of a component.
   *
   * @param[in]     info        Information for the component.
   */
  virtual int handle_component (const CUTS_Component_Info & info);

  /**
   * Signal the service object to handle the new set of data. This
   * method is required by all service objects because it is their
   * only way of processing data collected from the testing
   * environment.
   */
  virtual int handle_metrics (void);

  /**
   * Get a reference to the remoting object. This method is not
   * required by a service object unless it wants to provide
   * remoting capabilities. If this method is not defined it will
   * will return CUTS::BDC_Service::_nil () as a default.
   *
   * @return      Pointer reference to the service object.
   */
  virtual CUTS::BDC_Service_ptr get_remote_object (void) const;

protected:
  /// Default constructor.
  CUTS_BDC_Service (void);

  /// Destructor.
  virtual ~CUTS_BDC_Service (void);

  /**
   * Accessor method to the system metrics. We do not allow
   * direct access to the metrics for security reasons.
   *
   * @return        Reference to the system metrics.
   */
  const CUTS_System_Metric & metrics (void) const;

  /// The hosting ORB for this service.
  ::CORBA::ORB_var orb_;

private:
  //===========================================================================
  /**
   * @struct Svc_Thread_Param
   *
   * Thread parameter for the service object. It contain vital information
   * for properly configuring the service object for its multithreaded
   * environment (e.g., service and notification object).
   */
  //===========================================================================
  struct Svc_Thread_Param
  {
    /// Pointer to the service object.
    CUTS_BDC_Service * svc_;

    /// Pointer to the notication object.
    ACE_Event * notify_;
  };

  /**
   * Service thread funtion. This method is responsible for
   * monitoring invoking handle_metrics () when new data is
   * present.
   *
   * @param[in]     param       Thread function parameter.
   */
  static ACE_THR_FUNC_RETURN svc (void * param);

  /// Pointer to the system metrics.
  CUTS_System_Metric * metrics_;

  /// Active state of the service.
  int active_;
};

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BDC_SERVICE_DECL(export) \
  extern "C" export ACE_Service_Object * \
  _make_CUTS_BDC_Service (void (**gobbler) (void *))

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BDC_SERVICE_IMPL(classname) \
  void _gobble_CUTS_BDC_Service (void * arg) \
  { \
    ACE_Service_Object * svcobj = \
      ACE_reinterpret_cast (ACE_Service_Object *, arg); \
    delete arg; \
  } \
  ACE_Service_Object  * \
  _make_CUTS_BDC_Service (void (**gobbler) (void *)) \
  { \
    if (gobbler != 0) *gobbler = &_gobble_CUTS_BDC_Service; \
    return new classname (); \
  }

#if defined (__CUTS_INLINE__)
#include "BDC_Service.inl"
#endif
