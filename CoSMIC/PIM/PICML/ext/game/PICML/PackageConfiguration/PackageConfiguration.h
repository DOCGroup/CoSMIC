// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfiguration.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATION_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATION_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfiguration_Impl;
  typedef PackageConfiguration_Impl * PackageConfiguration_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfiguration_Impl> PackageConfiguration;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageConfiguration_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    PackageConfiguration_Impl (void);

    /// Initializing constructor
    PackageConfiguration_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~PackageConfiguration_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfiguration _create (const PackageConfigurationContainer_in parent);
    ///@}
    size_t in_PackageConfReference_connections (std::vector <PackageConfReference> & conns) const;
    size_t in_PackageConfSpecializedConfig_connections (std::vector <PackageConfSpecializedConfig> & conns) const;
    size_t in_PackageConfConfigProperty_connections (std::vector <PackageConfConfigProperty> & conns) const;
    size_t in_PackageConfSelectRequirement_connections (std::vector <PackageConfSelectRequirement> & conns) const;
    size_t in_PackageConfBasePackage_connections (std::vector <PackageConfBasePackage> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurationContainer parent_PackageConfigurationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
