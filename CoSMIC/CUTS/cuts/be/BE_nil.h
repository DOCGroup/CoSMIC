// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_nil.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_NIL_H_
#define _CUTS_BE_NIL_H_

#include "BE_export.h"

namespace CUTS_BE
{
  //===========================================================================
  /**
   * @struct NIL
   *
   * NIL generator that does nothing. This allows us to stub out
   * unwanted generated code at compile-time to produce more optimal
   * and efficient
   */
  //===========================================================================

  struct CUTS_BE_Export NIL
  {
    /// Dummy execute method to satisfy the generator. We use variatric
    /// parameters so the method can be used with any number of parameters.
    static inline bool execute (...)
      { return false; }
  };

  //===========================================================================
  /**
   * @struct is_nil
   *
   * Template that determines if a generator is NIL. This template
   * is mainly used in generative programming techniques to determine
   * at compile-time if a generator is NIL.
   */
  //===========================================================================

  template <typename T>
  struct is_nil
  {
    /// By default, all generators are not nil.
    static const bool result_type = false;
  };

  //===========================================================================
  /**
   * @struct is_nil
   *
   * Template specialization for the NIL generator to always return
   * \a true.
   */
  //===========================================================================

  template < >
  struct CUTS_BE_Export is_nil <NIL>
  {
    static const bool result_type = true;
  };

  //===========================================================================
  /**
   * @struct is_nil
   *
   * Template that determines if a generator is NIL. This template
   * is mainly used in generative programming techniques to determine
   * at compile-time if a generator is NIL.
   */
  //===========================================================================

  template <typename T>
  struct not_is_nil
  {
    static const bool result_type = true;
  };

  //===========================================================================
  /**
   * @struct is_nil
   *
   * Template specialization for the NIL generator to always return
   * \a false.
   */
  //===========================================================================

  template < >
  struct CUTS_BE_Export not_is_nil <NIL>
  {
    static const bool result_type = false;
  };
}

#endif  // !defined _CUTS_BE_NIL_H_
