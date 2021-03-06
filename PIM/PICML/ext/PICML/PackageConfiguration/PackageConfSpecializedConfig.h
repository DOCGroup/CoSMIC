// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfSpecializedConfig.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFSPECIALIZEDCONFIG_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFSPECIALIZEDCONFIG_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfSpecializedConfig_Impl;
  typedef PackageConfSpecializedConfig_Impl * PackageConfSpecializedConfig_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfSpecializedConfig_Impl > PackageConfSpecializedConfig;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfSpecializedConfig_Impl
   *
   * Implementation for the PackageConfSpecializedConfig model element.
   */
  class PICML_Export PackageConfSpecializedConfig_Impl :
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
    static PackageConfSpecializedConfig _create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, PackageConfigurationReference_in dst);
    ///@}

    // Default constructor.
    PackageConfSpecializedConfig_Impl (void);

    // Initializing constructor.
    PackageConfSpecializedConfig_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PackageConfSpecializedConfig_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    ///@}
    PackageConfiguration src_PackageConfiguration (void) const;
    PackageConfigurationReference dst_PackageConfigurationReference (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfSpecializedConfig.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFSPECIALIZEDCONFIG
