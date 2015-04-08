// -*- C++ -*-

//============================================================================
/**
 * @file    DomainParticipantFactory.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DDSENTITIES_DOMAINPARTICIPANTFACTORY_H_
#define _DQML_STANDARD_DDSENTITIES_DOMAINPARTICIPANTFACTORY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/DDSEntities/DomainEntity.h"
#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DomainParticipantFactory_Impl;
  typedef DomainParticipantFactory_Impl * DomainParticipantFactory_in;
  typedef ::GAME::Mga::Smart_Ptr < DomainParticipantFactory_Impl > DomainParticipantFactory;

  // Forward decl.
  class Visitor;

  /**
   * @class DomainParticipantFactory_Impl
   *
   * Implementation for the DomainParticipantFactory model element.
   */
  class DQML_Export DomainParticipantFactory_Impl :
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
    static DomainParticipantFactory _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    DomainParticipantFactory_Impl (void);

    // Initializing constructor.
    DomainParticipantFactory_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DomainParticipantFactory_Impl (void);

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

    /// Get the src dpf_dp_Connection connection.
    size_t src_of_dpf_dp_Connection (std::vector <dpf_dp_Connection> & items) const;
    GAME::Mga::Collection_T <dpf_dp_Connection> src_of_dpf_dp_Connection (void) const;

    /// Get the src dpfactory_entityfactory_Connection connection.
    size_t src_of_dpfactory_entityfactory_Connection (std::vector <dpfactory_entityfactory_Connection> & items) const;
    bool has_src_of_dpfactory_entityfactory_Connection (void) const;
    dpfactory_entityfactory_Connection src_of_dpfactory_entityfactory_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DomainParticipantFactory.inl"
#endif

#endif  // !defined _DQML_STANDARD_DDSENTITIES_DOMAINPARTICIPANTFACTORY
