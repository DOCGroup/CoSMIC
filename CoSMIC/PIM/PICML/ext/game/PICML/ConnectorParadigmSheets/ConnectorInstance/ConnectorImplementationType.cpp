// $Id$

#include "stdafx.h"
#include "ConnectorImplementationType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConnectorImplementationType_Impl::metaname = "ConnectorImplementationType";

  //
  // ConnectorImplementationType_Impl
  //
  ConnectorImplementationType_Impl::ConnectorImplementationType_Impl (void)
  {
  }

  //
  // ConnectorImplementationType_Impl
  //
  ConnectorImplementationType_Impl::ConnectorImplementationType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ConnectorImplementationType_Impl
  //
  ConnectorImplementationType_Impl::~ConnectorImplementationType_Impl (void)
  {
  }

  //
  // accept
  //
  void ConnectorImplementationType_Impl::accept (Visitor * v)
  {
    v->visit_ConnectorImplementationType (this);
  }

  //
  // _create
  //
  ConnectorImplementationType ConnectorImplementationType_Impl::_create (const ConnectorInstance_in parent)
  {
    return ::GAME::Mga::create_object <ConnectorImplementationType> (parent, ConnectorImplementationType_Impl::metaname);
  }

  //
  // parent_ConnectorInstance
  //
  ConnectorInstance ConnectorImplementationType_Impl::parent_ConnectorInstance (void) const
  {
    return ::GAME::Mga::get_parent <ConnectorInstance> (this->object_.p);
  }
}

