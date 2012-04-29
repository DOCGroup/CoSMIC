// $Id$

#include "StdAfx.h"
#include "PortType.h"

#if !defined (__GAME_INLINE__)
#include "PortType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PortType_Impl::metaname ("PortType");

  //
  // accept
  //
  void PortType_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PortType (this);
    else
      v->visit_Model (this);
  }

  //
  // get_ObjectPorts
  //
  size_t PortType_Impl::get_ObjectPorts (std::vector <ObjectPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ObjectPorts
  //
  ::GAME::Mga::Iterator <ObjectPort> PortType_Impl::get_ObjectPorts (void) const
  {
    return this->children <ObjectPort> ();
  }

  //
  // get_ReadonlyAttributes
  //
  size_t PortType_Impl::get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReadonlyAttributes
  //
  ::GAME::Mga::Iterator <ReadonlyAttribute> PortType_Impl::get_ReadonlyAttributes (void) const
  {
    return this->children <ReadonlyAttribute> ();
  }
}

