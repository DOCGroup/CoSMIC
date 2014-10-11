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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Set.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Workspaces_Impl;
  typedef Workspaces_Impl * Workspaces_in;
  typedef ::GAME::Mga::Smart_Ptr < Workspaces_Impl > Workspaces;

  // Forward decl.
  class Visitor;

  /**
   * @class Workspaces_Impl
   *
   * Implementation for the Workspaces model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static Workspaces _create (const MPC_in parent);
    ///@}

    // Default constructor.
    Workspaces_Impl (void);

    // Initializing constructor.
    Workspaces_Impl (IMgaSet * ptr);

    // Destructor.
    virtual ~Workspaces_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    MPC parent_MPC (void);
    ///@}

    /**
     * @name Set Member Getters
     */
    ///@{

    ::GAME::Mga::Collection_T <Project> members_Project (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Workspaces.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_WORKSPACES
