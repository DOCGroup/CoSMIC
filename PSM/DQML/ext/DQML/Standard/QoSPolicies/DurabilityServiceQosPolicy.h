// -*- C++ -*-

//============================================================================
/**
 * @file    DurabilityServiceQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_DURABILITYSERVICEQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_DURABILITYSERVICEQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DurabilityServiceQosPolicy_Impl;
  typedef DurabilityServiceQosPolicy_Impl * DurabilityServiceQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < DurabilityServiceQosPolicy_Impl > DurabilityServiceQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class DurabilityServiceQosPolicy_Impl
   *
   * Implementation for the DurabilityServiceQosPolicy model element.
   */
  class DQML_Export DurabilityServiceQosPolicy_Impl :
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
    static DurabilityServiceQosPolicy _create (const TopicQos_in parent);
    static DurabilityServiceQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    DurabilityServiceQosPolicy_Impl (void);

    // Initializing constructor.
    DurabilityServiceQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~DurabilityServiceQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopicQos parent_TopicQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of service_cleanup_delay
    void service_cleanup_delay (double val);

    /// Get the value of service_cleanup_delay
    double service_cleanup_delay (void) const;

    /// Set the value of history_kind
    void history_kind (const std::string & val);

    /// Get the value of history_kind
    std::string history_kind (void) const;

    /// Set the value of history_depth
    void history_depth (long val);

    /// Get the value of history_depth
    long history_depth (void) const;

    /// Set the value of max_samples
    void max_samples (long val);

    /// Get the value of max_samples
    long max_samples (void) const;

    /// Set the value of max_instances
    void max_instances (long val);

    /// Get the value of max_instances
    long max_instances (void) const;

    /// Set the value of max_samples_per_instance
    void max_samples_per_instance (long val);

    /// Get the value of max_samples_per_instance
    long max_samples_per_instance (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst topic_dursvc_Connection connection.
    size_t dst_of_topic_dursvc_Connection (std::vector <topic_dursvc_Connection> & items) const;
    GAME::Mga::Collection_T <topic_dursvc_Connection> dst_of_topic_dursvc_Connection (void) const;

    /// Get the dst dw_dursvc_Connection connection.
    size_t dst_of_dw_dursvc_Connection (std::vector <dw_dursvc_Connection> & items) const;
    GAME::Mga::Collection_T <dw_dursvc_Connection> dst_of_dw_dursvc_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DurabilityServiceQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_DURABILITYSERVICEQOSPOLICY
