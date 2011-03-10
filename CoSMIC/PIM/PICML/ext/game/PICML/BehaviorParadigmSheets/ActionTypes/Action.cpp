// $Id$

#include "stdafx.h"
#include "Action.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Action_Impl::metaname = "Action";

  //
  // Action_Impl
  //
  Action_Impl::Action_Impl (void)
  {
  }

  //
  // Action_Impl
  //
  Action_Impl::Action_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Action_Impl
  //
  Action_Impl::~Action_Impl (void)
  {
  }

  //
  // accept
  //
  void Action_Impl::accept (Visitor * v)
  {
    v->visit_Action (this);
  }

  //
  // get_ActionType
  //
  ActionType Action_Impl::get_ActionType (void) const
  {
    // Get the collection of children.
    std::vector <ActionType> items;
    this->children (items);

    return !items.empty () ? items.front () : ActionType ();
  }
}

