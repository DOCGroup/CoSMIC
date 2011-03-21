// $Id$

#include "stdafx.h"
#include "Book.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "Library/Visitor.h"
#include "Library/Library/Borrow.h"
#include "Library/Library/Library.h"

namespace Library
{
  //
  // metaname
  //
  const std::string Book_Impl::metaname = "Book";

  //
  // Book_Impl
  //
  Book_Impl::Book_Impl (void)
  {
  }

  //
  // Book_Impl
  //
  Book_Impl::Book_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Book_Impl
  //
  Book_Impl::~Book_Impl (void)
  {
  }

  //
  // accept
  //
  void Book_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Book (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }

  //
  // _create
  //
  Book Book_Impl::_create (const Library_in parent)
  {
    return ::GAME::Mga::create_object <Book> (parent, Book_Impl::metaname);
  }

  //
  // Author
  //
  void Book_Impl::Author (const std::string & val)
  {
    static const std::string attr_Author ("Author");
    this->attribute (attr_Author)->string_value (val);
  }

  //
  // Author
  //
  std::string Book_Impl::Author (void) const
  {
    static const std::string attr_Author ("Author");
    return this->attribute (attr_Author)->string_value ();
  }

  //
  // Title
  //
  void Book_Impl::Title (const std::string & val)
  {
    static const std::string attr_Title ("Title");
    this->attribute (attr_Title)->string_value (val);
  }

  //
  // Title
  //
  std::string Book_Impl::Title (void) const
  {
    static const std::string attr_Title ("Title");
    return this->attribute (attr_Title)->string_value ();
  }

  //
  // ISBN
  //
  void Book_Impl::ISBN (double val)
  {
    static const std::string attr_ISBN ("ISBN");
    this->attribute (attr_ISBN)->double_value (val);
  }

  //
  // ISBN
  //
  double Book_Impl::ISBN (void) const
  {
    static const std::string attr_ISBN ("ISBN");
    return this->attribute (attr_ISBN)->double_value ();
  }

  //
  // Quantity
  //
  void Book_Impl::Quantity (long val)
  {
    static const std::string attr_Quantity ("Quantity");
    this->attribute (attr_Quantity)->int_value (val);
  }

  //
  // Quantity
  //
  long Book_Impl::Quantity (void) const
  {
    static const std::string attr_Quantity ("Quantity");
    return this->attribute (attr_Quantity)->int_value ();
  }

  //
  // Genre
  //
  void Book_Impl::Genre (const std::string & val)
  {
    static const std::string attr_Genre ("Genre");
    this->attribute (attr_Genre)->string_value (val);
  }

  //
  // Genre
  //
  std::string Book_Impl::Genre (void) const
  {
    static const std::string attr_Genre ("Genre");
    return this->attribute (attr_Genre)->string_value ();
  }

  //
  // in_Borrow_connections
  //
  size_t Book_Impl::in_Borrow_connections (std::vector <Borrow> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_Library
  //
  Library Book_Impl::parent_Library (void) const
  {
    return ::GAME::Mga::get_parent <Library> (this->object_.p);
  }
}

