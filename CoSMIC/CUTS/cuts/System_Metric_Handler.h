// -*- C++ -*-

//=============================================================================
/**
 * @file      System_Metric_Handler.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_SYSTEM_METRIC_HANDLER_H_
#define _CUTS_SYSTEM_METRIC_HANDLER_H_

#include "cuts/System_Metric.h"

//=============================================================================
/**
 * @class CUTS_System_Metric_Handler
 *
 * Callback object for the system metrics. This allows objects to
 * receive notification anytime the CUTS_System_Metric object changes.
 */
//=============================================================================

class CUTS_Export CUTS_System_Metric_Handler
{
public:
  /// Destructor.
  virtual ~CUTS_System_Metric_Handler (void);

  /**
   * Event handle for the system metrics.
   *
   * @param[in]       metrics       The system metrics.
   * @retval          0             Successfully handled the metrics.
   * @retval          -1            Failed to handle the metrics.
   */
  virtual int handle_metrics (const CUTS_System_Metric & metrics);

protected:
  /// Destructor.
  CUTS_System_Metric_Handler (void);
};

#if defined (__CUTS_INLINE__)
#include "cuts/System_Metric_Handler.inl"
#endif

#endif  // !defined _CUTS_SYSTEM_METRIC_HANDLER_H_
