// -*- C++ -*-

//============================================================================
/**
 * @file    DDSQoS.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_MAIN_DDSQOS_H_
#define _DQML_STANDARD_MAIN_DDSQOS_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/RootFolder.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DDSQoS_Impl;
  typedef DDSQoS_Impl * DDSQoS_in;
  typedef ::GAME::Mga::Smart_Ptr < DDSQoS_Impl > DDSQoS;

  // Forward decl.
  class Visitor;

  /**
   * @class DDSQoS_Impl
   *
   * Implementation for the DDSQoS model element.
   */
  class DQML_Export DDSQoS_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static DDSQoS _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    DDSQoS_Impl (void);

    // Initializing constructor.
    DDSQoS_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DDSQoS_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_dr_topic_Connections (std::vector <dr_topic_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_topic_Connection> get_dr_topic_Connections (void) const;

    size_t get_dw_topic_Connections (std::vector <dw_topic_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_topic_Connection> get_dw_topic_Connections (void) const;

    size_t get_dw_pub_Connections (std::vector <dw_pub_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_pub_Connection> get_dw_pub_Connections (void) const;

    size_t get_dr_sub_Connections (std::vector <dr_sub_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_sub_Connection> get_dr_sub_Connections (void) const;

    size_t get_dp_topic_Connections (std::vector <dp_topic_Connection> & items) const;
    ::GAME::Mga::Iterator <dp_topic_Connection> get_dp_topic_Connections (void) const;

    size_t get_dp_pub_Connections (std::vector <dp_pub_Connection> & items) const;
    ::GAME::Mga::Iterator <dp_pub_Connection> get_dp_pub_Connections (void) const;

    size_t get_dp_sub_Connections (std::vector <dp_sub_Connection> & items) const;
    ::GAME::Mga::Iterator <dp_sub_Connection> get_dp_sub_Connections (void) const;

    size_t get_dpf_dp_Connections (std::vector <dpf_dp_Connection> & items) const;
    ::GAME::Mga::Iterator <dpf_dp_Connection> get_dpf_dp_Connections (void) const;

    size_t get_DomainEntitys (std::vector <DomainEntity> & items) const;
    ::GAME::Mga::Iterator <DomainEntity> get_DomainEntitys (void) const;

    size_t get_QoSPolicys (std::vector <QoSPolicy> & items) const;
    ::GAME::Mga::Iterator <QoSPolicy> get_QoSPolicys (void) const;

    size_t get_dr_durqos_Connections (std::vector <dr_durqos_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_durqos_Connection> get_dr_durqos_Connections (void) const;

    size_t get_topic_durqos_Connections (std::vector <topic_durqos_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_durqos_Connection> get_topic_durqos_Connections (void) const;

    size_t get_dw_durqos_Connections (std::vector <dw_durqos_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_durqos_Connection> get_dw_durqos_Connections (void) const;

    size_t get_pub_presqos_Connections (std::vector <pub_presqos_Connection> & items) const;
    ::GAME::Mga::Iterator <pub_presqos_Connection> get_pub_presqos_Connections (void) const;

    size_t get_sub_presqos_Connections (std::vector <sub_presqos_Connection> & items) const;
    ::GAME::Mga::Iterator <sub_presqos_Connection> get_sub_presqos_Connections (void) const;

    size_t get_dr_deadline_Connections (std::vector <dr_deadline_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_deadline_Connection> get_dr_deadline_Connections (void) const;

    size_t get_top_deadline_Connections (std::vector <top_deadline_Connection> & items) const;
    ::GAME::Mga::Iterator <top_deadline_Connection> get_top_deadline_Connections (void) const;

    size_t get_dw_deadline_Connections (std::vector <dw_deadline_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_deadline_Connection> get_dw_deadline_Connections (void) const;

    size_t get_dr_timebased_Connections (std::vector <dr_timebased_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_timebased_Connection> get_dr_timebased_Connections (void) const;

    size_t get_top_latency_Connections (std::vector <top_latency_Connection> & items) const;
    ::GAME::Mga::Iterator <top_latency_Connection> get_top_latency_Connections (void) const;

    size_t get_dr_latency_Connections (std::vector <dr_latency_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_latency_Connection> get_dr_latency_Connections (void) const;

    size_t get_dw_latency_Connections (std::vector <dw_latency_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_latency_Connection> get_dw_latency_Connections (void) const;

    size_t get_dr_ownership_Connections (std::vector <dr_ownership_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_ownership_Connection> get_dr_ownership_Connections (void) const;

    size_t get_topic_ownership_Connections (std::vector <topic_ownership_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_ownership_Connection> get_topic_ownership_Connections (void) const;

    size_t get_dw_ownership_Connections (std::vector <dw_ownership_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_ownership_Connection> get_dw_ownership_Connections (void) const;

    size_t get_dr_liveliness_Connections (std::vector <dr_liveliness_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_liveliness_Connection> get_dr_liveliness_Connections (void) const;

    size_t get_topic_liveliness_Connections (std::vector <topic_liveliness_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_liveliness_Connection> get_topic_liveliness_Connections (void) const;

    size_t get_dw_liveliness_Connections (std::vector <dw_liveliness_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_liveliness_Connection> get_dw_liveliness_Connections (void) const;

    size_t get_dr_reliability_Connections (std::vector <dr_reliability_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_reliability_Connection> get_dr_reliability_Connections (void) const;

    size_t get_topic_reliability_Connections (std::vector <topic_reliability_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_reliability_Connection> get_topic_reliability_Connections (void) const;

    size_t get_dw_reliability_Connections (std::vector <dw_reliability_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_reliability_Connection> get_dw_reliability_Connections (void) const;

    size_t get_dr_dstOrder_Connections (std::vector <dr_dstOrder_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_dstOrder_Connection> get_dr_dstOrder_Connections (void) const;

    size_t get_topic_dstOrder_Connections (std::vector <topic_dstOrder_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_dstOrder_Connection> get_topic_dstOrder_Connections (void) const;

    size_t get_dw_dstOrder_Connections (std::vector <dw_dstOrder_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_dstOrder_Connection> get_dw_dstOrder_Connections (void) const;

    size_t get_dp_userdata_Connections (std::vector <dp_userdata_Connection> & items) const;
    ::GAME::Mga::Iterator <dp_userdata_Connection> get_dp_userdata_Connections (void) const;

    size_t get_dr_userdata_Connections (std::vector <dr_userdata_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_userdata_Connection> get_dr_userdata_Connections (void) const;

    size_t get_dw_userdata_Connections (std::vector <dw_userdata_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_userdata_Connection> get_dw_userdata_Connections (void) const;

    size_t get_topic_topicdata_Connections (std::vector <topic_topicdata_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_topicdata_Connection> get_topic_topicdata_Connections (void) const;

    size_t get_pub_groupdata_Connections (std::vector <pub_groupdata_Connection> & items) const;
    ::GAME::Mga::Iterator <pub_groupdata_Connection> get_pub_groupdata_Connections (void) const;

    size_t get_sub_groupdata_Connections (std::vector <sub_groupdata_Connection> & items) const;
    ::GAME::Mga::Iterator <sub_groupdata_Connection> get_sub_groupdata_Connections (void) const;

    size_t get_topic_dursvc_Connections (std::vector <topic_dursvc_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_dursvc_Connection> get_topic_dursvc_Connections (void) const;

    size_t get_dw_dursvc_Connections (std::vector <dw_dursvc_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_dursvc_Connection> get_dw_dursvc_Connections (void) const;

    size_t get_dw_ownerstrength_Connections (std::vector <dw_ownerstrength_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_ownerstrength_Connection> get_dw_ownerstrength_Connections (void) const;

    size_t get_pub_part_Connections (std::vector <pub_part_Connection> & items) const;
    ::GAME::Mga::Iterator <pub_part_Connection> get_pub_part_Connections (void) const;

    size_t get_sub_part_Connections (std::vector <sub_part_Connection> & items) const;
    ::GAME::Mga::Iterator <sub_part_Connection> get_sub_part_Connections (void) const;

    size_t get_dw_transpri_Connections (std::vector <dw_transpri_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_transpri_Connection> get_dw_transpri_Connections (void) const;

    size_t get_topic_transpri_Connections (std::vector <topic_transpri_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_transpri_Connection> get_topic_transpri_Connections (void) const;

    size_t get_topic_lifespan_Connections (std::vector <topic_lifespan_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_lifespan_Connection> get_topic_lifespan_Connections (void) const;

    size_t get_dw_lifespan_Connections (std::vector <dw_lifespan_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_lifespan_Connection> get_dw_lifespan_Connections (void) const;

    size_t get_dr_history_Connections (std::vector <dr_history_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_history_Connection> get_dr_history_Connections (void) const;

    size_t get_topic_history_Connections (std::vector <topic_history_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_history_Connection> get_topic_history_Connections (void) const;

    size_t get_dw_history_Connections (std::vector <dw_history_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_history_Connection> get_dw_history_Connections (void) const;

    size_t get_dr_res_Connections (std::vector <dr_res_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_res_Connection> get_dr_res_Connections (void) const;

    size_t get_topic_res_Connections (std::vector <topic_res_Connection> & items) const;
    ::GAME::Mga::Iterator <topic_res_Connection> get_topic_res_Connections (void) const;

    size_t get_dw_res_Connections (std::vector <dw_res_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_res_Connection> get_dw_res_Connections (void) const;

    size_t get_dpfactory_entityfactory_Connections (std::vector <dpfactory_entityfactory_Connection> & items) const;
    ::GAME::Mga::Iterator <dpfactory_entityfactory_Connection> get_dpfactory_entityfactory_Connections (void) const;

    size_t get_dp_entityfactory_Connections (std::vector <dp_entityfactory_Connection> & items) const;
    ::GAME::Mga::Iterator <dp_entityfactory_Connection> get_dp_entityfactory_Connections (void) const;

    size_t get_pub_entityfactory_Connections (std::vector <pub_entityfactory_Connection> & items) const;
    ::GAME::Mga::Iterator <pub_entityfactory_Connection> get_pub_entityfactory_Connections (void) const;

    size_t get_sub_entityfactory_Connections (std::vector <sub_entityfactory_Connection> & items) const;
    ::GAME::Mga::Iterator <sub_entityfactory_Connection> get_sub_entityfactory_Connections (void) const;

    size_t get_dw_writerdatalifecycle_Connections (std::vector <dw_writerdatalifecycle_Connection> & items) const;
    ::GAME::Mga::Iterator <dw_writerdatalifecycle_Connection> get_dw_writerdatalifecycle_Connections (void) const;

    size_t get_dr_readerdatalifecycle_Connections (std::vector <dr_readerdatalifecycle_Connection> & items) const;
    ::GAME::Mga::Iterator <dr_readerdatalifecycle_Connection> get_dr_readerdatalifecycle_Connections (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DDSQoS.inl"
#endif

#endif  // !defined _DQML_STANDARD_MAIN_DDSQOS
