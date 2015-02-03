// $Id$

#include "StdAfx.h"
#include "Implementation.h"

#if !defined (__GAME_INLINE__)
#include "Implementation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Implementation_Impl::metaname ("Implementation");

  //
  // is_abstract
  //
  const bool Implementation_Impl::is_abstract (0);

  //
  // _create (const PackageContainer_in, ComponentPackage_in src, ComponentImplementationReference_in dst)
  //
  Implementation Implementation_Impl::_create (const PackageContainer_in parent, ComponentPackage_in src, ComponentImplementationReference_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, Implementation_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void Implementation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Implementation (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer Implementation_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // ComponentPackage
  //
  ComponentPackage Implementation_Impl::src_ComponentPackage (void) const
  {
    return ComponentPackage::_narrow (this->src ());
  }

  //
  // ComponentImplementationReference
  //
  ComponentImplementationReference Implementation_Impl::dst_ComponentImplementationReference (void) const
  {
    return ComponentImplementationReference::_narrow (this->dst ());
  }
}

