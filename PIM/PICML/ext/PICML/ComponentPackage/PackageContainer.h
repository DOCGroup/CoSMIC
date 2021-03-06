// -*- C++ -*-

//============================================================================
/**
 * @file    PackageContainer.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_PACKAGECONTAINER_H_
#define _PICML_COMPONENTPACKAGE_PACKAGECONTAINER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PackageContainer_Impl;
  typedef PackageContainer_Impl * PackageContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < PackageContainer_Impl > PackageContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class PackageContainer_Impl
   *
   * Implementation for the PackageContainer model element.
   */
  class PICML_Export PackageContainer_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PackageContainer _create (const ComponentPackages_in parent);
    ///@}

    // Default constructor.
    PackageContainer_Impl (void);

    // Initializing constructor.
    PackageContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~PackageContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentPackages parent_ComponentPackages (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_PackageInterface (void) const;
    PackageInterface get_PackageInterface (void) const;

    bool has_ComponentRef (void) const;
    ComponentRef get_ComponentRef (void) const;

    bool has_ComponentPackage (void) const;
    ComponentPackage get_ComponentPackage (void) const;
    size_t get_Implementations (std::vector <Implementation> & items) const;
    ::GAME::Mga::Collection_T <Implementation> get_Implementations (void) const;

    size_t get_ComponentImplementationReferences (std::vector <ComponentImplementationReference> & items) const;
    ::GAME::Mga::Collection_T <ComponentImplementationReference> get_ComponentImplementationReferences (void) const;

    size_t get_PackageInfoPropertys (std::vector <PackageInfoProperty> & items) const;
    ::GAME::Mga::Collection_T <PackageInfoProperty> get_PackageInfoPropertys (void) const;

    size_t get_PackageConfigPropertys (std::vector <PackageConfigProperty> & items) const;
    ::GAME::Mga::Collection_T <PackageConfigProperty> get_PackageConfigPropertys (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PackageContainer.inl"
#endif

#endif  // !defined _PICML_COMPONENTPACKAGE_PACKAGECONTAINER
