#ifndef _GME_ATOM_H_
#define _GME_ATOM_H_

#include "FCO.h"

namespace GME
{
  class GME_Export Atom : public FCO
  {
  public:
    typedef IMgaAtom _type;

    Atom (void);
    Atom (IMgaAtom * atom);
    Atom (const Atom & atom);
    virtual ~Atom (void);

    const Atom & operator = (const Atom & atom);
    void attach (IMgaAtom * atom);

  protected:
    IMgaAtom * impl (void) const;

    mutable CComPtr <IMgaAtom> atom_;
  };
}

#endif
