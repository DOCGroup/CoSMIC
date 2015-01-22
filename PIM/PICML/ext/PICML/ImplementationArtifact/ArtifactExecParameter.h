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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactExecParameter_Impl;
  typedef ArtifactExecParameter_Impl * ArtifactExecParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < ArtifactExecParameter_Impl > ArtifactExecParameter;

  // Forward decl.
  class Visitor;

  /**
   * @class ArtifactExecParameter_Impl
   *
   * Implementation for the ArtifactExecParameter model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactExecParameter _create (const ArtifactContainer_in parent, ImplementationArtifact_in src, Property_in dst);
    ///@}

    // Default constructor.
    ArtifactExecParameter_Impl (void);

    // Initializing constructor.
    ArtifactExecParameter_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ArtifactExecParameter_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ArtifactContainer parent_ArtifactContainer (void);
    ///@}
    ImplementationArtifact src_ImplementationArtifact (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ArtifactExecParameter.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTEXECPARAMETER
