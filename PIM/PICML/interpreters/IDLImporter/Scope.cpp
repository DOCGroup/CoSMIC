#include "Scope.h"
#include <stack>

//
// scope
//
void Scope::
scope (const ::GAME::XME::FCO & named_type,
       const GAME::Xml::String & separator,
       bool leading,
       GAME::Xml::String & result)
{
  GAME::Xml::String tempstr;
  std::stack <GAME::XME::Object> temp_stack;

  // Continue walking up the tree until we reach a File object.
  GAME::XME::Object parent = named_type.parent ();

  static const GAME::Xml::String meta_Package ("Package");
  while (parent.kind () == meta_Package)
  {
    temp_stack.push (parent);
    parent = parent.parent ();
  }

  // Insert the leading separator, if applicable.
  if (leading)
    tempstr.append (separator);

  // Empty the remainder of the stack.
  while (!temp_stack.empty ())
  {
    parent = temp_stack.top ();
    temp_stack.pop ();

    tempstr.append (parent.name ());
    tempstr.append (separator);
  }

  result = tempstr;
}

//
// fq_name
//
void Scope::
fq_name (const ::GAME::XME::FCO & named_type,
         const GAME::Xml::String & separator,
         bool leading,
         GAME::Xml::String & result)
{
  Scope::scope (named_type, separator, leading, result);
  result.append (named_type.name ());
}
