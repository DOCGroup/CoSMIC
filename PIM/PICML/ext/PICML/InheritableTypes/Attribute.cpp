// $Id$

#include "StdAfx.h"
#include "Attribute.h"

#if !defined (__GAME_INLINE__)
#include "Attribute.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/SetException.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Attribute_Impl::metaname ("Attribute");

  //
  // is_abstract
  //
  const bool Attribute_Impl::is_abstract = false;

  //
  // _create (const Inheritable_in)
  //
  Attribute Attribute_Impl::_create (const Inheritable_in parent)
  {
    return ::GAME::Mga::create < Attribute > (parent, Attribute_Impl::metaname);
  }

  //
  // _create (const Component_in)
  //
  Attribute Attribute_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create < Attribute > (parent, Attribute_Impl::metaname);
  }

  //
  // _create (const PortType_in)
  //
  Attribute Attribute_Impl::_create (const PortType_in parent)
  {
    return ::GAME::Mga::create < Attribute > (parent, Attribute_Impl::metaname);
  }

  //
  // _create (const ConnectorObject_in)
  //
  Attribute Attribute_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create < Attribute > (parent, Attribute_Impl::metaname);
  }

  //
  // accept
  //
  void Attribute_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Attribute (this);
    else
      v->visit_Model (this);
  }

  //
  // get_SetExceptions
  //
  size_t Attribute_Impl::get_SetExceptions (std::vector <SetException> & items) const
  {
    return this->children (items);
  }

  //
  // get_SetExceptions
  //
  ::GAME::Mga::Collection_T <SetException> Attribute_Impl::get_SetExceptions (void) const
  {
    return this->children <SetException> ();
  }
}

