// $Id$

#include "StdAfx.h"
#include "ConnectorObject.h"

#if !defined (__GAME_INLINE__)
#include "ConnectorObject.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorType.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorInherits.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "PICML/ComponentParadigmSheets/ComponentType/MirrorPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPort.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
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
  // is_abstract
  //
  const bool ConnectorObject_Impl::is_abstract = false;

  //
  // _create (const Package_in)
  //
  ConnectorObject ConnectorObject_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < ConnectorObject > (parent, ConnectorObject_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  ConnectorObject ConnectorObject_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create < ConnectorObject > (parent, ConnectorObject_Impl::metaname);
  }

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
    return this->children <ConnectorInherits> ().first ();
  }

  //
  // get_RequiredRequestPorts
  //
  size_t ConnectorObject_Impl::get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequiredRequestPorts
  //
  ::GAME::Mga::Collection_T <RequiredRequestPort> ConnectorObject_Impl::get_RequiredRequestPorts (void) const
  {
    return this->children <RequiredRequestPort> ();
  }

  //
  // get_ProvidedRequestPorts
  //
  size_t ConnectorObject_Impl::get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ProvidedRequestPorts
  //
  ::GAME::Mga::Collection_T <ProvidedRequestPort> ConnectorObject_Impl::get_ProvidedRequestPorts (void) const
  {
    return this->children <ProvidedRequestPort> ();
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
  ::GAME::Mga::Collection_T <Collection> ConnectorObject_Impl::get_Collections (void) const
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
  ::GAME::Mga::Collection_T <ReadonlyAttribute> ConnectorObject_Impl::get_ReadonlyAttributes (void) const
  {
    return this->children <ReadonlyAttribute> ();
  }

  //
  // get_Attributes
  //
  size_t ConnectorObject_Impl::get_Attributes (std::vector <Attribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_Attributes
  //
  ::GAME::Mga::Collection_T <Attribute> ConnectorObject_Impl::get_Attributes (void) const
  {
    return this->children <Attribute> ();
  }

  //
  // get_MirrorPorts
  //
  size_t ConnectorObject_Impl::get_MirrorPorts (std::vector <MirrorPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_MirrorPorts
  //
  ::GAME::Mga::Collection_T <MirrorPort> ConnectorObject_Impl::get_MirrorPorts (void) const
  {
    return this->children <MirrorPort> ();
  }

  //
  // get_ExtendedPorts
  //
  size_t ConnectorObject_Impl::get_ExtendedPorts (std::vector <ExtendedPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedPorts
  //
  ::GAME::Mga::Collection_T <ExtendedPort> ConnectorObject_Impl::get_ExtendedPorts (void) const
  {
    return this->children <ExtendedPort> ();
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
  ::GAME::Mga::Collection_T <Aggregate> ConnectorObject_Impl::get_Aggregates (void) const
  {
    return this->children <Aggregate> ();
  }
}

