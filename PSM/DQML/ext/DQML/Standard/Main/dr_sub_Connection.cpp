// $Id$

#include "StdAfx.h"
#include "dr_sub_Connection.h"

#if !defined (__GAME_INLINE__)
#include "dr_sub_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/DataReader.h"
#include "DQML/Standard/DDSEntities/Subscriber.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string dr_sub_Connection_Impl::metaname ("dr_sub_Connection");

  //
  // _create (const DDSQoS_in)
  //
  dr_sub_Connection dr_sub_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < dr_sub_Connection > (parent, dr_sub_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void dr_sub_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_dr_sub_Connection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // Subscriber
  //
  Subscriber dr_sub_Connection_Impl::src_Subscriber (void) const
  {
    return Subscriber::_narrow (this->src ());
  }

  //
  // DataReader
  //
  DataReader dr_sub_Connection_Impl::dst_DataReader (void) const
  {
    return DataReader::_narrow (this->dst ());
  }
}

