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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ArtifactContainer_Impl;
  typedef ArtifactContainer_Impl * ArtifactContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < ArtifactContainer_Impl > ArtifactContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class ArtifactContainer_Impl
   *
   * Implementation for the ArtifactContainer model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static ArtifactContainer _create (const ImplementationArtifacts_in parent);
    ///@}

    // Default constructor.
    ArtifactContainer_Impl (void);

    // Initializing constructor.
    ArtifactContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ArtifactContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationArtifacts parent_ImplementationArtifacts (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Requirements (std::vector <Requirement> & items) const;
    ::GAME::Mga::Collection_T <Requirement> get_Requirements (void) const;

    size_t get_ECRequirementss (std::vector <ECRequirements> & items) const;
    ::GAME::Mga::Collection_T <ECRequirements> get_ECRequirementss (void) const;

    size_t get_RTRequirementss (std::vector <RTRequirements> & items) const;
    ::GAME::Mga::Collection_T <RTRequirements> get_RTRequirementss (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_ImplementationArtifacts (std::vector <ImplementationArtifact> & items) const;
    ::GAME::Mga::Collection_T <ImplementationArtifact> get_ImplementationArtifacts (void) const;

    size_t get_ArtifactDeployRequirements (std::vector <ArtifactDeployRequirement> & items) const;
    ::GAME::Mga::Collection_T <ArtifactDeployRequirement> get_ArtifactDeployRequirements (void) const;

    size_t get_ArtifactDependsOns (std::vector <ArtifactDependsOn> & items) const;
    ::GAME::Mga::Collection_T <ArtifactDependsOn> get_ArtifactDependsOns (void) const;

    size_t get_ImplementationArtifactReferences (std::vector <ImplementationArtifactReference> & items) const;
    ::GAME::Mga::Collection_T <ImplementationArtifactReference> get_ImplementationArtifactReferences (void) const;

    size_t get_ComponentServantArtifacts (std::vector <ComponentServantArtifact> & items) const;
    ::GAME::Mga::Collection_T <ComponentServantArtifact> get_ComponentServantArtifacts (void) const;

    size_t get_ComponentImplementationArtifacts (std::vector <ComponentImplementationArtifact> & items) const;
    ::GAME::Mga::Collection_T <ComponentImplementationArtifact> get_ComponentImplementationArtifacts (void) const;

    size_t get_ArtifactExecParameters (std::vector <ArtifactExecParameter> & items) const;
    ::GAME::Mga::Collection_T <ArtifactExecParameter> get_ArtifactExecParameters (void) const;

    size_t get_ArtifactInfoPropertys (std::vector <ArtifactInfoProperty> & items) const;
    ::GAME::Mga::Collection_T <ArtifactInfoProperty> get_ArtifactInfoPropertys (void) const;

    size_t get_ArtifactDependencys (std::vector <ArtifactDependency> & items) const;
    ::GAME::Mga::Collection_T <ArtifactDependency> get_ArtifactDependencys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ArtifactContainer.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONARTIFACT_ARTIFACTCONTAINER
