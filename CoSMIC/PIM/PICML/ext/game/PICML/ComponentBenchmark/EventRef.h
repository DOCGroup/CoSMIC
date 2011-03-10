// -*- C++ -*-

//============================================================================
/**
 * @file    EventRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_EVENTREF_H_
#define _PICML_COMPONENTBENCHMARK_EVENTREF_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EventRef_Impl;
  typedef EventRef_Impl * EventRef_in;
  typedef ::GAME::Mga::Smart_Ptr <EventRef_Impl> EventRef;

  // Forward decl.
  class Visitor;

  class PICML_Export EventRef_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    EventRef_Impl (void);

    /// Initializing constructor
    EventRef_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~EventRef_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static EventRef _create (const BenchmarkAnalysis_in parent);
    ///@}
    size_t in_TimerEventSinkConn_connections (std::vector <TimerEventSinkConn> & conns) const;

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
