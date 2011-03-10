// -*- C++ -*-

//============================================================================
/**
 * @file    ArtifactInfoProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTINFOPROPERTY_H_
#define _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTINFOPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactInfoProperty_Impl;
  typedef ArtifactInfoProperty_Impl * ArtifactInfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactInfoProperty_Impl> ArtifactInfoProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export ArtifactInfoProperty_Impl :
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
    ArtifactInfoProperty_Impl (void);

    /// Initializing constructor
    ArtifactInfoProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ArtifactInfoProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactInfoProperty _create (const ArtifactContainer_in parent);
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
