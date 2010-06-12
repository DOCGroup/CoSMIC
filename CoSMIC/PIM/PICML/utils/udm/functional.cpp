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
static std::string 
_scope (const PICML::MgaObject & obj,
        const std::string & separator,
        bool leading,
        const PICML::MgaObject & stop = PICML::MgaObject ())
{
  std::stack <PICML::MgaObject> temp_stack;

  // Continue walking up the tree until we reach a File object.
  PICML::MgaObject parent = PICML::MgaObject::Cast (obj.parent ());

  while (parent.type () == PICML::Package::meta && parent != stop)
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
// scope
//
std::string scope (const PICML::NamedType & named_type,
                   const std::string & separator,
                   bool leading)
{
  return _scope (named_type, separator, leading);
}

//
// scope
//
std::string scope (const PICML::Exception & ex,
                   const std::string & separator,
                   bool leading)
{
  return _scope (ex, separator, leading);
}

//
// scope
//
std::string scope (const PICML::Package & p,
                   const std::string & separator,
                   bool leading)
{
  return _scope (p, separator, leading);
}

//
// scope
//
std::string scope (const PICML::TemplatePackageRefContainerFCO & fco,
                   const PICML::MgaObject & object,
                   const std::string & separator,
                   bool leading)
{
  PICML::TemplatePackageInstanceDecl conn = fco.srcTemplatePackageInstanceDecl ();

  // If there is not template instance association, then just
  // return the full scope of the object.
  if (conn == Udm::null)
    return _scope (object, separator, leading);

  PICML::TemplatePackageInstanceRef ref = conn.srcTemplatePackageInstanceDecl_end ();
  PICML::TemplatePackageInstance inst = ref.ref ();

  // First, get the scope of the template instance.
  std::string prefix = _scope (inst, separator, leading);
  prefix += std::string (inst.name ());

  PICML::PackageType pt = inst.PackageType_child ();
  PICML::Package package = pt.ref ();

  // Now, get the scope of the object up to the template package.
  prefix += _scope (object, separator, true, package);
  return prefix;
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
// fq_type
//
std::string fq_type (const PICML::Exception & ex,
                     const std::string & separator,
                     bool leading)
{
  std::ostringstream fq_name;
  fq_name << scope (ex, separator, leading) << ex.name ();

  return fq_name.str ();
}

//
// fq_type
//
std::string fq_type (const PICML::Package & p,
                     const std::string & separator,
                     bool leading)
{
  std::ostringstream fq_name;
  fq_name << scope (p, separator, leading) << p.name ();

  return fq_name.str ();
}

//
// fq_type
//
std::string fq_type (const PICML::TemplatePackageRefContainerFCO & fco,
                     const PICML::MgaObject & object,
                     const std::string & separator,
                     bool leading)
{
  std::string fq_name (scope (fco, object, separator, leading));
  fq_name += object.name ();

  return fq_name;
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
