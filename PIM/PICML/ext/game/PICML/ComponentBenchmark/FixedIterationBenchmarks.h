// -*- C++ -*-

//============================================================================
/**
 * @file    FixedIterationBenchmarks.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_FIXEDITERATIONBENCHMARKS_H_
#define _PICML_COMPONENTBENCHMARK_FIXEDITERATIONBENCHMARKS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FixedIterationBenchmarks_Impl;
  typedef FixedIterationBenchmarks_Impl * FixedIterationBenchmarks_in;
  typedef ::GAME::Mga::Smart_Ptr < FixedIterationBenchmarks_Impl > FixedIterationBenchmarks;

  // Forward decl.
  class Visitor;

  /**
   * @class FixedIterationBenchmarks_Impl
   *
   * Implementation for the FixedIterationBenchmarks model element.
   */
  class PICML_Export FixedIterationBenchmarks_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static FixedIterationBenchmarks _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    FixedIterationBenchmarks_Impl (void);

    // Initializing constructor.
    FixedIterationBenchmarks_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~FixedIterationBenchmarks_Impl (void);

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

    /// Set the value of benchmarkIterations
    void benchmarkIterations (long val);

    /// Get the value of benchmarkIterations
    long benchmarkIterations (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "FixedIterationBenchmarks.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_FIXEDITERATIONBENCHMARKS
