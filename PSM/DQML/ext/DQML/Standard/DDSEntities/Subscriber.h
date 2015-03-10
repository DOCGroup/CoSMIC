// -*- C++ -*-

//============================================================================
/**
 * @file    Subscriber.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DDSENTITIES_SUBSCRIBER_H_
#define _DQML_STANDARD_DDSENTITIES_SUBSCRIBER_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class Subscriber_Impl;
  typedef Subscriber_Impl * Subscriber_in;
  typedef ::GAME::Mga::Smart_Ptr < Subscriber_Impl > Subscriber;

  // Forward decl.
  class Visitor;

  /**
   * @class Subscriber_Impl
   *
   * Implementation for the Subscriber model element.
   */
  class DQML_Export Subscriber_Impl :
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
    static Subscriber _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    Subscriber_Impl (void);

    // Initializing constructor.
    Subscriber_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Subscriber_Impl (void);

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

    /// Get the src sub_presqos_Connection connection.
    size_t src_of_sub_presqos_Connection (std::vector <sub_presqos_Connection> & items) const;
    bool has_src_of_sub_presqos_Connection (void) const;
    sub_presqos_Connection src_of_sub_presqos_Connection (void) const;

    /// Get the src dr_sub_Connection connection.
    size_t src_of_dr_sub_Connection (std::vector <dr_sub_Connection> & items) const;
    GAME::Mga::Collection_T <dr_sub_Connection> src_of_dr_sub_Connection (void) const;

    /// Get the src sub_groupdata_Connection connection.
    size_t src_of_sub_groupdata_Connection (std::vector <sub_groupdata_Connection> & items) const;
    bool has_src_of_sub_groupdata_Connection (void) const;
    sub_groupdata_Connection src_of_sub_groupdata_Connection (void) const;

    /// Get the src sub_entityfactory_Connection connection.
    size_t src_of_sub_entityfactory_Connection (std::vector <sub_entityfactory_Connection> & items) const;
    bool has_src_of_sub_entityfactory_Connection (void) const;
    sub_entityfactory_Connection src_of_sub_entityfactory_Connection (void) const;

    /// Get the src sub_part_Connection connection.
    size_t src_of_sub_part_Connection (std::vector <sub_part_Connection> & items) const;
    bool has_src_of_sub_part_Connection (void) const;
    sub_part_Connection src_of_sub_part_Connection (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dp_sub_Connection connection.
    size_t dst_of_dp_sub_Connection (std::vector <dp_sub_Connection> & items) const;
    dp_sub_Connection dst_of_dp_sub_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Subscriber.inl"
#endif

#endif  // !defined _DQML_STANDARD_DDSENTITIES_SUBSCRIBER
