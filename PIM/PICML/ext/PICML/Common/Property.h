// -*- C++ -*-

//============================================================================
/**
 * @file    Property.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_PROPERTY_H_
#define _PICML_COMMON_PROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Property_Impl;
  typedef Property_Impl * Property_in;
  typedef ::GAME::Mga::Smart_Ptr < Property_Impl > Property;

  /**
   * @class Property_Impl
   *
   * Implementation for the Property model element.
   */
  class PICML_Export Property_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    Property_Impl (void);

    // Initializing constructor.
    Property_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~Property_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    RequirementBase parent_RequirementBase (void);
    BehaviorInputAction parent_BehaviorInputAction (void);
    ActionBase parent_ActionBase (void);
    QueryInputAction parent_QueryInputAction (void);
    Path parent_Path (void);
    ImplementationContainer parent_ImplementationContainer (void);
    ComponentContainer parent_ComponentContainer (void);
    Paths parent_Paths (void);
    DeploymentPlan parent_DeploymentPlan (void);
    ArtifactContainer parent_ArtifactContainer (void);
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    PackageContainer parent_PackageContainer (void);
    Domain parent_Domain (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src EdgeProperty connection.
    size_t src_of_EdgeProperty (std::vector <EdgeProperty> & items) const;
    GAME::Mga::Collection_T <EdgeProperty> src_of_EdgeProperty (void) const;

    /// Get the src CollocationGroupProperty connection.
    size_t src_of_CollocationGroupProperty (std::vector <CollocationGroupProperty> & items) const;
    GAME::Mga::Collection_T <CollocationGroupProperty> src_of_CollocationGroupProperty (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ConfigProperty connection.
    size_t dst_of_ConfigProperty (std::vector <ConfigProperty> & items) const;
    GAME::Mga::Collection_T <ConfigProperty> dst_of_ConfigProperty (void) const;

    /// Get the dst MonolithExecParameter connection.
    size_t dst_of_MonolithExecParameter (std::vector <MonolithExecParameter> & items) const;
    GAME::Mga::Collection_T <MonolithExecParameter> dst_of_MonolithExecParameter (void) const;

    /// Get the dst ArtifactInfoProperty connection.
    size_t dst_of_ArtifactInfoProperty (std::vector <ArtifactInfoProperty> & items) const;
    GAME::Mga::Collection_T <ArtifactInfoProperty> dst_of_ArtifactInfoProperty (void) const;

    /// Get the dst ArtifactExecParameter connection.
    size_t dst_of_ArtifactExecParameter (std::vector <ArtifactExecParameter> & items) const;
    GAME::Mga::Collection_T <ArtifactExecParameter> dst_of_ArtifactExecParameter (void) const;

    /// Get the dst AssemblyConfigProperty connection.
    size_t dst_of_AssemblyConfigProperty (std::vector <AssemblyConfigProperty> & items) const;
    GAME::Mga::Collection_T <AssemblyConfigProperty> dst_of_AssemblyConfigProperty (void) const;

    /// Get the dst PackageConfigProperty connection.
    size_t dst_of_PackageConfigProperty (std::vector <PackageConfigProperty> & items) const;
    GAME::Mga::Collection_T <PackageConfigProperty> dst_of_PackageConfigProperty (void) const;

    /// Get the dst PackageInfoProperty connection.
    size_t dst_of_PackageInfoProperty (std::vector <PackageInfoProperty> & items) const;
    GAME::Mga::Collection_T <PackageInfoProperty> dst_of_PackageInfoProperty (void) const;

    /// Get the dst ComponentInfoProperty connection.
    size_t dst_of_ComponentInfoProperty (std::vector <ComponentInfoProperty> & items) const;
    GAME::Mga::Collection_T <ComponentInfoProperty> dst_of_ComponentInfoProperty (void) const;

    /// Get the dst ComponentConfigProperty connection.
    size_t dst_of_ComponentConfigProperty (std::vector <ComponentConfigProperty> & items) const;
    GAME::Mga::Collection_T <ComponentConfigProperty> dst_of_ComponentConfigProperty (void) const;

    /// Get the dst PackageConfConfigProperty connection.
    size_t dst_of_PackageConfConfigProperty (std::vector <PackageConfConfigProperty> & items) const;
    GAME::Mga::Collection_T <PackageConfConfigProperty> dst_of_PackageConfConfigProperty (void) const;

    /// Get the dst InfoProperty connection.
    size_t dst_of_InfoProperty (std::vector <InfoProperty> & items) const;
    GAME::Mga::Collection_T <InfoProperty> dst_of_InfoProperty (void) const;

    /// Get the dst AttributeValue connection.
    size_t dst_of_AttributeValue (std::vector <AttributeValue> & items) const;
    GAME::Mga::Collection_T <AttributeValue> dst_of_AttributeValue (void) const;

    /// Get the dst AttributeMappingValue connection.
    size_t dst_of_AttributeMappingValue (std::vector <AttributeMappingValue> & items) const;
    bool has_dst_of_AttributeMappingValue (void) const;
    AttributeMappingValue dst_of_AttributeMappingValue (void) const;

    /// Get the dst PathProperty connection.
    size_t dst_of_PathProperty (std::vector <PathProperty> & items) const;
    GAME::Mga::Collection_T <PathProperty> dst_of_PathProperty (void) const;

    /// Get the dst PropertyMapping connection.
    size_t dst_of_PropertyMapping (std::vector <PropertyMapping> & items) const;
    GAME::Mga::Collection_T <PropertyMapping> dst_of_PropertyMapping (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Property.inl"
#endif

#endif  // !defined _PICML_COMMON_PROPERTY
