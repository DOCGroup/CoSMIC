// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfigurationContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONCONTAINER_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONCONTAINER_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfigurationContainer_Impl;
  typedef PackageConfigurationContainer_Impl * PackageConfigurationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfigurationContainer_Impl> PackageConfigurationContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageConfigurationContainer_Impl :
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
    PackageConfigurationContainer_Impl (void);

    /// Initializing constructor
    PackageConfigurationContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~PackageConfigurationContainer_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfigurationContainer _create (const PackageConfigurations_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_PackageConfigurations (std::vector <PackageConfiguration> & items) const;

    PackageConfSpecializedConfig get_PackageConfSpecializedConfig (void) const;
    size_t get_PackageConfSelectRequirements (std::vector <PackageConfSelectRequirement> & items) const;
    size_t get_PackageConfConfigPropertys (std::vector <PackageConfConfigProperty> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;
    size_t get_Requirements (std::vector <Requirement> & items) const;

    ComponentPackageReference get_ComponentPackageReference (void) const;

    ComponentPackage get_ComponentPackage (void) const;

    PackageConfReference get_PackageConfReference (void) const;

    PackageConfBasePackage get_PackageConfBasePackage (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurations parent_PackageConfigurations (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
