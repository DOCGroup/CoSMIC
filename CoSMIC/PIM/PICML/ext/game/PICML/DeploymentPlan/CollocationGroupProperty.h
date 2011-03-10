// -*- C++ -*-

//============================================================================
/**
 * @file    CollocationGroupProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUPPROPERTY_H_
#define _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUPPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CollocationGroupProperty_Impl;
  typedef CollocationGroupProperty_Impl * CollocationGroupProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <CollocationGroupProperty_Impl> CollocationGroupProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export CollocationGroupProperty_Impl :
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
    CollocationGroupProperty_Impl (void);

    /// Initializing constructor
    CollocationGroupProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~CollocationGroupProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static CollocationGroupProperty _create (const DeploymentPlan_in parent);
    ///@}

    /// Get the src Property connection point.
    Property src_Property (void);

    /// Get the dst CollocationGroup connection point.
    CollocationGroup dst_CollocationGroup (void);

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
