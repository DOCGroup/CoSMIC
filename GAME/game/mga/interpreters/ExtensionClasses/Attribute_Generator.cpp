// $Id$

#include "StdAfx.h"
#include "Attribute_Generator.h"
#include "Functors.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaAtom.h"

namespace GAME
{
namespace Mga
{

//
// Attribute_Generator
//
Attribute_Generator::
Attribute_Generator (const std::string & classname,
                     std::ofstream & header,
                     std::ofstream & source)
: classname_ (classname),
  header_ (header),
  source_ (source)
{

}

//
// ~Attribute_Generator
//
Attribute_Generator::~Attribute_Generator (void)
{

}

//
// visit_Connection
//
void Attribute_Generator::visit_Connection (Connection_in c)
{
  c->src ()->accept (this);
}

//
// visit_Atom
//
void Attribute_Generator::visit_Atom (Atom_in a)
{
  const std::string metaname = a->meta ()->name ();
  std::string getter_type;
  std::string setter_type;
  std::string function_name;

  if (metaname == "BooleanAttribute")
  {
    // Set the setter/getter for the boolean type.
    setter_type = "bool";
    getter_type = "bool";
    function_name = "bool_value";
  }
  else if (metaname == "EnumAttribute")
  {
    // Set the setter/getter for the enum type.
    setter_type = "const std::string &";
    getter_type = "std::string";
    function_name = "string_value";
  }
  else if (metaname == "FieldAttribute")
  {
    // Determine the setter/getter values for the field attribute.
    static const std::string attr_DataType ("DataType");
    const std::string datatype = a->attribute (attr_DataType)->string_value ();

    if (datatype == "integer")
    {
      setter_type = "long";
      getter_type = "long";
      function_name = "int_value";
    }
    else if (datatype == "string")
    {
      setter_type = "const std::string &";
      getter_type = "std::string";
      function_name = "string_value";
    }
    else if (datatype == "double")
    {
      setter_type = "double";
      getter_type = "double";
      function_name = "double_value";
    }
  }

  // Write the setter and getter methods in the header and source file.
  const std::string name = a->name ();

  this->header_
    << std::endl
    << "/// Set the value of " << name << std::endl
    << "void " << name << " (" << setter_type << " val);"
    << std::endl
    << "/// Get the value of " << name << std::endl
    << getter_type << " " << name << " (void) const;";

  this->source_
    << function_header_t (name)
    << "void " << this->classname_ << "::" << name << " (" << setter_type << " val)"
    << "{"
    << "static const std::string attr_" << name << " (\"" << name << "\");"
    << "this->attribute (attr_" << name << ")->" << function_name << " (val);"
    << "}"
    << function_header_t (name)
    << getter_type << " " << this->classname_ << "::" << name << " (void) const"
    << "{"
    << "static const std::string attr_" << name << " (\"" << name << "\");"
    << "return this->attribute (attr_" << name << ")->" << function_name << " ();"
    << "}";
}

}
}
