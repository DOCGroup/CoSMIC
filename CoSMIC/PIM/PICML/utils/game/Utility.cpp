// $Id$

#include "Utility.h"
#include "game/MetaBase.h"
#include <stack>

namespace PICML
{
namespace GAME
{
//
// scope
//
std::string scope (const GME::Model & named_type,
                   const std::string & separator,
                   bool leading)
{
  std::string scope;
  std::stack <GME::Object> temp_stack;

  // Continue walking up the tree until we reach a File object.
  GME::Object parent = named_type.parent ();

  while (parent.meta ().name () == "Package")
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
std::string fq_type (const GME::Model & named_type,
                     const std::string & separator,
                     bool leading)
{
  return
    scope (named_type, separator, leading) +
    named_type.name ();
}

}
}
