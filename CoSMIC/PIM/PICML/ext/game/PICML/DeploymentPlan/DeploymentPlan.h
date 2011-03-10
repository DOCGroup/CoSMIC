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

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DeploymentPlan_Impl;
  typedef DeploymentPlan_Impl * DeploymentPlan_in;
  typedef ::GAME::Mga::Smart_Ptr <DeploymentPlan_Impl> DeploymentPlan;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    DeploymentPlan_Impl (void);

    /// Initializing constructor
    DeploymentPlan_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~DeploymentPlan_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static DeploymentPlan _create (const DeploymentPlans_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_CollocationGroups (std::vector <CollocationGroup> & items) const;
    size_t get_InstanceMappings (std::vector <InstanceMapping> & items) const;
    size_t get_Deployss (std::vector <Deploys> & items) const;
    size_t get_NodeReferences (std::vector <NodeReference> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;
    size_t get_PropertyMappings (std::vector <PropertyMapping> & items) const;
    size_t get_CollocationGroupPropertys (std::vector <CollocationGroupProperty> & items) const;
    size_t get_CollocationGroupMembers (std::vector <CollocationGroupMember> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    DeploymentPlans parent_DeploymentPlans (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
