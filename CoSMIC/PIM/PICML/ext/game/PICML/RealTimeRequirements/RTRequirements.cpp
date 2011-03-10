// $Id$

#include "stdafx.h"
#include "RTRequirements.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/RealTimeRequirements/ServiceProvider.h"
#include "PICML/RealTimeRequirements/ServiceConsumer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RTRequirements_Impl::metaname = "RTRequirements";

  //
  // RTRequirements_Impl
  //
  RTRequirements_Impl::RTRequirements_Impl (void)
  {
  }

  //
  // RTRequirements_Impl
  //
  RTRequirements_Impl::RTRequirements_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RTRequirements_Impl
  //
  RTRequirements_Impl::~RTRequirements_Impl (void)
  {
  }

  //
  // accept
  //
  void RTRequirements_Impl::accept (Visitor * v)
  {
    v->visit_RTRequirements (this);
  }

  //
  // get_ServiceProvider
  //
  ServiceProvider RTRequirements_Impl::get_ServiceProvider (void) const
  {
    // Get the collection of children.
    std::vector <ServiceProvider> items;
    this->children (items);

    return !items.empty () ? items.front () : ServiceProvider ();
  }

  //
  // get_ServiceConsumer
  //
  ServiceConsumer RTRequirements_Impl::get_ServiceConsumer (void) const
  {
    // Get the collection of children.
    std::vector <ServiceConsumer> items;
    this->children (items);

    return !items.empty () ? items.front () : ServiceConsumer ();
  }
}

