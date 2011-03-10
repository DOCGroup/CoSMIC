// $Id$

#include "stdafx.h"
#include "Implementation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Implementation_Impl::metaname = "Implementation";

  //
  // Implementation_Impl
  //
  Implementation_Impl::Implementation_Impl (void)
  {
  }

  //
  // Implementation_Impl
  //
  Implementation_Impl::Implementation_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Implementation_Impl
  //
  Implementation_Impl::~Implementation_Impl (void)
  {
  }

  //
  // accept
  //
  void Implementation_Impl::accept (Visitor * v)
  {
    v->visit_Implementation (this);
  }

  //
  // _create
  //
  Implementation Implementation_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object <Implementation> (parent, Implementation_Impl::metaname);
  }

  //
  // src_ComponentPackage
  //
  ComponentPackage Implementation_Impl::src_ComponentPackage (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentPackage::_narrow (target);
  }

  //
  // dst_ComponentImplementationReference
  //
  ComponentImplementationReference Implementation_Impl::dst_ComponentImplementationReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ComponentImplementationReference::_narrow (target);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer Implementation_Impl::parent_PackageContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageContainer> (this->object_.p);
  }
}

