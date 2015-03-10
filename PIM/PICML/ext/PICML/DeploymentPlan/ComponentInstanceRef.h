// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInstanceRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_COMPONENTINSTANCEREF_H_
#define _PICML_DEPLOYMENTPLAN_COMPONENTINSTANCEREF_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/DeploymentPlan/CollocationGroupMember.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInstanceRef_Impl;
  typedef ComponentInstanceRef_Impl * ComponentInstanceRef_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentInstanceRef_Impl > ComponentInstanceRef;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentInstanceRef_Impl
   *
   * Implementation for the ComponentInstanceRef model element.
   */
  class PICML_Export ComponentInstanceRef_Impl :
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentInstanceRef _create (const DeploymentPlan_in parent);
    ///@}

    // Default constructor.
    ComponentInstanceRef_Impl (void);

    // Initializing constructor.
    ComponentInstanceRef_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentInstanceRef_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst Deploys connection.
    size_t dst_of_Deploys (std::vector <Deploys> & items) const;
    bool has_dst_of_Deploys (void) const;
    Deploys dst_of_Deploys (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ComponentInstance_is_nil (void) const;
    ComponentInstance refers_to_ComponentInstance (void) const;
    void refers_to_ComponentInstance (ComponentInstance_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentInstanceRef.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_COMPONENTINSTANCEREF
