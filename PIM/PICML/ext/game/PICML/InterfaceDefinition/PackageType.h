// -*- C++ -*-

//============================================================================
/**
 * @file    PackageType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_PACKAGETYPE_H_
#define _PICML_INTERFACEDEFINITION_PACKAGETYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageType_Impl;
  typedef PackageType_Impl * PackageType_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageType_Impl > PackageType;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageType_Impl
   *
   * Implementation for the PackageType model element.
   */
  class PICML_Export PackageType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageType _create (const TemplatePackageInstance_in parent);
    static PackageType _create (const TemplatePackageAlias_in parent);
    ///@}

    // Default constructor.
    PackageType_Impl (void);

    // Initializing constructor.
    PackageType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~PackageType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TemplatePackageInstance parent_TemplatePackageInstance (void);
    TemplatePackageAlias parent_TemplatePackageAlias (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Package_is_nil (void) const;
    Package get_Package (void) const;
    void set_Package (Package_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PackageType.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_PACKAGETYPE
