#include "StdAfx.h"
#include "AttributeValue.h"

#if !defined (__GAME_INLINE__)
#include "AttributeValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
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
  // is_abstract
  //
  const bool AttributeValue_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in, AttributeInstance_in src, Property_in dst)
  //
  AttributeValue AttributeValue_Impl::_create (const ComponentAssembly_in parent, AttributeInstance_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, AttributeValue_Impl::metaname, src, dst);
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

