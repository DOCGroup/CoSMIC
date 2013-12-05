// $Id$

#include "StdAfx.h"
#include "ServiceConsumer.h"

#if !defined (__GAME_INLINE__)
#include "ServiceConsumer.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ServiceConsumer_Impl::metaname ("ServiceConsumer");

  //
  // _create (const RTRequirements_in)
  //
  ServiceConsumer ServiceConsumer_Impl::_create (const RTRequirements_in parent)
  {
    return ::GAME::Mga::create_object < ServiceConsumer > (parent, ServiceConsumer_Impl::metaname);
  }

  //
  // accept
  //
  void ServiceConsumer_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ServiceConsumer (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_RTRequirements
  //
  RTRequirements ServiceConsumer_Impl::parent_RTRequirements (void)
  {
    return RTRequirements::_narrow (this->parent ());
  }
}

