// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationArtifacts.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACTS_H_
#define _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACTS_H_

#include "game/mga/Folder.h"
#include "game/mga/RootFolder.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationArtifacts_Impl;
  typedef ImplementationArtifacts_Impl * ImplementationArtifacts_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationArtifacts_Impl> ImplementationArtifacts;

  // Forward decl.
  class Visitor;

  class PICML_Export ImplementationArtifacts_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ImplementationArtifacts_Impl (void);

    /// Initializing constructor
    ImplementationArtifacts_Impl (IMgaFolder * ptr);

    /// Destructor
    virtual ~ImplementationArtifacts_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ImplementationArtifacts _create (const ::GAME::Mga::RootFolder_in parent);
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
