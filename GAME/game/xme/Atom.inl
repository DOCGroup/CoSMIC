// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{
//
// Atom
//
GAME_INLINE
Atom::Atom (void)
: FCO (0, Object_Type::OT_ATOM)
{

}

//
// Atom
//
GAME_INLINE
Atom::Atom (const Atom & atom)
: FCO (atom)
{

}

//
// Atom
//
GAME_INLINE
Atom::Atom (xercesc::DOMElement * atom, bool validate)
: FCO (atom, false)
{
  if (validate && !((this->type_ & Object_Type::OT_ATOM) == Object_Type::OT_ATOM))
    throw Invalid_Cast ();
}

//
// Atom
//
GAME_INLINE
Atom::Atom (xercesc::DOMElement * atom)
: FCO (atom, Object_Type::OT_ATOM)
{

}

//
// Atom
//
GAME_INLINE
Atom::~Atom (void)
{

}

//
// operator =
//
GAME_INLINE
const Atom & Atom::operator = (const Atom & atom)
{
  this->obj_ = atom.obj_;
  return *this;
}

//
// _narrow
//
GAME_INLINE
Atom Atom::_narrow (const Object & obj)
{
  if ((Object_Type::OT_ATOM & obj.type ()))
    return Atom (obj.ptr ());

  throw Invalid_Cast ();
}


}
}
