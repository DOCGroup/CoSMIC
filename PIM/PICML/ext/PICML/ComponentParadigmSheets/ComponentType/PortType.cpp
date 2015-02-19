// $Id$

#include "StdAfx.h"
#include "PortType.h"

#if !defined (__GAME_INLINE__)
#include "PortType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"
#include "PICML/InheritableTypes/Attribute.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "PICML/ComponentParadigmSheets/ComponentType/MirrorPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPort.h"
#include "PICML/InheritableTypes/HasOperations.h"
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
  const std::string PortType_Impl::metaname ("PortType");

  //
  // is_abstract
  //
  const bool PortType_Impl::is_abstract = false;

  //
  // _create (const HasOperations_in)
  //
  PortType PortType_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create < PortType > (parent, PortType_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  PortType PortType_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < PortType > (parent, PortType_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  PortType PortType_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create < PortType > (parent, PortType_Impl::metaname);
  }

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
  // get_RequiredRequestPorts
  //
  size_t PortType_Impl::get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequiredRequestPorts
  //
  ::GAME::Mga::Collection_T <RequiredRequestPort> PortType_Impl::get_RequiredRequestPorts (void) const
  {
    return this->children <RequiredRequestPort> ();
  }

  //
  // get_ProvidedRequestPorts
  //
  size_t PortType_Impl::get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const
  {
    return this->children (items);
  }

  //
  // get_ProvidedRequestPorts
  //
  ::GAME::Mga::Collection_T <ProvidedRequestPort> PortType_Impl::get_ProvidedRequestPorts (void) const
  {
    return this->children <ProvidedRequestPort> ();
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
  ::GAME::Mga::Collection_T <ReadonlyAttribute> PortType_Impl::get_ReadonlyAttributes (void) const
  {
    return this->children <ReadonlyAttribute> ();
  }

  //
  // get_Attributes
  //
  size_t PortType_Impl::get_Attributes (std::vector <Attribute> & items) const
  {
    return this->children (items);
  }

  //
  // get_Attributes
  //
  ::GAME::Mga::Collection_T <Attribute> PortType_Impl::get_Attributes (void) const
  {
    return this->children <Attribute> ();
  }
}

