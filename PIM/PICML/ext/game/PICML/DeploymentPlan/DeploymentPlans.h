// -*- C++ -*-

//============================================================================
/**
 * @file    DeploymentPlans.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_DEPLOYMENTPLANS_H_
#define _PICML_DEPLOYMENTPLAN_DEPLOYMENTPLANS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DeploymentPlans_Impl;
  typedef DeploymentPlans_Impl * DeploymentPlans_in;
  typedef ::GAME::Mga::Smart_Ptr < DeploymentPlans_Impl > DeploymentPlans;

  // Forward decl.
  class Visitor;

  /**
   * @class DeploymentPlans_Impl
   *
   * Implementation for the DeploymentPlans model element.
   */
  class PICML_Export DeploymentPlans_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static DeploymentPlans _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    DeploymentPlans_Impl (void);

    // Initializing constructor.
    DeploymentPlans_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~DeploymentPlans_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    size_t get_DeploymentPlans (std::vector <DeploymentPlan> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "DeploymentPlans.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_DEPLOYMENTPLANS
