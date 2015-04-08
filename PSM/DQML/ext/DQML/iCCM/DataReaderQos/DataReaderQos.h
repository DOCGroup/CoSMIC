// -*- C++ -*-

//============================================================================
/**
 * @file    DataReaderQos.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DATAREADERQOS_DATAREADERQOS_H_
#define _DQML_ICCM_DATAREADERQOS_DATAREADERQOS_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DataReaderQos_Impl;
  typedef DataReaderQos_Impl * DataReaderQos_in;
  typedef ::GAME::Mga::Smart_Ptr < DataReaderQos_Impl > DataReaderQos;

  // Forward decl.
  class Visitor;

  /**
   * @class DataReaderQos_Impl
   *
   * Implementation for the DataReaderQos model element.
   */
  class DQML_Export DataReaderQos_Impl :
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
    static DataReaderQos _create (const Participant_in parent);
    ///@}

    // Default constructor.
    DataReaderQos_Impl (void);

    // Initializing constructor.
    DataReaderQos_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DataReaderQos_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Participant parent_Participant (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of isprivate
    void isprivate (bool val);

    /// Get the value of isprivate
    bool isprivate (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src SubscriberConnection connection.
    size_t src_of_SubscriberConnection (std::vector <SubscriberConnection> & items) const;
    bool has_src_of_SubscriberConnection (void) const;
    SubscriberConnection src_of_SubscriberConnection (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst PublishesConnection connection.
    size_t dst_of_PublishesConnection (std::vector <PublishesConnection> & items) const;
    GAME::Mga::Collection_T <PublishesConnection> dst_of_PublishesConnection (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_DeadlineQosPolicy (void) const;
    DeadlineQosPolicy get_DeadlineQosPolicy (void) const;

    bool has_ResourceLimitsQosPolicy (void) const;
    ResourceLimitsQosPolicy get_ResourceLimitsQosPolicy (void) const;

    bool has_DurabilityQosPolicy (void) const;
    DurabilityQosPolicy get_DurabilityQosPolicy (void) const;

    bool has_UserDataQosPolicy (void) const;
    UserDataQosPolicy get_UserDataQosPolicy (void) const;

    bool has_DestinationOrderQosPolicy (void) const;
    DestinationOrderQosPolicy get_DestinationOrderQosPolicy (void) const;

    bool has_LatencyBudgetQosPolicy (void) const;
    LatencyBudgetQosPolicy get_LatencyBudgetQosPolicy (void) const;

    bool has_HistoryQosPolicy (void) const;
    HistoryQosPolicy get_HistoryQosPolicy (void) const;

    bool has_ReliabilityQosPolicy (void) const;
    ReliabilityQosPolicy get_ReliabilityQosPolicy (void) const;

    bool has_OwnershipQosPolicy (void) const;
    OwnershipQosPolicy get_OwnershipQosPolicy (void) const;

    bool has_TimeBasedFilterQosPolicy (void) const;
    TimeBasedFilterQosPolicy get_TimeBasedFilterQosPolicy (void) const;

    bool has_ReaderDataLifecycleQosPolicy (void) const;
    ReaderDataLifecycleQosPolicy get_ReaderDataLifecycleQosPolicy (void) const;

    bool has_ShareQosPolicy (void) const;
    ShareQosPolicy get_ShareQosPolicy (void) const;

    bool has_ReaderLifespanQosPolicy (void) const;
    ReaderLifespanQosPolicy get_ReaderLifespanQosPolicy (void) const;

    bool has_SubscriptionKeyQosPolicy (void) const;
    SubscriptionKeyQosPolicy get_SubscriptionKeyQosPolicy (void) const;

    bool has_LivelinessQosPolicy (void) const;
    LivelinessQosPolicy get_LivelinessQosPolicy (void) const;

    bool has_TopicQosReference (void) const;
    TopicQosReference get_TopicQosReference (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DataReaderQos.inl"
#endif

#endif  // !defined _DQML_ICCM_DATAREADERQOS_DATAREADERQOS
