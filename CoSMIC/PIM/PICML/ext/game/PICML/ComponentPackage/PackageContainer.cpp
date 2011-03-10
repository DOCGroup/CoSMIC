// $Id$

#include "stdafx.h"
#include "PackageContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/PackageInfoProperty.h"
#include "PICML/Common/Property.h"
#include "PICML/ComponentPackage/PackageInterface.h"
#include "PICML/ComponentPackage/PackageConfigProperty.h"
#include "PICML/ComponentPackage/Implementation.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"
#include "PICML/ComponentPackage/ComponentPackages.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageContainer_Impl::metaname = "PackageContainer";

  //
  // PackageContainer_Impl
  //
  PackageContainer_Impl::PackageContainer_Impl (void)
  {
  }

  //
  // PackageContainer_Impl
  //
  PackageContainer_Impl::PackageContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageContainer_Impl
  //
  PackageContainer_Impl::~PackageContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageContainer_Impl::accept (Visitor * v)
  {
    v->visit_PackageContainer (this);
  }

  //
  // _create
  //
  PackageContainer PackageContainer_Impl::_create (const ComponentPackages_in parent)
  {
    return ::GAME::Mga::create_root_object <PackageContainer> (parent, PackageContainer_Impl::metaname);
  }

  //
  // get_PackageInfoPropertys
  //
  size_t PackageContainer_Impl::get_PackageInfoPropertys (std::vector <PackageInfoProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t PackageContainer_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageInterface
  //
  PackageInterface PackageContainer_Impl::get_PackageInterface (void) const
  {
    // Get the collection of children.
    std::vector <PackageInterface> items;
    this->children (items);

    return !items.empty () ? items.front () : PackageInterface ();
  }

  //
  // get_PackageConfigPropertys
  //
  size_t PackageContainer_Impl::get_PackageConfigPropertys (std::vector <PackageConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_Implementations
  //
  size_t PackageContainer_Impl::get_Implementations (std::vector <Implementation> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentPackage
  //
  ComponentPackage PackageContainer_Impl::get_ComponentPackage (void) const
  {
    // Get the collection of children.
    std::vector <ComponentPackage> items;
    this->children (items);

    return !items.empty () ? items.front () : ComponentPackage ();
  }

  //
  // get_ComponentRef
  //
  ComponentRef PackageContainer_Impl::get_ComponentRef (void) const
  {
    // Get the collection of children.
    std::vector <ComponentRef> items;
    this->children (items);

    return !items.empty () ? items.front () : ComponentRef ();
  }

  //
  // get_ComponentImplementationReferences
  //
  size_t PackageContainer_Impl::get_ComponentImplementationReferences (std::vector <ComponentImplementationReference> & items) const
  {
    return this->children (items);
  }

  //
  // parent_ComponentPackages
  //
  ComponentPackages PackageContainer_Impl::parent_ComponentPackages (void) const
  {
    return ::GAME::Mga::get_parent <ComponentPackages> (this->object_.p);
  }
}

