// $Id$

#include "stdafx.h"
#include "SendsTo.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortEnd.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortEnd.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SendsTo_Impl::metaname = "SendsTo";

  //
  // SendsTo_Impl
  //
  SendsTo_Impl::SendsTo_Impl (void)
  {
  }

  //
  // SendsTo_Impl
  //
  SendsTo_Impl::SendsTo_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~SendsTo_Impl
  //
  SendsTo_Impl::~SendsTo_Impl (void)
  {
  }

  //
  // accept
  //
  void SendsTo_Impl::accept (Visitor * v)
  {
    v->visit_SendsTo (this);
  }

  //
  // src_OutEventPortEnd
  //
  OutEventPortEnd SendsTo_Impl::src_OutEventPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return OutEventPortEnd::_narrow (target);
  }

  //
  // dst_InEventPortEnd
  //
  InEventPortEnd SendsTo_Impl::dst_InEventPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return InEventPortEnd::_narrow (target);
  }
}

