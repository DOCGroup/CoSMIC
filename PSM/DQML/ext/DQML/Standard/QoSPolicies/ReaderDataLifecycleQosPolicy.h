// -*- C++ -*-

//============================================================================
/**
 * @file    ReaderDataLifecycleQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_READERDATALIFECYCLEQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_READERDATALIFECYCLEQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class ReaderDataLifecycleQosPolicy_Impl;
  typedef ReaderDataLifecycleQosPolicy_Impl * ReaderDataLifecycleQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < ReaderDataLifecycleQosPolicy_Impl > ReaderDataLifecycleQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class ReaderDataLifecycleQosPolicy_Impl
   *
   * Implementation for the ReaderDataLifecycleQosPolicy model element.
   */
  class DQML_Export ReaderDataLifecycleQosPolicy_Impl :
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
    static ReaderDataLifecycleQosPolicy _create (const DataReaderQos_in parent);
    static ReaderDataLifecycleQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    ReaderDataLifecycleQosPolicy_Impl (void);

    // Initializing constructor.
    ReaderDataLifecycleQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ReaderDataLifecycleQosPolicy_Impl (void);

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

    /// Set the value of autopurge_nowriter_samples_delay
    void autopurge_nowriter_samples_delay (double val);

    /// Get the value of autopurge_nowriter_samples_delay
    double autopurge_nowriter_samples_delay (void) const;

    /// Set the value of autopurge_disposed_samples_delay
    void autopurge_disposed_samples_delay (double val);

    /// Get the value of autopurge_disposed_samples_delay
    double autopurge_disposed_samples_delay (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dr_readerdatalifecycle_Connection connection.
    size_t dst_dr_readerdatalifecycle_Connection (std::vector <dr_readerdatalifecycle_Connection> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ReaderDataLifecycleQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_READERDATALIFECYCLEQOSPOLICY
