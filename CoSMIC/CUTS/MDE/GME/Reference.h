#ifndef _GME_REFERENCE_H_
#define _GME_REFERENCE_H_

#include "FCO.h"

namespace GME
{
  class GME_Export Reference : public FCO
  {
  public:
    typedef IMgaReference _type;

    Reference (void);
    Reference (IMgaReference * ref);
    Reference (const Reference & ref);
    virtual ~Reference (void);

    const Reference & operator = (const Reference & ref);
    void attach (IMgaReference * ref);

    FCO refers_to (void) const;
    void refers_to (const FCO & fco);

    operator IMgaReference * (void) const;

  private:
    IMgaReference * impl (void) const;

    mutable CComPtr <IMgaReference> ref_;
  };
}

#endif  // !defined _GME_REFERENCE_H_
