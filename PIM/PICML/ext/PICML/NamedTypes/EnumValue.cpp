#include "StdAfx.h"
#include "EnumValue.h"

#if !defined (__GAME_INLINE__)
#include "EnumValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Enum.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string EnumValue_Impl::metaname ("EnumValue");

  //
  // is_abstract
  //
  const bool EnumValue_Impl::is_abstract = false;

  //
  // _create (const Enum_in)
  //
  EnumValue EnumValue_Impl::_create (const Enum_in parent)
  {
    return ::GAME::Mga::create < EnumValue > (parent, EnumValue_Impl::metaname);
  }

  //
  // accept
  //
  void EnumValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_EnumValue (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_Enum
  //
  Enum EnumValue_Impl::parent_Enum (void)
  {
    return Enum::_narrow (this->parent ());
  }
}

