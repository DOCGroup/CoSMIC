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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Project_Impl;
  typedef Project_Impl * Project_in;
  typedef ::GAME::Mga::Smart_Ptr < Project_Impl > Project;

  // Forward decl.
  class Visitor;

  /**
   * @class Project_Impl
   *
   * Implementation for the Project model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Project _create (const MPC_in parent);
    ///@}

    // Default constructor.
    Project_Impl (void);

    // Initializing constructor.
    Project_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Project_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    MPC parent_MPC (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ImplementationArtifacts (std::vector <ImplementationArtifact> & items) const;
    ::GAME::Mga::Collection_T <ImplementationArtifact> get_ImplementationArtifacts (void) const;

    size_t get_ExtResourceConns (std::vector <ExtResourceConn> & items) const;
    ::GAME::Mga::Collection_T <ExtResourceConn> get_ExtResourceConns (void) const;

    size_t get_ExternalResourcess (std::vector <ExternalResources> & items) const;
    ::GAME::Mga::Collection_T <ExternalResources> get_ExternalResourcess (void) const;

    size_t get_ExecutorProjects (std::vector <ExecutorProject> & items) const;
    ::GAME::Mga::Collection_T <ExecutorProject> get_ExecutorProjects (void) const;

    size_t get_ServantProjects (std::vector <ServantProject> & items) const;
    ::GAME::Mga::Collection_T <ServantProject> get_ServantProjects (void) const;

    size_t get_StubProjects (std::vector <StubProject> & items) const;
    ::GAME::Mga::Collection_T <StubProject> get_StubProjects (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Project.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_PROJECT
