// $Id$

#include "StdAfx.h"
#include "PredefinedTypes.h"

#if !defined (__GAME_INLINE__)
#include "PredefinedTypes.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PredefinedTypes_Impl::metaname ("PredefinedTypes");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  PredefinedTypes PredefinedTypes_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <PredefinedTypes> (parent, PredefinedTypes_Impl::metaname);
  }

  //
  // accept
  //
  void PredefinedTypes_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PredefinedTypes (this);
    else
      v->visit_Folder (this);
  }

  //
  // get_PredefinedTypes
  //
  size_t PredefinedTypes_Impl::get_PredefinedTypes (std::vector <PredefinedType> & items) const
  {
    return this->children (items);
  }
}

