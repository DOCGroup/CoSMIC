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
  // is_abstract
  //
  const bool dr_sub_Connection_Impl::is_abstract = false;

  //
  // _create (const DDSQoS_in, Subscriber_in src, DataReader_in dst)
  //
  dr_sub_Connection dr_sub_Connection_Impl::_create (const DDSQoS_in parent, Subscriber_in src, DataReader_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, dr_sub_Connection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void dr_sub_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_dr_sub_Connection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_DDSQoS
  //
  DDSQoS dr_sub_Connection_Impl::parent_DDSQoS (void)
  {
    return DDSQoS::_narrow (this->parent ());
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

