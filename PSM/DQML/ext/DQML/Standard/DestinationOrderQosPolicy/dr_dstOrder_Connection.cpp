// $Id$

#include "StdAfx.h"
#include "dr_dstOrder_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dr_dstOrder_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataReader.h"
#include "DQML/Standard/QoSPolicies/DestinationOrderQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dr_dstOrder_Connection_Impl::metaname ("dr_dstOrder_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dr_dstOrder_Connection dr_dstOrder_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dr_dstOrder_Connection > (parent, dr_dstOrder_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dr_dstOrder_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dr_dstOrder_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // DataReader
  //
  DataReader dr_dstOrder_Connection_Impl::src_DataReader (void) const
  {
    return DataReader::_narrow (this->src ());
  }

  //
  // DestinationOrderQosPolicy
  //
  DestinationOrderQosPolicy dr_dstOrder_Connection_Impl::dst_DestinationOrderQosPolicy (void) const
  {
    return DestinationOrderQosPolicy::_narrow (this->dst ());
  }
}

