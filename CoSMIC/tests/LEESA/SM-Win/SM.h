// This header file is modified by gen-pairs.pl program of LEESA, which generates IsDescendant<T,U>
// pairs at the end of the header file. Command: perl gen-pairs.pl <PARADIGM-NAME>
// More information about LEESA can be found at http://www.dre.vanderbilt.edu/~sutambe/files/LEESA/LEESA.pdf 

#ifndef MOBIES_SM_H
#define MOBIES_SM_H

// header file SM.h generated from diagram SM
// generated with Udm version 3.13 on Sun Nov 29 19:45:08 2009

#include <UdmBase.h>

#if !defined(UDM_VERSION_MAJOR) || !defined(UDM_VERSION_MINOR)
#    error "Udm headers too old, they do not define UDM_VERSION"
#elif UDM_VERSION_MAJOR < 3
#    error "Udm headers too old, minimum version required 3.13"
#elif UDM_VERSION_MAJOR == 3 && UDM_VERSION_MINOR < 13
#    error "Udm headers too old, minimum version required 3.13"
#endif

#include <Uml.h>

#include <UdmMPL.h>

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#include "SM_export.h"

#include "LEESA_VisitorAsIndex.h"

namespace SM {

	extern ::Uml::Diagram meta;
	class SM_Export StateMachine;
	class SM_Export Transition;
	class SM_Export State;
	class SM_Export Reference;
	class SM_Export StartState;
	class SM_Export BaseState;
	class SM_Export Sequence;
	class SM_Export InputSequence;
	class SM_Export Events;
	class SM_Export RootFolder;
	class SM_Export MgaObject;

	class SM_Export Visitor : public Udm::BaseVisitor {
	public:
		virtual ~Visitor() {}

		virtual void Visit_StateMachine(const StateMachine &) {}
		virtual void Leave_StateMachine(const StateMachine &) {}
		virtual void Visit_Transition(const Transition &) {}
		virtual void Leave_Transition(const Transition &) {}
		virtual void Visit_State(const State &) {}
		virtual void Leave_State(const State &) {}
		virtual void Visit_Reference(const Reference &) {}
		virtual void Leave_Reference(const Reference &) {}
		virtual void Visit_StartState(const StartState &) {}
		virtual void Leave_StartState(const StartState &) {}
		virtual void Visit_Sequence(const Sequence &) {}
		virtual void Leave_Sequence(const Sequence &) {}
		virtual void Visit_InputSequence(const InputSequence &) {}
		virtual void Leave_InputSequence(const InputSequence &) {}
		virtual void Visit_Events(const Events &) {}
		virtual void Leave_Events(const Events &) {}
		virtual void Visit_RootFolder(const RootFolder &) {}
		virtual void Leave_RootFolder(const RootFolder &) {}
		virtual void Visit_Object(const Udm::Object &) {}

	};

	SM_Export void Initialize();
	SM_Export void Initialize(const ::Uml::Diagram &dgr);

	extern SM_Export Udm::UdmDiagram diagram;

	class SM_Export RootFolder : public Udm::Object , public LEESA::VisitorAsIndex_CRTP< RootFolder, Visitor > {
	public:
		typedef ::Udm::FolderMetaTag MetaKind;

		RootFolder() {}
		RootFolder(Udm::ObjectImpl *impl) : UDM_OBJECT(impl) {}
		RootFolder(const RootFolder &master) : UDM_OBJECT(master) {}

		static RootFolder Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static RootFolder Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		RootFolder CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<RootFolder> Instances() { return Udm::InstantiatedAttr<RootFolder>(impl); }
		template <class Pred> Udm::InstantiatedAttr<RootFolder, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<RootFolder, Pred>(impl); }
		RootFolder CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<RootFolder> Derived() { return Udm::DerivedAttr<RootFolder>(impl); }
		template <class Pred> Udm::DerivedAttr<RootFolder, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<RootFolder, Pred>(impl); }
		Udm::ArchetypeAttr<RootFolder> Archetype() const { return Udm::ArchetypeAttr<RootFolder>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }
		Udm::ChildrenAttr< ::SM::InputSequence> InputSequence_children() const { return Udm::ChildrenAttr< ::SM::InputSequence>(impl, meta_InputSequence_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::InputSequence, Pred> InputSequence_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::InputSequence, Pred>(impl, meta_InputSequence_children); }
		Udm::ChildrenAttr< ::SM::StateMachine> StateMachine_children() const { return Udm::ChildrenAttr< ::SM::StateMachine>(impl, meta_StateMachine_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::StateMachine, Pred> StateMachine_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::StateMachine, Pred>(impl, meta_StateMachine_children); }
		Udm::ChildrenAttr< ::SM::RootFolder> RootFolder_children() const { return Udm::ChildrenAttr< ::SM::RootFolder>(impl, meta_RootFolder_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::RootFolder, Pred> RootFolder_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::RootFolder, Pred>(impl, meta_RootFolder_children); }
		Udm::ChildrenAttr< ::SM::StateMachine> StateMachine_kind_children() const { return Udm::ChildrenAttr< ::SM::StateMachine>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::StateMachine, Pred> StateMachine_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::StateMachine, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::InputSequence> InputSequence_kind_children() const { return Udm::ChildrenAttr< ::SM::InputSequence>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::InputSequence, Pred> InputSequence_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::InputSequence, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::RootFolder> RootFolder_kind_children() const { return Udm::ChildrenAttr< ::SM::RootFolder>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::RootFolder, Pred> RootFolder_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::RootFolder, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::SM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::SM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::SM::RootFolder>(impl, meta_RootFolder_parent); }
		Udm::ParentAttr< ::SM::RootFolder> parent() const { return Udm::ParentAttr< ::SM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_RootFolder(*this); }
		void Leave(Visitor &v) { v.Leave_RootFolder(*this); }
		using LEESA::VisitorAsIndex_CRTP< RootFolder, Visitor >::operator [];


		static ::Uml::Class meta;
		static ::Uml::Attribute meta_name;
		static ::Uml::CompositionChildRole meta_InputSequence_children;
		static ::Uml::CompositionChildRole meta_StateMachine_children;
		static ::Uml::CompositionChildRole meta_RootFolder_children;
		static ::Uml::CompositionParentRole meta_RootFolder_parent;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::RootFolder> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::SM::StateMachine, ::SM::InputSequence, ::SM::RootFolder> ChildrenKinds;







	};

	class SM_Export MgaObject : public Udm::Object {
	public:
		typedef ::Udm::UnknownMetaTag MetaKind;

		MgaObject() {}
		MgaObject(Udm::ObjectImpl *impl) : UDM_OBJECT(impl) {}
		MgaObject(const MgaObject &master) : UDM_OBJECT(master) {}

		static MgaObject Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static MgaObject Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		MgaObject CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<MgaObject> Instances() { return Udm::InstantiatedAttr<MgaObject>(impl); }
		template <class Pred> Udm::InstantiatedAttr<MgaObject, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<MgaObject, Pred>(impl); }
		MgaObject CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<MgaObject> Derived() { return Udm::DerivedAttr<MgaObject>(impl); }
		template <class Pred> Udm::DerivedAttr<MgaObject, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<MgaObject, Pred>(impl); }
		Udm::ArchetypeAttr<MgaObject> Archetype() const { return Udm::ArchetypeAttr<MgaObject>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::StringAttr position() const { return Udm::StringAttr(impl, meta_position); }
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }
		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }

		void Leave(Visitor &v) { }

		static ::Uml::Class meta;
		static ::Uml::Attribute meta_position;
		static ::Uml::Attribute meta_name;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< > ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;







	};

	class SM_Export StateMachine :  public MgaObject , public LEESA::VisitorAsIndex_CRTP< StateMachine, Visitor > {
	public:
		typedef ::Udm::ModelMetaTag MetaKind;

		StateMachine() {}
		StateMachine(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		StateMachine(const StateMachine &master) : MgaObject(master) {}

		static StateMachine Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static StateMachine Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		StateMachine CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<StateMachine> Instances() { return Udm::InstantiatedAttr<StateMachine>(impl); }
		template <class Pred> Udm::InstantiatedAttr<StateMachine, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<StateMachine, Pred>(impl); }
		StateMachine CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<StateMachine> Derived() { return Udm::DerivedAttr<StateMachine>(impl); }
		template <class Pred> Udm::DerivedAttr<StateMachine, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<StateMachine, Pred>(impl); }
		Udm::ArchetypeAttr<StateMachine> Archetype() const { return Udm::ArchetypeAttr<StateMachine>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::ChildrenAttr< ::SM::Reference> Reference_children() const { return Udm::ChildrenAttr< ::SM::Reference>(impl, meta_Reference_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Reference, Pred> Reference_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Reference, Pred>(impl, meta_Reference_children); }
		Udm::ChildrenAttr< ::SM::Transition> Transition_children() const { return Udm::ChildrenAttr< ::SM::Transition>(impl, meta_Transition_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Transition, Pred> Transition_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Transition, Pred>(impl, meta_Transition_children); }
		Udm::ChildrenAttr< ::SM::BaseState> BaseState_children() const { return Udm::ChildrenAttr< ::SM::BaseState>(impl, meta_BaseState_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::BaseState, Pred> BaseState_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::BaseState, Pred>(impl, meta_BaseState_children); }
		Udm::ChildrenAttr< ::SM::Transition> Transition_kind_children() const { return Udm::ChildrenAttr< ::SM::Transition>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Transition, Pred> Transition_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Transition, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::State> State_kind_children() const { return Udm::ChildrenAttr< ::SM::State>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::State, Pred> State_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::State, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::Reference> Reference_kind_children() const { return Udm::ChildrenAttr< ::SM::Reference>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Reference, Pred> Reference_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Reference, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::StartState> StartState_kind_children() const { return Udm::ChildrenAttr< ::SM::StartState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::StartState, Pred> StartState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::StartState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::BaseState> BaseState_kind_children() const { return Udm::ChildrenAttr< ::SM::BaseState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::BaseState, Pred> BaseState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::BaseState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::SM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::SM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::SM::RootFolder>(impl, meta_RootFolder_parent); }
		Udm::ParentAttr< ::SM::RootFolder> parent() const { return Udm::ParentAttr< ::SM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_StateMachine(*this); }
		void Leave(Visitor &v) { v.Leave_StateMachine(*this); }
		using LEESA::VisitorAsIndex_CRTP< StateMachine, Visitor >::operator [];


		static ::Uml::Class meta;
		static ::Uml::CompositionChildRole meta_Reference_children;
		static ::Uml::CompositionChildRole meta_Transition_children;
		static ::Uml::CompositionChildRole meta_BaseState_children;
		static ::Uml::CompositionParentRole meta_RootFolder_parent;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::RootFolder> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::SM::Transition, ::SM::State, ::SM::Reference, ::SM::StartState, ::SM::BaseState> ChildrenKinds;







	};

	class SM_Export Transition :  public MgaObject , public LEESA::VisitorAsIndex_CRTP< Transition, Visitor > {
	public:
		typedef ::Udm::ConnectionMetaTag MetaKind;

		Transition() {}
		Transition(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		Transition(const Transition &master) : MgaObject(master) {}

		static Transition Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static Transition Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		Transition CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<Transition> Instances() { return Udm::InstantiatedAttr<Transition>(impl); }
		template <class Pred> Udm::InstantiatedAttr<Transition, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<Transition, Pred>(impl); }
		Transition CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<Transition> Derived() { return Udm::DerivedAttr<Transition>(impl); }
		template <class Pred> Udm::DerivedAttr<Transition, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<Transition, Pred>(impl); }
		Udm::ArchetypeAttr<Transition> Archetype() const { return Udm::ArchetypeAttr<Transition>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::StringAttr Event() const { return Udm::StringAttr(impl, meta_Event); }
		Udm::ParentAttr< ::SM::StateMachine> StateMachine_parent() const { return Udm::ParentAttr< ::SM::StateMachine>(impl, meta_StateMachine_parent); }
		Udm::ParentAttr< ::SM::BaseState> BaseState_parent() const { return Udm::ParentAttr< ::SM::BaseState>(impl, meta_BaseState_parent); }
		Udm::ParentAttr< ::SM::MgaObject> parent() const { return Udm::ParentAttr< ::SM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		Udm::AssocEndAttr< ::SM::BaseState> srcTransition_end() const { return Udm::AssocEndAttr< ::SM::BaseState>(impl, meta_srcTransition_end_); }
		Udm::AssocEndAttr< ::SM::BaseState> dstTransition_end() const { return Udm::AssocEndAttr< ::SM::BaseState>(impl, meta_dstTransition_end_); }
		void Accept(Visitor &v) { v.Visit_Transition(*this); }
		void Leave(Visitor &v) { v.Leave_Transition(*this); }
		using LEESA::VisitorAsIndex_CRTP< Transition, Visitor >::operator [];


		static ::Uml::Class meta;
		static ::Uml::Attribute meta_Event;
		static ::Uml::CompositionParentRole meta_StateMachine_parent;
		static ::Uml::CompositionParentRole meta_BaseState_parent;
		static ::Uml::AssociationRole meta_srcTransition_end_;
		static ::Uml::AssociationRole meta_dstTransition_end_;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::StateMachine, ::SM::BaseState> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;







	};

	class SM_Export Reference :  public MgaObject , public LEESA::VisitorAsIndex_CRTP< Reference, Visitor > {
	public:
		typedef ::Udm::ReferenceMetaTag MetaKind;

		Reference() {}
		Reference(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		Reference(const Reference &master) : MgaObject(master) {}

		static Reference Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static Reference Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		Reference CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<Reference> Instances() { return Udm::InstantiatedAttr<Reference>(impl); }
		template <class Pred> Udm::InstantiatedAttr<Reference, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<Reference, Pred>(impl); }
		Reference CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<Reference> Derived() { return Udm::DerivedAttr<Reference>(impl); }
		template <class Pred> Udm::DerivedAttr<Reference, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<Reference, Pred>(impl); }
		Udm::ArchetypeAttr<Reference> Archetype() const { return Udm::ArchetypeAttr<Reference>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::PointerAttr< ::SM::BaseState> ref() const { return Udm::PointerAttr< ::SM::BaseState>(impl, meta_ref); }
		Udm::ParentAttr< ::SM::StateMachine> StateMachine_parent() const { return Udm::ParentAttr< ::SM::StateMachine>(impl, meta_StateMachine_parent); }
		Udm::ParentAttr< ::SM::BaseState> BaseState_parent() const { return Udm::ParentAttr< ::SM::BaseState>(impl, meta_BaseState_parent); }
		Udm::ParentAttr< ::SM::MgaObject> parent() const { return Udm::ParentAttr< ::SM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_Reference(*this); }
		void Leave(Visitor &v) { v.Leave_Reference(*this); }
		using LEESA::VisitorAsIndex_CRTP< Reference, Visitor >::operator [];


		static ::Uml::Class meta;
		static ::Uml::AssociationRole meta_ref;
		static ::Uml::CompositionParentRole meta_StateMachine_parent;
		static ::Uml::CompositionParentRole meta_BaseState_parent;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::StateMachine, ::SM::BaseState> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;







	};

	class SM_Export BaseState :  public MgaObject , public LEESA::VisitorAsIndex_CRTP< BaseState, Visitor > {
	public:
		typedef ::Udm::ModelMetaTag MetaKind;

		BaseState() {}
		BaseState(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		BaseState(const BaseState &master) : MgaObject(master) {}

		static BaseState Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static BaseState Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		BaseState CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<BaseState> Instances() { return Udm::InstantiatedAttr<BaseState>(impl); }
		template <class Pred> Udm::InstantiatedAttr<BaseState, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<BaseState, Pred>(impl); }
		BaseState CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<BaseState> Derived() { return Udm::DerivedAttr<BaseState>(impl); }
		template <class Pred> Udm::DerivedAttr<BaseState, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<BaseState, Pred>(impl); }
		Udm::ArchetypeAttr<BaseState> Archetype() const { return Udm::ArchetypeAttr<BaseState>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::AssocAttr< ::SM::Reference> referedbyReference() const { return Udm::AssocAttr< ::SM::Reference>(impl, meta_referedbyReference); }
		template <class Pred> Udm::AssocAttr< ::SM::Reference, Pred> referedbyReference_sorted(const Pred &) const { return Udm::AssocAttr< ::SM::Reference, Pred>(impl, meta_referedbyReference); }
		Udm::AClassAssocAttr< ::SM::Transition, ::SM::BaseState> dstTransition() const { return Udm::AClassAssocAttr< ::SM::Transition, ::SM::BaseState>(impl, meta_dstTransition, meta_dstTransition_rev); }
		template <class Pred> Udm::AClassAssocAttr< ::SM::Transition, ::SM::BaseState, Pred> dstTransition_sorted(const Pred &) const { return Udm::AClassAssocAttr< ::SM::Transition, ::SM::BaseState, Pred>(impl, meta_dstTransition, meta_dstTransition_rev); }
		Udm::AClassAssocAttr< ::SM::Transition, ::SM::BaseState> srcTransition() const { return Udm::AClassAssocAttr< ::SM::Transition, ::SM::BaseState>(impl, meta_srcTransition, meta_srcTransition_rev); }
		template <class Pred> Udm::AClassAssocAttr< ::SM::Transition, ::SM::BaseState, Pred> srcTransition_sorted(const Pred &) const { return Udm::AClassAssocAttr< ::SM::Transition, ::SM::BaseState, Pred>(impl, meta_srcTransition, meta_srcTransition_rev); }
		Udm::ChildrenAttr< ::SM::BaseState> BaseState_children() const { return Udm::ChildrenAttr< ::SM::BaseState>(impl, meta_BaseState_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::BaseState, Pred> BaseState_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::BaseState, Pred>(impl, meta_BaseState_children); }
		Udm::ChildrenAttr< ::SM::Reference> Reference_children() const { return Udm::ChildrenAttr< ::SM::Reference>(impl, meta_Reference_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Reference, Pred> Reference_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Reference, Pred>(impl, meta_Reference_children); }
		Udm::ChildrenAttr< ::SM::Transition> Transition_children() const { return Udm::ChildrenAttr< ::SM::Transition>(impl, meta_Transition_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Transition, Pred> Transition_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Transition, Pred>(impl, meta_Transition_children); }
		Udm::ChildrenAttr< ::SM::Transition> Transition_kind_children() const { return Udm::ChildrenAttr< ::SM::Transition>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Transition, Pred> Transition_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Transition, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::State> State_kind_children() const { return Udm::ChildrenAttr< ::SM::State>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::State, Pred> State_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::State, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::Reference> Reference_kind_children() const { return Udm::ChildrenAttr< ::SM::Reference>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Reference, Pred> Reference_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Reference, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::StartState> StartState_kind_children() const { return Udm::ChildrenAttr< ::SM::StartState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::StartState, Pred> StartState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::StartState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::BaseState> BaseState_kind_children() const { return Udm::ChildrenAttr< ::SM::BaseState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::BaseState, Pred> BaseState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::BaseState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::SM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::SM::StateMachine> StateMachine_parent() const { return Udm::ParentAttr< ::SM::StateMachine>(impl, meta_StateMachine_parent); }
		Udm::ParentAttr< ::SM::BaseState> BaseState_parent() const { return Udm::ParentAttr< ::SM::BaseState>(impl, meta_BaseState_parent); }
		Udm::ParentAttr< ::SM::MgaObject> parent() const { return Udm::ParentAttr< ::SM::MgaObject>(impl, Udm::NULLPARENTROLE); }

		void Leave(Visitor &v) { }

		static ::Uml::Class meta;
		static ::Uml::AssociationRole meta_referedbyReference;
		static ::Uml::AssociationRole meta_dstTransition;
		static ::Uml::AssociationRole meta_dstTransition_rev;
		static ::Uml::AssociationRole meta_srcTransition;
		static ::Uml::AssociationRole meta_srcTransition_rev;
		static ::Uml::CompositionChildRole meta_BaseState_children;
		static ::Uml::CompositionChildRole meta_Reference_children;
		static ::Uml::CompositionChildRole meta_Transition_children;
		static ::Uml::CompositionParentRole meta_StateMachine_parent;
		static ::Uml::CompositionParentRole meta_BaseState_parent;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::StateMachine, ::SM::BaseState> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::SM::Transition, ::SM::State, ::SM::Reference, ::SM::StartState, ::SM::BaseState> ChildrenKinds;







	};

	class SM_Export State :  public BaseState , public LEESA::VisitorAsIndex_CRTP< State, Visitor > {
	public:
		typedef ::Udm::ModelMetaTag MetaKind;

		State() {}
		State(Udm::ObjectImpl *impl) : BaseState(impl) {}
		State(const State &master) : BaseState(master) {}

		static State Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static State Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		State CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<State> Instances() { return Udm::InstantiatedAttr<State>(impl); }
		template <class Pred> Udm::InstantiatedAttr<State, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<State, Pred>(impl); }
		State CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<State> Derived() { return Udm::DerivedAttr<State>(impl); }
		template <class Pred> Udm::DerivedAttr<State, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<State, Pred>(impl); }
		Udm::ArchetypeAttr<State> Archetype() const { return Udm::ArchetypeAttr<State>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::ParentAttr< ::SM::MgaObject> parent() const { return Udm::ParentAttr< ::SM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_State(*this); }
		void Leave(Visitor &v) { v.Leave_State(*this); }
		using LEESA::VisitorAsIndex_CRTP< State, Visitor >::operator [];


		static ::Uml::Class meta;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::StateMachine, ::SM::BaseState> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::SM::Transition, ::SM::State, ::SM::Reference, ::SM::StartState, ::SM::BaseState> ChildrenKinds;







	};

	class SM_Export StartState :  public BaseState , public LEESA::VisitorAsIndex_CRTP< StartState, Visitor > {
	public:
		typedef ::Udm::ModelMetaTag MetaKind;

		StartState() {}
		StartState(Udm::ObjectImpl *impl) : BaseState(impl) {}
		StartState(const StartState &master) : BaseState(master) {}

		static StartState Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static StartState Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		StartState CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<StartState> Instances() { return Udm::InstantiatedAttr<StartState>(impl); }
		template <class Pred> Udm::InstantiatedAttr<StartState, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<StartState, Pred>(impl); }
		StartState CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<StartState> Derived() { return Udm::DerivedAttr<StartState>(impl); }
		template <class Pred> Udm::DerivedAttr<StartState, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<StartState, Pred>(impl); }
		Udm::ArchetypeAttr<StartState> Archetype() const { return Udm::ArchetypeAttr<StartState>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::ParentAttr< ::SM::MgaObject> parent() const { return Udm::ParentAttr< ::SM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_StartState(*this); }
		void Leave(Visitor &v) { v.Leave_StartState(*this); }
		using LEESA::VisitorAsIndex_CRTP< StartState, Visitor >::operator [];


		static ::Uml::Class meta;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::StateMachine, ::SM::BaseState> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::SM::Transition, ::SM::State, ::SM::Reference, ::SM::StartState, ::SM::BaseState> ChildrenKinds;







	};

	class SM_Export Sequence :  public MgaObject , public LEESA::VisitorAsIndex_CRTP< Sequence, Visitor > {
	public:
		typedef ::Udm::ConnectionMetaTag MetaKind;

		Sequence() {}
		Sequence(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		Sequence(const Sequence &master) : MgaObject(master) {}

		static Sequence Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static Sequence Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		Sequence CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<Sequence> Instances() { return Udm::InstantiatedAttr<Sequence>(impl); }
		template <class Pred> Udm::InstantiatedAttr<Sequence, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<Sequence, Pred>(impl); }
		Sequence CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<Sequence> Derived() { return Udm::DerivedAttr<Sequence>(impl); }
		template <class Pred> Udm::DerivedAttr<Sequence, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<Sequence, Pred>(impl); }
		Udm::ArchetypeAttr<Sequence> Archetype() const { return Udm::ArchetypeAttr<Sequence>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::ParentAttr< ::SM::InputSequence> InputSequence_parent() const { return Udm::ParentAttr< ::SM::InputSequence>(impl, meta_InputSequence_parent); }
		Udm::ParentAttr< ::SM::MgaObject> parent() const { return Udm::ParentAttr< ::SM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		Udm::AssocEndAttr< ::SM::Events> dstSequence_end() const { return Udm::AssocEndAttr< ::SM::Events>(impl, meta_dstSequence_end_); }
		Udm::AssocEndAttr< ::SM::Events> srcSequence_end() const { return Udm::AssocEndAttr< ::SM::Events>(impl, meta_srcSequence_end_); }
		void Accept(Visitor &v) { v.Visit_Sequence(*this); }
		void Leave(Visitor &v) { v.Leave_Sequence(*this); }
		using LEESA::VisitorAsIndex_CRTP< Sequence, Visitor >::operator [];


		static ::Uml::Class meta;
		static ::Uml::CompositionParentRole meta_InputSequence_parent;
		static ::Uml::AssociationRole meta_dstSequence_end_;
		static ::Uml::AssociationRole meta_srcSequence_end_;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::InputSequence> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;







	};

	class SM_Export InputSequence :  public MgaObject , public LEESA::VisitorAsIndex_CRTP< InputSequence, Visitor > {
	public:
		typedef ::Udm::ModelMetaTag MetaKind;

		InputSequence() {}
		InputSequence(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		InputSequence(const InputSequence &master) : MgaObject(master) {}

		static InputSequence Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static InputSequence Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		InputSequence CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<InputSequence> Instances() { return Udm::InstantiatedAttr<InputSequence>(impl); }
		template <class Pred> Udm::InstantiatedAttr<InputSequence, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<InputSequence, Pred>(impl); }
		InputSequence CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<InputSequence> Derived() { return Udm::DerivedAttr<InputSequence>(impl); }
		template <class Pred> Udm::DerivedAttr<InputSequence, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<InputSequence, Pred>(impl); }
		Udm::ArchetypeAttr<InputSequence> Archetype() const { return Udm::ArchetypeAttr<InputSequence>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::ChildrenAttr< ::SM::Sequence> Sequence_children() const { return Udm::ChildrenAttr< ::SM::Sequence>(impl, meta_Sequence_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Sequence, Pred> Sequence_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Sequence, Pred>(impl, meta_Sequence_children); }
		Udm::ChildrenAttr< ::SM::Events> Events_children() const { return Udm::ChildrenAttr< ::SM::Events>(impl, meta_Events_children); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Events, Pred> Events_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Events, Pred>(impl, meta_Events_children); }
		Udm::ChildrenAttr< ::SM::Sequence> Sequence_kind_children() const { return Udm::ChildrenAttr< ::SM::Sequence>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Sequence, Pred> Sequence_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Sequence, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::Events> Events_kind_children() const { return Udm::ChildrenAttr< ::SM::Events>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::Events, Pred> Events_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::Events, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::SM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::SM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::SM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::SM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::SM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::SM::RootFolder>(impl, meta_RootFolder_parent); }
		Udm::ParentAttr< ::SM::RootFolder> parent() const { return Udm::ParentAttr< ::SM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_InputSequence(*this); }
		void Leave(Visitor &v) { v.Leave_InputSequence(*this); }
		using LEESA::VisitorAsIndex_CRTP< InputSequence, Visitor >::operator [];


		static ::Uml::Class meta;
		static ::Uml::CompositionChildRole meta_Sequence_children;
		static ::Uml::CompositionChildRole meta_Events_children;
		static ::Uml::CompositionParentRole meta_RootFolder_parent;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::RootFolder> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::SM::Sequence, ::SM::Events> ChildrenKinds;







	};

	class SM_Export Events :  public MgaObject , public LEESA::VisitorAsIndex_CRTP< Events, Visitor > {
	public:
		typedef ::Udm::AtomMetaTag MetaKind;

		Events() {}
		Events(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		Events(const Events &master) : MgaObject(master) {}

		static Events Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static Events Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		Events CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<Events> Instances() { return Udm::InstantiatedAttr<Events>(impl); }
		template <class Pred> Udm::InstantiatedAttr<Events, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<Events, Pred>(impl); }
		Events CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<Events> Derived() { return Udm::DerivedAttr<Events>(impl); }
		template <class Pred> Udm::DerivedAttr<Events, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<Events, Pred>(impl); }
		Udm::ArchetypeAttr<Events> Archetype() const { return Udm::ArchetypeAttr<Events>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		Udm::IntegerAttr Delay() const { return Udm::IntegerAttr(impl, meta_Delay); }
		Udm::AClassPointerAttr< ::SM::Sequence, ::SM::Events> srcSequence() const { return Udm::AClassPointerAttr< ::SM::Sequence, ::SM::Events>(impl, meta_srcSequence, meta_srcSequence_rev); }
		Udm::AClassPointerAttr< ::SM::Sequence, ::SM::Events> dstSequence() const { return Udm::AClassPointerAttr< ::SM::Sequence, ::SM::Events>(impl, meta_dstSequence, meta_dstSequence_rev); }
		Udm::ParentAttr< ::SM::InputSequence> InputSequence_parent() const { return Udm::ParentAttr< ::SM::InputSequence>(impl, meta_InputSequence_parent); }
		Udm::ParentAttr< ::SM::MgaObject> parent() const { return Udm::ParentAttr< ::SM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_Events(*this); }
		void Leave(Visitor &v) { v.Leave_Events(*this); }
		using LEESA::VisitorAsIndex_CRTP< Events, Visitor >::operator [];


		static ::Uml::Class meta;
		static ::Uml::Attribute meta_Delay;
		static ::Uml::AssociationRole meta_srcSequence;
		static ::Uml::AssociationRole meta_srcSequence_rev;
		static ::Uml::AssociationRole meta_dstSequence;
		static ::Uml::AssociationRole meta_dstSequence_rev;
		static ::Uml::CompositionParentRole meta_InputSequence_parent;


		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::SM::InputSequence> ParentKinds;


		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;







	};

}

// The following is generated by gen-pairs.pl program of LEESA. For more information
// please visit: http://www.dre.vanderbilt.edu/~sutambe/files/LEESA/LEESA.pdf

#ifndef DOMAIN_HAS_DESCENDANT_PAIRS
#define DOMAIN_HAS_DESCENDANT_PAIRS
#endif // DOMAIN_HAS_DESCENDANT_PAIRS

namespace SM {

  struct _False_ { enum { value = 0 }; };
  struct _True_  { enum { value = 1 }; };

  template <class T, class U>
  struct IsDescendant : _False_ {};

  template <> struct IsDescendant < ::SM::BaseState, ::SM::BaseState > : _True_ {};
  template <> struct IsDescendant < ::SM::BaseState, ::SM::Reference > : _True_ {};
  template <> struct IsDescendant < ::SM::BaseState, ::SM::StartState > : _True_ {};
  template <> struct IsDescendant < ::SM::BaseState, ::SM::State > : _True_ {};
  template <> struct IsDescendant < ::SM::BaseState, ::SM::Transition > : _True_ {};

  template <> struct IsDescendant < ::SM::InputSequence, ::SM::Events > : _True_ {};
  template <> struct IsDescendant < ::SM::InputSequence, ::SM::Sequence > : _True_ {};

  template <> struct IsDescendant < ::SM::RootFolder, ::SM::BaseState > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::Events > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::InputSequence > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::Reference > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::RootFolder > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::Sequence > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::StartState > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::State > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::StateMachine > : _True_ {};
  template <> struct IsDescendant < ::SM::RootFolder, ::SM::Transition > : _True_ {};

  template <> struct IsDescendant < ::SM::StartState, ::SM::BaseState > : _True_ {};
  template <> struct IsDescendant < ::SM::StartState, ::SM::Reference > : _True_ {};
  template <> struct IsDescendant < ::SM::StartState, ::SM::StartState > : _True_ {};
  template <> struct IsDescendant < ::SM::StartState, ::SM::State > : _True_ {};
  template <> struct IsDescendant < ::SM::StartState, ::SM::Transition > : _True_ {};

  template <> struct IsDescendant < ::SM::State, ::SM::BaseState > : _True_ {};
  template <> struct IsDescendant < ::SM::State, ::SM::Reference > : _True_ {};
  template <> struct IsDescendant < ::SM::State, ::SM::StartState > : _True_ {};
  template <> struct IsDescendant < ::SM::State, ::SM::State > : _True_ {};
  template <> struct IsDescendant < ::SM::State, ::SM::Transition > : _True_ {};

  template <> struct IsDescendant < ::SM::StateMachine, ::SM::BaseState > : _True_ {};
  template <> struct IsDescendant < ::SM::StateMachine, ::SM::Reference > : _True_ {};
  template <> struct IsDescendant < ::SM::StateMachine, ::SM::StartState > : _True_ {};
  template <> struct IsDescendant < ::SM::StateMachine, ::SM::State > : _True_ {};
  template <> struct IsDescendant < ::SM::StateMachine, ::SM::Transition > : _True_ {};


} // namespace SM

#endif // MOBIES_SM_H

