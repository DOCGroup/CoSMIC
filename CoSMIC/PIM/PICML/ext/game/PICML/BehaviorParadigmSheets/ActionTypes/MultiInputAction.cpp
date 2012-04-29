// $Id$

#include "StdAfx.h"
#include "MultiInputAction.h"

#if !defined (__GAME_INLINE__)
#include "MultiInputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInput.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MultiInputAction_Impl::metaname ("MultiInputAction");

  //
  // _create (const BehaviorModel_in)
  //
  MultiInputAction MultiInputAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < MultiInputAction > (parent, MultiInputAction_Impl::metaname);
  }

  //
  // _create (const BehaviorInputAction_in)
  //
  MultiInputAction MultiInputAction_Impl::_create (const BehaviorInputAction_in parent)
  {
    return ::GAME::Mga::create_object < MultiInputAction > (parent, MultiInputAction_Impl::metaname);
  }

  //
  // accept
  //
  void MultiInputAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MultiInputAction (this);
    else
      v->visit_Model (this);
  }

  //
  // dst_MultiInput
  //
  size_t MultiInputAction_Impl::dst_MultiInput (std::vector <MultiInput> & items) const
  {
    return this->in_connections <MultiInput> (items);
  }
}

