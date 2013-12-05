// $Id$

#include "StdAfx.h"
#include "OutEventPort.h"

#if !defined (__GAME_INLINE__)
#include "OutEventPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventType.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/OutEventPortInstance.h"
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
  const std::string OutEventPort_Impl::metaname ("OutEventPort");

  //
  // _create (const Component_in)
  //
  OutEventPort OutEventPort_Impl::_create (const Component_in parent)
  {
    return ::GAME::Mga::create_object < OutEventPort > (parent, OutEventPort_Impl::metaname);
  }

  //
  // _create (const ConnectedComponent_in)
  //
  OutEventPort OutEventPort_Impl::_create (const ConnectedComponent_in parent)
  {
    return ::GAME::Mga::create_object < OutEventPort > (parent, OutEventPort_Impl::metaname);
  }

  //
  // _create (const Path_in)
  //
  OutEventPort OutEventPort_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object < OutEventPort > (parent, OutEventPort_Impl::metaname);
  }

  //
  // accept
  //
  void OutEventPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_OutEventPort (this);
    else
      v->visit_Reference (this);
  }

  //
  // EventType_is_nil
  //
  bool OutEventPort_Impl::EventType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_EventType
  //
  void OutEventPort_Impl::set_EventType (EventType_in item)
  {
    this->refers_to (item);
  }

  //
  // get_EventType
  //
  EventType OutEventPort_Impl::get_EventType (void) const
  {
    return EventType::_narrow (this->refers_to ());
  }
}

