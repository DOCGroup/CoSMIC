// $Id$

#include "StdAfx.h"
#include "Set_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Set_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Connection_Endpoint_Visitor.h"
#include "game/mga/Connection.h"

#include "boost/bind.hpp"
#include <algorithm>

//
// build
//
void Set_Class_Definition::build (GAME::Mga::FCO_in fco)
{
  // First, pass control to the base class.
  FCO_Class_Definition::build (fco);

  // Get all the members of this set definition.
  std::vector <GAME::Mga::Connection> set_membership;
  fco->in_connections ("SetMembership", set_membership);

  Source_Connection_Endpoint_Visitor src_visitor (fco, this->members_);
  std::for_each (GAME::Mga::make_impl_iter (set_membership.begin ()),
                 GAME::Mga::make_impl_iter (set_membership.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &src_visitor));
}

//
// get_includes
//
void Set_Class_Definition::get_includes (std::set <GAME::Mga::Atom> & includes)
{
  // Pass control to the base clas.
  FCO_Class_Definition::get_includes (includes);

  // Get the includes for this definition.
  typedef std::set <GAME::Mga::Atom> atom_set;

  std::for_each (this->members_.begin (),
                 this->members_.end (),
                 boost::bind (&atom_set::insert, boost::ref (includes), _1));
}

//
// generate_definition
//
void Set_Class_Definition::
generate_definition (const Generation_Context & ctx)
{

}
