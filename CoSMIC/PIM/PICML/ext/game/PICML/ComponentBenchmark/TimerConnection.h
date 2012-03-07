// -*- C++ -*-

//============================================================================
/**
 * @file    TimerConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_TIMERCONNECTION_H_
#define _PICML_COMPONENTBENCHMARK_TIMERCONNECTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TimerConnection_Impl;
  typedef TimerConnection_Impl * TimerConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < TimerConnection_Impl > TimerConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class TimerConnection_Impl
   *
   * Implementation for the TimerConnection model element.
   */
  class PICML_Export TimerConnection_Impl :
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
    static TimerConnection _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    TimerConnection_Impl (void);

    // Initializing constructor.
    TimerConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~TimerConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    OperationRef src_OperationRef (void) const;
    TimeProbe dst_TimeProbe (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "TimerConnection.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_TIMERCONNECTION
