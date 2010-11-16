// $Id$

#include "FCO.h"

#if !defined (__GAME_INLINE__)
#include "FCO.inl"
#endif

namespace GAME
{
namespace XME
{
const GAME::Xml::String FCO::ATTR_ROLE ("role");
const GAME::Xml::String FCO::ATTR_KIND ("kind");

//
// attach
//
void FCO::attach (xercesc::DOMElement * fco, bool validate)
{
  // Pass control to the base class.
  Object::attach (fco, false);

  // Validate the concrete type.
  if (validate && !((this->type_ & Object_Type::OT_FCO) == Object_Type::OT_FCO))
    throw Invalid_Cast ();
}

//
// attribute
//
Attribute FCO::attribute (const GAME::Xml::String & name, bool create) const
{
  using xercesc::DOMNodeList;
  using xercesc::DOMElement;
  using xercesc::DOMNode;
  using xercesc::DOMDocument;

  DOMNode * node = 0;
  DOMElement * element = 0;

  // Get all the immediate children of this element.
  DOMNodeList * list = this->obj_->getChildNodes ();
  size_t length = list->getLength ();

  for (size_t i = 0; i < length; ++ i)
  {
    // Get the next item in the list.
    node = list->item (i);

    if (node->getNodeType () == DOMNode::ELEMENT_NODE)
    {
      // Convert the node to an element.
      element = dynamic_cast <DOMElement *> (node);

      // Check the name of this attribute.
      if (name == element->getAttribute (ATTR_KIND))
        return element;
    }
  }

  // Should we create a new attribute since we could not find
  // an existing attribute.
  if (create)
    return Attribute::_create (*this, name);

  // Ok, we failed!!
  throw Bad_Attribute ();
}

//
// registry
//
Registry & FCO::registry (void)
{
  if (0 != this->registry_.get ())
    return *this->registry_;

  this->registry_.reset (new Registry (*this));
  return *this->registry_;
}

//
// registry
//
const Registry & FCO::registry (void) const
{
  if (0 != this->registry_.get ())
    return *this->registry_;

  this->registry_.reset (new Registry (const_cast <FCO &> (*this)));
  return *this->registry_;
}

}
}
