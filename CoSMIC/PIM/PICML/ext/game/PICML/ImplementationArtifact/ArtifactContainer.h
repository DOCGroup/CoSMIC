// -*- C++ -*-

//============================================================================
/**
 * @file    ArtifactContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTCONTAINER_H_
#define _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTCONTAINER_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactContainer_Impl;
  typedef ArtifactContainer_Impl * ArtifactContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ArtifactContainer_Impl> ArtifactContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export ArtifactContainer_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ArtifactContainer_Impl (void);

    /// Initializing constructor
    ArtifactContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ArtifactContainer_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactContainer _create (const ImplementationArtifacts_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ArtifactDependencys (std::vector <ArtifactDependency> & items) const;
    size_t get_ArtifactInfoPropertys (std::vector <ArtifactInfoProperty> & items) const;
    size_t get_ArtifactExecParameters (std::vector <ArtifactExecParameter> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;
    size_t get_ImplementationArtifacts (std::vector <ImplementationArtifact> & items) const;
    size_t get_Requirements (std::vector <Requirement> & items) const;
    size_t get_ArtifactDeployRequirements (std::vector <ArtifactDeployRequirement> & items) const;
    size_t get_ImplementationArtifactReferences (std::vector <ImplementationArtifactReference> & items) const;
    size_t get_ArtifactDependsOns (std::vector <ArtifactDependsOn> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationArtifacts parent_ImplementationArtifacts (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
