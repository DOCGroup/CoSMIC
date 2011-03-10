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

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class package_Impl;
  typedef package_Impl * package_in;
  typedef ::GAME::Mga::Smart_Ptr <package_Impl> package;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    package_Impl (void);

    /// Initializing constructor
    package_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~package_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static package _create (const TopLevelPackageContainer_in parent);
    ///@}

    /// Get the src TopLevelPackage connection point.
    TopLevelPackage src_TopLevelPackage (void);

    /// Get the dst PackageConfigurationReference connection point.
    PackageConfigurationReference dst_PackageConfigurationReference (void);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelPackageContainer parent_TopLevelPackageContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
