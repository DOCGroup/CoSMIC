// -*- C++ -*-

//============================================================================
/**
 * @file    Maximum.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_MAXIMUM_H_
#define _PICML_COMPONENTBENCHMARK_MAXIMUM_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBenchmark/DataAnalysisBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Maximum_Impl;
  typedef Maximum_Impl * Maximum_in;
  typedef ::GAME::Mga::Smart_Ptr < Maximum_Impl > Maximum;

  // Forward decl.
  class Visitor;

  /**
   * @class Maximum_Impl
   *
   * Implementation for the Maximum model element.
   */
  class PICML_Export Maximum_Impl :
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
    static Maximum _create (const MetricsBase_in parent);
    static Maximum _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    Maximum_Impl (void);

    // Initializing constructor.
    Maximum_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Maximum_Impl (void);

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
#include "Maximum.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_MAXIMUM
