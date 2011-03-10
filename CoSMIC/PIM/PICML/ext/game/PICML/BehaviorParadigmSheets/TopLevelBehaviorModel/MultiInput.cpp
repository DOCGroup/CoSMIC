// $Id$

#include "stdafx.h"
#include "MultiInput.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInputBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/MultiInputAction.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MultiInput_Impl::metaname = "MultiInput";

  //
  // MultiInput_Impl
  //
  MultiInput_Impl::MultiInput_Impl (void)
  {
  }

  //
  // MultiInput_Impl
  //
  MultiInput_Impl::MultiInput_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MultiInput_Impl
  //
  MultiInput_Impl::~MultiInput_Impl (void)
  {
  }

  //
  // accept
  //
  void MultiInput_Impl::accept (Visitor * v)
  {
    v->visit_MultiInput (this);
  }

  //
  // _create
  //
  MultiInput MultiInput_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create_object <MultiInput> (parent, MultiInput_Impl::metaname);
  }

  //
  // src_MultiInputBase
  //
  MultiInputBase MultiInput_Impl::src_MultiInputBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return MultiInputBase::_narrow (target);
  }

  //
  // dst_MultiInputAction
  //
  MultiInputAction MultiInput_Impl::dst_MultiInputAction (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return MultiInputAction::_narrow (target);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior MultiInput_Impl::parent_TopLevelBehavior (void) const
  {
    return ::GAME::Mga::get_parent <TopLevelBehavior> (this->object_.p);
  }
}

