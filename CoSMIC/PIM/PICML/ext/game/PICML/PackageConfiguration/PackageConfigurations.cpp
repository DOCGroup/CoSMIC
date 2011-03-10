// $Id$

#include "stdafx.h"
#include "PackageConfigurations.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfigurations_Impl::metaname = "PackageConfigurations";

  //
  // PackageConfigurations_Impl
  //
  PackageConfigurations_Impl::PackageConfigurations_Impl (void)
  {
  }

  //
  // PackageConfigurations_Impl
  //
  PackageConfigurations_Impl::PackageConfigurations_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfigurations_Impl
  //
  PackageConfigurations_Impl::~PackageConfigurations_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfigurations_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfigurations (this);
  }

  //
  // _create
  //
  PackageConfigurations PackageConfigurations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <PackageConfigurations> (parent, PackageConfigurations_Impl::metaname);
  }

  ::GAME::Mga::RootFolder PackageConfigurations_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

