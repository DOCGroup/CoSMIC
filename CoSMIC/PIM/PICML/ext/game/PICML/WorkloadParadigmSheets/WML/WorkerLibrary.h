// -*- C++ -*-

//============================================================================
/**
 * @file    WorkerLibrary.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERLIBRARY_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERLIBRARY_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerLibrary_Impl;
  typedef WorkerLibrary_Impl * WorkerLibrary_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerLibrary_Impl> WorkerLibrary;

  // Forward decl.
  class Visitor;

  class PICML_Export WorkerLibrary_Impl :
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
    WorkerLibrary_Impl (void);

    /// Initializing constructor
    WorkerLibrary_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~WorkerLibrary_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static WorkerLibrary _create (const WorkerLibraries_in parent);
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
    size_t get_WorkerFiles (std::vector <WorkerFile> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    WorkerLibraries parent_WorkerLibraries (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
