// $Id$

#include "StdAfx.h"
#include "DataValueBase.h"

#if !defined (__GAME_INLINE__)
#include "DataValueBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/DataValueContainer.h"
#include "PICML/Common/ComplexProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DataValueBase_Impl::metaname ("DataValueBase");

  //
  // parent_DataValueContainer
  //
  DataValueContainer DataValueBase_Impl::parent_DataValueContainer (void)
  {
    return DataValueContainer::_narrow (this->parent ());
  }

  //
  // parent_ComplexProperty
  //
  ComplexProperty DataValueBase_Impl::parent_ComplexProperty (void)
  {
    return ComplexProperty::_narrow (this->parent ());
  }
}

