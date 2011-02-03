// -*- C++ -*-

//=============================================================================
/**
 * @file          MetaAttribute.h
 *
 * Wrapper for the IMgaMetaAttribute object.
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_ATTRIBUTE_H_
#define _GAME_MGA_META_ATTRIBUTE_H_

#include "MetaBase.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{
/**
 * @class Attribute_Impl
 *
 * Wrapper class for the IMgaMetaAttribute inteface.
 */
class GAME_MGA_Export Attribute_Impl : public Base_Impl
{
public:
  /// Type definition of the interface type.
  typedef IMgaMetaAttribute interface_type;

  /// Default constructor.
  Attribute_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       meta        The COM interface.
   */
  Attribute_Impl (IMgaMetaAttribute * meta);

  /// Destructor.
  virtual ~Attribute_Impl (void);

  /**
   * Get the meta base object this attribute is defined in
   *
   * @return          Base meta object.
   */
  Base defined_in (void) const;

  /**
   * Get the visibility property of the attribute.
   *
   * @retval          true        Attribute_Impl is visible.
   * @retval          false       Attribute_Impl is not visible.
   */
  bool viewable (void) const;

  /**
   * Set the visibility property of the attribute.
   *
   * @param[in]       value       New visibility value.
   */
  void viewable (bool value);

  /**
   * Get the attribute's type.
   *
   * @return          The attribute's type.
   */
  attval_enum type (void) const;

  /**
   * Set the attribute's type.
   *
   * @param[in]       val       The attributes type.
   */
  void type (attval_enum val);

  /// Helper method to the correct implementation.
  IMgaMetaAttribute * impl (void) const;

private:
  /// Cached pointer to the implementation.
  mutable ATL::CComPtr <IMgaMetaAttribute> meta_attr_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaAttribute.inl"
#endif

#endif  // !defined _GAME_MGA_META_ATTRIBUTE_H_
