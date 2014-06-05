// $Id$

#include "StdAfx.h"
#include "QoSPolicy.h"

#if !defined (__GAME_INLINE__)
#include "QoSPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"

namespace DQML
{
  //
  // metaname
  //
  const std::string QoSPolicy_Impl::metaname ("QoSPolicy");

  //
  // parent_DDSQoS
  //
  DDSQoS QoSPolicy_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }
}

