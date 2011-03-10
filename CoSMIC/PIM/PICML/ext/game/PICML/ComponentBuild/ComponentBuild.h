// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentBuild.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_COMPONENTBUILD_H_
#define _PICML_COMPONENTBUILD_COMPONENTBUILD_H_

#include "game/mga/Folder.h"
#include "game/mga/RootFolder.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentBuild_Impl;
  typedef ComponentBuild_Impl * ComponentBuild_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentBuild_Impl> ComponentBuild;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentBuild_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentBuild_Impl (void);

    /// Initializing constructor
    ComponentBuild_Impl (IMgaFolder * ptr);

    /// Destructor
    virtual ~ComponentBuild_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentBuild _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ::GAME::Mga::RootFolder parent_RootFolder (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
