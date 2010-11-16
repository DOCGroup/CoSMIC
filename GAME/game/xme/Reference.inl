// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{
//
// Reference
//
GAME_INLINE
Reference::Reference (void)
: FCO (0, Object_Type::OT_REFERENCE)
{

}

//
// Reference
//
GAME_INLINE
Reference::Reference (const Reference & atom)
: FCO (atom),
  refers_to_ (atom.refers_to_)
{

}

//
// Reference
//
GAME_INLINE
Reference::
Reference (xercesc::DOMElement * ref)
: FCO (ref, Object_Type::OT_REFERENCE)
{

}

//
// Reference
//
GAME_INLINE
Reference::
Reference (xercesc::DOMElement * ref, bool validate)
: FCO (ref, false)
{
  if (validate && !((this->type_ & Object_Type::OT_REFERENCE) == Object_Type::OT_REFERENCE))
    throw Invalid_Cast ();
}

//
// Reference
//
GAME_INLINE
Reference::~Reference (void)
{

}

//
// operator =
//
GAME_INLINE
const Reference & Reference::operator = (const Reference & ref)
{
  this->obj_ = ref.obj_;
  this->refers_to_ = ref.refers_to_;
  return *this;
}

//
// _narrow
//
GAME_INLINE
Reference Reference::_narrow (const Object & obj)
{
  if ((obj.type () & Object_Type::OT_REFERENCE))
    return obj.ptr ();

  throw Invalid_Cast ();
}

//
// refresh
//
GAME_INLINE
void Reference::refresh (void)
{
  this->get_reference ();
}

}
}
