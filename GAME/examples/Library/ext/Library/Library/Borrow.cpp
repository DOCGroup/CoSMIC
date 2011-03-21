// $Id$

#include "stdafx.h"
#include "Borrow.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "Library/Visitor.h"
#include "Library/Library/Library.h"
#include "Library/Library/Book.h"
#include "Library/Library/Patron.h"

namespace Library
{
  //
  // metaname
  //
  const std::string Borrow_Impl::metaname = "Borrow";

  //
  // Borrow_Impl
  //
  Borrow_Impl::Borrow_Impl (void)
  {
  }

  //
  // Borrow_Impl
  //
  Borrow_Impl::Borrow_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Borrow_Impl
  //
  Borrow_Impl::~Borrow_Impl (void)
  {
  }

  //
  // accept
  //
  void Borrow_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Borrow (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // _create
  //
  Borrow Borrow_Impl::_create (const Library_in parent)
  {
    return ::GAME::Mga::create_object <Borrow> (parent, Borrow_Impl::metaname);
  }

  //
  // src_Book
  //
  Book Borrow_Impl::src_Book (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return Book::_narrow (target);
  }

  //
  // dst_Patron
  //
  Patron Borrow_Impl::dst_Patron (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Patron::_narrow (target);
  }

  //
  // parent_Library
  //
  Library Borrow_Impl::parent_Library (void) const
  {
    return ::GAME::Mga::get_parent <Library> (this->object_.p);
  }
}

