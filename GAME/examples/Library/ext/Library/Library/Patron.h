// -*- C++ -*-

//============================================================================
/**
 * @file    Patron.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _LIBRARY_LIBRARY_PATRON_H_
#define _LIBRARY_LIBRARY_PATRON_H_

#include "game/mga/Atom.h"

#include "Library/Library_fwd.h"
#include "Library/Library_export.h"

namespace Library
{
  // Forward decl. and type definitions
  class Patron_Impl;
  typedef Patron_Impl * Patron_in;
  typedef ::GAME::Mga::Smart_Ptr <Patron_Impl> Patron;

  // Forward decl.
  class Visitor;

  class LIBRARY_Export Patron_Impl :
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
    Patron_Impl (void);

    /// Initializing constructor
    Patron_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~Patron_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Patron _create (const Library_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of HomeAddress
    void HomeAddress (const std::string & val);

    /// Get the value of HomeAddress
    std::string HomeAddress (void) const;

    /// Set the value of Gender
    void Gender (const std::string & val);

    /// Get the value of Gender
    std::string Gender (void) const;

    /// Set the value of Age
    void Age (long val);

    /// Get the value of Age
    long Age (void) const;

    /// Set the value of SSN
    void SSN (double val);

    /// Get the value of SSN
    double SSN (void) const;

    /// Set the value of Name
    void Name (const std::string & val);

    /// Get the value of Name
    std::string Name (void) const;
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
