// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentPackageReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPACKAGE_COMPONENTPACKAGEREFERENCE_H_
#define _PICML_COMPONENTPACKAGE_COMPONENTPACKAGEREFERENCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentPackageReference_Impl;
  typedef ComponentPackageReference_Impl * ComponentPackageReference_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentPackageReference_Impl > ComponentPackageReference;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentPackageReference_Impl
   *
   * Implementation for the ComponentPackageReference model element.
   */
  class PICML_Export ComponentPackageReference_Impl :
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
    static ComponentPackageReference _create (const ComponentAssembly_in parent);
    static ComponentPackageReference _create (const PackageConfigurationContainer_in parent);
    ///@}

    // Default constructor.
    ComponentPackageReference_Impl (void);

    // Initializing constructor.
    ComponentPackageReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentPackageReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    PackageConfigurationContainer parent_PackageConfigurationContainer (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of requiredUUID
    void requiredUUID (const std::string & val);

    /// Get the value of requiredUUID
    std::string requiredUUID (void) const;

    /// Set the value of requiredName
    void requiredName (const std::string & val);

    /// Get the value of requiredName
    std::string requiredName (void) const;

    /// Set the value of requiredType
    void requiredType (const std::string & val);

    /// Get the value of requiredType
    std::string requiredType (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst PackageConfReference connection.
    size_t dst_of_PackageConfReference (std::vector <PackageConfReference> & items) const;
    GAME::Mga::Collection_T <PackageConfReference> dst_of_PackageConfReference (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ComponentPackage_is_nil (void) const;
    ComponentPackage refers_to_ComponentPackage (void) const;
    void refers_to_ComponentPackage (ComponentPackage_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentPackageReference.inl"
#endif

#endif  // !defined _PICML_COMPONENTPACKAGE_COMPONENTPACKAGEREFERENCE
