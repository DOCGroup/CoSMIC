// $Id$

#include "Atom.h"

#if !defined (__GAME_INLINE__)
#include "Atom.inl"
#endif

#include "GME_ID_Generator.h"
#include "ID_Generator_Repo.h"
#include "Folder.h"

namespace GAME
{
namespace XME
{
//
// TAGNAME
//
const GAME::Xml::String Atom::TAGNAME ("atom");

template <typename T>
Atom Atom::create_impl (T parent, const GAME::Xml::String & kind)
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
      const GAME::Xml::String & kind,
      size_t relid)
: FCO (parent,
       TAGNAME,
       GAME_XME_ID_GENERATOR_REPO->get (parent)->generate_atom_id (),
       kind,
       kind,
       relid)
{

}

//
// _create
//
Atom Atom::_create (Folder parent, const GAME::Xml::String & kind)
{
  return Atom::create_impl (parent, kind);
}

//
// _create
//
Atom Atom::_create (Model parent, const GAME::Xml::String & kind)
{
  return Atom::create_impl (parent, kind);
}

}
}
