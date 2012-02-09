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

#ifndef _GAME_MGA_META_ASPECT_H_
#define _GAME_MGA_META_ASPECT_H_

#include "MetaBase.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{
/**
 * @class Aspect_Impl
 *
 * Wrapper class for the IMgaMetaAspect interface.
 */
class GAME_MGA_Export Aspect_Impl : public Base_Impl
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

  /**
   * Get all the attributes of this aspect.
   *
   * @param[out]       attrs        The vector holds all the attributes.
   */
  size_t attributes (std::vector <Attribute> & attrs) const;

  /**
   * Get all the parts of this aspect.
   *
   * @param[out]       parts        The vector holds all the parts.
   */
  size_t parts (std::vector <Part> & parts) const;

private:
  /// Cached pointer to the implementation.
  mutable ATL::CComPtr <IMgaMetaAspect> aspect_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaAspect.inl"
#endif

#endif  // !defined _GME_METAFCO_H_
