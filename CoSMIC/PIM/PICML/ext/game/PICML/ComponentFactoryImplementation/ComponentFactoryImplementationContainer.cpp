// $Id$

#include "stdafx.h"
#include "ComponentFactoryImplementationContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementations.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryImplementationContainer_Impl::metaname = "ComponentFactoryImplementationContainer";

  //
  // ComponentFactoryImplementationContainer_Impl
  //
  ComponentFactoryImplementationContainer_Impl::ComponentFactoryImplementationContainer_Impl (void)
  {
  }

  //
  // ComponentFactoryImplementationContainer_Impl
  //
  ComponentFactoryImplementationContainer_Impl::ComponentFactoryImplementationContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentFactoryImplementationContainer_Impl
  //
  ComponentFactoryImplementationContainer_Impl::~ComponentFactoryImplementationContainer_Impl (void)
  {
  }

  //
  // accept
  //
  void ComponentFactoryImplementationContainer_Impl::accept (Visitor * v)
  {
    v->visit_ComponentFactoryImplementationContainer (this);
  }

  //
  // _create
  //
  ComponentFactoryImplementationContainer ComponentFactoryImplementationContainer_Impl::_create (const ComponentFactoryImplementations_in parent)
  {
    return ::GAME::Mga::create_root_object <ComponentFactoryImplementationContainer> (parent, ComponentFactoryImplementationContainer_Impl::metaname);
  }

  //
  // get_ComponentFactoryInstances
  //
  size_t ComponentFactoryImplementationContainer_Impl::get_ComponentFactoryInstances (std::vector <ComponentFactoryInstance> & items) const
  {
    return this->children (items);
  }

  //
  // parent_ComponentFactoryImplementations
  //
  ComponentFactoryImplementations ComponentFactoryImplementationContainer_Impl::parent_ComponentFactoryImplementations (void) const
  {
    return ::GAME::Mga::get_parent <ComponentFactoryImplementations> (this->object_.p);
  }
}

