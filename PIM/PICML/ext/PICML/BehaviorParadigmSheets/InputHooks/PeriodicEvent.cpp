#include "StdAfx.h"
#include "PeriodicEvent.h"

#if !defined (__GAME_INLINE__)
#include "PeriodicEvent.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PeriodicEvent_Impl::metaname ("PeriodicEvent");

  //
  // is_abstract
  //
  const bool PeriodicEvent_Impl::is_abstract = false;

  //
  // _create (const TopLevelBehavior_in)
  //
  PeriodicEvent PeriodicEvent_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create < PeriodicEvent > (parent, PeriodicEvent_Impl::metaname);
  }

  //
  // accept
  //
  void PeriodicEvent_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PeriodicEvent (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior PeriodicEvent_Impl::parent_TopLevelBehavior (void)
  {
    return TopLevelBehavior::_narrow (this->parent ());
  }
}

