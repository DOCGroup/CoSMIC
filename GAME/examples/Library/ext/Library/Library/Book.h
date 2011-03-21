// -*- C++ -*-

//============================================================================
/**
 * @file    Book.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _LIBRARY_LIBRARY_BOOK_H_
#define _LIBRARY_LIBRARY_BOOK_H_

#include "game/mga/Atom.h"

#include "Library/Library_fwd.h"
#include "Library/Library_export.h"

namespace Library
{
  // Forward decl. and type definitions
  class Book_Impl;
  typedef Book_Impl * Book_in;
  typedef ::GAME::Mga::Smart_Ptr <Book_Impl> Book;

  // Forward decl.
  class Visitor;

  class LIBRARY_Export Book_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Book_Impl (void);

    /// Initializing constructor
    Book_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~Book_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Book _create (const Library_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Author
    void Author (const std::string & val);

    /// Get the value of Author
    std::string Author (void) const;

    /// Set the value of Title
    void Title (const std::string & val);

    /// Get the value of Title
    std::string Title (void) const;

    /// Set the value of ISBN
    void ISBN (double val);

    /// Get the value of ISBN
    double ISBN (void) const;

    /// Set the value of Quantity
    void Quantity (long val);

    /// Get the value of Quantity
    long Quantity (void) const;

    /// Set the value of Genre
    void Genre (const std::string & val);

    /// Get the value of Genre
    std::string Genre (void) const;
    ///@}
    size_t in_Borrow_connections (std::vector <Borrow> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    Library parent_Library (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
