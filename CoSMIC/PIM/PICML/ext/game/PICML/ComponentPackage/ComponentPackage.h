// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentPackage.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_COMPONENTPACKAGE_H_
#define _PICML_COMPONENTPACKAGE_COMPONENTPACKAGE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentPackage_Impl;
  typedef ComponentPackage_Impl * ComponentPackage_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentPackage_Impl > ComponentPackage;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentPackage_Impl
   *
   * Implementation for the ComponentPackage model element.
   */
  class PICML_Export ComponentPackage_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentPackage _create (const ComponentAssembly_in parent);
    static ComponentPackage _create (const PackageContainer_in parent);
    static ComponentPackage _create (const PackageConfigurationContainer_in parent);
    ///@}

    // Default constructor.
    ComponentPackage_Impl (void);

    // Initializing constructor.
    ComponentPackage_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ComponentPackage_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of UUID
    void UUID (const std::string & val);

    /// Get the value of UUID
    std::string UUID (void) const;

    /// Set the value of label
    void label (const std::string & val);

    /// Get the value of label
    std::string label (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src PackageInterface connection.
    size_t src_PackageInterface (std::vector <PackageInterface> & items) const;

    /// Get the src Implementation connection.
    size_t src_Implementation (std::vector <Implementation> & items) const;

    /// Get the src PackageConfigProperty connection.
    size_t src_PackageConfigProperty (std::vector <PackageConfigProperty> & items) const;

    /// Get the src PackageInfoProperty connection.
    size_t src_PackageInfoProperty (std::vector <PackageInfoProperty> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst PackageConfBasePackage connection.
    size_t dst_PackageConfBasePackage (std::vector <PackageConfBasePackage> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentPackage.inl"
#endif

#endif  // !defined _PICML_COMPONENTPACKAGE_COMPONENTPACKAGE
