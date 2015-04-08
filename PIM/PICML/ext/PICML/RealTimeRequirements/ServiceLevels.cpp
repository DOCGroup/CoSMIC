#include "StdAfx.h"
#include "ServiceLevels.h"

#if !defined (__GAME_INLINE__)
#include "ServiceLevels.inl"
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
  const std::string ServiceLevels_Impl::metaname ("ServiceLevels");

  //
  // is_abstract
  //
  const bool ServiceLevels_Impl::is_abstract = false;

  //
  // _create (const ServiceProvider_in)
  //
  ServiceLevels ServiceLevels_Impl::_create (const ServiceProvider_in parent)
  {
    return ::GAME::Mga::create < ServiceLevels > (parent, ServiceLevels_Impl::metaname);
  }

  //
  // accept
  //
  void ServiceLevels_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ServiceLevels (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ServiceProvider
  //
  ServiceProvider ServiceLevels_Impl::parent_ServiceProvider (void)
  {
    return ServiceProvider::_narrow (this->parent ());
  }
}

