// $Id$

#include "stdafx.h"
#include "DataValueBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/DataValueContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DataValueBase_Impl::metaname = "DataValueBase";

  //
  // DataValueBase_Impl
  //
  DataValueBase_Impl::DataValueBase_Impl (void)
  {
  }

  //
  // DataValueBase_Impl
  //
  DataValueBase_Impl::DataValueBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataValueBase_Impl
  //
  DataValueBase_Impl::~DataValueBase_Impl (void)
  {
  }

  //
  // parent_ComplexProperty
  //
  ComplexProperty DataValueBase_Impl::parent_ComplexProperty (void) const
  {
    return ::GAME::Mga::get_parent <ComplexProperty> (this->object_.p);
  }

  //
  // parent_DataValueContainer
  //
  DataValueContainer DataValueBase_Impl::parent_DataValueContainer (void) const
  {
    return ::GAME::Mga::get_parent <DataValueContainer> (this->object_.p);
  }
}

