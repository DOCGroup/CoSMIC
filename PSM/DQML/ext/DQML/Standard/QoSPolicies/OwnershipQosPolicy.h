// -*- C++ -*-

//============================================================================
/**
 * @file    OwnershipQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_OWNERSHIPQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_OWNERSHIPQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class OwnershipQosPolicy_Impl;
  typedef OwnershipQosPolicy_Impl * OwnershipQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < OwnershipQosPolicy_Impl > OwnershipQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class OwnershipQosPolicy_Impl
   *
   * Implementation for the OwnershipQosPolicy model element.
   */
  class DQML_Export OwnershipQosPolicy_Impl :
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
    static OwnershipQosPolicy _create (const DataReaderQos_in parent);
    static OwnershipQosPolicy _create (const DataWriterQos_in parent);
    static OwnershipQosPolicy _create (const TopicQos_in parent);
    static OwnershipQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    OwnershipQosPolicy_Impl (void);

    // Initializing constructor.
    OwnershipQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~OwnershipQosPolicy_Impl (void);

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

    /// Set the value of ownership_kind
    void ownership_kind (const std::string & val);

    /// Get the value of ownership_kind
    std::string ownership_kind (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dw_ownership_Connection connection.
    size_t dst_of_dw_ownership_Connection (std::vector <dw_ownership_Connection> & items) const;
    GAME::Mga::Collection_T <dw_ownership_Connection> dst_of_dw_ownership_Connection (void) const;

    /// Get the dst dr_ownership_Connection connection.
    size_t dst_of_dr_ownership_Connection (std::vector <dr_ownership_Connection> & items) const;
    GAME::Mga::Collection_T <dr_ownership_Connection> dst_of_dr_ownership_Connection (void) const;

    /// Get the dst topic_ownership_Connection connection.
    size_t dst_of_topic_ownership_Connection (std::vector <topic_ownership_Connection> & items) const;
    GAME::Mga::Collection_T <topic_ownership_Connection> dst_of_topic_ownership_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OwnershipQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_OWNERSHIPQOSPOLICY
