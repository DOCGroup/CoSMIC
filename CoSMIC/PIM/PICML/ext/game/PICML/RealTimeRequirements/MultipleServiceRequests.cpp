// $Id$

#include "stdafx.h"
#include "MultipleServiceRequests.h"

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
  const std::string MultipleServiceRequests_Impl::metaname = "MultipleServiceRequests";

  //
  // MultipleServiceRequests_Impl
  //
  MultipleServiceRequests_Impl::MultipleServiceRequests_Impl (void)
  {
  }

  //
  // MultipleServiceRequests_Impl
  //
  MultipleServiceRequests_Impl::MultipleServiceRequests_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MultipleServiceRequests_Impl
  //
  MultipleServiceRequests_Impl::~MultipleServiceRequests_Impl (void)
  {
  }

  //
  // accept
  //
  void MultipleServiceRequests_Impl::accept (Visitor * v)
  {
    v->visit_MultipleServiceRequests (this);
  }

  //
  // _create
  //
  MultipleServiceRequests MultipleServiceRequests_Impl::_create (const ServiceProvider_in parent)
  {
    return ::GAME::Mga::create_object <MultipleServiceRequests> (parent, MultipleServiceRequests_Impl::metaname);
  }

  //
  // minimum_simultaneous_service_level
  //
  void MultipleServiceRequests_Impl::minimum_simultaneous_service_level (long val)
  {
    static const std::string attr_minimum_simultaneous_service_level ("minimum_simultaneous_service_level");
    this->attribute (attr_minimum_simultaneous_service_level)->int_value (val);
  }

  //
  // minimum_simultaneous_service_level
  //
  long MultipleServiceRequests_Impl::minimum_simultaneous_service_level (void) const
  {
    static const std::string attr_minimum_simultaneous_service_level ("minimum_simultaneous_service_level");
    return this->attribute (attr_minimum_simultaneous_service_level)->int_value ();
  }

  //
  // simultaneous_service_execution
  //
  void MultipleServiceRequests_Impl::simultaneous_service_execution (bool val)
  {
    static const std::string attr_simultaneous_service_execution ("simultaneous_service_execution");
    this->attribute (attr_simultaneous_service_execution)->bool_value (val);
  }

  //
  // simultaneous_service_execution
  //
  bool MultipleServiceRequests_Impl::simultaneous_service_execution (void) const
  {
    static const std::string attr_simultaneous_service_execution ("simultaneous_service_execution");
    return this->attribute (attr_simultaneous_service_execution)->bool_value ();
  }

  //
  // buffer_service_requests
  //
  void MultipleServiceRequests_Impl::buffer_service_requests (bool val)
  {
    static const std::string attr_buffer_service_requests ("buffer_service_requests");
    this->attribute (attr_buffer_service_requests)->bool_value (val);
  }

  //
  // buffer_service_requests
  //
  bool MultipleServiceRequests_Impl::buffer_service_requests (void) const
  {
    static const std::string attr_buffer_service_requests ("buffer_service_requests");
    return this->attribute (attr_buffer_service_requests)->bool_value ();
  }

  //
  // maximum_simultaneous_service_level
  //
  void MultipleServiceRequests_Impl::maximum_simultaneous_service_level (long val)
  {
    static const std::string attr_maximum_simultaneous_service_level ("maximum_simultaneous_service_level");
    this->attribute (attr_maximum_simultaneous_service_level)->int_value (val);
  }

  //
  // maximum_simultaneous_service_level
  //
  long MultipleServiceRequests_Impl::maximum_simultaneous_service_level (void) const
  {
    static const std::string attr_maximum_simultaneous_service_level ("maximum_simultaneous_service_level");
    return this->attribute (attr_maximum_simultaneous_service_level)->int_value ();
  }

  //
  // parent_ServiceProvider
  //
  ServiceProvider MultipleServiceRequests_Impl::parent_ServiceProvider (void) const
  {
    return ::GAME::Mga::get_parent <ServiceProvider> (this->object_.p);
  }
}

