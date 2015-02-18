// -*- C++ -*-

//============================================================================
/**
 * @file    TopicDataQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_TOPICDATAQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_TOPICDATAQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class TopicDataQosPolicy_Impl;
  typedef TopicDataQosPolicy_Impl * TopicDataQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < TopicDataQosPolicy_Impl > TopicDataQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class TopicDataQosPolicy_Impl
   *
   * Implementation for the TopicDataQosPolicy model element.
   */
  class DQML_Export TopicDataQosPolicy_Impl :
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
    static TopicDataQosPolicy _create (const TopicQos_in parent);
    static TopicDataQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    TopicDataQosPolicy_Impl (void);

    // Initializing constructor.
    TopicDataQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TopicDataQosPolicy_Impl (void);

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

    /// Set the value of topic_value
    void topic_value (const std::string & val);

    /// Get the value of topic_value
    std::string topic_value (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst topic_topicdata_Connection connection.
    size_t dst_of_topic_topicdata_Connection (std::vector <topic_topicdata_Connection> & items) const;
    bool has_dst_of_topic_topicdata_Connection (void) const;
    topic_topicdata_Connection dst_of_topic_topicdata_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TopicDataQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_TOPICDATAQOSPOLICY
