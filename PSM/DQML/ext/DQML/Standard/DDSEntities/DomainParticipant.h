// -*- C++ -*-

//============================================================================
/**
 * @file    DomainParticipant.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DDSENTITIES_DOMAINPARTICIPANT_H_
#define _DQML_STANDARD_DDSENTITIES_DOMAINPARTICIPANT_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DomainParticipant_Impl;
  typedef DomainParticipant_Impl * DomainParticipant_in;
  typedef ::GAME::Mga::Smart_Ptr < DomainParticipant_Impl > DomainParticipant;

  // Forward decl.
  class Visitor;

  /**
   * @class DomainParticipant_Impl
   *
   * Implementation for the DomainParticipant model element.
   */
  class DQML_Export DomainParticipant_Impl :
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
    static DomainParticipant _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    DomainParticipant_Impl (void);

    // Initializing constructor.
    DomainParticipant_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DomainParticipant_Impl (void);

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

    /// Get the src dp_userdata_Connection connection.
    size_t src_dp_userdata_Connection (std::vector <dp_userdata_Connection> & items) const;

    /// Get the src dp_topic_Connection connection.
    size_t src_dp_topic_Connection (std::vector <dp_topic_Connection> & items) const;

    /// Get the src dp_sub_Connection connection.
    size_t src_dp_sub_Connection (std::vector <dp_sub_Connection> & items) const;

    /// Get the src dp_pub_Connection connection.
    size_t src_dp_pub_Connection (std::vector <dp_pub_Connection> & items) const;

    /// Get the src dp_entityfactory_Connection connection.
    size_t src_dp_entityfactory_Connection (std::vector <dp_entityfactory_Connection> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dpf_dp_Connection connection.
    size_t dst_dpf_dp_Connection (std::vector <dpf_dp_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DomainParticipant.inl"
#endif

#endif  // !defined _DQML_STANDARD_DDSENTITIES_DOMAINPARTICIPANT
