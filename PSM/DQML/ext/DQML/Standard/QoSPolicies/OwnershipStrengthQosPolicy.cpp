// $Id$

#include "StdAfx.h"
#include "OwnershipStrengthQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "OwnershipStrengthQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/OwnershipStrengthQosPolicy/dw_ownerstrength_Connection.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string OwnershipStrengthQosPolicy_Impl::metaname ("OwnershipStrengthQosPolicy");

  //
  // _create (const DataWriterQos_in)
  //
  OwnershipStrengthQosPolicy OwnershipStrengthQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < OwnershipStrengthQosPolicy > (parent, OwnershipStrengthQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  OwnershipStrengthQosPolicy OwnershipStrengthQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < OwnershipStrengthQosPolicy > (parent, OwnershipStrengthQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void OwnershipStrengthQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_OwnershipStrengthQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dw_ownerstrength_Connection
  //
  size_t OwnershipStrengthQosPolicy_Impl::dst_dw_ownerstrength_Connection (std::vector <dw_ownerstrength_Connection> & items) const
  {
    return this->in_connections <dw_ownerstrength_Connection> (items);
  }
}

