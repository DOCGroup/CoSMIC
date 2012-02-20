// -*- C++ -*-

//============================================================================
/**
 * @file    ReliabilityQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_RELIABILITYQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_RELIABILITYQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class ReliabilityQosPolicy_Impl;
  typedef ReliabilityQosPolicy_Impl * ReliabilityQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < ReliabilityQosPolicy_Impl > ReliabilityQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class ReliabilityQosPolicy_Impl
   *
   * Implementation for the ReliabilityQosPolicy model element.
   */
  class DQML_Export ReliabilityQosPolicy_Impl :
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
    static ReliabilityQosPolicy _create (const TopicQos_in parent);
    static ReliabilityQosPolicy _create (const DataWriterQos_in parent);
    static ReliabilityQosPolicy _create (const DataReaderQos_in parent);
    static ReliabilityQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    ReliabilityQosPolicy_Impl (void);

    // Initializing constructor.
    ReliabilityQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ReliabilityQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of reliability_kind
    void reliability_kind (const std::string & val);

    /// Get the value of reliability_kind
    std::string reliability_kind (void) const;

    /// Set the value of max_blocking_time
    void max_blocking_time (double val);

    /// Get the value of max_blocking_time
    double max_blocking_time (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dr_reliability_Connection connection.
    size_t dst_dr_reliability_Connection (std::vector <dr_reliability_Connection> & items) const;

    /// Get the dst topic_reliability_Connection connection.
    size_t dst_topic_reliability_Connection (std::vector <topic_reliability_Connection> & items) const;

    /// Get the dst dw_reliability_Connection connection.
    size_t dst_dw_reliability_Connection (std::vector <dw_reliability_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ReliabilityQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_RELIABILITYQOSPOLICY
