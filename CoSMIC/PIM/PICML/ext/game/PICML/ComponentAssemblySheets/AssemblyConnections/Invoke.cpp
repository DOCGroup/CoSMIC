// $Id$

#include "stdafx.h"
#include "Invoke.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Invoke_Impl::metaname = "Invoke";

  //
  // Invoke_Impl
  //
  Invoke_Impl::Invoke_Impl (void)
  {
  }

  //
  // Invoke_Impl
  //
  Invoke_Impl::Invoke_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Invoke_Impl
  //
  Invoke_Impl::~Invoke_Impl (void)
  {
  }

  //
  // accept
  //
  void Invoke_Impl::accept (Visitor * v)
  {
    v->visit_Invoke (this);
  }

  //
  // src_RequiredRequestPortEnd
  //
  RequiredRequestPortEnd Invoke_Impl::src_RequiredRequestPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return RequiredRequestPortEnd::_narrow (target);
  }

  //
  // dst_ProvidedRequestPortEnd
  //
  ProvidedRequestPortEnd Invoke_Impl::dst_ProvidedRequestPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ProvidedRequestPortEnd::_narrow (target);
  }
}

