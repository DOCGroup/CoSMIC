// $Id$

#include "StdAfx.h"
#include "dr_deadline_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dr_deadline_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/DeadlineQosPolicy.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataReader.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dr_deadline_Connection_Impl::metaname ("dr_deadline_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dr_deadline_Connection dr_deadline_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dr_deadline_Connection > (parent, dr_deadline_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dr_deadline_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dr_deadline_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dr_deadline_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // DataReader
  //
  DataReader dr_deadline_Connection_Impl::src_DataReader (void) const
  {
    return DataReader::_narrow (this->src ());
  }

  //
  // DeadlineQosPolicy
  //
  DeadlineQosPolicy dr_deadline_Connection_Impl::dst_DeadlineQosPolicy (void) const
  {
    return DeadlineQosPolicy::_narrow (this->dst ());
  }
}

