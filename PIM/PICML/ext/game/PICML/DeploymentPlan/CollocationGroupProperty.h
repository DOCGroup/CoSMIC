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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CollocationGroupProperty_Impl;
  typedef CollocationGroupProperty_Impl * CollocationGroupProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < CollocationGroupProperty_Impl > CollocationGroupProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class CollocationGroupProperty_Impl
   *
   * Implementation for the CollocationGroupProperty model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static CollocationGroupProperty _create (const DeploymentPlan_in parent);
    ///@}

    // Default constructor.
    CollocationGroupProperty_Impl (void);

    // Initializing constructor.
    CollocationGroupProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~CollocationGroupProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DeploymentPlan parent_DeploymentPlan (void);
    ///@}
    Property src_Property (void) const;
    CollocationGroup dst_CollocationGroup (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "CollocationGroupProperty.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUPPROPERTY
