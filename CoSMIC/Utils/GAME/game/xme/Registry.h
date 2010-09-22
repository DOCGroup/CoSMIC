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
#include "Object.h"

namespace GAME
{
namespace XME
{
// Forward decl.
class Object;

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
  Registry (Object parent);

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

  Object & owner (void);

  const Object & owner (void) const;

  Registry_Node child (const GAME::Xml::String & name, bool create);

private:
  /// The parent of the registry.
  Object parent_;

  static const GAME::Xml::String TAGNAME;
  static const GAME::Xml::String ATTR_TAGNAME;
  static const GAME::Xml::String ATTR_NAME;
};

}
}

#if defined (__GAME_INLINE__)
#include "Registry.inl"
#endif

#endif  // !defined _GAME_XME_REGISTRY_H_
