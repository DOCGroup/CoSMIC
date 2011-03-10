// -*- C++ -*-

//============================================================================
/**
 * @file    Task.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_TASK_H_
#define _PICML_COMPONENTBENCHMARK_TASK_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Task_Impl;
  typedef Task_Impl * Task_in;
  typedef ::GAME::Mga::Smart_Ptr <Task_Impl> Task;

  // Forward decl.
  class Visitor;

  class PICML_Export Task_Impl :
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
    Task_Impl (void);

    /// Initializing constructor
    Task_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~Task_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Task _create (const BenchmarkAnalysis_in parent);
    ///@}
    size_t in_WorkLoadOperationConnection_connections (std::vector <WorkLoadOperationConnection> & conns) const;

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
