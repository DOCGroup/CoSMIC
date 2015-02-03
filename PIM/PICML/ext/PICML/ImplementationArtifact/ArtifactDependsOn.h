// -*- C++ -*-

//============================================================================
/**
 * @file    ArtifactDependsOn.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTDEPENDSON_H_
#define _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTDEPENDSON_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactDependsOn_Impl;
  typedef ArtifactDependsOn_Impl * ArtifactDependsOn_in;
  typedef ::GAME::Mga::Smart_Ptr < ArtifactDependsOn_Impl > ArtifactDependsOn;

  // Forward decl.
  class Visitor;

  /**
   * @class ArtifactDependsOn_Impl
   *
   * Implementation for the ArtifactDependsOn model element.
   */
  class PICML_Export ArtifactDependsOn_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactDependsOn _create (const ArtifactContainer_in parent, ImplementationArtifact_in src, ImplementationArtifactReference_in dst);
    ///@}

    // Default constructor.
    ArtifactDependsOn_Impl (void);

    // Initializing constructor.
    ArtifactDependsOn_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ArtifactDependsOn_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ArtifactContainer parent_ArtifactContainer (void);
    ///@}
    ImplementationArtifact src_ImplementationArtifact (void) const;
    ImplementationArtifactReference dst_ImplementationArtifactReference (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ArtifactDependsOn.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTDEPENDSON
