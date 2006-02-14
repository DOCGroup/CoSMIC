// -*- C++ -*-

#ifndef _CUTS_SYSTEM_METRIC_H_
#define _CUTS_SYSTEM_METRIC_H_

#include "cuts/config.h"
#include "ace/RW_Thread_Mutex.h"
#include <map>
#include <string>

class CUTS_Component_Metric;

//=============================================================================
/**
 * @class CUTS_System_Metric
 */
//=============================================================================

class CUTS_Export CUTS_System_Metric
{
public:
  /// Constructor.
  CUTS_System_Metric (void);

  /// Destructor.
  ~CUTS_System_Metric (void);

  CUTS_Component_Metric * insert_component (const char * name);

  void remove_component (const char * name);

  CUTS_Component_Metric * component_metrics (const char * name);

private:
  typedef std::map <std::string, CUTS_Component_Metric *> Component_Metrics;

  Component_Metrics component_metrics_;

  ACE_RW_Thread_Mutex lock_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/System_Metric.inl"
#endif

#endif  // !defined _CUTS_SYSTEM_METRIC_H_
