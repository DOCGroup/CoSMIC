// -*- C++ -*-

//============================================================================
/**
 * @file    StubProject.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_STUBPROJECT_H_
#define _PICML_COMPONENTBUILD_STUBPROJECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentBuild/ComponentLib.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class StubProject_Impl;
  typedef StubProject_Impl * StubProject_in;
  typedef ::GAME::Mga::Smart_Ptr < StubProject_Impl > StubProject;

  // Forward decl.
  class Visitor;

  /**
   * @class StubProject_Impl
   *
   * Implementation for the StubProject model element.
   */
  class PICML_Export StubProject_Impl :
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
    static StubProject _create (const Project_in parent);
    ///@}

    // Default constructor.
    StubProject_Impl (void);

    // Initializing constructor.
    StubProject_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~StubProject_Impl (void);

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

    bool has_FileRef (void) const;
    FileRef get_FileRef (void) const;

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
#include "StubProject.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_STUBPROJECT
