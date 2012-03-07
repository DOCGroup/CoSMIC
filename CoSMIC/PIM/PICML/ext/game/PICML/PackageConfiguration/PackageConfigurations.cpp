// $Id$

#include "StdAfx.h"
#include "PackageConfigurations.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfigurations.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfigurations_Impl::metaname ("PackageConfigurations");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  PackageConfigurations PackageConfigurations_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <PackageConfigurations> (parent, PackageConfigurations_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfigurations_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PackageConfigurations (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_PackageConfigurationContainers
  //
  size_t PackageConfigurations_Impl::get_PackageConfigurationContainers (std::vector <PackageConfigurationContainer> & items) const
  {
    return this->children (items);
  }
}

