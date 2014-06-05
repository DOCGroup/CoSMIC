// $Id$

#include "StdAfx.h"
#include "Inheritable.h"

#if !defined (__GAME_INLINE__)
#include "Inheritable.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Inherits.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"

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
  ::GAME::Mga::Collection_T <Inherits> Inheritable_Impl::get_Inheritss (void) const
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
  ::GAME::Mga::Collection_T <ReadonlyAttribute> Inheritable_Impl::get_ReadonlyAttributes (void) const
  {
    return this->children <ReadonlyAttribute> ();
  }

  //
  // get_Attributes
  //
  size_t Inheritable_Impl::get_Attributes (std::vector <Attribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_Attributes
  //
  ::GAME::Mga::Collection_T <Attribute> Inheritable_Impl::get_Attributes (void) const
  {
    return this->children <Attribute> ();
  }
}

