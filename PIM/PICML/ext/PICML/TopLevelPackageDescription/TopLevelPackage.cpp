// $Id$

#include "StdAfx.h"
#include "TopLevelPackage.h"

#if !defined (__GAME_INLINE__)
#include "TopLevelPackage.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/package.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TopLevelPackage_Impl::metaname ("TopLevelPackage");

  //
  // is_abstract
  //
  const bool TopLevelPackage_Impl::is_abstract = false;

  //
  // _create (const TopLevelPackageContainer_in)
  //
  TopLevelPackage TopLevelPackage_Impl::_create (const TopLevelPackageContainer_in parent)
  {
    return ::GAME::Mga::create < TopLevelPackage > (parent, TopLevelPackage_Impl::metaname);
  }

  //
  // accept
  //
  void TopLevelPackage_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TopLevelPackage (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_TopLevelPackageContainer
  //
  TopLevelPackageContainer TopLevelPackage_Impl::parent_TopLevelPackageContainer (void)
  {
    return TopLevelPackageContainer::_narrow (this->parent ());
  }

  //
  // src_of_package
  //
  size_t TopLevelPackage_Impl::src_of_package (std::vector <package> & items) const
  {
    return this->in_connections <package> (items);
  }

  //
  // src_of_package
  //
  package TopLevelPackage_Impl::src_of_package (void) const
  {
    return this->in_connections <package> ("src").first ();
  }
}

