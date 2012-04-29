// $Id$

#include "StdAfx.h"
#include "QueryInput.h"

#if !defined (__GAME_INLINE__)
#include "QueryInput.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInputBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string QueryInput_Impl::metaname ("QueryInput");

  //
  // _create (const TopLevelBehavior_in)
  //
  QueryInput QueryInput_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create_object < QueryInput > (parent, QueryInput_Impl::metaname);
  }

  //
  // accept
  //
  void QueryInput_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_QueryInput (this);
    else
      v->visit_Connection (this);
  }

  //
  // QueryInputBase
  //
  QueryInputBase QueryInput_Impl::src_QueryInputBase (void) const
  {
    return QueryInputBase::_narrow (this->src ());
  }

  //
  // QueryInputAction
  //
  QueryInputAction QueryInput_Impl::dst_QueryInputAction (void) const
  {
    return QueryInputAction::_narrow (this->dst ());
  }
}

