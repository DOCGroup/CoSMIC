// -*- C++ -*-

//============================================================================
/**
 * @file    DataAnalysisBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_DATAANALYSISBASE_H_
#define _PICML_COMPONENTBENCHMARK_DATAANALYSISBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataAnalysisBase_Impl;
  typedef DataAnalysisBase_Impl * DataAnalysisBase_in;
  typedef ::GAME::Mga::Smart_Ptr < DataAnalysisBase_Impl > DataAnalysisBase;

  /**
   * @class DataAnalysisBase_Impl
   *
   * Implementation for the DataAnalysisBase model element.
   */
  class PICML_Export DataAnalysisBase_Impl :
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
    DataAnalysisBase_Impl (void);

    // Initializing constructor.
    DataAnalysisBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~DataAnalysisBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    MetricsBase parent_MetricsBase (void);
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DataAnalysisBase.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_DATAANALYSISBASE
