// -*- C++ -*-

//=============================================================================
/**
 * @file        MetaRole.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_PART_H_
#define _GAME_MGA_META_PART_H_

#include "MetaRole.h"
#include "MetaAspect.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class Part_Impl
 *
 * Wrapper class for the IMgaMetaPart interface.
 */
class GAME_MGA_Export Part_Impl : public Base_Impl
{
public:
  /// Type definition of the COM interface.
  typedef IMgaMetaPart interface_type;

  /// Default constructor.
  Part_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     role        Pointer to a COM interface.
   */
  Part_Impl (IMgaMetaPart * role);

  /// Destructor.
  virtual ~Part_Impl (void);

  /**
   * Get the meta FCO for the role.
   *
   * @return          The meta FCO of the role.
   */
  std::string kind_aspect (void) const;

  /**
   * Get a raw pointer to the underlying COM object.
   *
   * @return        Pointer to the raw COM object.
   */
  IMgaMetaPart * impl (void) const;

  bool is_linked (void) const;

  bool is_primary (void) const;

  /// Get the role for the part.
  Role role (void) const;

  /// Get the aspect for this part.
  Aspect in_aspect (void) const;

  /**
   * Get the count of parts.
   *
   * @return        Count of parts present.
   */
  long count (void) const;

private:
  /// Pointer to the COM object.
  mutable ATL::CComPtr <IMgaMetaPart> part_;
  CComPtr <IMgaMetaParts> parts_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaPart.inl"
#endif

#endif  // !defined _GAME_MGA_META_ROLE_H_
