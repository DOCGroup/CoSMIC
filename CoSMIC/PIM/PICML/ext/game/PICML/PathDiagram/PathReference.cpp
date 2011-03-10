// $Id$

#include "stdafx.h"
#include "PathReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PathDiagram/Path.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PathReference_Impl::metaname = "PathReference";

  //
  // PathReference_Impl
  //
  PathReference_Impl::PathReference_Impl (void)
  {
  }

  //
  // PathReference_Impl
  //
  PathReference_Impl::PathReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PathReference_Impl
  //
  PathReference_Impl::~PathReference_Impl (void)
  {
  }

  //
  // accept
  //
  void PathReference_Impl::accept (Visitor * v)
  {
    v->visit_PathReference (this);
  }

  //
  // refers_to_Path
  //
  Path PathReference_Impl::refers_to_Path (void) const
  {
    return ::GAME::Mga::get_refers_to <Path> (this);
  }
}

