// $Id$

#include "StdAfx.h"
#include "ProvidedRequestPort.h"

#if !defined (__GAME_INLINE__)
#include "ProvidedRequestPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Provideable.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/PredefinedTypes/GenericObject.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ProvidedRequestPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/PathDiagram/Path.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPort_Impl::metaname ("ProvidedRequestPort");

  //
  // _create (const PortType_in)
  //
  ProvidedRequestPort ProvidedRequestPort_Impl::_create (const PortType_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPort > (parent, ProvidedRequestPort_Impl::metaname);
  }

  //
  // _create (const ConnectorObject_in)
  //
  ProvidedRequestPort ProvidedRequestPort_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPort > (parent, ProvidedRequestPort_Impl::metaname);
  }

  //
  // _create (const Component_in)
  //
  ProvidedRequestPort ProvidedRequestPort_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPort > (parent, ProvidedRequestPort_Impl::metaname);
  }

  //
  // _create (const ConnectedComponent_in)
  //
  ProvidedRequestPort ProvidedRequestPort_Impl::_create (const ConnectedComponent_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPort > (parent, ProvidedRequestPort_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  ProvidedRequestPort ProvidedRequestPort_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < ProvidedRequestPort > (parent, ProvidedRequestPort_Impl::metaname);
  }

  //
  // accept
  //
  void ProvidedRequestPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ProvidedRequestPort (this);
    else
      v->visit_Reference (this);
  }

  //
  // Provideable_is_nil
  //
  bool ProvidedRequestPort_Impl::Provideable_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_Provideable
  //
  void ProvidedRequestPort_Impl::set_Provideable (Provideable_in item)
  {
    this->refers_to (item);
  }

  //
  // get_Provideable
  //
  Provideable ProvidedRequestPort_Impl::get_Provideable (void) const
  {
    return Provideable::_narrow (this->refers_to ());
  }
}

