// -*- C++ -*-

//============================================================================
/**
 * @file    ResourceLimitsQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_RESOURCELIMITSQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_RESOURCELIMITSQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class ResourceLimitsQosPolicy_Impl;
  typedef ResourceLimitsQosPolicy_Impl * ResourceLimitsQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < ResourceLimitsQosPolicy_Impl > ResourceLimitsQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class ResourceLimitsQosPolicy_Impl
   *
   * Implementation for the ResourceLimitsQosPolicy model element.
   */
  class DQML_Export ResourceLimitsQosPolicy_Impl :
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
    static ResourceLimitsQosPolicy _create (const DataReaderQos_in parent);
    static ResourceLimitsQosPolicy _create (const DataWriterQos_in parent);
    static ResourceLimitsQosPolicy _create (const TopicQos_in parent);
    static ResourceLimitsQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    ResourceLimitsQosPolicy_Impl (void);

    // Initializing constructor.
    ResourceLimitsQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ResourceLimitsQosPolicy_Impl (void);

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

    /// Get the dst dw_res_Connection connection.
    size_t dst_dw_res_Connection (std::vector <dw_res_Connection> & items) const;

    /// Get the dst dr_res_Connection connection.
    size_t dst_dr_res_Connection (std::vector <dr_res_Connection> & items) const;

    /// Get the dst topic_res_Connection connection.
    size_t dst_topic_res_Connection (std::vector <topic_res_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ResourceLimitsQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_RESOURCELIMITSQOSPOLICY
