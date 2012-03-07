// $Id$

#include "StdAfx.h"
#include "Inheritable.h"

#if !defined (__GAME_INLINE__)
#include "Inheritable.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Inherits.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Inheritable_Impl::metaname ("Inheritable");

  //
  // get_Inheritss
  //
  size_t Inheritable_Impl::get_Inheritss (std::vector <Inherits> & items) const
  {
    return this->children (items);
  }

  //
  // get_Inheritss
  //
  ::GAME::Mga::Iterator <Inherits> Inheritable_Impl::get_Inheritss (void) const
  {
    return this->children <Inherits> ();
  }

  //
  // get_ReadonlyAttributes
  //
  size_t Inheritable_Impl::get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReadonlyAttributes
  //
  ::GAME::Mga::Iterator <ReadonlyAttribute> Inheritable_Impl::get_ReadonlyAttributes (void) const
  {
    return this->children <ReadonlyAttribute> ();
  }
}

