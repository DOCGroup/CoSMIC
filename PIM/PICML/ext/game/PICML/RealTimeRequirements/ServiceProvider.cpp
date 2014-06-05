// $Id$

#include "StdAfx.h"
#include "ServiceProvider.h"

#if !defined (__GAME_INLINE__)
#include "ServiceProvider.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/RealTimeRequirements/MultipleServiceRequests.h"
#include "PICML/RealTimeRequirements/ServiceLevels.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ServiceProvider_Impl::metaname ("ServiceProvider");

  //
  // _create (const RTRequirements_in)
  //
  ServiceProvider ServiceProvider_Impl::_create (const RTRequirements_in parent)
  {
    return ::GAME::Mga::create_object < ServiceProvider > (parent, ServiceProvider_Impl::metaname);
  }

  //
  // accept
  //
  void ServiceProvider_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ServiceProvider (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_RTRequirements
  //
  RTRequirements ServiceProvider_Impl::parent_RTRequirements (void)
  {
    return RTRequirements::_narrow (this->parent ());
  }

  //
  // has_MultipleServiceRequests
  //
  bool ServiceProvider_Impl::has_MultipleServiceRequests (void) const
  {
    return this->children <MultipleServiceRequests> ().count () == 1;
  }

  //
  // get_MultipleServiceRequests
  //
  MultipleServiceRequests ServiceProvider_Impl::get_MultipleServiceRequests (void) const
  {
    return this->children <MultipleServiceRequests> ().first ();
  }

  //
  // has_ServiceLevels
  //
  bool ServiceProvider_Impl::has_ServiceLevels (void) const
  {
    return this->children <ServiceLevels> ().count () == 1;
  }

  //
  // get_ServiceLevels
  //
  ServiceLevels ServiceProvider_Impl::get_ServiceLevels (void) const
  {
    return this->children <ServiceLevels> ().first ();
  }
}

