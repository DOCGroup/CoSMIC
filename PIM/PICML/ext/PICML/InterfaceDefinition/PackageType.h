// -*- C++ -*-

//============================================================================
/**
 * @file    PackageType.h
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageType _create (const TemplatePackageAlias_in parent);
    static PackageType _create (const TemplatePackageInstance_in parent);
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
    TemplatePackageAlias parent_TemplatePackageAlias (void);
    TemplatePackageInstance parent_TemplatePackageInstance (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Package_is_nil (void) const;
    Package refers_to_Package (void) const;
    void refers_to_Package (Package_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PackageType.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_PACKAGETYPE
