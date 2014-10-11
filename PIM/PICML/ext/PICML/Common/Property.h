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
    size_t src_EdgeProperty (std::vector <EdgeProperty> & items) const;

    /// Get the src CollocationGroupProperty connection.
    size_t src_CollocationGroupProperty (std::vector <CollocationGroupProperty> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ConfigProperty connection.
    size_t dst_ConfigProperty (std::vector <ConfigProperty> & items) const;

    /// Get the dst MonolithExecParameter connection.
    size_t dst_MonolithExecParameter (std::vector <MonolithExecParameter> & items) const;

    /// Get the dst ArtifactInfoProperty connection.
    size_t dst_ArtifactInfoProperty (std::vector <ArtifactInfoProperty> & items) const;

    /// Get the dst ArtifactExecParameter connection.
    size_t dst_ArtifactExecParameter (std::vector <ArtifactExecParameter> & items) const;

    /// Get the dst AssemblyConfigProperty connection.
    size_t dst_AssemblyConfigProperty (std::vector <AssemblyConfigProperty> & items) const;

    /// Get the dst PackageConfigProperty connection.
    size_t dst_PackageConfigProperty (std::vector <PackageConfigProperty> & items) const;

    /// Get the dst PackageInfoProperty connection.
    size_t dst_PackageInfoProperty (std::vector <PackageInfoProperty> & items) const;

    /// Get the dst ComponentInfoProperty connection.
    size_t dst_ComponentInfoProperty (std::vector <ComponentInfoProperty> & items) const;

    /// Get the dst ComponentConfigProperty connection.
    size_t dst_ComponentConfigProperty (std::vector <ComponentConfigProperty> & items) const;

    /// Get the dst PackageConfConfigProperty connection.
    size_t dst_PackageConfConfigProperty (std::vector <PackageConfConfigProperty> & items) const;

    /// Get the dst InfoProperty connection.
    size_t dst_InfoProperty (std::vector <InfoProperty> & items) const;

    /// Get the dst AttributeValue connection.
    size_t dst_AttributeValue (std::vector <AttributeValue> & items) const;

    /// Get the dst AttributeMappingValue connection.
    size_t dst_AttributeMappingValue (std::vector <AttributeMappingValue> & items) const;

    /// Get the dst PathProperty connection.
    size_t dst_PathProperty (std::vector <PathProperty> & items) const;

    /// Get the dst PropertyMapping connection.
    size_t dst_PropertyMapping (std::vector <PropertyMapping> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Property.inl"
#endif

#endif  // !defined _PICML_COMMON_PROPERTY
