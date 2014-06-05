// $Id$

#include "StdAfx.h"
#include "DomainEntity.h"

#if !defined (__GAME_INLINE__)
#include "DomainEntity.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"

namespace DQML
{
  //
  // metaname
  //
  const std::string DomainEntity_Impl::metaname ("DomainEntity");

  //
  // parent_DDSQoS
  //
  DDSQoS DomainEntity_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }
}

