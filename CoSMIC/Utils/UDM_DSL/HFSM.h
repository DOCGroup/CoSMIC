#ifndef MOBIES_HFSM_H
#define MOBIES_HFSM_H

// header file HFSM.h generated from diagram HFSM
// generated with Udm version 3.13 on Fri Nov 14 10:06:45 2008

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

namespace HFSM {

	extern ::Uml::Diagram meta;
	class InputSequence;
	class Sequence;
	class Events;
	class Transition;
	class FinalState;
	class StartState;
	class State;
	class StateMachine;
	class BaseState;
	class RootFolder;
	class MgaObject;

	class Visitor : public Udm::BaseVisitor {
	public:
		virtual ~Visitor() {}

		virtual void Visit_InputSequence(const InputSequence &) {}
		virtual void Visit_Sequence(const Sequence &) {}
		virtual void Visit_Events(const Events &) {}
		virtual void Visit_Transition(const Transition &) {}
		virtual void Visit_FinalState(const FinalState &) {}
		virtual void Visit_StartState(const StartState &) {}
		virtual void Visit_State(const State &) {}
		virtual void Visit_StateMachine(const StateMachine &) {}
		virtual void Visit_RootFolder(const RootFolder &) {}
		virtual void Visit_Object(const Udm::Object &) const;

	};

	void Initialize();
	void Initialize(const ::Uml::Diagram &dgr);

	extern Udm::UdmDiagram diagram;

	class RootFolder : public Udm::Object {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }
		Udm::ChildrenAttr< ::HFSM::StateMachine> StateMachine_children() const { return Udm::ChildrenAttr< ::HFSM::StateMachine>(impl, meta_StateMachine_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::StateMachine, Pred> StateMachine_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::StateMachine, Pred>(impl, meta_StateMachine_children); }
		Udm::ChildrenAttr< ::HFSM::InputSequence> InputSequence_children() const { return Udm::ChildrenAttr< ::HFSM::InputSequence>(impl, meta_InputSequence_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::InputSequence, Pred> InputSequence_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::InputSequence, Pred>(impl, meta_InputSequence_children); }
		Udm::ChildrenAttr< ::HFSM::RootFolder> RootFolder_children() const { return Udm::ChildrenAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::RootFolder, Pred> RootFolder_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::RootFolder, Pred>(impl, meta_RootFolder_children); }
		Udm::ChildrenAttr< ::HFSM::InputSequence> InputSequence_kind_children() const { return Udm::ChildrenAttr< ::HFSM::InputSequence>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::InputSequence, Pred> InputSequence_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::InputSequence, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::StateMachine> StateMachine_kind_children() const { return Udm::ChildrenAttr< ::HFSM::StateMachine>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::StateMachine, Pred> StateMachine_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::StateMachine, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::RootFolder> RootFolder_kind_children() const { return Udm::ChildrenAttr< ::HFSM::RootFolder>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::RootFolder, Pred> RootFolder_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::RootFolder, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::HFSM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_parent); }
		Udm::ParentAttr< ::HFSM::RootFolder> parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_RootFolder(*this); }

		static ::Uml::Class meta;
		static ::Uml::Attribute meta_name;
		static ::Uml::CompositionChildRole meta_StateMachine_children;
		static ::Uml::CompositionChildRole meta_InputSequence_children;
		static ::Uml::CompositionChildRole meta_RootFolder_children;
		static ::Uml::CompositionParentRole meta_RootFolder_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_RootFolder_parent {};
		typedef boost::mpl::pair< ::HFSM::RootFolder, PR_RootFolder_parent > _PR_RootFolder_parent__RootFolder;
		typedef boost::mpl::vector< _PR_RootFolder_parent__RootFolder> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::RootFolder> ParentKinds;

		// types and typelist for children by returned type and role relations;
		class CR_StateMachine_children {};
		class CR_InputSequence_children {};
		class CR_RootFolder_children {};
		typedef boost::mpl::pair< ::HFSM::StateMachine, CR_StateMachine_children > _CR_StateMachine_children__StateMachine;
		typedef boost::mpl::pair< ::HFSM::InputSequence, CR_InputSequence_children > _CR_InputSequence_children__InputSequence;
		typedef boost::mpl::pair< ::HFSM::RootFolder, CR_RootFolder_children > _CR_RootFolder_children__RootFolder;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< _CR_StateMachine_children__StateMachine, _CR_InputSequence_children__InputSequence, _CR_RootFolder_children__RootFolder> ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::InputSequence, ::HFSM::StateMachine, ::HFSM::RootFolder> ChildrenKinds;
    typedef boost::mpl::vector< 
    ::HFSM::RootFolder,
    ::HFSM::InputSequence,                           
    ::HFSM::Sequence,
    ::HFSM::Events,
    ::HFSM::StateMachine,
    ::HFSM::Transition,
    ::HFSM::StartState,
    ::HFSM::FinalState,
    ::HFSM::State,
    ::HFSM::BaseState> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class MgaObject : public Udm::Object {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::StringAttr position() const { return Udm::StringAttr(impl, meta_position); }
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }
		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }

		static ::Uml::Class meta;
		static ::Uml::Attribute meta_position;
		static ::Uml::Attribute meta_name;

		// types and typelist for parent by returned type and role relations;
		typedef boost::mpl::vector< > Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< > ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class InputSequence :  public MgaObject {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::ChildrenAttr< ::HFSM::Sequence> Sequence_children() const { return Udm::ChildrenAttr< ::HFSM::Sequence>(impl, meta_Sequence_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Sequence, Pred> Sequence_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Sequence, Pred>(impl, meta_Sequence_children); }
		Udm::ChildrenAttr< ::HFSM::Events> Events_children() const { return Udm::ChildrenAttr< ::HFSM::Events>(impl, meta_Events_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Events, Pred> Events_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Events, Pred>(impl, meta_Events_children); }
		Udm::ChildrenAttr< ::HFSM::Sequence> Sequence_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Sequence>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Sequence, Pred> Sequence_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Sequence, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::Events> Events_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Events>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Events, Pred> Events_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Events, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::HFSM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_parent); }
		Udm::ParentAttr< ::HFSM::RootFolder> parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_InputSequence(*this); }

		static ::Uml::Class meta;
		static ::Uml::CompositionChildRole meta_Sequence_children;
		static ::Uml::CompositionChildRole meta_Events_children;
		static ::Uml::CompositionParentRole meta_RootFolder_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_RootFolder_parent {};
		typedef boost::mpl::pair< ::HFSM::RootFolder, PR_RootFolder_parent > _PR_RootFolder_parent__RootFolder;
		typedef boost::mpl::vector< _PR_RootFolder_parent__RootFolder> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::RootFolder> ParentKinds;

		// types and typelist for children by returned type and role relations;
		class CR_Sequence_children {};
		class CR_Events_children {};
		typedef boost::mpl::pair< ::HFSM::Sequence, CR_Sequence_children > _CR_Sequence_children__Sequence;
		typedef boost::mpl::pair< ::HFSM::Events, CR_Events_children > _CR_Events_children__Events;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< _CR_Sequence_children__Sequence, _CR_Events_children__Events> ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Sequence, ::HFSM::Events> ChildrenKinds;
    typedef boost::mpl::vector<                         
      ::HFSM::Sequence,
      ::HFSM::Events> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class Sequence :  public MgaObject {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::ParentAttr< ::HFSM::InputSequence> InputSequence_parent() const { return Udm::ParentAttr< ::HFSM::InputSequence>(impl, meta_InputSequence_parent); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		Udm::AssocEndAttr< ::HFSM::Events> dstSequence_end() const { return Udm::AssocEndAttr< ::HFSM::Events>(impl, meta_dstSequence_end_); }
		Udm::AssocEndAttr< ::HFSM::Events> srcSequence_end() const { return Udm::AssocEndAttr< ::HFSM::Events>(impl, meta_srcSequence_end_); }
		void Accept(Visitor &v) { v.Visit_Sequence(*this); }

		static ::Uml::Class meta;
		static ::Uml::CompositionParentRole meta_InputSequence_parent;
		static ::Uml::AssociationRole meta_dstSequence_end_;
		static ::Uml::AssociationRole meta_srcSequence_end_;

		// types and typelist for parent by returned type and role relations;
		class PR_InputSequence_parent {};
		typedef boost::mpl::pair< ::HFSM::InputSequence, PR_InputSequence_parent > _PR_InputSequence_parent__InputSequence;
		typedef boost::mpl::vector< _PR_InputSequence_parent__InputSequence> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::InputSequence> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;
    typedef boost::mpl::vector<> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		class ACE_dstSequence {};
		class ACE_srcSequence {};
		typedef boost::mpl::pair< ::HFSM::Events, ACE_dstSequence > _ACE_dstSequence__Events;
		typedef boost::mpl::pair< ::HFSM::Events, ACE_srcSequence > _ACE_srcSequence__Events;
		typedef boost::mpl::vector< _ACE_dstSequence__Events, _ACE_srcSequence__Events> AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class Events :  public MgaObject {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::IntegerAttr Delay() const { return Udm::IntegerAttr(impl, meta_Delay); }
		Udm::AClassPointerAttr< ::HFSM::Sequence, ::HFSM::Events> srcSequence() const { return Udm::AClassPointerAttr< ::HFSM::Sequence, ::HFSM::Events>(impl, meta_srcSequence, meta_srcSequence_rev); }
		Udm::AClassPointerAttr< ::HFSM::Sequence, ::HFSM::Events> dstSequence() const { return Udm::AClassPointerAttr< ::HFSM::Sequence, ::HFSM::Events>(impl, meta_dstSequence, meta_dstSequence_rev); }
		Udm::ParentAttr< ::HFSM::InputSequence> InputSequence_parent() const { return Udm::ParentAttr< ::HFSM::InputSequence>(impl, meta_InputSequence_parent); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_Events(*this); }

		static ::Uml::Class meta;
		static ::Uml::Attribute meta_Delay;
		static ::Uml::AssociationRole meta_srcSequence;
		static ::Uml::AssociationRole meta_srcSequence_rev;
		static ::Uml::AssociationRole meta_dstSequence;
		static ::Uml::AssociationRole meta_dstSequence_rev;
		static ::Uml::CompositionParentRole meta_InputSequence_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_InputSequence_parent {};
		typedef boost::mpl::pair< ::HFSM::InputSequence, PR_InputSequence_parent > _PR_InputSequence_parent__InputSequence;
		typedef boost::mpl::vector< _PR_InputSequence_parent__InputSequence> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::InputSequence> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;
    typedef boost::mpl::vector<> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		class AR_srcSequence {};
		class AR_dstSequence {};
		typedef boost::mpl::pair< ::HFSM::Events, boost::mpl::pair< ::HFSM::Sequence, AR_srcSequence > > _AR_srcSequence__Sequence__Events;
		typedef boost::mpl::pair< ::HFSM::Events, boost::mpl::pair< ::HFSM::Sequence, AR_dstSequence > > _AR_dstSequence__Sequence__Events;
		typedef boost::mpl::vector< _AR_srcSequence__Sequence__Events, _AR_dstSequence__Sequence__Events> AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class Transition :  public MgaObject {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::StringAttr Event() const { return Udm::StringAttr(impl, meta_Event); }
		Udm::ParentAttr< ::HFSM::BaseState> BaseState_parent() const { return Udm::ParentAttr< ::HFSM::BaseState>(impl, meta_BaseState_parent); }
		Udm::ParentAttr< ::HFSM::StateMachine> StateMachine_parent() const { return Udm::ParentAttr< ::HFSM::StateMachine>(impl, meta_StateMachine_parent); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		Udm::AssocEndAttr< ::HFSM::BaseState> dstTransition_end() const { return Udm::AssocEndAttr< ::HFSM::BaseState>(impl, meta_dstTransition_end_); }
		Udm::AssocEndAttr< ::HFSM::BaseState> srcTransition_end() const { return Udm::AssocEndAttr< ::HFSM::BaseState>(impl, meta_srcTransition_end_); }
		void Accept(Visitor &v) { v.Visit_Transition(*this); }

		static ::Uml::Class meta;
		static ::Uml::Attribute meta_Event;
		static ::Uml::CompositionParentRole meta_BaseState_parent;
		static ::Uml::CompositionParentRole meta_StateMachine_parent;
		static ::Uml::AssociationRole meta_dstTransition_end_;
		static ::Uml::AssociationRole meta_srcTransition_end_;

		// types and typelist for parent by returned type and role relations;
		class PR_BaseState_parent {};
		class PR_StateMachine_parent {};
		typedef boost::mpl::pair< ::HFSM::BaseState, PR_BaseState_parent > _PR_BaseState_parent__BaseState;
		typedef boost::mpl::pair< ::HFSM::StateMachine, PR_StateMachine_parent > _PR_StateMachine_parent__StateMachine;
		typedef boost::mpl::vector< _PR_BaseState_parent__BaseState, _PR_StateMachine_parent__StateMachine> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::StateMachine, ::HFSM::BaseState> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;
    typedef boost::mpl::vector<> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		class ACE_dstTransition {};
		class ACE_srcTransition {};
		typedef boost::mpl::pair< ::HFSM::BaseState, ACE_dstTransition > _ACE_dstTransition__BaseState;
		typedef boost::mpl::pair< ::HFSM::BaseState, ACE_srcTransition > _ACE_srcTransition__BaseState;
		typedef boost::mpl::vector< _ACE_dstTransition__BaseState, _ACE_srcTransition__BaseState> AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class StateMachine :  public MgaObject {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::ChildrenAttr< ::HFSM::BaseState> BaseState_children() const { return Udm::ChildrenAttr< ::HFSM::BaseState>(impl, meta_BaseState_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::BaseState, Pred> BaseState_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::BaseState, Pred>(impl, meta_BaseState_children); }
		Udm::ChildrenAttr< ::HFSM::Transition> Transition_children() const { return Udm::ChildrenAttr< ::HFSM::Transition>(impl, meta_Transition_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Transition, Pred> Transition_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Transition, Pred>(impl, meta_Transition_children); }
		Udm::ChildrenAttr< ::HFSM::Transition> Transition_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Transition>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Transition, Pred> Transition_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Transition, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::FinalState> FinalState_kind_children() const { return Udm::ChildrenAttr< ::HFSM::FinalState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::FinalState, Pred> FinalState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::FinalState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::StartState> StartState_kind_children() const { return Udm::ChildrenAttr< ::HFSM::StartState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::StartState, Pred> StartState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::StartState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::State> State_kind_children() const { return Udm::ChildrenAttr< ::HFSM::State>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::State, Pred> State_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::State, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::BaseState> BaseState_kind_children() const { return Udm::ChildrenAttr< ::HFSM::BaseState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::BaseState, Pred> BaseState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::BaseState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::HFSM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_parent); }
		Udm::ParentAttr< ::HFSM::RootFolder> parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_StateMachine(*this); }

		static ::Uml::Class meta;
		static ::Uml::CompositionChildRole meta_BaseState_children;
		static ::Uml::CompositionChildRole meta_Transition_children;
		static ::Uml::CompositionParentRole meta_RootFolder_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_RootFolder_parent {};
		typedef boost::mpl::pair< ::HFSM::RootFolder, PR_RootFolder_parent > _PR_RootFolder_parent__RootFolder;
		typedef boost::mpl::vector< _PR_RootFolder_parent__RootFolder> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::RootFolder> ParentKinds;

		// types and typelist for children by returned type and role relations;
		class CR_BaseState_children {};
		class CR_Transition_children {};
		typedef boost::mpl::pair< ::HFSM::BaseState, CR_BaseState_children > _CR_BaseState_children__BaseState;
		typedef boost::mpl::pair< ::HFSM::Transition, CR_Transition_children > _CR_Transition_children__Transition;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< _CR_BaseState_children__BaseState, _CR_Transition_children__Transition> ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Transition, ::HFSM::BaseState> ChildrenKinds;
    typedef boost::mpl::vector< 
        ::HFSM::Transition,
        ::HFSM::StartState,
        ::HFSM::FinalState,
        ::HFSM::State,
        ::HFSM::BaseState> DescendantKinds;

    // types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class BaseState :  public MgaObject {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::AClassPointerAttr< ::HFSM::Transition, ::HFSM::BaseState> srcTransition() const { return Udm::AClassPointerAttr< ::HFSM::Transition, ::HFSM::BaseState>(impl, meta_srcTransition, meta_srcTransition_rev); }
		Udm::AClassPointerAttr< ::HFSM::Transition, ::HFSM::BaseState> dstTransition() const { return Udm::AClassPointerAttr< ::HFSM::Transition, ::HFSM::BaseState>(impl, meta_dstTransition, meta_dstTransition_rev); }
		Udm::ChildAttr< ::HFSM::Transition> Transition_child() const { return Udm::ChildAttr< ::HFSM::Transition>(impl, meta_Transition_child); }
		Udm::ChildrenAttr< ::HFSM::BaseState> BaseState_children() const { return Udm::ChildrenAttr< ::HFSM::BaseState>(impl, meta_BaseState_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::BaseState, Pred> BaseState_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::BaseState, Pred>(impl, meta_BaseState_children); }
		Udm::ChildrenAttr< ::HFSM::Transition> Transition_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Transition>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Transition, Pred> Transition_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Transition, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::FinalState> FinalState_kind_children() const { return Udm::ChildrenAttr< ::HFSM::FinalState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::FinalState, Pred> FinalState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::FinalState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::StartState> StartState_kind_children() const { return Udm::ChildrenAttr< ::HFSM::StartState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::StartState, Pred> StartState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::StartState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::State> State_kind_children() const { return Udm::ChildrenAttr< ::HFSM::State>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::State, Pred> State_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::State, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::BaseState> BaseState_kind_children() const { return Udm::ChildrenAttr< ::HFSM::BaseState>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::BaseState, Pred> BaseState_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::BaseState, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::HFSM::StateMachine> StateMachine_parent() const { return Udm::ParentAttr< ::HFSM::StateMachine>(impl, meta_StateMachine_parent); }
		Udm::ParentAttr< ::HFSM::BaseState> BaseState_parent() const { return Udm::ParentAttr< ::HFSM::BaseState>(impl, meta_BaseState_parent); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }

		static ::Uml::Class meta;
		static ::Uml::AssociationRole meta_srcTransition;
		static ::Uml::AssociationRole meta_srcTransition_rev;
		static ::Uml::AssociationRole meta_dstTransition;
		static ::Uml::AssociationRole meta_dstTransition_rev;
		static ::Uml::CompositionChildRole meta_Transition_child;
		static ::Uml::CompositionChildRole meta_BaseState_children;
		static ::Uml::CompositionParentRole meta_StateMachine_parent;
		static ::Uml::CompositionParentRole meta_BaseState_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_StateMachine_parent {};
		class PR_BaseState_parent {};
		typedef boost::mpl::pair< ::HFSM::StateMachine, PR_StateMachine_parent > _PR_StateMachine_parent__StateMachine;
		typedef boost::mpl::pair< ::HFSM::BaseState, PR_BaseState_parent > _PR_BaseState_parent__BaseState;
		typedef boost::mpl::vector< _PR_StateMachine_parent__StateMachine, _PR_BaseState_parent__BaseState> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::StateMachine, ::HFSM::BaseState> ParentKinds;

		// types and typelist for children by returned type and role relations;
		class CR_Transition_child {};
		class CR_BaseState_children {};
		typedef boost::mpl::pair< ::HFSM::Transition, CR_Transition_child > _CR_Transition_child__Transition;
		typedef boost::mpl::pair< ::HFSM::BaseState, CR_BaseState_children > _CR_BaseState_children__BaseState;
		typedef boost::mpl::vector< _CR_Transition_child__Transition> ChildrenSingle;
		typedef boost::mpl::vector< _CR_BaseState_children__BaseState> ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Transition, ::HFSM::BaseState> ChildrenKinds;
    typedef boost::mpl::vector< 
              ::HFSM::Transition,
              ::HFSM::StartState,
              ::HFSM::FinalState,
              ::HFSM::State,
              ::HFSM::BaseState> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		class AR_srcTransition {};
		class AR_dstTransition {};
		typedef boost::mpl::pair< ::HFSM::BaseState, boost::mpl::pair< ::HFSM::Transition, AR_srcTransition > > _AR_srcTransition__Transition__BaseState;
		typedef boost::mpl::pair< ::HFSM::BaseState, boost::mpl::pair< ::HFSM::Transition, AR_dstTransition > > _AR_dstTransition__Transition__BaseState;
		typedef boost::mpl::vector< _AR_srcTransition__Transition__BaseState, _AR_dstTransition__Transition__BaseState> AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class FinalState :  public BaseState {
	public:
		typedef ::Udm::ModelMetaTag MetaKind;

		FinalState() {}
		FinalState(Udm::ObjectImpl *impl) : BaseState(impl) {}
		FinalState(const FinalState &master) : BaseState(master) {}

		static FinalState Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static FinalState Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		FinalState CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<FinalState> Instances() { return Udm::InstantiatedAttr<FinalState>(impl); }
		template <class Pred> Udm::InstantiatedAttr<FinalState, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<FinalState, Pred>(impl); }
		FinalState CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<FinalState> Derived() { return Udm::DerivedAttr<FinalState>(impl); }
		template <class Pred> Udm::DerivedAttr<FinalState, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<FinalState, Pred>(impl); }
		Udm::ArchetypeAttr<FinalState> Archetype() const { return Udm::ArchetypeAttr<FinalState>(impl); }
		template <typename T> const ::Uml::AssociationRole& _type2ARole() const;
		template <typename T> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> _type2ACARole() const;
		template <typename T> const ::Uml::CompositionParentRole& _type2CPRole() const;
		template <typename T> const ::Uml::CompositionChildRole& _type2CCRole() const;
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_FinalState(*this); }

		static ::Uml::Class meta;

		// types and typelist for parent by returned type and role relations;
		typedef boost::mpl::vector< > Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::StateMachine, ::HFSM::BaseState> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Transition, ::HFSM::BaseState> ChildrenKinds;
    typedef boost::mpl::vector< 
              ::HFSM::Transition,
              ::HFSM::StartState,
              ::HFSM::FinalState,
              ::HFSM::State,
              ::HFSM::BaseState> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class StartState :  public BaseState {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_StartState(*this); }

		static ::Uml::Class meta;

		// types and typelist for parent by returned type and role relations;
		typedef boost::mpl::vector< > Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::StateMachine, ::HFSM::BaseState> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Transition, ::HFSM::BaseState> ChildrenKinds;
    typedef boost::mpl::vector< 
              ::HFSM::Transition,
              ::HFSM::StartState,
              ::HFSM::FinalState,
              ::HFSM::State,
              ::HFSM::BaseState> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class State :  public BaseState {
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
		template <class PeerType, class RoleType> Udm::PointerAttr<PeerType> peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, AssociationsSingle> >(); return Udm::PointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::AssocAttr<PeersType> peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::AssocAttr<PeersType, Pred> peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, AssociationsMulti> >(); return Udm::AssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassPointerAttr<ConnectorType, PeerType> connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, AssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassAssocAttr<ConnectorsType, PeerType> connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred> connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, AssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class PeerType, class RoleType> Udm::CrossPointerAttr<PeerType> cross_peer() const { boost::function_requires< Udm::WithRoleInTListConcept<PeerType, RoleType, CrossAssociationsSingle> >(); return Udm::CrossPointerAttr<PeerType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType> Udm::CrossAssocAttr<PeersType> cross_peers() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType>(impl, _type2ARole<RoleType>()); }
		template <class PeersType, class RoleType, class Pred> Udm::CrossAssocAttr<PeersType, Pred> cross_peers_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<PeersType, RoleType, CrossAssociationsMulti> >(); return Udm::CrossAssocAttr<PeersType, Pred>(impl, _type2ARole<RoleType>()); }
		template <class ConnectorType, class PeerType, class RoleType> Udm::AClassCrossPointerAttr<ConnectorType, PeerType> cross_connector() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorType, RoleType, CrossAssociationsWAClassSingle> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossPointerAttr<ConnectorType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType> cross_connectors() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ConnectorsType, class PeerType, class RoleType, class Pred> Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred> cross_connectors_sorted() const { boost::function_requires< Udm::WithAClassAndRoleInTListConcept<PeerType, ConnectorsType, RoleType, CrossAssociationsWAClassMulti> >(); pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> roles_mp = _type2ACARole<RoleType>(); return Udm::AClassCrossAssocAttr<ConnectorsType, PeerType, Pred>(impl, *roles_mp.first, *roles_mp.second); }
		template <class ChildType, class RoleType> Udm::ChildAttr<ChildType> child() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildType, RoleType, ChildrenSingle> >(); return Udm::ChildAttr<ChildType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType> Udm::ChildrenAttr<ChildrenType> children() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType, class RoleType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_sorted() const { boost::function_requires< Udm::WithRoleInTListConcept<ChildrenType, RoleType, ChildrenMulti> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, _type2CCRole<RoleType>()); }
		template <class ChildrenType> Udm::ChildrenAttr<ChildrenType> children_kind() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType>(impl, Udm::NULLCHILDROLE); }
		template <class ChildrenType, class Pred> Udm::ChildrenAttr<ChildrenType, Pred> children_kind_sorted() const { boost::function_requires< Udm::InTListConcept<ChildrenType, ChildrenKinds> >(); return Udm::ChildrenAttr<ChildrenType, Pred>(impl, Udm::NULLCHILDROLE); }
		template <class ParentType, class RoleType> Udm::ParentAttr<ParentType> parent() const { boost::function_requires< Udm::WithRoleInTListConcept<ParentType, RoleType, Parents> >(); return Udm::ParentAttr<ParentType>(impl, _type2CPRole<RoleType>()); }
		template <class ParentType> Udm::ParentAttr<ParentType> parent_kind() const { boost::function_requires< Udm::InTListConcept<ParentType, ParentKinds> >(); return Udm::ParentAttr<ParentType>(impl, Udm::NULLPARENTROLE); }
		template <class EndType, class RoleType> Udm::AssocEndAttr<EndType> end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, AClassEnds> >(); return Udm::AssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		template <class EndType, class RoleType> Udm::CrossAssocEndAttr<EndType> cross_end() const { boost::function_requires< Udm::WithRoleInTListConcept<EndType, RoleType, CrossAClassEnds> >(); return Udm::CrossAssocEndAttr<EndType>(impl, _type2ARole<RoleType>()); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) { v.Visit_State(*this); }

		static ::Uml::Class meta;

		// types and typelist for parent by returned type and role relations;
		typedef boost::mpl::vector< > Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::StateMachine, ::HFSM::BaseState> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Transition, ::HFSM::BaseState> ChildrenKinds;
    typedef boost::mpl::vector< 
              ::HFSM::Transition,
              ::HFSM::StartState,
              ::HFSM::FinalState,
              ::HFSM::State,
              ::HFSM::BaseState> DescendantKinds;

		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< > AssociationsWAClassMulti;

		// types and typelist for cross associations by returned type and role relations;
		typedef boost::mpl::vector< > CrossAssociationsSingle;
		typedef boost::mpl::vector< > CrossAssociationsMulti;

		// types and typelist for cross associations by returned type, association class and role relations;
		typedef boost::mpl::vector< > CrossAssociationsWAClassSingle;
		typedef boost::mpl::vector< > CrossAssociationsWAClassMulti;

		// types and typelist for association class ends by returned type and role relations;
		typedef boost::mpl::vector< > AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

}

#endif // MOBIES_HFSM_H
