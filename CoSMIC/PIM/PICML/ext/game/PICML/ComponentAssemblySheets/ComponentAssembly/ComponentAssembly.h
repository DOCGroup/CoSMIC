// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentAssembly.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_COMPONENTASSEMBLY_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_COMPONENTASSEMBLY_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentAssembly_Impl;
  typedef ComponentAssembly_Impl * ComponentAssembly_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentAssembly_Impl> ComponentAssembly;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentAssembly_Impl :
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
    ComponentAssembly_Impl (void);

    /// Initializing constructor
    ComponentAssembly_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ComponentAssembly_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentAssembly _create (const ComponentAssembly_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_OutEventPortDelegates (std::vector <OutEventPortDelegate> & items) const;
    size_t get_Requirements (std::vector <Requirement> & items) const;
    size_t get_EventSinkDelegates (std::vector <EventSinkDelegate> & items) const;
    size_t get_AssemblyselectRequirements (std::vector <AssemblyselectRequirement> & items) const;
    size_t get_SendsTos (std::vector <SendsTo> & items) const;
    size_t get_Propertys (std::vector <Property> & items) const;
    size_t get_AttributeValues (std::vector <AttributeValue> & items) const;
    size_t get_AssemblyConfigPropertys (std::vector <AssemblyConfigProperty> & items) const;
    size_t get_ComponentAssemblyReferences (std::vector <ComponentAssemblyReference> & items) const;
    size_t get_AttributeDelegates (std::vector <AttributeDelegate> & items) const;
    size_t get_EventSourceDelegates (std::vector <EventSourceDelegate> & items) const;
    size_t get_MirrorDelegates (std::vector <MirrorDelegate> & items) const;
    size_t get_ConnectorToFacets (std::vector <ConnectorToFacet> & items) const;
    size_t get_ExtendedDelegates (std::vector <ExtendedDelegate> & items) const;
    size_t get_ConnectorInstances (std::vector <ConnectorInstance> & items) const;
    size_t get_ReceptacleDelegates (std::vector <ReceptacleDelegate> & items) const;
    size_t get_Invokes (std::vector <Invoke> & items) const;
    size_t get_ExternalPorts (std::vector <ExternalPort> & items) const;
    size_t get_FacetDelegates (std::vector <FacetDelegate> & items) const;
    size_t get_ProvidedRequestPortDelegates (std::vector <ProvidedRequestPortDelegate> & items) const;
    size_t get_InEventPortDelegates (std::vector <InEventPortDelegate> & items) const;
    size_t get_AttributeMappings (std::vector <AttributeMapping> & items) const;
    size_t get_ExtendedPortDelegates (std::vector <ExtendedPortDelegate> & items) const;
    size_t get_ConnectorToReceptacles (std::vector <ConnectorToReceptacle> & items) const;
    size_t get_ComponentAssemblys (std::vector <ComponentAssembly> & items) const;
    size_t get_MirrorPortDelegates (std::vector <MirrorPortDelegate> & items) const;
    size_t get_RequiredRequestPortDelegates (std::vector <RequiredRequestPortDelegate> & items) const;
    size_t get_ComponentInstances (std::vector <ComponentInstance> & items) const;
    size_t get_ExternalDelegates (std::vector <ExternalDelegate> & items) const;
    size_t get_AttributeMappingValues (std::vector <AttributeMappingValue> & items) const;
    size_t get_ComponentPackages (std::vector <ComponentPackage> & items) const;
    size_t get_Publishs (std::vector <Publish> & items) const;
    size_t get_ComponentPackageReferences (std::vector <ComponentPackageReference> & items) const;
    size_t get_AttributeMappingDelegates (std::vector <AttributeMappingDelegate> & items) const;
    size_t get_Consumes (std::vector <Consume> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
