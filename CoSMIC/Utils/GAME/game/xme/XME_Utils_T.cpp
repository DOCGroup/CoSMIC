// $Id$

#include "xercesc/dom/DOMNodeList.hpp"
#include "game/xml/String.h"
#include "Exceptions.h"

namespace GAME
{
namespace XME
{
static const GAME::Xml::String ATTR_KIND ("kind");

//
// get_children
//
template <typename T>
size_t Utils::
get_children (xercesc::DOMElement * e,  std::vector <T> & children)
{
  using xercesc::DOMElement;
  using xercesc::DOMNode;
  using xercesc::DOMNodeList;

  if (e->hasChildNodes ())
  {
    // Get an iterator to the child nodes.
    DOMNodeList * list = e->getChildNodes ();
    size_t length = list->getLength ();

    // Resize the list.
    children.resize (length);

    // Copy over all the children in the list.
    size_t final_length = 0;
    DOMNode * node = 0;

    for (size_t i = 0; i < length; ++ i)
    {
      // Get the name of the next node.
      node = list->item (i);

      if (node->getNodeType () == DOMNode::ELEMENT_NODE)
      {
        // Get the tagname for the element.
        e = dynamic_cast <DOMElement *> (node);

        try
        {
          // Save the next element. If the element is not of the
          // type T, then it will throw an exception.
          children[final_length].attach (e, true);
          ++ final_length;
        }
        catch (const Invalid_Cast & )
        {

        }
      }
    }

    // Update the final size of the collection.
    children.resize (final_length);
  }
  else
  {
    // Remove all the elements from the collection.
    children.clear ();
  }

  return children.size ();
}

//
// get_children
//
template <typename T>
size_t Utils::
get_children (xercesc::DOMElement * e,
              const GAME::Xml::String & metaname,
              std::vector <T> & children)
{
  using xercesc::DOMElement;
  using xercesc::DOMNode;
  using xercesc::DOMNodeList;

  if (e->hasChildNodes ())
  {
    // Get an iterator to the child nodes.
    DOMNodeList * list = e->getChildNodes ();
    size_t length = list->getLength ();

    // Resize the list.
    children.resize (length);

    // Copy over all the children in the list.
    size_t final_length = 0;
    DOMNode * node = 0;
    GAME::Xml::String kind;

    for (size_t i = 0; i < length; ++ i)
    {
      // Get the name of the next node.
      node = list->item (i);

      if (node->getNodeType () == DOMNode::ELEMENT_NODE)
      {
        // Make sure this is of the right kind.
        e = dynamic_cast <DOMElement *> (node);
        kind.set (e->getAttribute (ATTR_KIND), false);

        // Save the element to the list.
        if (metaname == kind)
          children[final_length ++].attach (e, false);
      }
    }

    // Update the final size of the collection.
    children.resize (final_length);
  }
  else
  {
    // Remove all the elements from the collection.
    children.clear ();
  }

  return children.size ();}
}
}
