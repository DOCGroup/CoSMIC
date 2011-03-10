// $Id$

#include "stdafx.h"
#include "ComplexTypeReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/DataValueContainer.h"
#include "PICML/Common/ComplexType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComplexTypeReference_Impl::metaname = "ComplexTypeReference";

  //
  // ComplexTypeReference_Impl
  //
  ComplexTypeReference_Impl::ComplexTypeReference_Impl (void)
  {
  }

  //
  // ComplexTypeReference_Impl
  //
  ComplexTypeReference_Impl::ComplexTypeReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComplexTypeReference_Impl
  //
  ComplexTypeReference_Impl::~ComplexTypeReference_Impl (void)
  {
  }

  //
  // accept
  //
  void ComplexTypeReference_Impl::accept (Visitor * v)
  {
    v->visit_ComplexTypeReference (this);
  }

  //
  // _create
  //
  ComplexTypeReference ComplexTypeReference_Impl::_create (const ComplexProperty_in parent)
  {
    return ::GAME::Mga::create_object <ComplexTypeReference> (parent, ComplexTypeReference_Impl::metaname);
  }

  //
  // _create
  //
  ComplexTypeReference ComplexTypeReference_Impl::_create (const DataValueContainer_in parent)
  {
    return ::GAME::Mga::create_object <ComplexTypeReference> (parent, ComplexTypeReference_Impl::metaname);
  }

  //
  // parent_ComplexProperty
  //
  ComplexProperty ComplexTypeReference_Impl::parent_ComplexProperty (void) const
  {
    return ::GAME::Mga::get_parent <ComplexProperty> (this->object_.p);
  }

  //
  // parent_DataValueContainer
  //
  DataValueContainer ComplexTypeReference_Impl::parent_DataValueContainer (void) const
  {
    return ::GAME::Mga::get_parent <DataValueContainer> (this->object_.p);
  }

  //
  // refers_to_ComplexType
  //
  ComplexType ComplexTypeReference_Impl::refers_to_ComplexType (void) const
  {
    return ::GAME::Mga::get_refers_to <ComplexType> (this);
  }
}

