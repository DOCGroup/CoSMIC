// $Id$

#include "stdafx.h"
#include "ServiceProvider.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/RealTimeRequirements/ServiceLevels.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/RealTimeRequirements/MultipleServiceRequests.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ServiceProvider_Impl::metaname = "ServiceProvider";

  //
  // ServiceProvider_Impl
  //
  ServiceProvider_Impl::ServiceProvider_Impl (void)
  {
  }

  //
  // ServiceProvider_Impl
  //
  ServiceProvider_Impl::ServiceProvider_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ServiceProvider_Impl
  //
  ServiceProvider_Impl::~ServiceProvider_Impl (void)
  {
  }

  //
  // accept
  //
  void ServiceProvider_Impl::accept (Visitor * v)
  {
    v->visit_ServiceProvider (this);
  }

  //
  // _create
  //
  ServiceProvider ServiceProvider_Impl::_create (const RTRequirements_in parent)
  {
    return ::GAME::Mga::create_object <ServiceProvider> (parent, ServiceProvider_Impl::metaname);
  }

  //
  // fixed_prioirty_service_execution
  //
  void ServiceProvider_Impl::fixed_prioirty_service_execution (bool val)
  {
    static const std::string attr_fixed_prioirty_service_execution ("fixed_prioirty_service_execution");
    this->attribute (attr_fixed_prioirty_service_execution)->bool_value (val);
  }

  //
  // fixed_prioirty_service_execution
  //
  bool ServiceProvider_Impl::fixed_prioirty_service_execution (void) const
  {
    static const std::string attr_fixed_prioirty_service_execution ("fixed_prioirty_service_execution");
    return this->attribute (attr_fixed_prioirty_service_execution)->bool_value ();
  }

  //
  // get_ServiceLevels
  //
  ServiceLevels ServiceProvider_Impl::get_ServiceLevels (void) const
  {
    // Get the collection of children.
    std::vector <ServiceLevels> items;
    this->children (items);

    return !items.empty () ? items.front () : ServiceLevels ();
  }

  //
  // get_MultipleServiceRequests
  //
  MultipleServiceRequests ServiceProvider_Impl::get_MultipleServiceRequests (void) const
  {
    // Get the collection of children.
    std::vector <MultipleServiceRequests> items;
    this->children (items);

    return !items.empty () ? items.front () : MultipleServiceRequests ();
  }

  //
  // parent_RTRequirements
  //
  RTRequirements ServiceProvider_Impl::parent_RTRequirements (void) const
  {
    return ::GAME::Mga::get_parent <RTRequirements> (this->object_.p);
  }
}

