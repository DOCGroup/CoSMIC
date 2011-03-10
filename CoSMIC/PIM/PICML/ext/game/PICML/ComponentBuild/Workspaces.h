// -*- C++ -*-

//============================================================================
/**
 * @file    Workspaces.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_WORKSPACES_H_
#define _PICML_COMPONENTBUILD_WORKSPACES_H_

#include "game/mga/Set.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Workspaces_Impl;
  typedef Workspaces_Impl * Workspaces_in;
  typedef ::GAME::Mga::Smart_Ptr <Workspaces_Impl> Workspaces;

  // Forward decl.
  class Visitor;

  class PICML_Export Workspaces_Impl :
    public virtual ::GAME::Mga::Set_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::set_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaSet interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Workspaces_Impl (void);

    /// Initializing constructor
    Workspaces_Impl (IMgaSet * ptr);

    /// Destructor
    virtual ~Workspaces_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Workspaces _create (const MPC_in parent);
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
