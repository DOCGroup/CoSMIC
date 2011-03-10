// $Id$

#include "stdafx.h"
#include "OutEventPort.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string OutEventPort_Impl::metaname = "OutEventPort";

  //
  // OutEventPort_Impl
  //
  OutEventPort_Impl::OutEventPort_Impl (void)
  {
  }

  //
  // OutEventPort_Impl
  //
  OutEventPort_Impl::OutEventPort_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~OutEventPort_Impl
  //
  OutEventPort_Impl::~OutEventPort_Impl (void)
  {
  }

  //
  // accept
  //
  void OutEventPort_Impl::accept (Visitor * v)
  {
    v->visit_OutEventPort (this);
  }

  //
  // out_event_port_type
  //
  void OutEventPort_Impl::out_event_port_type (const std::string & val)
  {
    static const std::string attr_out_event_port_type ("out_event_port_type");
    this->attribute (attr_out_event_port_type)->string_value (val);
  }

  //
  // out_event_port_type
  //
  std::string OutEventPort_Impl::out_event_port_type (void) const
  {
    static const std::string attr_out_event_port_type ("out_event_port_type");
    return this->attribute (attr_out_event_port_type)->string_value ();
  }

  //
  // single_destination
  //
  void OutEventPort_Impl::single_destination (bool val)
  {
    static const std::string attr_single_destination ("single_destination");
    this->attribute (attr_single_destination)->bool_value (val);
  }

  //
  // single_destination
  //
  bool OutEventPort_Impl::single_destination (void) const
  {
    static const std::string attr_single_destination ("single_destination");
    return this->attribute (attr_single_destination)->bool_value ();
  }

  //
  // refers_to_EventType
  //
  EventType OutEventPort_Impl::refers_to_EventType (void) const
  {
    return ::GAME::Mga::get_refers_to <EventType> (this);
  }
}

