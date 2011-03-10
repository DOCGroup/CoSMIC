// $Id$

#include "stdafx.h"
#include "RequiredRequestPort.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Provideable.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequiredRequestPort_Impl::metaname = "RequiredRequestPort";

  //
  // RequiredRequestPort_Impl
  //
  RequiredRequestPort_Impl::RequiredRequestPort_Impl (void)
  {
  }

  //
  // RequiredRequestPort_Impl
  //
  RequiredRequestPort_Impl::RequiredRequestPort_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequiredRequestPort_Impl
  //
  RequiredRequestPort_Impl::~RequiredRequestPort_Impl (void)
  {
  }

  //
  // accept
  //
  void RequiredRequestPort_Impl::accept (Visitor * v)
  {
    v->visit_RequiredRequestPort (this);
  }

  //
  // AsyncCommunication
  //
  void RequiredRequestPort_Impl::AsyncCommunication (bool val)
  {
    static const std::string attr_AsyncCommunication ("AsyncCommunication");
    this->attribute (attr_AsyncCommunication)->bool_value (val);
  }

  //
  // AsyncCommunication
  //
  bool RequiredRequestPort_Impl::AsyncCommunication (void) const
  {
    static const std::string attr_AsyncCommunication ("AsyncCommunication");
    return this->attribute (attr_AsyncCommunication)->bool_value ();
  }

  //
  // multiple_connections
  //
  void RequiredRequestPort_Impl::multiple_connections (bool val)
  {
    static const std::string attr_multiple_connections ("multiple_connections");
    this->attribute (attr_multiple_connections)->bool_value (val);
  }

  //
  // multiple_connections
  //
  bool RequiredRequestPort_Impl::multiple_connections (void) const
  {
    static const std::string attr_multiple_connections ("multiple_connections");
    return this->attribute (attr_multiple_connections)->bool_value ();
  }

  //
  // refers_to_Provideable
  //
  Provideable RequiredRequestPort_Impl::refers_to_Provideable (void) const
  {
    return ::GAME::Mga::get_refers_to <Provideable> (this);
  }
}

