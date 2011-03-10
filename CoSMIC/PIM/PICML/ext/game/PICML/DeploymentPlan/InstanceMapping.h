// -*- C++ -*-

//============================================================================
/**
 * @file    InstanceMapping.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_INSTANCEMAPPING_H_
#define _PICML_DEPLOYMENTPLAN_INSTANCEMAPPING_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InstanceMapping_Impl;
  typedef InstanceMapping_Impl * InstanceMapping_in;
  typedef ::GAME::Mga::Smart_Ptr <InstanceMapping_Impl> InstanceMapping;

  // Forward decl.
  class Visitor;

  class PICML_Export InstanceMapping_Impl :
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
    InstanceMapping_Impl (void);

    /// Initializing constructor
    InstanceMapping_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~InstanceMapping_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static InstanceMapping _create (const DeploymentPlan_in parent);
    ///@}

    /// Get the src CollocationGroup connection point.
    CollocationGroup src_CollocationGroup (void);

    /// Get the dst NodeReference connection point.
    NodeReference dst_NodeReference (void);

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
