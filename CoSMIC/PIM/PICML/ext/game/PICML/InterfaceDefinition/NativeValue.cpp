// $Id$

#include "StdAfx.h"
#include "NativeValue.h"

#if !defined (__GAME_INLINE__)
#include "NativeValue.inl"
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
  const std::string NativeValue_Impl::metaname ("NativeValue");

  //
  // _create (const Package_in)
  //
  NativeValue NativeValue_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < NativeValue > (parent, NativeValue_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  NativeValue NativeValue_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < NativeValue > (parent, NativeValue_Impl::metaname);
  }

  //
  // accept
  //
  void NativeValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_NativeValue (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

