// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaAspect.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_META_ASPECT_H_
#define _GAME_META_ASPECT_H_

#include "MetaBase.h"

namespace GAME
{
namespace Meta
{
/**
 * @class Aspect
 *
 * Wrapper class for the IMgaMetaAspect interface.
 */
class GAME_Export Aspect : public Base
{
public:
  /// Type definition of the interface pointer.
  typedef IMgaMetaAspect interface_type;

  /// Default constructor.
  Aspect (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        Pointer to the meta information.
   */
  Aspect (IMgaMetaAspect * aspect);

  /**
   * Copy constructor.
   *
   * @param[in]     meta        The source object.
   */
  Aspect (const Aspect & aspect);

  /// Destructor.
  virtual ~Aspect (void);

  /**
   * Assignment operator.
   *
   * @param[in]     meta        The source object.
   * @return        Reference to this object.
   */
  const Aspect & operator = (const Aspect & aspect);

  /// Helper method to the correct implementation.
  IMgaMetaAspect * impl (void) const;

private:
  /// Cached pointer to the implementation.
  mutable CComPtr <IMgaMetaAspect> aspect_;
};

}
}

#if defined (__GAME_INLINE__)
#include "MetaAspect.inl"
#endif

#endif  // !defined _GME_METAFCO_H_
