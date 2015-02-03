// -*- C++ -*-

//============================================================================
/**
 * @file    TriggerBenchmarks.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_TRIGGERBENCHMARKS_H_
#define _PICML_COMPONENTBENCHMARK_TRIGGERBENCHMARKS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBenchmark/BenchmarkType.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TriggerBenchmarks_Impl;
  typedef TriggerBenchmarks_Impl * TriggerBenchmarks_in;
  typedef ::GAME::Mga::Smart_Ptr < TriggerBenchmarks_Impl > TriggerBenchmarks;

  // Forward decl.
  class Visitor;

  /**
   * @class TriggerBenchmarks_Impl
   *
   * Implementation for the TriggerBenchmarks model element.
   */
  class PICML_Export TriggerBenchmarks_Impl :
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
    static TriggerBenchmarks _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    TriggerBenchmarks_Impl (void);

    // Initializing constructor.
    TriggerBenchmarks_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TriggerBenchmarks_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TriggerBenchmarks.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_TRIGGERBENCHMARKS
