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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CollocationGroupMember_Impl;
  typedef CollocationGroupMember_Impl * CollocationGroupMember_in;
  typedef ::GAME::Mga::Smart_Ptr < CollocationGroupMember_Impl > CollocationGroupMember;

  /**
   * @class CollocationGroupMember_Impl
   *
   * Implementation for the CollocationGroupMember model element.
   */
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


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    CollocationGroupMember_Impl (void);

    // Initializing constructor.
    CollocationGroupMember_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~CollocationGroupMember_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    DeploymentPlan parent_DeploymentPlan (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "CollocationGroupMember.inl"
#endif

#endif  // !defined _PICML_DEPLOYMENTPLAN_COLLOCATIONGROUPMEMBER
