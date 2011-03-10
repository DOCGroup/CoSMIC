// -*- C++ -*-

//============================================================================
/**
 * @file    Average.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_AVERAGE_H_
#define _PICML_COMPONENTBENCHMARK_AVERAGE_H_

#include "game/mga/Atom.h"
#include "PICML/ComponentBenchmark/DataAnalysisBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Average_Impl;
  typedef Average_Impl * Average_in;
  typedef ::GAME::Mga::Smart_Ptr <Average_Impl> Average;

  // Forward decl.
  class Visitor;

  class PICML_Export Average_Impl :
    public virtual DataAnalysisBase_Impl,
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Average_Impl (void);

    /// Initializing constructor
    Average_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~Average_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
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
