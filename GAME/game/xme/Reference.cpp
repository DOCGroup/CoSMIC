// $Id$

#include "Reference.h"

#if !defined (__GAME_INLINE__)
#include "Reference.inl"
#endif

#include "GME_ID_Generator.h"
#include "ID_Generator_Repo.h"
#include "Folder.h"

namespace GAME
{
namespace XME
{
const GAME::Xml::String Reference::TAGNAME ("reference");
const GAME::Xml::String Reference::ATTR_REFERRED ("referred");
const GAME::Xml::String Reference::NULL_REFERENCE ("");

template <typename T>
Reference Reference::create_impl (T parent, const GAME::Xml::String & kind)
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
           const GAME::Xml::String & kind,
           size_t relid)
: FCO (parent,
       TAGNAME,
       GAME_XME_ID_GENERATOR_REPO->get (parent)->generate_reference_id (),
       kind,
       kind,
       relid)
{

}

//
// _create
//
Reference Reference::_create (Folder parent, const GAME::Xml::String & kind)
{
  return Reference::create_impl (parent, kind);
}

//
// _create
//
Reference Reference::_create (Model parent, const GAME::Xml::String & kind)
{
  return Reference::create_impl (parent, kind);
}

//
// refers_to
//
void Reference::refers_to (const FCO & fco)
{
  if (fco.is_nil ())
  {
    this->reset ();
  }
  else
  {
    this->obj_->setAttribute (ATTR_REFERRED, GAME::Xml::String (fco.id ()));
    this->refers_to_ = fco;
  }
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
  GAME::Xml::String id (this->obj_->getAttribute (ATTR_REFERRED), false);

  if (id == NULL_REFERENCE)
    return;

  using xercesc::DOMDocument;
  using xercesc::DOMElement;

  // Search for the element by id.
  DOMDocument * doc = this->obj_->getOwnerDocument ();
  DOMElement * element = doc->getElementById (id);

  if (0 != element)
    this->refers_to_.attach (element);
  else
    this->obj_->removeAttribute (ATTR_REFERRED);
}

//
// is_null
//
bool Reference::is_null (void) const
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
  this->obj_->removeAttribute (ATTR_REFERRED);
  this->refers_to_.release ();
}

}
}
