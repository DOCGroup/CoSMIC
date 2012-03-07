// $Id$

#include "StdAfx.h"
#include "ApplicationTask.h"

#if !defined (__GAME_INLINE__)
#include "ApplicationTask.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ApplicationTask_Impl::metaname ("ApplicationTask");

  //
  // _create (const TopLevelBehavior_in)
  //
  ApplicationTask ApplicationTask_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create_object < ApplicationTask > (parent, ApplicationTask_Impl::metaname);
  }

  //
  // accept
  //
  void ApplicationTask_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ApplicationTask (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

