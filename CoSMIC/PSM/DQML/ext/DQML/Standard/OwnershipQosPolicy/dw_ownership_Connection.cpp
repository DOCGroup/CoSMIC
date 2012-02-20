// $Id$

#include "StdAfx.h"
#include "dw_ownership_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_ownership_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/QoSPolicies/OwnershipQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_ownership_Connection_Impl::metaname ("dw_ownership_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dw_ownership_Connection dw_ownership_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dw_ownership_Connection > (parent, dw_ownership_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dw_ownership_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dw_ownership_Connection (this);
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
  DataWriter dw_ownership_Connection_Impl::src_DataWriter (void) const
  {
    return DataWriter::_narrow (this->src ());
  }

  //
  // OwnershipQosPolicy
  //
  OwnershipQosPolicy dw_ownership_Connection_Impl::dst_OwnershipQosPolicy (void) const
  {
    return OwnershipQosPolicy::_narrow (this->dst ());
  }
}

