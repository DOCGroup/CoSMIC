// -*- C++ -*-

//============================================================================
/**
 * @file    dp_entityfactory_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_ENTITYFACTORYQOSPOLICY_DP_ENTITYFACTORY_CONNECTION_H_
#define _DQML_STANDARD_ENTITYFACTORYQOSPOLICY_DP_ENTITYFACTORY_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dp_entityfactory_Connection_Impl;
  typedef dp_entityfactory_Connection_Impl * dp_entityfactory_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dp_entityfactory_Connection_Impl > dp_entityfactory_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dp_entityfactory_Connection_Impl
   *
   * Implementation for the dp_entityfactory_Connection model element.
   */
  class DQML_Export dp_entityfactory_Connection_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static dp_entityfactory_Connection _create (const DDSQoS_in parent, DomainParticipant_in src, EntityFactoryQosPolicy_in dst);
    ///@}

    // Default constructor.
    dp_entityfactory_Connection_Impl (void);

    // Initializing constructor.
    dp_entityfactory_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dp_entityfactory_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    DomainParticipant src_DomainParticipant (void) const;
    EntityFactoryQosPolicy dst_EntityFactoryQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dp_entityfactory_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_ENTITYFACTORYQOSPOLICY_DP_ENTITYFACTORY_CONNECTION
