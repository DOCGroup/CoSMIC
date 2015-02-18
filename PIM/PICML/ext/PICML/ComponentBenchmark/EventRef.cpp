// $Id$

#include "StdAfx.h"
#include "EventRef.h"

#if !defined (__GAME_INLINE__)
#include "EventRef.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
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
  // is_abstract
  //
  const bool EventRef_Impl::is_abstract = false;

  //
  // _create (const BenchmarkAnalysis_in)
  //
  EventRef EventRef_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create < EventRef > (parent, EventRef_Impl::metaname);
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
  // src_of_TimerEventSinkConn
  //
  size_t EventRef_Impl::src_of_TimerEventSinkConn (std::vector <TimerEventSinkConn> & items) const
  {
    return this->in_connections <TimerEventSinkConn> (items);
  }

  //
  // has_src_of_TimerEventSinkConn
  //
  bool EventRef_Impl::has_src_of_TimerEventSinkConn (void) const
  {
    return this->in_connections <TimerEventSinkConn> ("src").count () == 1;
  }

  //
  // src_of_TimerEventSinkConn
  //
  TimerEventSinkConn EventRef_Impl::src_of_TimerEventSinkConn (void) const
  {
    return this->in_connections <TimerEventSinkConn> ("src").first ();
  }

  //
  // Event_is_nil
  //
  bool EventRef_Impl::Event_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_Event
  //
  void EventRef_Impl::refers_to_Event (Event_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Event
  //
  Event EventRef_Impl::refers_to_Event (void) const
  {
    return Event::_narrow (this->refers_to ());
  }
}

