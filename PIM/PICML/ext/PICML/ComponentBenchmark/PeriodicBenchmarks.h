// -*- C++ -*-

//============================================================================
/**
 * @file    PeriodicBenchmarks.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_PERIODICBENCHMARKS_H_
#define _PICML_COMPONENTBENCHMARK_PERIODICBENCHMARKS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PeriodicBenchmarks_Impl;
  typedef PeriodicBenchmarks_Impl * PeriodicBenchmarks_in;
  typedef ::GAME::Mga::Smart_Ptr < PeriodicBenchmarks_Impl > PeriodicBenchmarks;

  // Forward decl.
  class Visitor;

  /**
   * @class PeriodicBenchmarks_Impl
   *
   * Implementation for the PeriodicBenchmarks model element.
   */
  class PICML_Export PeriodicBenchmarks_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual BenchmarkType_Impl
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
    static PeriodicBenchmarks _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    PeriodicBenchmarks_Impl (void);

    // Initializing constructor.
    PeriodicBenchmarks_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~PeriodicBenchmarks_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of timeperiod
    void timeperiod (long val);

    /// Get the value of timeperiod
    long timeperiod (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PeriodicBenchmarks.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_PERIODICBENCHMARKS
