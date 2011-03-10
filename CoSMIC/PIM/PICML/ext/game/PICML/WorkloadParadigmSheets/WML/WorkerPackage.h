// -*- C++ -*-

//============================================================================
/**
 * @file    WorkerPackage.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERPACKAGE_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERPACKAGE_H_

#include "game/mga/Model.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackageBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerPackage_Impl;
  typedef WorkerPackage_Impl * WorkerPackage_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerPackage_Impl> WorkerPackage;

  // Forward decl.
  class Visitor;

  class PICML_Export WorkerPackage_Impl :
    public virtual WorkerPackageBase_Impl,
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
    WorkerPackage_Impl (void);

    /// Initializing constructor
    WorkerPackage_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~WorkerPackage_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkerPackage _create (const WorkerFile_in parent);
    static WorkerPackage _create (const WorkerPackage_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_WorkerPackages (std::vector <WorkerPackage> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    WorkerFile parent_WorkerFile (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
