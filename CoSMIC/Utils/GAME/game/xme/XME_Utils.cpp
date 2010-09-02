// $Id$

#include "XME_Utils.h"
#include "game/xml/String.h"
#include "xercesc/DOM/DOMDocument.hpp"
#include "xercesc/DOM/DOMNode.hpp"
#include "xercesc/DOM/DOMNodeList.hpp"

namespace GAME
{
namespace XME
{
//
// set_element_value
//
void Utils::
set_element_value (xercesc::DOMElement * e,
                   const std::string & element,
                   const std::string & value)
{
  Utils::set_element_value (e,
                            GAME::Xml::String (element),
                            GAME::Xml::String (value));
}

//
// set_element_value
//
void Utils::
set_element_value (xercesc::DOMElement * e,
                   const GAME::Xml::String & element,
                   const GAME::Xml::String & value)
{
  using xercesc::DOMNode;
  using xercesc::DOMNodeList;
  using xercesc::DOMDocument;

  // There should be only 1 <name> tag in the list.
  GAME::Xml::String nodename;
  DOMNode * node = 0;
  DOMNodeList * list = e->getChildNodes ();
  size_t len = list->getLength ();

  for (size_t i = 0; i < len; ++ i)
  {
    // Get the name of the next node.
    node = list->item (i);
    nodename.set (node->getNodeName (), false);

    if (nodename == element)
      break;

    // Reset the node.
    node = 0;
  }

  if (node == 0)
  {
    // We need to create the <name> element.
    DOMDocument * doc = e->getOwnerDocument ();
    node = doc->createElement (element);
    e->appendChild (node);
  }

  // Since there are no child nodes, we can just set the
  // text content to the name of the object.
  node->setTextContent (value);
}

//
// get_element_value
//
void Utils::
get_element_value (const xercesc::DOMElement * e,
                   const std::string & element,
                   std::string & value)
{
  using namespace xercesc;

  // There should be only 1 <name> tag in the list.
  DOMNodeList * list = e->getElementsByTagName (GAME::Xml::String (element));
  size_t len = list->getLength ();

  assert (len <= 1);

  if (len == 0)
  {
    value = "";
  }
  else if (len == 1)
  {
    // Get text content of the one and only node in listing.
    DOMNode * node = list->item (0);
    GAME::Xml::String content (node->getTextContent (), false);

    // Save the value in C string format.
    value = content.to_string ();
  }
}

//
// get_element_value
//
const XMLCh * Utils::
get_element_value (const xercesc::DOMElement * e, const GAME::Xml::String & element)
{
  using xercesc::DOMNodeList;
  using xercesc::DOMNode;

  // There should be only 1 <name> tag in the list.
  GAME::Xml::String nodename;
  DOMNode * node = 0;
  DOMNodeList * list = e->getChildNodes ();
  size_t len = list->getLength ();

  for (size_t i = 0; i < len; ++ i)
  {
    node = list->item (i);
    nodename.set (node->getNodeName (), false);

    if (nodename == element)
      return node->getTextContent ();
  }

  return 0;
}

//
// get_element_value
//
const XMLCh * Utils::
get_element_value (const xercesc::DOMElement * e, const std::string & element)
{
  return Utils::get_element_value (e, GAME::Xml::String (element));
}

}

}
