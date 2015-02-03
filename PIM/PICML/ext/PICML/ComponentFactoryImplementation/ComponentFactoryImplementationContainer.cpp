// $Id$

#include "StdAfx.h"
#include "ComponentFactoryImplementationContainer.h"

#if !defined (__GAME_INLINE__)
#include "ComponentFactoryImplementationContainer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementations.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryImplementationContainer_Impl::metaname ("ComponentFactoryImplementationContainer");

  //
  // is_abstract
  //
  const bool ComponentFactoryImplementationContainer_Impl::is_abstract (0);

  //
  // _create (const ComponentFactoryImplementations_in)
  //
  ComponentFactoryImplementationContainer ComponentFactoryImplementationContainer_Impl::_create (const ComponentFactoryImplementations_in parent)
  {
    return ::GAME::Mga::create < ComponentFactoryImplementationContainer > (parent, ComponentFactoryImplementationContainer_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentFactoryImplementationContainer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentFactoryImplementationContainer (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentFactoryImplementations
  //
  ComponentFactoryImplementations ComponentFactoryImplementationContainer_Impl::parent_ComponentFactoryImplementations (void)
  {
    return ComponentFactoryImplementations::_narrow (this->parent ());
  }

  //
  // get_ComponentFactoryInstances
  //
  size_t ComponentFactoryImplementationContainer_Impl::get_ComponentFactoryInstances (std::vector <ComponentFactoryInstance> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComponentFactoryInstances
  //
  ::GAME::Mga::Collection_T <ComponentFactoryInstance> ComponentFactoryImplementationContainer_Impl::get_ComponentFactoryInstances (void) const
  {
    return this->children <ComponentFactoryInstance> ();
  }
}

