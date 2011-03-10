// -*- C++ -*-

//============================================================================
/**
 * @file    BenchmarkType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_BENCHMARKTYPE_H_
#define _PICML_COMPONENTBENCHMARK_BENCHMARKTYPE_H_

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BenchmarkType_Impl;
  typedef BenchmarkType_Impl * BenchmarkType_in;
  typedef ::GAME::Mga::Smart_Ptr <BenchmarkType_Impl> BenchmarkType;

  class PICML_Export BenchmarkType_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    BenchmarkType_Impl (void);

    /// Initializing constructor
    BenchmarkType_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~BenchmarkType_Impl (void) = 0;
    size_t in_BenchmarkCharacteristics_connections (std::vector <BenchmarkCharacteristics> & conns) const;

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
