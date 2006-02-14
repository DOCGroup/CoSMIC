// -*- C++ -*-

#ifndef _CUTS_COMPONENT_METRIC_H_
#define _CUTS_COMPONENT_METRIC_H_

#include "cuts/config.h"
#include "ace/RW_Thread_Mutex.h"
#include <map>
#include <string>

// forward declarations
class CUTS_Port_Metric;

//=============================================================================
/**
 * @class CUTS_Component_Metric
 */
//=============================================================================

class CUTS_Export CUTS_Component_Metric
{
public:
  /// Constructor.
  CUTS_Component_Metric (void);

  /// Destructor.
  ~CUTS_Component_Metric (void);

  /// Insert a new port into the component metrics.
  CUTS_Port_Metric * insert_port (const char * port);

  /// Remove a new port into the component metrics.
  void remove_port (const char * port);

  /// Get the metrics of the specified port.
  CUTS_Port_Metric * port_metrics (const char * port);

private:
  /// Type definition for the mapping of names to ports.
  typedef std::map <std::string, CUTS_Port_Metric *> Port_Metric_Map;

  /// Mapping of name to port metrics.
  Port_Metric_Map port_metrics_;

  /// Locking mechanism for thread sychronization.
  ACE_RW_Thread_Mutex lock_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Component_Metric.inl"
#endif

#endif  // !defined _CUTS_COMPONENT_METRIC_H_
