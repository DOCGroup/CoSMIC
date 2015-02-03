// -*- C++ -*-

//============================================================================
/**
 * @file    dpf_dp_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_MAIN_DPF_DP_CONNECTION_H_
#define _DQML_STANDARD_MAIN_DPF_DP_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dpf_dp_Connection_Impl;
  typedef dpf_dp_Connection_Impl * dpf_dp_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dpf_dp_Connection_Impl > dpf_dp_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dpf_dp_Connection_Impl
   *
   * Implementation for the dpf_dp_Connection model element.
   */
  class DQML_Export dpf_dp_Connection_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static dpf_dp_Connection _create (const DDSQoS_in parent, DomainParticipantFactory_in src, DomainParticipant_in dst);
    ///@}

    // Default constructor.
    dpf_dp_Connection_Impl (void);

    // Initializing constructor.
    dpf_dp_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dpf_dp_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    DomainParticipantFactory src_DomainParticipantFactory (void) const;
    DomainParticipant dst_DomainParticipant (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dpf_dp_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_MAIN_DPF_DP_CONNECTION
