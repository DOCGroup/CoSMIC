// $Id$

#include "StdAfx.h"
#include "ComponentConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "ComponentConfigProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentContainer.h"
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
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentConfigProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentContainer
  //
  ComponentContainer ComponentConfigProperty_Impl::parent_ComponentContainer (void)
  {
    return ComponentContainer::_narrow (this->parent ());
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

