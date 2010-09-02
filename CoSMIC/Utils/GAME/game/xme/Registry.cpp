// $Id$

#include "Registry.h"

#if !defined (__GAME_INLINE__)
#include "Registry.inl"
#endif

#include "Registry_Node.h"

namespace GAME
{
namespace XME
{
const GAME::Xml::String Registry::TAGNAME ("regnode");
const GAME::Xml::String Registry::ATTR_TAGNAME ("attribute");
const GAME::Xml::String Registry::ATTR_NAME ("name");

//
// child
//
Registry_Node Registry::child (const GAME::Xml::String & name, bool create)
{
  using xercesc::DOMElement;
  using xercesc::DOMNode;
  using xercesc::DOMNodeList;

  // Get the list of child nodes for this node.
  DOMNodeList * list = this->parent_.ptr ()->getChildNodes ();
  size_t length = list->getLength ();

  DOMElement * e = 0;
  DOMNode * node = 0;

  for (size_t i = 0; i < length; ++ i)
  {
    // Get the next node in the list.
    node = list->item (i);

    if (node->getNodeType () == DOMNode::ELEMENT_NODE &&
        node->getNodeName () == TAGNAME)
    {
      // Check if this attibute is the correct one.
      e = dynamic_cast <DOMElement *> (node);

      if (e->getAttribute (ATTR_NAME) == name)
        return Registry_Node (e, true);
    }
    else if (node->getNodeName () == ATTR_TAGNAME)
      break;
  }

  // Should we create the node instead since we were not able to
  // find it in the list.
  if (create)
    return Registry_Node::_create (*this, name);

  // Throw an exception as last resort.
  throw Not_Found ();
}

}
}
