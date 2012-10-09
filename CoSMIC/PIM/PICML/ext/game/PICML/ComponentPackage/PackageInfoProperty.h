// -*- C++ -*-

//============================================================================
/**
 * @file    PackageInfoProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_PACKAGEINFOPROPERTY_H_
#define _PICML_COMPONENTPACKAGE_PACKAGEINFOPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageInfoProperty_Impl;
  typedef PackageInfoProperty_Impl * PackageInfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageInfoProperty_Impl > PackageInfoProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageInfoProperty_Impl
   *
   * Implementation for the PackageInfoProperty model element.
   */
  class PICML_Export PackageInfoProperty_Impl :
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
    static PackageInfoProperty _create (const PackageContainer_in parent);
    ///@}

    // Default constructor.
    PackageInfoProperty_Impl (void);

    // Initializing constructor.
    PackageInfoProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PackageInfoProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageContainer parent_PackageContainer (void);
    ///@}
    ComponentPackage src_ComponentPackage (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PackageInfoProperty.inl"
#endif

#endif  // !defined _PICML_COMPONENTPACKAGE_PACKAGEINFOPROPERTY
