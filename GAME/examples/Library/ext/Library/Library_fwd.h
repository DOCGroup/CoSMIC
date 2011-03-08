// -*- C++ -*-
// $Id$

#ifndef _LIBRARY_FWD_H_
#define _LIBRARY_FWD_H_

namespace Library
{

  // Forward declarations for Patron
  class Patron_Impl;
  typedef Patron_Impl * Patron_in;
  typedef ::GAME::Mga::Smart_Ptr <Patron_Impl> Patron;

  // Forward declarations for Borrow
  class Borrow_Impl;
  typedef Borrow_Impl * Borrow_in;
  typedef ::GAME::Mga::Smart_Ptr <Borrow_Impl> Borrow;

  // Forward declarations for Library
  class Library_Impl;
  typedef Library_Impl * Library_in;
  typedef ::GAME::Mga::Smart_Ptr <Library_Impl> Library;

  // Forward declarations for Book
  class Book_Impl;
  typedef Book_Impl * Book_in;
  typedef ::GAME::Mga::Smart_Ptr <Book_Impl> Book;
}

#endif
