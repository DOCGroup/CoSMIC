// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfConfigProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFCONFIGPROPERTY_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFCONFIGPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfConfigProperty_Impl;
  typedef PackageConfConfigProperty_Impl * PackageConfConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfConfigProperty_Impl> PackageConfConfigProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageConfConfigProperty_Impl :
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
    PackageConfConfigProperty_Impl (void);

    /// Initializing constructor
    PackageConfConfigProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~PackageConfConfigProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfConfigProperty _create (const PackageConfigurationContainer_in parent);
    ///@}

    /// Get the src PackageConfiguration connection point.
    PackageConfiguration src_PackageConfiguration (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

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
