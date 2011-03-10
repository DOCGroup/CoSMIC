// $Id$

#include "stdafx.h"
#include "TopLevelPackages.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TopLevelPackages_Impl::metaname = "TopLevelPackages";

  //
  // TopLevelPackages_Impl
  //
  TopLevelPackages_Impl::TopLevelPackages_Impl (void)
  {
  }

  //
  // TopLevelPackages_Impl
  //
  TopLevelPackages_Impl::TopLevelPackages_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TopLevelPackages_Impl
  //
  TopLevelPackages_Impl::~TopLevelPackages_Impl (void)
  {
  }

  //
  // accept
  //
  void TopLevelPackages_Impl::accept (Visitor * v)
  {
    v->visit_TopLevelPackages (this);
  }

  //
  // _create
  //
  TopLevelPackages TopLevelPackages_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <TopLevelPackages> (parent, TopLevelPackages_Impl::metaname);
  }

  ::GAME::Mga::RootFolder TopLevelPackages_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

