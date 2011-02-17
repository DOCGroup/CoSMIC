// $Id$

#include "StdAfx.h"
#include "RefersTo_Method_Generator.h"
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
// RefersTo_Method_Generator
//
RefersTo_Method_Generator::
RefersTo_Method_Generator (FCO_in fco,
                          const std::string & classname,
                          std::ofstream & header,
                          std::ofstream & source)
: fco_ (fco),
  classname_ (classname),
  header_ (header),
  source_ (source)
{

}

//
// ~RefersTo_Method_Generator
//
RefersTo_Method_Generator::~RefersTo_Method_Generator (void)
{

}

//
// visit_Connection
//
void RefersTo_Method_Generator::visit_Connection (Connection_in c)
{
  if (c->dst () != this->fco_ || c->dst () == c->src ())
    c->dst ()->accept (this);
}

//
// visit_Atom
//
void RefersTo_Method_Generator::visit_Atom (Atom_in a)
{
  if (this->seen_.find (a) != this->seen_.end ())
    return;

  const std::string ref_type = a->name ();
  const std::string method_name = "refers_to_" + ref_type;

  this->header_
    << ref_type << " " << method_name << " (void) const;";

  this->source_
    << function_header_t (method_name)
    << ref_type << " " << this->classname_ << "::" << method_name << " (void) const"
    << "{"
    << "return ::GAME::Mga::get_refers_to <" << ref_type << "> (this);"
    << "}";

  this->seen_.insert (a);
}

}
}
