// $Id$

#include "StdAfx.h"
#include "dw_deadline_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_deadline_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/QoSPolicies/DeadlineQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_deadline_Connection_Impl::metaname ("dw_deadline_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dw_deadline_Connection dw_deadline_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dw_deadline_Connection > (parent, dw_deadline_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dw_deadline_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dw_deadline_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // DataWriter
  //
  DataWriter dw_deadline_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // DeadlineQosPolicy
  //
  DeadlineQosPolicy dw_deadline_Connection_Impl::dst_DeadlineQosPolicy (void) const
  {
    return DeadlineQosPolicy::_narrow (this->dst ());
  }
}

