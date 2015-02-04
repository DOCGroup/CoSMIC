// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfigurations.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONS_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfigurations_Impl;
  typedef PackageConfigurations_Impl * PackageConfigurations_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfigurations_Impl > PackageConfigurations;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfigurations_Impl
   *
   * Implementation for the PackageConfigurations model element.
   */
  class PICML_Export PackageConfigurations_Impl :
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
    static PackageConfigurations _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    PackageConfigurations_Impl (void);

    // Initializing constructor.
    PackageConfigurations_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~PackageConfigurations_Impl (void);

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

    size_t get_PackageConfigurationContainers (std::vector <PackageConfigurationContainer> & items) const;

    ::GAME::Mga::Collection_T <PackageConfigurationContainer> get_PackageConfigurationContainers (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfigurations.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONS
