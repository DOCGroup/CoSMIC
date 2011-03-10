// -*- C++ -*-

//============================================================================
/**
 * @file    PackageContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_PACKAGECONTAINER_H_
#define _PICML_COMPONENTPACKAGE_PACKAGECONTAINER_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageContainer_Impl;
  typedef PackageContainer_Impl * PackageContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageContainer_Impl> PackageContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageContainer_Impl :
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
    PackageContainer_Impl (void);

    /// Initializing constructor
    PackageContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~PackageContainer_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageContainer _create (const ComponentPackages_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_PackageInfoPropertys (std::vector <PackageInfoProperty> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;

    PackageInterface get_PackageInterface (void) const;
    size_t get_PackageConfigPropertys (std::vector <PackageConfigProperty> & items) const;
    size_t get_Implementations (std::vector <Implementation> & items) const;

    ComponentPackage get_ComponentPackage (void) const;

    ComponentRef get_ComponentRef (void) const;
    size_t get_ComponentImplementationReferences (std::vector <ComponentImplementationReference> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentPackages parent_ComponentPackages (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
