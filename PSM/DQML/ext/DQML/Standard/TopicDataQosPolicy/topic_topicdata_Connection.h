// -*- C++ -*-

//============================================================================
/**
 * @file    topic_topicdata_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_TOPICDATAQOSPOLICY_TOPIC_TOPICDATA_CONNECTION_H_
#define _DQML_STANDARD_TOPICDATAQOSPOLICY_TOPIC_TOPICDATA_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class topic_topicdata_Connection_Impl;
  typedef topic_topicdata_Connection_Impl * topic_topicdata_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < topic_topicdata_Connection_Impl > topic_topicdata_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class topic_topicdata_Connection_Impl
   *
   * Implementation for the topic_topicdata_Connection model element.
   */
  class DQML_Export topic_topicdata_Connection_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static topic_topicdata_Connection _create (const DDSQoS_in parent, Topic_in src, TopicDataQosPolicy_in dst);
    ///@}

    // Default constructor.
    topic_topicdata_Connection_Impl (void);

    // Initializing constructor.
    topic_topicdata_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~topic_topicdata_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    Topic src_Topic (void) const;
    TopicDataQosPolicy dst_TopicDataQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "topic_topicdata_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_TOPICDATAQOSPOLICY_TOPIC_TOPICDATA_CONNECTION
