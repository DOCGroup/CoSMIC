// $Id$

#include "stdafx.h"
#include "Library.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "Library/Visitor.h"
#include "Library/Library/Patron.h"
#include "Library/Library/Borrow.h"
#include "Library/Library/Book.h"

namespace Library
{
  //
  // metaname
  //
  const std::string Library_Impl::metaname = "Library";

  //
  // Library_Impl
  //
  Library_Impl::Library_Impl (void)
  {
  }

  //
  // Library_Impl
  //
  Library_Impl::Library_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Library_Impl
  //
  Library_Impl::~Library_Impl (void)
  {
  }

  //
  // accept
  //
  void Library_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Library (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // _create
  //
  Library Library_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <Library> (parent, Library_Impl::metaname);
  }

  //
  // LibraryAddress
  //
  void Library_Impl::LibraryAddress (const std::string & val)
  {
    static const std::string attr_LibraryAddress ("LibraryAddress");
    this->attribute (attr_LibraryAddress)->string_value (val);
  }

  //
  // LibraryAddress
  //
  std::string Library_Impl::LibraryAddress (void) const
  {
    static const std::string attr_LibraryAddress ("LibraryAddress");
    return this->attribute (attr_LibraryAddress)->string_value ();
  }

  //
  // LibraryName
  //
  void Library_Impl::LibraryName (const std::string & val)
  {
    static const std::string attr_LibraryName ("LibraryName");
    this->attribute (attr_LibraryName)->string_value (val);
  }

  //
  // LibraryName
  //
  std::string Library_Impl::LibraryName (void) const
  {
    static const std::string attr_LibraryName ("LibraryName");
    return this->attribute (attr_LibraryName)->string_value ();
  }

  //
  // get_Patrons
  //
  size_t Library_Impl::get_Patrons (std::vector <Patron> & items) const
  {
    return this->children (items);
  }

  //
  // get_Borrows
  //
  size_t Library_Impl::get_Borrows (std::vector <Borrow> & items) const
  {
    return this->children (items);
  }

  //
  // get_Books
  //
  size_t Library_Impl::get_Books (std::vector <Book> & items) const
  {
    return this->children (items);
  }

  ::GAME::Mga::RootFolder Library_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

