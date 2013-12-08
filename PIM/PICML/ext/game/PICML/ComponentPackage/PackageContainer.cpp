// $Id$

#include "StdAfx.h"
#include "PackageContainer.h"

#if !defined (__GAME_INLINE__)
#include "PackageContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentPackage/PackageConfigProperty.h"
#include "PICML/ComponentPackage/PackageInfoProperty.h"
#include "PICML/ComponentPackage/Implementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/ComponentPackage/PackageInterface.h"
#include "PICML/ComponentPackage/ComponentPackages.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageContainer_Impl::metaname ("PackageContainer");

  //
  // _create (const ComponentPackages_in)
  //
  PackageContainer PackageContainer_Impl::_create (const ComponentPackages_in parent)
  {
    return ::GAME::Mga::create_root_object < PackageContainer > (parent, PackageContainer_Impl::metaname);
  }

  //
  // accept
  //
  void PackageContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentPackages
  //
  ComponentPackages PackageContainer_Impl::parent_ComponentPackages (void)
  {
    return ComponentPackages::_narrow (this->parent ());
  }

  //
  // has_ComponentPackage
  //
  bool PackageContainer_Impl::has_ComponentPackage (void) const
  {
    return this->children <ComponentPackage> ().count () == 1;
  }

  //
  // get_ComponentPackage
  //
  ComponentPackage PackageContainer_Impl::get_ComponentPackage (void) const
  {
    return this->children <ComponentPackage> ().item ();
  }

  //
  // has_ComponentRef
  //
  bool PackageContainer_Impl::has_ComponentRef (void) const
  {
    return this->children <ComponentRef> ().count () == 1;
  }

  //
  // get_ComponentRef
  //
  ComponentRef PackageContainer_Impl::get_ComponentRef (void) const
  {
    return this->children <ComponentRef> ().item ();
  }

  //
  // has_PackageInterface
  //
  bool PackageContainer_Impl::has_PackageInterface (void) const
  {
    return this->children <PackageInterface> ().count () == 1;
  }

  //
  // get_PackageInterface
  //
  PackageInterface PackageContainer_Impl::get_PackageInterface (void) const
  {
    return this->children <PackageInterface> ().item ();
  }

  //
  // get_PackageConfigPropertys
  //
  size_t PackageContainer_Impl::get_PackageConfigPropertys (std::vector <PackageConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageConfigPropertys
  //
  ::GAME::Mga::Iterator <PackageConfigProperty> PackageContainer_Impl::get_PackageConfigPropertys (void) const
  {
    return this->children <PackageConfigProperty> ();
  }

  //
  // get_PackageInfoPropertys
  //
  size_t PackageContainer_Impl::get_PackageInfoPropertys (std::vector <PackageInfoProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageInfoPropertys
  //
  ::GAME::Mga::Iterator <PackageInfoProperty> PackageContainer_Impl::get_PackageInfoPropertys (void) const
  {
    return this->children <PackageInfoProperty> ();
  }

  //
  // get_Implementations
  //
  size_t PackageContainer_Impl::get_Implementations (std::vector <Implementation> & items) const
  {
    return this->children (items);
  }

  //
  // get_Implementations
  //
  ::GAME::Mga::Iterator <Implementation> PackageContainer_Impl::get_Implementations (void) const
  {
    return this->children <Implementation> ();
  }

  //
  // get_ComponentImplementationReferences
  //
  size_t PackageContainer_Impl::get_ComponentImplementationReferences (std::vector <ComponentImplementationReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentImplementationReferences
  //
  ::GAME::Mga::Iterator <ComponentImplementationReference> PackageContainer_Impl::get_ComponentImplementationReferences (void) const
  {
    return this->children <ComponentImplementationReference> ();
  }

  //
  // get_ComplexPropertys
  //
  size_t PackageContainer_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Iterator <ComplexProperty> PackageContainer_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t PackageContainer_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Iterator <SimpleProperty> PackageContainer_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
  }
}
