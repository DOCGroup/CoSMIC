// $Id$

#include "StdAfx.h"
#include "MultiInput.h"

#if !defined (__GAME_INLINE__)
#include "MultiInput.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInputBase.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/Environment.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ProvidedRequestPort.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/MultiInputAction.h"
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
  const std::string MultiInput_Impl::metaname ("MultiInput");

  //
  // _create (const TopLevelBehavior_in)
  //
  MultiInput MultiInput_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create_object < MultiInput > (parent, MultiInput_Impl::metaname);
  }

  //
  // accept
  //
  void MultiInput_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MultiInput (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior MultiInput_Impl::parent_TopLevelBehavior (void)
  {
    return TopLevelBehavior::_narrow (this->parent ());
  }

  //
  // MultiInputBase
  //
  MultiInputBase MultiInput_Impl::src_MultiInputBase (void) const
  {
    return MultiInputBase::_narrow (this->src ());
  }

  //
  // MultiInputAction
  //
  MultiInputAction MultiInput_Impl::dst_MultiInputAction (void) const
  {
    return MultiInputAction::_narrow (this->dst ());
  }
}
