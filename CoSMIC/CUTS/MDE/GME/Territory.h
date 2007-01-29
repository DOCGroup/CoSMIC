// -*- C++ -*-

#ifndef _GME_TERRITORY_H_
#define _GME_TERRITORY_H_

#include <atlbase.h>
#include <string>
#include "Mga.h"
#include "GME_export.h"

namespace GME
{
  class GME_Export Territory
  {
  public:
    /// Default constructor.
    Territory (void);

    /**
     * Initializing constructor
     *
     * @param[in]     terr        Source territory.
     */
    Territory (IMgaTerritory * terr);

    /**
     * Copy constructor.
     *
     * @param[in]     terr        Source territory.
     */
    Territory (const Territory & terr);

    /// Destructor.
    ~Territory (void);

    /// Close the territory.
    void close (void);

    void attach (IMgaTerritory * terr);

    operator IMgaTerritory * (void) const;

  private:
    CComPtr <IMgaTerritory> terr_;
  };
}

#endif  // !defined _GME_TERRITORY_H_
