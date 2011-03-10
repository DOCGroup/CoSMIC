// $Id$

#include "stdafx.h"
#include "Implements.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Implements_Impl::metaname = "Implements";

  //
  // Implements_Impl
  //
  Implements_Impl::Implements_Impl (void)
  {
  }

  //
  // Implements_Impl
  //
  Implements_Impl::Implements_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Implements_Impl
  //
  Implements_Impl::~Implements_Impl (void)
  {
  }

  //
  // accept
  //
  void Implements_Impl::accept (Visitor * v)
  {
    v->visit_Implements (this);
  }

  //
  // _create
  //
  Implements Implements_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <Implements> (parent, Implements_Impl::metaname);
  }

  //
  // src_ComponentImplementation
  //
  ComponentImplementation Implements_Impl::src_ComponentImplementation (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentImplementation::_narrow (target);
  }

  //
  // dst_ComponentRef
  //
  ComponentRef Implements_Impl::dst_ComponentRef (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ComponentRef::_narrow (target);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer Implements_Impl::parent_ComponentImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentImplementationContainer> (this->object_.p);
  }
}

