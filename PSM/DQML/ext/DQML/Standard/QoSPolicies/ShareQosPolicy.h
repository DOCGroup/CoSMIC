// -*- C++ -*-

//============================================================================
/**
 * @file    ShareQosPolicy.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_SHAREQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_SHAREQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class ShareQosPolicy_Impl;
  typedef ShareQosPolicy_Impl * ShareQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < ShareQosPolicy_Impl > ShareQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class ShareQosPolicy_Impl
   *
   * Implementation for the ShareQosPolicy model element.
   */
  class DQML_Export ShareQosPolicy_Impl :
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
    static ShareQosPolicy _create (const SubscriberQos_in parent);
    static ShareQosPolicy _create (const DataReaderQos_in parent);
    static ShareQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    ShareQosPolicy_Impl (void);

    // Initializing constructor.
    ShareQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ShareQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    SubscriberQos parent_SubscriberQos (void);
    DataReaderQos parent_DataReaderQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of share_qos_enable
    void share_qos_enable (bool val);

    /// Get the value of share_qos_enable
    bool share_qos_enable (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ShareQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_SHAREQOSPOLICY
