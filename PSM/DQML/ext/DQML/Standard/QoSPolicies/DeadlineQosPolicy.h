// -*- C++ -*-

//============================================================================
/**
 * @file    DeadlineQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_DEADLINEQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_DEADLINEQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DeadlineQosPolicy_Impl;
  typedef DeadlineQosPolicy_Impl * DeadlineQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < DeadlineQosPolicy_Impl > DeadlineQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class DeadlineQosPolicy_Impl
   *
   * Implementation for the DeadlineQosPolicy model element.
   */
  class DQML_Export DeadlineQosPolicy_Impl :
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
    static DeadlineQosPolicy _create (const DataReaderQos_in parent);
    static DeadlineQosPolicy _create (const DataWriterQos_in parent);
    static DeadlineQosPolicy _create (const TopicQos_in parent);
    static DeadlineQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    DeadlineQosPolicy_Impl (void);

    // Initializing constructor.
    DeadlineQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~DeadlineQosPolicy_Impl (void);

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

    /// Set the value of period
    void period (double val);

    /// Get the value of period
    double period (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dw_deadline_Connection connection.
    size_t dst_dw_deadline_Connection (std::vector <dw_deadline_Connection> & items) const;

    /// Get the dst top_deadline_Connection connection.
    size_t dst_top_deadline_Connection (std::vector <top_deadline_Connection> & items) const;

    /// Get the dst dr_deadline_Connection connection.
    size_t dst_dr_deadline_Connection (std::vector <dr_deadline_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DeadlineQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_DEADLINEQOSPOLICY
