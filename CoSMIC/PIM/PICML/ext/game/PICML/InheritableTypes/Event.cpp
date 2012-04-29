// $Id$

#include "StdAfx.h"
#include "Event.h"

#if !defined (__GAME_INLINE__)
#include "Event.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/ComponentBenchmark/BenchmarkAnalysis.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Event_Impl::metaname ("Event");

  //
  // _create (const BenchmarkAnalysis_in)
  //
  Event Event_Impl::_create (const BenchmarkAnalysis_in parent)
  {
    return ::GAME::Mga::create_object < Event > (parent, Event_Impl::metaname);
  }

  //
  // _create (const ObjectByValue_in)
  //
  Event Event_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create_object < Event > (parent, Event_Impl::metaname);
  }

  //
  // accept
  //
  void Event_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Event (this);
    else
      v->visit_Model (this);
  }
}

