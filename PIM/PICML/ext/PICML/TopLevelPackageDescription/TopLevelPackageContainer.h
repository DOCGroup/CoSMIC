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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TopLevelPackageContainer_Impl;
  typedef TopLevelPackageContainer_Impl * TopLevelPackageContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < TopLevelPackageContainer_Impl > TopLevelPackageContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class TopLevelPackageContainer_Impl
   *
   * Implementation for the TopLevelPackageContainer model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static TopLevelPackageContainer _create (const TopLevelPackages_in parent);
    ///@}

    // Default constructor.
    TopLevelPackageContainer_Impl (void);

    // Initializing constructor.
    TopLevelPackageContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~TopLevelPackageContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelPackages parent_TopLevelPackages (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_TopLevelPackage (void) const;
    TopLevelPackage get_TopLevelPackage (void) const;

    bool has_package (void) const;
    package get_package (void) const;

    bool has_PackageConfigurationReference (void) const;
    PackageConfigurationReference get_PackageConfigurationReference (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TopLevelPackageContainer.inl"
#endif

#endif  // !defined _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGECONTAINER
