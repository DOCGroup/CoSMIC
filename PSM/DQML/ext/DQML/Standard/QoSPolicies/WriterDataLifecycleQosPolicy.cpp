// $Id$

#include "StdAfx.h"
#include "WriterDataLifecycleQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "WriterDataLifecycleQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/Standard/WriterDataLifecycleQosPolicy/dw_writerdatalifecycle_Connection.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string WriterDataLifecycleQosPolicy_Impl::metaname ("WriterDataLifecycleQosPolicy");

  //
  // is_abstract
  //
  const bool WriterDataLifecycleQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataWriterQos_in)
  //
  WriterDataLifecycleQosPolicy WriterDataLifecycleQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create < WriterDataLifecycleQosPolicy > (parent, WriterDataLifecycleQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  WriterDataLifecycleQosPolicy WriterDataLifecycleQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < WriterDataLifecycleQosPolicy > (parent, WriterDataLifecycleQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void WriterDataLifecycleQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WriterDataLifecycleQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos WriterDataLifecycleQosPolicy_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // dst_of_dw_writerdatalifecycle_Connection
  //
  size_t WriterDataLifecycleQosPolicy_Impl::dst_of_dw_writerdatalifecycle_Connection (std::vector <dw_writerdatalifecycle_Connection> & items) const
  {
    return this->in_connections <dw_writerdatalifecycle_Connection> (items);
  }

  //
  // dst_of_dw_writerdatalifecycle_Connection
  //
  GAME::Mga::Collection_T <dw_writerdatalifecycle_Connection> WriterDataLifecycleQosPolicy_Impl::dst_of_dw_writerdatalifecycle_Connection (void) const
  {
    return this->in_connections <dw_writerdatalifecycle_Connection> ("dst");
  }
}

