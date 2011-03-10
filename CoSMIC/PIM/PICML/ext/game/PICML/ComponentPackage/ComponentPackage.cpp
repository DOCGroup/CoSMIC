// $Id$

#include "stdafx.h"
#include "ComponentPackage.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/PackageConfigProperty.h"
#include "PICML/ComponentPackage/PackageInterface.h"
#include "PICML/ComponentPackage/PackageInfoProperty.h"
#include "PICML/ComponentPackage/Implementation.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentPackage_Impl::metaname = "ComponentPackage";

  //
  // ComponentPackage_Impl
  //
  ComponentPackage_Impl::ComponentPackage_Impl (void)
  {
  }

  //
  // ComponentPackage_Impl
  //
  ComponentPackage_Impl::ComponentPackage_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentPackage_Impl
  //
  ComponentPackage_Impl::~ComponentPackage_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentPackage_Impl::accept (Visitor * v)
  {
    v->visit_ComponentPackage (this);
  }

  //
  // _create
  //
  ComponentPackage ComponentPackage_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object <ComponentPackage> (parent, ComponentPackage_Impl::metaname);
  }

  //
  // in_PackageConfigProperty_connections
  //
  size_t ComponentPackage_Impl::in_PackageConfigProperty_connections (std::vector <PackageConfigProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_PackageInterface_connections
  //
  size_t ComponentPackage_Impl::in_PackageInterface_connections (std::vector <PackageInterface> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_PackageInfoProperty_connections
  //
  size_t ComponentPackage_Impl::in_PackageInfoProperty_connections (std::vector <PackageInfoProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_Implementation_connections
  //
  size_t ComponentPackage_Impl::in_Implementation_connections (std::vector <Implementation> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer ComponentPackage_Impl::parent_PackageContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageContainer> (this->object_.p);
  }
}

