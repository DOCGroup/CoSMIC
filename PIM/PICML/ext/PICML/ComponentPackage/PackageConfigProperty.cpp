// $Id$

#include "StdAfx.h"
#include "PackageConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfigProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfigProperty_Impl::metaname ("PackageConfigProperty");

  //
  // is_abstract
  //
  const bool PackageConfigProperty_Impl::is_abstract (0);

  //
  // _create (const PackageContainer_in, ComponentPackage_in src, Property_in dst)
  //
  PackageConfigProperty PackageConfigProperty_Impl::_create (const PackageContainer_in parent, ComponentPackage_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PackageConfigProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PackageConfigProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfigProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer PackageConfigProperty_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // ComponentPackage
  //
  ComponentPackage PackageConfigProperty_Impl::src_ComponentPackage (void) const
  {
    return ComponentPackage::_narrow (this->src ());
  }

  //
  // Property
  //
  Property PackageConfigProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

