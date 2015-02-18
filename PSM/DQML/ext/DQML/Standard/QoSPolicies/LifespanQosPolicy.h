// -*- C++ -*-

//============================================================================
/**
 * @file    LifespanQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_LIFESPANQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_LIFESPANQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class LifespanQosPolicy_Impl;
  typedef LifespanQosPolicy_Impl * LifespanQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < LifespanQosPolicy_Impl > LifespanQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class LifespanQosPolicy_Impl
   *
   * Implementation for the LifespanQosPolicy model element.
   */
  class DQML_Export LifespanQosPolicy_Impl :
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
    static LifespanQosPolicy _create (const TopicQos_in parent);
    static LifespanQosPolicy _create (const DataWriterQos_in parent);
    static LifespanQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    LifespanQosPolicy_Impl (void);

    // Initializing constructor.
    LifespanQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~LifespanQosPolicy_Impl (void);

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

    /// Set the value of lifespan_duration
    void lifespan_duration (double val);

    /// Get the value of lifespan_duration
    double lifespan_duration (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst topic_lifespan_Connection connection.
    size_t dst_of_topic_lifespan_Connection (std::vector <topic_lifespan_Connection> & items) const;
    bool has_dst_of_topic_lifespan_Connection (void) const;
    topic_lifespan_Connection dst_of_topic_lifespan_Connection (void) const;

    /// Get the dst dw_lifespan_Connection connection.
    size_t dst_of_dw_lifespan_Connection (std::vector <dw_lifespan_Connection> & items) const;
    bool has_dst_of_dw_lifespan_Connection (void) const;
    dw_lifespan_Connection dst_of_dw_lifespan_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "LifespanQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_LIFESPANQOSPOLICY
