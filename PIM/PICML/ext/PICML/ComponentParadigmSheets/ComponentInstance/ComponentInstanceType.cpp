// $Id$

#include "StdAfx.h"
#include "ComponentInstanceType.h"

#if !defined (__GAME_INLINE__)
#include "ComponentInstanceType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentInstanceType_Impl::metaname ("ComponentInstanceType");

  //
  // is_abstract
  //
  const bool ComponentInstanceType_Impl::is_abstract = false;

  //
  // _create (const ComponentInstance_in)
  //
  ComponentInstanceType ComponentInstanceType_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create < ComponentInstanceType > (parent, ComponentInstanceType_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentInstanceType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentInstanceType (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ComponentInstance
  //
  ComponentInstance ComponentInstanceType_Impl::parent_ComponentInstance (void)
  {
    return ComponentInstance::_narrow (this->parent ());
  }

  //
  // MonolithicImplementation_is_nil
  //
  bool ComponentInstanceType_Impl::MonolithicImplementation_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_MonolithicImplementation
  //
  void ComponentInstanceType_Impl::refers_to_MonolithicImplementation (MonolithicImplementation_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_MonolithicImplementation
  //
  MonolithicImplementation ComponentInstanceType_Impl::refers_to_MonolithicImplementation (void) const
  {
    return MonolithicImplementation::_narrow (this->refers_to ());
  }
}

