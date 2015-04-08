// -*- C++ -*-

//============================================================================
/**
 * @file    SchedulingQosPolicy.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_SCHEDULINGQOSPOLICY_SCHEDULINGQOSPOLICY_H_
#define _DQML_STANDARD_SCHEDULINGQOSPOLICY_SCHEDULINGQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class SchedulingQosPolicy_Impl;
  typedef SchedulingQosPolicy_Impl * SchedulingQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < SchedulingQosPolicy_Impl > SchedulingQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class SchedulingQosPolicy_Impl
   *
   * Implementation for the SchedulingQosPolicy model element.
   */
  class DQML_Export SchedulingQosPolicy_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    // Default constructor.
    SchedulingQosPolicy_Impl (void);

    // Initializing constructor.
    SchedulingQosPolicy_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~SchedulingQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of scheduling_priority
    void scheduling_priority (long val);

    /// Get the value of scheduling_priority
    long scheduling_priority (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_SchedulingPriorityQosPolicy (void) const;
    SchedulingPriorityQosPolicy get_SchedulingPriorityQosPolicy (void) const;

    bool has_SchedulingClassQosPolicy (void) const;
    SchedulingClassQosPolicy get_SchedulingClassQosPolicy (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SchedulingQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_SCHEDULINGQOSPOLICY_SCHEDULINGQOSPOLICY
