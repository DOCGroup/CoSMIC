// -*- C++ -*-

#ifndef _GME_FCO_H_
#define _GME_FCO_H_

#include "Object.h"

namespace GME
{
  class GME_Export FCO : public Object
  {
  public:
    typedef IMgaFCO _type;

    FCO (void);
    FCO (IMgaFCO * fco);
    const FCO (const FCO & fco);
    virtual ~FCO (void);

    bool is_instance (void) const;
    bool is_primary_derived (void) const;

    const FCO & operator = (const FCO & fco);
    void attach (IMgaFCO * fco);

    operator IMgaFCO * (void) const;

  protected:
    IMgaFCO * impl (void) const;
    mutable CComPtr <IMgaFCO> fco_;
  };
}

#endif  // !define _GME_FCO_H_
