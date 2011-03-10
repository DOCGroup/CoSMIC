// $Id$

#include "stdafx.h"
#include "AttributeMember.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeMember_Impl::metaname = "AttributeMember";

  //
  // AttributeMember_Impl
  //
  AttributeMember_Impl::AttributeMember_Impl (void)
  {
  }

  //
  // AttributeMember_Impl
  //
  AttributeMember_Impl::AttributeMember_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeMember_Impl
  //
  AttributeMember_Impl::~AttributeMember_Impl (void)
  {
  }

  //
  // accept
  //
  void AttributeMember_Impl::accept (Visitor * v)
  {
    v->visit_AttributeMember (this);
  }

  //
  // _create
  //
  AttributeMember AttributeMember_Impl::_create (const ReadonlyAttribute_in parent)
  {
    return ::GAME::Mga::create_object <AttributeMember> (parent, AttributeMember_Impl::metaname);
  }

  //
  // parent_ReadonlyAttribute
  //
  ReadonlyAttribute AttributeMember_Impl::parent_ReadonlyAttribute (void) const
  {
    return ::GAME::Mga::get_parent <ReadonlyAttribute> (this->object_.p);
  }
}

