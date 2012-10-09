// $Id: generate_cpp_class.py 3679 2012-04-30 02:25:20Z hillj $

#include "StdAfx.h"
#include "Object_Manager.h"

#if !defined (__GAME_INLINE__)
#include "Object_Manager.inl"
#endif

#include "Class_Definition.h"
#include "Object_Class_Definition.h"

//
// get
//
Object_Class_Definition * Object_Manager::get (GAME::Mga::Atom_in atom)
{
  // First, locate the object class definition in our cache. If we
  // found it, then we should return it.
  const std::string metaname = atom->name ();
  Object_Class_Definition * definition = 0;

  if (0 == this->objects_.find (metaname, definition))
    return definition;

  // Since we could not locate a definition for the atom, we need to
  // build it. This way we have it for now, and later usage.
  this->build (atom, definition);
  return definition;
}

//
// build
//
void Object_Manager::build (GAME::Mga::Atom_in atom)
{
  Object_Class_Definition * definition = 0;
  this->build (atom, definition);
}

//
// build
//
void Object_Manager::
build (GAME::Mga::Atom_in atom, Object_Class_Definition * & definition)
{
  const std::string metaname = atom->name ();

  if (0 != this->objects_.find (metaname, definition))
  {
    // Since we did not find it, we need to create a new class definition
    // and store it for later usage.
    std::auto_ptr <Class_Definition> auto_clean (Class_Definition::_create (atom));

    if (0 == auto_clean.get ())
      return;

    definition = dynamic_cast <Object_Class_Definition *> (auto_clean.get ());

    if (0 == this->objects_.bind (metaname, definition))
      auto_clean.release ();

    // Now, let's build the object we just found. ;-)
    definition->build (atom);
  }
}
