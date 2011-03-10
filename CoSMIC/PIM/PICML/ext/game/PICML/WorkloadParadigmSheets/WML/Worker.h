// -*- C++ -*-

//============================================================================
/**
 * @file    Worker.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_WORKER_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_WORKER_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Worker_Impl;
  typedef Worker_Impl * Worker_in;
  typedef ::GAME::Mga::Smart_Ptr <Worker_Impl> Worker;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    Worker_Impl (void);

    /// Initializing constructor
    Worker_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Worker_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Worker _create (const WorkerPackageBase_in parent);
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
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    WorkerPackageBase parent_WorkerPackageBase (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
