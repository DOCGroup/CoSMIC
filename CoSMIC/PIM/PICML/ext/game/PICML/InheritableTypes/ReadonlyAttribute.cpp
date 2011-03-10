// $Id$

#include "stdafx.h"
#include "ReadonlyAttribute.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/GetException.h"
#include "PICML/InheritableTypes/AttributeMember.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ReadonlyAttribute_Impl::metaname = "ReadonlyAttribute";

  //
  // ReadonlyAttribute_Impl
  //
  ReadonlyAttribute_Impl::ReadonlyAttribute_Impl (void)
  {
  }

  //
  // ReadonlyAttribute_Impl
  //
  ReadonlyAttribute_Impl::ReadonlyAttribute_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ReadonlyAttribute_Impl
  //
  ReadonlyAttribute_Impl::~ReadonlyAttribute_Impl (void)
  {
  }

  //
  // accept
  //
  void ReadonlyAttribute_Impl::accept (Visitor * v)
  {
    v->visit_ReadonlyAttribute (this);
  }

  //
  // _create
  //
  ReadonlyAttribute ReadonlyAttribute_Impl::_create (const Inheritable_in parent)
  {
    return ::GAME::Mga::create_object <ReadonlyAttribute> (parent, ReadonlyAttribute_Impl::metaname);
  }

  //
  // get_GetExceptions
  //
  size_t ReadonlyAttribute_Impl::get_GetExceptions (std::vector <GetException> & items) const
  {
    return this->children (items);
  }

  //
  // get_AttributeMember
  //
  AttributeMember ReadonlyAttribute_Impl::get_AttributeMember (void) const
  {
    // Get the collection of children.
    std::vector <AttributeMember> items;
    this->children (items);

    return !items.empty () ? items.front () : AttributeMember ();
  }

  //
  // parent_Inheritable
  //
  Inheritable ReadonlyAttribute_Impl::parent_Inheritable (void) const
  {
    return ::GAME::Mga::get_parent <Inheritable> (this->object_.p);
  }
}

