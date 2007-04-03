// -*- C++ -*-

//=============================================================================
/**
 * @file      Time_Value_History.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TIME_VALUE_HISTORY_H_
#define _CUTS_TIME_VALUE_HISTORY_H_

#include "ace/Containers_T.h"
#include "ace/Time_Value.h"

//=============================================================================
/**
 * @class CUTS_Time_Value
 *
 * The timing structure for collected extended metrics related
 * to the occurrence of events.
 */
//=============================================================================

struct CUTS_Export CUTS_Time_Value_Ex
{
  CUTS_Time_Value_Ex (void)
  {

  }

  /**
   * Copy constructor.
   *
   * @param[in]     tv        The source time value.
   */
  CUTS_Time_Value_Ex (const CUTS_Time_Value_Ex & tv)
    : start_ (tv.start_),
      stop_ (tv.stop_)
  {

  }

  const CUTS_Time_Value_Ex & operator = (const CUTS_Time_Value_Ex & tv)
  {
    this->start_ = tv.start_;
    this->stop_ = tv.stop_;
    return *this;
  }

  /// Starting time of the measurement.
  ACE_Time_Value start_;

  /// Stopping time of the measurement.
  ACE_Time_Value stop_;
};

/// Type definition for the history of time values.
typedef ACE_Array <ACE_Time_Value> CUTS_Time_Value_History;

/// Type definition for the extended time value history.
typedef ACE_Array <CUTS_Time_Value_Ex> CUTS_Time_Value_Ex_History;

#endif  // !defined _CUTS_TIME_VALUE_HISTORY_H_
