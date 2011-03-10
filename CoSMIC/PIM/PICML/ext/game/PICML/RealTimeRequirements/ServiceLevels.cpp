// $Id$

#include "stdafx.h"
#include "ServiceLevels.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/RealTimeRequirements/ServiceProvider.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ServiceLevels_Impl::metaname = "ServiceLevels";

  //
  // ServiceLevels_Impl
  //
  ServiceLevels_Impl::ServiceLevels_Impl (void)
  {
  }

  //
  // ServiceLevels_Impl
  //
  ServiceLevels_Impl::ServiceLevels_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ServiceLevels_Impl
  //
  ServiceLevels_Impl::~ServiceLevels_Impl (void)
  {
  }

  //
  // accept
  //
  void ServiceLevels_Impl::accept (Visitor * v)
  {
    v->visit_ServiceLevels (this);
  }

  //
  // _create
  //
  ServiceLevels ServiceLevels_Impl::_create (const ServiceProvider_in parent)
  {
    return ::GAME::Mga::create_object <ServiceLevels> (parent, ServiceLevels_Impl::metaname);
  }

  //
  // varying_service_levels
  //
  void ServiceLevels_Impl::varying_service_levels (bool val)
  {
    static const std::string attr_varying_service_levels ("varying_service_levels");
    this->attribute (attr_varying_service_levels)->bool_value (val);
  }

  //
  // varying_service_levels
  //
  bool ServiceLevels_Impl::varying_service_levels (void) const
  {
    static const std::string attr_varying_service_levels ("varying_service_levels");
    return this->attribute (attr_varying_service_levels)->bool_value ();
  }

  //
  // parent_ServiceProvider
  //
  ServiceProvider ServiceLevels_Impl::parent_ServiceProvider (void) const
  {
    return ::GAME::Mga::get_parent <ServiceProvider> (this->object_.p);
  }
}

