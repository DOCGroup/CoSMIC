// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfigurationContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONCONTAINER_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONCONTAINER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfigurationContainer_Impl;
  typedef PackageConfigurationContainer_Impl * PackageConfigurationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfigurationContainer_Impl > PackageConfigurationContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfigurationContainer_Impl
   *
   * Implementation for the PackageConfigurationContainer model element.
   */
  class PICML_Export PackageConfigurationContainer_Impl :
    public virtual ::GAME::Mga::Model_Impl
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
    static PackageConfigurationContainer _create (const PackageConfigurations_in parent);
    ///@}

    // Default constructor.
    PackageConfigurationContainer_Impl (void);

    // Initializing constructor.
    PackageConfigurationContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~PackageConfigurationContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurations parent_PackageConfigurations (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ComponentPackage (void) const;
    ComponentPackage get_ComponentPackage (void) const;

    bool has_PackageConfBasePackage (void) const;
    PackageConfBasePackage get_PackageConfBasePackage (void) const;

    bool has_PackageConfReference (void) const;
    PackageConfReference get_PackageConfReference (void) const;

    bool has_ComponentPackageReference (void) const;
    ComponentPackageReference get_ComponentPackageReference (void) const;

    bool has_PackageConfSpecializedConfig (void) const;
    PackageConfSpecializedConfig get_PackageConfSpecializedConfig (void) const;
    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_PackageConfigurations (std::vector <PackageConfiguration> & items) const;
    ::GAME::Mga::Collection_T <PackageConfiguration> get_PackageConfigurations (void) const;

    size_t get_PackageConfSelectRequirements (std::vector <PackageConfSelectRequirement> & items) const;
    ::GAME::Mga::Collection_T <PackageConfSelectRequirement> get_PackageConfSelectRequirements (void) const;

    size_t get_Requirements (std::vector <Requirement> & items) const;
    ::GAME::Mga::Collection_T <Requirement> get_Requirements (void) const;

    size_t get_RTRequirementss (std::vector <RTRequirements> & items) const;
    ::GAME::Mga::Collection_T <RTRequirements> get_RTRequirementss (void) const;

    size_t get_ECRequirementss (std::vector <ECRequirements> & items) const;
    ::GAME::Mga::Collection_T <ECRequirements> get_ECRequirementss (void) const;

    size_t get_PackageConfConfigPropertys (std::vector <PackageConfConfigProperty> & items) const;
    ::GAME::Mga::Collection_T <PackageConfConfigProperty> get_PackageConfConfigPropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfigurationContainer.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONCONTAINER
