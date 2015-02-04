// $Id$

#include "StdAfx.h"
#include "DataValueBase.h"

#if !defined (__GAME_INLINE__)
#include "DataValueBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/DataValueContainer.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DataValueBase_Impl::metaname ("DataValueBase");

  //
  // is_abstract
  //
  const bool DataValueBase_Impl::is_abstract = true;

  //
  // parent_ComplexProperty
  //
  ComplexProperty DataValueBase_Impl::parent_ComplexProperty (void)
  {
    return ComplexProperty::_narrow (this->parent ());
  }

  //
  // parent_DataValueContainer
  //
  DataValueContainer DataValueBase_Impl::parent_DataValueContainer (void)
  {
    return DataValueContainer::_narrow (this->parent ());
  }
}

