// $Id$

#include "stdafx.h"
#include "Utility.h"
#include "game/mga/MetaBase.h"
#include "game/mga/MetaModel.h"
#include <stack>

namespace PICML
{
//
// scope
//
std::string scope (const GAME::Mga::FCO_in named_type,
                   const std::string & separator,
                   bool leading)
{
  std::string scope;
  std::stack <GAME::Mga::Object> temp_stack;

  // Continue walking up the tree until we reach a File object.
  static const std::string meta_File ("File");
  GAME::Mga::Object parent = named_type->parent ();

  while (parent->meta ()->name () != meta_File)
  {
    temp_stack.push (parent);
    parent = parent->parent ();
  }

  // Insert the leading separator, if applicable.
  if (leading)
    scope += separator;

  // Empty the remainder of the stack.
  while (!temp_stack.empty ())
  {
    parent = temp_stack.top ();
    temp_stack.pop ();

    scope += parent->name () + separator;
  }

  return scope;
}

//
// fq_type
//
std::string fq_type (const GAME::Mga::FCO_in named_type,
                     const std::string & separator,
                     bool leading)
{
  return
    scope (named_type, separator, leading) +
    named_type->name ();
}

//
// get_template_package_inst
//
GAME::Mga::Model get_template_package_inst (const GAME::Mga::FCO_in type)
{
  ::GAME::Mga::Model parent = type->parent_model ();
  static const std::string meta_File ("File");
  std::string metaname = parent->meta ()->name ();

  while (metaname != "File")
  {
    static const std::string meta_TemplatePackageInstance ("TemplatePackageInstance");

    // Make sure this is not a template package instance.
    if (metaname == meta_TemplatePackageInstance)
      return parent;

    // Move up the tree one more element.
    parent = parent->parent_model ();
    metaname = parent->meta ()->name ();
  }

  return GAME::Mga::Model ();
}

}
