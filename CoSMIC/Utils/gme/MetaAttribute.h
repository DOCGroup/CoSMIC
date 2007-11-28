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

#ifndef _GME_METAATTRIBUTE_H_
#define _GME_METAATTRIBUTE_H_

#include "MetaBase.h"

namespace GME
{
namespace Meta
{
  //===========================================================================
  /**
   * @class Attribute
   *
   * Wrapper class for the IMgaMetaAttribute inteface.
   */
  //===========================================================================

  class GME_Export Attribute : public Base
  {
  public:
    /**
     * Extract the meta attribute from the base meta object.
     *
     * @param[in]       base        The base meta object.
     * @return          The extracted meta attribute.
     */
    static Attribute _narrow (const Base & base);

    /// Default constructor.
    Attribute (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       meta        The COM interface.
     */
    Attribute (IMgaMetaAttribute * meta);

    /**
     * Copy constructor.
     *
     * @param[in]       meta        The source meta attribute.
     */
    Attribute (const Attribute & meta);

    /// Destructor.
    virtual ~Attribute (void);

    /**
     * Attach to an existing interface pointer.
     *
     * @param[in]       attr        The source meta attribute.
     */
    void attach (IMgaAttribute * attr);

    /**
     * Assignment operator.
     *
     * @param[in]       attr        The source meta attribute.
     * @return          Reference to self.
     */
    const Attribute & operator = (const Attribute & attr);

    /**
     * Get the meta base object this attribute is defined in
     *
     * @return          Base meta object.
     */
    Base defined_in (void) const;

    /**
     * Get the visibility property of the attribute.
     *
     * @retval          true        Attribute is visible.
     * @retval          false       Attribute is not visible.
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
    attval_enum value_type (void) const;

    /**
     * Set the attribute's type.
     *
     * @param[in]       val       The attributes type.
     */
    void value_type (attval_enum val);

  private:
    /// Helper method to the correct implementation.
    IMgaMetaAttribute * impl (void) const;

  private:
    /// Cached pointer to the implementation.
    mutable CComPtr <IMgaMetaAttribute> meta_attr_;
  };
}
}

#if defined (__GME_INLINE__)
#include "MetaAttribute.inl"
#endif

#endif  // !defined _GME_METAATTRIBUTE_H_
