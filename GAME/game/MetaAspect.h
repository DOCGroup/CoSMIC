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
 * @class Aspect_Impl
 *
 * Wrapper class for the IMgaMetaAspect interface.
 */
class GAME_Export Aspect_Impl : public Base_Impl
{
public:
  /// Type definition of the interface pointer.
  typedef IMgaMetaAspect interface_type;

  /// Default constructor.
  Aspect_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        Pointer to the meta information.
   */
  Aspect_Impl (IMgaMetaAspect * aspect);

  /// Destructor.
  virtual ~Aspect_Impl (void);

  /// Helper method to the correct implementation.
  IMgaMetaAspect * impl (void) const;

private:
  /// Cached pointer to the implementation.
  mutable ATL::CComPtr <IMgaMetaAspect> aspect_;
};

}
}

#if defined (__GAME_INLINE__)
#include "MetaAspect.inl"
#endif

#endif  // !defined _GME_METAFCO_H_
