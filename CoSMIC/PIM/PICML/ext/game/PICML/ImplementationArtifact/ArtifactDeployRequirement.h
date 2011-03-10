// -*- C++ -*-

//============================================================================
/**
 * @file    ArtifactDeployRequirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTDEPLOYREQUIREMENT_H_
#define _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTDEPLOYREQUIREMENT_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactDeployRequirement_Impl;
  typedef ArtifactDeployRequirement_Impl * ArtifactDeployRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactDeployRequirement_Impl> ArtifactDeployRequirement;

  // Forward decl.
  class Visitor;

  class PICML_Export ArtifactDeployRequirement_Impl :
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
    ArtifactDeployRequirement_Impl (void);

    /// Initializing constructor
    ArtifactDeployRequirement_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ArtifactDeployRequirement_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactDeployRequirement _create (const ArtifactContainer_in parent);
    ///@}

    /// Get the src ImplementationArtifact connection point.
    ImplementationArtifact src_ImplementationArtifact (void);

    /// Get the dst Requirement connection point.
    Requirement dst_Requirement (void);

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
