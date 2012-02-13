// $Id$

#include "StdAfx.h"
#include "Containment_Generator.h"
#include "Functors.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaAtom.h"

#include "boost/bind.hpp"

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
  const std::string card = c->attribute ("Cardinality")->string_value ();

  this->generate_containment (src, card);
}

//
// visit_Reference
//
void Containment_Generator::visit_Reference (Reference_in ref)
{
  // Visit all the containment connections.
  std::vector <Connection> containment;
  ref->in_connections ("Containment", containment);

  std::for_each (containment.begin (),
                 containment.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              this));
}

//
// generate_containment
//
void Containment_Generator::
generate_containment (FCO_in fco, const std::string & card)
{
  if (this->seen_.find (fco->id ()) != this->seen_.end ())
    return;

  // Extract the concrete values for the cardinality.
  std::istringstream istr (card);
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

  const std::string name = fco->name ();

  if (max_cardinality == 1)
  {
    const std::string method_name = "get_" + name;
    const std::string has_method_name = "has_" + name;

    // Declare the function.
    this->header_
      << std::endl
      << "bool " << has_method_name << " (void) const;"
      << name << " " << method_name << " (void) const;";

    // Implement the function.
    this->source_
      << function_header_t (has_method_name)
      << "bool " << this->classname_ << "::" << has_method_name << " (void) const"
      << "{"
      << "// Get the collection of children." << std::endl
      << "GAME::Mga::Iterator <" << name << "> iter = this->children <" << name << "> ();"
      << "return iter.count () == 1;"
      << "}"
      << function_header_t (method_name)
      << name << " " << this->classname_ << "::" << method_name << " (void) const"
      << "{"
      << "GAME::Mga::Iterator <" << name << "> iter = this->children <" << name << "> ();"
      << "return *iter;"
      << "}";
  }
  else
  {
    const std::string method_name = "get_" + name + "s";

    // Declare the function.
    this->header_
      << std::endl
      << "size_t " << method_name << " (std::vector <"
      << name << "> & items) const;"
      << "GAME::Mga::Iterator <" << name << "> " << method_name << " (void) const;";

    // Implement the function.
    this->source_
      << function_header_t (method_name)
      << "size_t " << this->classname_ << "::"
      << method_name << " (std::vector <" << name << "> & items) const"
      << "{"
      << "return this->children (items);"
      << "}"
      << function_header_t (method_name)
      << "GAME::Mga::Iterator <" << name << "> " << this->classname_ << "::"
      << method_name << " (void) const"
      << "{"
      << "return this->children <" << name << "> ();"
      << "}";
  }

  // Make this item as seen.
  this->seen_.insert (fco->id ());
}

}
}
