// -*- C++ -*-

//============================================================================
/**
 * @file    BenchmarkCharacteristics.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_BENCHMARKCHARACTERISTICS_H_
#define _PICML_COMPONENTBENCHMARK_BENCHMARKCHARACTERISTICS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BenchmarkCharacteristics_Impl;
  typedef BenchmarkCharacteristics_Impl * BenchmarkCharacteristics_in;
  typedef ::GAME::Mga::Smart_Ptr < BenchmarkCharacteristics_Impl > BenchmarkCharacteristics;

  // Forward decl.
  class Visitor;

  /**
   * @class BenchmarkCharacteristics_Impl
   *
   * Implementation for the BenchmarkCharacteristics model element.
   */
  class PICML_Export BenchmarkCharacteristics_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static BenchmarkCharacteristics _create (const BenchmarkAnalysis_in parent, BenchmarkType_in src, MetricsBase_in dst);
    ///@}

    // Default constructor.
    BenchmarkCharacteristics_Impl (void);

    // Initializing constructor.
    BenchmarkCharacteristics_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~BenchmarkCharacteristics_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}
    BenchmarkType src_BenchmarkType (void) const;
    MetricsBase dst_MetricsBase (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "BenchmarkCharacteristics.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_BENCHMARKCHARACTERISTICS
