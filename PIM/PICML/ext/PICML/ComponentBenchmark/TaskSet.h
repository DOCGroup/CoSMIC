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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Set.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TaskSet_Impl;
  typedef TaskSet_Impl * TaskSet_in;
  typedef ::GAME::Mga::Smart_Ptr < TaskSet_Impl > TaskSet;

  // Forward decl.
  class Visitor;

  /**
   * @class TaskSet_Impl
   *
   * Implementation for the TaskSet model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static TaskSet _create (const BenchmarkAnalysis_in parent);
    ///@}

    // Default constructor.
    TaskSet_Impl (void);

    // Initializing constructor.
    TaskSet_Impl (IMgaSet * ptr);

    // Destructor.
    virtual ~TaskSet_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of priority
    void priority (long val);

    /// Get the value of priority
    long priority (void) const;

    /// Set the value of rate
    void rate (long val);

    /// Get the value of rate
    long rate (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst WorkloadCharacteristics connection.
    size_t dst_of_WorkloadCharacteristics (std::vector <WorkloadCharacteristics> & items) const;
    GAME::Mga::Collection_T <WorkloadCharacteristics> dst_of_WorkloadCharacteristics (void) const;
    ///@}

    /**
     * @name Set Member Getters
     */
    ///@{

    ::GAME::Mga::Collection_T <Task> members_Task (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TaskSet.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_TASKSET
