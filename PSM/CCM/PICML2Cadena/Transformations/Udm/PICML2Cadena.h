#ifndef MOBIES_PICML2CADENA_H
#define MOBIES_PICML2CADENA_H
// header file PICML2Cadena.h generated from diagram PICML2Cadena
// generated on Mon Nov 15 02:46:30 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif



namespace PICML2Cadena {

	class  PublishConnector_cross_ph_PICML;
	class  invoke_cross_ph_PICML;
	class  emit_cross_ph_PICML;
	class  ComponentAssembly_cross_ph_PICML;
	class  OutEventPort_cross_ph_PICML;
	class  ProvidedRequestPort_cross_ph_PICML;
	class  RequiredRequestPort_cross_ph_PICML;
	class  InEventPort_cross_ph_PICML;
	class  Port_cross_ph_PICML;
	class  Component_cross_ph_PICML;
	class  RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties;
	class  ESSConnection_cross_ph_cadena_scenario;
	class  FRConnection_cross_ph_cadena_scenario;
	class  EventSink_cross_ph_cadena_scenario;
	class  EventSource_cross_ph_cadena_scenario;
	class  Receptacle_cross_ph_cadena_scenario;
	class  Facet_cross_ph_cadena_scenario;
	class  ComponentPort_cross_ph_cadena_scenario;
	class  ComponentInstance_cross_ph_cadena_scenario;
	class  _gen_cont;

	  void Initialize();

	  void Initialize(const Uml::Diagram &dgr);
	extern  Udm::UdmDiagram diagram;

	class  PublishConnector_cross_ph_PICML :  public Udm::Object {
	 public:
		static Uml::Class meta;

		PublishConnector_cross_ph_PICML() { }
		PublishConnector_cross_ph_PICML(Udm::ObjectImpl *impl) : Object(impl) { }
		PublishConnector_cross_ph_PICML(const PublishConnector_cross_ph_PICML &master) : Object(master) { }
		static PublishConnector_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static PublishConnector_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PublishConnector_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PublishConnector_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PublishConnector_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::PublishConnector_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PublishConnector_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::PublishConnector_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::PublishConnector_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::PublishConnector_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::PublishConnector_cross_ph_PICML>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_cadenaESSConnection;
		Udm::PointerAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario> cadenaESSConnection() const { return Udm::PointerAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario>(impl, meta_cadenaESSConnection); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  invoke_cross_ph_PICML :  public Udm::Object {
	 public:
		static Uml::Class meta;

		invoke_cross_ph_PICML() { }
		invoke_cross_ph_PICML(Udm::ObjectImpl *impl) : Object(impl) { }
		invoke_cross_ph_PICML(const invoke_cross_ph_PICML &master) : Object(master) { }
		static invoke_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static invoke_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		invoke_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		invoke_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<invoke_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::invoke_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<invoke_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::invoke_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::invoke_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::invoke_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::invoke_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::invoke_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::invoke_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::invoke_cross_ph_PICML>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_cadenaInvoke;
		Udm::PointerAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario> cadenaInvoke() const { return Udm::PointerAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario>(impl, meta_cadenaInvoke); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  emit_cross_ph_PICML :  public Udm::Object {
	 public:
		static Uml::Class meta;

		emit_cross_ph_PICML() { }
		emit_cross_ph_PICML(Udm::ObjectImpl *impl) : Object(impl) { }
		emit_cross_ph_PICML(const emit_cross_ph_PICML &master) : Object(master) { }
		static emit_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static emit_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		emit_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		emit_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<emit_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::emit_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<emit_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::emit_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::emit_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::emit_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::emit_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::emit_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::emit_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::emit_cross_ph_PICML>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_cadenaEmit;
		Udm::AssocAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario> cadenaEmit() const { return Udm::AssocAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario>(impl, meta_cadenaEmit); }
		template <class Pred> Udm::AssocAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred > cadenaEmit_sorted(const Pred &) const { return Udm::AssocAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred>(impl, meta_cadenaEmit); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentAssembly_cross_ph_PICML :  public Udm::Object {
	 public:
		static Uml::Class meta;

		ComponentAssembly_cross_ph_PICML() { }
		ComponentAssembly_cross_ph_PICML(Udm::ObjectImpl *impl) : Object(impl) { }
		ComponentAssembly_cross_ph_PICML(const ComponentAssembly_cross_ph_PICML &master) : Object(master) { }
		static ComponentAssembly_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static ComponentAssembly_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentAssembly_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentAssembly_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentAssembly_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentAssembly_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_rootContainer;
		Udm::PointerAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties> rootContainer() const { return Udm::PointerAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties>(impl, meta_rootContainer); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  Port_cross_ph_PICML :  public Udm::Object {
	 public:
		static Uml::Class meta;

		Port_cross_ph_PICML() { }
		Port_cross_ph_PICML(Udm::ObjectImpl *impl) : Object(impl) { }
		Port_cross_ph_PICML(const Port_cross_ph_PICML &master) : Object(master) { }
		static Port_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static Port_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Port_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Port_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Port_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::Port_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Port_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::Port_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::Port_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::Port_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::Port_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::Port_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::Port_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::Port_cross_ph_PICML>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_cadenaPort;
		Udm::PointerAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario> cadenaPort() const { return Udm::PointerAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario>(impl, meta_cadenaPort); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  OutEventPort_cross_ph_PICML :  public Port_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		OutEventPort_cross_ph_PICML() { }
		OutEventPort_cross_ph_PICML(Udm::ObjectImpl *impl) : Port_cross_ph_PICML(impl) { }
		OutEventPort_cross_ph_PICML(const OutEventPort_cross_ph_PICML &master) : Port_cross_ph_PICML(master) { }
		static OutEventPort_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static OutEventPort_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		OutEventPort_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		OutEventPort_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<OutEventPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::OutEventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<OutEventPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::OutEventPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::OutEventPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::OutEventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::OutEventPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::OutEventPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::OutEventPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::OutEventPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  ProvidedRequestPort_cross_ph_PICML :  public Port_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		ProvidedRequestPort_cross_ph_PICML() { }
		ProvidedRequestPort_cross_ph_PICML(Udm::ObjectImpl *impl) : Port_cross_ph_PICML(impl) { }
		ProvidedRequestPort_cross_ph_PICML(const ProvidedRequestPort_cross_ph_PICML &master) : Port_cross_ph_PICML(master) { }
		static ProvidedRequestPort_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static ProvidedRequestPort_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ProvidedRequestPort_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ProvidedRequestPort_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ProvidedRequestPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ProvidedRequestPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  RequiredRequestPort_cross_ph_PICML :  public Port_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		RequiredRequestPort_cross_ph_PICML() { }
		RequiredRequestPort_cross_ph_PICML(Udm::ObjectImpl *impl) : Port_cross_ph_PICML(impl) { }
		RequiredRequestPort_cross_ph_PICML(const RequiredRequestPort_cross_ph_PICML &master) : Port_cross_ph_PICML(master) { }
		static RequiredRequestPort_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static RequiredRequestPort_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RequiredRequestPort_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RequiredRequestPort_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RequiredRequestPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RequiredRequestPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  InEventPort_cross_ph_PICML :  public Port_cross_ph_PICML {
	 public:
		static Uml::Class meta;

		InEventPort_cross_ph_PICML() { }
		InEventPort_cross_ph_PICML(Udm::ObjectImpl *impl) : Port_cross_ph_PICML(impl) { }
		InEventPort_cross_ph_PICML(const InEventPort_cross_ph_PICML &master) : Port_cross_ph_PICML(master) { }
		static InEventPort_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static InEventPort_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		InEventPort_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		InEventPort_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<InEventPort_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::InEventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<InEventPort_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::InEventPort_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::InEventPort_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::InEventPort_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::InEventPort_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::InEventPort_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::InEventPort_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::InEventPort_cross_ph_PICML>(impl);}

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  Component_cross_ph_PICML :  public Udm::Object {
	 public:
		static Uml::Class meta;

		Component_cross_ph_PICML() { }
		Component_cross_ph_PICML(Udm::ObjectImpl *impl) : Object(impl) { }
		Component_cross_ph_PICML(const Component_cross_ph_PICML &master) : Object(master) { }
		static Component_cross_ph_PICML Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static Component_cross_ph_PICML Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Component_cross_ph_PICML CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Component_cross_ph_PICML CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Component_cross_ph_PICML> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::Component_cross_ph_PICML>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Component_cross_ph_PICML, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::Component_cross_ph_PICML, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::Component_cross_ph_PICML> Derived() { return Udm::DerivedAttr<PICML2Cadena::Component_cross_ph_PICML>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::Component_cross_ph_PICML, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::Component_cross_ph_PICML, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::Component_cross_ph_PICML> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::Component_cross_ph_PICML>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_cadenaComponentInstance;
		Udm::PointerAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario> cadenaComponentInstance() const { return Udm::PointerAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario>(impl, meta_cadenaComponentInstance); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties :  public Udm::Object {
	 public:
		static Uml::Class meta;

		RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties() { }
		RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties(Udm::ObjectImpl *impl) : Object(impl) { }
		RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties(const RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties &master) : Object(master) { }
		static RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties> Derived() { return Udm::DerivedAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_componentAssembly;
		Udm::PointerAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML> componentAssembly() const { return Udm::PointerAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML>(impl, meta_componentAssembly); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  ESSConnection_cross_ph_cadena_scenario :  public Udm::Object {
	 public:
		static Uml::Class meta;

		ESSConnection_cross_ph_cadena_scenario() { }
		ESSConnection_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : Object(impl) { }
		ESSConnection_cross_ph_cadena_scenario(const ESSConnection_cross_ph_cadena_scenario &master) : Object(master) { }
		static ESSConnection_cross_ph_cadena_scenario Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static ESSConnection_cross_ph_cadena_scenario Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ESSConnection_cross_ph_cadena_scenario CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ESSConnection_cross_ph_cadena_scenario CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ESSConnection_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ESSConnection_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_picmlPublishConnector;
		Udm::AssocAttr<PICML2Cadena::PublishConnector_cross_ph_PICML> picmlPublishConnector() const { return Udm::AssocAttr<PICML2Cadena::PublishConnector_cross_ph_PICML>(impl, meta_picmlPublishConnector); }
		template <class Pred> Udm::AssocAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred > picmlPublishConnector_sorted(const Pred &) const { return Udm::AssocAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred>(impl, meta_picmlPublishConnector); }

		static Uml::AssociationRole meta_picmlEmit;
		Udm::AssocAttr<PICML2Cadena::emit_cross_ph_PICML> picmlEmit() const { return Udm::AssocAttr<PICML2Cadena::emit_cross_ph_PICML>(impl, meta_picmlEmit); }
		template <class Pred> Udm::AssocAttr<PICML2Cadena::emit_cross_ph_PICML, Pred > picmlEmit_sorted(const Pred &) const { return Udm::AssocAttr<PICML2Cadena::emit_cross_ph_PICML, Pred>(impl, meta_picmlEmit); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  FRConnection_cross_ph_cadena_scenario :  public Udm::Object {
	 public:
		static Uml::Class meta;

		FRConnection_cross_ph_cadena_scenario() { }
		FRConnection_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : Object(impl) { }
		FRConnection_cross_ph_cadena_scenario(const FRConnection_cross_ph_cadena_scenario &master) : Object(master) { }
		static FRConnection_cross_ph_cadena_scenario Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static FRConnection_cross_ph_cadena_scenario Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		FRConnection_cross_ph_cadena_scenario CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		FRConnection_cross_ph_cadena_scenario CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<FRConnection_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<FRConnection_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_picmlInvoke;
		Udm::PointerAttr<PICML2Cadena::invoke_cross_ph_PICML> picmlInvoke() const { return Udm::PointerAttr<PICML2Cadena::invoke_cross_ph_PICML>(impl, meta_picmlInvoke); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentPort_cross_ph_cadena_scenario :  public Udm::Object {
	 public:
		static Uml::Class meta;

		ComponentPort_cross_ph_cadena_scenario() { }
		ComponentPort_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : Object(impl) { }
		ComponentPort_cross_ph_cadena_scenario(const ComponentPort_cross_ph_cadena_scenario &master) : Object(master) { }
		static ComponentPort_cross_ph_cadena_scenario Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static ComponentPort_cross_ph_cadena_scenario Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentPort_cross_ph_cadena_scenario CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentPort_cross_ph_cadena_scenario CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentPort_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentPort_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_picmlPort;
		Udm::PointerAttr<PICML2Cadena::Port_cross_ph_PICML> picmlPort() const { return Udm::PointerAttr<PICML2Cadena::Port_cross_ph_PICML>(impl, meta_picmlPort); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventSink_cross_ph_cadena_scenario :  public ComponentPort_cross_ph_cadena_scenario {
	 public:
		static Uml::Class meta;

		EventSink_cross_ph_cadena_scenario() { }
		EventSink_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : ComponentPort_cross_ph_cadena_scenario(impl) { }
		EventSink_cross_ph_cadena_scenario(const EventSink_cross_ph_cadena_scenario &master) : ComponentPort_cross_ph_cadena_scenario(master) { }
		static EventSink_cross_ph_cadena_scenario Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static EventSink_cross_ph_cadena_scenario Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventSink_cross_ph_cadena_scenario CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventSink_cross_ph_cadena_scenario CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventSink_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EventSink_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario>(impl);}

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventSource_cross_ph_cadena_scenario :  public ComponentPort_cross_ph_cadena_scenario {
	 public:
		static Uml::Class meta;

		EventSource_cross_ph_cadena_scenario() { }
		EventSource_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : ComponentPort_cross_ph_cadena_scenario(impl) { }
		EventSource_cross_ph_cadena_scenario(const EventSource_cross_ph_cadena_scenario &master) : ComponentPort_cross_ph_cadena_scenario(master) { }
		static EventSource_cross_ph_cadena_scenario Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static EventSource_cross_ph_cadena_scenario Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventSource_cross_ph_cadena_scenario CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventSource_cross_ph_cadena_scenario CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventSource_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EventSource_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario>(impl);}

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  Receptacle_cross_ph_cadena_scenario :  public ComponentPort_cross_ph_cadena_scenario {
	 public:
		static Uml::Class meta;

		Receptacle_cross_ph_cadena_scenario() { }
		Receptacle_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : ComponentPort_cross_ph_cadena_scenario(impl) { }
		Receptacle_cross_ph_cadena_scenario(const Receptacle_cross_ph_cadena_scenario &master) : ComponentPort_cross_ph_cadena_scenario(master) { }
		static Receptacle_cross_ph_cadena_scenario Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static Receptacle_cross_ph_cadena_scenario Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Receptacle_cross_ph_cadena_scenario CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Receptacle_cross_ph_cadena_scenario CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Receptacle_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Receptacle_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario>(impl);}

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  Facet_cross_ph_cadena_scenario :  public ComponentPort_cross_ph_cadena_scenario {
	 public:
		static Uml::Class meta;

		Facet_cross_ph_cadena_scenario() { }
		Facet_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : ComponentPort_cross_ph_cadena_scenario(impl) { }
		Facet_cross_ph_cadena_scenario(const Facet_cross_ph_cadena_scenario &master) : ComponentPort_cross_ph_cadena_scenario(master) { }
		static Facet_cross_ph_cadena_scenario Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static Facet_cross_ph_cadena_scenario Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Facet_cross_ph_cadena_scenario CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Facet_cross_ph_cadena_scenario CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Facet_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Facet_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario>(impl);}

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentInstance_cross_ph_cadena_scenario :  public Udm::Object {
	 public:
		static Uml::Class meta;

		ComponentInstance_cross_ph_cadena_scenario() { }
		ComponentInstance_cross_ph_cadena_scenario(Udm::ObjectImpl *impl) : Object(impl) { }
		ComponentInstance_cross_ph_cadena_scenario(const ComponentInstance_cross_ph_cadena_scenario &master) : Object(master) { }
		static ComponentInstance_cross_ph_cadena_scenario Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static ComponentInstance_cross_ph_cadena_scenario Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentInstance_cross_ph_cadena_scenario CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentInstance_cross_ph_cadena_scenario CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentInstance_cross_ph_cadena_scenario> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentInstance_cross_ph_cadena_scenario, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario> Derived() { return Udm::DerivedAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario>(impl);}

		static Uml::Attribute meta_rem_id;
		Udm::IntegerAttr rem_id() const { return Udm::IntegerAttr(impl, meta_rem_id); }

		static Uml::Attribute meta_rem_sysname;
		Udm::StringAttr rem_sysname() const { return Udm::StringAttr(impl, meta_rem_sysname); }

		static Uml::AssociationRole meta_picmlComponentDef;
		Udm::PointerAttr<PICML2Cadena::Component_cross_ph_PICML> picmlComponentDef() const { return Udm::PointerAttr<PICML2Cadena::Component_cross_ph_PICML>(impl, meta_picmlComponentDef); }

		static Uml::CompositionParentRole meta__gen_cont_parent;
		Udm::ParentAttr<PICML2Cadena::_gen_cont> _gen_cont_parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, meta__gen_cont_parent); }

		Udm::ParentAttr<PICML2Cadena::_gen_cont> parent() const { return Udm::ParentAttr<PICML2Cadena::_gen_cont>(impl, Udm::NULLPARENTROLE); }
	};

	class  _gen_cont :  public Udm::Object {
	 public:
		static Uml::Class meta;

		_gen_cont() { }
		_gen_cont(Udm::ObjectImpl *impl) : Object(impl) { }
		_gen_cont(const _gen_cont &master) : Object(master) { }
		static _gen_cont Cast(const Udm::Object &a) { return __Cast(a, meta); }

		static _gen_cont Create(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		_gen_cont CreateInstance(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		_gen_cont CreateDerived(const Udm::Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<_gen_cont> Instances() { return Udm::InstantiatedAttr<PICML2Cadena::_gen_cont>(impl);}
		template <class Pred> Udm::InstantiatedAttr<_gen_cont, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML2Cadena::_gen_cont, Pred>(impl);}

		Udm::DerivedAttr<PICML2Cadena::_gen_cont> Derived() { return Udm::DerivedAttr<PICML2Cadena::_gen_cont>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML2Cadena::_gen_cont, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML2Cadena::_gen_cont, Pred>(impl);}

		Udm::ArchetypeAttr<PICML2Cadena::_gen_cont> Archetype() { return Udm::ArchetypeAttr<PICML2Cadena::_gen_cont>(impl);}

		static Uml::CompositionChildRole meta_PublishConnector_cross_ph_PICML_children;
		Udm::ChildrenAttr<PICML2Cadena::PublishConnector_cross_ph_PICML> PublishConnector_cross_ph_PICML_children() const { return Udm::ChildrenAttr<PICML2Cadena::PublishConnector_cross_ph_PICML>(impl, meta_PublishConnector_cross_ph_PICML_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred> PublishConnector_cross_ph_PICML_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred>(impl, meta_PublishConnector_cross_ph_PICML_children); }

		static Uml::CompositionChildRole meta_invoke_cross_ph_PICML_children;
		Udm::ChildrenAttr<PICML2Cadena::invoke_cross_ph_PICML> invoke_cross_ph_PICML_children() const { return Udm::ChildrenAttr<PICML2Cadena::invoke_cross_ph_PICML>(impl, meta_invoke_cross_ph_PICML_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::invoke_cross_ph_PICML, Pred> invoke_cross_ph_PICML_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::invoke_cross_ph_PICML, Pred>(impl, meta_invoke_cross_ph_PICML_children); }

		static Uml::CompositionChildRole meta_emit_cross_ph_PICML_children;
		Udm::ChildrenAttr<PICML2Cadena::emit_cross_ph_PICML> emit_cross_ph_PICML_children() const { return Udm::ChildrenAttr<PICML2Cadena::emit_cross_ph_PICML>(impl, meta_emit_cross_ph_PICML_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::emit_cross_ph_PICML, Pred> emit_cross_ph_PICML_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::emit_cross_ph_PICML, Pred>(impl, meta_emit_cross_ph_PICML_children); }

		static Uml::CompositionChildRole meta_ComponentAssembly_cross_ph_PICML_children;
		Udm::ChildrenAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML> ComponentAssembly_cross_ph_PICML_children() const { return Udm::ChildrenAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML>(impl, meta_ComponentAssembly_cross_ph_PICML_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML, Pred> ComponentAssembly_cross_ph_PICML_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML, Pred>(impl, meta_ComponentAssembly_cross_ph_PICML_children); }

		static Uml::CompositionChildRole meta_Port_cross_ph_PICML_children;
		Udm::ChildrenAttr<PICML2Cadena::Port_cross_ph_PICML> Port_cross_ph_PICML_children() const { return Udm::ChildrenAttr<PICML2Cadena::Port_cross_ph_PICML>(impl, meta_Port_cross_ph_PICML_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::Port_cross_ph_PICML, Pred> Port_cross_ph_PICML_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::Port_cross_ph_PICML, Pred>(impl, meta_Port_cross_ph_PICML_children); }

		static Uml::CompositionChildRole meta_Component_cross_ph_PICML_children;
		Udm::ChildrenAttr<PICML2Cadena::Component_cross_ph_PICML> Component_cross_ph_PICML_children() const { return Udm::ChildrenAttr<PICML2Cadena::Component_cross_ph_PICML>(impl, meta_Component_cross_ph_PICML_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::Component_cross_ph_PICML, Pred> Component_cross_ph_PICML_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::Component_cross_ph_PICML, Pred>(impl, meta_Component_cross_ph_PICML_children); }

		static Uml::CompositionChildRole meta_RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties_children;
		Udm::ChildrenAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties> RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties_children() const { return Udm::ChildrenAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties>(impl, meta_RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties, Pred> RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties, Pred>(impl, meta_RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties_children); }

		static Uml::CompositionChildRole meta_ESSConnection_cross_ph_cadena_scenario_children;
		Udm::ChildrenAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario> ESSConnection_cross_ph_cadena_scenario_children() const { return Udm::ChildrenAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario>(impl, meta_ESSConnection_cross_ph_cadena_scenario_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred> ESSConnection_cross_ph_cadena_scenario_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred>(impl, meta_ESSConnection_cross_ph_cadena_scenario_children); }

		static Uml::CompositionChildRole meta_FRConnection_cross_ph_cadena_scenario_children;
		Udm::ChildrenAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario> FRConnection_cross_ph_cadena_scenario_children() const { return Udm::ChildrenAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario>(impl, meta_FRConnection_cross_ph_cadena_scenario_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario, Pred> FRConnection_cross_ph_cadena_scenario_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario, Pred>(impl, meta_FRConnection_cross_ph_cadena_scenario_children); }

		static Uml::CompositionChildRole meta_ComponentPort_cross_ph_cadena_scenario_children;
		Udm::ChildrenAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario> ComponentPort_cross_ph_cadena_scenario_children() const { return Udm::ChildrenAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario>(impl, meta_ComponentPort_cross_ph_cadena_scenario_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario, Pred> ComponentPort_cross_ph_cadena_scenario_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario, Pred>(impl, meta_ComponentPort_cross_ph_cadena_scenario_children); }

		static Uml::CompositionChildRole meta_ComponentInstance_cross_ph_cadena_scenario_children;
		Udm::ChildrenAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario> ComponentInstance_cross_ph_cadena_scenario_children() const { return Udm::ChildrenAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario>(impl, meta_ComponentInstance_cross_ph_cadena_scenario_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario, Pred> ComponentInstance_cross_ph_cadena_scenario_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario, Pred>(impl, meta_ComponentInstance_cross_ph_cadena_scenario_children); }

		Udm::ChildrenAttr<PICML2Cadena::PublishConnector_cross_ph_PICML> PublishConnector_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::PublishConnector_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred> PublishConnector_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::PublishConnector_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::invoke_cross_ph_PICML> invoke_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::invoke_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::invoke_cross_ph_PICML, Pred> invoke_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::invoke_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::emit_cross_ph_PICML> emit_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::emit_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::emit_cross_ph_PICML, Pred> emit_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::emit_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML> ComponentAssembly_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML, Pred> ComponentAssembly_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ComponentAssembly_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::OutEventPort_cross_ph_PICML> OutEventPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::OutEventPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::OutEventPort_cross_ph_PICML, Pred> OutEventPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::OutEventPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML> ProvidedRequestPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML, Pred> ProvidedRequestPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ProvidedRequestPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML> RequiredRequestPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML, Pred> RequiredRequestPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::RequiredRequestPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::InEventPort_cross_ph_PICML> InEventPort_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::InEventPort_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::InEventPort_cross_ph_PICML, Pred> InEventPort_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::InEventPort_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::Port_cross_ph_PICML> Port_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::Port_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::Port_cross_ph_PICML, Pred> Port_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::Port_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::Component_cross_ph_PICML> Component_cross_ph_PICML_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::Component_cross_ph_PICML>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::Component_cross_ph_PICML, Pred> Component_cross_ph_PICML_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::Component_cross_ph_PICML, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties> RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties, Pred> RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::RootContainer_cross_ph_PICMLCadena_Xchange_embedded_EIProperties, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario> ESSConnection_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred> ESSConnection_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ESSConnection_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario> FRConnection_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario, Pred> FRConnection_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::FRConnection_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario> EventSink_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario, Pred> EventSink_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::EventSink_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario> EventSource_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario, Pred> EventSource_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::EventSource_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario> Receptacle_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario, Pred> Receptacle_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::Receptacle_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario> Facet_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario, Pred> Facet_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::Facet_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario> ComponentPort_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario, Pred> ComponentPort_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ComponentPort_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario> ComponentInstance_cross_ph_cadena_scenario_kind_children() const { return Udm::ChildrenAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario, Pred> ComponentInstance_cross_ph_cadena_scenario_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML2Cadena::ComponentInstance_cross_ph_cadena_scenario, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

}

#endif //MOBIES_PICML2CADENA_H