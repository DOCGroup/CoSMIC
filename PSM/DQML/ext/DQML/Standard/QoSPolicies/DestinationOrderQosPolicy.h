// -*- C++ -*-

//============================================================================
/**
 * @file    DestinationOrderQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_DESTINATIONORDERQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_DESTINATIONORDERQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DestinationOrderQosPolicy_Impl;
  typedef DestinationOrderQosPolicy_Impl * DestinationOrderQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < DestinationOrderQosPolicy_Impl > DestinationOrderQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class DestinationOrderQosPolicy_Impl
   *
   * Implementation for the DestinationOrderQosPolicy model element.
   */
  class DQML_Export DestinationOrderQosPolicy_Impl :
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
    static DestinationOrderQosPolicy _create (const DataWriterQos_in parent);
    static DestinationOrderQosPolicy _create (const DataReaderQos_in parent);
    static DestinationOrderQosPolicy _create (const TopicQos_in parent);
    static DestinationOrderQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    DestinationOrderQosPolicy_Impl (void);

    // Initializing constructor.
    DestinationOrderQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~DestinationOrderQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DataWriterQos parent_DataWriterQos (void);
    DataReaderQos parent_DataReaderQos (void);
    TopicQos parent_TopicQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of dest_order_kind
    void dest_order_kind (const std::string & val);

    /// Get the value of dest_order_kind
    std::string dest_order_kind (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst topic_dstOrder_Connection connection.
    size_t dst_topic_dstOrder_Connection (std::vector <topic_dstOrder_Connection> & items) const;

    /// Get the dst dw_dstOrder_Connection connection.
    size_t dst_dw_dstOrder_Connection (std::vector <dw_dstOrder_Connection> & items) const;

    /// Get the dst dr_dstOrder_Connection connection.
    size_t dst_dr_dstOrder_Connection (std::vector <dr_dstOrder_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DestinationOrderQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_DESTINATIONORDERQOSPOLICY
