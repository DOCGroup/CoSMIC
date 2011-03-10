// -*- C++ -*-

//============================================================================
/**
 * @file    Project.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_PROJECT_H_
#define _PICML_COMPONENTBUILD_PROJECT_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Project_Impl;
  typedef Project_Impl * Project_in;
  typedef ::GAME::Mga::Smart_Ptr <Project_Impl> Project;

  // Forward decl.
  class Visitor;

  class PICML_Export Project_Impl :
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
    Project_Impl (void);

    /// Initializing constructor
    Project_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Project_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Project _create (const MPC_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComponentLibs (std::vector <ComponentLib> & items) const;
    size_t get_ExtResourceConns (std::vector <ExtResourceConn> & items) const;
    size_t get_ExternalResourcess (std::vector <ExternalResources> & items) const;
    size_t get_ImplementationArtifacts (std::vector <ImplementationArtifact> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    MPC parent_MPC (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
