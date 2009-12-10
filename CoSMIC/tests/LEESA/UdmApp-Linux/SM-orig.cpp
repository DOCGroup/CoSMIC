// cpp (meta datanetwork format) source file SM.cpp
// generated from diagram SM
// generated on Wed Dec 09 21:34:13 2009

#include "SM.h"
#include <UmlExt.h>
#include <UdmStatic.h>


namespace SM {

	::Uml::Class StateMachine::meta;
	::Uml::CompositionChildRole StateMachine::meta_Reference_children;
	::Uml::CompositionChildRole StateMachine::meta_Transition_children;
	::Uml::CompositionChildRole StateMachine::meta_BaseState_children;
	::Uml::CompositionParentRole StateMachine::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& StateMachine::_type2CCRole< StateMachine::CR_Reference_children >() const { return meta_Reference_children; }
	template <> const ::Uml::CompositionChildRole& StateMachine::_type2CCRole< StateMachine::CR_Transition_children >() const { return meta_Transition_children; }
	template <> const ::Uml::CompositionChildRole& StateMachine::_type2CCRole< StateMachine::CR_BaseState_children >() const { return meta_BaseState_children; }
	template <> const ::Uml::CompositionParentRole& StateMachine::_type2CPRole< StateMachine::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class Transition::meta;
	::Uml::Attribute Transition::meta_Event;
	::Uml::CompositionParentRole Transition::meta_StateMachine_parent;
	::Uml::CompositionParentRole Transition::meta_BaseState_parent;
	::Uml::AssociationRole Transition::meta_srcTransition_end_;
	::Uml::AssociationRole Transition::meta_dstTransition_end_;

	template <> const ::Uml::CompositionParentRole& Transition::_type2CPRole< Transition::PR_StateMachine_parent >() const { return meta_StateMachine_parent; }
	template <> const ::Uml::CompositionParentRole& Transition::_type2CPRole< Transition::PR_BaseState_parent >() const { return meta_BaseState_parent; }
	template <> const ::Uml::AssociationRole& Transition::_type2ARole< Transition::ACE_srcTransition >() const { return meta_srcTransition_end_; }
	template <> const ::Uml::AssociationRole& Transition::_type2ARole< Transition::ACE_dstTransition >() const { return meta_dstTransition_end_; }

	::Uml::Class State::meta;

	::Uml::Class Reference::meta;
	::Uml::AssociationRole Reference::meta_ref;
	::Uml::CompositionParentRole Reference::meta_StateMachine_parent;
	::Uml::CompositionParentRole Reference::meta_BaseState_parent;

	template <> const ::Uml::AssociationRole& Reference::_type2ARole< Reference::AR_ref >() const { return meta_ref; }
	template <> const ::Uml::CompositionParentRole& Reference::_type2CPRole< Reference::PR_StateMachine_parent >() const { return meta_StateMachine_parent; }
	template <> const ::Uml::CompositionParentRole& Reference::_type2CPRole< Reference::PR_BaseState_parent >() const { return meta_BaseState_parent; }

	::Uml::Class StartState::meta;

	::Uml::Class BaseState::meta;
	::Uml::AssociationRole BaseState::meta_referedbyReference;
	::Uml::AssociationRole BaseState::meta_dstTransition;
	::Uml::AssociationRole BaseState::meta_dstTransition_rev;
	::Uml::AssociationRole BaseState::meta_srcTransition;
	::Uml::AssociationRole BaseState::meta_srcTransition_rev;
	::Uml::CompositionChildRole BaseState::meta_BaseState_children;
	::Uml::CompositionChildRole BaseState::meta_Reference_children;
	::Uml::CompositionChildRole BaseState::meta_Transition_children;
	::Uml::CompositionParentRole BaseState::meta_StateMachine_parent;
	::Uml::CompositionParentRole BaseState::meta_BaseState_parent;

	template <> const ::Uml::AssociationRole& BaseState::_type2ARole< BaseState::AR_referedbyReference >() const { return meta_referedbyReference; }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> BaseState::_type2ACARole< BaseState::AR_dstTransition >() const { return make_pair(&meta_dstTransition, &meta_dstTransition_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> BaseState::_type2ACARole< BaseState::AR_srcTransition >() const { return make_pair(&meta_srcTransition, &meta_srcTransition_rev); }
	template <> const ::Uml::CompositionChildRole& BaseState::_type2CCRole< BaseState::CR_BaseState_children >() const { return meta_BaseState_children; }
	template <> const ::Uml::CompositionChildRole& BaseState::_type2CCRole< BaseState::CR_Reference_children >() const { return meta_Reference_children; }
	template <> const ::Uml::CompositionChildRole& BaseState::_type2CCRole< BaseState::CR_Transition_children >() const { return meta_Transition_children; }
	template <> const ::Uml::CompositionParentRole& BaseState::_type2CPRole< BaseState::PR_StateMachine_parent >() const { return meta_StateMachine_parent; }
	template <> const ::Uml::CompositionParentRole& BaseState::_type2CPRole< BaseState::PR_BaseState_parent >() const { return meta_BaseState_parent; }

	::Uml::Class Sequence::meta;
	::Uml::CompositionParentRole Sequence::meta_InputSequence_parent;
	::Uml::AssociationRole Sequence::meta_dstSequence_end_;
	::Uml::AssociationRole Sequence::meta_srcSequence_end_;

	template <> const ::Uml::CompositionParentRole& Sequence::_type2CPRole< Sequence::PR_InputSequence_parent >() const { return meta_InputSequence_parent; }
	template <> const ::Uml::AssociationRole& Sequence::_type2ARole< Sequence::ACE_dstSequence >() const { return meta_dstSequence_end_; }
	template <> const ::Uml::AssociationRole& Sequence::_type2ARole< Sequence::ACE_srcSequence >() const { return meta_srcSequence_end_; }

	::Uml::Class InputSequence::meta;
	::Uml::CompositionChildRole InputSequence::meta_Sequence_children;
	::Uml::CompositionChildRole InputSequence::meta_Events_children;
	::Uml::CompositionParentRole InputSequence::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& InputSequence::_type2CCRole< InputSequence::CR_Sequence_children >() const { return meta_Sequence_children; }
	template <> const ::Uml::CompositionChildRole& InputSequence::_type2CCRole< InputSequence::CR_Events_children >() const { return meta_Events_children; }
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

	::Uml::Class RootFolder::meta;
	::Uml::Attribute RootFolder::meta_name;
	::Uml::CompositionChildRole RootFolder::meta_InputSequence_children;
	::Uml::CompositionChildRole RootFolder::meta_StateMachine_children;
	::Uml::CompositionChildRole RootFolder::meta_RootFolder_children;
	::Uml::CompositionParentRole RootFolder::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_InputSequence_children >() const { return meta_InputSequence_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_StateMachine_children >() const { return meta_StateMachine_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_RootFolder_children >() const { return meta_RootFolder_children; }
	template <> const ::Uml::CompositionParentRole& RootFolder::_type2CPRole< RootFolder::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class MgaObject::meta;
	::Uml::Attribute MgaObject::meta_position;
	::Uml::Attribute MgaObject::meta_name;

	::Uml::Diagram meta;

	void CreateMeta() {
		// classes, with attributes, constraints and constraint definitions
		BaseState::meta = ::Uml::Class::Create(meta);

		Events::meta = ::Uml::Class::Create(meta);
		Events::meta_Delay = ::Uml::Attribute::Create(Events::meta);

		InputSequence::meta = ::Uml::Class::Create(meta);

		MgaObject::meta = ::Uml::Class::Create(meta);
		MgaObject::meta_position = ::Uml::Attribute::Create(MgaObject::meta);
		MgaObject::meta_name = ::Uml::Attribute::Create(MgaObject::meta);

		Reference::meta = ::Uml::Class::Create(meta);

		RootFolder::meta = ::Uml::Class::Create(meta);
		RootFolder::meta_name = ::Uml::Attribute::Create(RootFolder::meta);

		Sequence::meta = ::Uml::Class::Create(meta);

		StartState::meta = ::Uml::Class::Create(meta);

		State::meta = ::Uml::Class::Create(meta);

		StateMachine::meta = ::Uml::Class::Create(meta);

		Transition::meta = ::Uml::Class::Create(meta);
		Transition::meta_Event = ::Uml::Attribute::Create(Transition::meta);

	}

	void InitMeta() {
		// classes, with attributes, constraints and constraint definitions
		::Uml::InitClassProps(BaseState::meta, "BaseState", true, "Model", NULL);

		::Uml::InitClassProps(Events::meta, "Events", false, "Atom", NULL);
		vector<string> Events_Delay_dva;
		Events_Delay_dva.push_back("2");
		::Uml::InitAttributeProps(Events::meta_Delay, "Delay", "Integer", false, false, 1, 1, false, "public", Events_Delay_dva);

		::Uml::InitClassProps(InputSequence::meta, "InputSequence", false, "Model", NULL);

		::Uml::InitClassProps(MgaObject::meta, "MgaObject", true, NULL, NULL);
		::Uml::InitAttributeProps(MgaObject::meta_position, "position", "String", false, false, 0, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(MgaObject::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Reference::meta, "Reference", false, "Reference", NULL);

		::Uml::InitClassProps(RootFolder::meta, "RootFolder", false, "Folder", NULL);
		::Uml::InitAttributeProps(RootFolder::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Sequence::meta, "Sequence", false, "Connection", NULL);

		::Uml::InitClassProps(StartState::meta, "StartState", false, "Model", NULL);

		::Uml::InitClassProps(State::meta, "State", false, "Model", NULL);

		::Uml::InitClassProps(StateMachine::meta, "StateMachine", false, "Model", NULL);

		::Uml::InitClassProps(Transition::meta, "Transition", false, "Connection", NULL);
		::Uml::InitAttributeProps(Transition::meta_Event, "Event", "String", false, false, 1, 1, false, "public", vector<string>());

		// associations
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "");
			BaseState::meta_referedbyReference = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(BaseState::meta_referedbyReference, "referedbyReference", true, false, 0, -1);
			Reference::meta_ref = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Reference::meta_ref, "ref", true, false, 0, 1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Transition");
			BaseState::meta_dstTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(BaseState::meta_dstTransition, "dstTransition", true, false, 0, -1);
			BaseState::meta_srcTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(BaseState::meta_srcTransition, "srcTransition", true, false, 0, -1);

		}
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "Sequence");
			Events::meta_srcSequence = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Events::meta_srcSequence, "srcSequence", true, false, 0, 1);
			Events::meta_dstSequence = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Events::meta_dstSequence, "dstSequence", true, false, 0, 1);

		}

		// compositions
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Reference::meta_StateMachine_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Reference::meta_StateMachine_parent, "StateMachine_parent", true);
			StateMachine::meta_Reference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(StateMachine::meta_Reference_children, "Reference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Transition::meta_StateMachine_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Transition::meta_StateMachine_parent, "StateMachine_parent", true);
			StateMachine::meta_Transition_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(StateMachine::meta_Transition_children, "Transition", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			BaseState::meta_StateMachine_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(BaseState::meta_StateMachine_parent, "StateMachine_parent", true);
			StateMachine::meta_BaseState_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(StateMachine::meta_BaseState_children, "BaseState", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			BaseState::meta_BaseState_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(BaseState::meta_BaseState_parent, "BaseState_parent", true);
			BaseState::meta_BaseState_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BaseState::meta_BaseState_children, "BaseState", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Reference::meta_BaseState_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Reference::meta_BaseState_parent, "BaseState_parent", true);
			BaseState::meta_Reference_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BaseState::meta_Reference_children, "Reference", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Transition::meta_BaseState_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Transition::meta_BaseState_parent, "BaseState_parent", true);
			BaseState::meta_Transition_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(BaseState::meta_Transition_children, "Transition", true, 0, -1);

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
			Events::meta_InputSequence_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Events::meta_InputSequence_parent, "InputSequence_parent", true);
			InputSequence::meta_Events_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(InputSequence::meta_Events_children, "Events", true, 0, -1);

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
			StateMachine::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(StateMachine::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_StateMachine_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_StateMachine_children, "StateMachine", true, 0, -1);

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
		BaseState::meta_referedbyReference.target() = Reference::meta;
		BaseState::meta_dstTransition.target() = BaseState::meta;
		BaseState::meta_srcTransition.target() = BaseState::meta;
		BaseState::meta_BaseState_parent.target() = BaseState::meta;
		Reference::meta_BaseState_parent.target() = BaseState::meta;
		Transition::meta_BaseState_parent.target() = BaseState::meta;
		StateMachine::meta_BaseState_children.target() = BaseState::meta;
		BaseState::meta_BaseState_children.target() = BaseState::meta;
		BaseState::meta.subTypes() += State::meta;
		BaseState::meta.subTypes() += StartState::meta;

		Events::meta_srcSequence.target() = Events::meta;
		Events::meta_dstSequence.target() = Events::meta;
		InputSequence::meta_Events_children.target() = Events::meta;

		Sequence::meta_InputSequence_parent.target() = InputSequence::meta;
		Events::meta_InputSequence_parent.target() = InputSequence::meta;
		RootFolder::meta_InputSequence_children.target() = InputSequence::meta;

		MgaObject::meta.subTypes() += StateMachine::meta;
		MgaObject::meta.subTypes() += Transition::meta;
		MgaObject::meta.subTypes() += Reference::meta;
		MgaObject::meta.subTypes() += BaseState::meta;
		MgaObject::meta.subTypes() += Sequence::meta;
		MgaObject::meta.subTypes() += InputSequence::meta;
		MgaObject::meta.subTypes() += Events::meta;

		Reference::meta_ref.target() = BaseState::meta;
		StateMachine::meta_Reference_children.target() = Reference::meta;
		BaseState::meta_Reference_children.target() = Reference::meta;

		InputSequence::meta_RootFolder_parent.target() = RootFolder::meta;
		StateMachine::meta_RootFolder_parent.target() = RootFolder::meta;
		RootFolder::meta_RootFolder_parent.target() = RootFolder::meta;
		RootFolder::meta_RootFolder_children.target() = RootFolder::meta;

		InputSequence::meta_Sequence_children.target() = Sequence::meta;
		Sequence::meta.association() = Events::meta_srcSequence.parent();
		Sequence::meta_srcSequence_end_ = Events::meta_dstSequence_rev = Events::meta_srcSequence;
		Sequence::meta_dstSequence_end_ = Events::meta_srcSequence_rev = Events::meta_dstSequence;

		Reference::meta_StateMachine_parent.target() = StateMachine::meta;
		Transition::meta_StateMachine_parent.target() = StateMachine::meta;
		BaseState::meta_StateMachine_parent.target() = StateMachine::meta;
		RootFolder::meta_StateMachine_children.target() = StateMachine::meta;

		StateMachine::meta_Transition_children.target() = Transition::meta;
		BaseState::meta_Transition_children.target() = Transition::meta;
		Transition::meta.association() = BaseState::meta_dstTransition.parent();
		Transition::meta_dstTransition_end_ = BaseState::meta_srcTransition_rev = BaseState::meta_dstTransition;
		Transition::meta_srcTransition_end_ = BaseState::meta_dstTransition_rev = BaseState::meta_srcTransition;

	}

	void InitMeta(const ::Uml::Diagram &parent) {
		// classes, with attributes, constraints and constraint definitions
		::Uml::SetClass(BaseState::meta, parent, "BaseState");

		::Uml::SetClass(Events::meta, parent, "Events");
		::Uml::SetAttribute(Events::meta_Delay, Events::meta, "Delay");

		::Uml::SetClass(InputSequence::meta, parent, "InputSequence");

		::Uml::SetClass(MgaObject::meta, parent, "MgaObject");
		::Uml::SetAttribute(MgaObject::meta_position, MgaObject::meta, "position");
		::Uml::SetAttribute(MgaObject::meta_name, MgaObject::meta, "name");

		::Uml::SetClass(Reference::meta, parent, "Reference");

		::Uml::SetClass(RootFolder::meta, parent, "RootFolder");
		::Uml::SetAttribute(RootFolder::meta_name, RootFolder::meta, "name");

		::Uml::SetClass(Sequence::meta, parent, "Sequence");

		::Uml::SetClass(StartState::meta, parent, "StartState");

		::Uml::SetClass(State::meta, parent, "State");

		::Uml::SetClass(StateMachine::meta, parent, "StateMachine");

		::Uml::SetClass(Transition::meta, parent, "Transition");
		::Uml::SetAttribute(Transition::meta_Event, Transition::meta, "Event");

	}

	void InitMetaLinks(const ::Uml::Diagram &parent) {
		// classes
		::Uml::SetAssocRole(BaseState::meta_referedbyReference, BaseState::meta, Reference::meta, "ref");
		::Uml::SetAssocRole(BaseState::meta_dstTransition, BaseState::meta, BaseState::meta, "srcTransition");
		BaseState::meta_srcTransition_rev = BaseState::meta_dstTransition;
		::Uml::SetAssocRole(BaseState::meta_srcTransition, BaseState::meta, BaseState::meta, "dstTransition");
		BaseState::meta_dstTransition_rev = BaseState::meta_srcTransition;
		::Uml::SetChildRole(BaseState::meta_BaseState_children, BaseState::meta, BaseState::meta, "", "");
		::Uml::SetChildRole(BaseState::meta_Reference_children, BaseState::meta, Reference::meta, "", "");
		::Uml::SetChildRole(BaseState::meta_Transition_children, BaseState::meta, Transition::meta, "", "");
		::Uml::SetParentRole(BaseState::meta_StateMachine_parent, BaseState::meta, StateMachine::meta, "", "");
		::Uml::SetParentRole(BaseState::meta_BaseState_parent, BaseState::meta, BaseState::meta, "", "");

		::Uml::SetAssocRole(Events::meta_srcSequence, Events::meta, Events::meta, "dstSequence");
		Events::meta_dstSequence_rev = Events::meta_srcSequence;
		::Uml::SetAssocRole(Events::meta_dstSequence, Events::meta, Events::meta, "srcSequence");
		Events::meta_srcSequence_rev = Events::meta_dstSequence;
		::Uml::SetParentRole(Events::meta_InputSequence_parent, Events::meta, InputSequence::meta, "", "");

		::Uml::SetChildRole(InputSequence::meta_Sequence_children, InputSequence::meta, Sequence::meta, "", "");
		::Uml::SetChildRole(InputSequence::meta_Events_children, InputSequence::meta, Events::meta, "", "");
		::Uml::SetParentRole(InputSequence::meta_RootFolder_parent, InputSequence::meta, RootFolder::meta, "", "");

		::Uml::SetAssocRole(Reference::meta_ref, Reference::meta, BaseState::meta, "referedbyReference");
		::Uml::SetParentRole(Reference::meta_StateMachine_parent, Reference::meta, StateMachine::meta, "", "");
		::Uml::SetParentRole(Reference::meta_BaseState_parent, Reference::meta, BaseState::meta, "", "");

		::Uml::SetChildRole(RootFolder::meta_InputSequence_children, RootFolder::meta, InputSequence::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_StateMachine_children, RootFolder::meta, StateMachine::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_RootFolder_children, RootFolder::meta, RootFolder::meta, "", "");
		::Uml::SetParentRole(RootFolder::meta_RootFolder_parent, RootFolder::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(Sequence::meta_InputSequence_parent, Sequence::meta, InputSequence::meta, "", "");
		Sequence::meta_dstSequence_end_ = Events::meta_dstSequence;
		Sequence::meta_srcSequence_end_ = Events::meta_srcSequence;

		::Uml::SetChildRole(StateMachine::meta_Reference_children, StateMachine::meta, Reference::meta, "", "");
		::Uml::SetChildRole(StateMachine::meta_Transition_children, StateMachine::meta, Transition::meta, "", "");
		::Uml::SetChildRole(StateMachine::meta_BaseState_children, StateMachine::meta, BaseState::meta, "", "");
		::Uml::SetParentRole(StateMachine::meta_RootFolder_parent, StateMachine::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(Transition::meta_StateMachine_parent, Transition::meta, StateMachine::meta, "", "");
		::Uml::SetParentRole(Transition::meta_BaseState_parent, Transition::meta, BaseState::meta, "", "");
		Transition::meta_srcTransition_end_ = BaseState::meta_srcTransition;
		Transition::meta_dstTransition_end_ = BaseState::meta_dstTransition;

	}

	SM_Export void Initialize()
	{
		static bool first = true;
		if (!first) return;
		first = false;
		::Uml::Initialize();

	
		ASSERT( meta == Udm::null );

		UdmStatic::StaticDataNetwork * meta_dn = new UdmStatic::StaticDataNetwork(::Uml::diagram);
		meta_dn->CreateNew("SM.mem", "", ::Uml::Diagram::meta, Udm::CHANGES_LOST_DEFAULT);
		meta = ::Uml::Diagram::Cast(meta_dn->GetRootObject());

		::Uml::InitDiagramProps(meta, "SM", "1.00");


		CreateMeta();
		InitMeta();
		InitMetaLinks();

	}

	SM_Export void Initialize(const ::Uml::Diagram &dgr)
	{
		
		meta = dgr;

		InitMeta(dgr);
		InitMetaLinks(dgr);

		
		
	}


	SM_Export Udm::UdmDiagram diagram = { &meta, Initialize };
	static struct _regClass
	{
		_regClass()
		{
			Udm::MetaDepository::StoreDiagram("SM", diagram);
		}
		~_regClass()
		{
			Udm::MetaDepository::RemoveDiagram("SM");
		}
	} __regUnUsed;

}

