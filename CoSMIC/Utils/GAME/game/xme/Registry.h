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

#include "Registry_Node.h"

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

  Registry_Node child (const ::Utils::XStr & name, bool create);

private:
  /// The parent of the registry.
  FCO & parent_;

  static const ::Utils::XStr TAGNAME;
  static const ::Utils::XStr ATTR_TAGNAME;
  static const ::Utils::XStr ATTR_NAME;
};

}
}

#if defined (__GME_INLINE__)
#include "Registry.inl"
#endif

#endif  // !defined _GAME_XME_REGISTRY_H_
