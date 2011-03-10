// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentFactoryInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYINSTANCE_H_
#define _PICML_COMPONENTFACTORYIMPLEMENTATION_COMPONENTFACTORYINSTANCE_H_

#include "game/mga/Reference.h"
#include "PICML/ImplementationCommon/MonolithicImplementationBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentFactoryInstance_Impl;
  typedef ComponentFactoryInstance_Impl * ComponentFactoryInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentFactoryInstance_Impl> ComponentFactoryInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentFactoryInstance_Impl :
    public virtual MonolithicImplementationBase_Impl,
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ComponentFactoryInstance_Impl (void);

    /// Initializing constructor
    ComponentFactoryInstance_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComponentFactoryInstance_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentFactoryInstance _create (const ComponentFactoryImplementationContainer_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentFactoryImplementationContainer parent_ComponentFactoryImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
