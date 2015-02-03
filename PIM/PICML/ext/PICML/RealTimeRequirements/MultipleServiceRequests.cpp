// $Id$

#include "StdAfx.h"
#include "MultipleServiceRequests.h"

#if !defined (__GAME_INLINE__)
#include "MultipleServiceRequests.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/RealTimeRequirements/ServiceProvider.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string MultipleServiceRequests_Impl::metaname ("MultipleServiceRequests");

  //
  // is_abstract
  //
  const bool MultipleServiceRequests_Impl::is_abstract (0);

  //
  // _create (const ServiceProvider_in)
  //
  MultipleServiceRequests MultipleServiceRequests_Impl::_create (const ServiceProvider_in parent)
  {
    return ::GAME::Mga::create < MultipleServiceRequests > (parent, MultipleServiceRequests_Impl::metaname);
  }

  //
  // accept
  //
  void MultipleServiceRequests_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_MultipleServiceRequests (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ServiceProvider
  //
  ServiceProvider MultipleServiceRequests_Impl::parent_ServiceProvider (void)
  {
    return ServiceProvider::_narrow (this->parent ());
  }
}

