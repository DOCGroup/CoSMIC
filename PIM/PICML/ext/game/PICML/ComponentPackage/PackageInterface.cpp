// $Id$

#include "StdAfx.h"
#include "PackageInterface.h"

#if !defined (__GAME_INLINE__)
#include "PackageInterface.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageInterface_Impl::metaname ("PackageInterface");

  //
  // _create (const PackageContainer_in)
  //
  PackageInterface PackageInterface_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageInterface > (parent, PackageInterface_Impl::metaname);
  }

  //
  // accept
  //
  void PackageInterface_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageInterface (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer PackageInterface_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // ComponentPackage
  //
  ComponentPackage PackageInterface_Impl::src_ComponentPackage (void) const
  {
    return ComponentPackage::_narrow (this->src ());
  }

  //
  // ComponentRef
  //
  ComponentRef PackageInterface_Impl::dst_ComponentRef (void) const
  {
    return ComponentRef::_narrow (this->dst ());
  }
}
