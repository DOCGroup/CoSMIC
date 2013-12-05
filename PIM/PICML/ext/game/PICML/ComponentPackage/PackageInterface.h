// -*- C++ -*-

//============================================================================
/**
 * @file    PackageInterface.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_PACKAGEINTERFACE_H_
#define _PICML_COMPONENTPACKAGE_PACKAGEINTERFACE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageInterface_Impl;
  typedef PackageInterface_Impl * PackageInterface_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageInterface_Impl > PackageInterface;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageInterface_Impl
   *
   * Implementation for the PackageInterface model element.
   */
  class PICML_Export PackageInterface_Impl :
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
    static PackageInterface _create (const PackageContainer_in parent);
    ///@}

    // Default constructor.
    PackageInterface_Impl (void);

    // Initializing constructor.
    PackageInterface_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PackageInterface_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageContainer parent_PackageContainer (void);
    ///@}
    ComponentPackage src_ComponentPackage (void) const;
    ComponentRef dst_ComponentRef (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PackageInterface.inl"
#endif

#endif  // !defined _PICML_COMPONENTPACKAGE_PACKAGEINTERFACE
