// $Id$

#include "StdAfx.h"
#include "ComponentInfoProperty.h"

#if !defined (__GAME_INLINE__)
#include "ComponentInfoProperty.inl"
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
  const std::string ComponentInfoProperty_Impl::metaname ("ComponentInfoProperty");

  //
  // _create (const ComponentContainer_in)
  //
  ComponentInfoProperty ComponentInfoProperty_Impl::_create (const ComponentContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentInfoProperty > (parent, ComponentInfoProperty_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentInfoProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentInfoProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // ComponentRef
  //
  ComponentRef ComponentInfoProperty_Impl::src_ComponentRef (void) const
  {
    return ComponentRef::_narrow (this->src ());
  }

  //
  // Property
  //
  Property ComponentInfoProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

