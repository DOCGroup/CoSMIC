// $Id$

#include "StdAfx.h"
#include "EventRef.h"

#if !defined (__GAME_INLINE__)
#include "EventRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string EventRef_Impl::metaname ("EventRef");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  EventRef EventRef_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < EventRef > (parent, EventRef_Impl::metaname);
  }

  //
  // accept
  //
  void EventRef_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_EventRef (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis EventRef_Impl::parent_BenchmarkAnalysis (void)
  {
    return BenchmarkAnalysis::_narrow (this->parent ());
  }

  //
  // src_TimerEventSinkConn
  //
  size_t EventRef_Impl::src_TimerEventSinkConn (std::vector <TimerEventSinkConn> & items) const
  {
    return this->in_connections <TimerEventSinkConn> (items);
  }

  //
  // Event_is_nil
  //
  bool EventRef_Impl::Event_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_Event
  //
  void EventRef_Impl::set_Event (Event_in item)
  {
    this->refers_to (item);
  }

  //
  // get_Event
  //
  Event EventRef_Impl::get_Event (void) const
  {
    return Event::_narrow (this->refers_to ());
  }
}

