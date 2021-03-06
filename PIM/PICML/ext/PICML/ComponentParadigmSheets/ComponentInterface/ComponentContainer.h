// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentContainer.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTCONTAINER_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTCONTAINER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentContainer_Impl;
  typedef ComponentContainer_Impl * ComponentContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentContainer_Impl > ComponentContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentContainer_Impl
   *
   * Implementation for the ComponentContainer model element.
   */
  class PICML_Export ComponentContainer_Impl :
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
    static ComponentContainer _create (const ComponentTypes_in parent);
    ///@}

    // Default constructor.
    ComponentContainer_Impl (void);

    // Initializing constructor.
    ComponentContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ComponentContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentTypes parent_ComponentTypes (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ComponentRef (void) const;
    ComponentRef get_ComponentRef (void) const;
    size_t get_ComponentConfigPropertys (std::vector <ComponentConfigProperty> & items) const;
    ::GAME::Mga::Collection_T <ComponentConfigProperty> get_ComponentConfigPropertys (void) const;

    size_t get_ComponentInfoPropertys (std::vector <ComponentInfoProperty> & items) const;
    ::GAME::Mga::Collection_T <ComponentInfoProperty> get_ComponentInfoPropertys (void) const;

    size_t get_ComponentPropertys (std::vector <ComponentProperty> & items) const;
    ::GAME::Mga::Collection_T <ComponentProperty> get_ComponentPropertys (void) const;

    size_t get_ComponentPropertyDescriptions (std::vector <ComponentPropertyDescription> & items) const;
    ::GAME::Mga::Collection_T <ComponentPropertyDescription> get_ComponentPropertyDescriptions (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentContainer.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMPONENTCONTAINER
