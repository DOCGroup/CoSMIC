// -*- C++ -*-

//============================================================================
/**
 * @file    LatencyBudgetQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_LATENCYBUDGETQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_LATENCYBUDGETQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class LatencyBudgetQosPolicy_Impl;
  typedef LatencyBudgetQosPolicy_Impl * LatencyBudgetQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < LatencyBudgetQosPolicy_Impl > LatencyBudgetQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class LatencyBudgetQosPolicy_Impl
   *
   * Implementation for the LatencyBudgetQosPolicy model element.
   */
  class DQML_Export LatencyBudgetQosPolicy_Impl :
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
    static LatencyBudgetQosPolicy _create (const DataReaderQos_in parent);
    static LatencyBudgetQosPolicy _create (const DataWriterQos_in parent);
    static LatencyBudgetQosPolicy _create (const TopicQos_in parent);
    static LatencyBudgetQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    LatencyBudgetQosPolicy_Impl (void);

    // Initializing constructor.
    LatencyBudgetQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~LatencyBudgetQosPolicy_Impl (void);

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

    /// Set the value of duration
    void duration (double val);

    /// Get the value of duration
    double duration (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst top_latency_Connection connection.
    size_t dst_of_top_latency_Connection (std::vector <top_latency_Connection> & items) const;
    GAME::Mga::Collection_T <top_latency_Connection> dst_of_top_latency_Connection (void) const;

    /// Get the dst dr_latency_Connection connection.
    size_t dst_of_dr_latency_Connection (std::vector <dr_latency_Connection> & items) const;
    GAME::Mga::Collection_T <dr_latency_Connection> dst_of_dr_latency_Connection (void) const;

    /// Get the dst dw_latency_Connection connection.
    size_t dst_of_dw_latency_Connection (std::vector <dw_latency_Connection> & items) const;
    GAME::Mga::Collection_T <dw_latency_Connection> dst_of_dw_latency_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "LatencyBudgetQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_LATENCYBUDGETQOSPOLICY
