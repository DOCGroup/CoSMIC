// $Id$

#include "StdAfx.h"
#include "Containment_Generator.h"
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
// Containment_Generator
//
Containment_Generator::
Containment_Generator (const std::string & classname,
                       std::ofstream & header,
                       std::ofstream & source)
: classname_ (classname),
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
  this->cardinality_ = c->attribute ("Cardinality")->string_value ();
  c->src ()->accept (this);
}

//
// visit_Atom
//
void Containment_Generator::visit_Atom (Atom_in a)
{
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
      << "static const std::string meta_" << name << " (\"" << name << "\");"
      << "std::vector <" << name << "> items;"
      << std::endl
      << "this->children (meta_" << name << ", items);"
      << "return items.front ();"
      << "}";
  }
  else
  {
    const std::string method_name = "get_" + name + "s";

    // Declare the function.
    this->header_
      << std::endl
      << "size_t " << method_name << " (std::vector <"
      << name << "> & items) const;";

    // Implement the function.
    this->source_
      << function_header_t (method_name)
      << "size_t " << this->classname_ << "::"
      << method_name << " (std::vector <" << name << "> & items) const"
      << "{"
      << "static const std::string meta_" << name << " (\"" << name << "\");"
      << "return this->children (meta_" << name << ", items);"
      << "}";
  }
}

}
}
