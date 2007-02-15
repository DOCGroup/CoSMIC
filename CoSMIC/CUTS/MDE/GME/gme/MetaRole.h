// -*- C++ -*-

#ifndef _GME_METAROLE_H_
#define _GME_METAROLE_H_

#include "MetaFCO.h"

namespace GME
{
  class GME_Export MetaRole : public MetaBase
  {
  public:
    typedef IMgaMetaRole _type;

    MetaRole (void);

    MetaRole (IMgaMetaRole * role);

    MetaRole (const MetaRole & role);

    virtual ~MetaRole (void);

    const MetaRole & operator = (const MetaRole & role);

    MetaFCO kind (void) const;

    operator IMgaMetaRole * (void) const;

    IMgaMetaRole * impl (void) const;

  private:
    mutable CComPtr <IMgaMetaRole> metarole_;
  };
}

#if defined (__GME_INLINE__)
#include "MetaRole.inl"
#endif

#endif  // !defined _GME_METAROLE_H_
