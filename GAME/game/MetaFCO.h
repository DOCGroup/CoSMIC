// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaFCO.h
 *
 * Defines the GAME::Meta::FCO_Impl object.
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_METAFCO_H_
#define _GME_METAFCO_H_

#include "MetaAttribute.h"

namespace GAME
{
namespace Meta
{
/**
 * @class FCO_Impl
 *
 * Wrapper class for the IMgaMetaFCO interface.
 */
class GAME_Export FCO_Impl : public Base_Impl
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

#if defined (__GAME_INLINE__)
#include "MetaFCO.inl"
#endif

#endif  // !defined _GME_METAFCO_H_
