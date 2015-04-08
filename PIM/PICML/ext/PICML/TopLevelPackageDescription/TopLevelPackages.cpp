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
  // is_abstract
  //
  const bool TopLevelPackages_Impl::is_abstract = false;

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  TopLevelPackages TopLevelPackages_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <TopLevelPackages> (parent, TopLevelPackages_Impl::metaname);
  }

  //
  // accept
  //
  void TopLevelPackages_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TopLevelPackages (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder TopLevelPackages_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_TopLevelPackageContainers
  //
  size_t TopLevelPackages_Impl::get_TopLevelPackageContainers (std::vector <TopLevelPackageContainer> & items) const
  {
    return this->children (items);
  }

  //
  // get_TopLevelPackageContainers
  //
  ::GAME::Mga::Collection_T <TopLevelPackageContainer> TopLevelPackages_Impl::get_TopLevelPackageContainers (void) const
  {
    return this->children <TopLevelPackageContainer> ();
  }
}

