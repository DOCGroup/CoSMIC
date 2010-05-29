// $Id$

#include "Reference.h"

#if !defined (__GAME_INLINE__)
#include "Reference.inl"
#endif

#include "GME_ID_Generator.h"
#include "Folder.h"

namespace GAME
{
namespace XME
{
const ::Utils::XStr Reference::TAGNAME ("reference");
const ::Utils::XStr Reference::ATTR_REFERRED ("referred");
const ::Utils::XStr Reference::NULL_REFERENCE ("");

template <typename T>
static Reference Reference::create_impl (T parent, const ::Utils::XStr & kind)
{
  // Generate the relative id for the new folder.
  size_t counter = parent.relid_counter ();
  parent.relid_counter (counter + 1);

  // Generate a unique id for the new folder.
  return Reference (parent.ptr (), kind, counter);
}

//
// Reference
//
GAME_INLINE
Reference::
Reference (xercesc::DOMElement * parent,
           const ::Utils::XStr & kind,
           size_t relid)
: FCO (parent,
       TAGNAME,
       GME_XME_ID_GENERATOR (Reference)->generate_id (),
       kind,
       kind,
       relid)
{
  this->obj_->setAttribute (ATTR_REFERRED, NULL_REFERENCE);
}


//
// _create
//
Reference Reference::_create (Folder & parent, const ::Utils::XStr & kind)
{
  return Reference::create_impl (parent, kind);
}

//
// _create
//
Reference Reference::_create (Model & parent, const ::Utils::XStr & kind)
{
  return Reference::create_impl (parent, kind);
}

//
// refers_to
//
void Reference::refers_to (const FCO & fco)
{
  this->obj_->setAttribute (ATTR_REFERRED, ::Utils::XStr (fco.id ()));
  this->refers_to_ = fco;
}

//
// refers_to
//
FCO Reference::refers_to (void) const
{
  if (this->refers_to_.is_nil ())
    this->get_reference ();

  return this->refers_to_;
}

//
// get_reference
//
void Reference::get_reference (void) const
{
  ::Utils::XStr id (this->obj_->getAttribute (ATTR_REFERRED), false);

  if (id != NULL_REFERENCE)
  {
    using xercesc::DOMDocument;
    using xercesc::DOMElement;

    // Search for the element by id.
    DOMDocument * doc = this->obj_->getOwnerDocument ();
    DOMElement * element = doc->getElementById (id);

    if (element)
      this->refers_to_.attach (element);
  }
}

//
// is_null
//
bool Reference::is_null (void)
{
  if (this->refers_to_.is_nil ())
    this->get_reference ();

  return this->refers_to_.is_nil ();
}

//
// reset
//
void Reference::reset (void)
{
  this->obj_->setAttribute (ATTR_REFERRED, NULL_REFERENCE);
  this->refers_to_.release ();
}

}
}
