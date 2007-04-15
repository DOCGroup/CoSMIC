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
#include "cuts/System_Metric_Handler.h"
#include "ace/Service_Object.h"

// Forward decl.
class CUTS_BDC_Service_Manager;

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
  public CUTS_Component_Registry_Handler,
  public CUTS_System_Metric_Handler
{
  // Friend decl.
  friend class CUTS_BDC_Service_Manager;

public:
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
   * Get a reference to the remoting object. This method is not
   * required by a service object unless it wants to provide
   * remoting capabilities. If this method is not defined it will
   * will return CUTS::BDC_Service::_nil () as a default.
   *
   * @return      Pointer reference to the service object.
   */
  virtual ::CUTS::BDC_Service_ptr get_remote_object (void) const;

  /**
   * Determine if the service is currently active.
   *
   * @retval      true      The service is active.
   * @retval      false     The service is not active.
   */
  bool is_active (void) const;

protected:
  /// Default constructor.
  CUTS_BDC_Service (void);

  /// Destructor.
  virtual ~CUTS_BDC_Service (void);

  /**
   * Get the service manager for this service object. This method
   * should only be used if the service is active. Otherwise, this
   * method will return NIL.
   *
   * @return      Pointer to the service manager.
   */
  const CUTS_BDC_Service_Manager * svc_mgr (void);

private:
  /// Pointer to the parent service manager.
  CUTS_BDC_Service_Manager * svc_mgr_;

  /// Active state of the service.
  int active_;
};

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BDC_SERVICE_DECL(export_marco) \
  extern "C" export_marco ACE_Service_Object * \
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
      reinterpret_cast <ACE_Service_Object *> (arg); \
    delete svcobj; \
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
