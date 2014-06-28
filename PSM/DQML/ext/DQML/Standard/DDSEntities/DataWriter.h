// -*- C++ -*-

//============================================================================
/**
 * @file    DataWriter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DDSENTITIES_DATAWRITER_H_
#define _DQML_STANDARD_DDSENTITIES_DATAWRITER_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DataWriter_Impl;
  typedef DataWriter_Impl * DataWriter_in;
  typedef ::GAME::Mga::Smart_Ptr < DataWriter_Impl > DataWriter;

  // Forward decl.
  class Visitor;

  /**
   * @class DataWriter_Impl
   *
   * Implementation for the DataWriter model element.
   */
  class DQML_Export DataWriter_Impl :
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
    static DataWriter _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    DataWriter_Impl (void);

    // Initializing constructor.
    DataWriter_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DataWriter_Impl (void);

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

    /// Get the src dw_dursvc_Connection connection.
    size_t src_dw_dursvc_Connection (std::vector <dw_dursvc_Connection> & items) const;

    /// Get the src dw_ownership_Connection connection.
    size_t src_dw_ownership_Connection (std::vector <dw_ownership_Connection> & items) const;

    /// Get the src dw_res_Connection connection.
    size_t src_dw_res_Connection (std::vector <dw_res_Connection> & items) const;

    /// Get the src dw_transpri_Connection connection.
    size_t src_dw_transpri_Connection (std::vector <dw_transpri_Connection> & items) const;

    /// Get the src dw_userdata_Connection connection.
    size_t src_dw_userdata_Connection (std::vector <dw_userdata_Connection> & items) const;

    /// Get the src dw_topic_Connection connection.
    size_t src_dw_topic_Connection (std::vector <dw_topic_Connection> & items) const;

    /// Get the src dw_reliability_Connection connection.
    size_t src_dw_reliability_Connection (std::vector <dw_reliability_Connection> & items) const;

    /// Get the src dw_history_Connection connection.
    size_t src_dw_history_Connection (std::vector <dw_history_Connection> & items) const;

    /// Get the src dw_dstOrder_Connection connection.
    size_t src_dw_dstOrder_Connection (std::vector <dw_dstOrder_Connection> & items) const;

    /// Get the src dw_writerdatalifecycle_Connection connection.
    size_t src_dw_writerdatalifecycle_Connection (std::vector <dw_writerdatalifecycle_Connection> & items) const;

    /// Get the src dw_liveliness_Connection connection.
    size_t src_dw_liveliness_Connection (std::vector <dw_liveliness_Connection> & items) const;

    /// Get the src dw_lifespan_Connection connection.
    size_t src_dw_lifespan_Connection (std::vector <dw_lifespan_Connection> & items) const;

    /// Get the src dw_deadline_Connection connection.
    size_t src_dw_deadline_Connection (std::vector <dw_deadline_Connection> & items) const;

    /// Get the src dw_durqos_Connection connection.
    size_t src_dw_durqos_Connection (std::vector <dw_durqos_Connection> & items) const;

    /// Get the src dw_latency_Connection connection.
    size_t src_dw_latency_Connection (std::vector <dw_latency_Connection> & items) const;

    /// Get the src dw_ownerstrength_Connection connection.
    size_t src_dw_ownerstrength_Connection (std::vector <dw_ownerstrength_Connection> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dw_pub_Connection connection.
    size_t dst_dw_pub_Connection (std::vector <dw_pub_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DataWriter.inl"
#endif

#endif  // !defined _DQML_STANDARD_DDSENTITIES_DATAWRITER
