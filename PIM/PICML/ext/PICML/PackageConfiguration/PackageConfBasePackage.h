// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfBasePackage.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PACKAGECONFIGURATION_PACKAGECONFBASEPACKAGE_H_
#define _PICML_PACKAGECONFIGURATION_PACKAGECONFBASEPACKAGE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfBasePackage_Impl;
  typedef PackageConfBasePackage_Impl * PackageConfBasePackage_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfBasePackage_Impl > PackageConfBasePackage;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfBasePackage_Impl
   *
   * Implementation for the PackageConfBasePackage model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfBasePackage _create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, ComponentPackage_in dst);
    ///@}

    // Default constructor.
    PackageConfBasePackage_Impl (void);

    // Initializing constructor.
    PackageConfBasePackage_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PackageConfBasePackage_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    ///@}
    PackageConfiguration src_PackageConfiguration (void) const;
    ComponentPackage dst_ComponentPackage (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfBasePackage.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFBASEPACKAGE
