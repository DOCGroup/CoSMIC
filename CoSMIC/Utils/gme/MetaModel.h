#ifndef _GME_METAMODEL_H_
#define _GME_METAMODEL_H_

#include "MetaRole.h"

namespace GME
{
  class GME_Export MetaModel : public MetaFCO
  {
  public:
    typedef IMgaMetaModel _type;

    static MetaModel _narrow (MetaBase & meta);

    MetaModel (void);

    MetaModel (IMgaMetaModel * meta);

    MetaModel (const MetaModel & model);

    virtual ~MetaModel (void);

    MetaModel & operator = (const MetaModel & meta);

    operator IMgaMetaModel * (void) const;

    MetaRole role (const std::string & role) const;

    IMgaMetaModel * impl (void) const;

  private:
    mutable CComPtr <IMgaMetaModel> metamodel_;
  };
}

#if defined (__GME_INLINE__)
#include "MetaModel.inl"
#endif

#endif  // !defined _GME_METAMODEL_H_
