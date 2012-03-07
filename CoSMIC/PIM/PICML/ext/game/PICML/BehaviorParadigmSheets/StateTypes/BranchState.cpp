// $Id$

#include "StdAfx.h"
#include "BranchState.h"

#if !defined (__GAME_INLINE__)
#include "BranchState.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string BranchState_Impl::metaname ("BranchState");

  //
  // _create (const BehaviorModel_in)
  //
  BranchState BranchState_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < BranchState > (parent, BranchState_Impl::metaname);
  }

  //
  // accept
  //
  void BranchState_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_BranchState (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // src_BranchTransition
  //
  size_t BranchState_Impl::src_BranchTransition (std::vector <BranchTransition> & items) const
  {
    return this->in_connections <BranchTransition> (items);
  }
}

