// -*- C++ -*-

//============================================================================
/**
 * @file    OwnershipStrengthQosPolicy.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_OWNERSHIPSTRENGTHQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_OWNERSHIPSTRENGTHQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class OwnershipStrengthQosPolicy_Impl;
  typedef OwnershipStrengthQosPolicy_Impl * OwnershipStrengthQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < OwnershipStrengthQosPolicy_Impl > OwnershipStrengthQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class OwnershipStrengthQosPolicy_Impl
   *
   * Implementation for the OwnershipStrengthQosPolicy model element.
   */
  class DQML_Export OwnershipStrengthQosPolicy_Impl :
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
    static OwnershipStrengthQosPolicy _create (const DataWriterQos_in parent);
    static OwnershipStrengthQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    OwnershipStrengthQosPolicy_Impl (void);

    // Initializing constructor.
    OwnershipStrengthQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~OwnershipStrengthQosPolicy_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DataWriterQos parent_DataWriterQos (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of ownership_value
    void ownership_value (long val);

    /// Get the value of ownership_value
    long ownership_value (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dw_ownerstrength_Connection connection.
    size_t dst_of_dw_ownerstrength_Connection (std::vector <dw_ownerstrength_Connection> & items) const;
    GAME::Mga::Collection_T <dw_ownerstrength_Connection> dst_of_dw_ownerstrength_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OwnershipStrengthQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_OWNERSHIPSTRENGTHQOSPOLICY
