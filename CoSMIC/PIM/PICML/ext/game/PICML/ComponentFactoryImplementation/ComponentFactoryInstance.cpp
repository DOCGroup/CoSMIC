// $Id$

#include "stdafx.h"
#include "ComponentFactoryInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryInstance_Impl::metaname = "ComponentFactoryInstance";

  //
  // ComponentFactoryInstance_Impl
  //
  ComponentFactoryInstance_Impl::ComponentFactoryInstance_Impl (void)
  {
  }

  //
  // ComponentFactoryInstance_Impl
  //
  ComponentFactoryInstance_Impl::ComponentFactoryInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactoryInstance_Impl
  //
  ComponentFactoryInstance_Impl::~ComponentFactoryInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentFactoryInstance_Impl::accept (Visitor * v)
  {
    v->visit_ComponentFactoryInstance (this);
  }

  //
  // _create
  //
  ComponentFactoryInstance ComponentFactoryInstance_Impl::_create (const ComponentFactoryImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <ComponentFactoryInstance> (parent, ComponentFactoryInstance_Impl::metaname);
  }

  //
  // parent_ComponentFactoryImplementationContainer
  //
  ComponentFactoryImplementationContainer ComponentFactoryInstance_Impl::parent_ComponentFactoryImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentFactoryImplementationContainer> (this->object_.p);
  }
}

