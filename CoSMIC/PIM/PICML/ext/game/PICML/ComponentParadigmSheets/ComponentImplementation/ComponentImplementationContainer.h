// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementationContainer.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONCONTAINER_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONCONTAINER_H_

#include "game/mga/Model.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementationContainer_Impl;
  typedef ComponentImplementationContainer_Impl * ComponentImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementationContainer_Impl> ComponentImplementationContainer;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentImplementationContainer_Impl :
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
    ComponentImplementationContainer_Impl (void);

    /// Initializing constructor
    ComponentImplementationContainer_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ComponentImplementationContainer_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentImplementationContainer _create (const ComponentImplementations_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_CriticalPaths (std::vector <CriticalPath> & items) const;
    size_t get_ComponentImplementations (std::vector <ComponentImplementation> & items) const;

    PathReference get_PathReference (void) const;
    size_t get_Capabilitys (std::vector <Capability> & items) const;
    size_t get_ImplementationCapabilitys (std::vector <ImplementationCapability> & items) const;
    size_t get_ImplementationDependencys (std::vector <ImplementationDependency> & items) const;

    ComponentRef get_ComponentRef (void) const;

    Implements get_Implements (void) const;
    size_t get_ImplementationDependsOns (std::vector <ImplementationDependsOn> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementations parent_ComponentImplementations (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
