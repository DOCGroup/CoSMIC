// $Id$

#include "StdAfx.h"
#include "dw_pub_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_pub_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
#include "DQML/Standard/DDSEntities/Publisher.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dw_pub_Connection_Impl::metaname ("dw_pub_Connection");

  //
  // is_abstract
  //
  const bool dw_pub_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, Publisher_in src, DataWriter_in dst)
  //
  dw_pub_Connection dw_pub_Connection_Impl::_create (const DDSQoS_in parent, Publisher_in src, DataWriter_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dw_pub_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dw_pub_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dw_pub_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dw_pub_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
  }

  //
  // Publisher
  //
  Publisher dw_pub_Connection_Impl::src_Publisher (void) const
  {
    return Publisher::_narrow (this->src ());
  }

  //
  // DataWriter
  //
  DataWriter dw_pub_Connection_Impl::dst_DataWriter (void) const
  {
    return DataWriter::_narrow (this->dst ());
  }
}

