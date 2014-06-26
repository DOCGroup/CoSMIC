// -*- C++ -*-

//============================================================================
/**
 * @file    DataReader.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DDSENTITIES_DATAREADER_H_
#define _DQML_STANDARD_DDSENTITIES_DATAREADER_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DataReader_Impl;
  typedef DataReader_Impl * DataReader_in;
  typedef ::GAME::Mga::Smart_Ptr < DataReader_Impl > DataReader;

  // Forward decl.
  class Visitor;

  /**
   * @class DataReader_Impl
   *
   * Implementation for the DataReader model element.
   */
  class DQML_Export DataReader_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static DataReader _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    DataReader_Impl (void);

    // Initializing constructor.
    DataReader_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DataReader_Impl (void);

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

    /// Get the src dr_timebased_Connection connection.
    size_t src_dr_timebased_Connection (std::vector <dr_timebased_Connection> & items) const;

    /// Get the src dr_res_Connection connection.
    size_t src_dr_res_Connection (std::vector <dr_res_Connection> & items) const;

    /// Get the src dr_liveliness_Connection connection.
    size_t src_dr_liveliness_Connection (std::vector <dr_liveliness_Connection> & items) const;

    /// Get the src dr_readerdatalifecycle_Connection connection.
    size_t src_dr_readerdatalifecycle_Connection (std::vector <dr_readerdatalifecycle_Connection> & items) const;

    /// Get the src dr_dstOrder_Connection connection.
    size_t src_dr_dstOrder_Connection (std::vector <dr_dstOrder_Connection> & items) const;

    /// Get the src dr_ownership_Connection connection.
    size_t src_dr_ownership_Connection (std::vector <dr_ownership_Connection> & items) const;

    /// Get the src dr_durqos_Connection connection.
    size_t src_dr_durqos_Connection (std::vector <dr_durqos_Connection> & items) const;

    /// Get the src dr_topic_Connection connection.
    size_t src_dr_topic_Connection (std::vector <dr_topic_Connection> & items) const;

    /// Get the src dr_deadline_Connection connection.
    size_t src_dr_deadline_Connection (std::vector <dr_deadline_Connection> & items) const;

    /// Get the src dr_history_Connection connection.
    size_t src_dr_history_Connection (std::vector <dr_history_Connection> & items) const;

    /// Get the src dr_latency_Connection connection.
    size_t src_dr_latency_Connection (std::vector <dr_latency_Connection> & items) const;

    /// Get the src dr_userdata_Connection connection.
    size_t src_dr_userdata_Connection (std::vector <dr_userdata_Connection> & items) const;

    /// Get the src dr_reliability_Connection connection.
    size_t src_dr_reliability_Connection (std::vector <dr_reliability_Connection> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dr_sub_Connection connection.
    size_t dst_dr_sub_Connection (std::vector <dr_sub_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DataReader.inl"
#endif

#endif  // !defined _DQML_STANDARD_DDSENTITIES_DATAREADER
