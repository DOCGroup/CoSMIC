// $Id$

#include "StdAfx.h"
#include "Component.h"

#if !defined (__GAME_INLINE__)
#include "Component.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentInherits.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Component_Impl::metaname ("Component");

  //
  // accept
  //
  void Component_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Component (this);
    else
      v->visit_Model (this);
  }

  //
  // has_ComponentInherits
  //
  bool Component_Impl::has_ComponentInherits (void) const
  {
    return this->children <ComponentInherits> ().count () == 1;
  }

  //
  // get_ComponentInherits
  //
  ComponentInherits Component_Impl::get_ComponentInherits (void) const
  {
    return this->children <ComponentInherits> ().item ();
  }

  //
  // get_Ports
  //
  size_t Component_Impl::get_Ports (std::vector <Port> & items) const
  {
    return this->children (items);
  }

  //
  // get_Ports
  //
  ::GAME::Mga::Iterator <Port> Component_Impl::get_Ports (void) const
  {
    return this->children <Port> ();
  }

  //
  // get_ExtendedPortBases
  //
  size_t Component_Impl::get_ExtendedPortBases (std::vector <ExtendedPortBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedPortBases
  //
  ::GAME::Mga::Iterator <ExtendedPortBase> Component_Impl::get_ExtendedPortBases (void) const
  {
    return this->children <ExtendedPortBase> ();
  }

  //
  // get_ReadonlyAttributes
  //
  size_t Component_Impl::get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReadonlyAttributes
  //
  ::GAME::Mga::Iterator <ReadonlyAttribute> Component_Impl::get_ReadonlyAttributes (void) const
  {
    return this->children <ReadonlyAttribute> ();
  }
}

