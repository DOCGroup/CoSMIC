// -*- C++ -*-

//============================================================================
/**
 * @file    TransportPriorityQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_TRANSPORTPRIORITYQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_TRANSPORTPRIORITYQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class TransportPriorityQosPolicy_Impl;
  typedef TransportPriorityQosPolicy_Impl * TransportPriorityQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < TransportPriorityQosPolicy_Impl > TransportPriorityQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class TransportPriorityQosPolicy_Impl
   *
   * Implementation for the TransportPriorityQosPolicy model element.
   */
  class DQML_Export TransportPriorityQosPolicy_Impl :
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
    static TransportPriorityQosPolicy _create (const TopicQos_in parent);
    static TransportPriorityQosPolicy _create (const DataWriterQos_in parent);
    static TransportPriorityQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    TransportPriorityQosPolicy_Impl (void);

    // Initializing constructor.
    TransportPriorityQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TransportPriorityQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopicQos parent_TopicQos (void);
    DataWriterQos parent_DataWriterQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of transport_value
    void transport_value (long val);

    /// Get the value of transport_value
    long transport_value (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst topic_transpri_Connection connection.
    size_t dst_of_topic_transpri_Connection (std::vector <topic_transpri_Connection> & items) const;
    GAME::Mga::Collection_T <topic_transpri_Connection> dst_of_topic_transpri_Connection (void) const;

    /// Get the dst dw_transpri_Connection connection.
    size_t dst_of_dw_transpri_Connection (std::vector <dw_transpri_Connection> & items) const;
    GAME::Mga::Collection_T <dw_transpri_Connection> dst_of_dw_transpri_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TransportPriorityQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_TRANSPORTPRIORITYQOSPOLICY
