#ifndef MOBIES_PICMLASSEMBLY2CADENASCENARIO_H
#define MOBIES_PICMLASSEMBLY2CADENASCENARIO_H
// header file PICMLAssembly2CadenaScenario.h generated from diagram PICMLAssembly2CadenaScenario
// generated on Tue May 11 01:39:25 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif



namespace PICMLAssembly2CadenaScenario {

	typedef Udm::Object Object;

	class  EventSource_cross_ph_cadena_scenario;
	class  EventSink_cross_ph_cadena_scenario;
	class  Receptacle_cross_ph_cadena_scenario;
	class  Facet_cross_ph_cadena_scenario;
	class  ComponentPort_cross_ph_cadena_scenario;
	class  RequestPort_cross_ph_PICML;
	class  EventPort_cross_ph_PICML;
	class  ProvidedRequestPort_cross_ph_PICML;
	class  RequiredRequestPort_cross_ph_PICML;
	class  OutEventPort_cross_ph_PICML;
	class  InEventPort_cross_ph_PICML;
	class  Port_cross_ph_PICML;
	class  _gen_cont;

	  void Initialize();

	  void Initialize(const Uml::Diagram &dgr);
	extern  Udm::UdmDiagram diagram;

	class  ComponentPort_cross_ph_cadena_scenario :  public Object {
	 public:
		static Uml::Class meta;

		ComponentPort_cross_ph_cadena_scenario() { }
		ComponentPort_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : Object(impl) { }
		ComponentPort_cross_ph_cadena_scenario(const ComponentPort_cross_ph_cadena_scenario &master) : Object(master) { }
		static ComponentPort_cross_ph_cadena_scenario Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentPort_cross_ph_cadena_scenario Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentPort_cross_ph_cadena_scenario CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentPort_cross_ph_cadena_scenario CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentPort_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentPort_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_picmlPort;
		Udm::AssocAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML> picmlPort() const { return Udm::AssocAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML>(impl, meta_picmlPort); }
		template <class Pred> Udm::AssocAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred > picmlPort_sorted(const Pred &) const { return Udm::AssocAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred>(impl, meta_picmlPort); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventSource_cross_ph_cadena_scenario :  public ComponentPort_cross_ph_cadena_scenario {
	 public:
		static Uml::Class meta;

		EventSource_cross_ph_cadena_scenario() { }
		EventSource_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : ComponentPort_cross_ph_cadena_scenario(impl) { }
		EventSource_cross_ph_cadena_scenario(const EventSource_cross_ph_cadena_scenario &master) : ComponentPort_cross_ph_cadena_scenario(master) { }
		static EventSource_cross_ph_cadena_scenario Cast(const Object &a) { return __Cast(a, meta); }

		static EventSource_cross_ph_cadena_scenario Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventSource_cross_ph_cadena_scenario CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventSource_cross_ph_cadena_scenario CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventSource_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EventSource_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventSink_cross_ph_cadena_scenario :  public ComponentPort_cross_ph_cadena_scenario {
	 public:
		static Uml::Class meta;

		EventSink_cross_ph_cadena_scenario() { }
		EventSink_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : ComponentPort_cross_ph_cadena_scenario(impl) { }
		EventSink_cross_ph_cadena_scenario(const EventSink_cross_ph_cadena_scenario &master) : ComponentPort_cross_ph_cadena_scenario(master) { }
		static EventSink_cross_ph_cadena_scenario Cast(const Object &a) { return __Cast(a, meta); }

		static EventSink_cross_ph_cadena_scenario Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventSink_cross_ph_cadena_scenario CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventSink_cross_ph_cadena_scenario CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventSink_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EventSink_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  Receptacle_cross_ph_cadena_scenario :  public ComponentPort_cross_ph_cadena_scenario {
	 public:
		static Uml::Class meta;

		Receptacle_cross_ph_cadena_scenario() { }
		Receptacle_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : ComponentPort_cross_ph_cadena_scenario(impl) { }
		Receptacle_cross_ph_cadena_scenario(const Receptacle_cross_ph_cadena_scenario &master) : ComponentPort_cross_ph_cadena_scenario(master) { }
		static Receptacle_cross_ph_cadena_scenario Cast(const Object &a) { return __Cast(a, meta); }

		static Receptacle_cross_ph_cadena_scenario Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Receptacle_cross_ph_cadena_scenario CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Receptacle_cross_ph_cadena_scenario CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Receptacle_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Receptacle_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  Facet_cross_ph_cadena_scenario :  public ComponentPort_cross_ph_cadena_scenario {
	 public:
		static Uml::Class meta;

		Facet_cross_ph_cadena_scenario() { }
		Facet_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : ComponentPort_cross_ph_cadena_scenario(impl) { }
		Facet_cross_ph_cadena_scenario(const Facet_cross_ph_cadena_scenario &master) : ComponentPort_cross_ph_cadena_scenario(master) { }
		static Facet_cross_ph_cadena_scenario Cast(const Object &a) { return __Cast(a, meta); }

		static Facet_cross_ph_cadena_scenario Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Facet_cross_ph_cadena_scenario CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Facet_cross_ph_cadena_scenario CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Facet_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Facet_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  Port_cross_ph_PICML :  public Object {
	 public:
		static Uml::Class meta;

		Port_cross_ph_PICML() { }
		Port_cross_ph_PICML(Udm::ObjectImpl *impl) : Object(impl) { }
		Port_cross_ph_PICML(const Port_cross_ph_PICML &master) : Object(master) { }
		static Port_cross_ph_PICML Cast(const Object &a) { return __Cast(a, meta); }

		static Port_cross_ph_PICML Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Port_cross_ph_PICML CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Port_cross_ph_PICML CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Port_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Port_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_cadenaPort;
		Udm::AssocAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario> cadenaPort() const { return Udm::AssocAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario>(impl, meta_cadenaPort); }
		template <class Pred> Udm::AssocAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred > cadenaPort_sorted(const Pred &) const { return Udm::AssocAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred>(impl, meta_cadenaPort); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  RequestPort_cross_ph_PICML :  public Port_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		RequestPort_cross_ph_PICML() { }
		RequestPort_cross_ph_PICML(Udm::ObjectImpl *impl) : Port_cross_ph_PICML(impl) { }
		RequestPort_cross_ph_PICML(const RequestPort_cross_ph_PICML &master) : Port_cross_ph_PICML(master) { }
		static RequestPort_cross_ph_PICML Cast(const Object &a) { return __Cast(a, meta); }

		static RequestPort_cross_ph_PICML Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RequestPort_cross_ph_PICML CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RequestPort_cross_ph_PICML CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RequestPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RequestPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventPort_cross_ph_PICML :  public Port_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		EventPort_cross_ph_PICML() { }
		EventPort_cross_ph_PICML(Udm::ObjectImpl *impl) : Port_cross_ph_PICML(impl) { }
		EventPort_cross_ph_PICML(const EventPort_cross_ph_PICML &master) : Port_cross_ph_PICML(master) { }
		static EventPort_cross_ph_PICML Cast(const Object &a) { return __Cast(a, meta); }

		static EventPort_cross_ph_PICML Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventPort_cross_ph_PICML CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventPort_cross_ph_PICML CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EventPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  ProvidedRequestPort_cross_ph_PICML :  public RequestPort_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		ProvidedRequestPort_cross_ph_PICML() { }
		ProvidedRequestPort_cross_ph_PICML(Udm::ObjectImpl *impl) : RequestPort_cross_ph_PICML(impl) { }
		ProvidedRequestPort_cross_ph_PICML(const ProvidedRequestPort_cross_ph_PICML &master) : RequestPort_cross_ph_PICML(master) { }
		static ProvidedRequestPort_cross_ph_PICML Cast(const Object &a) { return __Cast(a, meta); }

		static ProvidedRequestPort_cross_ph_PICML Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ProvidedRequestPort_cross_ph_PICML CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ProvidedRequestPort_cross_ph_PICML CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ProvidedRequestPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ProvidedRequestPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  RequiredRequestPort_cross_ph_PICML :  public RequestPort_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		RequiredRequestPort_cross_ph_PICML() { }
		RequiredRequestPort_cross_ph_PICML(Udm::ObjectImpl *impl) : RequestPort_cross_ph_PICML(impl) { }
		RequiredRequestPort_cross_ph_PICML(const RequiredRequestPort_cross_ph_PICML &master) : RequestPort_cross_ph_PICML(master) { }
		static RequiredRequestPort_cross_ph_PICML Cast(const Object &a) { return __Cast(a, meta); }

		static RequiredRequestPort_cross_ph_PICML Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RequiredRequestPort_cross_ph_PICML CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RequiredRequestPort_cross_ph_PICML CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RequiredRequestPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RequiredRequestPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  OutEventPort_cross_ph_PICML :  public EventPort_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		OutEventPort_cross_ph_PICML() { }
		OutEventPort_cross_ph_PICML(Udm::ObjectImpl *impl) : EventPort_cross_ph_PICML(impl) { }
		OutEventPort_cross_ph_PICML(const OutEventPort_cross_ph_PICML &master) : EventPort_cross_ph_PICML(master) { }
		static OutEventPort_cross_ph_PICML Cast(const Object &a) { return __Cast(a, meta); }

		static OutEventPort_cross_ph_PICML Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		OutEventPort_cross_ph_PICML CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		OutEventPort_cross_ph_PICML CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<OutEventPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<OutEventPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  InEventPort_cross_ph_PICML :  public EventPort_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		InEventPort_cross_ph_PICML() { }
		InEventPort_cross_ph_PICML(Udm::ObjectImpl *impl) : EventPort_cross_ph_PICML(impl) { }
		InEventPort_cross_ph_PICML(const InEventPort_cross_ph_PICML &master) : EventPort_cross_ph_PICML(master) { }
		static InEventPort_cross_ph_PICML Cast(const Object &a) { return __Cast(a, meta); }

		static InEventPort_cross_ph_PICML Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		InEventPort_cross_ph_PICML CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		InEventPort_cross_ph_PICML CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<InEventPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<InEventPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont> parent() const { return Udm::ParentAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  _gen_cont :  public Object {
	 public:
		static Uml::Class meta;

		_gen_cont() { }
		_gen_cont(Udm::ObjectImpl *impl) : Object(impl) { }
		_gen_cont(const _gen_cont &master) : Object(master) { }
		static _gen_cont Cast(const Object &a) { return __Cast(a, meta); }

		static _gen_cont Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		_gen_cont CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		_gen_cont CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<_gen_cont> Instances() { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl);}
		template <class Pred> Udm::InstantiatedAttr<_gen_cont, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICMLAssembly2CadenaScenario::_gen_cont, Pred>(impl);}

		Udm::DerivedAttr<PICMLAssembly2CadenaScenario::_gen_cont> Derived() { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl);}
		template <class Pred> Udm::DerivedAttr<PICMLAssembly2CadenaScenario::_gen_cont, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICMLAssembly2CadenaScenario::_gen_cont, Pred>(impl);}

		Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::_gen_cont> Archetype() { return Udm::ArchetypeAttr<PICMLAssembly2CadenaScenario::_gen_cont>(impl);}

		static Uml::CompositionChildRole meta_Port_cross_ph_PICML_children;
		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML> Port_cross_ph_PICML_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML>(impl, meta_Port_cross_ph_PICML_children); }
		 template <class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred> Port_cross_ph_PICML_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred>(impl, meta_Port_cross_ph_PICML_children); }

		static Uml::CompositionChildRole meta_ComponentPort_cross_ph_cadena_scenario_children;
		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario> ComponentPort_cross_ph_cadena_scenario_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario>(impl, meta_ComponentPort_cross_ph_cadena_scenario_children); }
		 template <class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred> ComponentPort_cross_ph_cadena_scenario_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred>(impl, meta_ComponentPort_cross_ph_cadena_scenario_children); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario> EventSource_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario, Pred> EventSource_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventSource_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario> EventSink_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario, Pred> EventSink_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventSink_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario> Receptacle_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario, Pred> Receptacle_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Receptacle_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario> Facet_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario, Pred> Facet_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Facet_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario> ComponentPort_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred> ComponentPort_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ComponentPort_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML> RequestPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML, Pred> RequestPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::RequestPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML> EventPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML, Pred> EventPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::EventPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML> ProvidedRequestPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML, Pred> ProvidedRequestPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::ProvidedRequestPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML> RequiredRequestPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML, Pred> RequiredRequestPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::RequiredRequestPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML> OutEventPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML, Pred> OutEventPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::OutEventPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML> InEventPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML, Pred> InEventPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::InEventPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML> Port_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred> Port_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICMLAssembly2CadenaScenario::Port_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

}

#endif //MOBIES_PICMLASSEMBLY2CADENASCENARIO_H
