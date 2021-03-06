// -*- C++ -*-

//============================================================================
/**
 * @file    PartitionQosPolicy.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_PARTITIONQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_PARTITIONQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class PartitionQosPolicy_Impl;
  typedef PartitionQosPolicy_Impl * PartitionQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < PartitionQosPolicy_Impl > PartitionQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class PartitionQosPolicy_Impl
   *
   * Implementation for the PartitionQosPolicy model element.
   */
  class DQML_Export PartitionQosPolicy_Impl :
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
    static PartitionQosPolicy _create (const PublisherQos_in parent);
    static PartitionQosPolicy _create (const SubscriberQos_in parent);
    static PartitionQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    PartitionQosPolicy_Impl (void);

    // Initializing constructor.
    PartitionQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~PartitionQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PublisherQos parent_PublisherQos (void);
    SubscriberQos parent_SubscriberQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of partition_name
    void partition_name (const std::string & val);

    /// Get the value of partition_name
    std::string partition_name (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst pub_part_Connection connection.
    size_t dst_of_pub_part_Connection (std::vector <pub_part_Connection> & items) const;
    GAME::Mga::Collection_T <pub_part_Connection> dst_of_pub_part_Connection (void) const;

    /// Get the dst sub_part_Connection connection.
    size_t dst_of_sub_part_Connection (std::vector <sub_part_Connection> & items) const;
    GAME::Mga::Collection_T <sub_part_Connection> dst_of_sub_part_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PartitionQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_PARTITIONQOSPOLICY
