// cpp(meta datanetwork format) source file HFSM.cpp generated from diagram HFSM
// generated on Thu May 29 18:22:44 2008

#include "HFSM.h"
#include "UmlExt.h"

#include "UdmStatic.h"

namespace HFSM {

	::Uml::Diagram umldiagram;

		::Uml::Class InputSequence::meta;
		::Uml::Class Events::meta;
		::Uml::Class Sequence::meta;
		::Uml::Class State::meta;
		::Uml::Class Transition::meta;
		::Uml::Class RootFolder::meta;
		::Uml::Class MgaObject::meta;
		::Uml::Attribute Events::meta_Delay;
		::Uml::Attribute State::meta_StartState;
		::Uml::Attribute Transition::meta_Event;
		::Uml::Attribute RootFolder::meta_name;
		::Uml::Attribute MgaObject::meta_position;
		::Uml::Attribute MgaObject::meta_name;
		::Uml::AssociationRole Events::meta_srcSequence, Events::meta_srcSequence_rev;
		::Uml::AssociationRole Events::meta_dstSequence, Events::meta_dstSequence_rev;
		::Uml::AssociationRole Sequence::meta_dstSequence_end_;
		::Uml::AssociationRole Sequence::meta_srcSequence_end_;
		::Uml::AssociationRole State::meta_srcTransition, State::meta_srcTransition_rev;
		::Uml::AssociationRole State::meta_dstTransition, State::meta_dstTransition_rev;
		::Uml::AssociationRole Transition::meta_dstTransition_end_;
		::Uml::AssociationRole Transition::meta_srcTransition_end_;
		::Uml::CompositionParentRole InputSequence::meta_RootFolder_parent;
		::Uml::CompositionParentRole Events::meta_InputSequence_parent;
		::Uml::CompositionParentRole Sequence::meta_InputSequence_parent;
		::Uml::CompositionParentRole State::meta_State_parent;
		::Uml::CompositionParentRole State::meta_RootFolder_parent;
		::Uml::CompositionParentRole Transition::meta_State_parent;
		::Uml::CompositionParentRole RootFolder::meta_RootFolder_parent;
		::Uml::CompositionChildRole InputSequence::meta_Events_children;
		::Uml::CompositionChildRole InputSequence::meta_Sequence_children;
		::Uml::CompositionChildRole State::meta_State_child;
		::Uml::CompositionChildRole State::meta_Transition_child;
		::Uml::CompositionChildRole RootFolder::meta_State_children;
		::Uml::CompositionChildRole RootFolder::meta_InputSequence_children;
		::Uml::CompositionChildRole RootFolder::meta_RootFolder_children;
		void Creates()
		{
			InputSequence::meta = ::Uml::Class::Create(umldiagram);
			Events::meta = ::Uml::Class::Create(umldiagram);
			Sequence::meta = ::Uml::Class::Create(umldiagram);
			State::meta = ::Uml::Class::Create(umldiagram);
			Transition::meta = ::Uml::Class::Create(umldiagram);
			RootFolder::meta = ::Uml::Class::Create(umldiagram);
			MgaObject::meta = ::Uml::Class::Create(umldiagram);
			Events::meta_Delay = ::Uml::Attribute::Create(Events::meta);
			State::meta_StartState = ::Uml::Attribute::Create(State::meta);
			Transition::meta_Event = ::Uml::Attribute::Create(Transition::meta);
			RootFolder::meta_name = ::Uml::Attribute::Create(RootFolder::meta);
			MgaObject::meta_position = ::Uml::Attribute::Create(MgaObject::meta);
			MgaObject::meta_name = ::Uml::Attribute::Create(MgaObject::meta);
		}
		void InitClassesAttributes()
		{
			InputSequence::meta.name() = "InputSequence";
			InputSequence::meta.isAbstract() = false;
			InputSequence::meta.stereotype() = "Model";
			Events::meta.name() = "Events";
			Events::meta.isAbstract() = false;
			Events::meta.stereotype() = "Atom";
			Sequence::meta.name() = "Sequence";
			Sequence::meta.isAbstract() = false;
			Sequence::meta.stereotype() = "Connection";
			State::meta.name() = "State";
			State::meta.isAbstract() = false;
			State::meta.stereotype() = "Model";
			Transition::meta.name() = "Transition";
			Transition::meta.isAbstract() = false;
			Transition::meta.stereotype() = "Connection";
			RootFolder::meta.name() = "RootFolder";
			RootFolder::meta.isAbstract() = false;
			RootFolder::meta.stereotype() = "Folder";
			MgaObject::meta.name() = "MgaObject";
			MgaObject::meta.isAbstract() = true;
			
			vector<string> Events_Delay_dva;
			Events_Delay_dva.push_back("2");
			Events::meta_Delay.name() = "Delay";
			Events::meta_Delay.type() = "Integer";
			Events::meta_Delay.min() = 1;
			Events::meta_Delay.max() = 1;
			Events::meta_Delay.nonpersistent() = false;
			Events::meta_Delay.registry() = false;
			Events::meta_Delay.ordered() = false;
			Events::meta_Delay.visibility() = "public";
			Events::meta_Delay.defvalue() = Events_Delay_dva;
			vector<string> State_StartState_dva;
			State_StartState_dva.push_back("false");
			State::meta_StartState.name() = "StartState";
			State::meta_StartState.type() = "Boolean";
			State::meta_StartState.min() = 1;
			State::meta_StartState.max() = 1;
			State::meta_StartState.nonpersistent() = false;
			State::meta_StartState.registry() = false;
			State::meta_StartState.ordered() = false;
			State::meta_StartState.visibility() = "public";
			State::meta_StartState.defvalue() = State_StartState_dva;
			Transition::meta_Event.name() = "Event";
			Transition::meta_Event.type() = "String";
			Transition::meta_Event.min() = 1;
			Transition::meta_Event.max() = 1;
			Transition::meta_Event.nonpersistent() = false;
			Transition::meta_Event.registry() = false;
			Transition::meta_Event.ordered() = false;
			Transition::meta_Event.visibility() = "public";
			Transition::meta_Event.defvalue() = vector<string>();
			RootFolder::meta_name.name() = "name";
			RootFolder::meta_name.type() = "String";
			RootFolder::meta_name.min() = 0;
			RootFolder::meta_name.max() = 1;
			RootFolder::meta_name.nonpersistent() = false;
			RootFolder::meta_name.registry() = false;
			RootFolder::meta_name.ordered() = false;
			RootFolder::meta_name.visibility() = "public";
			RootFolder::meta_name.defvalue() = vector<string>();
			MgaObject::meta_position.name() = "position";
			MgaObject::meta_position.type() = "String";
			MgaObject::meta_position.min() = 0;
			MgaObject::meta_position.max() = 1;
			MgaObject::meta_position.nonpersistent() = false;
			MgaObject::meta_position.registry() = false;
			MgaObject::meta_position.ordered() = false;
			MgaObject::meta_position.visibility() = "public";
			MgaObject::meta_position.defvalue() = vector<string>();
			MgaObject::meta_name.name() = "name";
			MgaObject::meta_name.type() = "String";
			MgaObject::meta_name.min() = 0;
			MgaObject::meta_name.max() = 1;
			MgaObject::meta_name.nonpersistent() = false;
			MgaObject::meta_name.registry() = false;
			MgaObject::meta_name.ordered() = false;
			MgaObject::meta_name.visibility() = "public";
			MgaObject::meta_name.defvalue() = vector<string>();
			
		}
		void CreatesNamespaces()
		{
		}
		void InitNamespaces()
		{
		}
		void InitAssociation0()
		{
			::Uml::Association ass = ::Uml::Association::Create(umldiagram);
			ass.name() = "Sequence";
			ass.assocClass() = ::HFSM::Sequence::meta;
			::HFSM::Events::meta_srcSequence = ::Uml::AssociationRole::Create(ass);
			::HFSM::Events::meta_srcSequence.name() = "srcSequence";
			::HFSM::Events::meta_srcSequence.min() = 0;
			::HFSM::Events::meta_srcSequence.max() = 1;
			::HFSM::Events::meta_srcSequence.isNavigable() = true;
			::HFSM::Events::meta_srcSequence.isPrimary() = false;
			::HFSM::Events::meta_srcSequence.target() = ::HFSM::Events::meta;
			::HFSM::Sequence::meta_srcSequence_end_ = ::HFSM::Events::meta_dstSequence_rev = ::HFSM::Events::meta_srcSequence;
			::HFSM::Events::meta_dstSequence = ::Uml::AssociationRole::Create(ass);
			::HFSM::Events::meta_dstSequence.name() = "dstSequence";
			::HFSM::Events::meta_dstSequence.min() = 0;
			::HFSM::Events::meta_dstSequence.max() = 1;
			::HFSM::Events::meta_dstSequence.isNavigable() = true;
			::HFSM::Events::meta_dstSequence.isPrimary() = false;
			::HFSM::Events::meta_dstSequence.target() = ::HFSM::Events::meta;
			::HFSM::Sequence::meta_dstSequence_end_ = ::HFSM::Events::meta_srcSequence_rev = ::HFSM::Events::meta_dstSequence;
		};
		void InitAssociation1()
		{
			::Uml::Association ass = ::Uml::Association::Create(umldiagram);
			ass.name() = "Transition";
			ass.assocClass() = ::HFSM::Transition::meta;
			::HFSM::State::meta_srcTransition = ::Uml::AssociationRole::Create(ass);
			::HFSM::State::meta_srcTransition.name() = "srcTransition";
			::HFSM::State::meta_srcTransition.min() = 1;
			::HFSM::State::meta_srcTransition.max() = 1;
			::HFSM::State::meta_srcTransition.isNavigable() = true;
			::HFSM::State::meta_srcTransition.isPrimary() = false;
			::HFSM::State::meta_srcTransition.target() = ::HFSM::State::meta;
			::HFSM::Transition::meta_srcTransition_end_ = ::HFSM::State::meta_dstTransition_rev = ::HFSM::State::meta_srcTransition;
			::HFSM::State::meta_dstTransition = ::Uml::AssociationRole::Create(ass);
			::HFSM::State::meta_dstTransition.name() = "dstTransition";
			::HFSM::State::meta_dstTransition.min() = 1;
			::HFSM::State::meta_dstTransition.max() = 1;
			::HFSM::State::meta_dstTransition.isNavigable() = true;
			::HFSM::State::meta_dstTransition.isPrimary() = false;
			::HFSM::State::meta_dstTransition.target() = ::HFSM::State::meta;
			::HFSM::Transition::meta_dstTransition_end_ = ::HFSM::State::meta_srcTransition_rev = ::HFSM::State::meta_dstTransition;
		};
		void InitComposition0()
		{
			::Uml::Composition comp = ::Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
			::HFSM::Events::meta_InputSequence_parent = ::Uml::CompositionParentRole::Create(comp);
			::HFSM::Events::meta_InputSequence_parent.name() = "InputSequence_parent";
			::HFSM::Events::meta_InputSequence_parent.isNavigable() = true;
			::HFSM::Events::meta_InputSequence_parent.target() = ::HFSM::InputSequence::meta;
			::HFSM::InputSequence::meta_Events_children = ::Uml::CompositionChildRole::Create(comp);
			::HFSM::InputSequence::meta_Events_children.name() = "Events";
			::HFSM::InputSequence::meta_Events_children.min() = 0;
			::HFSM::InputSequence::meta_Events_children.max() = -1;
			::HFSM::InputSequence::meta_Events_children.isNavigable() = true;
			::HFSM::InputSequence::meta_Events_children.target() = ::HFSM::Events::meta;
		}
		void InitComposition1()
		{
			::Uml::Composition comp = ::Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
			::HFSM::Sequence::meta_InputSequence_parent = ::Uml::CompositionParentRole::Create(comp);
			::HFSM::Sequence::meta_InputSequence_parent.name() = "InputSequence_parent";
			::HFSM::Sequence::meta_InputSequence_parent.isNavigable() = true;
			::HFSM::Sequence::meta_InputSequence_parent.target() = ::HFSM::InputSequence::meta;
			::HFSM::InputSequence::meta_Sequence_children = ::Uml::CompositionChildRole::Create(comp);
			::HFSM::InputSequence::meta_Sequence_children.name() = "Sequence";
			::HFSM::InputSequence::meta_Sequence_children.min() = 0;
			::HFSM::InputSequence::meta_Sequence_children.max() = -1;
			::HFSM::InputSequence::meta_Sequence_children.isNavigable() = true;
			::HFSM::InputSequence::meta_Sequence_children.target() = ::HFSM::Sequence::meta;
		}
		void InitComposition2()
		{
			::Uml::Composition comp = ::Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
			::HFSM::State::meta_State_parent = ::Uml::CompositionParentRole::Create(comp);
			::HFSM::State::meta_State_parent.name() = "State_parent";
			::HFSM::State::meta_State_parent.isNavigable() = true;
			::HFSM::State::meta_State_parent.target() = ::HFSM::State::meta;
			::HFSM::State::meta_State_child = ::Uml::CompositionChildRole::Create(comp);
			::HFSM::State::meta_State_child.name() = "State";
			::HFSM::State::meta_State_child.min() = 1;
			::HFSM::State::meta_State_child.max() = 1;
			::HFSM::State::meta_State_child.isNavigable() = true;
			::HFSM::State::meta_State_child.target() = ::HFSM::State::meta;
		}
		void InitComposition3()
		{
			::Uml::Composition comp = ::Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
			::HFSM::Transition::meta_State_parent = ::Uml::CompositionParentRole::Create(comp);
			::HFSM::Transition::meta_State_parent.name() = "State_parent";
			::HFSM::Transition::meta_State_parent.isNavigable() = true;
			::HFSM::Transition::meta_State_parent.target() = ::HFSM::State::meta;
			::HFSM::State::meta_Transition_child = ::Uml::CompositionChildRole::Create(comp);
			::HFSM::State::meta_Transition_child.name() = "Transition";
			::HFSM::State::meta_Transition_child.min() = 1;
			::HFSM::State::meta_Transition_child.max() = 1;
			::HFSM::State::meta_Transition_child.isNavigable() = true;
			::HFSM::State::meta_Transition_child.target() = ::HFSM::Transition::meta;
		}
		void InitComposition4()
		{
			::Uml::Composition comp = ::Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
			::HFSM::State::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::HFSM::State::meta_RootFolder_parent.name() = "RootFolder_parent";
			::HFSM::State::meta_RootFolder_parent.isNavigable() = true;
			::HFSM::State::meta_RootFolder_parent.target() = ::HFSM::RootFolder::meta;
			::HFSM::RootFolder::meta_State_children = ::Uml::CompositionChildRole::Create(comp);
			::HFSM::RootFolder::meta_State_children.name() = "State";
			::HFSM::RootFolder::meta_State_children.min() = 0;
			::HFSM::RootFolder::meta_State_children.max() = -1;
			::HFSM::RootFolder::meta_State_children.isNavigable() = true;
			::HFSM::RootFolder::meta_State_children.target() = ::HFSM::State::meta;
		}
		void InitComposition5()
		{
			::Uml::Composition comp = ::Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
			::HFSM::InputSequence::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::HFSM::InputSequence::meta_RootFolder_parent.name() = "RootFolder_parent";
			::HFSM::InputSequence::meta_RootFolder_parent.isNavigable() = true;
			::HFSM::InputSequence::meta_RootFolder_parent.target() = ::HFSM::RootFolder::meta;
			::HFSM::RootFolder::meta_InputSequence_children = ::Uml::CompositionChildRole::Create(comp);
			::HFSM::RootFolder::meta_InputSequence_children.name() = "InputSequence";
			::HFSM::RootFolder::meta_InputSequence_children.min() = 0;
			::HFSM::RootFolder::meta_InputSequence_children.max() = -1;
			::HFSM::RootFolder::meta_InputSequence_children.isNavigable() = true;
			::HFSM::RootFolder::meta_InputSequence_children.target() = ::HFSM::InputSequence::meta;
		}
		void InitComposition6()
		{
			::Uml::Composition comp = ::Uml::Composition::Create(umldiagram);
			comp.nonpersistent() =false;
			::HFSM::RootFolder::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::HFSM::RootFolder::meta_RootFolder_parent.name() = "RootFolder_parent";
			::HFSM::RootFolder::meta_RootFolder_parent.isNavigable() = true;
			::HFSM::RootFolder::meta_RootFolder_parent.target() = ::HFSM::RootFolder::meta;
			::HFSM::RootFolder::meta_RootFolder_children = ::Uml::CompositionChildRole::Create(comp);
			::HFSM::RootFolder::meta_RootFolder_children.name() = "RootFolder";
			::HFSM::RootFolder::meta_RootFolder_children.min() = 0;
			::HFSM::RootFolder::meta_RootFolder_children.max() = -1;
			::HFSM::RootFolder::meta_RootFolder_children.isNavigable() = true;
			::HFSM::RootFolder::meta_RootFolder_children.target() = ::HFSM::RootFolder::meta;
		}
		void InitCrossNSCompositions()
		{
		}
		void InitInheritence()
		{
			MgaObject::meta.subTypes() +=  ::HFSM::InputSequence::meta;
			MgaObject::meta.subTypes() +=  ::HFSM::Events::meta;
			MgaObject::meta.subTypes() +=  ::HFSM::Sequence::meta;
			MgaObject::meta.subTypes() +=  ::HFSM::State::meta;
			MgaObject::meta.subTypes() +=  ::HFSM::Transition::meta;
		}
		void InitCrossNSInheritence()
		{
		}
	 void InitializeDgr()
	{
		Creates();
		InitClassesAttributes();
		CreatesNamespaces();
		InitNamespaces();
			InitAssociation0();
			InitAssociation1();
		InitComposition0();
		InitComposition1();
		InitComposition2();
		InitComposition3();
		InitComposition4();
		InitComposition5();
		InitComposition6();
		InitInheritence();
		
	}
		 void InitializeDgr(const ::Uml::Diagram & dgr)
		{
			::Uml::SetClass(InputSequence::meta, dgr, "InputSequence");
			::Uml::SetClass(Events::meta, dgr, "Events");
			::Uml::SetAttribute(Events::meta_Delay,Events::meta, "Delay");
			::Uml::SetClass(Sequence::meta, dgr, "Sequence");
			::Uml::SetClass(State::meta, dgr, "State");
			::Uml::SetAttribute(State::meta_StartState,State::meta, "StartState");
			::Uml::SetClass(Transition::meta, dgr, "Transition");
			::Uml::SetAttribute(Transition::meta_Event,Transition::meta, "Event");
			::Uml::SetClass(RootFolder::meta, dgr, "RootFolder");
			::Uml::SetAttribute(RootFolder::meta_name,RootFolder::meta, "name");
			::Uml::SetClass(MgaObject::meta, dgr, "MgaObject");
			::Uml::SetAttribute(MgaObject::meta_position,MgaObject::meta, "position");
			::Uml::SetAttribute(MgaObject::meta_name,MgaObject::meta, "name");
			//composition child roles 
			::Uml::SetParentRole(InputSequence::meta_RootFolder_parent,InputSequence::meta,::HFSM::RootFolder::meta, "", "");
			::Uml::SetParentRole(Events::meta_InputSequence_parent,Events::meta,::HFSM::InputSequence::meta, "", "");
			::Uml::SetParentRole(Sequence::meta_InputSequence_parent,Sequence::meta,::HFSM::InputSequence::meta, "", "");
			::Uml::SetParentRole(State::meta_State_parent,State::meta,::HFSM::State::meta, "", "");
			::Uml::SetParentRole(State::meta_RootFolder_parent,State::meta,::HFSM::RootFolder::meta, "", "");
			::Uml::SetParentRole(Transition::meta_State_parent,Transition::meta,::HFSM::State::meta, "", "");
			::Uml::SetParentRole(RootFolder::meta_RootFolder_parent,RootFolder::meta,::HFSM::RootFolder::meta, "", "");
			// composition parentroles 
			::Uml::SetChildRole(InputSequence::meta_Events_children,InputSequence::meta,::HFSM::Events::meta, "", "");
			::Uml::SetChildRole(InputSequence::meta_Sequence_children,InputSequence::meta,::HFSM::Sequence::meta, "", "");
			::Uml::SetChildRole(State::meta_State_child,State::meta,::HFSM::State::meta, "", "");
			::Uml::SetChildRole(State::meta_Transition_child,State::meta,::HFSM::Transition::meta, "", "");
			::Uml::SetChildRole(RootFolder::meta_State_children,RootFolder::meta,::HFSM::State::meta, "", "");
			::Uml::SetChildRole(RootFolder::meta_InputSequence_children,RootFolder::meta,::HFSM::InputSequence::meta, "", "");
			::Uml::SetChildRole(RootFolder::meta_RootFolder_children,RootFolder::meta,::HFSM::RootFolder::meta, "", "");
			// Association roles 
			::Uml::SetAssocRole(Events::meta_srcSequence,Events::meta,::HFSM::Events::meta, "dstSequence");
			::HFSM::Events::meta_dstSequence_rev = Events::meta_srcSequence;
			::Uml::SetAssocRole(Events::meta_dstSequence,Events::meta,::HFSM::Events::meta, "srcSequence");
			::HFSM::Events::meta_srcSequence_rev = Events::meta_dstSequence;
			::Uml::SetAssocRole(State::meta_srcTransition,State::meta,::HFSM::State::meta, "dstTransition");
			::HFSM::State::meta_dstTransition_rev = State::meta_srcTransition;
			::Uml::SetAssocRole(State::meta_dstTransition,State::meta,::HFSM::State::meta, "srcTransition");
			::HFSM::State::meta_srcTransition_rev = State::meta_dstTransition;
			Sequence::meta_dstSequence_end_ = ::HFSM::Events::meta_dstSequence;
			Sequence::meta_srcSequence_end_ = ::HFSM::Events::meta_srcSequence;
			Transition::meta_dstTransition_end_ = ::HFSM::State::meta_dstTransition;
			Transition::meta_srcTransition_end_ = ::HFSM::State::meta_srcTransition;

			// namespaces

			
		}
	 void Initialize()
	{
		static bool first = true;
		if(!first) return;
		first = false;
		::Uml::Initialize();

		ASSERT( umldiagram == Udm::null );
		UdmStatic::StaticDataNetwork * meta_dn = new UdmStatic::StaticDataNetwork(::Uml::diagram);
		meta_dn->CreateNew("HFSM.mem", "", ::Uml::Diagram::meta, Udm::CHANGES_LOST_DEFAULT);
		umldiagram = ::Uml::Diagram::Cast(meta_dn->GetRootObject());
		umldiagram.name() ="HFSM";
		umldiagram.version() ="1.00";
		InitializeDgr();

		InitCrossNSInheritence();
		InitCrossNSCompositions();

	};

	 void Initialize(const ::Uml::Diagram &dgr)
	{
		umldiagram = dgr;
		InitializeDgr(dgr);

	};

	 Udm::UdmDiagram diagram = { &umldiagram, Initialize };
	static struct _regClass
	{
		_regClass()
		{
			Udm::MetaDepository::StoreDiagram("HFSM", diagram);
		};
		~_regClass()
		{
			Udm::MetaDepository::RemoveDiagram("HFSM");
		};
	} __regUnUsed;

}
// END HFSM.cpp
