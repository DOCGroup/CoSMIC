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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TimeProbe_Impl;
  typedef TimeProbe_Impl * TimeProbe_in;
  typedef ::GAME::Mga::Smart_Ptr < TimeProbe_Impl > TimeProbe;

  // Forward decl.
  class Visitor;

  /**
   * @class TimeProbe_Impl
   *
   * Implementation for the TimeProbe model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static TimeProbe _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    TimeProbe_Impl (void);

    // Initializing constructor.
    TimeProbe_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TimeProbe_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst TimerConnection connection.
    size_t dst_TimerConnection (std::vector <TimerConnection> & items) const;

    /// Get the dst TimerEventSinkConn connection.
    size_t dst_TimerEventSinkConn (std::vector <TimerEventSinkConn> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TimeProbe.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_TIMEPROBE
