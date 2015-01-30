// $Id$

#include "StdAfx.h"
#include "Environment.h"

#if !defined (__GAME_INLINE__)
#include "Environment.inl"
#endif

#include "PICML/Visitor.h"
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
  const std::string Environment_Impl::metaname ("Environment");

  //
  // _create (const TopLevelBehavior_in)
  //
  Environment Environment_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create < Environment > (parent, Environment_Impl::metaname);
  }

  //
  // accept
  //
  void Environment_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Environment (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior Environment_Impl::parent_TopLevelBehavior (void)
  {
    return TopLevelBehavior::_narrow (this->parent ());
  }
}

