// $Id$

#include "stdafx.h"
#include "EdgeProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/Common/Property.h"
#include "PICML/PathDiagram/Edge.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string EdgeProperty_Impl::metaname = "EdgeProperty";

  //
  // EdgeProperty_Impl
  //
  EdgeProperty_Impl::EdgeProperty_Impl (void)
  {
  }

  //
  // EdgeProperty_Impl
  //
  EdgeProperty_Impl::EdgeProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EdgeProperty_Impl
  //
  EdgeProperty_Impl::~EdgeProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void EdgeProperty_Impl::accept (Visitor * v)
  {
    v->visit_EdgeProperty (this);
  }

  //
  // _create
  //
  EdgeProperty EdgeProperty_Impl::_create (const Path_in parent)
  {
    return ::GAME::Mga::create_object <EdgeProperty> (parent, EdgeProperty_Impl::metaname);
  }

  //
  // src_Property
  //
  Property EdgeProperty_Impl::src_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Property::_narrow (target);
  }

  //
  // dst_Edge
  //
  Edge EdgeProperty_Impl::dst_Edge (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Edge::_narrow (target);
  }

  //
  // parent_Path
  //
  Path EdgeProperty_Impl::parent_Path (void) const
  {
    return ::GAME::Mga::get_parent <Path> (this->object_.p);
  }
}

