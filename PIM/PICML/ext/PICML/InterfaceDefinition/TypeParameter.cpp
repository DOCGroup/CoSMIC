// $Id$

#include "StdAfx.h"
#include "TypeParameter.h"

#if !defined (__GAME_INLINE__)
#include "TypeParameter.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TypeParameter_Impl::metaname ("TypeParameter");

  //
  // _create (const Package_in)
  //
  TypeParameter TypeParameter_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < TypeParameter > (parent, TypeParameter_Impl::metaname);
  }

  //
  // accept
  //
  void TypeParameter_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TypeParameter (this);
    else
      v->visit_Atom (this);
  }
}

