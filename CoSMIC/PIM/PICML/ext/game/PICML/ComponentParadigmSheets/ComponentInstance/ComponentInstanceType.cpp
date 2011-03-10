// $Id$

#include "stdafx.h"
#include "ComponentInstanceType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInstanceType_Impl::metaname = "ComponentInstanceType";

  //
  // ComponentInstanceType_Impl
  //
  ComponentInstanceType_Impl::ComponentInstanceType_Impl (void)
  {
  }

  //
  // ComponentInstanceType_Impl
  //
  ComponentInstanceType_Impl::ComponentInstanceType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentInstanceType_Impl
  //
  ComponentInstanceType_Impl::~ComponentInstanceType_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentInstanceType_Impl::accept (Visitor * v)
  {
    v->visit_ComponentInstanceType (this);
  }

  //
  // _create
  //
  ComponentInstanceType ComponentInstanceType_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object <ComponentInstanceType> (parent, ComponentInstanceType_Impl::metaname);
  }

  //
  // parent_ComponentInstance
  //
  ComponentInstance ComponentInstanceType_Impl::parent_ComponentInstance (void) const
  {
    return ::GAME::Mga::get_parent <ComponentInstance> (this->object_.p);
  }
}

