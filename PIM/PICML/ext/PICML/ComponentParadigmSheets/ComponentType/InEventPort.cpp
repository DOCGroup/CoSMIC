// $Id$

#include "StdAfx.h"
#include "InEventPort.h"

#if !defined (__GAME_INLINE__)
#include "InEventPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/InEventPortInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventType.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/PathDiagram/ConnectedComponent.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/PathDiagram/Path.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InEventPort_Impl::metaname ("InEventPort");

  //
  // is_abstract
  //
  const bool InEventPort_Impl::is_abstract = false;

  //
  // _create (const ConnectedComponent_in)
  //
  InEventPort InEventPort_Impl::_create (const ConnectedComponent_in parent)
  {
    return ::GAME::Mga::create < InEventPort > (parent, InEventPort_Impl::metaname);
  }

  //
  // _create (const Component_in)
  //
  InEventPort InEventPort_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create < InEventPort > (parent, InEventPort_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  InEventPort InEventPort_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create < InEventPort > (parent, InEventPort_Impl::metaname);
  }

  //
  // accept
  //
  void InEventPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InEventPort (this);
    else
      v->visit_Reference (this);
  }

  //
  // EventType_is_nil
  //
  bool InEventPort_Impl::EventType_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_EventType
  //
  void InEventPort_Impl::refers_to_EventType (EventType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_EventType
  //
  EventType InEventPort_Impl::refers_to_EventType (void) const
  {
    return EventType::_narrow (this->refers_to ());
  }
}

