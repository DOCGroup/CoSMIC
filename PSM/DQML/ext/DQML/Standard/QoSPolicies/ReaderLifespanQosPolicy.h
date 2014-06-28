// -*- C++ -*-

//============================================================================
/**
 * @file    ReaderLifespanQosPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_READERLIFESPANQOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_READERLIFESPANQOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/Standard/QoSPolicies/QoSPolicy.h"
#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class ReaderLifespanQosPolicy_Impl;
  typedef ReaderLifespanQosPolicy_Impl * ReaderLifespanQosPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < ReaderLifespanQosPolicy_Impl > ReaderLifespanQosPolicy;

  // Forward decl.
  class Visitor;

  /**
   * @class ReaderLifespanQosPolicy_Impl
   *
   * Implementation for the ReaderLifespanQosPolicy model element.
   */
  class DQML_Export ReaderLifespanQosPolicy_Impl :
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
    static ReaderLifespanQosPolicy _create (const DataReaderQos_in parent);
    static ReaderLifespanQosPolicy _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    ReaderLifespanQosPolicy_Impl (void);

    // Initializing constructor.
    ReaderLifespanQosPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ReaderLifespanQosPolicy_Impl (void);

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

    /// Set the value of duration
    void duration (double val);

    /// Get the value of duration
    double duration (void) const;

    /// Set the value of use_lifespan
    void use_lifespan (bool val);

    /// Get the value of use_lifespan
    bool use_lifespan (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ReaderLifespanQosPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_READERLIFESPANQOSPOLICY
