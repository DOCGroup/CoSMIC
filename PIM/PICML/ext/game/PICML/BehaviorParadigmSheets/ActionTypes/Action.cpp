// $Id$

#include "StdAfx.h"
#include "Action.h"

#if !defined (__GAME_INLINE__)
#include "Action.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionType.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Action_Impl::metaname ("Action");

  //
  // _create (const BehaviorModel_in)
  //
  Action Action_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < Action > (parent, Action_Impl::metaname);
  }

  //
  // accept
  //
  void Action_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Action (this);
    else
      v->visit_Model (this);
  }

  //
  // has_ActionType
  //
  bool Action_Impl::has_ActionType (void) const
  {
    return this->children <ActionType> ().count () == 1;
  }

  //
  // get_ActionType
  //
  ActionType Action_Impl::get_ActionType (void) const
  {
	  Model_Impl m;
	  m.children<ActionType> ().first ();
    return this->children <ActionType> ().first ();
  }
}

