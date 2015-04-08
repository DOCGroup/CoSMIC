#include "StdAfx.h"
#include "BranchState.h"

#if !defined (__GAME_INLINE__)
#include "BranchState.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
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
  // is_abstract
  //
  const bool BranchState_Impl::is_abstract = false;

  //
  // _create (const BehaviorModel_in)
  //
  BranchState BranchState_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create < BranchState > (parent, BranchState_Impl::metaname);
  }

  //
  // accept
  //
  void BranchState_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_BranchState (this);
    else
      v->visit_Atom (this);
  }

  //
  // src_of_BranchTransition
  //
  size_t BranchState_Impl::src_of_BranchTransition (std::vector <BranchTransition> & items) const
  {
    return this->in_connections <BranchTransition> (items);
  }

  //
  // src_of_BranchTransition
  //
  GAME::Mga::Collection_T <BranchTransition> BranchState_Impl::src_of_BranchTransition (void) const
  {
    return this->in_connections <BranchTransition> ("src");
  }
}

