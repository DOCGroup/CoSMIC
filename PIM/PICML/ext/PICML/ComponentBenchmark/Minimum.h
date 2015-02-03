// -*- C++ -*-

//============================================================================
/**
 * @file    Minimum.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_MINIMUM_H_
#define _PICML_COMPONENTBENCHMARK_MINIMUM_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBenchmark/DataAnalysisBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Minimum_Impl;
  typedef Minimum_Impl * Minimum_in;
  typedef ::GAME::Mga::Smart_Ptr < Minimum_Impl > Minimum;

  // Forward decl.
  class Visitor;

  /**
   * @class Minimum_Impl
   *
   * Implementation for the Minimum model element.
   */
  class PICML_Export Minimum_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual DataAnalysisBase_Impl
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
    static Minimum _create (const MetricsBase_in parent);
    static Minimum _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    Minimum_Impl (void);

    // Initializing constructor.
    Minimum_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Minimum_Impl (void);

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
#include "Minimum.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_MINIMUM
