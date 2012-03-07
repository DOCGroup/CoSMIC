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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/WorkloadParadigmSheets/WML/WorkerPackageBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerFile_Impl;
  typedef WorkerFile_Impl * WorkerFile_in;
  typedef ::GAME::Mga::Smart_Ptr < WorkerFile_Impl > WorkerFile;

  // Forward decl.
  class Visitor;

  /**
   * @class WorkerFile_Impl
   *
   * Implementation for the WorkerFile model element.
   */
  class PICML_Export WorkerFile_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual WorkerPackageBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkerFile _create (const WorkerLibrary_in parent);
    static WorkerFile _create (const WorkerPackageBase_in parent);
    ///@}

    // Default constructor.
    WorkerFile_Impl (void);

    // Initializing constructor.
    WorkerFile_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~WorkerFile_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

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
    ::GAME::Mga::Iterator <WorkerPackage> get_WorkerPackages (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "WorkerFile.inl"
#endif

#endif  // !defined _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERFILE
