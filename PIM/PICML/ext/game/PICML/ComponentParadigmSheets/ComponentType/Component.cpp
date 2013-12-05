// $Id$

#include "StdAfx.h"
#include "Component.h"

#if !defined (__GAME_INLINE__)
#include "Component.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "PICML/ComponentParadigmSheets/ComponentType/MirrorPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentInherits.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Port.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/ComponentBenchmark/CompRef.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
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
  // _create (const File_in)
  //
  Component Component_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < Component > (parent, Component_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  Component Component_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < Component > (parent, Component_Impl::metaname);
  }

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

  //
  // get_Attributes
  //
  size_t Component_Impl::get_Attributes (std::vector <Attribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_Attributes
  //
  ::GAME::Mga::Iterator <Attribute> Component_Impl::get_Attributes (void) const
  {
    return this->children <Attribute> ();
  }

  //
  // get_MirrorPorts
  //
  size_t Component_Impl::get_MirrorPorts (std::vector <MirrorPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_MirrorPorts
  //
  ::GAME::Mga::Iterator <MirrorPort> Component_Impl::get_MirrorPorts (void) const
  {
    return this->children <MirrorPort> ();
  }

  //
  // get_ExtendedPorts
  //
  size_t Component_Impl::get_ExtendedPorts (std::vector <ExtendedPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ExtendedPorts
  //
  ::GAME::Mga::Iterator <ExtendedPort> Component_Impl::get_ExtendedPorts (void) const
  {
    return this->children <ExtendedPort> ();
  }

  //
  // get_RequiredRequestPorts
  //
  size_t Component_Impl::get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequiredRequestPorts
  //
  ::GAME::Mga::Iterator <RequiredRequestPort> Component_Impl::get_RequiredRequestPorts (void) const
  {
    return this->children <RequiredRequestPort> ();
  }

  //
  // get_ProvidedRequestPorts
  //
  size_t Component_Impl::get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ProvidedRequestPorts
  //
  ::GAME::Mga::Iterator <ProvidedRequestPort> Component_Impl::get_ProvidedRequestPorts (void) const
  {
    return this->children <ProvidedRequestPort> ();
  }

  //
  // get_InEventPorts
  //
  size_t Component_Impl::get_InEventPorts (std::vector <InEventPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_InEventPorts
  //
  ::GAME::Mga::Iterator <InEventPort> Component_Impl::get_InEventPorts (void) const
  {
    return this->children <InEventPort> ();
  }

  //
  // get_OutEventPorts
  //
  size_t Component_Impl::get_OutEventPorts (std::vector <OutEventPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_OutEventPorts
  //
  ::GAME::Mga::Iterator <OutEventPort> Component_Impl::get_OutEventPorts (void) const
  {
    return this->children <OutEventPort> ();
  }
}

