// $Id$

#include "StdAfx.h"
#include "TopicQosReference.h"

#if !defined (__GAME_INLINE__)
#include "TopicQosReference.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DataWriterQos/DataWriterQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string TopicQosReference_Impl::metaname ("TopicQosReference");

  //
  // _create (const DataWriterQos_in)
  //
  TopicQosReference TopicQosReference_Impl::_create (const DataWriterQos_in parent)
  {
    return ::GAME::Mga::create_object < TopicQosReference > (parent, TopicQosReference_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  TopicQosReference TopicQosReference_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create_object < TopicQosReference > (parent, TopicQosReference_Impl::metaname);
  }

  //
  // accept
  //
  void TopicQosReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TopicQosReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_DataWriterQos
  //
  DataWriterQos TopicQosReference_Impl::parent_DataWriterQos (void)
  {
    return DataWriterQos::_narrow (this->parent ());
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos TopicQosReference_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }

  //
  // TopicQos_is_nil
  //
  bool TopicQosReference_Impl::TopicQos_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_TopicQos
  //
  void TopicQosReference_Impl::set_TopicQos (TopicQos_in item)
  {
    this->refers_to (item);
  }

  //
  // get_TopicQos
  //
  TopicQos TopicQosReference_Impl::get_TopicQos (void) const
  {
    return TopicQos::_narrow (this->refers_to ());
  }
}

