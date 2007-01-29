// -*- C++ -*-

#ifndef _GME_METABASE_H_
#define _GME_METABASE_H_

#include <atlbase.h>
#include <string>
#include "Mga.h"
#include "Exception.h"

namespace GME
{
  class GME_Export MetaBase
  {
  public:
    typedef IMgaMetaBase _type;

    MetaBase (void);
    MetaBase (IMgaMetaBase * meta);
    MetaBase (const MetaBase & meta);
    virtual ~MetaBase (void);

    std::string name (void) const;
    std::string displayed_name (void) const;

    void attach (IMgaMetaBase * metabase);
    const MetaBase & operator = (const MetaBase & metabase);

  protected:
    CComPtr <IMgaMetaBase> metabase_;
  };
}

#endif  // !defined _GME_METABASE_H_
