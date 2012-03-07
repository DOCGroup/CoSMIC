// $Id$

#include "StdAfx.h"
#include "Implementation.h"

#if !defined (__GAME_INLINE__)
#include "Implementation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationReference.h"
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
  const std::string Implementation_Impl::metaname ("Implementation");

  //
  // _create (const PackageContainer_in)
  //
  Implementation Implementation_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < Implementation > (parent, Implementation_Impl::metaname);
  }

  //
  // accept
  //
  void Implementation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Implementation (this);
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

