#ifndef MOBIES_HFSM_H
#define MOBIES_HFSM_H

// header file HFSM.h generated from diagram HFSM
// generated with Udm version 3.13 on Fri Feb 06 18:54:28 2009

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
	class DataFlow;
	class DataStore;
	class Process;
	class Entity;
	class ContextDFD;
	class RootFolder;
	class MgaObject;

	class Visitor : public Udm::BaseVisitor {
	public:
		virtual ~Visitor() {}

		virtual void Visit_DataFlow(const DataFlow &) {}
		virtual void Visit_DataStore(const DataStore &) {}
		virtual void Visit_Process(const Process &) {}
		virtual void Visit_Entity(const Entity &) {}
		virtual void Visit_ContextDFD(const ContextDFD &) {}
		virtual void Visit_RootFolder(const RootFolder &) {}
		virtual void Visit_Object(const Udm::Object &);

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
		Udm::ChildrenAttr< ::HFSM::RootFolder> RootFolder_children() const { return Udm::ChildrenAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::RootFolder, Pred> RootFolder_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::RootFolder, Pred>(impl, meta_RootFolder_children); }
		Udm::ChildrenAttr< ::HFSM::ContextDFD> ContextDFD_children() const { return Udm::ChildrenAttr< ::HFSM::ContextDFD>(impl, meta_ContextDFD_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::ContextDFD, Pred> ContextDFD_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::ContextDFD, Pred>(impl, meta_ContextDFD_children); }
		Udm::ChildrenAttr< ::HFSM::ContextDFD> ContextDFD_kind_children() const { return Udm::ChildrenAttr< ::HFSM::ContextDFD>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::ContextDFD, Pred> ContextDFD_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::ContextDFD, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::RootFolder> RootFolder_kind_children() const { return Udm::ChildrenAttr< ::HFSM::RootFolder>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::RootFolder, Pred> RootFolder_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::RootFolder, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::HFSM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_parent); }
		Udm::ParentAttr< ::HFSM::RootFolder> parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) const { v.Visit_RootFolder(*this); }
    using Udm::Object::Accept;

		static ::Uml::Class meta;
		static ::Uml::Attribute meta_name;
		static ::Uml::CompositionChildRole meta_RootFolder_children;
		static ::Uml::CompositionChildRole meta_ContextDFD_children;
		static ::Uml::CompositionParentRole meta_RootFolder_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_RootFolder_parent {};
		typedef boost::mpl::pair< ::HFSM::RootFolder, PR_RootFolder_parent > _PR_RootFolder_parent__RootFolder;
		typedef boost::mpl::vector< _PR_RootFolder_parent__RootFolder> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::RootFolder> ParentKinds;

		// types and typelist for children by returned type and role relations;
		class CR_RootFolder_children {};
		class CR_ContextDFD_children {};
		typedef boost::mpl::pair< ::HFSM::RootFolder, CR_RootFolder_children > _CR_RootFolder_children__RootFolder;
		typedef boost::mpl::pair< ::HFSM::ContextDFD, CR_ContextDFD_children > _CR_ContextDFD_children__ContextDFD;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< _CR_RootFolder_children__RootFolder, _CR_ContextDFD_children__ContextDFD> ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::ContextDFD > ChildrenKinds;
    typedef boost::mpl::vector< ::HFSM::ContextDFD, ::HFSM::Process, 
                                ::HFSM::DataFlow, ::HFSM::DataStore, 
                                ::HFSM::Entity> DescendantKinds;

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

	class DataFlow :  public MgaObject {
	public:
		typedef ::Udm::ConnectionMetaTag MetaKind;

		DataFlow() {}
		DataFlow(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		DataFlow(const DataFlow &master) : MgaObject(master) {}

		static DataFlow Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static DataFlow Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		DataFlow CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<DataFlow> Instances() { return Udm::InstantiatedAttr<DataFlow>(impl); }
		template <class Pred> Udm::InstantiatedAttr<DataFlow, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<DataFlow, Pred>(impl); }
		DataFlow CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<DataFlow> Derived() { return Udm::DerivedAttr<DataFlow>(impl); }
		template <class Pred> Udm::DerivedAttr<DataFlow, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<DataFlow, Pred>(impl); }
		Udm::ArchetypeAttr<DataFlow> Archetype() const { return Udm::ArchetypeAttr<DataFlow>(impl); }
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
		Udm::ParentAttr< ::HFSM::ContextDFD> ContextDFD_parent() const { return Udm::ParentAttr< ::HFSM::ContextDFD>(impl, meta_ContextDFD_parent); }
		Udm::ParentAttr< ::HFSM::Process> Process_parent() const { return Udm::ParentAttr< ::HFSM::Process>(impl, meta_Process_parent); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		Udm::AssocEndAttr< ::HFSM::Process> dstTransition_end() const { return Udm::AssocEndAttr< ::HFSM::Process>(impl, meta_dstTransition_end_); }
		Udm::AssocEndAttr< ::HFSM::Process> srcTransition_end() const { return Udm::AssocEndAttr< ::HFSM::Process>(impl, meta_srcTransition_end_); }
		void Accept(Visitor &v) const { v.Visit_DataFlow(*this); }
    using Udm::Object::Accept;

		static ::Uml::Class meta;
		static ::Uml::Attribute meta_Event;
		static ::Uml::CompositionParentRole meta_ContextDFD_parent;
		static ::Uml::CompositionParentRole meta_Process_parent;
		static ::Uml::AssociationRole meta_dstTransition_end_;
		static ::Uml::AssociationRole meta_srcTransition_end_;

		// types and typelist for parent by returned type and role relations;
		class PR_ContextDFD_parent {};
		class PR_Process_parent {};
		typedef boost::mpl::pair< ::HFSM::ContextDFD, PR_ContextDFD_parent > _PR_ContextDFD_parent__ContextDFD;
		typedef boost::mpl::pair< ::HFSM::Process, PR_Process_parent > _PR_Process_parent__Process;
		typedef boost::mpl::vector< _PR_ContextDFD_parent__ContextDFD, _PR_Process_parent__Process> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Process, ::HFSM::ContextDFD> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;
    typedef boost::mpl::vector< > DescendantKinds;


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
		typedef boost::mpl::pair< ::HFSM::Process, ACE_dstTransition > _ACE_dstTransition__Process;
		typedef boost::mpl::pair< ::HFSM::Process, ACE_srcTransition > _ACE_srcTransition__Process;
		typedef boost::mpl::vector< _ACE_dstTransition__Process, _ACE_srcTransition__Process> AClassEnds;

		// types and typelist for cross association class by returned type and role relations;
		typedef boost::mpl::vector< > CrossAClassEnds;

	};

	class DataStore :  public MgaObject {
	public:
		typedef ::Udm::AtomMetaTag MetaKind;

		DataStore() {}
		DataStore(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		DataStore(const DataStore &master) : MgaObject(master) {}

		static DataStore Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static DataStore Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		DataStore CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<DataStore> Instances() { return Udm::InstantiatedAttr<DataStore>(impl); }
		template <class Pred> Udm::InstantiatedAttr<DataStore, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<DataStore, Pred>(impl); }
		DataStore CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<DataStore> Derived() { return Udm::DerivedAttr<DataStore>(impl); }
		template <class Pred> Udm::DerivedAttr<DataStore, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<DataStore, Pred>(impl); }
		Udm::ArchetypeAttr<DataStore> Archetype() const { return Udm::ArchetypeAttr<DataStore>(impl); }
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
		Udm::ParentAttr< ::HFSM::Process> Process_parent() const { return Udm::ParentAttr< ::HFSM::Process>(impl, meta_Process_parent); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) const { v.Visit_DataStore(*this); }
    using Udm::Object::Accept;

		static ::Uml::Class meta;
		static ::Uml::CompositionParentRole meta_Process_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_Process_parent {};
		typedef boost::mpl::pair< ::HFSM::Process, PR_Process_parent > _PR_Process_parent__Process;
		typedef boost::mpl::vector< _PR_Process_parent__Process> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Process> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;
    typedef boost::mpl::vector< > DescendantKinds;

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

	class Process :  public MgaObject {
	public:
		typedef ::Udm::ModelMetaTag MetaKind;

		Process() {}
		Process(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		Process(const Process &master) : MgaObject(master) {}

		static Process Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static Process Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		Process CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<Process> Instances() { return Udm::InstantiatedAttr<Process>(impl); }
		template <class Pred> Udm::InstantiatedAttr<Process, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<Process, Pred>(impl); }
		Process CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<Process> Derived() { return Udm::DerivedAttr<Process>(impl); }
		template <class Pred> Udm::DerivedAttr<Process, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<Process, Pred>(impl); }
		Udm::ArchetypeAttr<Process> Archetype() const { return Udm::ArchetypeAttr<Process>(impl); }
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
		Udm::AClassAssocAttr< ::HFSM::DataFlow, ::HFSM::Process> srcTransition() const { return Udm::AClassAssocAttr< ::HFSM::DataFlow, ::HFSM::Process>(impl, meta_srcTransition, meta_srcTransition_rev); }
		template <class Pred> Udm::AClassAssocAttr< ::HFSM::DataFlow, ::HFSM::Process, Pred> srcTransition_sorted(const Pred &) const { return Udm::AClassAssocAttr< ::HFSM::DataFlow, ::HFSM::Process, Pred>(impl, meta_srcTransition, meta_srcTransition_rev); }
		Udm::AClassAssocAttr< ::HFSM::DataFlow, ::HFSM::Process> dstTransition() const { return Udm::AClassAssocAttr< ::HFSM::DataFlow, ::HFSM::Process>(impl, meta_dstTransition, meta_dstTransition_rev); }
		template <class Pred> Udm::AClassAssocAttr< ::HFSM::DataFlow, ::HFSM::Process, Pred> dstTransition_sorted(const Pred &) const { return Udm::AClassAssocAttr< ::HFSM::DataFlow, ::HFSM::Process, Pred>(impl, meta_dstTransition, meta_dstTransition_rev); }
		Udm::ChildrenAttr< ::HFSM::Entity> Entity_children() const { return Udm::ChildrenAttr< ::HFSM::Entity>(impl, meta_Entity_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Entity, Pred> Entity_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Entity, Pred>(impl, meta_Entity_children); }
		Udm::ChildrenAttr< ::HFSM::DataStore> DataStore_children() const { return Udm::ChildrenAttr< ::HFSM::DataStore>(impl, meta_DataStore_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::DataStore, Pred> DataStore_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::DataStore, Pred>(impl, meta_DataStore_children); }
		Udm::ChildrenAttr< ::HFSM::Process> Process_children() const { return Udm::ChildrenAttr< ::HFSM::Process>(impl, meta_Process_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Process, Pred> Process_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Process, Pred>(impl, meta_Process_children); }
		Udm::ChildrenAttr< ::HFSM::DataFlow> DataFlow_children() const { return Udm::ChildrenAttr< ::HFSM::DataFlow>(impl, meta_DataFlow_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::DataFlow, Pred> DataFlow_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::DataFlow, Pred>(impl, meta_DataFlow_children); }
		Udm::ChildrenAttr< ::HFSM::DataFlow> DataFlow_kind_children() const { return Udm::ChildrenAttr< ::HFSM::DataFlow>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::DataFlow, Pred> DataFlow_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::DataFlow, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::DataStore> DataStore_kind_children() const { return Udm::ChildrenAttr< ::HFSM::DataStore>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::DataStore, Pred> DataStore_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::DataStore, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::Process> Process_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Process>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Process, Pred> Process_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Process, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::Entity> Entity_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Entity>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Entity, Pred> Entity_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Entity, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::HFSM::Process> Process_parent() const { return Udm::ParentAttr< ::HFSM::Process>(impl, meta_Process_parent); }
		Udm::ParentAttr< ::HFSM::ContextDFD> ContextDFD_parent() const { return Udm::ParentAttr< ::HFSM::ContextDFD>(impl, meta_ContextDFD_parent); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) const { v.Visit_Process(*this); }
    using Udm::Object::Accept;

		static ::Uml::Class meta;
		static ::Uml::AssociationRole meta_srcTransition;
		static ::Uml::AssociationRole meta_srcTransition_rev;
		static ::Uml::AssociationRole meta_dstTransition;
		static ::Uml::AssociationRole meta_dstTransition_rev;
		static ::Uml::CompositionChildRole meta_Entity_children;
		static ::Uml::CompositionChildRole meta_DataStore_children;
		static ::Uml::CompositionChildRole meta_Process_children;
		static ::Uml::CompositionChildRole meta_DataFlow_children;
		static ::Uml::CompositionParentRole meta_Process_parent;
		static ::Uml::CompositionParentRole meta_ContextDFD_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_Process_parent {};
		class PR_ContextDFD_parent {};
		typedef boost::mpl::pair< ::HFSM::Process, PR_Process_parent > _PR_Process_parent__Process;
		typedef boost::mpl::pair< ::HFSM::ContextDFD, PR_ContextDFD_parent > _PR_ContextDFD_parent__ContextDFD;
		typedef boost::mpl::vector< _PR_Process_parent__Process, _PR_ContextDFD_parent__ContextDFD> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Process, ::HFSM::ContextDFD> ParentKinds;

		// types and typelist for children by returned type and role relations;
		class CR_Entity_children {};
		class CR_DataStore_children {};
		class CR_Process_children {};
		class CR_DataFlow_children {};
		typedef boost::mpl::pair< ::HFSM::Entity, CR_Entity_children > _CR_Entity_children__Entity;
		typedef boost::mpl::pair< ::HFSM::DataStore, CR_DataStore_children > _CR_DataStore_children__DataStore;
		typedef boost::mpl::pair< ::HFSM::Process, CR_Process_children > _CR_Process_children__Process;
		typedef boost::mpl::pair< ::HFSM::DataFlow, CR_DataFlow_children > _CR_DataFlow_children__DataFlow;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< _CR_Entity_children__Entity, _CR_DataStore_children__DataStore, _CR_Process_children__Process, _CR_DataFlow_children__DataFlow> ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::DataFlow, ::HFSM::DataStore, ::HFSM::Process, ::HFSM::Entity> ChildrenKinds;
    typedef boost::mpl::vector< ::HFSM::Process, ::HFSM::DataFlow, 
                                ::HFSM::DataStore, ::HFSM::Entity> DescendantKinds;


		// types and typelist for associations by returned type and role relations;
		typedef boost::mpl::vector< > AssociationsSingle;
		typedef boost::mpl::vector< > AssociationsMulti;

		// types and typelist for associations by returned type, association class and role relations;
		class AR_srcTransition {};
		class AR_dstTransition {};
		typedef boost::mpl::pair< ::HFSM::Process, boost::mpl::pair< ::HFSM::DataFlow, AR_srcTransition > > _AR_srcTransition__DataFlow__Process;
		typedef boost::mpl::pair< ::HFSM::Process, boost::mpl::pair< ::HFSM::DataFlow, AR_dstTransition > > _AR_dstTransition__DataFlow__Process;
		typedef boost::mpl::vector< > AssociationsWAClassSingle;
		typedef boost::mpl::vector< _AR_srcTransition__DataFlow__Process, _AR_dstTransition__DataFlow__Process> AssociationsWAClassMulti;

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

	class Entity :  public MgaObject {
	public:
		typedef ::Udm::AtomMetaTag MetaKind;

		Entity() {}
		Entity(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		Entity(const Entity &master) : MgaObject(master) {}

		static Entity Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static Entity Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		Entity CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<Entity> Instances() { return Udm::InstantiatedAttr<Entity>(impl); }
		template <class Pred> Udm::InstantiatedAttr<Entity, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<Entity, Pred>(impl); }
		Entity CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<Entity> Derived() { return Udm::DerivedAttr<Entity>(impl); }
		template <class Pred> Udm::DerivedAttr<Entity, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<Entity, Pred>(impl); }
		Udm::ArchetypeAttr<Entity> Archetype() const { return Udm::ArchetypeAttr<Entity>(impl); }
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
		Udm::ParentAttr< ::HFSM::Process> Process_parent() const { return Udm::ParentAttr< ::HFSM::Process>(impl, meta_Process_parent); }
		Udm::ParentAttr< ::HFSM::ContextDFD> ContextDFD_parent() const { return Udm::ParentAttr< ::HFSM::ContextDFD>(impl, meta_ContextDFD_parent); }
		Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) const { v.Visit_Entity(*this); }
    using Udm::Object::Accept;

		static ::Uml::Class meta;
		static ::Uml::CompositionParentRole meta_Process_parent;
		static ::Uml::CompositionParentRole meta_ContextDFD_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_Process_parent {};
		class PR_ContextDFD_parent {};
		typedef boost::mpl::pair< ::HFSM::Process, PR_Process_parent > _PR_Process_parent__Process;
		typedef boost::mpl::pair< ::HFSM::ContextDFD, PR_ContextDFD_parent > _PR_ContextDFD_parent__ContextDFD;
		typedef boost::mpl::vector< _PR_Process_parent__Process, _PR_ContextDFD_parent__ContextDFD> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::Process, ::HFSM::ContextDFD> ParentKinds;

		// types and typelist for children by returned type and role relations;
		typedef boost::mpl::vector< > ChildrenSingle;
		typedef boost::mpl::vector< > ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< > ChildrenKinds;
    typedef boost::mpl::vector< > DescendantKinds;


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

	class ContextDFD :  public MgaObject {
	public:
		typedef ::Udm::ModelMetaTag MetaKind;

		ContextDFD() {}
		ContextDFD(Udm::ObjectImpl *impl) : MgaObject(impl) {}
		ContextDFD(const ContextDFD &master) : MgaObject(master) {}

		static ContextDFD Cast(const Udm::Object &a) { return __Cast(a, meta); }
		static ContextDFD Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }
		ContextDFD CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::InstantiatedAttr<ContextDFD> Instances() { return Udm::InstantiatedAttr<ContextDFD>(impl); }
		template <class Pred> Udm::InstantiatedAttr<ContextDFD, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<ContextDFD, Pred>(impl); }
		ContextDFD CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }
		Udm::DerivedAttr<ContextDFD> Derived() { return Udm::DerivedAttr<ContextDFD>(impl); }
		template <class Pred> Udm::DerivedAttr<ContextDFD, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<ContextDFD, Pred>(impl); }
		Udm::ArchetypeAttr<ContextDFD> Archetype() const { return Udm::ArchetypeAttr<ContextDFD>(impl); }
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
		Udm::ChildrenAttr< ::HFSM::DataFlow> DataFlow_children() const { return Udm::ChildrenAttr< ::HFSM::DataFlow>(impl, meta_DataFlow_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::DataFlow, Pred> DataFlow_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::DataFlow, Pred>(impl, meta_DataFlow_children); }
		Udm::ChildAttr< ::HFSM::Process> Process_child() const { return Udm::ChildAttr< ::HFSM::Process>(impl, meta_Process_child); }
		Udm::ChildrenAttr< ::HFSM::Entity> Entity_children() const { return Udm::ChildrenAttr< ::HFSM::Entity>(impl, meta_Entity_children); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Entity, Pred> Entity_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Entity, Pred>(impl, meta_Entity_children); }
		Udm::ChildrenAttr< ::HFSM::DataFlow> DataFlow_kind_children() const { return Udm::ChildrenAttr< ::HFSM::DataFlow>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::DataFlow, Pred> DataFlow_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::DataFlow, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::Process> Process_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Process>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Process, Pred> Process_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Process, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::Entity> Entity_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Entity>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::Entity, Pred> Entity_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Entity, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template <class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }
		Udm::ParentAttr< ::HFSM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_parent); }
		Udm::ParentAttr< ::HFSM::RootFolder> parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		void Accept(Visitor &v) const { v.Visit_ContextDFD(*this); }
    using Udm::Object::Accept;

		static ::Uml::Class meta;
		static ::Uml::CompositionChildRole meta_DataFlow_children;
		static ::Uml::CompositionChildRole meta_Process_child;
		static ::Uml::CompositionChildRole meta_Entity_children;
		static ::Uml::CompositionParentRole meta_RootFolder_parent;

		// types and typelist for parent by returned type and role relations;
		class PR_RootFolder_parent {};
		typedef boost::mpl::pair< ::HFSM::RootFolder, PR_RootFolder_parent > _PR_RootFolder_parent__RootFolder;
		typedef boost::mpl::vector< _PR_RootFolder_parent__RootFolder> Parents;

		// typelist for parent by returned type relations;
		typedef boost::mpl::vector< ::HFSM::RootFolder> ParentKinds;

		// types and typelist for children by returned type and role relations;
		class CR_DataFlow_children {};
		class CR_Process_child {};
		class CR_Entity_children {};
		typedef boost::mpl::pair< ::HFSM::DataFlow, CR_DataFlow_children > _CR_DataFlow_children__DataFlow;
		typedef boost::mpl::pair< ::HFSM::Process, CR_Process_child > _CR_Process_child__Process;
		typedef boost::mpl::pair< ::HFSM::Entity, CR_Entity_children > _CR_Entity_children__Entity;
		typedef boost::mpl::vector< _CR_Process_child__Process> ChildrenSingle;
		typedef boost::mpl::vector< _CR_DataFlow_children__DataFlow, _CR_Entity_children__Entity> ChildrenMulti;

		// typelist for children by returned type relations;
		typedef boost::mpl::vector< ::HFSM::DataFlow, ::HFSM::Process, ::HFSM::Entity> ChildrenKinds;
    typedef boost::mpl::vector< ::HFSM::Process, ::HFSM::DataFlow, 
                                ::HFSM::DataStore, ::HFSM::Entity> DescendantKinds;


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
