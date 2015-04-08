#include "StdAfx.h"
#include "TopicQosFolder.h"

#if !defined (__GAME_INLINE__)
#include "TopicQosFolder.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/iCCM/iCCM.h"
#include "DQML/iCCM/TopicQos/TopicQos.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string TopicQosFolder_Impl::metaname ("TopicQosFolder");

  //
  // is_abstract
  //
  const bool TopicQosFolder_Impl::is_abstract = false;

  //
  // _create (const iCCM_in)
  //
  TopicQosFolder TopicQosFolder_Impl::_create (const iCCM_in parent)
  {
    return ::GAME::Mga::create < TopicQosFolder > (parent, TopicQosFolder_Impl::metaname);
  }

  //
  // accept
  //
  void TopicQosFolder_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TopicQosFolder (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_iCCM
  //
  iCCM TopicQosFolder_Impl::parent_iCCM (void)
  {
    return iCCM::_narrow (this->parent ());
  }

  //
  // get_TopicQoss
  //
  size_t TopicQosFolder_Impl::get_TopicQoss (std::vector <TopicQos> & items) const
  {
    return this->children (items);
  }

  //
  // get_TopicQoss
  //
  ::GAME::Mga::Collection_T <TopicQos> TopicQosFolder_Impl::get_TopicQoss (void) const
  {
    return this->children <TopicQos> ();
  }
}

