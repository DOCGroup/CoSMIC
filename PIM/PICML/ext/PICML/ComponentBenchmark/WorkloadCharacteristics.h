// -*- C++ -*-

//============================================================================
/**
 * @file    WorkloadCharacteristics.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_WORKLOADCHARACTERISTICS_H_
#define _PICML_COMPONENTBENCHMARK_WORKLOADCHARACTERISTICS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkloadCharacteristics_Impl;
  typedef WorkloadCharacteristics_Impl * WorkloadCharacteristics_in;
  typedef ::GAME::Mga::Smart_Ptr < WorkloadCharacteristics_Impl > WorkloadCharacteristics;

  // Forward decl.
  class Visitor;

  /**
   * @class WorkloadCharacteristics_Impl
   *
   * Implementation for the WorkloadCharacteristics model element.
   */
  class PICML_Export WorkloadCharacteristics_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkloadCharacteristics _create (const BenchmarkAnalysis_in parent, MetricsBase_in src, TaskSet_in dst);
    ///@}

    // Default constructor.
    WorkloadCharacteristics_Impl (void);

    // Initializing constructor.
    WorkloadCharacteristics_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~WorkloadCharacteristics_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}
    MetricsBase src_MetricsBase (void) const;
    TaskSet dst_TaskSet (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "WorkloadCharacteristics.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_WORKLOADCHARACTERISTICS
