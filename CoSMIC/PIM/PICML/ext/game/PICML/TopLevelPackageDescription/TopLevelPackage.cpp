// $Id$

#include "StdAfx.h"
#include "TopLevelPackage.h"

#if !defined (__GAME_INLINE__)
#include "TopLevelPackage.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackageContainer.h"
#include "PICML/TopLevelPackageDescription/package.h"
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
  // _create (const TopLevelPackageContainer_in)
  //
  TopLevelPackage TopLevelPackage_Impl::_create (const TopLevelPackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < TopLevelPackage > (parent, TopLevelPackage_Impl::metaname);
  }

  //
  // accept
  //
  void TopLevelPackage_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TopLevelPackage (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // src_package
  //
  size_t TopLevelPackage_Impl::src_package (std::vector <package> & items) const
  {
    return this->in_connections <package> (items);
  }
}

