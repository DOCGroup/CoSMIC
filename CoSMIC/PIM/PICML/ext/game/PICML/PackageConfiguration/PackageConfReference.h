// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFREFERENCE_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFREFERENCE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfReference_Impl;
  typedef PackageConfReference_Impl * PackageConfReference_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfReference_Impl> PackageConfReference;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageConfReference_Impl :
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
    PackageConfReference_Impl (void);

    /// Initializing constructor
    PackageConfReference_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~PackageConfReference_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfReference _create (const PackageConfigurationContainer_in parent);
    ///@}

    /// Get the src PackageConfiguration connection point.
    PackageConfiguration src_PackageConfiguration (void);

    /// Get the dst ComponentPackageReference connection point.
    ComponentPackageReference dst_ComponentPackageReference (void);

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
