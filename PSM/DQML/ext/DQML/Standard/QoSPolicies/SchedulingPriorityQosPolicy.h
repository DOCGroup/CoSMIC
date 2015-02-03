// -*- C++ -*-

//============================================================================
/**
 * @file    SchedulingPriorityQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_SCHEDULINGPRIORITYQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_SCHEDULINGPRIORITYQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class SchedulingPriorityQosPolicy_Impl;
  typedef SchedulingPriorityQosPolicy_Impl * SchedulingPriorityQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < SchedulingPriorityQosPolicy_Impl > SchedulingPriorityQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class SchedulingPriorityQosPolicy_Impl
   *
   * Implementation for the SchedulingPriorityQosPolicy model element.
   */
  class DQML_Export SchedulingPriorityQosPolicy_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual QoSPolicy_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static SchedulingPriorityQosPolicy _create (const SchedulingQosPolicy_in parent);
    static SchedulingPriorityQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    SchedulingPriorityQosPolicy_Impl (void);

    // Initializing constructor.
    SchedulingPriorityQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~SchedulingPriorityQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    SchedulingQosPolicy parent_SchedulingQosPolicy (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of scheduling_priority_kind
    void scheduling_priority_kind (const std::string & val);

    /// Get the value of scheduling_priority_kind
    std::string scheduling_priority_kind (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SchedulingPriorityQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_SCHEDULINGPRIORITYQOSPOLICY
