// $Id$

#include "StdAfx.h"
#include "dw_lifespan_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_lifespan_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/QoSPolicies/LifespanQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_lifespan_Connection_Impl::metaname ("dw_lifespan_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dw_lifespan_Connection dw_lifespan_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dw_lifespan_Connection > (parent, dw_lifespan_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dw_lifespan_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dw_lifespan_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dw_lifespan_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataWriter
  //
  DataWriter dw_lifespan_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // LifespanQosPolicy
  //
  LifespanQosPolicy dw_lifespan_Connection_Impl::dst_LifespanQosPolicy (void) const
  {
    return LifespanQosPolicy::_narrow (this->dst ());
  }
}

