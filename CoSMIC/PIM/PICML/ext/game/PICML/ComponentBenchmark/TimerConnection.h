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

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TimerConnection_Impl;
  typedef TimerConnection_Impl * TimerConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <TimerConnection_Impl> TimerConnection;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    TimerConnection_Impl (void);

    /// Initializing constructor
    TimerConnection_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~TimerConnection_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static TimerConnection _create (const BenchmarkAnalysis_in parent);
    ///@}

    /// Get the src OperationRef connection point.
    OperationRef src_OperationRef (void);

    /// Get the dst TimeProbe connection point.
    TimeProbe dst_TimeProbe (void);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
