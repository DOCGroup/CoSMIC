// -*- C++ -*-

//=============================================================================
/**
 * @file      Activation_Record_Log.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ACTIVATION_RECORD_LOG_H_
#define _CUTS_ACTIVATION_RECORD_LOG_H_

#include "cuts/Activation_Record.h"
#include "ace/Containers_T.h"

//=============================================================================
/**
 * @class CUTS_Activation_Record_Log
 *
 * Collection of Activation_Records for fast logging.
 */
//=============================================================================

class CUTS_Export CUTS_Activation_Record_Log :
  public ACE_Array_Base <CUTS_Activation_Record>
{
public:
  /// Constructor
  CUTS_Activation_Record_Log (size_t size = 0);

  /// Destructor
  ~CUTS_Activation_Record_Log (void);

  /**
   * Get the number of free records in the log. Free records are
   * considered those that have not been used for logging metrics.
   *
   * @return        The number of free records.
   */
  size_t free_size (void) const;

  /**
   * Get the number of used records in the log. Used records are
   * considered those that have been used for logging metrics.
   *
   * @return        The number of used records.
   */
  size_t used_size (void) const;

  /// Reset the log by converting all used records to free records.
  void reset (void);

  CUTS_Activation_Record * next_free_record (void);

private:
  /// Number of used records in the log.
  size_t used_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Activation_Record_Log.inl"
#endif

#endif  // !defined _CUTS_ACTIVATION_RECORD_LOG_H_
