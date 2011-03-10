// -*- C++ -*-

//============================================================================
/**
 * @file    TimeProbe.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_TIMEPROBE_H_
#define _PICML_COMPONENTBENCHMARK_TIMEPROBE_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TimeProbe_Impl;
  typedef TimeProbe_Impl * TimeProbe_in;
  typedef ::GAME::Mga::Smart_Ptr <TimeProbe_Impl> TimeProbe;

  // Forward decl.
  class Visitor;

  class PICML_Export TimeProbe_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    TimeProbe_Impl (void);

    /// Initializing constructor
    TimeProbe_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~TimeProbe_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static TimeProbe _create (const BenchmarkAnalysis_in parent);
    ///@}
    size_t in_TimerEventSinkConn_connections (std::vector <TimerEventSinkConn> & conns) const;
    size_t in_TimerConnection_connections (std::vector <TimerConnection> & conns) const;

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
