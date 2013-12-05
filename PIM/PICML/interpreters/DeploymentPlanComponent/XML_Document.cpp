// $Id$

#include "XML_Document.h"
#include "xercesc/util/PlatformUtils.hpp"
#include "game/xml/String.h"

//
// create_element
//
xercesc::DOMElement *
XML_Document::
create_element (xercesc::DOMNode * parent, const std::string & name)
{
  using namespace GAME::Xml;
  using namespace xercesc;

  // Create the new element.
  DOMDocument * doc = parent->getOwnerDocument ();
  DOMElement * element = doc->createElement (String (name.c_str ()));

  // Attach the element to the parent.
  parent->appendChild (element);

  return element;
}

//
// create_simple_content
//
xercesc::DOMElement *
XML_Document::
create_simple_content (xercesc::DOMNode * parent,
                       const std::string & name,
                       const std::string & value)
{
  using namespace GAME::Xml;
  using namespace xercesc;

  // Create the element.
  DOMElement * child = XML_Document::create_element (parent, name);

  if (value.empty ())
    return child;

  // Create the text inside the child element.
  DOMDocument * doc = child->getOwnerDocument ();
  child->appendChild (doc->createTextNode (String (value.c_str ())));
  return child;
}
