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

#include "game/mga/Atom.h"
#include "PICML/ComponentBenchmark/BenchmarkType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class FixedIterationBenchmarks_Impl;
  typedef FixedIterationBenchmarks_Impl * FixedIterationBenchmarks_in;
  typedef ::GAME::Mga::Smart_Ptr <FixedIterationBenchmarks_Impl> FixedIterationBenchmarks;

  // Forward decl.
  class Visitor;

  class PICML_Export FixedIterationBenchmarks_Impl :
    public virtual BenchmarkType_Impl,
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
    FixedIterationBenchmarks_Impl (void);

    /// Initializing constructor
    FixedIterationBenchmarks_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~FixedIterationBenchmarks_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
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

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
