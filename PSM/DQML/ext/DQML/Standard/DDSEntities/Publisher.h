// -*- C++ -*-

//============================================================================
/**
 * @file    Publisher.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DDSENTITIES_PUBLISHER_H_
#define _DQML_STANDARD_DDSENTITIES_PUBLISHER_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class Publisher_Impl;
  typedef Publisher_Impl * Publisher_in;
  typedef ::GAME::Mga::Smart_Ptr < Publisher_Impl > Publisher;

  // Forward decl.
  class Visitor;

  /**
   * @class Publisher_Impl
   *
   * Implementation for the Publisher model element.
   */
  class DQML_Export Publisher_Impl :
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
    static Publisher _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    Publisher_Impl (void);

    // Initializing constructor.
    Publisher_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Publisher_Impl (void);

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

    /// Get the src pub_groupdata_Connection connection.
    size_t src_of_pub_groupdata_Connection (std::vector <pub_groupdata_Connection> & items) const;
    GAME::Mga::Collection_T <pub_groupdata_Connection> src_of_pub_groupdata_Connection (void) const;

    /// Get the src pub_entityfactory_Connection connection.
    size_t src_of_pub_entityfactory_Connection (std::vector <pub_entityfactory_Connection> & items) const;
    GAME::Mga::Collection_T <pub_entityfactory_Connection> src_of_pub_entityfactory_Connection (void) const;

    /// Get the src pub_part_Connection connection.
    size_t src_of_pub_part_Connection (std::vector <pub_part_Connection> & items) const;
    GAME::Mga::Collection_T <pub_part_Connection> src_of_pub_part_Connection (void) const;

    /// Get the src pub_presqos_Connection connection.
    size_t src_of_pub_presqos_Connection (std::vector <pub_presqos_Connection> & items) const;
    GAME::Mga::Collection_T <pub_presqos_Connection> src_of_pub_presqos_Connection (void) const;

    /// Get the src dw_pub_Connection connection.
    size_t src_of_dw_pub_Connection (std::vector <dw_pub_Connection> & items) const;
    GAME::Mga::Collection_T <dw_pub_Connection> src_of_dw_pub_Connection (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dp_pub_Connection connection.
    size_t dst_of_dp_pub_Connection (std::vector <dp_pub_Connection> & items) const;
    GAME::Mga::Collection_T <dp_pub_Connection> dst_of_dp_pub_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Publisher.inl"
#endif

#endif  // !defined _DQML_STANDARD_DDSENTITIES_PUBLISHER
