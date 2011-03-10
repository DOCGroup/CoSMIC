// -*- C++ -*-

//============================================================================
/**
 * @file    Deploys.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_DEPLOYS_H_
#define _PICML_DEPLOYMENTPLAN_DEPLOYS_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Deploys_Impl;
  typedef Deploys_Impl * Deploys_in;
  typedef ::GAME::Mga::Smart_Ptr <Deploys_Impl> Deploys;

  // Forward decl.
  class Visitor;

  class PICML_Export Deploys_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Deploys_Impl (void);

    /// Initializing constructor
    Deploys_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Deploys_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Deploys _create (const DeploymentPlan_in parent);
    ///@}

    /// Get the src ComponentFactoryRef connection point.
    ComponentFactoryRef src_ComponentFactoryRef (void);

    /// Get the dst ComponentInstanceRef connection point.
    ComponentInstanceRef dst_ComponentInstanceRef (void);

    /**
     * @name Parent Methods
     */
    ///@{
    DeploymentPlan parent_DeploymentPlan (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
