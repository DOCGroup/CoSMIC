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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Deploys_Impl;
  typedef Deploys_Impl * Deploys_in;
  typedef ::GAME::Mga::Smart_Ptr < Deploys_Impl > Deploys;

  // Forward decl.
  class Visitor;

  /**
   * @class Deploys_Impl
   *
   * Implementation for the Deploys model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static Deploys _create (const DeploymentPlan_in parent);
    ///@}

    // Default constructor.
    Deploys_Impl (void);

    // Initializing constructor.
    Deploys_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~Deploys_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    ComponentFactoryRef src_ComponentFactoryRef (void) const;
    ComponentInstanceRef dst_ComponentInstanceRef (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "Deploys.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_DEPLOYS
