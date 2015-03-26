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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Task_Impl;
  typedef Task_Impl * Task_in;
  typedef ::GAME::Mga::Smart_Ptr < Task_Impl > Task;

  // Forward decl.
  class Visitor;

  /**
   * @class Task_Impl
   *
   * Implementation for the Task model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Task _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    Task_Impl (void);

    // Initializing constructor.
    Task_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Task_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst WorkLoadOperationConnection connection.
    size_t dst_of_WorkLoadOperationConnection (std::vector <WorkLoadOperationConnection> & items) const;
    bool has_dst_of_WorkLoadOperationConnection (void) const;
    WorkLoadOperationConnection dst_of_WorkLoadOperationConnection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Task.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_TASK
