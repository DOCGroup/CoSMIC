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
  // _create (const ComponentInstance_in)
  //
  ComponentInstanceType ComponentInstanceType_Impl::_create (const ComponentInstance_in parent)
  {
    return ::GAME::Mga::create_object < ComponentInstanceType > (parent, ComponentInstanceType_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentInstanceType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentInstanceType (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // MonolithicImplementation_is_nil
  //
  bool ComponentInstanceType_Impl::MonolithicImplementation_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_MonolithicImplementation
  //
  MonolithicImplementation ComponentInstanceType_Impl::get_MonolithicImplementation (void) const
  {
    return MonolithicImplementation::_narrow (this->refers_to ());
  }
}

