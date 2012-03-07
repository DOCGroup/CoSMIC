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
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
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
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ManagesComponent connection.
    size_t src_ManagesComponent (std::vector <ManagesComponent> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_LookupKey (void) const;
    LookupKey get_LookupKey (void) const;
    size_t get_FactoryOperations (std::vector <FactoryOperation> & items) const;
    ::GAME::Mga::Iterator <FactoryOperation> get_FactoryOperations (void) const;

    size_t get_LookupOperations (std::vector <LookupOperation> & items) const;
    ::GAME::Mga::Iterator <LookupOperation> get_LookupOperations (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentFactory.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_COMPONENTFACTORY
