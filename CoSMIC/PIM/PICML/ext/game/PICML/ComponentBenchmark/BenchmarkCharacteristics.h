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

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BenchmarkCharacteristics_Impl;
  typedef BenchmarkCharacteristics_Impl * BenchmarkCharacteristics_in;
  typedef ::GAME::Mga::Smart_Ptr <BenchmarkCharacteristics_Impl> BenchmarkCharacteristics;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    BenchmarkCharacteristics_Impl (void);

    /// Initializing constructor
    BenchmarkCharacteristics_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~BenchmarkCharacteristics_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static BenchmarkCharacteristics _create (const BenchmarkAnalysis_in parent);
    ///@}

    /// Get the src BenchmarkType connection point.
    BenchmarkType src_BenchmarkType (void);

    /// Get the dst MetricsBase connection point.
    MetricsBase dst_MetricsBase (void);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
