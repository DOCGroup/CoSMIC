// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentFactoryRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_COMPONENTFACTORYREF_H_
#define _PICML_DEPLOYMENTPLAN_COMPONENTFACTORYREF_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/DeploymentPlan/CollocationGroupMember.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentFactoryRef_Impl;
  typedef ComponentFactoryRef_Impl * ComponentFactoryRef_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentFactoryRef_Impl > ComponentFactoryRef;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentFactoryRef_Impl
   *
   * Implementation for the ComponentFactoryRef model element.
   */
  class PICML_Export ComponentFactoryRef_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual CollocationGroupMember_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentFactoryRef _create (const DeploymentPlan_in parent);
    ///@}

    // Default constructor.
    ComponentFactoryRef_Impl (void);

    // Initializing constructor.
    ComponentFactoryRef_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentFactoryRef_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src Deploys connection.
    size_t src_Deploys (std::vector <Deploys> & items) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ComponentFactoryInstance_is_nil (void) const;
    ComponentFactoryInstance get_ComponentFactoryInstance (void) const;
    void set_ComponentFactoryInstance (ComponentFactoryInstance_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentFactoryRef.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_COMPONENTFACTORYREF
