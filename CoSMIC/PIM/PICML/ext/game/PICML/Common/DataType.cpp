// $Id$

#include "stdafx.h"
#include "DataType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Common/SatisfierProperty.h"
#include "PICML/NamedTypes/MemberType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DataType_Impl::metaname = "DataType";

  //
  // DataType_Impl
  //
  DataType_Impl::DataType_Impl (void)
  {
  }

  //
  // DataType_Impl
  //
  DataType_Impl::DataType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataType_Impl
  //
  DataType_Impl::~DataType_Impl (void)
  {
  }

  //
  // accept
  //
  void DataType_Impl::accept (Visitor * v)
  {
    v->visit_DataType (this);
  }

  //
  // _create
  //
  DataType DataType_Impl::_create (const SatisfierProperty_in parent)
  {
    return ::GAME::Mga::create_object <DataType> (parent, DataType_Impl::metaname);
  }

  //
  // parent_SatisfierProperty
  //
  SatisfierProperty DataType_Impl::parent_SatisfierProperty (void) const
  {
    return ::GAME::Mga::get_parent <SatisfierProperty> (this->object_.p);
  }
}

