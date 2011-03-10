// $Id$

#include "stdafx.h"
#include "QueryInput.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInputBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string QueryInput_Impl::metaname = "QueryInput";

  //
  // QueryInput_Impl
  //
  QueryInput_Impl::QueryInput_Impl (void)
  {
  }

  //
  // QueryInput_Impl
  //
  QueryInput_Impl::QueryInput_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~QueryInput_Impl
  //
  QueryInput_Impl::~QueryInput_Impl (void)
  {
  }

  //
  // accept
  //
  void QueryInput_Impl::accept (Visitor * v)
  {
    v->visit_QueryInput (this);
  }

  //
  // _create
  //
  QueryInput QueryInput_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create_object <QueryInput> (parent, QueryInput_Impl::metaname);
  }

  //
  // src_QueryInputBase
  //
  QueryInputBase QueryInput_Impl::src_QueryInputBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return QueryInputBase::_narrow (target);
  }

  //
  // dst_QueryInputAction
  //
  QueryInputAction QueryInput_Impl::dst_QueryInputAction (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return QueryInputAction::_narrow (target);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior QueryInput_Impl::parent_TopLevelBehavior (void) const
  {
    return ::GAME::Mga::get_parent <TopLevelBehavior> (this->object_.p);
  }
}

