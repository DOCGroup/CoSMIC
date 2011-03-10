// -*- C++ -*-

//============================================================================
/**
 * @file    WorkerFile.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERFILE_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERFILE_H_

#include "game/mga/Model.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackageBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerFile_Impl;
  typedef WorkerFile_Impl * WorkerFile_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerFile_Impl> WorkerFile;

  // Forward decl.
  class Visitor;

  class PICML_Export WorkerFile_Impl :
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
    WorkerFile_Impl (void);

    /// Initializing constructor
    WorkerFile_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~WorkerFile_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkerFile _create (const WorkerLibrary_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Location
    void Location (const std::string & val);

    /// Get the value of Location
    std::string Location (void) const;
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
    WorkerLibrary parent_WorkerLibrary (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
