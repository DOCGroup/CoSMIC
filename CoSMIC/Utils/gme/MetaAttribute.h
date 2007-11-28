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
  class GME_Export MetaAttribute : public MetaBase
  {
  public:
    MetaAttribute (void);

    MetaAttribute (IMgaMetaAttribute * meta);

    MetaAttribute (const MetaAttribute & meta);

    virtual ~MetaAttribute (void);

    void attach (IMgaAttribute * attr);

    const MetaAttribute & operator = (const MetaAttribute & attr);

    MetaBase defined_in (void) const;

    bool viewable (void) const;
    void viewable (bool value);

    attval_enum value_type (void) const;
    void value_type (attval_enum val);


  private:
    /// Helper method to the correct implementation.
    IMgaMetaAttribute * impl (void) const;

  private:
    /// Cached pointer to the implementation.
    mutable CComPtr <IMgaMetaAttribute> meta_attr_;
  };
}

#if defined (__GME_INLINE__)
#include "MetaAttribute.inl"
#endif

#endif  // !defined _GME_METAATTRIBUTE_H_
