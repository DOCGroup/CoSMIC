// cpp (meta datanetwork format) source file HFSM.cpp
// generated from diagram HFSM
// generated on Mon Nov 03 23:18:43 2008

#include "HFSM.h"
#include <UmlExt.h>
#include <UdmStatic.h>


namespace HFSM {

	::Uml::Class InputSequence::meta;
	::Uml::CompositionChildRole InputSequence::meta_Events_children;
	::Uml::CompositionChildRole InputSequence::meta_Sequence_children;
	::Uml::CompositionParentRole InputSequence::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& InputSequence::_type2CCRole< InputSequence::CR_Events_children >() const { return meta_Events_children; }
	template <> const ::Uml::CompositionChildRole& InputSequence::_type2CCRole< InputSequence::CR_Sequence_children >() const { return meta_Sequence_children; }
	template <> const ::Uml::CompositionParentRole& InputSequence::_type2CPRole< InputSequence::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class Events::meta;
	::Uml::Attribute Events::meta_Delay;
	::Uml::AssociationRole Events::meta_srcSequence;
	::Uml::AssociationRole Events::meta_srcSequence_rev;
	::Uml::AssociationRole Events::meta_dstSequence;
	::Uml::AssociationRole Events::meta_dstSequence_rev;
	::Uml::CompositionParentRole Events::meta_InputSequence_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Events::_type2ACARole< Events::AR_srcSequence >() const { return make_pair(&meta_srcSequence, &meta_srcSequence_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Events::_type2ACARole< Events::AR_dstSequence >() const { return make_pair(&meta_dstSequence, &meta_dstSequence_rev); }
	template <> const ::Uml::CompositionParentRole& Events::_type2CPRole< Events::PR_InputSequence_parent >() const { return meta_InputSequence_parent; }

	::Uml::Class Sequence::meta;
	::Uml::CompositionParentRole Sequence::meta_InputSequence_parent;
	::Uml::AssociationRole Sequence::meta_dstSequence_end_;
	::Uml::AssociationRole Sequence::meta_srcSequence_end_;

	template <> const ::Uml::CompositionParentRole& Sequence::_type2CPRole< Sequence::PR_InputSequence_parent >() const { return meta_InputSequence_parent; }
	template <> const ::Uml::AssociationRole& Sequence::_type2ARole< Sequence::ACE_dstSequence >() const { return meta_dstSequence_end_; }
	template <> const ::Uml::AssociationRole& Sequence::_type2ARole< Sequence::ACE_srcSequence >() const { return meta_srcSequence_end_; }

	::Uml::Class State::meta;
	::Uml::Attribute State::meta_StartState;
	::Uml::AssociationRole State::meta_srcTransition;
	::Uml::AssociationRole State::meta_srcTransition_rev;
	::Uml::AssociationRole State::meta_dstTransition;
	::Uml::AssociationRole State::meta_dstTransition_rev;
	::Uml::CompositionChildRole State::meta_State_child;
	::Uml::CompositionChildRole State::meta_Transition_child;
	::Uml::CompositionParentRole State::meta_State_parent;
	::Uml::CompositionParentRole State::meta_RootFolder_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> State::_type2ACARole< State::AR_srcTransition >() const { return make_pair(&meta_srcTransition, &meta_srcTransition_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> State::_type2ACARole< State::AR_dstTransition >() const { return make_pair(&meta_dstTransition, &meta_dstTransition_rev); }
	template <> const ::Uml::CompositionChildRole& State::_type2CCRole< State::CR_State_child >() const { return meta_State_child; }
	template <> const ::Uml::CompositionChildRole& State::_type2CCRole< State::CR_Transition_child >() const { return meta_Transition_child; }
	template <> const ::Uml::CompositionParentRole& State::_type2CPRole< State::PR_State_parent >() const { return meta_State_parent; }
	template <> const ::Uml::CompositionParentRole& State::_type2CPRole< State::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class Transition::meta;
	::Uml::Attribute Transition::meta_Event;
	::Uml::CompositionParentRole Transition::meta_State_parent;
	::Uml::AssociationRole Transition::meta_dstTransition_end_;
	::Uml::AssociationRole Transition::meta_srcTransition_end_;

	template <> const ::Uml::CompositionParentRole& Transition::_type2CPRole< Transition::PR_State_parent >() const { return meta_State_parent; }
	template <> const ::Uml::AssociationRole& Transition::_type2ARole< Transition::ACE_dstTransition >() const { return meta_dstTransition_end_; }
	template <> const ::Uml::AssociationRole& Transition::_type2ARole< Transition::ACE_srcTransition >() const { return meta_srcTransition_end_; }

	::Uml::Class RootFolder::meta;
	::Uml::Attribute RootFolder::meta_name;
	::Uml::CompositionChildRole RootFolder::meta_State_children;
	::Uml::CompositionChildRole RootFolder::meta_InputSequence_children;
	::Uml::CompositionChildRole RootFolder::meta_RootFolder_children;
	::Uml::CompositionParentRole RootFolder::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_State_children >() const { return meta_State_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_InputSequence_children >() const { return meta_InputSequence_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_RootFolder_children >() const { return meta_RootFolder_children; }
	template <> const ::Uml::CompositionParentRole& RootFolder::_type2CPRole< RootFolder::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class MgaObject::meta;
	::Uml::Attribute MgaObject::meta_position;
	::Uml::Attribute MgaObject::meta_name;

	::Uml::Diagram meta;

	void CreateMeta() {
		// classes, with attributes, constraints and constraint definitions
		Events::meta = ::Uml::Class::Create(meta);
		Events::meta_Delay = ::Uml::Attribute::Create(Events::meta);

		InputSequence::meta = ::Uml::Class::Create(meta);

		MgaObject::meta = ::Uml::Class::Create(meta);
		MgaObject::meta_position = ::Uml::Attribute::Create(MgaObject::meta);
		MgaObject::meta_name = ::Uml::Attribute::Create(MgaObject::meta);

		RootFolder::meta = ::Uml::Class::Create(meta);
		RootFolder::meta_name = ::Uml::Attribute::Create(RootFolder::meta);

		Sequence::meta = ::Uml::Class::Create(meta);

		State::meta = ::Uml::Class::Create(meta);
		State::meta_StartState = ::Uml::Attribute::Create(State::meta);

		Transition::meta = ::Uml::Class::Create(meta);
		Transition::meta_Event = ::Uml::Attribute::Create(Transition::meta);

	}

	void InitMeta() {
		// classes, with attributes, constraints and constraint definitions
		::Uml::InitClassProps(Events::meta, "Events", false, "Atom", NULL);
		vector<string> Events_Delay_dva;
		Events_Delay_dva.push_back("2");
		::Uml::InitAttributeProps(Events::meta_Delay, "Delay", "Integer", false, false, 1, 1, false, "public", Events_Delay_dva);

		::Uml::InitClassProps(InputSequence::meta, "InputSequence", false, "Model", NULL);

		::Uml::InitClassProps(MgaObject::meta, "MgaObject", true, NULL, NULL);
		::Uml::InitAttributeProps(MgaObject::meta_position, "position", "String", false, false, 0, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(MgaObject::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(RootFolder::meta, "RootFolder", false, "Folder", NULL);
		::Uml::InitAttributeProps(RootFolder::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Sequence::meta, "Sequence", false, "Connection", NULL);

		::Uml::InitClassProps(State::meta, "State", false, "Model", NULL);
		vector<string> State_StartState_dva;
		State_StartState_dva.push_back("false");
		::Uml::InitAttributeProps(State::meta_StartState, "StartState", "Boolean", false, false, 1, 1, false, "public", State_StartState_dva);

		::Uml::InitClassProps(Transition::meta, "Transition", false, "Connection", NULL);
		::Uml::InitAttributeProps(Transition::meta_Event, "Event", "String", false, false, 1, 1, false, "public", vector<string>());

		// associations
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Sequence");
			Events::meta_srcSequence = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Events::meta_srcSequence, "srcSequence", true, false, 0, 1);
			Events::meta_dstSequence = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Events::meta_dstSequence, "dstSequence", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Transition");
			State::meta_srcTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(State::meta_srcTransition, "srcTransition", true, false, 1, 1);
			State::meta_dstTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(State::meta_dstTransition, "dstTransition", true, false, 1, 1);

		}

		// compositions
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Events::meta_InputSequence_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Events::meta_InputSequence_parent, "InputSequence_parent", true);
			InputSequence::meta_Events_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(InputSequence::meta_Events_children, "Events", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Sequence::meta_InputSequence_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Sequence::meta_InputSequence_parent, "InputSequence_parent", true);
			InputSequence::meta_Sequence_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(InputSequence::meta_Sequence_children, "Sequence", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			State::meta_State_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(State::meta_State_parent, "State_parent", true);
			State::meta_State_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(State::meta_State_child, "State", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Transition::meta_State_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Transition::meta_State_parent, "State_parent", true);
			State::meta_Transition_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(State::meta_Transition_child, "Transition", true, 1, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			State::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(State::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_State_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_State_children, "State", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			InputSequence::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(InputSequence::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_InputSequence_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_InputSequence_children, "InputSequence", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			RootFolder::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(RootFolder::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_RootFolder_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_RootFolder_children, "RootFolder", true, 0, -1);

		}

	}

	void InitMetaLinks() {
		Events::meta_srcSequence.target() = Events::meta;
		Events::meta_dstSequence.target() = Events::meta;
		InputSequence::meta_Events_children.target() = Events::meta;

		Events::meta_InputSequence_parent.target() = InputSequence::meta;
		Sequence::meta_InputSequence_parent.target() = InputSequence::meta;
		RootFolder::meta_InputSequence_children.target() = InputSequence::meta;

		MgaObject::meta.subTypes() += InputSequence::meta;
		MgaObject::meta.subTypes() += Events::meta;
		MgaObject::meta.subTypes() += Sequence::meta;
		MgaObject::meta.subTypes() += State::meta;
		MgaObject::meta.subTypes() += Transition::meta;

		State::meta_RootFolder_parent.target() = RootFolder::meta;
		InputSequence::meta_RootFolder_parent.target() = RootFolder::meta;
		RootFolder::meta_RootFolder_parent.target() = RootFolder::meta;
		RootFolder::meta_RootFolder_children.target() = RootFolder::meta;

		InputSequence::meta_Sequence_children.target() = Sequence::meta;
		Sequence::meta.association() = Events::meta_srcSequence.parent();
		Sequence::meta_srcSequence_end_ = Events::meta_dstSequence_rev = Events::meta_srcSequence;
		Sequence::meta_dstSequence_end_ = Events::meta_srcSequence_rev = Events::meta_dstSequence;

		State::meta_srcTransition.target() = State::meta;
		State::meta_dstTransition.target() = State::meta;
		State::meta_State_parent.target() = State::meta;
		Transition::meta_State_parent.target() = State::meta;
		State::meta_State_child.target() = State::meta;
		RootFolder::meta_State_children.target() = State::meta;

		State::meta_Transition_child.target() = Transition::meta;
		Transition::meta.association() = State::meta_srcTransition.parent();
		Transition::meta_srcTransition_end_ = State::meta_dstTransition_rev = State::meta_srcTransition;
		Transition::meta_dstTransition_end_ = State::meta_srcTransition_rev = State::meta_dstTransition;

	}

	void InitMeta(const ::Uml::Diagram &parent) {
		// classes, with attributes, constraints and constraint definitions
		::Uml::SetClass(Events::meta, parent, "Events");
		::Uml::SetAttribute(Events::meta_Delay, Events::meta, "Delay");

		::Uml::SetClass(InputSequence::meta, parent, "InputSequence");

		::Uml::SetClass(MgaObject::meta, parent, "MgaObject");
		::Uml::SetAttribute(MgaObject::meta_position, MgaObject::meta, "position");
		::Uml::SetAttribute(MgaObject::meta_name, MgaObject::meta, "name");

		::Uml::SetClass(RootFolder::meta, parent, "RootFolder");
		::Uml::SetAttribute(RootFolder::meta_name, RootFolder::meta, "name");

		::Uml::SetClass(Sequence::meta, parent, "Sequence");

		::Uml::SetClass(State::meta, parent, "State");
		::Uml::SetAttribute(State::meta_StartState, State::meta, "StartState");

		::Uml::SetClass(Transition::meta, parent, "Transition");
		::Uml::SetAttribute(Transition::meta_Event, Transition::meta, "Event");

	}

	void InitMetaLinks(const ::Uml::Diagram &parent) {
		// classes
		::Uml::SetAssocRole(Events::meta_srcSequence, Events::meta, Events::meta, "dstSequence");
		Events::meta_dstSequence_rev = Events::meta_srcSequence;
		::Uml::SetAssocRole(Events::meta_dstSequence, Events::meta, Events::meta, "srcSequence");
		Events::meta_srcSequence_rev = Events::meta_dstSequence;
		::Uml::SetParentRole(Events::meta_InputSequence_parent, Events::meta, InputSequence::meta, "", "");

		::Uml::SetChildRole(InputSequence::meta_Events_children, InputSequence::meta, Events::meta, "", "");
		::Uml::SetChildRole(InputSequence::meta_Sequence_children, InputSequence::meta, Sequence::meta, "", "");
		::Uml::SetParentRole(InputSequence::meta_RootFolder_parent, InputSequence::meta, RootFolder::meta, "", "");

		::Uml::SetChildRole(RootFolder::meta_State_children, RootFolder::meta, State::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_InputSequence_children, RootFolder::meta, InputSequence::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_RootFolder_children, RootFolder::meta, RootFolder::meta, "", "");
		::Uml::SetParentRole(RootFolder::meta_RootFolder_parent, RootFolder::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(Sequence::meta_InputSequence_parent, Sequence::meta, InputSequence::meta, "", "");
		Sequence::meta_dstSequence_end_ = Events::meta_dstSequence;
		Sequence::meta_srcSequence_end_ = Events::meta_srcSequence;

		::Uml::SetAssocRole(State::meta_srcTransition, State::meta, State::meta, "dstTransition");
		State::meta_dstTransition_rev = State::meta_srcTransition;
		::Uml::SetAssocRole(State::meta_dstTransition, State::meta, State::meta, "srcTransition");
		State::meta_srcTransition_rev = State::meta_dstTransition;
		::Uml::SetChildRole(State::meta_State_child, State::meta, State::meta, "", "");
		::Uml::SetChildRole(State::meta_Transition_child, State::meta, Transition::meta, "", "");
		::Uml::SetParentRole(State::meta_State_parent, State::meta, State::meta, "", "");
		::Uml::SetParentRole(State::meta_RootFolder_parent, State::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(Transition::meta_State_parent, Transition::meta, State::meta, "", "");
		Transition::meta_dstTransition_end_ = State::meta_dstTransition;
		Transition::meta_srcTransition_end_ = State::meta_srcTransition;

	}

	void Initialize()
	{
		static bool first = true;
		if (!first) return;
		first = false;
		::Uml::Initialize();

	
		ASSERT( meta == Udm::null );

		UdmStatic::StaticDataNetwork * meta_dn = new UdmStatic::StaticDataNetwork(::Uml::diagram);
		meta_dn->CreateNew("HFSM.mem", "", ::Uml::Diagram::meta, Udm::CHANGES_LOST_DEFAULT);
		meta = ::Uml::Diagram::Cast(meta_dn->GetRootObject());

		::Uml::InitDiagramProps(meta, "HFSM", "1.00");


		CreateMeta();
		InitMeta();
		InitMetaLinks();

	}

	void Initialize(const ::Uml::Diagram &dgr)
	{
		
		meta = dgr;

		InitMeta(dgr);
		InitMetaLinks(dgr);

		
		
	}


	Udm::UdmDiagram diagram = { &meta, Initialize };
	static struct _regClass
	{
		_regClass()
		{
			Udm::MetaDepository::StoreDiagram("HFSM", diagram);
		}
		~_regClass()
		{
			Udm::MetaDepository::RemoveDiagram("HFSM");
		}
	} __regUnUsed;

}

