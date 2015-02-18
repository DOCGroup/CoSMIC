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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MPC_Impl;
  typedef MPC_Impl * MPC_in;
  typedef ::GAME::Mga::Smart_Ptr < MPC_Impl > MPC;

  // Forward decl.
  class Visitor;

  /**
   * @class MPC_Impl
   *
   * Implementation for the MPC model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static MPC _create (const ComponentBuild_in parent);
    ///@}

    // Default constructor.
    MPC_Impl (void);

    // Initializing constructor.
    MPC_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~MPC_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentBuild parent_ComponentBuild (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Workspacess (std::vector <Workspaces> & items) const;
    ::GAME::Mga::Collection_T <Workspaces> get_Workspacess (void) const;

    size_t get_Projects (std::vector <Project> & items) const;
    ::GAME::Mga::Collection_T <Project> get_Projects (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MPC.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_MPC
