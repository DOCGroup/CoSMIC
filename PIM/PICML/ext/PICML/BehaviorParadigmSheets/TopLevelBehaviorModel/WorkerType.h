// -*- C++ -*-

//============================================================================
/**
 * @file    WorkerType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_WORKERTYPE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_WORKERTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerType_Impl;
  typedef WorkerType_Impl * WorkerType_in;
  typedef ::GAME::Mga::Smart_Ptr < WorkerType_Impl > WorkerType;

  // Forward decl.
  class Visitor;

  /**
   * @class WorkerType_Impl
   *
   * Implementation for the WorkerType model element.
   */
  class PICML_Export WorkerType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkerType _create (const TopLevelBehavior_in parent);
    ///@}

    // Default constructor.
    WorkerType_Impl (void);

    // Initializing constructor.
    WorkerType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~WorkerType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelBehavior parent_TopLevelBehavior (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Worker_is_nil (void) const;
    Worker refers_to_Worker (void) const;
    void refers_to_Worker (Worker_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "WorkerType.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_WORKERTYPE
