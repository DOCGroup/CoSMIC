// -*- C++ -*-

//============================================================================
/**
 * @file    Borrow.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _LIBRARY_BORROW_H_
#define _LIBRARY_BORROW_H_

#include "game/mga/Connection.h"

#include "Library_fwd.h"
#include "Library_export.h"

namespace Library
{
  // Forward decl. and type definitions
  class Borrow_Impl;
  typedef Borrow_Impl * Borrow_in;
  typedef ::GAME::Mga::Smart_Ptr <Borrow_Impl> Borrow;

  // Forward declare the project's visitor.
  class Visitor;

  class LIBRARY_Export Borrow_Impl : public ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t tag_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Borrow_Impl (void);

    /// Initializing constructor
    Borrow_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Borrow_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Borrow _create (const Library_in parent);
    ///@}

    /// Get the src Book connection point.
    Book src_Book (void);

    /// Get the dst Patron connection point.
    Patron dst_Patron (void);

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
