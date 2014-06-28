// $Id$

#include "StdAfx.h"
#include "Paths.h"

#if !defined (__GAME_INLINE__)
#include "Paths.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/PathDiagram/PathDiagrams.h"
#include "PICML/PathDiagram/Path.h"
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
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Paths (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_PathDiagrams
  //
  PathDiagrams Paths_Impl::parent_PathDiagrams (void)
  {
    return PathDiagrams::_narrow (this->parent ());
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
  ::GAME::Mga::Collection_T <PathProperty> Paths_Impl::get_PathPropertys (void) const
  {
    return this->children <PathProperty> ();
  }

  //
  // get_ComplexPropertys
  //
  size_t Paths_Impl::get_ComplexPropertys (std::vector <ComplexProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ComplexPropertys
  //
  ::GAME::Mga::Collection_T <ComplexProperty> Paths_Impl::get_ComplexPropertys (void) const
  {
    return this->children <ComplexProperty> ();
  }

  //
  // get_SimplePropertys
  //
  size_t Paths_Impl::get_SimplePropertys (std::vector <SimpleProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_SimplePropertys
  //
  ::GAME::Mga::Collection_T <SimpleProperty> Paths_Impl::get_SimplePropertys (void) const
  {
    return this->children <SimpleProperty> ();
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
  ::GAME::Mga::Collection_T <Path> Paths_Impl::get_Paths (void) const
  {
    return this->children <Path> ();
  }
}

