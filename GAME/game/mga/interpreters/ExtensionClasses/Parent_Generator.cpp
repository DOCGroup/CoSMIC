// $Id$

#include "StdAfx.h"
#include "Parent_Generator.h"
#include "Functors.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaAtom.h"

#include <sstream>

namespace GAME
{
namespace Mga
{

//
// Parent_Generator
//
Parent_Generator::
Parent_Generator (const std::string & classname,
                  std::ofstream & header,
                  std::ofstream & source)
: classname_ (classname),
  header_ (header),
  source_ (source)
{

}

//
// ~Parent_Generator
//
Parent_Generator::~Parent_Generator (void)
{

}

//
// visit_Connection
//
void Parent_Generator::visit_Connection (Connection_in c)
{
  c->dst ()->accept (this);
}

//
// visit_Atom
//
void Parent_Generator::visit_Atom (Atom_in a)
{
  const std::string name = a->name ();
  const std::string parent_method = "parent_" + name;

  this->header_
    << name << " " << parent_method << " (void) const;";

  this->source_
    << function_header_t (parent_method)
    << name << " " << this->classname_ << "::"
    << parent_method << " (void) const"
    << "{"
    << "return ::GAME::Mga::get_parent <" << name << "> (this->object_.p);"
    << "}";
}

}
}
