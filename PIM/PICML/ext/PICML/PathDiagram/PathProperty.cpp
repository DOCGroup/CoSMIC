// $Id$

#include "StdAfx.h"
#include "PathProperty.h"

#if !defined (__GAME_INLINE__)
#include "PathProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/PathDiagram/Paths.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PathProperty_Impl::metaname ("PathProperty");

  //
  // is_abstract
  //
  const bool PathProperty_Impl::is_abstract = false;

  //
  // _create (const Paths_in, Path_in src, Property_in dst)
  //
  PathProperty PathProperty_Impl::_create (const Paths_in parent, Path_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PathProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PathProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PathProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Paths
  //
  Paths PathProperty_Impl::parent_Paths (void)
  {
    return Paths::_narrow (this->parent ());
  }

  //
  // Path
  //
  Path PathProperty_Impl::src_Path (void) const
  {
    return Path::_narrow (this->src ());
  }

  //
  // Property
  //
  Property PathProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

