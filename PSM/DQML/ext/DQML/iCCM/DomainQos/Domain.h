// -*- C++ -*-

//============================================================================
/**
 * @file    Domain.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DOMAINQOS_DOMAIN_H_
#define _DQML_ICCM_DOMAINQOS_DOMAIN_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class Domain_Impl;
  typedef Domain_Impl * Domain_in;
  typedef ::GAME::Mga::Smart_Ptr < Domain_Impl > Domain;

  // Forward decl.
  class Visitor;

  /**
   * @class Domain_Impl
   *
   * Implementation for the Domain model element.
   */
  class DQML_Export Domain_Impl :
    public virtual ::GAME::Mga::Model_Impl
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
    static Domain _create (const DomainQosFolder_in parent);
    ///@}

    // Default constructor.
    Domain_Impl (void);

    // Initializing constructor.
    Domain_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Domain_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DomainQosFolder parent_DomainQosFolder (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Participants (std::vector <Participant> & items) const;
    ::GAME::Mga::Collection_T <Participant> get_Participants (void) const;

    size_t get_PublishesConnections (std::vector <PublishesConnection> & items) const;
    ::GAME::Mga::Collection_T <PublishesConnection> get_PublishesConnections (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Domain.inl"
#endif

#endif  // !defined _DQML_ICCM_DOMAINQOS_DOMAIN
