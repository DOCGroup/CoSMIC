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

#include "game/mga/Atom.h"
#include "PICML/ComponentBenchmark/BenchmarkType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PeriodicBenchmarks_Impl;
  typedef PeriodicBenchmarks_Impl * PeriodicBenchmarks_in;
  typedef ::GAME::Mga::Smart_Ptr <PeriodicBenchmarks_Impl> PeriodicBenchmarks;

  // Forward decl.
  class Visitor;

  class PICML_Export PeriodicBenchmarks_Impl :
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
    PeriodicBenchmarks_Impl (void);

    /// Initializing constructor
    PeriodicBenchmarks_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~PeriodicBenchmarks_Impl (void);

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

    /// Set the value of timeperiod
    void timeperiod (long val);

    /// Get the value of timeperiod
    long timeperiod (void) const;
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
