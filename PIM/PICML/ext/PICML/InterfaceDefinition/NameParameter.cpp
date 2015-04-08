#include "StdAfx.h"
#include "NameParameter.h"

#if !defined (__GAME_INLINE__)
#include "NameParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string NameParameter_Impl::metaname ("NameParameter");

  //
  // is_abstract
  //
  const bool NameParameter_Impl::is_abstract = false;

  //
  // _create (const Package_in)
  //
  NameParameter NameParameter_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < NameParameter > (parent, NameParameter_Impl::metaname);
  }

  //
  // accept
  //
  void NameParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_NameParameter (this);
    else
      v->visit_Atom (this);
  }
}

