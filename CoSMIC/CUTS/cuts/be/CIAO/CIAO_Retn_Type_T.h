// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_In_Type_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_RETN_TYPE_T_H_
#define _CUTS_CIAO_RETN_TYPE_T_H_

#include <iosfwd>
#include "cuts/config.h"
#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Retn_Type_T
 *
 * Template class for generating variable types. This class really does
 * nothing. Its sole purpose is to generate a message for unsupported
 * types.
 */
//=============================================================================

template <typename T>
class CUTS_CIAO_Retn_Type_T
{
public:
  /// Type definition for the element type.
  typedef T type;

  /**
   * Initializing constructor.
   *
   * @parma[in]       element       Source element.
   */
  explicit CUTS_CIAO_Retn_Type_T (const T & element);

  /**
   * Write the element to the output stream. Since this is the
   * default return type, it will generates a unsupported type
   * message. To generate the real return type, you MUST specialize
   * this class.
   *
   * @param[in]     out         Destination output stream.
   * @param[in]     element     The source element.
   */
  void write (std::ostream & out) const;
};

template <typename T>
inline CUTS_CIAO_Retn_Type_T <T>
CUTS_CIAO_Retn_Type (const T & element)
{
  return CUTS_CIAO_Retn_Type_T <T> (element);
}

template <typename T>
inline std::ostream &
operator << (std::ostream & out, const CUTS_CIAO_Retn_Type_T <T> & retn)
{
  retn.write (out);
  return out;
}

#if defined (__CUTS_INLINE__)
#include "CIAO_Retn_Type_T.inl"
#endif

#include "CIAO_Retn_Type_T.cpp"

#endif  // !defined _CUTS_CIAO_RETN_TYPE_T_H_