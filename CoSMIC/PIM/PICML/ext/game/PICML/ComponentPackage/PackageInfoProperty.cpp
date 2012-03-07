// $Id$

#include "StdAfx.h"
#include "PackageInfoProperty.h"

#if !defined (__GAME_INLINE__)
#include "PackageInfoProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/ComponentPackage/PackageContainer.h"
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
  // _create (const PackageContainer_in)
  //
  PackageInfoProperty PackageInfoProperty_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageInfoProperty > (parent, PackageInfoProperty_Impl::metaname);
  }

  //
  // accept
  //
  void PackageInfoProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PackageInfoProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

