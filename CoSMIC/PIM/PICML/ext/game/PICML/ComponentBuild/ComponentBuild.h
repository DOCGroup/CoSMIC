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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentBuild_Impl;
  typedef ComponentBuild_Impl * ComponentBuild_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentBuild_Impl > ComponentBuild;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentBuild_Impl
   *
   * Implementation for the ComponentBuild model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentBuild _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    ComponentBuild_Impl (void);

    // Initializing constructor.
    ComponentBuild_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~ComponentBuild_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    size_t get_MPCs (std::vector <MPC> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentBuild.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_COMPONENTBUILD
