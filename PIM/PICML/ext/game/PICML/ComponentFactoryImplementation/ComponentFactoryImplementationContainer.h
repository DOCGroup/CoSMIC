// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentFactoryImplementationContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYIMPLEMENTATIONCONTAINER_H_
#define _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYIMPLEMENTATIONCONTAINER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentFactoryImplementationContainer_Impl;
  typedef ComponentFactoryImplementationContainer_Impl * ComponentFactoryImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentFactoryImplementationContainer_Impl > ComponentFactoryImplementationContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentFactoryImplementationContainer_Impl
   *
   * Implementation for the ComponentFactoryImplementationContainer model element.
   */
  class PICML_Export ComponentFactoryImplementationContainer_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual ImplementationContainer_Impl
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
    static ComponentFactoryImplementationContainer _create (const ComponentFactoryImplementations_in parent);
    ///@}

    // Default constructor.
    ComponentFactoryImplementationContainer_Impl (void);

    // Initializing constructor.
    ComponentFactoryImplementationContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ComponentFactoryImplementationContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentFactoryImplementations parent_ComponentFactoryImplementations (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComponentFactoryInstances (std::vector <ComponentFactoryInstance> & items) const;
    ::GAME::Mga::Iterator <ComponentFactoryInstance> get_ComponentFactoryInstances (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentFactoryImplementationContainer.inl"
#endif

#endif  // !defined _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYIMPLEMENTATIONCONTAINER
