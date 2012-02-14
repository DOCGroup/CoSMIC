// $Id$

#include "Fragment.h"

#if !defined (__GAME_INLINE__)
#include "Fragment.inl"
#endif

#include "xercesc/dom/DOMDocument.hpp"
#include <sstream>

namespace GAME
{
namespace Xml
{

//
// create_element
//
xercesc::DOMElement * Fragment::
create_element (xercesc::DOMElement * parent, const String & name)
{
  using xercesc::DOMElement;
  using xercesc::DOMDocument;

  // Create the new element.
  DOMDocument * doc = parent->getOwnerDocument ();
  DOMElement * element = doc->createElement (name);

  // Attach the element to the parent.
  parent->appendChild (element);

  return element;
}

//
// create_element
//
xercesc::DOMElement * Fragment::
create_element (xercesc::DOMElement * parent,
                const String & ns,
                const String & name)
{
  using xercesc::DOMElement;
  using xercesc::DOMDocument;

  // Create the new element.
  DOMDocument * doc = parent->getOwnerDocument ();
  DOMElement * element = doc->createElementNS (ns, name);

  // Attach the element to the parent.
  parent->appendChild (element);

  return element;
}

//
// create_simple_content
//
xercesc::DOMElement * Fragment::
create_simple_content (xercesc::DOMElement * parent,
                       const String & ns,
                       const String & name,
                       const String & value)
{
  using xercesc::DOMDocument;
  using xercesc::DOMElement;

  // Create the element.
  DOMElement * child = Fragment::create_element (parent, ns, name);

  // Create the text inside the child element.
  if (!value.empty ())
    child->setTextContent (value);

  return child;
}

//
// create_simple_content
//
xercesc::DOMElement * Fragment::
create_simple_content (xercesc::DOMElement * parent,
                       const String & name,
                       const String & value)
{
  using xercesc::DOMDocument;
  using xercesc::DOMElement;

  // Create the element.
  DOMElement * child = Fragment::create_element (parent, name);

  // Create the text inside the child element.
  if (!value.empty ())
    child->setTextContent (value);

  return child;
}

//
// set_attribute
//
void Fragment::set_attribute (const String & name, long value)
{
  std::ostringstream ostr;
  ostr << value;

  this->fragment_->setAttribute (name, String (ostr.str ()));
}

void Fragment::set_attribute (const String & name, double value)
{
  std::ostringstream ostr;
  ostr << value;

  this->fragment_->setAttribute (name, String (ostr.str ()));
}

}
}
