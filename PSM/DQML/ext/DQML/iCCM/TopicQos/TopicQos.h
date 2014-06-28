// -*- C++ -*-

//============================================================================
/**
 * @file    TopicQos.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_TOPICQOS_TOPICQOS_H_
#define _DQML_ICCM_TOPICQOS_TOPICQOS_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class TopicQos_Impl;
  typedef TopicQos_Impl * TopicQos_in;
  typedef ::GAME::Mga::Smart_Ptr < TopicQos_Impl > TopicQos;

  // Forward decl.
  class Visitor;

  /**
   * @class TopicQos_Impl
   *
   * Implementation for the TopicQos model element.
   */
  class DQML_Export TopicQos_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static TopicQos _create (const TopicQosFolder_in parent);
    ///@}

    // Default constructor.
    TopicQos_Impl (void);

    // Initializing constructor.
    TopicQos_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~TopicQos_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopicQosFolder parent_TopicQosFolder (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_DestinationOrderQosPolicy (void) const;
    DestinationOrderQosPolicy get_DestinationOrderQosPolicy (void) const;

    bool has_DeadlineQosPolicy (void) const;
    DeadlineQosPolicy get_DeadlineQosPolicy (void) const;

    bool has_TopicDataQosPolicy (void) const;
    TopicDataQosPolicy get_TopicDataQosPolicy (void) const;

    bool has_DurabilityQosPolicy (void) const;
    DurabilityQosPolicy get_DurabilityQosPolicy (void) const;

    bool has_DurabilityServiceQosPolicy (void) const;
    DurabilityServiceQosPolicy get_DurabilityServiceQosPolicy (void) const;

    bool has_ReliabilityQosPolicy (void) const;
    ReliabilityQosPolicy get_ReliabilityQosPolicy (void) const;

    bool has_LivelinessQosPolicy (void) const;
    LivelinessQosPolicy get_LivelinessQosPolicy (void) const;

    bool has_LifespanQosPolicy (void) const;
    LifespanQosPolicy get_LifespanQosPolicy (void) const;

    bool has_HistoryQosPolicy (void) const;
    HistoryQosPolicy get_HistoryQosPolicy (void) const;

    bool has_OwnershipQosPolicy (void) const;
    OwnershipQosPolicy get_OwnershipQosPolicy (void) const;

    bool has_TransportPriorityQosPolicy (void) const;
    TransportPriorityQosPolicy get_TransportPriorityQosPolicy (void) const;

    bool has_ResourceLimitsQosPolicy (void) const;
    ResourceLimitsQosPolicy get_ResourceLimitsQosPolicy (void) const;

    bool has_LatencyBudgetQosPolicy (void) const;
    LatencyBudgetQosPolicy get_LatencyBudgetQosPolicy (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TopicQos.inl"
#endif

#endif  // !defined _DQML_ICCM_TOPICQOS_TOPICQOS
