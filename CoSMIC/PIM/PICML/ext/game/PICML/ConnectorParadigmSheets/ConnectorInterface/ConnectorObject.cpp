// $Id$

#include "StdAfx.h"
#include "ConnectorObject.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorObject.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorInherits.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorObject_Impl::metaname ("ConnectorObject");

  //
  // accept
  //
  void ConnectorObject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ConnectorObject (this);
    else
      v->visit_Model (this);
  }

  //
  // has_ConnectorInherits
  //
  bool ConnectorObject_Impl::has_ConnectorInherits (void) const
  {
    return this->children <ConnectorInherits> ().count () == 1;
  }

  //
  // get_ConnectorInherits
  //
  ConnectorInherits ConnectorObject_Impl::get_ConnectorInherits (void) const
  {
    return this->children <ConnectorInherits> ().item ();
  }

  //
  // get_ObjectPorts
  //
  size_t ConnectorObject_Impl::get_ObjectPorts (std::vector <ObjectPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ObjectPorts
  //
  ::GAME::Mga::Iterator <ObjectPort> ConnectorObject_Impl::get_ObjectPorts (void) const
  {
    return this->children <ObjectPort> ();
  }

  //
  // get_ExtendedPortBases
  //
  size_t ConnectorObject_Impl::get_ExtendedPortBases (std::vector <ExtendedPortBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedPortBases
  //
  ::GAME::Mga::Iterator <ExtendedPortBase> ConnectorObject_Impl::get_ExtendedPortBases (void) const
  {
    return this->children <ExtendedPortBase> ();
  }

  //
  // get_Aggregates
  //
  size_t ConnectorObject_Impl::get_Aggregates (std::vector <Aggregate> & items) const
  {
    return this->children (items);
  }

  //
  // get_Aggregates
  //
  ::GAME::Mga::Iterator <Aggregate> ConnectorObject_Impl::get_Aggregates (void) const
  {
    return this->children <Aggregate> ();
  }

  //
  // get_Collections
  //
  size_t ConnectorObject_Impl::get_Collections (std::vector <Collection> & items) const
  {
    return this->children (items);
  }

  //
  // get_Collections
  //
  ::GAME::Mga::Iterator <Collection> ConnectorObject_Impl::get_Collections (void) const
  {
    return this->children <Collection> ();
  }

  //
  // get_ReadonlyAttributes
  //
  size_t ConnectorObject_Impl::get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReadonlyAttributes
  //
  ::GAME::Mga::Iterator <ReadonlyAttribute> ConnectorObject_Impl::get_ReadonlyAttributes (void) const
  {
    return this->children <ReadonlyAttribute> ();
  }
}

