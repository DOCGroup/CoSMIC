// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentFactoryInstance.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYINSTANCE_H_
#define _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentFactoryInstance_Impl;
  typedef ComponentFactoryInstance_Impl * ComponentFactoryInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentFactoryInstance_Impl > ComponentFactoryInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentFactoryInstance_Impl
   *
   * Implementation for the ComponentFactoryInstance model element.
   */
  class PICML_Export ComponentFactoryInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual MonolithicImplementationBase_Impl
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
    static ComponentFactoryInstance _create (const ComponentFactoryImplementationContainer_in parent);
    ///@}

    // Default constructor.
    ComponentFactoryInstance_Impl (void);

    // Initializing constructor.
    ComponentFactoryInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentFactoryInstance_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentFactoryImplementationContainer parent_ComponentFactoryImplementationContainer (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ComponentFactory_is_nil (void) const;
    ComponentFactory refers_to_ComponentFactory (void) const;
    void refers_to_ComponentFactory (ComponentFactory_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentFactoryInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYINSTANCE
