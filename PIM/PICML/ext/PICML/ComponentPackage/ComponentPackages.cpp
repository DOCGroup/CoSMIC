// $Id$

#include "StdAfx.h"
#include "ComponentPackages.h"

#if !defined (__GAME_INLINE__)
#include "ComponentPackages.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentPackages_Impl::metaname ("ComponentPackages");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  ComponentPackages ComponentPackages_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <ComponentPackages> (parent, ComponentPackages_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentPackages_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentPackages (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder ComponentPackages_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_PackageContainers
  //
  size_t ComponentPackages_Impl::get_PackageContainers (std::vector <PackageContainer> & items) const
  {
    return this->children (items);
  }

  //
  // get_PackageContainers
  //
  ::GAME::Mga::Collection_T <PackageContainer> ComponentPackages_Impl::get_PackageContainers (void) const
  {
    return this->children <PackageContainer> ();
  }
}

