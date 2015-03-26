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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageConfReference_Impl;
  typedef PackageConfReference_Impl * PackageConfReference_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageConfReference_Impl > PackageConfReference;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageConfReference_Impl
   *
   * Implementation for the PackageConfReference model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageConfReference _create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, ComponentPackageReference_in dst);
    ///@}

    // Default constructor.
    PackageConfReference_Impl (void);

    // Initializing constructor.
    PackageConfReference_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PackageConfReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    ///@}
    PackageConfiguration src_PackageConfiguration (void) const;
    ComponentPackageReference dst_ComponentPackageReference (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PackageConfReference.inl"
#endif

#endif  // !defined _PICML_PACKAGECONFIGURATION_PACKAGECONFREFERENCE
