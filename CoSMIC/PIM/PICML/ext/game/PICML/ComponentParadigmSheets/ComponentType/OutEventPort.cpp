// $Id$

#include "StdAfx.h"
#include "OutEventPort.h"

#if !defined (__GAME_INLINE__)
#include "OutEventPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/OutEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventType.h"
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
  // accept
  //
  void OutEventPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_OutEventPort (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // OutEventPort_is_nil
  //
  bool OutEventPort_Impl::OutEventPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_OutEventPort
  //
  OutEventPort OutEventPort_Impl::get_OutEventPort (void) const
  {
    return OutEventPort::_narrow (this->refers_to ());
  }

  //
  // EventType_is_nil
  //
  bool OutEventPort_Impl::EventType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_EventType
  //
  EventType OutEventPort_Impl::get_EventType (void) const
  {
    return EventType::_narrow (this->refers_to ());
  }
}

