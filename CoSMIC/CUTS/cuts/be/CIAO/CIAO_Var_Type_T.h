// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Var_Type_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_VAR_TYPE_T_H_
#define _CUTS_CIAO_VAR_TYPE_T_H_

#include <iosfwd>
#include "cuts/config.h"
#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T
 *
 * Template class for generating variable types. This class really does
 * nothing. Its sole purpose is to generate a message for unsupported
 * types.
 */
//=============================================================================

template <typename T>
class CUTS_CIAO_Var_Type_T
{
public:
  /**
   * Write the variable to the output stream.
   *
   * @param[in]     out       Destination output stream.
   * @param[in]     element   Source element.
   */
  static void write (std::ostream & out, const T & element);
};

#if defined (__CUTS_INLINE__)
#include "CIAO_Var_Type_T.inl"
#endif

#include "CIAO_Var_Type_T.cpp"

#endif  // !defined _CUTS_CIAO_VAR_TYPE_T_H_
