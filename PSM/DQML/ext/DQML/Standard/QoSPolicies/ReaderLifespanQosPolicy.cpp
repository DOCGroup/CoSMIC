// $Id$

#include "StdAfx.h"
#include "ReaderLifespanQosPolicy.h"

#if !defined (__GAME_INLINE__)
#include "ReaderLifespanQosPolicy.inl"
#endif

#include "DQML/Visitor.h"
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
  const std::string ReaderLifespanQosPolicy_Impl::metaname ("ReaderLifespanQosPolicy");

  //
  // is_abstract
  //
  const bool ReaderLifespanQosPolicy_Impl::is_abstract = false;

  //
  // _create (const DataReaderQos_in)
  //
  ReaderLifespanQosPolicy ReaderLifespanQosPolicy_Impl::_create (const DataReaderQos_in parent)
  {
    return ::GAME::Mga::create < ReaderLifespanQosPolicy > (parent, ReaderLifespanQosPolicy_Impl::metaname);
  }

  //
  // _create (const DDSQoS_in)
  //
  ReaderLifespanQosPolicy ReaderLifespanQosPolicy_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create < ReaderLifespanQosPolicy > (parent, ReaderLifespanQosPolicy_Impl::metaname);
  }

  //
  // accept
  //
  void ReaderLifespanQosPolicy_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ReaderLifespanQosPolicy (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_DataReaderQos
  //
  DataReaderQos ReaderLifespanQosPolicy_Impl::parent_DataReaderQos (void)
  {
    return DataReaderQos::_narrow (this->parent ());
  }
}

