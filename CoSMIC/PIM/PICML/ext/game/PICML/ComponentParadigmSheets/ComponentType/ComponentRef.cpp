// $Id$

#include "stdafx.h"
#include "ComponentRef.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentRef_Impl::metaname = "ComponentRef";

  //
  // ComponentRef_Impl
  //
  ComponentRef_Impl::ComponentRef_Impl (void)
  {
  }

  //
  // ComponentRef_Impl
  //
  ComponentRef_Impl::ComponentRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentRef_Impl
  //
  ComponentRef_Impl::~ComponentRef_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentRef_Impl::accept (Visitor * v)
  {
    v->visit_ComponentRef (this);
  }

  //
  // refers_to_Component
  //
  Component ComponentRef_Impl::refers_to_Component (void) const
  {
    return ::GAME::Mga::get_refers_to <Component> (this);
  }
}

