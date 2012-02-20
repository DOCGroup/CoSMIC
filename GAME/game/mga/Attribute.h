// -*- C++ -*-

//=============================================================================
/**
 * @file        Attribute_Impl.h
 *
 * Defines the Attribute_Impl class wrapper.
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_ATTRIBUTE_H_
#define _GAME_MGA_ATTRIBUTE_H_

#include "GME_fwd.h"
#include "Refcountable.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Attribute_Impl
 *
 * Wrapper class for the IMgaAttribute interface.
 */
class GAME_MGA_Export Attribute_Impl : public Refcountable
{
public:
  /// Type definition of the COM pointer type.
  typedef IMgaAttribute interface_type;

  /// Default constructor.
  Attribute_Impl (void);

  /**
   * Initializing constructor
   *
   * @param[in]     attr      Raw pointer to attribute
   */
  Attribute_Impl (IMgaAttribute * attr);

  /// Destructor.
  virtual ~Attribute_Impl (void);

  void attach (IMgaAttribute * attr);

  /// Get the contained instance pointer.
  IMgaAttribute * impl (void) const;

  /// Get the attribute's status.
  long status (void) const;

  /**
   * Get the owner of the attribute.
   *
   * @return        Owner of the attribute.
   */
  FCO owner (void) const;

  /**
   * Determine if the attribute has changed.
   *
   * @retval        true        Attribute_Impl has changed.
   * @retval        false       Attribute_Impl has not changed.
   */
  bool has_changed (void) const;

  /// Clear the attribute.
  void clear (void);

  /**
   * Get the string value of the attribute.
   *
   * @return        The string value of the attribute.
   */
  std::string string_value (void) const;

  /**
   * Set the string value of the attribute.
   *
   * @param[in]     val       The new string value.
   */
  void string_value (const std::string & val);

  /**
   * Get the integer value of the attribute.
   *
   * @return        The integer value of the attribute.
   */
  long int_value (void) const;

  /**
   * Set the integer value of the attribute.
   *
   * @param[in]     val       The new integer value.
   */
  void int_value (long val);

  /**
   * Get the boolean value of the attribute.
   *
   * @return        The boolean value of the attribute.
   */
  bool bool_value (void) const;

  /**
   * Set the boolean attribute of the attribute.
   *
   * @param[in]     val     The new boolean value.
   */
  void bool_value (bool val);

  /**
   * Get the float value of the attribute.
   *
   * @return        The float value of the attribute.
   */
  double double_value (void) const;

  /**
   * Set the float value of the attribute.
   *
   * @param[in]     val     The float value of the attribute.
   */
  void double_value (double val);

  /**
   * Retrieve the attributes meta information
   *
   * @return        Meta information
   */
  Meta::Attribute meta (void) const;

private:
  /// The underlying COM pointer to the attribute.
  mutable ATL::CComPtr <IMgaAttribute> attr_;

  // prevent the following operations
  Attribute_Impl (const Attribute_Impl & attr);
  const Attribute_Impl & operator = (const Attribute_Impl & attr);
};

}
}

#if defined (__GAME_INLINE__)
#include "Attribute.inl"
#endif

#endif  // !defined _GME_ATTRIBUTE_H_
