// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigPropertyEnd.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentInstance_Impl;
  typedef ComponentInstance_Impl * ComponentInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentInstance_Impl > ComponentInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentInstance_Impl
   *
   * Implementation for the ComponentInstance model element.
   */
  class PICML_Export ComponentInstance_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual AssemblyConfigPropertyEnd_Impl
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
    static ComponentInstance _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    ComponentInstance_Impl (void);

    // Initializing constructor.
    ComponentInstance_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ComponentInstance_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of UUID
    void UUID (const std::string & val);

    /// Get the value of UUID
    std::string UUID (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ComponentInstanceType (void) const;
    ComponentInstanceType get_ComponentInstanceType (void) const;
    size_t get_AttributeInstances (std::vector <AttributeInstance> & items) const;
    ::GAME::Mga::Collection_T <AttributeInstance> get_AttributeInstances (void) const;

    size_t get_RequiredRequestPortInstances (std::vector <RequiredRequestPortInstance> & items) const;
    ::GAME::Mga::Collection_T <RequiredRequestPortInstance> get_RequiredRequestPortInstances (void) const;

    size_t get_InEventPortInstances (std::vector <InEventPortInstance> & items) const;
    ::GAME::Mga::Collection_T <InEventPortInstance> get_InEventPortInstances (void) const;

    size_t get_ProvidedRequestPortInstances (std::vector <ProvidedRequestPortInstance> & items) const;
    ::GAME::Mga::Collection_T <ProvidedRequestPortInstance> get_ProvidedRequestPortInstances (void) const;

    size_t get_OutEventPortInstances (std::vector <OutEventPortInstance> & items) const;
    ::GAME::Mga::Collection_T <OutEventPortInstance> get_OutEventPortInstances (void) const;

    size_t get_MirrorPortInstances (std::vector <MirrorPortInstance> & items) const;
    ::GAME::Mga::Collection_T <MirrorPortInstance> get_MirrorPortInstances (void) const;

    size_t get_ExtendedPortInstances (std::vector <ExtendedPortInstance> & items) const;
    ::GAME::Mga::Collection_T <ExtendedPortInstance> get_ExtendedPortInstances (void) const;

    size_t get_SupportsInstances (std::vector <SupportsInstance> & items) const;
    ::GAME::Mga::Collection_T <SupportsInstance> get_SupportsInstances (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_COMPONENTINSTANCE
