#include "StdAfx.h"
#include "ShareQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "ShareQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/PublisherSubscriberQos/SubscriberQos.h"
#include "DQML/iCCM/DataReaderQos/DataReaderQos.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string ShareQosPolicy_Impl::metaname ("ShareQosPolicy");

  //
  // is_abstract
  //
  const bool ShareQosPolicy_Impl::is_abstract = false;

  //
  // _create (const SubscriberQos_in)
  //
  ShareQosPolicy ShareQosPolicy_Impl::_create (const SubscriberQos_in parent)
  {
    return ::GAME::Mga::create < ShareQosPolicy > (parent, ShareQosPolicy_Impl::metaname);
  }

  //
  // _create (const DataReaderQos_in)
  //
  ShareQosPolicy ShareQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < ShareQosPolicy > (parent, ShareQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  ShareQosPolicy ShareQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < ShareQosPolicy > (parent, ShareQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void ShareQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ShareQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_SubscriberQos
  //
  SubscriberQos ShareQosPolicy_Impl::parent_SubscriberQos (void)
  {
    return SubscriberQos::_narrow (this->parent ());
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos ShareQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }
}

