// $Id$

#include "StdAfx.h"
#include "Paths.h"

#if !defined (__GAME_INLINE__)
#include "Paths.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/PathDiagrams.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Paths_Impl::metaname ("Paths");

  //
  // _create (const PathDiagrams_in)
  //
  Paths Paths_Impl::_create (const PathDiagrams_in parent)
  {
    return ::GAME::Mga::create_root_object < Paths > (parent, Paths_Impl::metaname);
  }

  //
  // accept
  //
  void Paths_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Paths (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_Propertys
  //
  size_t Paths_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  ::GAME::Mga::Iterator <Property> Paths_Impl::get_Propertys (void) const
  {
    return this->children <Property> ();
  }

  //
  // get_Paths
  //
  size_t Paths_Impl::get_Paths (std::vector <Path> & items) const
  {
    return this->children (items);
  }

  //
  // get_Paths
  //
  ::GAME::Mga::Iterator <Path> Paths_Impl::get_Paths (void) const
  {
    return this->children <Path> ();
  }

  //
  // get_PathPropertys
  //
  size_t Paths_Impl::get_PathPropertys (std::vector <PathProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_PathPropertys
  //
  ::GAME::Mga::Iterator <PathProperty> Paths_Impl::get_PathPropertys (void) const
  {
    return this->children <PathProperty> ();
  }
}

