// $Id$

#include "StdAfx.h"
#include "pub_presqos_Connection.h"

#if !defined (__GAME_INLINE__)
#include "pub_presqos_Connection.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/Main/DDSQoS.h"
#include "DQML/Standard/DDSEntities/Publisher.h"
#include "DQML/Standard/QoSPolicies/PresentationQosPolicy.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string pub_presqos_Connection_Impl::metaname ("pub_presqos_Connection");

  //
  // _create (const DDSQoS_in)
  //
  pub_presqos_Connection pub_presqos_Connection_Impl::_create (const DDSQoS_in parent)
  {
    return ::GAME::Mga::create_object < pub_presqos_Connection > (parent, pub_presqos_Connection_Impl::metaname);
  }

  //
  // accept
  //
  void pub_presqos_Connection_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_pub_presqos_Connection (this);
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
  Publisher pub_presqos_Connection_Impl::src_Publisher (void) const
  {
    return Publisher::_narrow (this->src ());
  }

  //
  // PresentationQosPolicy
  //
  PresentationQosPolicy pub_presqos_Connection_Impl::dst_PresentationQosPolicy (void) const
  {
    return PresentationQosPolicy::_narrow (this->dst ());
  }
}

