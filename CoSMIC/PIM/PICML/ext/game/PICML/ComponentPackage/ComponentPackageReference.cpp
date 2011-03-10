// $Id$

#include "stdafx.h"
#include "ComponentPackageReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/ComponentPackage.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentPackageReference_Impl::metaname = "ComponentPackageReference";

  //
  // ComponentPackageReference_Impl
  //
  ComponentPackageReference_Impl::ComponentPackageReference_Impl (void)
  {
  }

  //
  // ComponentPackageReference_Impl
  //
  ComponentPackageReference_Impl::ComponentPackageReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentPackageReference_Impl
  //
  ComponentPackageReference_Impl::~ComponentPackageReference_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentPackageReference_Impl::accept (Visitor * v)
  {
    v->visit_ComponentPackageReference (this);
  }

  //
  // refers_to_ComponentPackage
  //
  ComponentPackage ComponentPackageReference_Impl::refers_to_ComponentPackage (void) const
  {
    return ::GAME::Mga::get_refers_to <ComponentPackage> (this);
  }
}

