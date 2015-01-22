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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConfigProperty_Impl;
  typedef ConfigProperty_Impl * ConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < ConfigProperty_Impl > ConfigProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class ConfigProperty_Impl
   *
   * Implementation for the ConfigProperty model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static ConfigProperty _create (const ImplementationContainer_in parent, Implemenation_in src, Property_in dst);
    ///@}

    // Default constructor.
    ConfigProperty_Impl (void);

    // Initializing constructor.
    ConfigProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ConfigProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationContainer parent_ImplementationContainer (void);
    ///@}
    Implemenation src_Implemenation (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ConfigProperty.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_CONFIGPROPERTY
