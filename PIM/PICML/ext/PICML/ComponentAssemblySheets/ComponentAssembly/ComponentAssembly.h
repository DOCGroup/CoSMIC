// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentAssembly.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_COMPONENTASSEMBLY_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_COMPONENTASSEMBLY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentAssembly_Impl;
  typedef ComponentAssembly_Impl * ComponentAssembly_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentAssembly_Impl > ComponentAssembly;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentAssembly_Impl
   *
   * Implementation for the ComponentAssembly model element.
   */
  class PICML_Export ComponentAssembly_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual ComponentImplementation_Impl
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
    static ComponentAssembly _create (const ComponentAssembly_in parent);
    static ComponentAssembly _create (const ComponentImplementationContainer_in parent);
    ///@}

    // Default constructor.
    ComponentAssembly_Impl (void);

    // Initializing constructor.
    ComponentAssembly_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ComponentAssembly_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src CriticalPath connection.
    size_t src_of_CriticalPath (std::vector <CriticalPath> & items) const;
    bool has_src_of_CriticalPath (void) const;
    CriticalPath src_of_CriticalPath (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_InEventPortDelegates (std::vector <InEventPortDelegate> & items) const;
    ::GAME::Mga::Collection_T <InEventPortDelegate> get_InEventPortDelegates (void) const;

    size_t get_ConnectorInstances (std::vector <ConnectorInstance> & items) const;
    ::GAME::Mga::Collection_T <ConnectorInstance> get_ConnectorInstances (void) const;

    size_t get_ComponentInstances (std::vector <ComponentInstance> & items) const;
    ::GAME::Mga::Collection_T <ComponentInstance> get_ComponentInstances (void) const;

    size_t get_AttributeMappings (std::vector <AttributeMapping> & items) const;
    ::GAME::Mga::Collection_T <AttributeMapping> get_AttributeMappings (void) const;

    size_t get_ComponentPackageReferences (std::vector <ComponentPackageReference> & items) const;
    ::GAME::Mga::Collection_T <ComponentPackageReference> get_ComponentPackageReferences (void) const;

    size_t get_AttributeValues (std::vector <AttributeValue> & items) const;
    ::GAME::Mga::Collection_T <AttributeValue> get_AttributeValues (void) const;

    size_t get_AttributeMappingDelegates (std::vector <AttributeMappingDelegate> & items) const;
    ::GAME::Mga::Collection_T <AttributeMappingDelegate> get_AttributeMappingDelegates (void) const;

    size_t get_AttributeDelegates (std::vector <AttributeDelegate> & items) const;
    ::GAME::Mga::Collection_T <AttributeDelegate> get_AttributeDelegates (void) const;

    size_t get_AttributeMappingValues (std::vector <AttributeMappingValue> & items) const;
    ::GAME::Mga::Collection_T <AttributeMappingValue> get_AttributeMappingValues (void) const;

    size_t get_ComponentAssemblys (std::vector <ComponentAssembly> & items) const;
    ::GAME::Mga::Collection_T <ComponentAssembly> get_ComponentAssemblys (void) const;

    size_t get_Requirements (std::vector <Requirement> & items) const;
    ::GAME::Mga::Collection_T <Requirement> get_Requirements (void) const;

    size_t get_RTRequirementss (std::vector <RTRequirements> & items) const;
    ::GAME::Mga::Collection_T <RTRequirements> get_RTRequirementss (void) const;

    size_t get_ECRequirementss (std::vector <ECRequirements> & items) const;
    ::GAME::Mga::Collection_T <ECRequirements> get_ECRequirementss (void) const;

    size_t get_ExternalDelegates (std::vector <ExternalDelegate> & items) const;
    ::GAME::Mga::Collection_T <ExternalDelegate> get_ExternalDelegates (void) const;

    size_t get_ComponentAssemblyReferences (std::vector <ComponentAssemblyReference> & items) const;
    ::GAME::Mga::Collection_T <ComponentAssemblyReference> get_ComponentAssemblyReferences (void) const;

    size_t get_AssemblyConfigPropertys (std::vector <AssemblyConfigProperty> & items) const;
    ::GAME::Mga::Collection_T <AssemblyConfigProperty> get_AssemblyConfigPropertys (void) const;

    size_t get_AssemblyselectRequirements (std::vector <AssemblyselectRequirement> & items) const;
    ::GAME::Mga::Collection_T <AssemblyselectRequirement> get_AssemblyselectRequirements (void) const;

    size_t get_ProvidedRequestPortDelegates (std::vector <ProvidedRequestPortDelegate> & items) const;
    ::GAME::Mga::Collection_T <ProvidedRequestPortDelegate> get_ProvidedRequestPortDelegates (void) const;

    size_t get_RequiredRequestPortDelegates (std::vector <RequiredRequestPortDelegate> & items) const;
    ::GAME::Mga::Collection_T <RequiredRequestPortDelegate> get_RequiredRequestPortDelegates (void) const;

    size_t get_MirrorPortDelegates (std::vector <MirrorPortDelegate> & items) const;
    ::GAME::Mga::Collection_T <MirrorPortDelegate> get_MirrorPortDelegates (void) const;

    size_t get_ExtendedPortDelegates (std::vector <ExtendedPortDelegate> & items) const;
    ::GAME::Mga::Collection_T <ExtendedPortDelegate> get_ExtendedPortDelegates (void) const;

    size_t get_OutEventPortDelegates (std::vector <OutEventPortDelegate> & items) const;
    ::GAME::Mga::Collection_T <OutEventPortDelegate> get_OutEventPortDelegates (void) const;

    size_t get_ExtendedDelegates (std::vector <ExtendedDelegate> & items) const;
    ::GAME::Mga::Collection_T <ExtendedDelegate> get_ExtendedDelegates (void) const;

    size_t get_EventSourceDelegates (std::vector <EventSourceDelegate> & items) const;
    ::GAME::Mga::Collection_T <EventSourceDelegate> get_EventSourceDelegates (void) const;

    size_t get_SendsTos (std::vector <SendsTo> & items) const;
    ::GAME::Mga::Collection_T <SendsTo> get_SendsTos (void) const;

    size_t get_EventSinkDelegates (std::vector <EventSinkDelegate> & items) const;
    ::GAME::Mga::Collection_T <EventSinkDelegate> get_EventSinkDelegates (void) const;

    size_t get_FacetDelegates (std::vector <FacetDelegate> & items) const;
    ::GAME::Mga::Collection_T <FacetDelegate> get_FacetDelegates (void) const;

    size_t get_Invokes (std::vector <Invoke> & items) const;
    ::GAME::Mga::Collection_T <Invoke> get_Invokes (void) const;

    size_t get_ConnectorToReceptacles (std::vector <ConnectorToReceptacle> & items) const;
    ::GAME::Mga::Collection_T <ConnectorToReceptacle> get_ConnectorToReceptacles (void) const;

    size_t get_ReceptacleDelegates (std::vector <ReceptacleDelegate> & items) const;
    ::GAME::Mga::Collection_T <ReceptacleDelegate> get_ReceptacleDelegates (void) const;

    size_t get_MirrorDelegates (std::vector <MirrorDelegate> & items) const;
    ::GAME::Mga::Collection_T <MirrorDelegate> get_MirrorDelegates (void) const;

    size_t get_Publishs (std::vector <Publish> & items) const;
    ::GAME::Mga::Collection_T <Publish> get_Publishs (void) const;

    size_t get_Consumes (std::vector <Consume> & items) const;
    ::GAME::Mga::Collection_T <Consume> get_Consumes (void) const;

    size_t get_ConnectorToFacets (std::vector <ConnectorToFacet> & items) const;
    ::GAME::Mga::Collection_T <ConnectorToFacet> get_ConnectorToFacets (void) const;

    size_t get_ExternalPorts (std::vector <ExternalPort> & items) const;
    ::GAME::Mga::Collection_T <ExternalPort> get_ExternalPorts (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_ComponentPackages (std::vector <ComponentPackage> & items) const;
    ::GAME::Mga::Collection_T <ComponentPackage> get_ComponentPackages (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentAssembly.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_COMPONENTASSEMBLY
