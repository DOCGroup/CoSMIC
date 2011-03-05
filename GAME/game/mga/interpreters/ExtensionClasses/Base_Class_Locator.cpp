// $Id$

#include "StdAfx.h"
#include "Base_Class_Locator.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaAtom.h"

#include "boost/bind.hpp"
#include <algorithm>

namespace GAME
{
namespace Mga
{

//
// Base_Class_Locator
//
Base_Class_Locator::Base_Class_Locator (std::set <Atom> & bc)
: bc_ (bc)
{

}

//
// ~Base_Class_Locator
//
Base_Class_Locator::~Base_Class_Locator (void)
{

}

//
// visit_Atom
//
void Base_Class_Locator::visit_Atom (Atom_in a)
{
  const std::string metaname = a->meta ()->name ();

  if (metaname == "Inheritance")
  {
    // Locate all the DerivedInheritance connections for this element.
    std::vector <Connection> derived_conns;
    a->in_connections ("BaseInheritance", derived_conns);

    std::for_each (derived_conns.begin (),
                   derived_conns.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                this));
  }
  else
  {
    // Locate all the BaseInheritance connections for this element.
    std::vector <Connection> base_conns;
    a->in_connections ("DerivedInheritance", base_conns);

    std::for_each (base_conns.begin (),
                   base_conns.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                this));
  }
}

//
// visit_Connection
//
void Base_Class_Locator::visit_Connection (Connection_in c)
{
  const std::string metaname = c->meta ()->name ();
  FCO src = c->src ();

  // We need to save the destination point if it is the actual
  // derived class.
  if (metaname == "BaseInheritance")
  {
    // Make sure we have located the atom, and walked through
    // all the proxy elements.
    while (src->type () == OBJTYPE_REFERENCE)
      src = Reference::_narrow (src)->refers_to ();

    this->bc_.insert (Atom::_narrow (src));
  }
  else
  {
    // Visit the destination connection point.
    src->accept (this);
  }
}

}
}
