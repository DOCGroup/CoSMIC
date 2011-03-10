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

#include "game/mga/Model.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Latency_Impl;
  typedef Latency_Impl * Latency_in;
  typedef ::GAME::Mga::Smart_Ptr <Latency_Impl> Latency;

  // Forward decl.
  class Visitor;

  class PICML_Export Latency_Impl :
    public virtual MetricsBase_Impl,
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Latency_Impl (void);

    /// Initializing constructor
    Latency_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Latency_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
