#ifndef MOBIES_HFSM_H
#define MOBIES_HFSM_H
// header file HFSM.h generated from diagram HFSM
// generated on Thu May 29 18:22:43 2008

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#define ENABLE_BOOST_MPL

#ifdef ENABLE_BOOST_MPL
	#include <boost/mpl/vector.hpp>
	#include <boost/mpl/contains.hpp>
    #include <boost/mpl/assert.hpp>
	#include <boost/mpl/deref.hpp>
	#include <boost/concept_check.hpp>
#endif // ENABLE_BOOST_MPL

#ifdef ENABLE_BOOST_MPL 
namespace Udm {
template <class ParentKind, class ChildKind>
struct ParentOfChildN {
	typedef typename ParentKind::ChildrenKinds ChildrenKinds;
	void constraints()
	{
		BOOST_MPL_ASSERT((boost::mpl::contains<ChildrenKinds, ChildKind > ));
	}
};

struct ModelMetaTag {};
struct AtomMetaTag {};
struct ConnectionMetaTag {};
struct ReferenceMetaTag {};
struct SetMetaTag {};

}
#endif // ENABLE_BOOST_MPL

namespace HFSM {
	extern  Udm::UdmDiagram diagram;
	 void Initialize(const ::Uml::Diagram &dgr);
	 void Initialize();

		class  InputSequence;
		class  Events;
		class  Sequence;
		class  State;
		class  Transition;
		class  RootFolder;
		class  MgaObject;


		class  Visitor : public Udm::BaseVisitor 
		{
		public:
			virtual void Visit_InputSequence(const InputSequence&){};
			virtual void Visit_Events(const Events&){};
			virtual void Visit_Sequence(const Sequence&){};
			virtual void Visit_State(const State&){};
			virtual void Visit_Transition(const Transition&){};
			virtual void Visit_RootFolder(const RootFolder&){};
			virtual void Visit_Object(const Udm::Object&){};
			virtual ~Visitor(){};
		};
		 void CreateMetaObjs();
		 void InitCrossNSInheritence();
		 void InitCrossNSCompositions();
		class  RootFolder :  public Udm::Object {
		public:

#ifdef ENABLE_BOOST_MPL
			typedef boost::mpl::vector<InputSequence, State> ChildrenKinds;
			typedef boost::mpl::vector<> ParentKind;
			typedef RootFolder Self;
			typedef Udm::ModelMetaTag MetaKind;

			template <class	ChildKind>
			Udm::ChildrenAttr<ChildKind> 
			kind_children() const 
			{ 
				boost::function_requires <Udm::ParentOfChildN<Self, ChildKind> > ();
				return Udm::ChildrenAttr<ChildKind>(impl, Udm::NULLCHILDROLE); 
			}
#endif // ENABLE_BOOST_MPL

			static ::Uml::Class meta;

			RootFolder() { }
			RootFolder(Udm::ObjectImpl *impl) : UDM_OBJECT(impl) { }
			RootFolder(const RootFolder &master) : UDM_OBJECT(master) { }
			static RootFolder Cast(const Udm::Object &a) { return __Cast(a, meta); }

			static RootFolder Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

			RootFolder CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

			RootFolder CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

			Udm::InstantiatedAttr< ::HFSM::RootFolder> Instances() { return Udm::InstantiatedAttr< ::HFSM::RootFolder>(impl);}
			template <class Pred> Udm::InstantiatedAttr< ::HFSM::RootFolder, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr< ::HFSM::RootFolder, Pred>(impl);}

			Udm::DerivedAttr< ::HFSM::RootFolder> Derived() { return Udm::DerivedAttr< ::HFSM::RootFolder>(impl);}
			template <class Pred> Udm::DerivedAttr< ::HFSM::RootFolder, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr< ::HFSM::RootFolder, Pred>(impl);}

			Udm::ArchetypeAttr< ::HFSM::RootFolder> Archetype() { return Udm::ArchetypeAttr< ::HFSM::RootFolder>(impl);}

			static ::Uml::Attribute meta_name;
			Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

			static ::Uml::CompositionChildRole meta_State_children;
			Udm::ChildrenAttr< ::HFSM::State> State_children() const { return Udm::ChildrenAttr< ::HFSM::State>(impl, meta_State_children); }
			template <class Pred> Udm::ChildrenAttr< ::HFSM::State, Pred> State_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::State, Pred>(impl, meta_State_children); }

			static ::Uml::CompositionChildRole meta_InputSequence_children;
			Udm::ChildrenAttr< ::HFSM::InputSequence> InputSequence_children() const { return Udm::ChildrenAttr< ::HFSM::InputSequence>(impl, meta_InputSequence_children); }
			template <class Pred> Udm::ChildrenAttr< ::HFSM::InputSequence, Pred> InputSequence_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::InputSequence, Pred>(impl, meta_InputSequence_children); }

			static ::Uml::CompositionChildRole meta_RootFolder_children;
			Udm::ChildrenAttr< ::HFSM::RootFolder> RootFolder_children() const { return Udm::ChildrenAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_children); }
			template <class Pred> Udm::ChildrenAttr< ::HFSM::RootFolder, Pred> RootFolder_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::RootFolder, Pred>(impl, meta_RootFolder_children); }

			Udm::ChildrenAttr< ::HFSM::InputSequence> InputSequence_kind_children() const { return Udm::ChildrenAttr< ::HFSM::InputSequence>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::InputSequence, Pred> InputSequence_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::InputSequence, Pred>(impl, Udm::NULLCHILDROLE); }

			Udm::ChildrenAttr< ::HFSM::State> State_kind_children() const { return Udm::ChildrenAttr< ::HFSM::State>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::State, Pred> State_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::State, Pred>(impl, Udm::NULLCHILDROLE); }

			Udm::ChildrenAttr< ::HFSM::RootFolder> RootFolder_kind_children() const { return Udm::ChildrenAttr< ::HFSM::RootFolder>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::RootFolder, Pred> RootFolder_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::RootFolder, Pred>(impl, Udm::NULLCHILDROLE); }

			Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

			static ::Uml::CompositionParentRole meta_RootFolder_parent;
			Udm::ParentAttr< ::HFSM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_parent); }

			Udm::ParentAttr< ::HFSM::RootFolder> parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		};

		class  MgaObject :  public Udm::Object {
		public:
			static ::Uml::Class meta;

			MgaObject() { }
			MgaObject(Udm::ObjectImpl *impl) : UDM_OBJECT(impl) { }
			MgaObject(const MgaObject &master) : UDM_OBJECT(master) { }
			static MgaObject Cast(const Udm::Object &a) { return __Cast(a, meta); }

			static MgaObject Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

			MgaObject CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

			MgaObject CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

			Udm::InstantiatedAttr< ::HFSM::MgaObject> Instances() { return Udm::InstantiatedAttr< ::HFSM::MgaObject>(impl);}
			template <class Pred> Udm::InstantiatedAttr< ::HFSM::MgaObject, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr< ::HFSM::MgaObject, Pred>(impl);}

			Udm::DerivedAttr< ::HFSM::MgaObject> Derived() { return Udm::DerivedAttr< ::HFSM::MgaObject>(impl);}
			template <class Pred> Udm::DerivedAttr< ::HFSM::MgaObject, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr< ::HFSM::MgaObject, Pred>(impl);}

			Udm::ArchetypeAttr< ::HFSM::MgaObject> Archetype() { return Udm::ArchetypeAttr< ::HFSM::MgaObject>(impl);}

			static ::Uml::Attribute meta_position;
			Udm::StringAttr position() const { return Udm::StringAttr(impl, meta_position); }

			static ::Uml::Attribute meta_name;
			Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

			Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
		};

		class  InputSequence :  public ::HFSM::MgaObject {
		public:

#ifdef ENABLE_BOOST_MPL
			typedef boost::mpl::vector<Events, Sequence> ChildrenKinds;
			typedef boost::mpl::vector<RootFolder> ParentKind;
			typedef InputSequence Self;
			typedef Udm::ModelMetaTag MetaKind;

			template <class	ChildKind>
			Udm::ChildrenAttr<ChildKind> 
			kind_children() const 
			{ 
				boost::function_requires <Udm::ParentOfChildN<Self, ChildKind> > ();
				return Udm::ChildrenAttr<ChildKind>(impl, Udm::NULLCHILDROLE); 
			}
#endif // ENABLE_BOOST_MPL

			static ::Uml::Class meta;

			InputSequence() { }
			InputSequence(Udm::ObjectImpl *impl) : ::HFSM::MgaObject(impl) { }
			InputSequence(const InputSequence &master) : ::HFSM::MgaObject(master) { }
			static InputSequence Cast(const Udm::Object &a) { return __Cast(a, meta); }

			static InputSequence Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

			InputSequence CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

			InputSequence CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

			Udm::InstantiatedAttr< ::HFSM::InputSequence> Instances() { return Udm::InstantiatedAttr< ::HFSM::InputSequence>(impl);}
			template <class Pred> Udm::InstantiatedAttr< ::HFSM::InputSequence, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr< ::HFSM::InputSequence, Pred>(impl);}

			Udm::DerivedAttr< ::HFSM::InputSequence> Derived() { return Udm::DerivedAttr< ::HFSM::InputSequence>(impl);}
			template <class Pred> Udm::DerivedAttr< ::HFSM::InputSequence, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr< ::HFSM::InputSequence, Pred>(impl);}

			Udm::ArchetypeAttr< ::HFSM::InputSequence> Archetype() { return Udm::ArchetypeAttr< ::HFSM::InputSequence>(impl);}

			static ::Uml::CompositionChildRole meta_Events_children;
			Udm::ChildrenAttr< ::HFSM::Events> Events_children() const { return Udm::ChildrenAttr< ::HFSM::Events>(impl, meta_Events_children); }
			template <class Pred> Udm::ChildrenAttr< ::HFSM::Events, Pred> Events_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Events, Pred>(impl, meta_Events_children); }

			static ::Uml::CompositionChildRole meta_Sequence_children;
			Udm::ChildrenAttr< ::HFSM::Sequence> Sequence_children() const { return Udm::ChildrenAttr< ::HFSM::Sequence>(impl, meta_Sequence_children); }
			template <class Pred> Udm::ChildrenAttr< ::HFSM::Sequence, Pred> Sequence_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Sequence, Pred>(impl, meta_Sequence_children); }

			Udm::ChildrenAttr< ::HFSM::Events> Events_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Events>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::Events, Pred> Events_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Events, Pred>(impl, Udm::NULLCHILDROLE); }

			Udm::ChildrenAttr< ::HFSM::Sequence> Sequence_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Sequence>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::Sequence, Pred> Sequence_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Sequence, Pred>(impl, Udm::NULLCHILDROLE); }

			Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

			static ::Uml::CompositionParentRole meta_RootFolder_parent;
			Udm::ParentAttr< ::HFSM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_parent); }

			Udm::ParentAttr< ::HFSM::RootFolder> parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, Udm::NULLPARENTROLE); }
		};

		class  Events :  public ::HFSM::MgaObject {
		public:

#ifdef ENABLE_BOOST_MPL
			typedef boost::mpl::vector<> ChildrenKinds;
			typedef boost::mpl::vector<InputSequence> ParentKind;
			typedef Events Self;
			typedef Udm::AtomMetaTag MetaKind;
#endif // ENABLE_BOOST_MPL

			static ::Uml::Class meta;

			Events() { }
			Events(Udm::ObjectImpl *impl) : ::HFSM::MgaObject(impl) { }
			Events(const Events &master) : ::HFSM::MgaObject(master) { }
			static Events Cast(const Udm::Object &a) { return __Cast(a, meta); }

			static Events Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

			Events CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

			Events CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

			Udm::InstantiatedAttr< ::HFSM::Events> Instances() { return Udm::InstantiatedAttr< ::HFSM::Events>(impl);}
			template <class Pred> Udm::InstantiatedAttr< ::HFSM::Events, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr< ::HFSM::Events, Pred>(impl);}

			Udm::DerivedAttr< ::HFSM::Events> Derived() { return Udm::DerivedAttr< ::HFSM::Events>(impl);}
			template <class Pred> Udm::DerivedAttr< ::HFSM::Events, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr< ::HFSM::Events, Pred>(impl);}

			Udm::ArchetypeAttr< ::HFSM::Events> Archetype() { return Udm::ArchetypeAttr< ::HFSM::Events>(impl);}

			static ::Uml::Attribute meta_Delay;
			Udm::IntegerAttr Delay() const { return Udm::IntegerAttr(impl, meta_Delay); }

			static ::Uml::AssociationRole meta_srcSequence;
			static ::Uml::AssociationRole meta_srcSequence_rev;
			Udm::AClassPointerAttr< ::HFSM::Sequence, ::HFSM::Events> srcSequence() const { return Udm::AClassPointerAttr< ::HFSM::Sequence, ::HFSM::Events>(impl, meta_srcSequence, meta_srcSequence_rev); }

			static ::Uml::AssociationRole meta_dstSequence;
			static ::Uml::AssociationRole meta_dstSequence_rev;
			Udm::AClassPointerAttr< ::HFSM::Sequence, ::HFSM::Events> dstSequence() const { return Udm::AClassPointerAttr< ::HFSM::Sequence, ::HFSM::Events>(impl, meta_dstSequence, meta_dstSequence_rev); }

			static ::Uml::CompositionParentRole meta_InputSequence_parent;
			Udm::ParentAttr< ::HFSM::InputSequence> InputSequence_parent() const { return Udm::ParentAttr< ::HFSM::InputSequence>(impl, meta_InputSequence_parent); }

			Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
		};

		class  Sequence :  public ::HFSM::MgaObject {
		public:

#ifdef ENABLE_BOOST_MPL
			typedef boost::mpl::vector<InputSequence> ParentKind;
			typedef boost::mpl::vector<> ChildrenKinds;
			typedef Sequence Self;
			typedef Udm::ConnectionMetaTag MetaKind;
#endif // #ifdef ENABLE_BOOST_MPL

			static ::Uml::Class meta;

			Sequence() { }
			Sequence(Udm::ObjectImpl *impl) : ::HFSM::MgaObject(impl) { }
			Sequence(const Sequence &master) : ::HFSM::MgaObject(master) { }
			static Sequence Cast(const Udm::Object &a) { return __Cast(a, meta); }

			static Sequence Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

			Sequence CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

			Sequence CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

			Udm::InstantiatedAttr< ::HFSM::Sequence> Instances() { return Udm::InstantiatedAttr< ::HFSM::Sequence>(impl);}
			template <class Pred> Udm::InstantiatedAttr< ::HFSM::Sequence, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr< ::HFSM::Sequence, Pred>(impl);}

			Udm::DerivedAttr< ::HFSM::Sequence> Derived() { return Udm::DerivedAttr< ::HFSM::Sequence>(impl);}
			template <class Pred> Udm::DerivedAttr< ::HFSM::Sequence, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr< ::HFSM::Sequence, Pred>(impl);}

			Udm::ArchetypeAttr< ::HFSM::Sequence> Archetype() { return Udm::ArchetypeAttr< ::HFSM::Sequence>(impl);}

			static ::Uml::CompositionParentRole meta_InputSequence_parent;
			Udm::ParentAttr< ::HFSM::InputSequence> InputSequence_parent() const { return Udm::ParentAttr< ::HFSM::InputSequence>(impl, meta_InputSequence_parent); }

			Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
			static ::Uml::AssociationRole meta_dstSequence_end_;
			Udm::AssocEndAttr< ::HFSM::Events> dstSequence_end() const { return Udm::AssocEndAttr< ::HFSM::Events>(impl, meta_dstSequence_end_); }

			static ::Uml::AssociationRole meta_srcSequence_end_;
			Udm::AssocEndAttr< ::HFSM::Events> srcSequence_end() const { return Udm::AssocEndAttr< ::HFSM::Events>(impl, meta_srcSequence_end_); }

		};

		class  State :  public ::HFSM::MgaObject {
		public:

#ifdef ENABLE_BOOST_MPL
			typedef boost::mpl::vector<State> ChildrenKinds;
			typedef boost::mpl::vector<State> ParentKind;
			typedef State Self;
			typedef Udm::ModelMetaTag MetaKind;
#endif // #ifdef ENABLE_BOOST_MPL

			static ::Uml::Class meta;

			State() { }
			State(Udm::ObjectImpl *impl) : ::HFSM::MgaObject(impl) { }
			State(const State &master) : ::HFSM::MgaObject(master) { }
			static State Cast(const Udm::Object &a) { return __Cast(a, meta); }

			static State Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

			State CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

			State CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

			Udm::InstantiatedAttr< ::HFSM::State> Instances() { return Udm::InstantiatedAttr< ::HFSM::State>(impl);}
			template <class Pred> Udm::InstantiatedAttr< ::HFSM::State, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr< ::HFSM::State, Pred>(impl);}

			Udm::DerivedAttr< ::HFSM::State> Derived() { return Udm::DerivedAttr< ::HFSM::State>(impl);}
			template <class Pred> Udm::DerivedAttr< ::HFSM::State, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr< ::HFSM::State, Pred>(impl);}

			Udm::ArchetypeAttr< ::HFSM::State> Archetype() { return Udm::ArchetypeAttr< ::HFSM::State>(impl);}

			static ::Uml::Attribute meta_StartState;
			Udm::BooleanAttr StartState() const { return Udm::BooleanAttr(impl, meta_StartState); }

			static ::Uml::AssociationRole meta_srcTransition;
			static ::Uml::AssociationRole meta_srcTransition_rev;
			Udm::AClassPointerAttr< ::HFSM::Transition, ::HFSM::State> srcTransition() const { return Udm::AClassPointerAttr< ::HFSM::Transition, ::HFSM::State>(impl, meta_srcTransition, meta_srcTransition_rev); }

			static ::Uml::AssociationRole meta_dstTransition;
			static ::Uml::AssociationRole meta_dstTransition_rev;
			Udm::AClassPointerAttr< ::HFSM::Transition, ::HFSM::State> dstTransition() const { return Udm::AClassPointerAttr< ::HFSM::Transition, ::HFSM::State>(impl, meta_dstTransition, meta_dstTransition_rev); }

			static ::Uml::CompositionChildRole meta_State_child;
			Udm::ChildAttr< ::HFSM::State> State_child() const { return Udm::ChildAttr< ::HFSM::State>(impl, meta_State_child); }

			static ::Uml::CompositionChildRole meta_Transition_child;
			Udm::ChildAttr< ::HFSM::Transition> Transition_child() const { return Udm::ChildAttr< ::HFSM::Transition>(impl, meta_Transition_child); }

			Udm::ChildrenAttr< ::HFSM::State> State_kind_children() const { return Udm::ChildrenAttr< ::HFSM::State>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::State, Pred> State_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::State, Pred>(impl, Udm::NULLCHILDROLE); }

			Udm::ChildrenAttr< ::HFSM::Transition> Transition_kind_children() const { return Udm::ChildrenAttr< ::HFSM::Transition>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::Transition, Pred> Transition_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::Transition, Pred>(impl, Udm::NULLCHILDROLE); }

			Udm::ChildrenAttr< ::HFSM::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr< ::HFSM::MgaObject>(impl, Udm::NULLCHILDROLE); }
			template<class Pred> Udm::ChildrenAttr< ::HFSM::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr< ::HFSM::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

			static ::Uml::CompositionParentRole meta_State_parent;
			Udm::ParentAttr< ::HFSM::State> State_parent() const { return Udm::ParentAttr< ::HFSM::State>(impl, meta_State_parent); }

			static ::Uml::CompositionParentRole meta_RootFolder_parent;
			Udm::ParentAttr< ::HFSM::RootFolder> RootFolder_parent() const { return Udm::ParentAttr< ::HFSM::RootFolder>(impl, meta_RootFolder_parent); }

			Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
		};

		class  Transition :  public ::HFSM::MgaObject {
		public:

#ifdef ENABLE_BOOST_MPL
			typedef boost::mpl::vector<> ChildrenKinds;
			typedef boost::mpl::vector<State> ParentKind;
			typedef Transition Self;
			typedef Udm::ConnectionMetaTag MetaKind;
#endif // #ifdef ENABLE_BOOST_MPL

			static ::Uml::Class meta;

			Transition() { }
			Transition(Udm::ObjectImpl *impl) : ::HFSM::MgaObject(impl) { }
			Transition(const Transition &master) : ::HFSM::MgaObject(master) { }
			static Transition Cast(const Udm::Object &a) { return __Cast(a, meta); }

			static Transition Create(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

			Transition CreateInstance(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

			Transition CreateDerived(const Udm::Object &parent, const ::Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

			Udm::InstantiatedAttr< ::HFSM::Transition> Instances() { return Udm::InstantiatedAttr< ::HFSM::Transition>(impl);}
			template <class Pred> Udm::InstantiatedAttr< ::HFSM::Transition, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr< ::HFSM::Transition, Pred>(impl);}

			Udm::DerivedAttr< ::HFSM::Transition> Derived() { return Udm::DerivedAttr< ::HFSM::Transition>(impl);}
			template <class Pred> Udm::DerivedAttr< ::HFSM::Transition, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr< ::HFSM::Transition, Pred>(impl);}

			Udm::ArchetypeAttr< ::HFSM::Transition> Archetype() { return Udm::ArchetypeAttr< ::HFSM::Transition>(impl);}

			static ::Uml::Attribute meta_Event;
			Udm::StringAttr Event() const { return Udm::StringAttr(impl, meta_Event); }

			static ::Uml::CompositionParentRole meta_State_parent;
			Udm::ParentAttr< ::HFSM::State> State_parent() const { return Udm::ParentAttr< ::HFSM::State>(impl, meta_State_parent); }

			Udm::ParentAttr< ::HFSM::MgaObject> parent() const { return Udm::ParentAttr< ::HFSM::MgaObject>(impl, Udm::NULLPARENTROLE); }
			static ::Uml::AssociationRole meta_dstTransition_end_;
			Udm::AssocEndAttr< ::HFSM::State> dstTransition_end() const { return Udm::AssocEndAttr< ::HFSM::State>(impl, meta_dstTransition_end_); }

			static ::Uml::AssociationRole meta_srcTransition_end_;
			Udm::AssocEndAttr< ::HFSM::State> srcTransition_end() const { return Udm::AssocEndAttr< ::HFSM::State>(impl, meta_srcTransition_end_); }

		};



}

#endif //MOBIES_HFSM_H
