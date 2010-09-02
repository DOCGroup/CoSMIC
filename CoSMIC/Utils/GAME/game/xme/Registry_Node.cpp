// $Id$

#include "Registry_Node.h"

#if !defined (__GAME_INLINE__)
#include "Registry_Node.inl"
#endif

#include "FCO.h"
#include "Registry.h"

namespace GAME
{
namespace XME
{
const GAME::Xml::String Registry_Node::TAGNAME ("regnode");
const GAME::Xml::String Registry_Node::TAGNAME_VALUE ("value");
const GAME::Xml::String Registry_Node::ATTR_NAME ("name");

//
// _create
//
Registry_Node Registry_Node::
_create (Registry & parent, const GAME::Xml::String & name)
{
  using xercesc::DOMElement;

  // First, we need to create the node.
  DOMElement * ptr = parent.owner ().ptr ();
  DOMElement * regnode = Registry_Node::_create (ptr, name);

  // Find the <name> tag in the parent element.
  using xercesc::DOMNodeList;
  DOMNodeList * list = ptr->getChildNodes ();

  // We always insert the registry node at slot 1 since this will
  // guarantee it is always after the <name> tag and before any
  // <attribute> tag.
  ptr->insertBefore (regnode, list->item (1));

  return Registry_Node (regnode, false);
}

//
// _create
//
Registry_Node Registry_Node::
_create (Registry_Node & parent, const GAME::Xml::String & name)
{
  // First, we need to create the node.
  using xercesc::DOMElement;
  DOMElement * node = Registry_Node::_create (parent.node_, name);

  // Append the node to the end pare.
  parent.node_->appendChild (node);

  return Registry_Node (node, false);
}

//
// _create
//
xercesc::DOMElement * Registry_Node::
_create (xercesc::DOMElement * parent, const GAME::Xml::String & name)
{
  using xercesc::DOMElement;
  using xercesc::DOMDocument;

  // First, create the registry node element.
  DOMDocument * doc = parent->getOwnerDocument ();
  DOMElement * node = doc->createElement (TAGNAME);

  // Set the name of the element.
  node->setAttribute (ATTR_NAME, name);

  return node;
}

//
// child
//
Registry_Node Registry_Node::child (const GAME::Xml::String & name, bool create)
{
  using xercesc::DOMElement;
  using xercesc::DOMNode;
  using xercesc::DOMNodeList;

  // Get the list of child nodes for this node.
  DOMNodeList * list = this->node_->getChildNodes ();
  size_t length = list->getLength ();

  DOMElement * e = 0;
  DOMNode * node = 0;

  for (size_t i = 0; i < length; ++ i)
  {
    // Get the next node in the list.
    node = list->item (i);

    if (node->getNodeType () == DOMNode::ELEMENT_NODE)
    {
      // Check if this attibute is the correct one.
      e = dynamic_cast <DOMElement *> (node);

      if (e->getAttribute (ATTR_NAME) == name)
        return Registry_Node (e, true);
    }
  }

  // Should we create the node instead since we were not able to
  // find it in the list.
  if (create)
    return Registry_Node::_create (*this, name);

  // Throw an exception as last resort.
  throw Not_Found ();
}

//
// value
//
void Registry_Node::value (const GAME::Xml::String & v) const
{
  if (0 == this->value_)
    this->get_value ();

  this->value_->setTextContent (v);
}

//
// value
//
const XMLCh * Registry_Node::value (void) const
{
  if (0 != this->value_)
    return this->value_->getTextContent ();

  this->get_value ();
  return this->value_->getTextContent ();
}

//
// get_value
//
void Registry_Node::get_value (void) const
{
  using xercesc::DOMNode;
  using xercesc::DOMElement;

  DOMNode * node = this->node_->getFirstChild ();
  this->value_ = dynamic_cast <DOMElement *> (node);
}

//
// new_value
//
void Registry_Node::new_value (void)
{
  using xercesc::DOMDocument;

  // Create the new value element.
  DOMDocument * doc = this->node_->getOwnerDocument ();
  this->value_ = doc->createElement (TAGNAME_VALUE);

  // Add the value node to the registry node.
  this->node_->appendChild (this->value_);
}


}
}
