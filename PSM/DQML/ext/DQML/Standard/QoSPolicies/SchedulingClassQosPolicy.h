// -*- C++ -*-

//============================================================================
/**
 * @file    SchedulingClassQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_SCHEDULINGCLASSQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_SCHEDULINGCLASSQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class SchedulingClassQosPolicy_Impl;
  typedef SchedulingClassQosPolicy_Impl * SchedulingClassQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < SchedulingClassQosPolicy_Impl > SchedulingClassQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class SchedulingClassQosPolicy_Impl
   *
   * Implementation for the SchedulingClassQosPolicy model element.
   */
  class DQML_Export SchedulingClassQosPolicy_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static SchedulingClassQosPolicy _create (const SchedulingQosPolicy_in parent);
    static SchedulingClassQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    SchedulingClassQosPolicy_Impl (void);

    // Initializing constructor.
    SchedulingClassQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~SchedulingClassQosPolicy_Impl (void);

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

    /// Set the value of scheduling_class_kind
    void scheduling_class_kind (const std::string & val);

    /// Get the value of scheduling_class_kind
    std::string scheduling_class_kind (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SchedulingClassQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_SCHEDULINGCLASSQOSPOLICY
