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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationArtifact_Impl;
  typedef ImplementationArtifact_Impl * ImplementationArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr < ImplementationArtifact_Impl > ImplementationArtifact;

  // Forward decl.
  class Visitor;

  /**
   * @class ImplementationArtifact_Impl
   *
   * Implementation for the ImplementationArtifact model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ImplementationArtifact _create (const Project_in parent);
    static ImplementationArtifact _create (const ArtifactContainer_in parent);
    ///@}

    // Default constructor.
    ImplementationArtifact_Impl (void);

    // Initializing constructor.
    ImplementationArtifact_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ImplementationArtifact_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Project parent_Project (void);
    ArtifactContainer parent_ArtifactContainer (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of UUID
    void UUID (const std::string & val);

    /// Get the value of UUID
    std::string UUID (void) const;

    /// Set the value of label
    void label (const std::string & val);

    /// Get the value of label
    std::string label (void) const;

    /// Set the value of location
    void location (const std::string & val);

    /// Get the value of location
    std::string location (void) const;

    /// Set the value of artifactVersion
    void artifactVersion (const std::string & val);

    /// Get the value of artifactVersion
    std::string artifactVersion (void) const;

    /// Set the value of operatingSystem
    void operatingSystem (const std::string & val);

    /// Get the value of operatingSystem
    std::string operatingSystem (void) const;

    /// Set the value of configuration
    void configuration (const std::string & val);

    /// Get the value of configuration
    std::string configuration (void) const;

    /// Set the value of architecture
    void architecture (const std::string & val);

    /// Get the value of architecture
    std::string architecture (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ArtifactDependsOn connection.
    size_t src_of_ArtifactDependsOn (std::vector <ArtifactDependsOn> & items) const;
    GAME::Mga::Collection_T <ArtifactDependsOn> src_of_ArtifactDependsOn (void) const;

    /// Get the src ArtifactDependency connection.
    size_t src_of_ArtifactDependency (std::vector <ArtifactDependency> & items) const;
    GAME::Mga::Collection_T <ArtifactDependency> src_of_ArtifactDependency (void) const;

    /// Get the src ArtifactInfoProperty connection.
    size_t src_of_ArtifactInfoProperty (std::vector <ArtifactInfoProperty> & items) const;
    GAME::Mga::Collection_T <ArtifactInfoProperty> src_of_ArtifactInfoProperty (void) const;

    /// Get the src ArtifactExecParameter connection.
    size_t src_of_ArtifactExecParameter (std::vector <ArtifactExecParameter> & items) const;
    GAME::Mga::Collection_T <ArtifactExecParameter> src_of_ArtifactExecParameter (void) const;

    /// Get the src ArtifactDeployRequirement connection.
    size_t src_of_ArtifactDeployRequirement (std::vector <ArtifactDeployRequirement> & items) const;
    GAME::Mga::Collection_T <ArtifactDeployRequirement> src_of_ArtifactDeployRequirement (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ArtifactDependency connection.
    size_t dst_of_ArtifactDependency (std::vector <ArtifactDependency> & items) const;
    GAME::Mga::Collection_T <ArtifactDependency> dst_of_ArtifactDependency (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ImplementationArtifact.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACT
