// $Id$

#include "Attribute.h"

#if !defined (__GAME_INLINE__)
#include "Attribute.inl"
#endif

#include "GME_ID_Generator.h"
#include "Folder.h"

namespace GAME
{
namespace XME
{
//
// TAGNAME
//
const GAME::Xml::String Attribute::TAGNAME ("attribute");

//
// VALUE_TAGNAME
//
const GAME::Xml::String Attribute::VALUE_TAGNAME ("value");
const GAME::Xml::String Attribute::ATTR_KIND ("kind");

const GAME::Xml::String Attribute::TRUE_VALUE ("True");
const GAME::Xml::String Attribute::FALSE_VALUE ("False");

//
// Attribute
//
Attribute::Attribute (const FCO & parent, const GAME::Xml::String & name)
: attr_ (0),
  value_ (0)
{
  using xercesc::DOMDocument;
  using xercesc::DOMElement;

  // Add the attribute to the document.
  DOMDocument * doc = parent.ptr ()->getOwnerDocument ();
  this->attr_ = doc->createElement (TAGNAME);
  parent.ptr ()->appendChild (this->attr_);

  // Set the kind of the attribute.
  this->attr_->setAttribute (ATTR_KIND, name);

  // Set an empty value for the attribute.
  this->value_ = doc->createElement (VALUE_TAGNAME);
  this->attr_->appendChild (this->value_);
  this->value_->setTextContent (GAME::Xml::String::EMPTY_STRING);
}

//
// value
//
const XMLCh * Attribute::value (void) const
{
  if (0 != this->value_)
    return this->value_->getTextContent ();

  this->get_value_element ();
  return this->value_->getTextContent ();
}

//
// value
//
void Attribute::value (const GAME::Xml::String & val)
{
  if (0 == this->value_)
    this->get_value_element ();

  this->value_->setTextContent (val);
}

//
// value
//
void Attribute::value (bool val)
{
  if (0 == this->value_)
    this->get_value_element ();

  this->value_->setTextContent (val ? TRUE_VALUE : FALSE_VALUE);
}

//
// value
//
void Attribute::get_value_element (void) const
{
  using xercesc::DOMNodeList;
  using xercesc::DOMElement;

  DOMNodeList * list = this->attr_->getChildNodes ();
  size_t length = list->getLength ();

  if (length >= 1)
  {
    this->value_ = dynamic_cast <DOMElement *> (list->item (0));
  }
  else
  {
    using xercesc::DOMDocument;

    DOMDocument * doc = this->attr_->getOwnerDocument ();
    this->value_ = doc->createElement (VALUE_TAGNAME);
    this->attr_->appendChild (this->value_);
  }
}

}
}
