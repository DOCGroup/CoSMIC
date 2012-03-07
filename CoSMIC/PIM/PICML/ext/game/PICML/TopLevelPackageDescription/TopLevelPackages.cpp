// $Id$

#include "StdAfx.h"
#include "TopLevelPackages.h"

#if !defined (__GAME_INLINE__)
#include "TopLevelPackages.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TopLevelPackages_Impl::metaname ("TopLevelPackages");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  TopLevelPackages TopLevelPackages_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <TopLevelPackages> (parent, TopLevelPackages_Impl::metaname);
  }

  //
  // accept
  //
  void TopLevelPackages_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TopLevelPackages (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_TopLevelPackageContainers
  //
  size_t TopLevelPackages_Impl::get_TopLevelPackageContainers (std::vector <TopLevelPackageContainer> & items) const
  {
    return this->children (items);
  }
}

