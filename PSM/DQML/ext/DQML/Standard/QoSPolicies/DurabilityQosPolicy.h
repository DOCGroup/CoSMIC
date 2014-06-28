// -*- C++ -*-

//============================================================================
/**
 * @file    DurabilityQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_DURABILITYQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_DURABILITYQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DurabilityQosPolicy_Impl;
  typedef DurabilityQosPolicy_Impl * DurabilityQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < DurabilityQosPolicy_Impl > DurabilityQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class DurabilityQosPolicy_Impl
   *
   * Implementation for the DurabilityQosPolicy model element.
   */
  class DQML_Export DurabilityQosPolicy_Impl :
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
    static DurabilityQosPolicy _create (const DataReaderQos_in parent);
    static DurabilityQosPolicy _create (const DataWriterQos_in parent);
    static DurabilityQosPolicy _create (const TopicQos_in parent);
    static DurabilityQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    DurabilityQosPolicy_Impl (void);

    // Initializing constructor.
    DurabilityQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~DurabilityQosPolicy_Impl (void);

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

    /// Set the value of kind
    void kind (const std::string & val);

    /// Get the value of kind
    std::string kind (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst topic_durqos_Connection connection.
    size_t dst_topic_durqos_Connection (std::vector <topic_durqos_Connection> & items) const;

    /// Get the dst dr_durqos_Connection connection.
    size_t dst_dr_durqos_Connection (std::vector <dr_durqos_Connection> & items) const;

    /// Get the dst dw_durqos_Connection connection.
    size_t dst_dw_durqos_Connection (std::vector <dw_durqos_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DurabilityQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_DURABILITYQOSPOLICY
