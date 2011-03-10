// $Id$

#include "stdafx.h"
#include "EventRef.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentBenchmark/TimerEventSinkConn.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "PICML/InheritableTypes/Event.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string EventRef_Impl::metaname = "EventRef";

  //
  // EventRef_Impl
  //
  EventRef_Impl::EventRef_Impl (void)
  {
  }

  //
  // EventRef_Impl
  //
  EventRef_Impl::EventRef_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EventRef_Impl
  //
  EventRef_Impl::~EventRef_Impl (void)
  {
  }

  //
  // accept
  //
  void EventRef_Impl::accept (Visitor * v)
  {
    v->visit_EventRef (this);
  }

  //
  // _create
  //
  EventRef EventRef_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object <EventRef> (parent, EventRef_Impl::metaname);
  }

  //
  // in_TimerEventSinkConn_connections
  //
  size_t EventRef_Impl::in_TimerEventSinkConn_connections (std::vector <TimerEventSinkConn> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_BenchmarkAnalysis
  //
  BenchmarkAnalysis EventRef_Impl::parent_BenchmarkAnalysis (void) const
  {
    return ::GAME::Mga::get_parent <BenchmarkAnalysis> (this->object_.p);
  }
}

