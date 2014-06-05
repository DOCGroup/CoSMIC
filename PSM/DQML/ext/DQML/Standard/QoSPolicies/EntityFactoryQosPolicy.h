// -*- C++ -*-

//============================================================================
/**
 * @file    EntityFactoryQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_ENTITYFACTORYQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_ENTITYFACTORYQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class EntityFactoryQosPolicy_Impl;
  typedef EntityFactoryQosPolicy_Impl * EntityFactoryQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < EntityFactoryQosPolicy_Impl > EntityFactoryQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class EntityFactoryQosPolicy_Impl
   *
   * Implementation for the EntityFactoryQosPolicy model element.
   */
  class DQML_Export EntityFactoryQosPolicy_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual QoSPolicy_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static EntityFactoryQosPolicy _create (const SubscriberQos_in parent);
    static EntityFactoryQosPolicy _create (const PublisherQos_in parent);
    static EntityFactoryQosPolicy _create (const Participant_in parent);
    static EntityFactoryQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    EntityFactoryQosPolicy_Impl (void);

    // Initializing constructor.
    EntityFactoryQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~EntityFactoryQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    SubscriberQos parent_SubscriberQos (void);
    PublisherQos parent_PublisherQos (void);
    Participant parent_Participant (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of autoenable_created_entities
    void autoenable_created_entities (bool val);

    /// Get the value of autoenable_created_entities
    bool autoenable_created_entities (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dpfactory_entityfactory_Connection connection.
    size_t dst_dpfactory_entityfactory_Connection (std::vector <dpfactory_entityfactory_Connection> & items) const;

    /// Get the dst pub_entityfactory_Connection connection.
    size_t dst_pub_entityfactory_Connection (std::vector <pub_entityfactory_Connection> & items) const;

    /// Get the dst sub_entityfactory_Connection connection.
    size_t dst_sub_entityfactory_Connection (std::vector <sub_entityfactory_Connection> & items) const;

    /// Get the dst dp_entityfactory_Connection connection.
    size_t dst_dp_entityfactory_Connection (std::vector <dp_entityfactory_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "EntityFactoryQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_ENTITYFACTORYQOSPOLICY
