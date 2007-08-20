// -*- C++ -*-

//=============================================================================
/**
 * @file      DB_Record.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_DB_RECORD_H_
#define _CUTS_DB_RECORD_H_

#include "DB_Exception.h"

// Forward decl.
class ACE_Date_Time;

//=============================================================================
/**
 * @class CUTS_DB_Record
 *
 * Base class implementation/interface for database records.
 */
//=============================================================================

class CUTS_DB_UTILS_Export CUTS_DB_Record
{
public:
  /// Default constructor.
  CUTS_DB_Record (void);

  /// Destructor.
  virtual ~CUTS_DB_Record (void);

  /**
   * Get the number of records in the result.
   *
   * @return Number of records.
   */
  virtual size_t count (void) = 0;

  /// Fetch the next row in the records.
  virtual void fetch (void)
    throw (CUTS_DB_Exception) = 0;

  /**
   * Get a string data value at the specified column.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    buffer        Pointer to the output buffer.
   * @param[in]     bufsize       Size of the output buffer.
   */
  virtual void get_data (size_t column, char * buffer, size_t bufsize) = 0;

  /**
   * Get a character value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Character value.
   */
  virtual void get_data (size_t column, char & value) = 0;

  /**
   * Get a character value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Character value.
   */
  virtual void get_data (size_t column, unsigned char & value) = 0;

  /**
   * Get a character value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Character value.
   */
  virtual void get_data (size_t column, short & value) = 0;

  /**
   * Get a character value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Character value.
   */
  virtual void get_data (size_t column, unsigned short & value) = 0;

  /**
   * Get a character value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Character value.
   */
  virtual void get_data (size_t column, long & value) = 0;

  /**
   * Get a character value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Character value.
   */
  virtual void get_data (size_t column, unsigned long & value) = 0;

  /**
   * Get a float value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Float value.
   */
  virtual void get_data (size_t column, float & value) = 0;

  /**
   * Get a double value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Double value.
   */
  virtual void get_data (size_t column, double & value) = 0;

  /**
   * Get a date time value.
   *
   * @param[in]     column        1-based column index.
   * @param[out]    value         Character value.
   */
  virtual void get_data (size_t column, ACE_Date_Time & value) = 0;

  /**
   * Get the number of columns in the result.
   *
   * @return Number of columns.
   */
  virtual size_t columns (void) = 0;

private:
  /// prevent the following operations
  CUTS_DB_Record (const CUTS_DB_Record &);
  const CUTS_DB_Record & operator = (const CUTS_DB_Record &);
};

#if defined (__CUTS_INLINE__)
#include "DB_Record.inl"
#endif

#endif  // !defined _CUTS_DB_RECORD_H_
