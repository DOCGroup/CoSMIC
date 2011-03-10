// -*- C++ -*-

//============================================================================
/**
 * @file    TopLevelPackageContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGECONTAINER_H_
#define _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGECONTAINER_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TopLevelPackageContainer_Impl;
  typedef TopLevelPackageContainer_Impl * TopLevelPackageContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <TopLevelPackageContainer_Impl> TopLevelPackageContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export TopLevelPackageContainer_Impl :
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
    TopLevelPackageContainer_Impl (void);

    /// Initializing constructor
    TopLevelPackageContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~TopLevelPackageContainer_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static TopLevelPackageContainer _create (const TopLevelPackages_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    package get_package (void) const;

    TopLevelPackage get_TopLevelPackage (void) const;

    PackageConfigurationReference get_PackageConfigurationReference (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelPackages parent_TopLevelPackages (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
