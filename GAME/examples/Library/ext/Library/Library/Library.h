// -*- C++ -*-

//============================================================================
/**
 * @file    Library.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _LIBRARY_LIBRARY_LIBRARY_H_
#define _LIBRARY_LIBRARY_LIBRARY_H_

#include "game/mga/Model.h"
#include "game/mga/RootFolder.h"

#include "Library/Library_fwd.h"
#include "Library/Library_export.h"

namespace Library
{
  // Forward decl. and type definitions
  class Library_Impl;
  typedef Library_Impl * Library_in;
  typedef ::GAME::Mga::Smart_Ptr <Library_Impl> Library;

  // Forward decl.
  class Visitor;

  class LIBRARY_Export Library_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Library_Impl (void);

    /// Initializing constructor
    Library_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Library_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Library _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of LibraryAddress
    void LibraryAddress (const std::string & val);

    /// Get the value of LibraryAddress
    std::string LibraryAddress (void) const;

    /// Set the value of LibraryName
    void LibraryName (const std::string & val);

    /// Get the value of LibraryName
    std::string LibraryName (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Patrons (std::vector <Patron> & items) const;
    size_t get_Borrows (std::vector <Borrow> & items) const;
    size_t get_Books (std::vector <Book> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ::GAME::Mga::RootFolder parent_RootFolder (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
