// $Id$

#include "StdAfx.h"
#include "PackageConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfigProperty.inl"
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
  const std::string PackageConfigProperty_Impl::metaname ("PackageConfigProperty");

  //
  // _create (const PackageContainer_in)
  //
  PackageConfigProperty PackageConfigProperty_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageConfigProperty > (parent, PackageConfigProperty_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfigProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PackageConfigProperty (this);
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

