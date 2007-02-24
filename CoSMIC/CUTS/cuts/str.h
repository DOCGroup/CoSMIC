// -*- C++ -*-

//=============================================================================
/**
 * @file      str.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_STR_H_
#define _CUTS_STR_H_

#include "cuts/CUTS_export.h"
#include "ace/SString.h"

//=============================================================================
/**
 * @class CUTS_str
 *
 * Class for cacheing strings for later usage. This is mainly used
 * by CUTS_Pending_Op_T when storing string values for later usage.
 */
//=============================================================================

class CUTS_Export CUTS_str
{
public:
  /// Type definition of the real type.
  typedef char * type;

  /// Default constructor.
  CUTS_str (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     str     Source string.
   */
  CUTS_str (const char * str);

  /**
   * Copy constructor.
   *
   * @param[in]     str     Source string.
   */
  CUTS_str (const CUTS_str & str);

  /// Destructor.
  ~CUTS_str (void);

  /**
   * Assignment operator.
   *
   * @param[in]     str     Source string
   * @return        Reference to this object.
   */
  const CUTS_str & operator = (const CUTS_str & str);

  /**
   * Conversion operator.
   *
   * @return        Pointer to the string.
   */
  operator const char * (void) const;

private:
  /// The containing string.
  ACE_CString str_;
};

#if defined (__CUTS_INLINE__)
#include "str.inl"
#endif

#endif  // !defined _CUTS_STR_H_
