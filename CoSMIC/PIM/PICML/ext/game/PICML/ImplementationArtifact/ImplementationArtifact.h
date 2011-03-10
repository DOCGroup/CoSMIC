// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationArtifact.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACT_H_
#define _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACT_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationArtifact_Impl;
  typedef ImplementationArtifact_Impl * ImplementationArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationArtifact_Impl> ImplementationArtifact;

  // Forward decl.
  class Visitor;

  class PICML_Export ImplementationArtifact_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ImplementationArtifact_Impl (void);

    /// Initializing constructor
    ImplementationArtifact_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ImplementationArtifact_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ImplementationArtifact _create (const ArtifactContainer_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of architecture
    void architecture (const std::string & val);

    /// Get the value of architecture
    std::string architecture (void) const;

    /// Set the value of artifactVersion
    void artifactVersion (const std::string & val);

    /// Get the value of artifactVersion
    std::string artifactVersion (void) const;

    /// Set the value of configuration
    void configuration (const std::string & val);

    /// Get the value of configuration
    std::string configuration (void) const;

    /// Set the value of operatingSystem
    void operatingSystem (const std::string & val);

    /// Get the value of operatingSystem
    std::string operatingSystem (void) const;
    ///@}
    size_t in_ArtifactDependency_connections (std::vector <ArtifactDependency> & conns) const;
    size_t in_ArtifactInfoProperty_connections (std::vector <ArtifactInfoProperty> & conns) const;
    size_t in_ArtifactExecParameter_connections (std::vector <ArtifactExecParameter> & conns) const;
    size_t in_ArtifactDeployRequirement_connections (std::vector <ArtifactDeployRequirement> & conns) const;
    size_t in_ArtifactDependsOn_connections (std::vector <ArtifactDependsOn> & conns) const;

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
