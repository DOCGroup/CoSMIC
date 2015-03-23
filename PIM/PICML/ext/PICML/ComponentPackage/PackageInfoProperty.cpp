// $Id$

#include "StdAfx.h"
#include "PackageInfoProperty.h"

#if !defined (__GAME_INLINE__)
#include "PackageInfoProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageInfoProperty_Impl::metaname ("PackageInfoProperty");

  //
  // is_abstract
  //
  const bool PackageInfoProperty_Impl::is_abstract = false;

  //
  // _create (const PackageContainer_in, ComponentPackage_in src, Property_in dst)
  //
  PackageInfoProperty PackageInfoProperty_Impl::_create (const PackageContainer_in parent, ComponentPackage_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PackageInfoProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PackageInfoProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageInfoProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer PackageInfoProperty_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // ComponentPackage
  //
  ComponentPackage PackageInfoProperty_Impl::src_ComponentPackage (void) const
  {
    return ComponentPackage::_narrow (this->src ());
  }

  //
  // Property
  //
  Property PackageInfoProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

