// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaFCO.h
 *
 * Defines the Meta::FCO_Impl object.
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_FCO_H_
#define _GAME_MGA_META_FCO_H_

#include "MetaAttribute.h"
#include "MetaRole.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class FCO_Impl
 *
 * Wrapper class for the IMgaMetaFCO interface.
 */
class GAME_MGA_Export FCO_Impl : public Base_Impl
{
public:
  /// Type definition of the interface pointer.
  typedef IMgaMetaFCO interface_type;

  /// Default constructor.
  FCO_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     meta        Pointer to the meta information.
   */
  FCO_Impl (IMgaMetaFCO * meta);

  /// Destructor.
  virtual ~FCO_Impl (void);

  /**
   * Get the meta object this FCO_Impl is defined in.
   *
   * @return        Base meta object.
   */
  Base defined_in (void) const;

  /**
   * Get all the roles where this FCO_Impl is defined in.
   *
   * @param[out]       roles      All the metaroles this FCO has been used in.
   */
  size_t used_in_roles (std::vector <Role> & roles) const;


  /**
   * Get an attributes meta information by its name.
   *
   * @param[in]       name        Name of the attribute.
   * @return          Meta information about the attribute.
   */
  Attribute attribute (const std::string & name,
                       bool display_name = false) const;

  /// Helper method to the correct implementation.
  IMgaMetaFCO * impl (void) const;

private:
  /// Cached pointer to the implementation.
  mutable CComPtr <IMgaMetaFCO> meta_fco_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaFCO.inl"
#endif

#endif  // !defined _GAME_MGA_META_FCO_H_
