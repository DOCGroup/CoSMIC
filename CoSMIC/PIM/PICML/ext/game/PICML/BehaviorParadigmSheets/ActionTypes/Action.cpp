// $Id$

#include "StdAfx.h"
#include "Action.h"

#if !defined (__GAME_INLINE__)
#include "Action.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionType.h"
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
  // _create (const ActionBase_in)
  //
  Action Action_Impl::_create (const ActionBase_in parent)
  {
    return ::GAME::Mga::create_object < Action > (parent, Action_Impl::metaname);
  }

  //
  // accept
  //
  void Action_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Action (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
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
    return this->children <ActionType> ().item ();
  }
}

