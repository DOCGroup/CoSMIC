// $Id$

#include "StdAfx.h"
#include "StringSeq_Item.h"

#if !defined (__GAME_INLINE__)
#include "StringSeq_Item.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/Standard/QoSPolicies/StringSeq.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string StringSeq_Item_Impl::metaname ("StringSeq_Item");

  //
  // _create (const StringSeq_in)
  //
  StringSeq_Item StringSeq_Item_Impl::_create (const StringSeq_in parent)
  {
    return ::GAME::Mga::create_object < StringSeq_Item > (parent, StringSeq_Item_Impl::metaname);
  }

  //
  // accept
  //
  void StringSeq_Item_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_StringSeq_Item (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_StringSeq
  //
  StringSeq StringSeq_Item_Impl::parent_StringSeq (void)
  {
    return StringSeq::_narrow (this->parent ());
  }
}

