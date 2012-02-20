// $Id$

#include "StdAfx.h"
#include "dw_pub_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dw_pub_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Publisher.h"
#include "DQML/Standard/DDSEntities/DataWriter.h"
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
  // _create (const DDSQoS_in)
  //
  dw_pub_Connection dw_pub_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dw_pub_Connection > (parent, dw_pub_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dw_pub_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dw_pub_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

