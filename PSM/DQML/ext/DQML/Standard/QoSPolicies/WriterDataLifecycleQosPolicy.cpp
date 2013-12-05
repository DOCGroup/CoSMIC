// $Id$

#include "StdAfx.h"
#include "WriterDataLifecycleQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "WriterDataLifecycleQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/WriterDataLifecycleQosPolicy/dw_writerdatalifecycle_Connection.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
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
  // _create (const DataWriterQos_in)
  //
  WriterDataLifecycleQosPolicy WriterDataLifecycleQosPolicy_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < WriterDataLifecycleQosPolicy > (parent, WriterDataLifecycleQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  WriterDataLifecycleQosPolicy WriterDataLifecycleQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < WriterDataLifecycleQosPolicy > (parent, WriterDataLifecycleQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void WriterDataLifecycleQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_WriterDataLifecycleQosPolicy (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // dst_dw_writerdatalifecycle_Connection
  //
  size_t WriterDataLifecycleQosPolicy_Impl::dst_dw_writerdatalifecycle_Connection (std::vector <dw_writerdatalifecycle_Connection> & items) const
  {
    return this->in_connections <dw_writerdatalifecycle_Connection> (items);
  }
}

