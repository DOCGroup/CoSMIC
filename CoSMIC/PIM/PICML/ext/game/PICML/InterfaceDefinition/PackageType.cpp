// $Id$

#include "stdafx.h"
#include "PackageType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/Package.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageType_Impl::metaname = "PackageType";

  //
  // PackageType_Impl
  //
  PackageType_Impl::PackageType_Impl (void)
  {
  }

  //
  // PackageType_Impl
  //
  PackageType_Impl::PackageType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageType_Impl
  //
  PackageType_Impl::~PackageType_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageType_Impl::accept (Visitor * v)
  {
    v->visit_PackageType (this);
  }

  //
  // _create
  //
  PackageType PackageType_Impl::_create (const TemplatePackageInstance_in parent)
  {
    return ::GAME::Mga::create_object <PackageType> (parent, PackageType_Impl::metaname);
  }

  //
  // parent_TemplatePackageInstance
  //
  TemplatePackageInstance PackageType_Impl::parent_TemplatePackageInstance (void) const
  {
    return ::GAME::Mga::get_parent <TemplatePackageInstance> (this->object_.p);
  }

  //
  // refers_to_Package
  //
  Package PackageType_Impl::refers_to_Package (void) const
  {
    return ::GAME::Mga::get_refers_to <Package> (this);
  }
}

