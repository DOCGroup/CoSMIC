// $Id$

#include "StdAfx.h"
#include "RTRequirements.h"

#if !defined (__GAME_INLINE__)
#include "RTRequirements.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/RealTimeRequirements/ServiceConsumer.h"
#include "PICML/RealTimeRequirements/ServiceProvider.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string RTRequirements_Impl::metaname ("RTRequirements");

  //
  // _create (const ComponentAssembly_in)
  //
  RTRequirements RTRequirements_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < RTRequirements > (parent, RTRequirements_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  RTRequirements RTRequirements_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create < RTRequirements > (parent, RTRequirements_Impl::metaname);
  }

  //
  // _create (const PackageConfigurationContainer_in)
  //
  RTRequirements RTRequirements_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create < RTRequirements > (parent, RTRequirements_Impl::metaname);
  }

  //
  // accept
  //
  void RTRequirements_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_RTRequirements (this);
    else
      v->visit_Model (this);
  }

  //
  // has_ServiceConsumer
  //
  bool RTRequirements_Impl::has_ServiceConsumer (void) const
  {
    return this->children <ServiceConsumer> ().count () == 1;
  }

  //
  // get_ServiceConsumer
  //
  ServiceConsumer RTRequirements_Impl::get_ServiceConsumer (void) const
  {
    return this->children <ServiceConsumer> ().first ();
  }

  //
  // has_ServiceProvider
  //
  bool RTRequirements_Impl::has_ServiceProvider (void) const
  {
    return this->children <ServiceProvider> ().count () == 1;
  }

  //
  // get_ServiceProvider
  //
  ServiceProvider RTRequirements_Impl::get_ServiceProvider (void) const
  {
    return this->children <ServiceProvider> ().first ();
  }
}

