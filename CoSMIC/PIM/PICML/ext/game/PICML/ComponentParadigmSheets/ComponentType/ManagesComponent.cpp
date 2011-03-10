// $Id$

#include "stdafx.h"
#include "ManagesComponent.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Manageable.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ManagesComponent_Impl::metaname = "ManagesComponent";

  //
  // ManagesComponent_Impl
  //
  ManagesComponent_Impl::ManagesComponent_Impl (void)
  {
  }

  //
  // ManagesComponent_Impl
  //
  ManagesComponent_Impl::ManagesComponent_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ManagesComponent_Impl
  //
  ManagesComponent_Impl::~ManagesComponent_Impl (void)
  {
  }

  //
  // accept
  //
  void ManagesComponent_Impl::accept (Visitor * v)
  {
    v->visit_ManagesComponent (this);
  }

  //
  // src_ComponentFactory
  //
  ComponentFactory ManagesComponent_Impl::src_ComponentFactory (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentFactory::_narrow (target);
  }

  //
  // dst_Manageable
  //
  Manageable ManagesComponent_Impl::dst_Manageable (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Manageable::_narrow (target);
  }
}

