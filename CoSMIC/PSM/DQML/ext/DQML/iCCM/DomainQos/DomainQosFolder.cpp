// $Id$

#include "StdAfx.h"
#include "DomainQosFolder.h"

#if !defined (__GAME_INLINE__)
#include "DomainQosFolder.inl"
#endif

#include "DQML/Visitor.h"
#include "DQML/iCCM/DomainQos/DomainQosFolder.h"
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
    return ::GAME::Mga::create_root_object < DomainQosFolder > (parent, DomainQosFolder_Impl::metaname);
  }

  //
  // accept
  //
  void DomainQosFolder_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_DomainQosFolder (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_DomainQosFolders
  //
  size_t DomainQosFolder_Impl::get_DomainQosFolders (std::vector <DomainQosFolder> & items) const
  {
    return this->folders (items);
  }

  //
  // get_Domains
  //
  size_t DomainQosFolder_Impl::get_Domains (std::vector <Domain> & items) const
  {
    return this->children (items);
  }
}

