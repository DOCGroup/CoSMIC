// -*- C++ -*-

//============================================================================
/**
 * @file    DataWriterQos.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DATAWRITERQOS_DATAWRITERQOS_H_
#define _DQML_ICCM_DATAWRITERQOS_DATAWRITERQOS_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DataWriterQos_Impl;
  typedef DataWriterQos_Impl * DataWriterQos_in;
  typedef ::GAME::Mga::Smart_Ptr < DataWriterQos_Impl > DataWriterQos;

  // Forward decl.
  class Visitor;

  /**
   * @class DataWriterQos_Impl
   *
   * Implementation for the DataWriterQos model element.
   */
  class DQML_Export DataWriterQos_Impl :
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
    static DataWriterQos _create (const Participant_in parent);
    ///@}

    // Default constructor.
    DataWriterQos_Impl (void);

    // Initializing constructor.
    DataWriterQos_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DataWriterQos_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of IsInstance
    void IsInstance (bool val);

    /// Get the value of IsInstance
    bool IsInstance (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src PublishesConnection connection.
    size_t src_PublishesConnection (std::vector <PublishesConnection> & items) const;

    /// Get the src PublisherConnection connection.
    size_t src_PublisherConnection (std::vector <PublisherConnection> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_DurabilityQosPolicy (void) const;
    DurabilityQosPolicy get_DurabilityQosPolicy (void) const;

    bool has_DeadlineQosPolicy (void) const;
    DeadlineQosPolicy get_DeadlineQosPolicy (void) const;

    bool has_LatencyBudgetQosPolicy (void) const;
    LatencyBudgetQosPolicy get_LatencyBudgetQosPolicy (void) const;

    bool has_OwnershipQosPolicy (void) const;
    OwnershipQosPolicy get_OwnershipQosPolicy (void) const;

    bool has_LivelinessQosPolicy (void) const;
    LivelinessQosPolicy get_LivelinessQosPolicy (void) const;

    bool has_ReliabilityQosPolicy (void) const;
    ReliabilityQosPolicy get_ReliabilityQosPolicy (void) const;

    bool has_DestinationOrderQosPolicy (void) const;
    DestinationOrderQosPolicy get_DestinationOrderQosPolicy (void) const;

    bool has_UserDataQosPolicy (void) const;
    UserDataQosPolicy get_UserDataQosPolicy (void) const;

    bool has_OwnershipStrengthQosPolicy (void) const;
    OwnershipStrengthQosPolicy get_OwnershipStrengthQosPolicy (void) const;

    bool has_TransportPriorityQosPolicy (void) const;
    TransportPriorityQosPolicy get_TransportPriorityQosPolicy (void) const;

    bool has_LifespanQosPolicy (void) const;
    LifespanQosPolicy get_LifespanQosPolicy (void) const;

    bool has_HistoryQosPolicy (void) const;
    HistoryQosPolicy get_HistoryQosPolicy (void) const;

    bool has_ResourceLimitsQosPolicy (void) const;
    ResourceLimitsQosPolicy get_ResourceLimitsQosPolicy (void) const;

    bool has_WriterDataLifecycleQosPolicy (void) const;
    WriterDataLifecycleQosPolicy get_WriterDataLifecycleQosPolicy (void) const;

    bool has_TopicQosReference (void) const;
    TopicQosReference get_TopicQosReference (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DataWriterQos.inl"
#endif

#endif  // !defined _DQML_ICCM_DATAWRITERQOS_DATAWRITERQOS
