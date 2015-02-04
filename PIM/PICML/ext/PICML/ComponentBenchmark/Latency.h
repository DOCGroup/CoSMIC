// -*- C++ -*-

//============================================================================
/**
 * @file    Latency.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_LATENCY_H_
#define _PICML_COMPONENTBENCHMARK_LATENCY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Latency_Impl;
  typedef Latency_Impl * Latency_in;
  typedef ::GAME::Mga::Smart_Ptr < Latency_Impl > Latency;

  // Forward decl.
  class Visitor;

  /**
   * @class Latency_Impl
   *
   * Implementation for the Latency model element.
   */
  class PICML_Export Latency_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual MetricsBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Latency _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    Latency_Impl (void);

    // Initializing constructor.
    Latency_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Latency_Impl (void);

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
#include "Latency.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_LATENCY
