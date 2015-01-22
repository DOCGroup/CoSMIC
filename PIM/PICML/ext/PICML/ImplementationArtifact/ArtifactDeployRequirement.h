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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactDeployRequirement_Impl;
  typedef ArtifactDeployRequirement_Impl * ArtifactDeployRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr < ArtifactDeployRequirement_Impl > ArtifactDeployRequirement;

  // Forward decl.
  class Visitor;

  /**
   * @class ArtifactDeployRequirement_Impl
   *
   * Implementation for the ArtifactDeployRequirement model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactDeployRequirement _create (const ArtifactContainer_in parent, ImplementationArtifact_in src, Requirement_in dst);
    ///@}

    // Default constructor.
    ArtifactDeployRequirement_Impl (void);

    // Initializing constructor.
    ArtifactDeployRequirement_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ArtifactDeployRequirement_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ArtifactContainer parent_ArtifactContainer (void);
    ///@}
    ImplementationArtifact src_ImplementationArtifact (void) const;
    Requirement dst_Requirement (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ArtifactDeployRequirement.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTDEPLOYREQUIREMENT
