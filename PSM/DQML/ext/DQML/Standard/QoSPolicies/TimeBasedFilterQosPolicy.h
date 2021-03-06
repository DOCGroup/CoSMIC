// -*- C++ -*-

//============================================================================
/**
 * @file    TimeBasedFilterQosPolicy.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_TIMEBASEDFILTERQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_TIMEBASEDFILTERQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class TimeBasedFilterQosPolicy_Impl;
  typedef TimeBasedFilterQosPolicy_Impl * TimeBasedFilterQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < TimeBasedFilterQosPolicy_Impl > TimeBasedFilterQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class TimeBasedFilterQosPolicy_Impl
   *
   * Implementation for the TimeBasedFilterQosPolicy model element.
   */
  class DQML_Export TimeBasedFilterQosPolicy_Impl :
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
    static TimeBasedFilterQosPolicy _create (const DataReaderQos_in parent);
    static TimeBasedFilterQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    TimeBasedFilterQosPolicy_Impl (void);

    // Initializing constructor.
    TimeBasedFilterQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TimeBasedFilterQosPolicy_Impl (void);

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

    /// Set the value of minimum_separation
    void minimum_separation (double val);

    /// Get the value of minimum_separation
    double minimum_separation (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst dr_timebased_Connection connection.
    size_t dst_of_dr_timebased_Connection (std::vector <dr_timebased_Connection> & items) const;
    GAME::Mga::Collection_T <dr_timebased_Connection> dst_of_dr_timebased_Connection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TimeBasedFilterQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_TIMEBASEDFILTERQOSPOLICY
