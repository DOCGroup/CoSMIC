// $Id$

#include "stdafx.h"
#include "ConnectorInherits.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorInherits_Impl::metaname = "ConnectorInherits";

  //
  // ConnectorInherits_Impl
  //
  ConnectorInherits_Impl::ConnectorInherits_Impl (void)
  {
  }

  //
  // ConnectorInherits_Impl
  //
  ConnectorInherits_Impl::ConnectorInherits_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorInherits_Impl
  //
  ConnectorInherits_Impl::~ConnectorInherits_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorInherits_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorInherits (this);
  }

  //
  // _create
  //
  ConnectorInherits ConnectorInherits_Impl::_create (const ConnectorObject_in parent)
  {
    return ::GAME::Mga::create_object <ConnectorInherits> (parent, ConnectorInherits_Impl::metaname);
  }

  //
  // parent_ConnectorObject
  //
  ConnectorObject ConnectorInherits_Impl::parent_ConnectorObject (void) const
  {
    return ::GAME::Mga::get_parent <ConnectorObject> (this->object_.p);
  }

  //
  // refers_to_ConnectorObject
  //
  ConnectorObject ConnectorInherits_Impl::refers_to_ConnectorObject (void) const
  {
    return ::GAME::Mga::get_refers_to <ConnectorObject> (this);
  }
}

