// -*- C++ -*-

//============================================================================
/**
 * @file    Worker.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_WORKER_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_WORKER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Worker_Impl;
  typedef Worker_Impl * Worker_in;
  typedef ::GAME::Mga::Smart_Ptr < Worker_Impl > Worker;

  // Forward decl.
  class Visitor;

  /**
   * @class Worker_Impl
   *
   * Implementation for the Worker model element.
   */
  class PICML_Export Worker_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Worker _create (const WorkerPackageBase_in parent);
    ///@}

    // Default constructor.
    Worker_Impl (void);

    // Initializing constructor.
    Worker_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Worker_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    WorkerPackageBase parent_WorkerPackageBase (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Abstract
    void Abstract (bool val);

    /// Get the value of Abstract
    bool Abstract (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Operations (std::vector <Operation> & items) const;
    ::GAME::Mga::Collection_T <Operation> get_Operations (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Worker.inl"
#endif

#endif  // !defined _PICML_WORKLOADPARADIGMSHEETS_WML_WORKER
