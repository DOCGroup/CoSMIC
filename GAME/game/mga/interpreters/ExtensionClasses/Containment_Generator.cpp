// $Id$

#include "StdAfx.h"
#include "Containment_Generator.h"
#include "Functors.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaAtom.h"

#include <sstream>

namespace GAME
{
namespace Mga
{

//
// Containment_Generator
//
Containment_Generator::
Containment_Generator (FCO_in fco,
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
// ~Containment_Generator
//
Containment_Generator::~Containment_Generator (void)
{

}

//
// visit_Connection
//
void Containment_Generator::visit_Connection (Connection_in c)
{
  FCO src = c->src ();

  if (this->fco_ == src && src != c->dst ())
    return;

  this->cardinality_ = c->attribute ("Cardinality")->string_value ();
  c->src ()->accept (this);
}

//
// visit_Atom
//
void Containment_Generator::visit_Atom (Atom_in a)
{
  if (this->seen_.find (a->id ()) != this->seen_.end ())
    return;

  // Extract the concrete values for the cardinality.
  std::istringstream istr (this->cardinality_);
  int min_cardinality = 0, max_cardinality = -1;

  istr >> min_cardinality;

  if (!istr.eof ())
  {
    istr.ignore (2);
    istr >> max_cardinality;
  }
  else
  {
    max_cardinality = min_cardinality;
  }

  const std::string name = a->name ();

  if (max_cardinality == 1)
  {
    const std::string method_name = "get_" + name;

    // Declare the function.
    this->header_
      << std::endl
      << name << " " << method_name << " (void) const;";

    // Implement the function.
    this->source_
      << function_header_t (method_name)
      << name << " " << this->classname_ << "::" << method_name << " (void) const"
      << "{"
      << "// Get the collection of children." << std::endl
      << "std::vector <" << name << "> items;"
      << "this->children (items);"
      << std::endl
      << "return !items.empty () ? items.front () : " << name << " ();"
      << "}";
  }
  else
  {
    const std::string method_name = "get_" + name + "s";

    // Declare the function.
    this->header_
      << "size_t " << method_name << " (std::vector <"
      << name << "> & items) const;";

    // Implement the function.
    this->source_
      << function_header_t (method_name)
      << "size_t " << this->classname_ << "::"
      << method_name << " (std::vector <" << name << "> & items) const"
      << "{"
      << "return this->children (items);"
      << "}";
  }

  // Make this item as seen.
  this->seen_.insert (a->id ());
}

//
// visit_Reference
//
void Containment_Generator::visit_Reference (Reference_in ref)
{
  ref->refers_to ()->accept (this);
}

}
}
