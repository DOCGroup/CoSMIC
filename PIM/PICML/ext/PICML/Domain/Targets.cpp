// $Id$

#include "StdAfx.h"
#include "Targets.h"

#if !defined (__GAME_INLINE__)
#include "Targets.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Domain/Domain.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Targets_Impl::metaname ("Targets");

  //
  // is_abstract
  //
  const bool Targets_Impl::is_abstract = false;

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  Targets Targets_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <Targets> (parent, Targets_Impl::metaname);
  }

  //
  // accept
  //
  void Targets_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Targets (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder Targets_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_Domains
  //
  size_t Targets_Impl::get_Domains (std::vector <Domain> & items) const
  {
    return this->children (items);
  }

  //
  // get_Domains
  //
  ::GAME::Mga::Collection_T <Domain> Targets_Impl::get_Domains (void) const
  {
    return this->children <Domain> ();
  }
}

