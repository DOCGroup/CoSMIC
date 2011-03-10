// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfigurationReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONREFERENCE_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFIGURATIONREFERENCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfigurationReference_Impl;
  typedef PackageConfigurationReference_Impl * PackageConfigurationReference_in;
  typedef ::GAME::Mga::Smart_Ptr <PackageConfigurationReference_Impl> PackageConfigurationReference;

  // Forward decl.
  class Visitor;

  class PICML_Export PackageConfigurationReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    PackageConfigurationReference_Impl (void);

    /// Initializing constructor
    PackageConfigurationReference_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~PackageConfigurationReference_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}
    size_t in_PackageConfSpecializedConfig_connections (std::vector <PackageConfSpecializedConfig> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    PackageConfiguration refers_to_PackageConfiguration (void) const;
    ///@}
  };
}

#endif
