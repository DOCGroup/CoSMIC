// -*- C++ -*-

//============================================================================
/**
 * @file    Throughput.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_THROUGHPUT_H_
#define _PICML_COMPONENTBENCHMARK_THROUGHPUT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBenchmark/MetricsBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Throughput_Impl;
  typedef Throughput_Impl * Throughput_in;
  typedef ::GAME::Mga::Smart_Ptr < Throughput_Impl > Throughput;

  // Forward decl.
  class Visitor;

  /**
   * @class Throughput_Impl
   *
   * Implementation for the Throughput model element.
   */
  class PICML_Export Throughput_Impl :
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
    static Throughput _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    Throughput_Impl (void);

    // Initializing constructor.
    Throughput_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Throughput_Impl (void);

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
#include "Throughput.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_THROUGHPUT
