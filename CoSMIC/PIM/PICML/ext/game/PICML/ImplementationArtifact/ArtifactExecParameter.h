// -*- C++ -*-

//============================================================================
/**
 * @file    ArtifactExecParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTEXECPARAMETER_H_
#define _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTEXECPARAMETER_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactExecParameter_Impl;
  typedef ArtifactExecParameter_Impl * ArtifactExecParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactExecParameter_Impl> ArtifactExecParameter;

  // Forward decl.
  class Visitor;

  class PICML_Export ArtifactExecParameter_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ArtifactExecParameter_Impl (void);

    /// Initializing constructor
    ArtifactExecParameter_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ArtifactExecParameter_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactExecParameter _create (const ArtifactContainer_in parent);
    ///@}

    /// Get the src ImplementationArtifact connection point.
    ImplementationArtifact src_ImplementationArtifact (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ArtifactContainer parent_ArtifactContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
