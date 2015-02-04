// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentFactory.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTFACTORY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTFACTORY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/SupportsInterfaces.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentFactory_Impl;
  typedef ComponentFactory_Impl * ComponentFactory_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentFactory_Impl > ComponentFactory;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentFactory_Impl
   *
   * Implementation for the ComponentFactory model element.
   */
  class PICML_Export ComponentFactory_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual HasOperations_Impl,
    public virtual SupportsInterfaces_Impl
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
    static ComponentFactory _create (const Package_in parent);
    static ComponentFactory _create (const File_in parent);
    ///@}

    // Default constructor.
    ComponentFactory_Impl (void);

    // Initializing constructor.
    ComponentFactory_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ComponentFactory_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ManagesComponent connection.
    size_t src_of_ManagesComponent (std::vector <ManagesComponent> & items) const;
    GAME::Mga::Collection_T <ManagesComponent> src_of_ManagesComponent (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_LookupKey (void) const;
    LookupKey get_LookupKey (void) const;
    size_t get_LookupOperations (std::vector <LookupOperation> & items) const;
    ::GAME::Mga::Collection_T <LookupOperation> get_LookupOperations (void) const;

    size_t get_FactoryOperations (std::vector <FactoryOperation> & items) const;
    ::GAME::Mga::Collection_T <FactoryOperation> get_FactoryOperations (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentFactory.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTFACTORY
