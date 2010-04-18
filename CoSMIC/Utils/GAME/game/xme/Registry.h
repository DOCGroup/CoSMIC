// -*- C++ -*-

//=============================================================================
/**
 * @file      Registry.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_REGISTRY_H_
#define _GAME_XME_REGISTRY_H_

#include "xercesc/dom/DOM.hpp"
#include "Utils/xercesc/XercesString.h"
#include "XME_export.h"

namespace GME
{
namespace XME
{
// Forward decl.
class FCO;

/**
 * @class Registry
 *
 * The node abstraction for the registry tree.
 */
class GAME_XME_Export Registry
{
public:
  /**
   * Initailizing constructor.
   *
   * @param[in]       parent        Parent object of the registry
   */
  Registry (FCO & parent);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Registry (const Registry & node);

  /// Destructor.
  ~Registry (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Registry & operator = (const Registry & node);

  FCO & owner (void);

  const FCO & owner (void) const;

private:
  /// The parent of the registry.
  FCO & parent_;
};

}
}

#if defined (__GME_INLINE__)
#include "Registry.inl"
#endif

#endif  // !defined _GAME_XME_REGISTRY_H_
