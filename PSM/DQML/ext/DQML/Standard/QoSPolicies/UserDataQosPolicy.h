// -*- C++ -*-

//============================================================================
/**
 * @file    UserDataQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_USERDATAQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_USERDATAQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class UserDataQosPolicy_Impl;
  typedef UserDataQosPolicy_Impl * UserDataQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < UserDataQosPolicy_Impl > UserDataQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class UserDataQosPolicy_Impl
   *
   * Implementation for the UserDataQosPolicy model element.
   */
  class DQML_Export UserDataQosPolicy_Impl :
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
    static UserDataQosPolicy _create (const DataWriterQos_in parent);
    static UserDataQosPolicy _create (const DataReaderQos_in parent);
    static UserDataQosPolicy _create (const Participant_in parent);
    static UserDataQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    UserDataQosPolicy_Impl (void);

    // Initializing constructor.
    UserDataQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~UserDataQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of user_value
    void user_value (const std::string & val);

    /// Get the value of user_value
    std::string user_value (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dp_userdata_Connection connection.
    size_t dst_dp_userdata_Connection (std::vector <dp_userdata_Connection> & items) const;

    /// Get the dst dr_userdata_Connection connection.
    size_t dst_dr_userdata_Connection (std::vector <dr_userdata_Connection> & items) const;

    /// Get the dst dw_userdata_Connection connection.
    size_t dst_dw_userdata_Connection (std::vector <dw_userdata_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "UserDataQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_USERDATAQOSPOLICY
