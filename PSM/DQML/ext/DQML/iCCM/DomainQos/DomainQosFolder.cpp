// $Id$

#include "StdAfx.h"
#include "DomainQosFolder.h"

#if !defined (__GAME_INLINE__)
#include "DomainQosFolder.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DomainQos/Domain.h"
#include "DQML/iCCM/iCCM/iCCM.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace DQML
{
  //
  // metaname
  //
  const std::string DomainQosFolder_Impl::metaname ("DomainQosFolder");

  //
  // _create (const iCCM_in)
  //
  DomainQosFolder DomainQosFolder_Impl::_create (const iCCM_in parent)
  {
    return ::GAME::Mga::create < DomainQosFolder > (parent, DomainQosFolder_Impl::metaname);
  }

  //
  // accept
  //
  void DomainQosFolder_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DomainQosFolder (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_iCCM
  //
  iCCM DomainQosFolder_Impl::parent_iCCM (void)
  {
    return iCCM::_narrow (this->parent ());
  }

  //
  // get_Domains
  //
  size_t DomainQosFolder_Impl::get_Domains (std::vector <Domain> & items) const
  {
    return this->children (items);
  }

  //
  // get_Domains
  //
  ::GAME::Mga::Collection_T <Domain> DomainQosFolder_Impl::get_Domains (void) const
  {
    return this->children <Domain> ();
  }
}

