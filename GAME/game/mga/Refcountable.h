// -*- C++ -*-

//=============================================================================
/**
 * @file      Refcountable.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_REFCOUNTABLE_H_
#define _GAME_MGA_REFCOUNTABLE_H_

#include "game/config.h"
#include "Mga_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Refcountable
 *
 * Base class for adding reference count support to an object. This
 * will allow any derived class to supply the interface expected by
 * the Smart_Ptr class.
 */
class GAME_MGA_Export Refcountable
{
protected:
  /// Default constructor.
  Refcountable (void);

  /// Destructor.
  virtual ~Refcountable (void);

public:
  /// Increment the reference counter.
  long increment (void);

  /// Decrement the reference counter.
  long decrement (void);

  /// Returns the current refcount.
  long refcount (void) const;

private:
  /// The object's reference count.
  long refcount_;

  // prevent the following operations
  Refcountable (const Refcountable &);
  const Refcountable & operator = (const Refcountable &);
};

}
}

#if defined (__GAME_INLINE__)
#include "Refcountable.inl"
#endif

#endif  // !defined _GME_REFERENCE_H_
