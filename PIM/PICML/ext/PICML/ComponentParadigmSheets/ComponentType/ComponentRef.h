// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentRef.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTREF_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTREF_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/Manageable.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentRef_Impl;
  typedef ComponentRef_Impl * ComponentRef_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentRef_Impl > ComponentRef;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentRef_Impl
   *
   * Implementation for the ComponentRef model element.
   */
  class PICML_Export ComponentRef_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual Manageable_Impl
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
    static ComponentRef _create (const Path_in parent);
    static ComponentRef _create (const ComponentImplementationContainer_in parent);
    static ComponentRef _create (const ComponentContainer_in parent);
    static ComponentRef _create (const Package_in parent);
    static ComponentRef _create (const PackageContainer_in parent);
    static ComponentRef _create (const File_in parent);
    ///@}

    // Default constructor.
    ComponentRef_Impl (void);

    // Initializing constructor.
    ComponentRef_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentRef_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Path parent_Path (void);
    ComponentImplementationContainer parent_ComponentImplementationContainer (void);
    ComponentContainer parent_ComponentContainer (void);
    Package parent_Package (void);
    PackageContainer parent_PackageContainer (void);
    File parent_File (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ComponentConfigProperty connection.
    size_t src_ComponentConfigProperty (std::vector <ComponentConfigProperty> & items) const;

    /// Get the src ComponentProperty connection.
    size_t src_ComponentProperty (std::vector <ComponentProperty> & items) const;

    /// Get the src ComponentInfoProperty connection.
    size_t src_ComponentInfoProperty (std::vector <ComponentInfoProperty> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst Implements connection.
    size_t dst_Implements (std::vector <Implements> & items) const;

    /// Get the dst PackageInterface connection.
    size_t dst_PackageInterface (std::vector <PackageInterface> & items) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Component_is_nil (void) const;
    Component get_Component (void) const;
    void set_Component (Component_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentRef.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTREF
