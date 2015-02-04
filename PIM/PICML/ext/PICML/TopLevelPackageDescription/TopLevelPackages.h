// -*- C++ -*-

//============================================================================
/**
 * @file    TopLevelPackages.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGES_H_
#define _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGES_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TopLevelPackages_Impl;
  typedef TopLevelPackages_Impl * TopLevelPackages_in;
  typedef ::GAME::Mga::Smart_Ptr < TopLevelPackages_Impl > TopLevelPackages;

  // Forward decl.
  class Visitor;

  /**
   * @class TopLevelPackages_Impl
   *
   * Implementation for the TopLevelPackages model element.
   */
  class PICML_Export TopLevelPackages_Impl :
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
    static TopLevelPackages _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    TopLevelPackages_Impl (void);

    // Initializing constructor.
    TopLevelPackages_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~TopLevelPackages_Impl (void);

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

    size_t get_TopLevelPackageContainers (std::vector <TopLevelPackageContainer> & items) const;

    ::GAME::Mga::Collection_T <TopLevelPackageContainer> get_TopLevelPackageContainers (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TopLevelPackages.inl"
#endif

#endif  // !defined _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGES
