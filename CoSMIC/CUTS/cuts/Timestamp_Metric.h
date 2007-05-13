// -*- C++ -*-

//=============================================================================
/**
 * @file      Timestamp_Metric.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TIMESTAMP_METRIC_H_
#define _CUTS_TIMESTAMP_METRIC_H_

#include "cuts/CUTS_export.h"
#include "ace/Time_Value.h"

//=============================================================================
/**
 * @class CUTS_Timestamp_Metric
 *
 * Helper class for adding a timestamp metric attribute to a metric
 * class. This is mainly for letting clients know which metrics are
 * up-to-date and what metrics our out-of-date.
 */
//=============================================================================

class CUTS_Timestamp_Metric
{
public:
  /// Default consturctor.
  CUTS_Timestamp_Metric (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     tv        The initial value of the timestamp.
   */
  CUTS_Timestamp_Metric (const ACE_Time_Value & tv);

  /// Destructor.
  ~CUTS_Timestamp_Metric (void);

  /**
   * Get the timestamp value.
   *
   * @return      The timestamp value.
   */
  ACE_Time_Value & timestamp (void);

  /// @overload
  const ACE_Time_Value & timestamp (void) const;

  /**
   * Set the value of the timestamp.
   *
   * @param[in]   timestamp       The timestamp's new value.
   */
  void timestamp (const ACE_Time_Value & tv);

private:
  /// The actual timestamp.
  ACE_Time_Value timestamp_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Timestamp_Metric.inl"
#endif

#endif  // !defined _CUTS_TIMESTAMP_METRIC_H_