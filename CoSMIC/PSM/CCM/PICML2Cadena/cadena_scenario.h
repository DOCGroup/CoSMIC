#ifndef MOBIES_CADENA_SCENARIO_H
#define MOBIES_CADENA_SCENARIO_H
// header file cadena_scenario.h generated from diagram cadena-scenario
// generated on Thu Apr 22 00:47:38 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif



namespace cadena_scenario {

	typedef Udm::Object Object;

	class  ScenarioElement;
	class  PortConnection;
	class  Scenario;
	class  ComponentInstance;
	class  Property;
	class  ComponentPort;
	class  Facet;
	class  Receptacle;
	class  EventSource;
	class  EventSink;
	class  FRConnection;
	class  ESSConnection;

	  void Initialize();
	extern  Udm::UdmDiagram diagram;

	class  ScenarioElement :  public Object {
	 public:
		static Uml::Class meta;

		ScenarioElement() { }
		ScenarioElement(Udm::ObjectImpl *impl) : Object(impl) { }
		ScenarioElement(const ScenarioElement &master) : Object(master) { }
		static ScenarioElement Cast(const Object &a) { return __Cast(a, meta); }

		static ScenarioElement Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ScenarioElement CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ScenarioElement CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ScenarioElement> Instances() { return Udm::InstantiatedAttr<cadena_scenario::ScenarioElement>(impl);}

		Udm::DerivedAttr<cadena_scenario::ScenarioElement> Derived() { return Udm::DerivedAttr<cadena_scenario::ScenarioElement>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::ScenarioElement> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::ScenarioElement>(impl);}

		static Uml::CompositionChildRole meta_properties;
		Udm::ChildrenAttr<cadena_scenario::Property> properties() const { return Udm::ChildrenAttr<cadena_scenario::Property>(impl, meta_properties); }

		Udm::ChildrenAttr<cadena_scenario::Property> Property_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::Property>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  PortConnection :  public ScenarioElement {
	 public:
		static Uml::Class meta;

		PortConnection() { }
		PortConnection(Udm::ObjectImpl *impl) : ScenarioElement(impl) { }
		PortConnection(const PortConnection &master) : ScenarioElement(master) { }
		static PortConnection Cast(const Object &a) { return __Cast(a, meta); }

		static PortConnection Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PortConnection CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PortConnection CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PortConnection> Instances() { return Udm::InstantiatedAttr<cadena_scenario::PortConnection>(impl);}

		Udm::DerivedAttr<cadena_scenario::PortConnection> Derived() { return Udm::DerivedAttr<cadena_scenario::PortConnection>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::PortConnection> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::PortConnection>(impl);}

		static Uml::CompositionParentRole meta_Scenario_parent;
		Udm::ParentAttr<cadena_scenario::Scenario> Scenario_parent() const { return Udm::ParentAttr<cadena_scenario::Scenario>(impl, meta_Scenario_parent); }

		Udm::ParentAttr<cadena_scenario::ScenarioElement> parent() const { return Udm::ParentAttr<cadena_scenario::ScenarioElement>(impl, Udm::NULLPARENTROLE); }
	};

	class  Scenario :  public ScenarioElement {
	 public:
		static Uml::Class meta;

		Scenario() { }
		Scenario(Udm::ObjectImpl *impl) : ScenarioElement(impl) { }
		Scenario(const Scenario &master) : ScenarioElement(master) { }
		static Scenario Cast(const Object &a) { return __Cast(a, meta); }

		static Scenario Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Scenario CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Scenario CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Scenario> Instances() { return Udm::InstantiatedAttr<cadena_scenario::Scenario>(impl);}

		Udm::DerivedAttr<cadena_scenario::Scenario> Derived() { return Udm::DerivedAttr<cadena_scenario::Scenario>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::Scenario> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::Scenario>(impl);}

		static Uml::CompositionChildRole meta_PortConnection_children;
		Udm::ChildrenAttr<cadena_scenario::PortConnection> PortConnection_children() const { return Udm::ChildrenAttr<cadena_scenario::PortConnection>(impl, meta_PortConnection_children); }

		static Uml::CompositionChildRole meta_ComponentInstance_children;
		Udm::ChildrenAttr<cadena_scenario::ComponentInstance> ComponentInstance_children() const { return Udm::ChildrenAttr<cadena_scenario::ComponentInstance>(impl, meta_ComponentInstance_children); }

		Udm::ChildrenAttr<cadena_scenario::ScenarioElement> ScenarioElement_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::ScenarioElement>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<cadena_scenario::PortConnection> PortConnection_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::PortConnection>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<cadena_scenario::ComponentInstance> ComponentInstance_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::ComponentInstance>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<cadena_scenario::FRConnection> FRConnection_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::FRConnection>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<cadena_scenario::ESSConnection> ESSConnection_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::ESSConnection>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentInstance :  public ScenarioElement {
	 public:
		static Uml::Class meta;

		ComponentInstance() { }
		ComponentInstance(Udm::ObjectImpl *impl) : ScenarioElement(impl) { }
		ComponentInstance(const ComponentInstance &master) : ScenarioElement(master) { }
		static ComponentInstance Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentInstance Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentInstance CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentInstance CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentInstance> Instances() { return Udm::InstantiatedAttr<cadena_scenario::ComponentInstance>(impl);}

		Udm::DerivedAttr<cadena_scenario::ComponentInstance> Derived() { return Udm::DerivedAttr<cadena_scenario::ComponentInstance>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::ComponentInstance> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::ComponentInstance>(impl);}

		static Uml::Attribute meta_type;
		Udm::StringAttr type() const { return Udm::StringAttr(impl, meta_type); }

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_ComponentPort_children;
		Udm::ChildrenAttr<cadena_scenario::ComponentPort> ComponentPort_children() const { return Udm::ChildrenAttr<cadena_scenario::ComponentPort>(impl, meta_ComponentPort_children); }

		Udm::ChildrenAttr<cadena_scenario::ComponentPort> ComponentPort_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::ComponentPort>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<cadena_scenario::Facet> Facet_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::Facet>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<cadena_scenario::Receptacle> Receptacle_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::Receptacle>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<cadena_scenario::EventSource> EventSource_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::EventSource>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<cadena_scenario::EventSink> EventSink_kind_children() const { return Udm::ChildrenAttr<cadena_scenario::EventSink>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_Scenario_parent;
		Udm::ParentAttr<cadena_scenario::Scenario> Scenario_parent() const { return Udm::ParentAttr<cadena_scenario::Scenario>(impl, meta_Scenario_parent); }

		Udm::ParentAttr<cadena_scenario::ScenarioElement> parent() const { return Udm::ParentAttr<cadena_scenario::ScenarioElement>(impl, Udm::NULLPARENTROLE); }
	};

	class  Property :  public Object {
	 public:
		static Uml::Class meta;

		Property() { }
		Property(Udm::ObjectImpl *impl) : Object(impl) { }
		Property(const Property &master) : Object(master) { }
		static Property Cast(const Object &a) { return __Cast(a, meta); }

		static Property Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Property CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Property CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Property> Instances() { return Udm::InstantiatedAttr<cadena_scenario::Property>(impl);}

		Udm::DerivedAttr<cadena_scenario::Property> Derived() { return Udm::DerivedAttr<cadena_scenario::Property>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::Property> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::Property>(impl);}

		static Uml::Attribute meta_value;
		Udm::StringAttr value() const { return Udm::StringAttr(impl, meta_value); }

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::Attribute meta_type;
		Udm::StringAttr type() const { return Udm::StringAttr(impl, meta_type); }

		static Uml::CompositionParentRole meta_properties_ScenarioElement_parent;
		Udm::ParentAttr<cadena_scenario::ScenarioElement> properties_ScenarioElement_parent() const { return Udm::ParentAttr<cadena_scenario::ScenarioElement>(impl, meta_properties_ScenarioElement_parent); }

		Udm::ParentAttr<cadena_scenario::ScenarioElement> parent() const { return Udm::ParentAttr<cadena_scenario::ScenarioElement>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentPort :  public Object {
	 public:
		static Uml::Class meta;

		ComponentPort() { }
		ComponentPort(Udm::ObjectImpl *impl) : Object(impl) { }
		ComponentPort(const ComponentPort &master) : Object(master) { }
		static ComponentPort Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentPort Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentPort CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentPort CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentPort> Instances() { return Udm::InstantiatedAttr<cadena_scenario::ComponentPort>(impl);}

		Udm::DerivedAttr<cadena_scenario::ComponentPort> Derived() { return Udm::DerivedAttr<cadena_scenario::ComponentPort>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::ComponentPort> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::ComponentPort>(impl);}

		static Uml::Attribute meta_Name;
		Udm::StringAttr Name() const { return Udm::StringAttr(impl, meta_Name); }

		static Uml::CompositionParentRole meta_ComponentInstance_parent;
		Udm::ParentAttr<cadena_scenario::ComponentInstance> ComponentInstance_parent() const { return Udm::ParentAttr<cadena_scenario::ComponentInstance>(impl, meta_ComponentInstance_parent); }

		Udm::ParentAttr<cadena_scenario::ScenarioElement> parent() const { return Udm::ParentAttr<cadena_scenario::ScenarioElement>(impl, Udm::NULLPARENTROLE); }
	};

	class  Facet :  public ComponentPort {
	 public:
		static Uml::Class meta;

		Facet() { }
		Facet(Udm::ObjectImpl *impl) : ComponentPort(impl) { }
		Facet(const Facet &master) : ComponentPort(master) { }
		static Facet Cast(const Object &a) { return __Cast(a, meta); }

		static Facet Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Facet CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Facet CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Facet> Instances() { return Udm::InstantiatedAttr<cadena_scenario::Facet>(impl);}

		Udm::DerivedAttr<cadena_scenario::Facet> Derived() { return Udm::DerivedAttr<cadena_scenario::Facet>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::Facet> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::Facet>(impl);}

		static Uml::AssociationRole meta_receptacles, meta_receptacles_rev;
		Udm::AClassAssocAttr<cadena_scenario::FRConnection, cadena_scenario::Receptacle> receptacles() const { return Udm::AClassAssocAttr<cadena_scenario::FRConnection, cadena_scenario::Receptacle>(impl, meta_receptacles, meta_receptacles_rev); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  Receptacle :  public ComponentPort {
	 public:
		static Uml::Class meta;

		Receptacle() { }
		Receptacle(Udm::ObjectImpl *impl) : ComponentPort(impl) { }
		Receptacle(const Receptacle &master) : ComponentPort(master) { }
		static Receptacle Cast(const Object &a) { return __Cast(a, meta); }

		static Receptacle Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Receptacle CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Receptacle CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Receptacle> Instances() { return Udm::InstantiatedAttr<cadena_scenario::Receptacle>(impl);}

		Udm::DerivedAttr<cadena_scenario::Receptacle> Derived() { return Udm::DerivedAttr<cadena_scenario::Receptacle>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::Receptacle> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::Receptacle>(impl);}

		static Uml::AssociationRole meta_facets, meta_facets_rev;
		Udm::AClassAssocAttr<cadena_scenario::FRConnection, cadena_scenario::Facet> facets() const { return Udm::AClassAssocAttr<cadena_scenario::FRConnection, cadena_scenario::Facet>(impl, meta_facets, meta_facets_rev); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventSource :  public ComponentPort {
	 public:
		static Uml::Class meta;

		EventSource() { }
		EventSource(Udm::ObjectImpl *impl) : ComponentPort(impl) { }
		EventSource(const EventSource &master) : ComponentPort(master) { }
		static EventSource Cast(const Object &a) { return __Cast(a, meta); }

		static EventSource Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventSource CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventSource CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventSource> Instances() { return Udm::InstantiatedAttr<cadena_scenario::EventSource>(impl);}

		Udm::DerivedAttr<cadena_scenario::EventSource> Derived() { return Udm::DerivedAttr<cadena_scenario::EventSource>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::EventSource> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::EventSource>(impl);}

		static Uml::AssociationRole meta_sinksConnections;
		Udm::AssocAttr<cadena_scenario::ESSConnection> sinksConnections() const { return Udm::AssocAttr<cadena_scenario::ESSConnection>(impl, meta_sinksConnections); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventSink :  public ComponentPort {
	 public:
		static Uml::Class meta;

		EventSink() { }
		EventSink(Udm::ObjectImpl *impl) : ComponentPort(impl) { }
		EventSink(const EventSink &master) : ComponentPort(master) { }
		static EventSink Cast(const Object &a) { return __Cast(a, meta); }

		static EventSink Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventSink CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventSink CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventSink> Instances() { return Udm::InstantiatedAttr<cadena_scenario::EventSink>(impl);}

		Udm::DerivedAttr<cadena_scenario::EventSink> Derived() { return Udm::DerivedAttr<cadena_scenario::EventSink>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::EventSink> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::EventSink>(impl);}

		static Uml::AssociationRole meta_sourcesConnections;
		Udm::AssocAttr<cadena_scenario::ESSConnection> sourcesConnections() const { return Udm::AssocAttr<cadena_scenario::ESSConnection>(impl, meta_sourcesConnections); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  FRConnection :  public PortConnection {
	 public:
		static Uml::Class meta;

		FRConnection() { }
		FRConnection(Udm::ObjectImpl *impl) : PortConnection(impl) { }
		FRConnection(const FRConnection &master) : PortConnection(master) { }
		static FRConnection Cast(const Object &a) { return __Cast(a, meta); }

		static FRConnection Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		FRConnection CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		FRConnection CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<FRConnection> Instances() { return Udm::InstantiatedAttr<cadena_scenario::FRConnection>(impl);}

		Udm::DerivedAttr<cadena_scenario::FRConnection> Derived() { return Udm::DerivedAttr<cadena_scenario::FRConnection>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::FRConnection> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::FRConnection>(impl);}

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_facets_end_;
		Udm::AssocEndAttr<cadena_scenario::Facet> facets_end() const { return Udm::AssocEndAttr<cadena_scenario::Facet>(impl, meta_facets_end_); }

		static Uml::AssociationRole meta_receptacles_end_;
		Udm::AssocEndAttr<cadena_scenario::Receptacle> receptacles_end() const { return Udm::AssocEndAttr<cadena_scenario::Receptacle>(impl, meta_receptacles_end_); }

	};

	class  ESSConnection :  public PortConnection {
	 public:
		static Uml::Class meta;

		ESSConnection() { }
		ESSConnection(Udm::ObjectImpl *impl) : PortConnection(impl) { }
		ESSConnection(const ESSConnection &master) : PortConnection(master) { }
		static ESSConnection Cast(const Object &a) { return __Cast(a, meta); }

		static ESSConnection Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ESSConnection CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ESSConnection CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ESSConnection> Instances() { return Udm::InstantiatedAttr<cadena_scenario::ESSConnection>(impl);}

		Udm::DerivedAttr<cadena_scenario::ESSConnection> Derived() { return Udm::DerivedAttr<cadena_scenario::ESSConnection>(impl);}

		Udm::ArchetypeAttr<cadena_scenario::ESSConnection> Archetype() { return Udm::ArchetypeAttr<cadena_scenario::ESSConnection>(impl);}

		static Uml::Attribute meta_Correlator;
		Udm::StringAttr Correlator() const { return Udm::StringAttr(impl, meta_Correlator); }

		static Uml::AssociationRole meta_sources;
		Udm::AssocAttr<cadena_scenario::EventSource> sources() const { return Udm::AssocAttr<cadena_scenario::EventSource>(impl, meta_sources); }

		static Uml::AssociationRole meta_sinks;
		Udm::AssocAttr<cadena_scenario::EventSink> sinks() const { return Udm::AssocAttr<cadena_scenario::EventSink>(impl, meta_sinks); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

}

#endif //MOBIES_CADENA_SCENARIO_H
