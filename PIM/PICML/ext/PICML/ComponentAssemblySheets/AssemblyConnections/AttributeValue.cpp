// $Id$

#include "StdAfx.h"
#include "AttributeValue.h"

#if !defined (__GAME_INLINE__)
#include "AttributeValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeValue_Impl::metaname ("AttributeValue");

  //
  // _create (const ComponentAssembly_in)
  //
  AttributeValue AttributeValue_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < AttributeValue > (parent, AttributeValue_Impl::metaname);
  }

  //
  // accept
  //
  void AttributeValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AttributeValue (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly AttributeValue_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // AttributeInstance
  //
  AttributeInstance AttributeValue_Impl::src_AttributeInstance (void) const
  {
    return AttributeInstance::_narrow (this->src ());
  }

  //
  // Property
  //
  Property AttributeValue_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

