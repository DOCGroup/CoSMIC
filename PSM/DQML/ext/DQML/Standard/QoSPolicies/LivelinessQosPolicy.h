// -*- C++ -*-

//============================================================================
/**
 * @file    LivelinessQosPolicy.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_LIVELINESSQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_LIVELINESSQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class LivelinessQosPolicy_Impl;
  typedef LivelinessQosPolicy_Impl * LivelinessQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < LivelinessQosPolicy_Impl > LivelinessQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class LivelinessQosPolicy_Impl
   *
   * Implementation for the LivelinessQosPolicy model element.
   */
  class DQML_Export LivelinessQosPolicy_Impl :
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
    static LivelinessQosPolicy _create (const DataReaderQos_in parent);
    static LivelinessQosPolicy _create (const DataWriterQos_in parent);
    static LivelinessQosPolicy _create (const TopicQos_in parent);
    static LivelinessQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    LivelinessQosPolicy_Impl (void);

    // Initializing constructor.
    LivelinessQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~LivelinessQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DataReaderQos parent_DataReaderQos (void);
    DataWriterQos parent_DataWriterQos (void);
    TopicQos parent_TopicQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of lease_duration
    void lease_duration (double val);

    /// Get the value of lease_duration
    double lease_duration (void) const;

    /// Set the value of liveliness_kind
    void liveliness_kind (const std::string & val);

    /// Get the value of liveliness_kind
    std::string liveliness_kind (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dw_liveliness_Connection connection.
    size_t dst_of_dw_liveliness_Connection (std::vector <dw_liveliness_Connection> & items) const;
    GAME::Mga::Collection_T <dw_liveliness_Connection> dst_of_dw_liveliness_Connection (void) const;

    /// Get the dst dr_liveliness_Connection connection.
    size_t dst_of_dr_liveliness_Connection (std::vector <dr_liveliness_Connection> & items) const;
    GAME::Mga::Collection_T <dr_liveliness_Connection> dst_of_dr_liveliness_Connection (void) const;

    /// Get the dst topic_liveliness_Connection connection.
    size_t dst_of_topic_liveliness_Connection (std::vector <topic_liveliness_Connection> & items) const;
    GAME::Mga::Collection_T <topic_liveliness_Connection> dst_of_topic_liveliness_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "LivelinessQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_LIVELINESSQOSPOLICY
