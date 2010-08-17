// $Id$

#include "Object.h"

#if !defined (__GAME_INLINE__)
#include "Object.inl"
#endif

#include "Object_Type_Map.hpp"
#include "Reference.h"
#include <sstream>

namespace GAME
{
namespace XME
{
// constants
const ::Utils::XStr Object::ATTR_ID ("id");
const ::Utils::XStr Object::ATTR_KIND ("kind");
const ::Utils::XStr Object::ATTR_RELID ("relid");
const ::Utils::XStr Object::ELEMENT_NAME ("name");

//
// Object
//
Object::
Object (xercesc::DOMElement * parent,
        const ::Utils::XStr & tagname,
        const ::Utils::XStr & id,
        const ::Utils::XStr & kind,
        size_t relid)
{
  using xercesc::DOMDocument;
  using xercesc::DOMElement;

  // Create the XML document for the object.
  DOMDocument * doc = parent->getOwnerDocument ();
  this->obj_ = doc->createElement (tagname);
  parent->appendChild (this->obj_);

  // Initialize the attributes of the object.
  std::ostringstream ostr;
  ostr << "0x" << std::hex << relid;

  this->obj_->setAttribute (ATTR_ID, id);
  this->obj_->setAttribute (ATTR_KIND, kind);
  this->obj_->setAttribute (ATTR_RELID, ::Utils::XStr (ostr.str ()));

  // Finally, make sure the 'id' is the id attribute. This will be
  // needed when making calls to getElementById ().
  if (!this->obj_->getAttributeNode (ATTR_ID)->isId ())
    this->obj_->setIdAttribute (ATTR_ID, true);

  // Make sure the object has <name> element.
  DOMElement * e = doc->createElement (ELEMENT_NAME);
  this->obj_->appendChild (e);
  e->setTextContent (::Utils::XStr::EMPTY_STRING);
}

//
// parent
//
Object Object::parent (void) const
{
  using xercesc::DOMElement;
  using xercesc::DOMNode;

  DOMNode * node = this->obj_->getParentNode ();
  DOMElement * e = dynamic_cast <DOMElement *> (node);

  return Object (e, false);
}

//
// destroy
//
void Object::destroy (void)
{
  using xercesc::DOMDocument;
  using xercesc::DOMElement;
  using xercesc::DOMNode;

  // Store this object's id since we will need it later.
  DOMDocument * doc = this->obj_->getOwnerDocument ();
  ::Utils::XStr old_id (this->id (), true);

  // Remove this node from the XML tree.
  DOMNode * parent = this->obj_->getParentNode ();
  parent->removeChild (this->obj_);

  // Release this object's resources.
  this->obj_->release ();
  this->obj_ = 0;

  // Check for any dangling references. If we find any we need
  // to reset them (i.e., set them to null). It would be nice to
  // use XPath to make this evaluation a LOT easier (e.g., locating
  // all the reference elements that refer to this element, and reset
  // them).

  using xercesc::DOMNodeList;

  DOMNodeList * list = doc->getElementsByTagName (Reference::TAGNAME);
  size_t length = list->getLength ();

  for (size_t i = 0; i < length; ++ i)
  {
    DOMElement * e = dynamic_cast <DOMElement *> (list->item (i));

    Reference ref (e, false);
    FCO refers_to = ref.refers_to ();

    if (!refers_to.is_nil ())
    {
      const ::Utils::XStr id (refers_to.id (), false);

      if (id == old_id)
        ref.reset ();
    }
  }

  // TODO Make sure deleted objects are removed from their set.
}

//
// attach
//
void Object::attach (xercesc::DOMElement *e, bool validate)
{
  // Get the tag name for this element.
  ::Utils::XStr tagname (e->getTagName (), false);
  const std::string & str = tagname.to_string ();

  // Locate the tagname in the hashmap.
  static Perfect_Hash hash_map;
  const object_type * info = hash_map.in_word_set (str.c_str (), str.length ());

  if (0 == info)
    throw Invalid_Cast ();

  // Save the identified type information.
  this->type_ = info->type;
  this->obj_ = e;
}

}
}
