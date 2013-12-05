// $Id$

#include "StdAfx.h"
#include "dr_ownership_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dr_ownership_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataReader.h"
#include "DQML/Standard/QoSPolicies/OwnershipQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dr_ownership_Connection_Impl::metaname ("dr_ownership_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dr_ownership_Connection dr_ownership_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dr_ownership_Connection > (parent, dr_ownership_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dr_ownership_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dr_ownership_Connection (this);
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
  DataReader dr_ownership_Connection_Impl::src_DataReader (void) const
  {
    return DataReader::_narrow (this->src ());
  }

  //
  // OwnershipQosPolicy
  //
  OwnershipQosPolicy dr_ownership_Connection_Impl::dst_OwnershipQosPolicy (void) const
  {
    return OwnershipQosPolicy::_narrow (this->dst ());
  }
}

