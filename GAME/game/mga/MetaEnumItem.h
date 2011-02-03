// -*- C++ -*-

//=============================================================================
/**
 * @file        MetaEnum.h
 *
 * Defines the MetaEnum class
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_ENUMITEM_H_
#define _GAME_MGA_META_ENUMITEM_H_

#include <string>
#include "GME_fwd.h"

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class EnumItem
 *
 * Wrapper class for the IMgaMetaEnumItem interface. It abstracts
 * away the complexities of interacting with COM when using standard
 * C++ implementation techniques.
 */
class GAME_MGA_Export EnumItem
{
public:
  /// Type definition of the COM type.
  typedef IMgaMetaEnumItem interface_type;

  /// Default constructor.
  EnumItem (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       item        Pointer to the COM interface.
   */
  EnumItem (IMgaMetaEnumItem * item);

  /**
   * Copy constructor.
   *
   * @param[in]       item        The source item.
   */
  EnumItem (const EnumItem & item);

  /// Destructor.
  virtual ~EnumItem (void);

  /**
   * Get a pointer to the raw COM iterface. This is useful if
   * the current object does not implement all of the underlying
   * COM interface.
   *
   * @return    Pointer to the raw COM interface.
   */
  IMgaMetaEnumItem * impl (void) const;

  /**
   * Assignment operator.
   *
   * @param[in]     item        Source enum item.
   * @return        Reference to self.
   */
  const EnumItem & operator = (const EnumItem & item);

  /**
   * Get the current value of the enum item.
   *
   * @return        Current value of enum item.
   */
  std::string value (void) const;

  /**
   * Set the value of the enum item.
   *
   * @param[in]     val         New value.
   */
  void value (const std::string & val);

  /**
   * Get the display name of the enum item.
   *
   * @return        The display name.
   */
  std::string display_name (void) const;

  /**
   * Set the display name of the enum item.
   *
   * @param[in]     name        The new name.
   */
  void display_name (const std::string & name);

  /**
   * Get the parent attribute of the enum item.
   *
   * @return        The parent attribute.
   */
  Attribute parent (void) const;

private:
  /// Pointer to the actual COM object.
  mutable CComPtr <IMgaMetaEnumItem> enum_item_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaEnumItem.inl"
#endif

#endif  // !defined _GAME_MGA_META_ENUMITEM_H_
