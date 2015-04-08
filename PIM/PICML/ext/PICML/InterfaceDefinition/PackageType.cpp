#include "StdAfx.h"
#include "PackageType.h"

#if !defined (__GAME_INLINE__)
#include "PackageType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageType_Impl::metaname ("PackageType");

  //
  // is_abstract
  //
  const bool PackageType_Impl::is_abstract = false;

  //
  // _create (const TemplatePackageAlias_in)
  //
  PackageType PackageType_Impl::_create (const TemplatePackageAlias_in parent)
  {
    return ::GAME::Mga::create < PackageType > (parent, PackageType_Impl::metaname);
  }

  //
  // _create (const TemplatePackageInstance_in)
  //
  PackageType PackageType_Impl::_create (const TemplatePackageInstance_in parent)
  {
    return ::GAME::Mga::create < PackageType > (parent, PackageType_Impl::metaname);
  }

  //
  // accept
  //
  void PackageType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageType (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_TemplatePackageAlias
  //
  TemplatePackageAlias PackageType_Impl::parent_TemplatePackageAlias (void)
  {
    return TemplatePackageAlias::_narrow (this->parent ());
  }

  //
  // parent_TemplatePackageInstance
  //
  TemplatePackageInstance PackageType_Impl::parent_TemplatePackageInstance (void)
  {
    return TemplatePackageInstance::_narrow (this->parent ());
  }

  //
  // Package_is_nil
  //
  bool PackageType_Impl::Package_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_Package
  //
  void PackageType_Impl::refers_to_Package (Package_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Package
  //
  Package PackageType_Impl::refers_to_Package (void) const
  {
    return Package::_narrow (this->refers_to ());
  }
}

