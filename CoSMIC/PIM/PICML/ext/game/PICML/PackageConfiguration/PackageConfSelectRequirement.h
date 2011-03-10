// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfSelectRequirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFSELECTREQUIREMENT_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFSELECTREQUIREMENT_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfSelectRequirement_Impl;
  typedef PackageConfSelectRequirement_Impl * PackageConfSelectRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfSelectRequirement_Impl> PackageConfSelectRequirement;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageConfSelectRequirement_Impl :
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
    PackageConfSelectRequirement_Impl (void);

    /// Initializing constructor
    PackageConfSelectRequirement_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~PackageConfSelectRequirement_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfSelectRequirement _create (const PackageConfigurationContainer_in parent);
    ///@}

    /// Get the src PackageConfiguration connection point.
    PackageConfiguration src_PackageConfiguration (void);

    /// Get the dst Requirement connection point.
    Requirement dst_Requirement (void);

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
