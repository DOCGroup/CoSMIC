// $Id$

#include "stdafx.h"
#include "ActionType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Action.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ActionType_Impl::metaname = "ActionType";

  //
  // ActionType_Impl
  //
  ActionType_Impl::ActionType_Impl (void)
  {
  }

  //
  // ActionType_Impl
  //
  ActionType_Impl::ActionType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ActionType_Impl
  //
  ActionType_Impl::~ActionType_Impl (void)
  {
  }

  //
  // accept
  //
  void ActionType_Impl::accept (Visitor * v)
  {
    v->visit_ActionType (this);
  }

  //
  // _create
  //
  ActionType ActionType_Impl::_create (const Action_in parent)
  {
    return ::GAME::Mga::create_object <ActionType> (parent, ActionType_Impl::metaname);
  }

  //
  // parent_Action
  //
  Action ActionType_Impl::parent_Action (void) const
  {
    return ::GAME::Mga::get_parent <Action> (this->object_.p);
  }
}

