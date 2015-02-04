// -*- C++ -*-

//============================================================================
/**
 * @file    WriterDataLifecycleQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_WRITERDATALIFECYCLEQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_WRITERDATALIFECYCLEQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class WriterDataLifecycleQosPolicy_Impl;
  typedef WriterDataLifecycleQosPolicy_Impl * WriterDataLifecycleQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < WriterDataLifecycleQosPolicy_Impl > WriterDataLifecycleQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class WriterDataLifecycleQosPolicy_Impl
   *
   * Implementation for the WriterDataLifecycleQosPolicy model element.
   */
  class DQML_Export WriterDataLifecycleQosPolicy_Impl :
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
    static WriterDataLifecycleQosPolicy _create (const DataWriterQos_in parent);
    static WriterDataLifecycleQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    WriterDataLifecycleQosPolicy_Impl (void);

    // Initializing constructor.
    WriterDataLifecycleQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~WriterDataLifecycleQosPolicy_Impl (void);

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

    /// Set the value of autodispose_unregistered_instances
    void autodispose_unregistered_instances (bool val);

    /// Get the value of autodispose_unregistered_instances
    bool autodispose_unregistered_instances (void) const;

    /// Set the value of autopurge_suspended_samples_delay
    void autopurge_suspended_samples_delay (double val);

    /// Get the value of autopurge_suspended_samples_delay
    double autopurge_suspended_samples_delay (void) const;

    /// Set the value of autounregister_instance_delay
    void autounregister_instance_delay (double val);

    /// Get the value of autounregister_instance_delay
    double autounregister_instance_delay (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dw_writerdatalifecycle_Connection connection.
    size_t dst_of_dw_writerdatalifecycle_Connection (std::vector <dw_writerdatalifecycle_Connection> & items) const;
    GAME::Mga::Collection_T <dw_writerdatalifecycle_Connection> dst_of_dw_writerdatalifecycle_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "WriterDataLifecycleQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_WRITERDATALIFECYCLEQOSPOLICY
