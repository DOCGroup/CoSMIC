// -*- C++ -*-

//============================================================================
/**
 * @file    ConfigProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_CONFIGPROPERTY_H_
#define _PICML_IMPLEMENTATIONCOMMON_CONFIGPROPERTY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConfigProperty_Impl;
  typedef ConfigProperty_Impl * ConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <ConfigProperty_Impl> ConfigProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export ConfigProperty_Impl :
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
    ConfigProperty_Impl (void);

    /// Initializing constructor
    ConfigProperty_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ConfigProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ConfigProperty _create (const ImplementationContainer_in parent);
    ///@}

    /// Get the src Implemenation connection point.
    Implemenation src_Implemenation (void);

    /// Get the dst Property connection point.
    Property dst_Property (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationContainer parent_ImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
