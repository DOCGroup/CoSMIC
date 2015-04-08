// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementationContainer.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONCONTAINER_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONCONTAINER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementationContainer_Impl;
  typedef ComponentImplementationContainer_Impl * ComponentImplementationContainer_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentImplementationContainer_Impl > ComponentImplementationContainer;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentImplementationContainer_Impl
   *
   * Implementation for the ComponentImplementationContainer model element.
   */
  class PICML_Export ComponentImplementationContainer_Impl :
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentImplementationContainer _create (const ComponentImplementations_in parent);
    ///@}

    // Default constructor.
    ComponentImplementationContainer_Impl (void);

    // Initializing constructor.
    ComponentImplementationContainer_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ComponentImplementationContainer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementations parent_ComponentImplementations (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_Implements (void) const;
    Implements get_Implements (void) const;

    bool has_ComponentRef (void) const;
    ComponentRef get_ComponentRef (void) const;

    bool has_PathReference (void) const;
    PathReference get_PathReference (void) const;
    size_t get_Capabilitys (std::vector <Capability> & items) const;
    ::GAME::Mga::Collection_T <Capability> get_Capabilitys (void) const;

    size_t get_ImplementationDependencys (std::vector <ImplementationDependency> & items) const;
    ::GAME::Mga::Collection_T <ImplementationDependency> get_ImplementationDependencys (void) const;

    size_t get_ImplementationCapabilitys (std::vector <ImplementationCapability> & items) const;
    ::GAME::Mga::Collection_T <ImplementationCapability> get_ImplementationCapabilitys (void) const;

    size_t get_CriticalPaths (std::vector <CriticalPath> & items) const;
    ::GAME::Mga::Collection_T <CriticalPath> get_CriticalPaths (void) const;

    size_t get_ImplementationDependsOns (std::vector <ImplementationDependsOn> & items) const;
    ::GAME::Mga::Collection_T <ImplementationDependsOn> get_ImplementationDependsOns (void) const;

    size_t get_MonolithicImplementations (std::vector <MonolithicImplementation> & items) const;
    ::GAME::Mga::Collection_T <MonolithicImplementation> get_MonolithicImplementations (void) const;

    size_t get_ComponentAssemblys (std::vector <ComponentAssembly> & items) const;
    ::GAME::Mga::Collection_T <ComponentAssembly> get_ComponentAssemblys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentImplementationContainer.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONCONTAINER
