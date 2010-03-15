// $Id$

#include "functional.h"
#include "Uml.h"
#include <stack>
#include <string>
#include <sstream>

namespace PICML
{
namespace utils
{
//
// scope
//
std::string scope (const PICML::NamedType & named_type,
                   const std::string & separator,
                   bool leading)
{
  std::stack <PICML::MgaObject> temp_stack;

  // Continue walking up the tree until we reach a File object.
  PICML::MgaObject parent = named_type.parent ();

  while (parent.type () == PICML::Package::meta)
  {
    temp_stack.push (parent);
    parent = PICML::MgaObject::Cast (parent.parent ());
  }

  // Insert the leading separator, if applicable.
  std::ostringstream scope;

  if (leading)
    scope << separator;

  // Empty the remainder of the stack.
  while (!temp_stack.empty ())
  {
    parent = temp_stack.top ();
    temp_stack.pop ();

    scope << parent.name () << separator;
  }

  return scope.str ();
}

//
// fq_type
//
std::string fq_type (const PICML::NamedType & named_type,
                     const std::string & separator,
                     bool leading)
{
  std::ostringstream fq_name;
  fq_name << scope (named_type, separator, leading) << named_type.name ();

  return fq_name.str ();
}

//
// repository_id
//
std::string repository_id (const PICML::NamedType & named_type)
{
  std::ostringstream ostr;
  ostr << "IDL:";

  // Write the prefix, if applicable.
  std::string prefix = named_type.SpecifyIdTag ();
  if (!prefix.empty ())
    ostr << prefix << "/";

  // Write the full scope of the named type.
  ostr << fq_type (named_type, "/", false) << ":";

  // Write the version tag, if applicable.
  std::string version = named_type.VersionTag ();
  ostr << (version.empty () ? "1.0" : version);

  return ostr.str ();
}

}
}
