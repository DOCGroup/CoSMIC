// -*- C++ -*-

//============================================================================
/**
 * @file    ServantProject.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_SERVANTPROJECT_H_
#define _PICML_COMPONENTBUILD_SERVANTPROJECT_H_

#include "game/mga/Model.h"
#include "PICML/ComponentBuild/ComponentLib.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ServantProject_Impl;
  typedef ServantProject_Impl * ServantProject_in;
  typedef ::GAME::Mga::Smart_Ptr <ServantProject_Impl> ServantProject;

  // Forward decl.
  class Visitor;

  class PICML_Export ServantProject_Impl :
    public virtual ComponentLib_Impl,
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
    ServantProject_Impl (void);

    /// Initializing constructor
    ServantProject_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ServantProject_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    FileRef get_FileRef (void) const;

    ImplementationArtifactReference get_ImplementationArtifactReference (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
