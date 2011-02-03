// -*- C++ -*-

//=============================================================================
/**
 * @file      Territory
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_TERRITORY_H_
#define _GAME_MGA_TERRITORY_H_

#include "Exception.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Territory
 *
 * Wrapper class for the IMgaTerritory interface.
 */
class GAME_MGA_Export Territory
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

  /**
   * Close the territory. After this method call, the territory
   * is no longer valid.
   */
  void close (void);

  /**
   * Attach to an existing territory.
   *
   * @param[in]       terr      Source territory.
   */
  void attach (IMgaTerritory * terr);

  /**
   * Convert the territory to an interface pointer.
   *
   * @return          Interface pointer to the territory.
   */
  operator IMgaTerritory * (void) const;

private:
  /// The COM pointer to the underlying territory.
  ATL::CComPtr <IMgaTerritory> terr_;
};

}
}

#endif  // !defined _GME_TERRITORY_H_
