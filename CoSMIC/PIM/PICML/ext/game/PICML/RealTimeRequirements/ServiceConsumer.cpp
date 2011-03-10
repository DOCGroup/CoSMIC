// $Id$

#include "stdafx.h"
#include "ServiceConsumer.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ServiceConsumer_Impl::metaname = "ServiceConsumer";

  //
  // ServiceConsumer_Impl
  //
  ServiceConsumer_Impl::ServiceConsumer_Impl (void)
  {
  }

  //
  // ServiceConsumer_Impl
  //
  ServiceConsumer_Impl::ServiceConsumer_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ServiceConsumer_Impl
  //
  ServiceConsumer_Impl::~ServiceConsumer_Impl (void)
  {
  }

  //
  // accept
  //
  void ServiceConsumer_Impl::accept (Visitor * v)
  {
    v->visit_ServiceConsumer (this);
  }

  //
  // _create
  //
  ServiceConsumer ServiceConsumer_Impl::_create (const RTRequirements_in parent)
  {
    return ::GAME::Mga::create_object <ServiceConsumer> (parent, ServiceConsumer_Impl::metaname);
  }

  //
  // prioritize_service_invocations
  //
  void ServiceConsumer_Impl::prioritize_service_invocations (bool val)
  {
    static const std::string attr_prioritize_service_invocations ("prioritize_service_invocations");
    this->attribute (attr_prioritize_service_invocations)->bool_value (val);
  }

  //
  // prioritize_service_invocations
  //
  bool ServiceConsumer_Impl::prioritize_service_invocations (void) const
  {
    static const std::string attr_prioritize_service_invocations ("prioritize_service_invocations");
    return this->attribute (attr_prioritize_service_invocations)->bool_value ();
  }

  //
  // parent_RTRequirements
  //
  RTRequirements ServiceConsumer_Impl::parent_RTRequirements (void) const
  {
    return ::GAME::Mga::get_parent <RTRequirements> (this->object_.p);
  }
}

