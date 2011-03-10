// -*- C++ -*-

//============================================================================
/**
 * @file    FileRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_FILEREF_H_
#define _PICML_INTERFACEDEFINITION_FILEREF_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FileRef_Impl;
  typedef FileRef_Impl * FileRef_in;
  typedef ::GAME::Mga::Smart_Ptr <FileRef_Impl> FileRef;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    FileRef_Impl (void);

    /// Initializing constructor
    FileRef_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~FileRef_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static FileRef _create (const File_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    File parent_File (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    File refers_to_File (void) const;
    ///@}
  };
}

#endif
