// -*- C++ -*-

//============================================================================
/**
 * @file    WorkLoadOperationConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_WORKLOADOPERATIONCONNECTION_H_
#define _PICML_COMPONENTBENCHMARK_WORKLOADOPERATIONCONNECTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkLoadOperationConnection_Impl;
  typedef WorkLoadOperationConnection_Impl * WorkLoadOperationConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < WorkLoadOperationConnection_Impl > WorkLoadOperationConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class WorkLoadOperationConnection_Impl
   *
   * Implementation for the WorkLoadOperationConnection model element.
   */
  class PICML_Export WorkLoadOperationConnection_Impl :
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
    static WorkLoadOperationConnection _create (const BenchmarkAnalysis_in parent, OperationRef_in src, Task_in dst);
    ///@}

    // Default constructor.
    WorkLoadOperationConnection_Impl (void);

    // Initializing constructor.
    WorkLoadOperationConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~WorkLoadOperationConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}
    OperationRef src_OperationRef (void) const;
    Task dst_Task (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "WorkLoadOperationConnection.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_WORKLOADOPERATIONCONNECTION
