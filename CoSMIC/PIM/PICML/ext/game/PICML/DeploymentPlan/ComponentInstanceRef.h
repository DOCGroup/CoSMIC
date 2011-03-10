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

#include "game/mga/Reference.h"
#include "PICML/DeploymentPlan/CollocationGroupMember.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInstanceRef_Impl;
  typedef ComponentInstanceRef_Impl * ComponentInstanceRef_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentInstanceRef_Impl> ComponentInstanceRef;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentInstanceRef_Impl :
    public virtual CollocationGroupMember_Impl,
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentInstanceRef_Impl (void);

    /// Initializing constructor
    ComponentInstanceRef_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComponentInstanceRef_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_Deploys_connections (std::vector <Deploys> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
