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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfConfigProperty_Impl;
  typedef PackageConfConfigProperty_Impl * PackageConfConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfConfigProperty_Impl > PackageConfConfigProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfConfigProperty_Impl
   *
   * Implementation for the PackageConfConfigProperty model element.
   */
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


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfConfigProperty _create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, Property_in dst);
    ///@}

    // Default constructor.
    PackageConfConfigProperty_Impl (void);

    // Initializing constructor.
    PackageConfConfigProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PackageConfConfigProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    ///@}
    PackageConfiguration src_PackageConfiguration (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfConfigProperty.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFCONFIGPROPERTY
