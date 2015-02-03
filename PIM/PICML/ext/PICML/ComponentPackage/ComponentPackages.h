// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentPackages.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_COMPONENTPACKAGES_H_
#define _PICML_COMPONENTPACKAGE_COMPONENTPACKAGES_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentPackages_Impl;
  typedef ComponentPackages_Impl * ComponentPackages_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentPackages_Impl > ComponentPackages;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentPackages_Impl
   *
   * Implementation for the ComponentPackages model element.
   */
  class PICML_Export ComponentPackages_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentPackages _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    ComponentPackages_Impl (void);

    // Initializing constructor.
    ComponentPackages_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~ComponentPackages_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    /**
     * @name Folder Getters
     */
    ///@{

    size_t get_PackageContainers (std::vector <PackageContainer> & items) const;

    ::GAME::Mga::Collection_T <PackageContainer> get_PackageContainers (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentPackages.inl"
#endif

#endif  // !defined _PICML_COMPONENTPACKAGE_COMPONENTPACKAGES
