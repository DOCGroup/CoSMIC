// cpp(meta datanetwork format) source file CadenaScenario2PICMLAssembly.cpp generated from diagram CadenaScenario2PICMLAssembly
// generated on Tue May 11 01:41:09 2004

#include "CadenaScenario2PICMLAssembly.h"
#include "UmlExt.h"

#include "UdmStatic.h"

namespace CadenaScenario2PICMLAssembly {

	Uml::Diagram umldiagram;

	Uml::Class EventSource_cross_ph_cadena_scenario::meta;
	Uml::Class EventSink_cross_ph_cadena_scenario::meta;
	Uml::Class Receptacle_cross_ph_cadena_scenario::meta;
	Uml::Class Facet_cross_ph_cadena_scenario::meta;
	Uml::Class ComponentPort_cross_ph_cadena_scenario::meta;
	Uml::Class RequestPort_cross_ph_PICML::meta;
	Uml::Class EventPort_cross_ph_PICML::meta;
	Uml::Class ProvidedRequestPort_cross_ph_PICML::meta;
	Uml::Class RequiredRequestPort_cross_ph_PICML::meta;
	Uml::Class OutEventPort_cross_ph_PICML::meta;
	Uml::Class InEventPort_cross_ph_PICML::meta;
	Uml::Class Port_cross_ph_PICML::meta;
	Uml::Class _gen_cont::meta;
	Uml::Attribute ComponentPort_cross_ph_cadena_scenario::meta_rem_id;
	Uml::Attribute ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname;
	Uml::Attribute Port_cross_ph_PICML::meta_rem_id;
	Uml::Attribute Port_cross_ph_PICML::meta_rem_sysname;
	Uml::AssociationRole ComponentPort_cross_ph_cadena_scenario::meta_picmlPort;
	Uml::AssociationRole Port_cross_ph_PICML::meta_cadenaPort;
	Uml::CompositionParentRole ComponentPort_cross_ph_cadena_scenario::meta__gen_cont_parent;
	Uml::CompositionParentRole Port_cross_ph_PICML::meta__gen_cont_parent;
	Uml::CompositionChildRole _gen_cont::meta_Port_cross_ph_PICML_children;
	Uml::CompositionChildRole _gen_cont::meta_ComponentPort_cross_ph_cadena_scenario_children;
	void Creates()
	{
		EventSource_cross_ph_cadena_scenario::meta = Uml::Class::Create(umldiagram);
		EventSink_cross_ph_cadena_scenario::meta = Uml::Class::Create(umldiagram);
		Receptacle_cross_ph_cadena_scenario::meta = Uml::Class::Create(umldiagram);
		Facet_cross_ph_cadena_scenario::meta = Uml::Class::Create(umldiagram);
		ComponentPort_cross_ph_cadena_scenario::meta = Uml::Class::Create(umldiagram);
		RequestPort_cross_ph_PICML::meta = Uml::Class::Create(umldiagram);
		EventPort_cross_ph_PICML::meta = Uml::Class::Create(umldiagram);
		ProvidedRequestPort_cross_ph_PICML::meta = Uml::Class::Create(umldiagram);
		RequiredRequestPort_cross_ph_PICML::meta = Uml::Class::Create(umldiagram);
		OutEventPort_cross_ph_PICML::meta = Uml::Class::Create(umldiagram);
		InEventPort_cross_ph_PICML::meta = Uml::Class::Create(umldiagram);
		Port_cross_ph_PICML::meta = Uml::Class::Create(umldiagram);
		_gen_cont::meta = Uml::Class::Create(umldiagram);
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id = Uml::Attribute::Create(ComponentPort_cross_ph_cadena_scenario::meta);
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname = Uml::Attribute::Create(ComponentPort_cross_ph_cadena_scenario::meta);
		Port_cross_ph_PICML::meta_rem_id = Uml::Attribute::Create(Port_cross_ph_PICML::meta);
		Port_cross_ph_PICML::meta_rem_sysname = Uml::Attribute::Create(Port_cross_ph_PICML::meta);
	}
	void InitClassesAttributes()
	{
		EventSource_cross_ph_cadena_scenario::meta.name() = "EventSource_cross_ph_cadena_scenario";
		EventSource_cross_ph_cadena_scenario::meta.isAbstract() = false;
		EventSource_cross_ph_cadena_scenario::meta.from() = "cadena_scenario";
		EventSink_cross_ph_cadena_scenario::meta.name() = "EventSink_cross_ph_cadena_scenario";
		EventSink_cross_ph_cadena_scenario::meta.isAbstract() = false;
		EventSink_cross_ph_cadena_scenario::meta.from() = "cadena_scenario";
		Receptacle_cross_ph_cadena_scenario::meta.name() = "Receptacle_cross_ph_cadena_scenario";
		Receptacle_cross_ph_cadena_scenario::meta.isAbstract() = false;
		Receptacle_cross_ph_cadena_scenario::meta.from() = "cadena_scenario";
		Facet_cross_ph_cadena_scenario::meta.name() = "Facet_cross_ph_cadena_scenario";
		Facet_cross_ph_cadena_scenario::meta.isAbstract() = false;
		Facet_cross_ph_cadena_scenario::meta.from() = "cadena_scenario";
		ComponentPort_cross_ph_cadena_scenario::meta.name() = "ComponentPort_cross_ph_cadena_scenario";
		ComponentPort_cross_ph_cadena_scenario::meta.isAbstract() = false;
		ComponentPort_cross_ph_cadena_scenario::meta.from() = "cadena_scenario";
		RequestPort_cross_ph_PICML::meta.name() = "RequestPort_cross_ph_PICML";
		RequestPort_cross_ph_PICML::meta.isAbstract() = false;
		RequestPort_cross_ph_PICML::meta.from() = "PICML";
		EventPort_cross_ph_PICML::meta.name() = "EventPort_cross_ph_PICML";
		EventPort_cross_ph_PICML::meta.isAbstract() = false;
		EventPort_cross_ph_PICML::meta.from() = "PICML";
		ProvidedRequestPort_cross_ph_PICML::meta.name() = "ProvidedRequestPort_cross_ph_PICML";
		ProvidedRequestPort_cross_ph_PICML::meta.isAbstract() = false;
		ProvidedRequestPort_cross_ph_PICML::meta.from() = "PICML";
		RequiredRequestPort_cross_ph_PICML::meta.name() = "RequiredRequestPort_cross_ph_PICML";
		RequiredRequestPort_cross_ph_PICML::meta.isAbstract() = false;
		RequiredRequestPort_cross_ph_PICML::meta.from() = "PICML";
		OutEventPort_cross_ph_PICML::meta.name() = "OutEventPort_cross_ph_PICML";
		OutEventPort_cross_ph_PICML::meta.isAbstract() = false;
		OutEventPort_cross_ph_PICML::meta.from() = "PICML";
		InEventPort_cross_ph_PICML::meta.name() = "InEventPort_cross_ph_PICML";
		InEventPort_cross_ph_PICML::meta.isAbstract() = false;
		InEventPort_cross_ph_PICML::meta.from() = "PICML";
		Port_cross_ph_PICML::meta.name() = "Port_cross_ph_PICML";
		Port_cross_ph_PICML::meta.isAbstract() = false;
		Port_cross_ph_PICML::meta.from() = "PICML";
		_gen_cont::meta.name() = "_gen_cont";
		_gen_cont::meta.isAbstract() = false;
		
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.name() = "rem_id";
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.type() = "Integer";
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.min() = 1;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.max() = 1;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.nonpersistent() = false;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.registry() = false;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.ordered() = false;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.visibility() = "";
		ComponentPort_cross_ph_cadena_scenario::meta_rem_id.defvalue() = vector<string>();
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.name() = "rem_sysname";
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.type() = "String";
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.min() = 1;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.max() = 1;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.nonpersistent() = false;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.registry() = false;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.ordered() = false;
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.visibility() = "";
		ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname.defvalue() = vector<string>();
		Port_cross_ph_PICML::meta_rem_id.name() = "rem_id";
		Port_cross_ph_PICML::meta_rem_id.type() = "Integer";
		Port_cross_ph_PICML::meta_rem_id.min() = 1;
		Port_cross_ph_PICML::meta_rem_id.max() = 1;
		Port_cross_ph_PICML::meta_rem_id.nonpersistent() = false;
		Port_cross_ph_PICML::meta_rem_id.registry() = false;
		Port_cross_ph_PICML::meta_rem_id.ordered() = false;
		Port_cross_ph_PICML::meta_rem_id.visibility() = "";
		Port_cross_ph_PICML::meta_rem_id.defvalue() = vector<string>();
		Port_cross_ph_PICML::meta_rem_sysname.name() = "rem_sysname";
		Port_cross_ph_PICML::meta_rem_sysname.type() = "String";
		Port_cross_ph_PICML::meta_rem_sysname.min() = 1;
		Port_cross_ph_PICML::meta_rem_sysname.max() = 1;
		Port_cross_ph_PICML::meta_rem_sysname.nonpersistent() = false;
		Port_cross_ph_PICML::meta_rem_sysname.registry() = false;
		Port_cross_ph_PICML::meta_rem_sysname.ordered() = false;
		Port_cross_ph_PICML::meta_rem_sysname.visibility() = "";
		Port_cross_ph_PICML::meta_rem_sysname.defvalue() = vector<string>();
		
	}
	void Initialize()
	{
		static bool first = true;
		if(!first) return;
		first = false;
		 Uml::Initialize();

		ASSERT( umldiagram == Udm::null );
		UdmStatic::StaticDataNetwork * meta_dn = new UdmStatic::StaticDataNetwork(Uml::diagram);
		meta_dn->CreateNew("CadenaScenario2PICMLAssembly.mem", "", Uml::Diagram::meta, Udm::CHANGES_LOST_DEFAULT);
		umldiagram = Uml::Diagram::Cast(meta_dn->GetRootObject());
		umldiagram.name() ="CadenaScenario2PICMLAssembly";
		umldiagram.version() ="1.00";
		Creates();
		InitClassesAttributes();
		Uml::InitDiagram(umldiagram, "CadenaScenario2PICMLAssembly", "1.00");

		{
			Uml::Association ass = Uml::Association::Create(umldiagram);
			ComponentPort_cross_ph_cadena_scenario::meta_picmlPort = Uml::AssociationRole::Create(ass);
			ComponentPort_cross_ph_cadena_scenario::meta_picmlPort.name() = "picmlPort";
			ComponentPort_cross_ph_cadena_scenario::meta_picmlPort.min() = 0;
			ComponentPort_cross_ph_cadena_scenario::meta_picmlPort.max() = -1;
			ComponentPort_cross_ph_cadena_scenario::meta_picmlPort.isNavigable() = true;
			ComponentPort_cross_ph_cadena_scenario::meta_picmlPort.isPrimary() = false;
			ComponentPort_cross_ph_cadena_scenario::meta_picmlPort.target() = Port_cross_ph_PICML::meta;
			Port_cross_ph_PICML::meta_cadenaPort = Uml::AssociationRole::Create(ass);
			Port_cross_ph_PICML::meta_cadenaPort.name() = "cadenaPort";
			Port_cross_ph_PICML::meta_cadenaPort.min() = 0;
			Port_cross_ph_PICML::meta_cadenaPort.max() = -1;
			Port_cross_ph_PICML::meta_cadenaPort.isNavigable() = true;
			Port_cross_ph_PICML::meta_cadenaPort.isPrimary() = false;
			Port_cross_ph_PICML::meta_cadenaPort.target() = ComponentPort_cross_ph_cadena_scenario::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			ComponentPort_cross_ph_cadena_scenario::meta__gen_cont_parent = Uml::CompositionParentRole::Create(comp);
			ComponentPort_cross_ph_cadena_scenario::meta__gen_cont_parent.name() = "_gen_cont_parent";
			ComponentPort_cross_ph_cadena_scenario::meta__gen_cont_parent.isNavigable() = true;
			ComponentPort_cross_ph_cadena_scenario::meta__gen_cont_parent.target() = _gen_cont::meta;
			_gen_cont::meta_ComponentPort_cross_ph_cadena_scenario_children = Uml::CompositionChildRole::Create(comp);
			_gen_cont::meta_ComponentPort_cross_ph_cadena_scenario_children.name() = "ComponentPort_cross_ph_cadena_scenario";
			_gen_cont::meta_ComponentPort_cross_ph_cadena_scenario_children.min() = 0;
			_gen_cont::meta_ComponentPort_cross_ph_cadena_scenario_children.max() = -1;
			_gen_cont::meta_ComponentPort_cross_ph_cadena_scenario_children.isNavigable() = true;
			_gen_cont::meta_ComponentPort_cross_ph_cadena_scenario_children.target() = ComponentPort_cross_ph_cadena_scenario::meta;
		}
		{
			Uml::Composition comp = Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
		
			Port_cross_ph_PICML::meta__gen_cont_parent = Uml::CompositionParentRole::Create(comp);
			Port_cross_ph_PICML::meta__gen_cont_parent.name() = "_gen_cont_parent";
			Port_cross_ph_PICML::meta__gen_cont_parent.isNavigable() = true;
			Port_cross_ph_PICML::meta__gen_cont_parent.target() = _gen_cont::meta;
			_gen_cont::meta_Port_cross_ph_PICML_children = Uml::CompositionChildRole::Create(comp);
			_gen_cont::meta_Port_cross_ph_PICML_children.name() = "Port_cross_ph_PICML";
			_gen_cont::meta_Port_cross_ph_PICML_children.min() = 0;
			_gen_cont::meta_Port_cross_ph_PICML_children.max() = -1;
			_gen_cont::meta_Port_cross_ph_PICML_children.isNavigable() = true;
			_gen_cont::meta_Port_cross_ph_PICML_children.target() = Port_cross_ph_PICML::meta;
		}
		ComponentPort_cross_ph_cadena_scenario::meta.subTypes() +=  EventSource_cross_ph_cadena_scenario::meta;
		ComponentPort_cross_ph_cadena_scenario::meta.subTypes() +=  EventSink_cross_ph_cadena_scenario::meta;
		ComponentPort_cross_ph_cadena_scenario::meta.subTypes() +=  Receptacle_cross_ph_cadena_scenario::meta;
		ComponentPort_cross_ph_cadena_scenario::meta.subTypes() +=  Facet_cross_ph_cadena_scenario::meta;
		RequestPort_cross_ph_PICML::meta.subTypes() +=  ProvidedRequestPort_cross_ph_PICML::meta;
		RequestPort_cross_ph_PICML::meta.subTypes() +=  RequiredRequestPort_cross_ph_PICML::meta;
		EventPort_cross_ph_PICML::meta.subTypes() +=  OutEventPort_cross_ph_PICML::meta;
		EventPort_cross_ph_PICML::meta.subTypes() +=  InEventPort_cross_ph_PICML::meta;
		Port_cross_ph_PICML::meta.subTypes() +=  RequestPort_cross_ph_PICML::meta;
		Port_cross_ph_PICML::meta.subTypes() +=  EventPort_cross_ph_PICML::meta;
		
	}
	void Initialize(const Uml::Diagram & dgr)
	{
		umldiagram = dgr;
		Uml::SetClass(EventSource_cross_ph_cadena_scenario::meta, umldiagram, "EventSource_cross_ph_cadena_scenario");

		Uml::SetClass(EventSink_cross_ph_cadena_scenario::meta, umldiagram, "EventSink_cross_ph_cadena_scenario");

		Uml::SetClass(Receptacle_cross_ph_cadena_scenario::meta, umldiagram, "Receptacle_cross_ph_cadena_scenario");

		Uml::SetClass(Facet_cross_ph_cadena_scenario::meta, umldiagram, "Facet_cross_ph_cadena_scenario");

		Uml::SetClass(ComponentPort_cross_ph_cadena_scenario::meta, umldiagram, "ComponentPort_cross_ph_cadena_scenario");
		Uml::SetAttribute(ComponentPort_cross_ph_cadena_scenario::meta_rem_id,ComponentPort_cross_ph_cadena_scenario::meta, "rem_id");
		Uml::SetAttribute(ComponentPort_cross_ph_cadena_scenario::meta_rem_sysname,ComponentPort_cross_ph_cadena_scenario::meta, "rem_sysname");
		Uml::SetGenericRole(ComponentPort_cross_ph_cadena_scenario::meta__gen_cont_parent,ComponentPort_cross_ph_cadena_scenario::meta, "");
		Uml::SetGenericRole(ComponentPort_cross_ph_cadena_scenario::meta_picmlPort,Port_cross_ph_PICML::meta, "cadenaPort");

		Uml::SetClass(RequestPort_cross_ph_PICML::meta, umldiagram, "RequestPort_cross_ph_PICML");

		Uml::SetClass(EventPort_cross_ph_PICML::meta, umldiagram, "EventPort_cross_ph_PICML");

		Uml::SetClass(ProvidedRequestPort_cross_ph_PICML::meta, umldiagram, "ProvidedRequestPort_cross_ph_PICML");

		Uml::SetClass(RequiredRequestPort_cross_ph_PICML::meta, umldiagram, "RequiredRequestPort_cross_ph_PICML");

		Uml::SetClass(OutEventPort_cross_ph_PICML::meta, umldiagram, "OutEventPort_cross_ph_PICML");

		Uml::SetClass(InEventPort_cross_ph_PICML::meta, umldiagram, "InEventPort_cross_ph_PICML");

		Uml::SetClass(Port_cross_ph_PICML::meta, umldiagram, "Port_cross_ph_PICML");
		Uml::SetAttribute(Port_cross_ph_PICML::meta_rem_id,Port_cross_ph_PICML::meta, "rem_id");
		Uml::SetAttribute(Port_cross_ph_PICML::meta_rem_sysname,Port_cross_ph_PICML::meta, "rem_sysname");
		Uml::SetGenericRole(Port_cross_ph_PICML::meta__gen_cont_parent,Port_cross_ph_PICML::meta, "");
		Uml::SetGenericRole(Port_cross_ph_PICML::meta_cadenaPort,ComponentPort_cross_ph_cadena_scenario::meta, "picmlPort");

		Uml::SetClass(_gen_cont::meta, umldiagram, "_gen_cont");
		Uml::SetGenericRole(_gen_cont::meta_Port_cross_ph_PICML_children,_gen_cont::meta, "");
		Uml::SetGenericRole(_gen_cont::meta_ComponentPort_cross_ph_cadena_scenario_children,_gen_cont::meta, "");

		
	}
	 Udm::UdmDiagram diagram = { &umldiagram, Initialize };
	static struct _regClass
	{
		_regClass()
		{
			Udm::MetaDepository::StoreDiagram("CadenaScenario2PICMLAssembly", diagram);
		};
		~_regClass()
		{
			Udm::MetaDepository::RemoveDiagram("CadenaScenario2PICMLAssembly");
		};
	} __regUnUsed;

}
// END CadenaScenario2PICMLAssembly.cpp
