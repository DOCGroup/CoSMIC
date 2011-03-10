// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfigProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_PACKAGECONFIGPROPERTY_H_
#define _PICML_COMPONENTPACKAGE_PACKAGECONFIGPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfigProperty_Impl;
  typedef PackageConfigProperty_Impl * PackageConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfigProperty_Impl> PackageConfigProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageConfigProperty_Impl :
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
    PackageConfigProperty_Impl (void);

    /// Initializing constructor
    PackageConfigProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~PackageConfigProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfigProperty _create (const PackageContainer_in parent);
    ///@}

    /// Get the src ComponentPackage connection point.
    ComponentPackage src_ComponentPackage (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageContainer parent_PackageContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
