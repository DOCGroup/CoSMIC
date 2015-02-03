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
  // is_abstract
  //
  const bool DomainEntity_Impl::is_abstract (1);

  //
  // parent_DDSQoS
  //
  DDSQoS DomainEntity_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }
}

