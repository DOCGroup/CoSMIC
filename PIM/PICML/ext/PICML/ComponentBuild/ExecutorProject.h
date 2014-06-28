// -*- C++ -*-

//============================================================================
/**
 * @file    ExecutorProject.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_EXECUTORPROJECT_H_
#define _PICML_COMPONENTBUILD_EXECUTORPROJECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBuild/ComponentLib.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExecutorProject_Impl;
  typedef ExecutorProject_Impl * ExecutorProject_in;
  typedef ::GAME::Mga::Smart_Ptr < ExecutorProject_Impl > ExecutorProject;

  // Forward decl.
  class Visitor;

  /**
   * @class ExecutorProject_Impl
   *
   * Implementation for the ExecutorProject model element.
   */
  class PICML_Export ExecutorProject_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual ComponentLib_Impl
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
    static ExecutorProject _create (const Project_in parent);
    ///@}

    // Default constructor.
    ExecutorProject_Impl (void);

    // Initializing constructor.
    ExecutorProject_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ExecutorProject_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ImplementationArtifactReference (void) const;
    ImplementationArtifactReference get_ImplementationArtifactReference (void) const;

    bool has_ComponentImplementationArtifact (void) const;
    ComponentImplementationArtifact get_ComponentImplementationArtifact (void) const;

    bool has_ComponentServantArtifact (void) const;
    ComponentServantArtifact get_ComponentServantArtifact (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExecutorProject.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_EXECUTORPROJECT
