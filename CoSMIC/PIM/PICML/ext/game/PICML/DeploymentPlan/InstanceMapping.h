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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InstanceMapping_Impl;
  typedef InstanceMapping_Impl * InstanceMapping_in;
  typedef ::GAME::Mga::Smart_Ptr < InstanceMapping_Impl > InstanceMapping;

  // Forward decl.
  class Visitor;

  /**
   * @class InstanceMapping_Impl
   *
   * Implementation for the InstanceMapping model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static InstanceMapping _create (const DeploymentPlan_in parent);
    ///@}

    // Default constructor.
    InstanceMapping_Impl (void);

    // Initializing constructor.
    InstanceMapping_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~InstanceMapping_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DeploymentPlan parent_DeploymentPlan (void);
    ///@}
    CollocationGroup src_CollocationGroup (void) const;
    NodeReference dst_NodeReference (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "InstanceMapping.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_INSTANCEMAPPING
