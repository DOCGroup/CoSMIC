// $Id$

#include "stdafx.h"
#include "PackageInterface.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageInterface_Impl::metaname = "PackageInterface";

  //
  // PackageInterface_Impl
  //
  PackageInterface_Impl::PackageInterface_Impl (void)
  {
  }

  //
  // PackageInterface_Impl
  //
  PackageInterface_Impl::PackageInterface_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageInterface_Impl
  //
  PackageInterface_Impl::~PackageInterface_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageInterface_Impl::accept (Visitor * v)
  {
    v->visit_PackageInterface (this);
  }

  //
  // _create
  //
  PackageInterface PackageInterface_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageInterface> (parent, PackageInterface_Impl::metaname);
  }

  //
  // src_ComponentPackage
  //
  ComponentPackage PackageInterface_Impl::src_ComponentPackage (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentPackage::_narrow (target);
  }

  //
  // dst_ComponentRef
  //
  ComponentRef PackageInterface_Impl::dst_ComponentRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ComponentRef::_narrow (target);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer PackageInterface_Impl::parent_PackageContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageContainer> (this->object_.p);
  }
}

