// $Id$

#include "StdAfx.h"
#include "Factory_Method_Generator.h"
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
// Factory_Method_Generator
//
Factory_Method_Generator::
Factory_Method_Generator (FCO_in fco,
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
// ~Factory_Method_Generator
//
Factory_Method_Generator::~Factory_Method_Generator (void)
{

}

//
// visit_Connection
//
void Factory_Method_Generator::visit_Connection (Connection_in c)
{
  if (c->dst () != this->fco_ || c->dst () == c->src ())
    c->dst ()->accept (this);
}

//
// visit_Atom
//
void Factory_Method_Generator::visit_Atom (Atom_in a)
{
  if (this->seen_.find (a) != this->seen_.end ())
    return;

  const std::string name = this->fco_->name ();
  const std::string in_type = a->name () + "_in";
  const std::string metaname = a->meta ()->name ();
  const std::string factory_method = metaname == "Model" ? "create_object" : "create_root_object";
  const std::string impl_type = name + "_Impl";

  this->header_
    << "static " << name << " _create (const " << in_type << " parent);";

  this->source_
    << function_header_t ("_create")
    << name << " " << this->classname_
    << "::_create (const " << in_type << " parent)"
    << "{"
    << "return ::GAME::Mga::"
    << factory_method
    << " <" << name << "> (parent, " << impl_type << "::metaname);"
    << "}";

  // Make sure we save this item.
  this->seen_.insert (a);
}

}
}
