// -*- C++ -*-

//============================================================================
/**
 * @file    SubscriptionKeyQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_SUBSCRIPTIONKEYQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_SUBSCRIPTIONKEYQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class SubscriptionKeyQosPolicy_Impl;
  typedef SubscriptionKeyQosPolicy_Impl * SubscriptionKeyQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < SubscriptionKeyQosPolicy_Impl > SubscriptionKeyQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class SubscriptionKeyQosPolicy_Impl
   *
   * Implementation for the SubscriptionKeyQosPolicy model element.
   */
  class DQML_Export SubscriptionKeyQosPolicy_Impl :
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


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static SubscriptionKeyQosPolicy _create (const DataReaderQos_in parent);
    static SubscriptionKeyQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    SubscriptionKeyQosPolicy_Impl (void);

    // Initializing constructor.
    SubscriptionKeyQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~SubscriptionKeyQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DataReaderQos parent_DataReaderQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of key_list
    void key_list (const std::string & val);

    /// Get the value of key_list
    std::string key_list (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SubscriptionKeyQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_SUBSCRIPTIONKEYQOSPOLICY
