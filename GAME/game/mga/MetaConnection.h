// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaConnection.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_CONNECTION_H_
#define _GAME_MGA_META_CONNECTION_H_

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
class GAME_MGA_Export Connection_Impl : public FCO_Impl
{
public:
  /// Type definition of the interface pointer.
  typedef IMgaMetaConnection interface_type;

  /// Default constructor.
  Connection_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        Pointer to the meta information.
   */
  Connection_Impl (IMgaMetaConnection * aspect);

  /// Destructor.
  virtual ~Connection_Impl (void);

  /// Helper method to the correct implementation.
  IMgaMetaConnection * impl (void) const;

private:
  /// Cached pointer to the implementation.
  mutable ATL::CComPtr <IMgaMetaConnection> conn_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaConnection.inl"
#endif

#endif  // !defined _GAME_MGA_META_CONNECTION_H_
