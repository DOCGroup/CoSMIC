// -*- C++ -*-

//=============================================================================
/**
 * @file        Attribute.h
 *
 * Defines the Attribute class wrapper.
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_ATTRIBUTE_H_
#define _GME_ATTRIBUTE_H_

#include "FCO.h"

namespace GME
{
  /**
   * @class Attribute
   *
   * Wrapper class for the IMgaAttribute interface.
   */
  class GME_Export Attribute
  {
  public:
    /// Type definition of the COM pointer type.
    typedef IMgaAttribute interface_type;

    Attribute (void);

    Attribute (IMgaAttribute * attr);

    Attribute (const Attribute & attr);

    virtual ~Attribute (void);

    void attach (IMgaAttribute * attr);

    const Attribute & operator = (const Attribute & attr);

    IMgaAttribute * impl (void);

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
     * @retval        true        Attribute has changed.
     * @retval        false       Attribute has not changed.
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
    double float_value (void) const;

    /**
     * Set the float value of the attribute.
     *
     * @param[in]     val     The float value of the attribute.
     */
    void float_value (double val);

    Meta::Attribute meta (void) const;

  private:
    /// The underlying COM pointer to the attribute.
    mutable ATL::CComPtr <IMgaAttribute> attr_;
  };
};

#if defined (__GME_INLINE__)
#include "Attribute.inl"
#endif

#endif  // !defined _GME_ATTRIBUTE_H_
