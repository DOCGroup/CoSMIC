// -*- C++ -*-

//============================================================================
/**
 * @file    FileRef.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_FILEREF_H_
#define _PICML_INTERFACEDEFINITION_FILEREF_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FileRef_Impl;
  typedef FileRef_Impl * FileRef_in;
  typedef ::GAME::Mga::Smart_Ptr < FileRef_Impl > FileRef;

  // Forward decl.
  class Visitor;

  /**
   * @class FileRef_Impl
   *
   * Implementation for the FileRef model element.
   */
  class PICML_Export FileRef_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static FileRef _create (const File_in parent);
    static FileRef _create (const ServantProject_in parent);
    static FileRef _create (const StubProject_in parent);
    ///@}

    // Default constructor.
    FileRef_Impl (void);

    // Initializing constructor.
    FileRef_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~FileRef_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    File parent_File (void);
    ServantProject parent_ServantProject (void);
    StubProject parent_StubProject (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool File_is_nil (void) const;
    File refers_to_File (void) const;
    void refers_to_File (File_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "FileRef.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_FILEREF
