// -*- C++ -*-

//============================================================================
/**
 * @file    HistoryQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_HISTORYQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_HISTORYQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class HistoryQosPolicy_Impl;
  typedef HistoryQosPolicy_Impl * HistoryQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < HistoryQosPolicy_Impl > HistoryQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class HistoryQosPolicy_Impl
   *
   * Implementation for the HistoryQosPolicy model element.
   */
  class DQML_Export HistoryQosPolicy_Impl :
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
    static HistoryQosPolicy _create (const DataReaderQos_in parent);
    static HistoryQosPolicy _create (const DataWriterQos_in parent);
    static HistoryQosPolicy _create (const TopicQos_in parent);
    static HistoryQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    HistoryQosPolicy_Impl (void);

    // Initializing constructor.
    HistoryQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~HistoryQosPolicy_Impl (void);

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

    /// Set the value of history_kind
    void history_kind (const std::string & val);

    /// Get the value of history_kind
    std::string history_kind (void) const;

    /// Set the value of history_depth
    void history_depth (long val);

    /// Get the value of history_depth
    long history_depth (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dw_history_Connection connection.
    size_t dst_dw_history_Connection (std::vector <dw_history_Connection> & items) const;

    /// Get the dst topic_history_Connection connection.
    size_t dst_topic_history_Connection (std::vector <topic_history_Connection> & items) const;

    /// Get the dst dr_history_Connection connection.
    size_t dst_dr_history_Connection (std::vector <dr_history_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "HistoryQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_HISTORYQOSPOLICY
