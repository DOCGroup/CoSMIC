// -*- C++ -*-

//============================================================================
/**
 * @file    TimerEventSinkConn.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_TIMEREVENTSINKCONN_H_
#define _PICML_COMPONENTBENCHMARK_TIMEREVENTSINKCONN_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TimerEventSinkConn_Impl;
  typedef TimerEventSinkConn_Impl * TimerEventSinkConn_in;
  typedef ::GAME::Mga::Smart_Ptr < TimerEventSinkConn_Impl > TimerEventSinkConn;

  // Forward decl.
  class Visitor;

  /**
   * @class TimerEventSinkConn_Impl
   *
   * Implementation for the TimerEventSinkConn model element.
   */
  class PICML_Export TimerEventSinkConn_Impl :
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
    static TimerEventSinkConn _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    TimerEventSinkConn_Impl (void);

    // Initializing constructor.
    TimerEventSinkConn_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~TimerEventSinkConn_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    EventRef src_EventRef (void) const;
    TimeProbe dst_TimeProbe (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "TimerEventSinkConn.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_TIMEREVENTSINKCONN
