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

#include "game/mga/Model.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentFactoryImplementationContainer_Impl;
  typedef ComponentFactoryImplementationContainer_Impl * ComponentFactoryImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentFactoryImplementationContainer_Impl> ComponentFactoryImplementationContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentFactoryImplementationContainer_Impl :
    public virtual ImplementationContainer_Impl,
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentFactoryImplementationContainer_Impl (void);

    /// Initializing constructor
    ComponentFactoryImplementationContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ComponentFactoryImplementationContainer_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentFactoryImplementationContainer _create (const ComponentFactoryImplementations_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComponentFactoryInstances (std::vector <ComponentFactoryInstance> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentFactoryImplementations parent_ComponentFactoryImplementations (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
