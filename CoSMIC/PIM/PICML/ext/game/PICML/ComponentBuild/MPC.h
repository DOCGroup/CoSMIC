// -*- C++ -*-

//============================================================================
/**
 * @file    MPC.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_MPC_H_
#define _PICML_COMPONENTBUILD_MPC_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MPC_Impl;
  typedef MPC_Impl * MPC_in;
  typedef ::GAME::Mga::Smart_Ptr <MPC_Impl> MPC;

  // Forward decl.
  class Visitor;

  class PICML_Export MPC_Impl :
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
    MPC_Impl (void);

    /// Initializing constructor
    MPC_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~MPC_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static MPC _create (const ComponentBuild_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Workspacess (std::vector <Workspaces> & items) const;
    size_t get_Projects (std::vector <Project> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentBuild parent_ComponentBuild (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
