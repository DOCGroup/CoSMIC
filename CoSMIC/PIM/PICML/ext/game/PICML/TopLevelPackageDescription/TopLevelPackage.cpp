// $Id$

#include "stdafx.h"
#include "TopLevelPackage.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/package.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TopLevelPackage_Impl::metaname = "TopLevelPackage";

  //
  // TopLevelPackage_Impl
  //
  TopLevelPackage_Impl::TopLevelPackage_Impl (void)
  {
  }

  //
  // TopLevelPackage_Impl
  //
  TopLevelPackage_Impl::TopLevelPackage_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TopLevelPackage_Impl
  //
  TopLevelPackage_Impl::~TopLevelPackage_Impl (void)
  {
  }

  //
  // accept
  //
  void TopLevelPackage_Impl::accept (Visitor * v)
  {
    v->visit_TopLevelPackage (this);
  }

  //
  // _create
  //
  TopLevelPackage TopLevelPackage_Impl::_create (const TopLevelPackageContainer_in parent)
  {
    return ::GAME::Mga::create_object <TopLevelPackage> (parent, TopLevelPackage_Impl::metaname);
  }

  //
  // in_package_connections
  //
  size_t TopLevelPackage_Impl::in_package_connections (std::vector <package> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_TopLevelPackageContainer
  //
  TopLevelPackageContainer TopLevelPackage_Impl::parent_TopLevelPackageContainer (void) const
  {
    return ::GAME::Mga::get_parent <TopLevelPackageContainer> (this->object_.p);
  }
}

