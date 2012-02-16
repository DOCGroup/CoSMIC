// -*- C++ -*-

//=============================================================================
/**
 *  @file         Fragment.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _GAME_XML_SWAP_FRAGMENT_H_
#define _GAME_XML_SWAP_FRAGMENT_H_

#include "Fragment.h"

namespace GAME
{
namespace Xml
{

/**
 * @class Swap_Fragment
 */
class GAME_XML_Export Swap_Fragment : public Fragment
{
public:
  /**
   * Initializing constructor.
   */
  Swap_Fragment (Fragment & current, const Fragment & f);

  /// Destructor.
  virtual ~Swap_Fragment (void);

private:
  /// Reference to the current fragment.
  Fragment & current_;

  /// The original fragment.
  Fragment orig_;
};

}
}

#endif  // !defined _GAME_XML_SWAP_FRAGMENT_H_
