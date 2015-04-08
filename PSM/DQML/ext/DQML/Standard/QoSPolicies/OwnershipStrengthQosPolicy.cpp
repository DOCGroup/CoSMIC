#include "StdAfx.h"
#include "OwnershipStrengthQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "OwnershipStrengthQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/OwnershipStrengthQosPolicy/dw_ownerstrength_Connection.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/Standard/Main/DDSQoS.h"
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
  // is_abstract
  //
  const bool OwnershipStrengthQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataWriterQos_in)
  //
  OwnershipStrengthQosPolicy OwnershipStrengthQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < OwnershipStrengthQosPolicy > (parent, OwnershipStrengthQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  OwnershipStrengthQosPolicy OwnershipStrengthQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < OwnershipStrengthQosPolicy > (parent, OwnershipStrengthQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void OwnershipStrengthQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_OwnershipStrengthQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos OwnershipStrengthQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // dst_of_dw_ownerstrength_Connection
  //
  size_t OwnershipStrengthQosPolicy_Impl::dst_of_dw_ownerstrength_Connection (std::vector <dw_ownerstrength_Connection> & items) const
  {
    return this->in_connections <dw_ownerstrength_Connection> (items);
  }

  //
  // dst_of_dw_ownerstrength_Connection
  //
  GAME::Mga::Collection_T <dw_ownerstrength_Connection> OwnershipStrengthQosPolicy_Impl::dst_of_dw_ownerstrength_Connection (void) const
  {
    return this->in_connections <dw_ownerstrength_Connection> ("dst");
  }
}

