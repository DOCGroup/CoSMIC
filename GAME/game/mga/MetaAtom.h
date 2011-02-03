// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaAtom.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_ATOM_H_
#define _GAME_MGA_META_ATOM_H_

#include "MetaFCO.h"

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
class GAME_MGA_Export Atom_Impl : public FCO_Impl
{
public:
  /// Type definition of the interface pointer.
  typedef IMgaMetaAtom interface_type;

  /// Default constructor.
  Atom_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        Pointer to the meta information.
   */
  Atom_Impl (IMgaMetaAtom * aspect);

  /// Destructor.
  virtual ~Atom_Impl (void);

  /// Helper method to the correct implementation.
  IMgaMetaAtom * impl (void) const;

private:
  /// Cached pointer to the implementation.
  mutable ATL::CComPtr <IMgaMetaAtom> atom_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaAtom.inl"
#endif

#endif  // !defined _GME_METAFCO_H_
