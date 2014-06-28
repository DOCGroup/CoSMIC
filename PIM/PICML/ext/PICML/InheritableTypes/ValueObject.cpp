// $Id$

#include "StdAfx.h"
#include "ValueObject.h"

#if !defined (__GAME_INLINE__)
#include "ValueObject.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ValueObject_Impl::metaname ("ValueObject");

  //
  // _create (const Package_in)
  //
  ValueObject ValueObject_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < ValueObject > (parent, ValueObject_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  ValueObject ValueObject_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < ValueObject > (parent, ValueObject_Impl::metaname);
  }

  //
  // accept
  //
  void ValueObject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ValueObject (this);
    else
      v->visit_Model (this);
  }
}

