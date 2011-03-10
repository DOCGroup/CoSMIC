// -*- C++ -*-

//============================================================================
/**
 * @file    CompRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_COMPREF_H_
#define _PICML_COMPONENTBENCHMARK_COMPREF_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CompRef_Impl;
  typedef CompRef_Impl * CompRef_in;
  typedef ::GAME::Mga::Smart_Ptr <CompRef_Impl> CompRef;

  // Forward decl.
  class Visitor;

  class PICML_Export CompRef_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    CompRef_Impl (void);

    /// Initializing constructor
    CompRef_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~CompRef_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static CompRef _create (const BenchmarkAnalysis_in parent);
    ///@}
    size_t in_ComponentOperation_connections (std::vector <ComponentOperation> & conns) const;

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
