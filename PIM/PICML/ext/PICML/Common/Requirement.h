// -*- C++ -*-

//============================================================================
/**
 * @file    Requirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_REQUIREMENT_H_
#define _PICML_COMMON_REQUIREMENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/RequirementBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Requirement_Impl;
  typedef Requirement_Impl * Requirement_in;
  typedef ::GAME::Mga::Smart_Ptr < Requirement_Impl > Requirement;

  // Forward decl.
  class Visitor;

  /**
   * @class Requirement_Impl
   *
   * Implementation for the Requirement model element.
   */
  class PICML_Export Requirement_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual RequirementBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Requirement _create (const ComponentAssembly_in parent);
    static Requirement _create (const ArtifactContainer_in parent);
    static Requirement _create (const PackageConfigurationContainer_in parent);
    ///@}

    // Default constructor.
    Requirement_Impl (void);

    // Initializing constructor.
    Requirement_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Requirement_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ArtifactContainer parent_ArtifactContainer (void);
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ArtifactDeployRequirement connection.
    size_t dst_of_ArtifactDeployRequirement (std::vector <ArtifactDeployRequirement> & items) const;
    GAME::Mga::Collection_T <ArtifactDeployRequirement> dst_of_ArtifactDeployRequirement (void) const;

    /// Get the dst AssemblyselectRequirement connection.
    size_t dst_of_AssemblyselectRequirement (std::vector <AssemblyselectRequirement> & items) const;
    GAME::Mga::Collection_T <AssemblyselectRequirement> dst_of_AssemblyselectRequirement (void) const;

    /// Get the dst PackageConfSelectRequirement connection.
    size_t dst_of_PackageConfSelectRequirement (std::vector <PackageConfSelectRequirement> & items) const;
    GAME::Mga::Collection_T <PackageConfSelectRequirement> dst_of_PackageConfSelectRequirement (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Requirement.inl"
#endif

#endif  // !defined _PICML_COMMON_REQUIREMENT
