// $Id$

#include "stdafx.h"
#include "Paths.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/PathProperty.h"
#include "PICML/PathDiagram/PathDiagrams.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Paths_Impl::metaname = "Paths";

  //
  // Paths_Impl
  //
  Paths_Impl::Paths_Impl (void)
  {
  }

  //
  // Paths_Impl
  //
  Paths_Impl::Paths_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Paths_Impl
  //
  Paths_Impl::~Paths_Impl (void)
  {
  }

  //
  // accept
  //
  void Paths_Impl::accept (Visitor * v)
  {
    v->visit_Paths (this);
  }

  //
  // _create
  //
  Paths Paths_Impl::_create (const PathDiagrams_in parent)
  {
    return ::GAME::Mga::create_root_object <Paths> (parent, Paths_Impl::metaname);
  }

  //
  // get_Propertys
  //
  size_t Paths_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_Paths
  //
  size_t Paths_Impl::get_Paths (std::vector <Path> & items) const
  {
    return this->children (items);
  }

  //
  // get_PathPropertys
  //
  size_t Paths_Impl::get_PathPropertys (std::vector <PathProperty> & items) const
  {
    return this->children (items);
  }

  //
  // parent_PathDiagrams
  //
  PathDiagrams Paths_Impl::parent_PathDiagrams (void) const
  {
    return ::GAME::Mga::get_parent <PathDiagrams> (this->object_.p);
  }
}

