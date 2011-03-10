// -*- C++ -*-

//============================================================================
/**
 * @file    CollocationGroup.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUP_H_
#define _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUP_H_

#include "game/mga/Set.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CollocationGroup_Impl;
  typedef CollocationGroup_Impl * CollocationGroup_in;
  typedef ::GAME::Mga::Smart_Ptr <CollocationGroup_Impl> CollocationGroup;

  // Forward decl.
  class Visitor;

  class PICML_Export CollocationGroup_Impl :
    public virtual ::GAME::Mga::Set_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::set_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaSet interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    CollocationGroup_Impl (void);

    /// Initializing constructor
    CollocationGroup_Impl (IMgaSet * ptr);

    /// Destructor
    virtual ~CollocationGroup_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static CollocationGroup _create (const DeploymentPlan_in parent);
    ///@}
    size_t in_InstanceMapping_connections (std::vector <InstanceMapping> & conns) const;
    size_t in_CollocationGroupProperty_connections (std::vector <CollocationGroupProperty> & conns) const;

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
