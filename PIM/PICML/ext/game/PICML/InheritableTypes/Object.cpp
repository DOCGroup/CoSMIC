// $Id$

#include "StdAfx.h"
#include "Object.h"

#if !defined (__GAME_INLINE__)
#include "Object.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/Supports.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Object_Impl::metaname ("Object");

  //
  // _create (const File_in)
  //
  Object Object_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < Object > (parent, Object_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  Object Object_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < Object > (parent, Object_Impl::metaname);
  }

  //
  // accept
  //
  void Object_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Object (this);
    else
      v->visit_Model (this);
  }
}

