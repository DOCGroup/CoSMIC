// -*- C++ -*-

//============================================================================
/**
 * @file    DeploymentPlan.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_DEPLOYMENTPLAN_H_
#define _PICML_DEPLOYMENTPLAN_DEPLOYMENTPLAN_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DeploymentPlan_Impl;
  typedef DeploymentPlan_Impl * DeploymentPlan_in;
  typedef ::GAME::Mga::Smart_Ptr < DeploymentPlan_Impl > DeploymentPlan;

  // Forward decl.
  class Visitor;

  /**
   * @class DeploymentPlan_Impl
   *
   * Implementation for the DeploymentPlan model element.
   */
  class PICML_Export DeploymentPlan_Impl :
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
    static DeploymentPlan _create (const DeploymentPlans_in parent);
    ///@}

    // Default constructor.
    DeploymentPlan_Impl (void);

    // Initializing constructor.
    DeploymentPlan_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DeploymentPlan_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DeploymentPlans parent_DeploymentPlans (void);
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
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComponentAssemblyReferences (std::vector <ComponentAssemblyReference> & items) const;
    ::GAME::Mga::Collection_T <ComponentAssemblyReference> get_ComponentAssemblyReferences (void) const;

    size_t get_ComponentInstanceRefs (std::vector <ComponentInstanceRef> & items) const;
    ::GAME::Mga::Collection_T <ComponentInstanceRef> get_ComponentInstanceRefs (void) const;

    size_t get_ComponentFactoryRefs (std::vector <ComponentFactoryRef> & items) const;
    ::GAME::Mga::Collection_T <ComponentFactoryRef> get_ComponentFactoryRefs (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_CollocationGroupPropertys (std::vector <CollocationGroupProperty> & items) const;
    ::GAME::Mga::Collection_T <CollocationGroupProperty> get_CollocationGroupPropertys (void) const;

    size_t get_CollocationGroups (std::vector <CollocationGroup> & items) const;
    ::GAME::Mga::Collection_T <CollocationGroup> get_CollocationGroups (void) const;

    size_t get_InstanceMappings (std::vector <InstanceMapping> & items) const;
    ::GAME::Mga::Collection_T <InstanceMapping> get_InstanceMappings (void) const;

    size_t get_NodeReferences (std::vector <NodeReference> & items) const;
    ::GAME::Mga::Collection_T <NodeReference> get_NodeReferences (void) const;

    size_t get_PropertyMappings (std::vector <PropertyMapping> & items) const;
    ::GAME::Mga::Collection_T <PropertyMapping> get_PropertyMappings (void) const;

    size_t get_Deployss (std::vector <Deploys> & items) const;
    ::GAME::Mga::Collection_T <Deploys> get_Deployss (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DeploymentPlan.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_DEPLOYMENTPLAN
