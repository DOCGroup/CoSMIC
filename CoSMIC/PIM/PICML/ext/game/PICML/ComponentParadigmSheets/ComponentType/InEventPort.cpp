// $Id$

#include "StdAfx.h"
#include "InEventPort.h"

#if !defined (__GAME_INLINE__)
#include "InEventPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventType.h"
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
  // accept
  //
  void InEventPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_InEventPort (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // InEventPort_is_nil
  //
  bool InEventPort_Impl::InEventPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_InEventPort
  //
  InEventPort InEventPort_Impl::get_InEventPort (void) const
  {
    return InEventPort::_narrow (this->refers_to ());
  }

  //
  // EventType_is_nil
  //
  bool InEventPort_Impl::EventType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_EventType
  //
  EventType InEventPort_Impl::get_EventType (void) const
  {
    return EventType::_narrow (this->refers_to ());
  }
}

