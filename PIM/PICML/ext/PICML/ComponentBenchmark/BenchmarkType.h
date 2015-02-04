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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BenchmarkType_Impl;
  typedef BenchmarkType_Impl * BenchmarkType_in;
  typedef ::GAME::Mga::Smart_Ptr < BenchmarkType_Impl > BenchmarkType;

  /**
   * @class BenchmarkType_Impl
   *
   * Implementation for the BenchmarkType model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    BenchmarkType_Impl (void);

    // Initializing constructor.
    BenchmarkType_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~BenchmarkType_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src BenchmarkCharacteristics connection.
    size_t src_of_BenchmarkCharacteristics (std::vector <BenchmarkCharacteristics> & items) const;
    GAME::Mga::Collection_T <BenchmarkCharacteristics> src_of_BenchmarkCharacteristics (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "BenchmarkType.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_BENCHMARKTYPE
