// -*- C++ -*-

//=============================================================================
/**
 * @file       Log_T.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_LOG_T_H_
#define _CUTS_LOG_T_H_

#include "cuts/config.h"
#include "ace/Containers_T.h"

//=============================================================================
/**
 * @class CUTS_Log_T
 *
 * Efficient log class for storing entries. The log is built on top
 * of an array and is optimized for fast access to its entries. It
 * also grows automatically once all entries in the record are used.
 * The log is also thread-safe, depending on the type of LOCK used
 * to parameterize this class.
 */
//=============================================================================

template <typename T, typename LOCK>
class CUTS_Log_T : public ACE_Array_Base <T>
{
public:
  /// Type definition of the iterator.
  typedef typename ACE_Array_Base <T>::iterator iterator;

  /// Type definition of the const iterator.
  typedef typename ACE_Array_Base <T>::const_iterator const_iterator;

  /**
   * Initializing constructor.
   *
   * @param[in]         size        Initial size of the log.
   * @param[in]         grow        Allow the log to grow as needed.
   */
  CUTS_Log_T (size_t size = 0, bool auto_grow = false);

  CUTS_Log_T (const CUTS_Log_T & log);

  /// Destructor
  ~CUTS_Log_T (void);

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

  T * next_free_record (void);

  T * next_free_record_i (void);

  LOCK & lock (void);

  const CUTS_Log_T & operator = (const CUTS_Log_T & log);

private:
  void copy_log (const CUTS_Log_T & log);
  void copy_log_i (const CUTS_Log_T & log);

  /// Number of used records in the log.
  size_t used_;

  /// Flag that determines if the log can grow when needed.
  bool auto_grow_;

  /// Lock for the log.
  LOCK lock_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Log_T.inl"
#endif

#include "cuts/Log_T.cpp"

#endif  // !defined _CUTS_LOG_T_H_
