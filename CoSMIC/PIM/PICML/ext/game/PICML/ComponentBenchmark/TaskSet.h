// -*- C++ -*-

//============================================================================
/**
 * @file    TaskSet.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_TASKSET_H_
#define _PICML_COMPONENTBENCHMARK_TASKSET_H_

#include "game/mga/Set.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TaskSet_Impl;
  typedef TaskSet_Impl * TaskSet_in;
  typedef ::GAME::Mga::Smart_Ptr <TaskSet_Impl> TaskSet;

  // Forward decl.
  class Visitor;

  class PICML_Export TaskSet_Impl :
    public virtual ::GAME::Mga::Set_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::set_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaSet interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    TaskSet_Impl (void);

    /// Initializing constructor
    TaskSet_Impl (IMgaSet * ptr);

    /// Destructor
    virtual ~TaskSet_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static TaskSet _create (const BenchmarkAnalysis_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of rate
    void rate (long val);

    /// Get the value of rate
    long rate (void) const;

    /// Set the value of priority
    void priority (long val);

    /// Get the value of priority
    long priority (void) const;
    ///@}
    size_t in_WorkloadCharacteristics_connections (std::vector <WorkloadCharacteristics> & conns) const;

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
