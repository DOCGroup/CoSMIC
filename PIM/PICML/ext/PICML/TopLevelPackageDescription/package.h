// -*- C++ -*-

//============================================================================
/**
 * @file    package.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TOPLEVELPACKAGEDESCRIPTION_PACKAGE_H_
#define _PICML_TOPLEVELPACKAGEDESCRIPTION_PACKAGE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class package_Impl;
  typedef package_Impl * package_in;
  typedef ::GAME::Mga::Smart_Ptr < package_Impl > package;

  // Forward decl.
  class Visitor;

  /**
   * @class package_Impl
   *
   * Implementation for the package model element.
   */
  class PICML_Export package_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static package _create (const TopLevelPackageContainer_in parent, TopLevelPackage_in src, PackageConfigurationReference_in dst);
    ///@}

    // Default constructor.
    package_Impl (void);

    // Initializing constructor.
    package_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~package_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelPackageContainer parent_TopLevelPackageContainer (void);
    ///@}
    TopLevelPackage src_TopLevelPackage (void) const;
    PackageConfigurationReference dst_PackageConfigurationReference (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "package.inl"
#endif

#endif  // !defined _PICML_TOPLEVELPACKAGEDESCRIPTION_PACKAGE
