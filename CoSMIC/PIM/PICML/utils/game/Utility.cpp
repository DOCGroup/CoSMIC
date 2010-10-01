// $Id$

#include "stdafx.h"
#include "Utility.h"
#include "game/MetaBase.h"
#include "game/MetaModel.h"
#include <stack>

namespace PICML
{
namespace GAME
{
//
// scope
//
std::string scope (const ::GAME::Model & named_type,
                   const std::string & separator,
                   bool leading)
{
  std::string scope;
  std::stack <::GAME::Object> temp_stack;

  // Continue walking up the tree until we reach a File object.
  static const std::string meta_File ("File");
  ::GAME::Object parent = named_type.parent ();

  while (parent.meta () != meta_File)
  {
    temp_stack.push (parent);
    parent = parent.parent ();
  }

  // Insert the leading separator, if applicable.
  if (leading)
    scope += separator;

  // Empty the remainder of the stack.
  while (!temp_stack.empty ())
  {
    parent = temp_stack.top ();
    temp_stack.pop ();

    scope += parent.name () + separator;
  }

  return scope;
}

//
// fq_type
//
std::string fq_type (const ::GAME::Model & named_type,
                     const std::string & separator,
                     bool leading)
{
  return
    scope (named_type, separator, leading) +
    named_type.name ();
}

//
// get_template_package_inst
//
::GAME::Model get_template_package_inst (const ::GAME::FCO & type)
{
  ::GAME::Model parent = type.parent_model ();
  ::GAME::Meta::Model metamodel = parent.meta ();

  static const std::string meta_File ("File");

  while (metamodel != "File")
  {
    static const std::string meta_TemplatePackageInstance ("TemplatePackageInstance");

    // Make sure this is not a template package instance.
    if (metamodel == meta_TemplatePackageInstance)
      return parent;

    // Move up the tree one more element.
    parent = parent.parent_model ();
    metamodel = parent.meta ();
  }

  return ::GAME::Model ();
}

}
}
