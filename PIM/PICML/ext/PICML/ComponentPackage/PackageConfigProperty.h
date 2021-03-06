// -*- C++ -*-

//============================================================================
/**
 * @file    PackageConfigProperty.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_PACKAGECONFIGPROPERTY_H_
#define _PICML_COMPONENTPACKAGE_PACKAGECONFIGPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfigProperty_Impl;
  typedef PackageConfigProperty_Impl * PackageConfigProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfigProperty_Impl > PackageConfigProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfigProperty_Impl
   *
   * Implementation for the PackageConfigProperty model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfigProperty _create (const PackageContainer_in parent, ComponentPackage_in src, Property_in dst);
    ///@}

    // Default constructor.
    PackageConfigProperty_Impl (void);

    // Initializing constructor.
    PackageConfigProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PackageConfigProperty_Impl (void);

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
#include "PackageConfigProperty.inl"
#endif

#endif  // !defined _PICML_COMPONENTPACKAGE_PACKAGECONFIGPROPERTY
