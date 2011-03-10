// -*- C++ -*-

//============================================================================
/**
 * @file    CollocationGroupMember.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUPMEMBER_H_
#define _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUPMEMBER_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CollocationGroupMember_Impl;
  typedef CollocationGroupMember_Impl * CollocationGroupMember_in;
  typedef ::GAME::Mga::Smart_Ptr <CollocationGroupMember_Impl> CollocationGroupMember;

  class PICML_Export CollocationGroupMember_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    CollocationGroupMember_Impl (void);

    /// Initializing constructor
    CollocationGroupMember_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~CollocationGroupMember_Impl (void) = 0;

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
