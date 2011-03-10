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

#include "game/mga/Model.h"
#include "PICML/ComponentBenchmark/MetricsBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Throughput_Impl;
  typedef Throughput_Impl * Throughput_in;
  typedef ::GAME::Mga::Smart_Ptr <Throughput_Impl> Throughput;

  // Forward decl.
  class Visitor;

  class PICML_Export Throughput_Impl :
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
    Throughput_Impl (void);

    /// Initializing constructor
    Throughput_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Throughput_Impl (void);

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
