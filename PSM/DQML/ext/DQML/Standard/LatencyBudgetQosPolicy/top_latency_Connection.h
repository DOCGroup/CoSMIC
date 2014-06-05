// -*- C++ -*-

//============================================================================
/**
 * @file    top_latency_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_LATENCYBUDGETQOSPOLICY_TOP_LATENCY_CONNECTION_H_
#define _DQML_STANDARD_LATENCYBUDGETQOSPOLICY_TOP_LATENCY_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class top_latency_Connection_Impl;
  typedef top_latency_Connection_Impl * top_latency_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < top_latency_Connection_Impl > top_latency_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class top_latency_Connection_Impl
   *
   * Implementation for the top_latency_Connection model element.
   */
  class DQML_Export top_latency_Connection_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static top_latency_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    top_latency_Connection_Impl (void);

    // Initializing constructor.
    top_latency_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~top_latency_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    Topic src_Topic (void) const;
    LatencyBudgetQosPolicy dst_LatencyBudgetQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "top_latency_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_LATENCYBUDGETQOSPOLICY_TOP_LATENCY_CONNECTION
