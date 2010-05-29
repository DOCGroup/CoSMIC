// $Id$

#include "Atom.h"

#if !defined (__GAME_INLINE__)
#include "Atom.inl"
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
const ::Utils::XStr Atom::TAGNAME ("atom");

template <typename T>
static Atom Atom::create_impl (T & parent, const ::Utils::XStr & kind)
{
  // Generate the relative id for the new folder.
  size_t counter = parent.relid_counter ();
  parent.relid_counter (counter + 1);

  // Generate a unique id for the new folder.
  return Atom (parent.ptr (), kind, counter);
}

//
// Atom
//
GAME_INLINE
Atom::
Atom (xercesc::DOMElement * parent,
      const ::Utils::XStr & kind,
      size_t relid)
: FCO (parent,
       TAGNAME,
       GME_XME_ID_GENERATOR (Atom)->generate_id (),
       kind,
       kind,
       relid)
{

}

//
// _create
//
Atom Atom::_create (Folder & parent, const ::Utils::XStr & kind)
{
  return Atom::create_impl (parent, kind);
}

//
// _create
//
Atom Atom::_create (Model & parent, const ::Utils::XStr & kind)
{
  return Atom::create_impl (parent, kind);
}

}
}
