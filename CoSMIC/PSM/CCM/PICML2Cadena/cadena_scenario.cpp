// cpp(meta datanetwork format) source file cadena_scenario.cpp generated from diagram cadena-scenario
// generated on Thu Apr 22 00:47:38 2004

#include "cadena_scenario.h"
#include "UmlExt.h"

#include "UdmStatic.h"

namespace cadena_scenario {

	Uml::Diagram umldiagram;

	Uml::Class ScenarioElement::meta;
	Uml::Class PortConnection::meta;
	Uml::Class Scenario::meta;
	Uml::Class ComponentInstance::meta;
	Uml::Class Property::meta;
	Uml::Class ComponentPort::meta;
	Uml::Class Facet::meta;
	Uml::Class Receptacle::meta;
	Uml::Class EventSource::meta;
	Uml::Class EventSink::meta;
	Uml::Class FRConnection::meta;
	Uml::Class ESSConnection::meta;
	Uml::Attribute ComponentInstance::meta_type;
	Uml::Attribute ComponentInstance::meta_name;
	Uml::Attribute Property::meta_value;
	Uml::Attribute Property::meta_name;
	Uml::Attribute Property::meta_type;
	Uml::Attribute ComponentPort::meta_Name;
	Uml::Attribute ESSConnection::meta_Correlator;
	Uml::AssociationRole Facet::meta_receptacles, Facet::meta_receptacles_rev;
	Uml::AssociationRole Receptacle::meta_facets, Receptacle::meta_facets_rev;
	Uml::AssociationRole EventSource::meta_sinksConnections;
	Uml::AssociationRole EventSink::meta_sourcesConnections;
	Uml::AssociationRole FRConnection::meta_facets_end_;
	Uml::AssociationRole FRConnection::meta_receptacles_end_;
	Uml::AssociationRole ESSConnection::meta_sources;
	Uml::AssociationRole ESSConnection::meta_sinks;
	Uml::CompositionParentRole PortConnection::meta_Scenario_parent;
	Uml::CompositionParentRole ComponentInstance::meta_Scenario_parent;
	Uml::CompositionParentRole Property::meta_properties_ScenarioElement_parent;
	Uml::CompositionParentRole ComponentPort::meta_ComponentInstance_parent;
	Uml::CompositionChildRole ScenarioElement::meta_properties;
	Uml::CompositionChildRole Scenario::meta_PortConnection_children;
	Uml::CompositionChildRole Scenario::meta_ComponentInstance_children;
	Uml::CompositionChildRole ComponentInstance::meta_ComponentPort_children;
	void Initialize()
	{
		static bool first = true;
		if(!first) return;
		first = false;
		 Uml::Initialize();

		ASSERT( umldiagram == Udm::null );
		UdmStatic::StaticDataNetwork * meta_dn = new UdmStatic::StaticDataNetwork(Uml::diagram);
		meta_dn->CreateNew("cadena_scenario.mem", "", Uml::Diagram::meta, Udm::CHANGES_LOST_DEFAULT);
		umldiagram = Uml::Diagram::Cast(meta_dn->GetRootObject());
		umldiagram.name() ="cadena_scenario";
		ScenarioElement::meta = Uml::Class::Create(umldiagram);
		PortConnection::meta = Uml::Class::Create(umldiagram);
		Scenario::meta = Uml::Class::Create(umldiagram);
		ComponentInstance::meta = Uml::Class::Create(umldiagram);
		Property::meta = Uml::Class::Create(umldiagram);
		ComponentPort::meta = Uml::Class::Create(umldiagram);
		Facet::meta = Uml::Class::Create(umldiagram);
		Receptacle::meta = Uml::Class::Create(umldiagram);
		EventSource::meta = Uml::Class::Create(umldiagram);
		EventSink::meta = Uml::Class::Create(umldiagram);
		FRConnection::meta = Uml::Class::Create(umldiagram);
		ESSConnection::meta = Uml::Class::Create(umldiagram);
		ComponentInstance::meta_type = Uml::Attribute::Create(ComponentInstance::meta);
		ComponentInstance::meta_name = Uml::Attribute::Create(ComponentInstance::meta);
		Property::meta_value = Uml::Attribute::Create(Property::meta);
		Property::meta_name = Uml::Attribute::Create(Property::meta);
		Property::meta_type = Uml::Attribute::Create(Property::meta);
		ComponentPort::meta_Name = Uml::Attribute::Create(ComponentPort::meta);
		ESSConnection::meta_Correlator = Uml::Attribute::Create(ESSConnection::meta);
		Uml::InitDiagram(umldiagram, "cadena_scenario");

		ScenarioElement::meta.name() = "ScenarioElement";
		ScenarioElement::meta.isAbstract() = true;
		PortConnection::meta.name() = "PortConnection";
		PortConnection::meta.isAbstract() = false;
		Scenario::meta.name() = "Scenario";
		Scenario::meta.isAbstract() = false;
		ComponentInstance::meta.name() = "ComponentInstance";
		ComponentInstance::meta.isAbstract() = false;
		Property::meta.name() = "Property";
		Property::meta.isAbstract() = false;
		ComponentPort::meta.name() = "ComponentPort";
		ComponentPort::meta.isAbstract() = false;
		Facet::meta.name() = "Facet";
		Facet::meta.isAbstract() = false;
		Receptacle::meta.name() = "Receptacle";
		Receptacle::meta.isAbstract() = false;
		EventSource::meta.name() = "EventSource";
		EventSource::meta.isAbstract() = false;
		EventSink::meta.name() = "EventSink";
		EventSink::meta.isAbstract() = false;
		FRConnection::meta.name() = "FRConnection";
		FRConnection::meta.isAbstract() = false;
		ESSConnection::meta.name() = "ESSConnection";
		ESSConnection::meta.isAbstract() = false;
		
		ComponentInstance::meta_type.name() = "type";
		ComponentInstance::meta_type.type() = "String";
		ComponentInstance::meta_type.min() = 1;
		ComponentInstance::meta_type.max() = 1;
		ComponentInstance::meta_type.nonpersistent() = false;
		ComponentInstance::meta_type.registry() = false;
		ComponentInstance::meta_type.ordered() = false;
		ComponentInstance::meta_type.visibility() = "public";
		ComponentInstance::meta_type.defvalue() = vector<string>();
		ComponentInstance::meta_name.name() = "name";
		ComponentInstance::meta_name.type() = "String";
		ComponentInstance::meta_name.min() = 1;
		ComponentInstance::meta_name.max() = 1;
		ComponentInstance::meta_name.nonpersistent() = false;
		ComponentInstance::meta_name.registry() = false;
		ComponentInstance::meta_name.ordered() = false;
		ComponentInstance::meta_name.visibility() = "public";
		ComponentInstance::meta_name.defvalue() = vector<string>();
		Property::meta_value.name() = "value";
		Property::meta_value.type() = "String";
		Property::meta_value.min() = 1;
		Property::meta_value.max() = 1;
		Property::meta_value.nonpersistent() = false;
		Property::meta_value.registry() = false;
		Property::meta_value.ordered() = false;
		Property::meta_value.visibility() = "public";
		Property::meta_value.defvalue() = vector<string>();
		Property::meta_name.name() = "name";
		Property::meta_name.type() = "String";
		Property::meta_name.min() = 1;
		Property::meta_name.max() = 1;
		Property::meta_name.nonpersistent() = false;
		Property::meta_name.registry() = false;
		Property::meta_name.ordered() = false;
		Property::meta_name.visibility() = "public";
		Property::meta_name.defvalue() = vector<string>();
		Property::meta_type.name() = "type";
		Property::meta_type.type() = "String";
		Property::meta_type.min() = 1;
		Property::meta_type.max() = 1;
		Property::meta_type.nonpersistent() = false;
		Property::meta_type.registry() = false;
		Property::meta_type.ordered() = false;
		Property::meta_type.visibility() = "public";
		Property::meta_type.defvalue() = vector<string>();
		ComponentPort::meta_Name.name() = "Name";
		ComponentPort::meta_Name.type() = "String";
		ComponentPort::meta_Name.min() = 1;
		ComponentPort::meta_Name.max() = 1;
		ComponentPort::meta_Name.nonpersistent() = false;
		ComponentPort::meta_Name.registry() = false;
		ComponentPort::meta_Name.ordered() = false;
		ComponentPort::meta_Name.visibility() = "public";
		ComponentPort::meta_Name.defvalue() = vector<string>();
		ESSConnection::meta_Correlator.name() = "Correlator";
		ESSConnection::meta_Correlator.type() = "String";
		ESSConnection::meta_Correlator.min() = 1;
		ESSConnection::meta_Correlator.max() = 1;
		ESSConnection::meta_Correlator.nonpersistent() = false;
		ESSConnection::meta_Correlator.registry() = false;
		ESSConnection::meta_Correlator.ordered() = false;
		ESSConnection::meta_Correlator.visibility() = "public";
		ESSConnection::meta_Correlator.defvalue() = vector<string>();
		
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ass.name() = "FRConnection";
			ass.assocClass() = FRConnection::meta;
			Facet::meta_receptacles = Uml::AssociationRole::Create(ass);
			Facet::meta_receptacles.name() = "receptacles";
			Facet::meta_receptacles.min() = 0;
			Facet::meta_receptacles.max() = -1;
			Facet::meta_receptacles.isNavigable() = true;
			Facet::meta_receptacles.isPrimary() = false;
			Facet::meta_receptacles.target() = Receptacle::meta;
			FRConnection::meta_receptacles_end_ = Receptacle::meta_facets_rev = Facet::meta_receptacles;
			Receptacle::meta_facets = Uml::AssociationRole::Create(ass);
			Receptacle::meta_facets.name() = "facets";
			Receptacle::meta_facets.min() = 0;
			Receptacle::meta_facets.max() = -1;
			Receptacle::meta_facets.isNavigable() = true;
			Receptacle::meta_facets.isPrimary() = false;
			Receptacle::meta_facets.target() = Facet::meta;
			FRConnection::meta_facets_end_ = Facet::meta_receptacles_rev = Receptacle::meta_facets;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ESSConnection::meta_sources = Uml::AssociationRole::Create(ass);
			ESSConnection::meta_sources.name() = "sources";
			ESSConnection::meta_sources.min() = 0;
			ESSConnection::meta_sources.max() = -1;
			ESSConnection::meta_sources.isNavigable() = true;
			ESSConnection::meta_sources.isPrimary() = false;
			ESSConnection::meta_sources.target() = EventSource::meta;
			EventSource::meta_sinksConnections = Uml::AssociationRole::Create(ass);
			EventSource::meta_sinksConnections.name() = "sinksConnections";
			EventSource::meta_sinksConnections.min() = 0;
			EventSource::meta_sinksConnections.max() = -1;
			EventSource::meta_sinksConnections.isNavigable() = true;
			EventSource::meta_sinksConnections.isPrimary() = false;
			EventSource::meta_sinksConnections.target() = ESSConnection::meta;
		}
		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			EventSink::meta_sourcesConnections = Uml::AssociationRole::Create(ass);
			EventSink::meta_sourcesConnections.name() = "sourcesConnections";
			EventSink::meta_sourcesConnections.min() = 0;
			EventSink::meta_sourcesConnections.max() = -1;
			EventSink::meta_sourcesConnections.isNavigable() = true;
			EventSink::meta_sourcesConnections.isPrimary() = false;
			EventSink::meta_sourcesConnections.target() = ESSConnection::meta;
			ESSConnection::meta_sinks = Uml::AssociationRole::Create(ass);
			ESSConnection::meta_sinks.name() = "sinks";
			ESSConnection::meta_sinks.min() = 0;
			ESSConnection::meta_sinks.max() = -1;
			ESSConnection::meta_sinks.isNavigable() = true;
			ESSConnection::meta_sinks.isPrimary() = false;
			ESSConnection::meta_sinks.target() = EventSink::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Property::meta_properties_ScenarioElement_parent = Uml::CompositionParentRole::Create(comp);
			Property::meta_properties_ScenarioElement_parent.name() = "properties_ScenarioElement_parent";
			Property::meta_properties_ScenarioElement_parent.isNavigable() = true;
			Property::meta_properties_ScenarioElement_parent.target() = ScenarioElement::meta;
			ScenarioElement::meta_properties = Uml::CompositionChildRole::Create(comp);
			ScenarioElement::meta_properties.name() = "properties";
			ScenarioElement::meta_properties.min() = 0;
			ScenarioElement::meta_properties.max() = -1;
			ScenarioElement::meta_properties.isNavigable() = true;
			ScenarioElement::meta_properties.target() = Property::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			PortConnection::meta_Scenario_parent = Uml::CompositionParentRole::Create(comp);
			PortConnection::meta_Scenario_parent.name() = "Scenario_parent";
			PortConnection::meta_Scenario_parent.isNavigable() = true;
			PortConnection::meta_Scenario_parent.target() = Scenario::meta;
			Scenario::meta_PortConnection_children = Uml::CompositionChildRole::Create(comp);
			Scenario::meta_PortConnection_children.name() = "PortConnection";
			Scenario::meta_PortConnection_children.min() = 0;
			Scenario::meta_PortConnection_children.max() = -1;
			Scenario::meta_PortConnection_children.isNavigable() = true;
			Scenario::meta_PortConnection_children.target() = PortConnection::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentInstance::meta_Scenario_parent = Uml::CompositionParentRole::Create(comp);
			ComponentInstance::meta_Scenario_parent.name() = "Scenario_parent";
			ComponentInstance::meta_Scenario_parent.isNavigable() = true;
			ComponentInstance::meta_Scenario_parent.target() = Scenario::meta;
			Scenario::meta_ComponentInstance_children = Uml::CompositionChildRole::Create(comp);
			Scenario::meta_ComponentInstance_children.name() = "ComponentInstance";
			Scenario::meta_ComponentInstance_children.min() = 0;
			Scenario::meta_ComponentInstance_children.max() = -1;
			Scenario::meta_ComponentInstance_children.isNavigable() = true;
			Scenario::meta_ComponentInstance_children.target() = ComponentInstance::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPort::meta_ComponentInstance_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPort::meta_ComponentInstance_parent.name() = "ComponentInstance_parent";
			ComponentPort::meta_ComponentInstance_parent.isNavigable() = true;
			ComponentPort::meta_ComponentInstance_parent.target() = ComponentInstance::meta;
			ComponentInstance::meta_ComponentPort_children = Uml::CompositionChildRole::Create(comp);
			ComponentInstance::meta_ComponentPort_children.name() = "ComponentPort";
			ComponentInstance::meta_ComponentPort_children.min() = 0;
			ComponentInstance::meta_ComponentPort_children.max() = -1;
			ComponentInstance::meta_ComponentPort_children.isNavigable() = true;
			ComponentInstance::meta_ComponentPort_children.target() = ComponentPort::meta;
		}
		ScenarioElement::meta.subTypes() +=  PortConnection::meta;
		ScenarioElement::meta.subTypes() +=  Scenario::meta;
		ScenarioElement::meta.subTypes() +=  ComponentInstance::meta;
		PortConnection::meta.subTypes() +=  FRConnection::meta;
		PortConnection::meta.subTypes() +=  ESSConnection::meta;
		ComponentPort::meta.subTypes() +=  Facet::meta;
		ComponentPort::meta.subTypes() +=  Receptacle::meta;
		ComponentPort::meta.subTypes() +=  EventSource::meta;
		ComponentPort::meta.subTypes() +=  EventSink::meta;
		
	}
	 Udm::UdmDiagram diagram = { &umldiagram, Initialize };
	static struct _regClass
	{
		_regClass()
		{
			Udm::MetaDepository::StoreDiagram("cadena-scenario", diagram);
		};
		~_regClass()
		{
			Udm::MetaDepository::RemoveDiagram("cadena-scenario");
		};
	} __regUnUsed;

}
// END cadena_scenario.cpp
