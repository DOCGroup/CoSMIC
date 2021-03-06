#include "StdAfx.h"
#include "PublishesConnection.h"

#if !defined (__GAME_INLINE__)
#include "PublishesConnection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DomainQos/Domain.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string PublishesConnection_Impl::metaname ("PublishesConnection");

  //
  // is_abstract
  //
  const bool PublishesConnection_Impl::is_abstract = false;

  //
  // _create (const Domain_in, DataWriterQos_in src, DataReaderQos_in dst)
  //
  PublishesConnection PublishesConnection_Impl::_create (const Domain_in parent, DataWriterQos_in src, DataReaderQos_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PublishesConnection_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PublishesConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PublishesConnection (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_Domain
  //
  Domain PublishesConnection_Impl::parent_Domain (void)
  {
    return Domain::_narrow (this->parent ());
  }

  //
  // DataWriterQos
  //
  DataWriterQos PublishesConnection_Impl::src_DataWriterQos (void) const
  {
    return DataWriterQos::_narrow (this->src ());
  }

  //
  // DataReaderQos
  //
  DataReaderQos PublishesConnection_Impl::dst_DataReaderQos (void) const
  {
    return DataReaderQos::_narrow (this->dst ());
  }
}

