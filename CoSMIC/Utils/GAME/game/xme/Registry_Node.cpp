// $Id$

#include "Registry_Node.h"

#if !defined (__GME_INLINE__)
#include "Registry_Node.inl"
#endif

#include "FCO.h"
#include "Registry.h"

namespace GME
{
namespace XME
{
const ::Utils::XStr Registry_Node::TAGNAME ("regnode");
const ::Utils::XStr Registry_Node::TAGNAME_VALUE ("value");
const ::Utils::XStr Registry_Node::ATTR_NAME ("name");

//
// _create
//
Registry_Node Registry_Node::
_create (Registry & parent, const ::Utils::XStr & name)
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

  return regnode;
}

//
// _create
//
Registry_Node Registry_Node::
_create (Registry_Node & parent, const ::Utils::XStr & name)
{
  // First, we need to create the node.
  using xercesc::DOMElement;
  DOMElement * node = Registry_Node::_create (parent.node_, name);

  // Append the node to the end pare.
  parent.node_->appendChild (node);

  return node;
}

//
// _create
//
xercesc::DOMElement * Registry_Node::
_create (xercesc::DOMElement * parent, const ::Utils::XStr & name)
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
// value
//
void Registry_Node::value (const ::Utils::XStr & v) const
{
  if (0 == this->value_)
    this->init_value ();

  this->value_->setTextContent (v);
}

//
// value
//
const XMLCh * Registry_Node::value (void) const
{
  if (0 == this->value_)
    this->init_value ();

  return this->value_->getTextContent ();
}

//
// value
//
void Registry_Node::init_value (void) const
{
  using xercesc::DOMElement;

  if (this->node_->hasChildNodes ())
  {
    using xercesc::DOMNodeList;

    // The first child if the value element.
    DOMNodeList * list = this->node_->getChildNodes ();
    this->value_ = dynamic_cast <DOMElement *> (list->item (0));
  }
  else
  {
    using xercesc::DOMDocument;

    // Create the value element.
    DOMDocument * doc = this->node_->getOwnerDocument ();
    this->value_ = doc->createElement (TAGNAME_VALUE);

    // Add the value node to the registry node.
    this->node_->appendChild (this->value_);
  }
}

}
}
