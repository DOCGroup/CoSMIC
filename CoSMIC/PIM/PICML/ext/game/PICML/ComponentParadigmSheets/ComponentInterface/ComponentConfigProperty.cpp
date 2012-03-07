// $Id$

#include "StdAfx.h"
#include "ComponentConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "ComponentConfigProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
#include "PICML/Common/Property.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentConfigProperty_Impl::metaname ("ComponentConfigProperty");

  //
  // _create (const ComponentContainer_in)
  //
  ComponentConfigProperty ComponentConfigProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentConfigProperty > (parent, ComponentConfigProperty_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentConfigProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ComponentConfigProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // ComponentRef
  //
  ComponentRef ComponentConfigProperty_Impl::src_ComponentRef (void) const
  {
    return ComponentRef::_narrow (this->src ());
  }

  //
  // Property
  //
  Property ComponentConfigProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

