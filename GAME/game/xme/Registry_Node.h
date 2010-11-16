// -*- C++ -*-

//=============================================================================
/**
 * @file      Registry_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_REGISTRY_NODE_H_
#define _GAME_XME_REGISTRY_NODE_H_

#include "xercesc/dom/DOM.hpp"
#include "game/xml/String.h"
#include "XME_export.h"

namespace GAME
{
namespace XME
{
// Forward decl.
class Registry;

/**
 * @class Registry_Node
 *
 * The node abstraction for the registry tree.
 */
class GAME_XME_Export Registry_Node
{
public:
  // Friend decl.
  friend class Registry;

  /**
   * Create a new folder
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Registry_Node _create (Registry & parent, const GAME::Xml::String & name);

  /**
   * Create a new folder
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Registry_Node _create (Registry_Node & parent, const GAME::Xml::String & name);

  /// Default constructor.
  Registry_Node (void);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Registry_Node (const Registry_Node & node);

  /// Destructor.
  ~Registry_Node (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Registry_Node & operator = (const Registry_Node & node);

  /**
   * Get the name of the registry node.
   *
   * @return        Pointer to string with name of node.
   */
  const XMLCh * name (void) const;

  void value (const GAME::Xml::String & v) const;

  const XMLCh * value (void) const;

  Registry_Node child (const GAME::Xml::String & name, bool create = false);

private:
  static const GAME::Xml::String TAGNAME;
  static const GAME::Xml::String TAGNAME_VALUE;
  static const GAME::Xml::String ATTR_NAME;

  static xercesc::DOMElement * _create (xercesc::DOMElement * parent, const GAME::Xml::String & name);

  Registry_Node (xercesc::DOMElement * node, bool existing);

  // Helper method to add the value tag.
  void new_value (void);

  // Helper method to get the existing value tag.
  void get_value (void) const;

  /// Pointer to the actual node.
  xercesc::DOMElement * node_;

  /// The value of the registry node.
  mutable xercesc::DOMElement * value_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Registry_Node.inl"
#endif

#endif  // !defined _GAME_XME_REGISTRY_NODE_H_
