// $Id$

#include "stdafx.h"
#include "AttributeValue.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/AttributeInstance.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AttributeValue_Impl::metaname = "AttributeValue";

  //
  // AttributeValue_Impl
  //
  AttributeValue_Impl::AttributeValue_Impl (void)
  {
  }

  //
  // AttributeValue_Impl
  //
  AttributeValue_Impl::AttributeValue_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AttributeValue_Impl
  //
  AttributeValue_Impl::~AttributeValue_Impl (void)
  {
  }

  //
  // accept
  //
  void AttributeValue_Impl::accept (Visitor * v)
  {
    v->visit_AttributeValue (this);
  }

  //
  // src_AttributeInstance
  //
  AttributeInstance AttributeValue_Impl::src_AttributeInstance (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return AttributeInstance::_narrow (target);
  }

  //
  // dst_Property
  //
  Property AttributeValue_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }
}

