// -*- C++ -*-

//============================================================================
/**
 * @file    Topic.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DDSENTITIES_TOPIC_H_
#define _DQML_STANDARD_DDSENTITIES_TOPIC_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class Topic_Impl;
  typedef Topic_Impl * Topic_in;
  typedef ::GAME::Mga::Smart_Ptr < Topic_Impl > Topic;

  // Forward decl.
  class Visitor;

  /**
   * @class Topic_Impl
   *
   * Implementation for the Topic model element.
   */
  class DQML_Export Topic_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual DomainEntity_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Topic _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    Topic_Impl (void);

    // Initializing constructor.
    Topic_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Topic_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src topic_transpri_Connection connection.
    size_t src_of_topic_transpri_Connection (std::vector <topic_transpri_Connection> & items) const;
    bool has_src_of_topic_transpri_Connection (void) const;
    topic_transpri_Connection src_of_topic_transpri_Connection (void) const;

    /// Get the src topic_reliability_Connection connection.
    size_t src_of_topic_reliability_Connection (std::vector <topic_reliability_Connection> & items) const;
    bool has_src_of_topic_reliability_Connection (void) const;
    topic_reliability_Connection src_of_topic_reliability_Connection (void) const;

    /// Get the src topic_dursvc_Connection connection.
    size_t src_of_topic_dursvc_Connection (std::vector <topic_dursvc_Connection> & items) const;
    bool has_src_of_topic_dursvc_Connection (void) const;
    topic_dursvc_Connection src_of_topic_dursvc_Connection (void) const;

    /// Get the src topic_ownership_Connection connection.
    size_t src_of_topic_ownership_Connection (std::vector <topic_ownership_Connection> & items) const;
    bool has_src_of_topic_ownership_Connection (void) const;
    topic_ownership_Connection src_of_topic_ownership_Connection (void) const;

    /// Get the src topic_dstOrder_Connection connection.
    size_t src_of_topic_dstOrder_Connection (std::vector <topic_dstOrder_Connection> & items) const;
    bool has_src_of_topic_dstOrder_Connection (void) const;
    topic_dstOrder_Connection src_of_topic_dstOrder_Connection (void) const;

    /// Get the src topic_lifespan_Connection connection.
    size_t src_of_topic_lifespan_Connection (std::vector <topic_lifespan_Connection> & items) const;
    bool has_src_of_topic_lifespan_Connection (void) const;
    topic_lifespan_Connection src_of_topic_lifespan_Connection (void) const;

    /// Get the src topic_history_Connection connection.
    size_t src_of_topic_history_Connection (std::vector <topic_history_Connection> & items) const;
    bool has_src_of_topic_history_Connection (void) const;
    topic_history_Connection src_of_topic_history_Connection (void) const;

    /// Get the src top_latency_Connection connection.
    size_t src_of_top_latency_Connection (std::vector <top_latency_Connection> & items) const;
    bool has_src_of_top_latency_Connection (void) const;
    top_latency_Connection src_of_top_latency_Connection (void) const;

    /// Get the src top_deadline_Connection connection.
    size_t src_of_top_deadline_Connection (std::vector <top_deadline_Connection> & items) const;
    bool has_src_of_top_deadline_Connection (void) const;
    top_deadline_Connection src_of_top_deadline_Connection (void) const;

    /// Get the src topic_liveliness_Connection connection.
    size_t src_of_topic_liveliness_Connection (std::vector <topic_liveliness_Connection> & items) const;
    bool has_src_of_topic_liveliness_Connection (void) const;
    topic_liveliness_Connection src_of_topic_liveliness_Connection (void) const;

    /// Get the src topic_topicdata_Connection connection.
    size_t src_of_topic_topicdata_Connection (std::vector <topic_topicdata_Connection> & items) const;
    bool has_src_of_topic_topicdata_Connection (void) const;
    topic_topicdata_Connection src_of_topic_topicdata_Connection (void) const;

    /// Get the src topic_res_Connection connection.
    size_t src_of_topic_res_Connection (std::vector <topic_res_Connection> & items) const;
    bool has_src_of_topic_res_Connection (void) const;
    topic_res_Connection src_of_topic_res_Connection (void) const;

    /// Get the src topic_durqos_Connection connection.
    size_t src_of_topic_durqos_Connection (std::vector <topic_durqos_Connection> & items) const;
    bool has_src_of_topic_durqos_Connection (void) const;
    topic_durqos_Connection src_of_topic_durqos_Connection (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dr_topic_Connection connection.
    size_t dst_of_dr_topic_Connection (std::vector <dr_topic_Connection> & items) const;
    GAME::Mga::Collection_T <dr_topic_Connection> dst_of_dr_topic_Connection (void) const;

    /// Get the dst dp_topic_Connection connection.
    size_t dst_of_dp_topic_Connection (std::vector <dp_topic_Connection> & items) const;
    dp_topic_Connection dst_of_dp_topic_Connection (void) const;

    /// Get the dst dw_topic_Connection connection.
    size_t dst_of_dw_topic_Connection (std::vector <dw_topic_Connection> & items) const;
    GAME::Mga::Collection_T <dw_topic_Connection> dst_of_dw_topic_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Topic.inl"
#endif

#endif  // !defined _DQML_STANDARD_DDSENTITIES_TOPIC
