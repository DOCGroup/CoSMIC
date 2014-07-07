// -*- C++ -*-

//============================================================================
/**
 * @file    Participant.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DOMAINPARTICIPANTQOS_PARTICIPANT_H_
#define _DQML_ICCM_DOMAINPARTICIPANTQOS_PARTICIPANT_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class Participant_Impl;
  typedef Participant_Impl * Participant_in;
  typedef ::GAME::Mga::Smart_Ptr < Participant_Impl > Participant;

  // Forward decl.
  class Visitor;

  /**
   * @class Participant_Impl
   *
   * Implementation for the Participant model element.
   */
  class DQML_Export Participant_Impl :
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
    static Participant _create (const Domain_in parent);
    ///@}

    // Default constructor.
    Participant_Impl (void);

    // Initializing constructor.
    Participant_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Participant_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Domain parent_Domain (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_EntityFactoryQosPolicy (void) const;
    EntityFactoryQosPolicy get_EntityFactoryQosPolicy (void) const;

    bool has_UserDataQosPolicy (void) const;
    UserDataQosPolicy get_UserDataQosPolicy (void) const;

    bool has_WatchdogSchedulingQosPolicy (void) const;
    WatchdogSchedulingQosPolicy get_WatchdogSchedulingQosPolicy (void) const;

    bool has_ListenerSchedulingQosPolicy (void) const;
    ListenerSchedulingQosPolicy get_ListenerSchedulingQosPolicy (void) const;
    size_t get_SubscriberConnections (std::vector <SubscriberConnection> & items) const;
    ::GAME::Mga::Collection_T <SubscriberConnection> get_SubscriberConnections (void) const;

    size_t get_PublisherConnections (std::vector <PublisherConnection> & items) const;
    ::GAME::Mga::Collection_T <PublisherConnection> get_PublisherConnections (void) const;

    size_t get_DataWriterQoss (std::vector <DataWriterQos> & items) const;
    ::GAME::Mga::Collection_T <DataWriterQos> get_DataWriterQoss (void) const;

    size_t get_SubscriberQoss (std::vector <SubscriberQos> & items) const;
    ::GAME::Mga::Collection_T <SubscriberQos> get_SubscriberQoss (void) const;

    size_t get_DataReaderQoss (std::vector <DataReaderQos> & items) const;
    ::GAME::Mga::Collection_T <DataReaderQos> get_DataReaderQoss (void) const;

    size_t get_PublisherQoss (std::vector <PublisherQos> & items) const;
    ::GAME::Mga::Collection_T <PublisherQos> get_PublisherQoss (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Participant.inl"
#endif

#endif  // !defined _DQML_ICCM_DOMAINPARTICIPANTQOS_PARTICIPANT
