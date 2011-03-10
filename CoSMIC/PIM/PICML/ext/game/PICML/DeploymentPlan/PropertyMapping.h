// -*- C++ -*-

//============================================================================
/**
 * @file    PropertyMapping.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_PROPERTYMAPPING_H_
#define _PICML_DEPLOYMENTPLAN_PROPERTYMAPPING_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PropertyMapping_Impl;
  typedef PropertyMapping_Impl * PropertyMapping_in;
  typedef ::GAME::Mga::Smart_Ptr <PropertyMapping_Impl> PropertyMapping;

  // Forward decl.
  class Visitor;

  class PICML_Export PropertyMapping_Impl :
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
    PropertyMapping_Impl (void);

    /// Initializing constructor
    PropertyMapping_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~PropertyMapping_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PropertyMapping _create (const DeploymentPlan_in parent);
    ///@}

    /// Get the src NodeReference connection point.
    NodeReference src_NodeReference (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

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
