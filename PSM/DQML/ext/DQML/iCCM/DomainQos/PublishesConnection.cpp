// $Id$

#include "StdAfx.h"
#include "PublishesConnection.h"

#if !defined (__GAME_INLINE__)
#include "PublishesConnection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DomainQos/Domain.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
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
  // _create (const Domain_in)
  //
  PublishesConnection PublishesConnection_Impl::_create (const Domain_in parent)
  {
    return ::GAME::Mga::create_object < PublishesConnection > (parent, PublishesConnection_Impl::metaname);
  }

  //
  // accept
  //
  void PublishesConnection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PublishesConnection (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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
