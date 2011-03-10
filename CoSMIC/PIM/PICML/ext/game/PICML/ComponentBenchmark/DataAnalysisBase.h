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

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DataAnalysisBase_Impl;
  typedef DataAnalysisBase_Impl * DataAnalysisBase_in;
  typedef ::GAME::Mga::Smart_Ptr <DataAnalysisBase_Impl> DataAnalysisBase;

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

    /// Default constructor
    DataAnalysisBase_Impl (void);

    /// Initializing constructor
    DataAnalysisBase_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~DataAnalysisBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    MetricsBase parent_MetricsBase (void) const;
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
