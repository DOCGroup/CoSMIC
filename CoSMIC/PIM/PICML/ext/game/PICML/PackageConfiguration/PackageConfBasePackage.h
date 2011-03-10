// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfBasePackage.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFBASEPACKAGE_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFBASEPACKAGE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfBasePackage_Impl;
  typedef PackageConfBasePackage_Impl * PackageConfBasePackage_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfBasePackage_Impl> PackageConfBasePackage;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageConfBasePackage_Impl :
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
    PackageConfBasePackage_Impl (void);

    /// Initializing constructor
    PackageConfBasePackage_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~PackageConfBasePackage_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfBasePackage _create (const PackageConfigurationContainer_in parent);
    ///@}

    /// Get the src PackageConfiguration connection point.
    PackageConfiguration src_PackageConfiguration (void);

    /// Get the dst ComponentPackage connection point.
    ComponentPackage dst_ComponentPackage (void);

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
