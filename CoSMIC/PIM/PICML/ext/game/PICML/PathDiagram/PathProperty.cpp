// $Id$

#include "stdafx.h"
#include "PathProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Paths.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PathProperty_Impl::metaname = "PathProperty";

  //
  // PathProperty_Impl
  //
  PathProperty_Impl::PathProperty_Impl (void)
  {
  }

  //
  // PathProperty_Impl
  //
  PathProperty_Impl::PathProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PathProperty_Impl
  //
  PathProperty_Impl::~PathProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void PathProperty_Impl::accept (Visitor * v)
  {
    v->visit_PathProperty (this);
  }

  //
  // _create
  //
  PathProperty PathProperty_Impl::_create (const Paths_in parent)
  {
    return ::GAME::Mga::create_object <PathProperty> (parent, PathProperty_Impl::metaname);
  }

  //
  // src_Path
  //
  Path PathProperty_Impl::src_Path (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Path::_narrow (target);
  }

  //
  // dst_Property
  //
  Property PathProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }

  //
  // parent_Paths
  //
  Paths PathProperty_Impl::parent_Paths (void) const
  {
    return ::GAME::Mga::get_parent <Paths> (this->object_.p);
  }
}

