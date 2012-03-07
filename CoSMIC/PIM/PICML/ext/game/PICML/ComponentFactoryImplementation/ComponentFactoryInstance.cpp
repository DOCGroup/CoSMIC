// $Id$

#include "StdAfx.h"
#include "ComponentFactoryInstance.h"

#if !defined (__GAME_INLINE__)
#include "ComponentFactoryInstance.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentFactoryInstance_Impl::metaname ("ComponentFactoryInstance");

  //
  // _create (const ComponentFactoryImplementationContainer_in)
  //
  ComponentFactoryInstance ComponentFactoryInstance_Impl::_create (const ComponentFactoryImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentFactoryInstance > (parent, ComponentFactoryInstance_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentFactoryInstance_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentFactoryInstance (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // ComponentFactory_is_nil
  //
  bool ComponentFactoryInstance_Impl::ComponentFactory_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ComponentFactory
  //
  ComponentFactory ComponentFactoryInstance_Impl::get_ComponentFactory (void) const
  {
    return ComponentFactory::_narrow (this->refers_to ());
  }

  //
  // ComponentFactoryInstance_is_nil
  //
  bool ComponentFactoryInstance_Impl::ComponentFactoryInstance_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ComponentFactoryInstance
  //
  ComponentFactoryInstance ComponentFactoryInstance_Impl::get_ComponentFactoryInstance (void) const
  {
    return ComponentFactoryInstance::_narrow (this->refers_to ());
  }
}

