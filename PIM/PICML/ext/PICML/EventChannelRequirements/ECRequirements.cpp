// $Id$

#include "StdAfx.h"
#include "ECRequirements.h"

#if !defined (__GAME_INLINE__)
#include "ECRequirements.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/EventChannelRequirements/ECRole.h"
#include "PICML/EventChannelRequirements/ECBehavior.h"
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
  const std::string ECRequirements_Impl::metaname ("ECRequirements");

  //
  // _create (const ComponentAssembly_in)
  //
  ECRequirements ECRequirements_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < ECRequirements > (parent, ECRequirements_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  ECRequirements ECRequirements_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create < ECRequirements > (parent, ECRequirements_Impl::metaname);
  }

  //
  // _create (const PackageConfigurationContainer_in)
  //
  ECRequirements ECRequirements_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create < ECRequirements > (parent, ECRequirements_Impl::metaname);
  }

  //
  // accept
  //
  void ECRequirements_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ECRequirements (this);
    else
      v->visit_Model (this);
  }

  //
  // has_ECBehavior
  //
  bool ECRequirements_Impl::has_ECBehavior (void) const
  {
    return this->children <ECBehavior> ().count () == 1;
  }

  //
  // get_ECBehavior
  //
  ECBehavior ECRequirements_Impl::get_ECBehavior (void) const
  {
    return this->children <ECBehavior> ().first ();
  }

  //
  // get_ECRoles
  //
  size_t ECRequirements_Impl::get_ECRoles (std::vector <ECRole> & items) const
  {
    return this->children (items);
  }

  //
  // get_ECRoles
  //
  ::GAME::Mga::Collection_T <ECRole> ECRequirements_Impl::get_ECRoles (void) const
  {
    return this->children <ECRole> ();
  }
}

