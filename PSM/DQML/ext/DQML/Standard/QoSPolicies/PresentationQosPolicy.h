// -*- C++ -*-

//============================================================================
/**
 * @file    PresentationQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_PRESENTATIONQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_PRESENTATIONQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class PresentationQosPolicy_Impl;
  typedef PresentationQosPolicy_Impl * PresentationQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < PresentationQosPolicy_Impl > PresentationQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class PresentationQosPolicy_Impl
   *
   * Implementation for the PresentationQosPolicy model element.
   */
  class DQML_Export PresentationQosPolicy_Impl :
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
    static PresentationQosPolicy _create (const PublisherQos_in parent);
    static PresentationQosPolicy _create (const SubscriberQos_in parent);
    static PresentationQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    PresentationQosPolicy_Impl (void);

    // Initializing constructor.
    PresentationQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~PresentationQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PublisherQos parent_PublisherQos (void);
    SubscriberQos parent_SubscriberQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of access_scope
    void access_scope (const std::string & val);

    /// Get the value of access_scope
    std::string access_scope (void) const;

    /// Set the value of coherent_access
    void coherent_access (bool val);

    /// Get the value of coherent_access
    bool coherent_access (void) const;

    /// Set the value of ordered_access
    void ordered_access (bool val);

    /// Get the value of ordered_access
    bool ordered_access (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst pub_presqos_Connection connection.
    size_t dst_of_pub_presqos_Connection (std::vector <pub_presqos_Connection> & items) const;
    GAME::Mga::Collection_T <pub_presqos_Connection> dst_of_pub_presqos_Connection (void) const;

    /// Get the dst sub_presqos_Connection connection.
    size_t dst_of_sub_presqos_Connection (std::vector <sub_presqos_Connection> & items) const;
    GAME::Mga::Collection_T <sub_presqos_Connection> dst_of_sub_presqos_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PresentationQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_PRESENTATIONQOSPOLICY
