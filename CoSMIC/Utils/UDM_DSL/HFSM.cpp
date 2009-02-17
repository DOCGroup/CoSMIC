// cpp (meta datanetwork format) source file HFSM.cpp
// generated from diagram HFSM
// generated on Fri Feb 06 18:54:28 2009

#include "HFSM.h"
#include <UmlExt.h>
#include <UdmStatic.h>


namespace HFSM {

	::Uml::Class DataFlow::meta;
	::Uml::Attribute DataFlow::meta_Event;
	::Uml::CompositionParentRole DataFlow::meta_ContextDFD_parent;
	::Uml::CompositionParentRole DataFlow::meta_Process_parent;
	::Uml::AssociationRole DataFlow::meta_dstTransition_end_;
	::Uml::AssociationRole DataFlow::meta_srcTransition_end_;

	template <> const ::Uml::CompositionParentRole& DataFlow::_type2CPRole< DataFlow::PR_ContextDFD_parent >() const { return meta_ContextDFD_parent; }
	template <> const ::Uml::CompositionParentRole& DataFlow::_type2CPRole< DataFlow::PR_Process_parent >() const { return meta_Process_parent; }
	template <> const ::Uml::AssociationRole& DataFlow::_type2ARole< DataFlow::ACE_dstTransition >() const { return meta_dstTransition_end_; }
	template <> const ::Uml::AssociationRole& DataFlow::_type2ARole< DataFlow::ACE_srcTransition >() const { return meta_srcTransition_end_; }

	::Uml::Class DataStore::meta;
	::Uml::CompositionParentRole DataStore::meta_Process_parent;

	template <> const ::Uml::CompositionParentRole& DataStore::_type2CPRole< DataStore::PR_Process_parent >() const { return meta_Process_parent; }

	::Uml::Class Process::meta;
	::Uml::AssociationRole Process::meta_srcTransition;
	::Uml::AssociationRole Process::meta_srcTransition_rev;
	::Uml::AssociationRole Process::meta_dstTransition;
	::Uml::AssociationRole Process::meta_dstTransition_rev;
	::Uml::CompositionChildRole Process::meta_Entity_children;
	::Uml::CompositionChildRole Process::meta_DataStore_children;
	::Uml::CompositionChildRole Process::meta_Process_children;
	::Uml::CompositionChildRole Process::meta_DataFlow_children;
	::Uml::CompositionParentRole Process::meta_Process_parent;
	::Uml::CompositionParentRole Process::meta_ContextDFD_parent;

	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Process::_type2ACARole< Process::AR_srcTransition >() const { return make_pair(&meta_srcTransition, &meta_srcTransition_rev); }
	template <> const pair<const ::Uml::AssociationRole*, const ::Uml::AssociationRole*> Process::_type2ACARole< Process::AR_dstTransition >() const { return make_pair(&meta_dstTransition, &meta_dstTransition_rev); }
	template <> const ::Uml::CompositionChildRole& Process::_type2CCRole< Process::CR_Entity_children >() const { return meta_Entity_children; }
	template <> const ::Uml::CompositionChildRole& Process::_type2CCRole< Process::CR_DataStore_children >() const { return meta_DataStore_children; }
	template <> const ::Uml::CompositionChildRole& Process::_type2CCRole< Process::CR_Process_children >() const { return meta_Process_children; }
	template <> const ::Uml::CompositionChildRole& Process::_type2CCRole< Process::CR_DataFlow_children >() const { return meta_DataFlow_children; }
	template <> const ::Uml::CompositionParentRole& Process::_type2CPRole< Process::PR_Process_parent >() const { return meta_Process_parent; }
	template <> const ::Uml::CompositionParentRole& Process::_type2CPRole< Process::PR_ContextDFD_parent >() const { return meta_ContextDFD_parent; }

	::Uml::Class Entity::meta;
	::Uml::CompositionParentRole Entity::meta_Process_parent;
	::Uml::CompositionParentRole Entity::meta_ContextDFD_parent;

	template <> const ::Uml::CompositionParentRole& Entity::_type2CPRole< Entity::PR_Process_parent >() const { return meta_Process_parent; }
	template <> const ::Uml::CompositionParentRole& Entity::_type2CPRole< Entity::PR_ContextDFD_parent >() const { return meta_ContextDFD_parent; }

	::Uml::Class ContextDFD::meta;
	::Uml::CompositionChildRole ContextDFD::meta_DataFlow_children;
	::Uml::CompositionChildRole ContextDFD::meta_Process_child;
	::Uml::CompositionChildRole ContextDFD::meta_Entity_children;
	::Uml::CompositionParentRole ContextDFD::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& ContextDFD::_type2CCRole< ContextDFD::CR_DataFlow_children >() const { return meta_DataFlow_children; }
	template <> const ::Uml::CompositionChildRole& ContextDFD::_type2CCRole< ContextDFD::CR_Process_child >() const { return meta_Process_child; }
	template <> const ::Uml::CompositionChildRole& ContextDFD::_type2CCRole< ContextDFD::CR_Entity_children >() const { return meta_Entity_children; }
	template <> const ::Uml::CompositionParentRole& ContextDFD::_type2CPRole< ContextDFD::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class RootFolder::meta;
	::Uml::Attribute RootFolder::meta_name;
	::Uml::CompositionChildRole RootFolder::meta_RootFolder_children;
	::Uml::CompositionChildRole RootFolder::meta_ContextDFD_children;
	::Uml::CompositionParentRole RootFolder::meta_RootFolder_parent;

	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_RootFolder_children >() const { return meta_RootFolder_children; }
	template <> const ::Uml::CompositionChildRole& RootFolder::_type2CCRole< RootFolder::CR_ContextDFD_children >() const { return meta_ContextDFD_children; }
	template <> const ::Uml::CompositionParentRole& RootFolder::_type2CPRole< RootFolder::PR_RootFolder_parent >() const { return meta_RootFolder_parent; }

	::Uml::Class MgaObject::meta;
	::Uml::Attribute MgaObject::meta_position;
	::Uml::Attribute MgaObject::meta_name;

	::Uml::Diagram meta;

	void CreateMeta() {
		// classes, with attributes, constraints and constraint definitions
		ContextDFD::meta = ::Uml::Class::Create(meta);

		DataFlow::meta = ::Uml::Class::Create(meta);
		DataFlow::meta_Event = ::Uml::Attribute::Create(DataFlow::meta);

		DataStore::meta = ::Uml::Class::Create(meta);

		Entity::meta = ::Uml::Class::Create(meta);

		MgaObject::meta = ::Uml::Class::Create(meta);
		MgaObject::meta_position = ::Uml::Attribute::Create(MgaObject::meta);
		MgaObject::meta_name = ::Uml::Attribute::Create(MgaObject::meta);

		Process::meta = ::Uml::Class::Create(meta);

		RootFolder::meta = ::Uml::Class::Create(meta);
		RootFolder::meta_name = ::Uml::Attribute::Create(RootFolder::meta);

	}

	void InitMeta() {
		// classes, with attributes, constraints and constraint definitions
		::Uml::InitClassProps(ContextDFD::meta, "ContextDFD", false, "Model", NULL);

		::Uml::InitClassProps(DataFlow::meta, "DataFlow", false, "Connection", NULL);
		::Uml::InitAttributeProps(DataFlow::meta_Event, "Event", "String", false, false, 1, 1, false, "public", vector<string>());

		::Uml::InitClassProps(DataStore::meta, "DataStore", false, "Atom", NULL);

		::Uml::InitClassProps(Entity::meta, "Entity", false, "Atom", NULL);

		::Uml::InitClassProps(MgaObject::meta, "MgaObject", true, NULL, NULL);
		::Uml::InitAttributeProps(MgaObject::meta_position, "position", "String", false, false, 0, 1, false, "public", vector<string>());
		::Uml::InitAttributeProps(MgaObject::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		::Uml::InitClassProps(Process::meta, "Process", false, "Model", NULL);

		::Uml::InitClassProps(RootFolder::meta, "RootFolder", false, "Folder", NULL);
		::Uml::InitAttributeProps(RootFolder::meta_name, "name", "String", false, false, 0, 1, false, "public", vector<string>());

		// associations
		{
			::Uml::Association ass = ::Uml::Association::Create(meta);
			::Uml::InitAssociationProps(ass, "DataFlow");
			Process::meta_srcTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Process::meta_srcTransition, "srcTransition", true, false, 0, -1);
			Process::meta_dstTransition = ::Uml::AssociationRole::Create(ass);
			::Uml::InitAssociationRoleProps(Process::meta_dstTransition, "dstTransition", true, false, 0, -1);

		}

		// compositions
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Entity::meta_Process_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Entity::meta_Process_parent, "Process_parent", true);
			Process::meta_Entity_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Process::meta_Entity_children, "Entity", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DataStore::meta_Process_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DataStore::meta_Process_parent, "Process_parent", true);
			Process::meta_DataStore_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Process::meta_DataStore_children, "DataStore", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Process::meta_Process_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Process::meta_Process_parent, "Process_parent", true);
			Process::meta_Process_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Process::meta_Process_children, "Process", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DataFlow::meta_Process_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DataFlow::meta_Process_parent, "Process_parent", true);
			Process::meta_DataFlow_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(Process::meta_DataFlow_children, "DataFlow", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			DataFlow::meta_ContextDFD_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(DataFlow::meta_ContextDFD_parent, "ContextDFD_parent", true);
			ContextDFD::meta_DataFlow_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ContextDFD::meta_DataFlow_children, "DataFlow", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Process::meta_ContextDFD_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Process::meta_ContextDFD_parent, "ContextDFD_parent", true);
			ContextDFD::meta_Process_child = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ContextDFD::meta_Process_child, "Process", true, 0, 1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			Entity::meta_ContextDFD_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(Entity::meta_ContextDFD_parent, "ContextDFD_parent", true);
			ContextDFD::meta_Entity_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(ContextDFD::meta_Entity_children, "Entity", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			RootFolder::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(RootFolder::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_RootFolder_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_RootFolder_children, "RootFolder", true, 0, -1);

		}
		{
			::Uml::Composition comp = ::Uml::Composition::Create(meta);
			::Uml::InitCompositionProps(comp, "", false);
			ContextDFD::meta_RootFolder_parent = ::Uml::CompositionParentRole::Create(comp);
			::Uml::InitCompositionParentRoleProps(ContextDFD::meta_RootFolder_parent, "RootFolder_parent", true);
			RootFolder::meta_ContextDFD_children = ::Uml::CompositionChildRole::Create(comp);
			::Uml::InitCompositionChildRoleProps(RootFolder::meta_ContextDFD_children, "ContextDFD", true, 0, -1);

		}

	}

	void InitMetaLinks() {
		DataFlow::meta_ContextDFD_parent.target() = ContextDFD::meta;
		Process::meta_ContextDFD_parent.target() = ContextDFD::meta;
		Entity::meta_ContextDFD_parent.target() = ContextDFD::meta;
		RootFolder::meta_ContextDFD_children.target() = ContextDFD::meta;

		ContextDFD::meta_DataFlow_children.target() = DataFlow::meta;
		Process::meta_DataFlow_children.target() = DataFlow::meta;
		DataFlow::meta.association() = Process::meta_srcTransition.parent();
		DataFlow::meta_srcTransition_end_ = Process::meta_dstTransition_rev = Process::meta_srcTransition;
		DataFlow::meta_dstTransition_end_ = Process::meta_srcTransition_rev = Process::meta_dstTransition;

		Process::meta_DataStore_children.target() = DataStore::meta;

		Process::meta_Entity_children.target() = Entity::meta;
		ContextDFD::meta_Entity_children.target() = Entity::meta;

		MgaObject::meta.subTypes() += DataFlow::meta;
		MgaObject::meta.subTypes() += DataStore::meta;
		MgaObject::meta.subTypes() += Process::meta;
		MgaObject::meta.subTypes() += Entity::meta;
		MgaObject::meta.subTypes() += ContextDFD::meta;

		Process::meta_srcTransition.target() = Process::meta;
		Process::meta_dstTransition.target() = Process::meta;
		Entity::meta_Process_parent.target() = Process::meta;
		DataStore::meta_Process_parent.target() = Process::meta;
		Process::meta_Process_parent.target() = Process::meta;
		DataFlow::meta_Process_parent.target() = Process::meta;
		Process::meta_Process_children.target() = Process::meta;
		ContextDFD::meta_Process_child.target() = Process::meta;

		RootFolder::meta_RootFolder_parent.target() = RootFolder::meta;
		ContextDFD::meta_RootFolder_parent.target() = RootFolder::meta;
		RootFolder::meta_RootFolder_children.target() = RootFolder::meta;

	}

	void InitMeta(const ::Uml::Diagram &parent) {
		// classes, with attributes, constraints and constraint definitions
		::Uml::SetClass(ContextDFD::meta, parent, "ContextDFD");

		::Uml::SetClass(DataFlow::meta, parent, "DataFlow");
		::Uml::SetAttribute(DataFlow::meta_Event, DataFlow::meta, "Event");

		::Uml::SetClass(DataStore::meta, parent, "DataStore");

		::Uml::SetClass(Entity::meta, parent, "Entity");

		::Uml::SetClass(MgaObject::meta, parent, "MgaObject");
		::Uml::SetAttribute(MgaObject::meta_position, MgaObject::meta, "position");
		::Uml::SetAttribute(MgaObject::meta_name, MgaObject::meta, "name");

		::Uml::SetClass(Process::meta, parent, "Process");

		::Uml::SetClass(RootFolder::meta, parent, "RootFolder");
		::Uml::SetAttribute(RootFolder::meta_name, RootFolder::meta, "name");

	}

	void InitMetaLinks(const ::Uml::Diagram &parent) {
		// classes
		::Uml::SetChildRole(ContextDFD::meta_DataFlow_children, ContextDFD::meta, DataFlow::meta, "", "");
		::Uml::SetChildRole(ContextDFD::meta_Process_child, ContextDFD::meta, Process::meta, "", "");
		::Uml::SetChildRole(ContextDFD::meta_Entity_children, ContextDFD::meta, Entity::meta, "", "");
		::Uml::SetParentRole(ContextDFD::meta_RootFolder_parent, ContextDFD::meta, RootFolder::meta, "", "");

		::Uml::SetParentRole(DataFlow::meta_ContextDFD_parent, DataFlow::meta, ContextDFD::meta, "", "");
		::Uml::SetParentRole(DataFlow::meta_Process_parent, DataFlow::meta, Process::meta, "", "");
		DataFlow::meta_dstTransition_end_ = Process::meta_dstTransition;
		DataFlow::meta_srcTransition_end_ = Process::meta_srcTransition;

		::Uml::SetParentRole(DataStore::meta_Process_parent, DataStore::meta, Process::meta, "", "");

		::Uml::SetParentRole(Entity::meta_Process_parent, Entity::meta, Process::meta, "", "");
		::Uml::SetParentRole(Entity::meta_ContextDFD_parent, Entity::meta, ContextDFD::meta, "", "");

		::Uml::SetAssocRole(Process::meta_srcTransition, Process::meta, Process::meta, "dstTransition");
		Process::meta_dstTransition_rev = Process::meta_srcTransition;
		::Uml::SetAssocRole(Process::meta_dstTransition, Process::meta, Process::meta, "srcTransition");
		Process::meta_srcTransition_rev = Process::meta_dstTransition;
		::Uml::SetChildRole(Process::meta_Entity_children, Process::meta, Entity::meta, "", "");
		::Uml::SetChildRole(Process::meta_DataStore_children, Process::meta, DataStore::meta, "", "");
		::Uml::SetChildRole(Process::meta_Process_children, Process::meta, Process::meta, "", "");
		::Uml::SetChildRole(Process::meta_DataFlow_children, Process::meta, DataFlow::meta, "", "");
		::Uml::SetParentRole(Process::meta_Process_parent, Process::meta, Process::meta, "", "");
		::Uml::SetParentRole(Process::meta_ContextDFD_parent, Process::meta, ContextDFD::meta, "", "");

		::Uml::SetChildRole(RootFolder::meta_RootFolder_children, RootFolder::meta, RootFolder::meta, "", "");
		::Uml::SetChildRole(RootFolder::meta_ContextDFD_children, RootFolder::meta, ContextDFD::meta, "", "");
		::Uml::SetParentRole(RootFolder::meta_RootFolder_parent, RootFolder::meta, RootFolder::meta, "", "");

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

/* The BaseVisitor reference need not be const. This will make it consistent
   with other Accept functions.
*/
//virtual void Udm::Object::Accept(const BaseVisitor & bv) { bv.Visit_Object(*this); }  

//virtual void Udm::BaseVisitor::Visit_Object (const Object &) const = 0;

  template <class T>
  static bool dispatchIf(Udm::Object o, Visitor & v)
  {
    if (Udm::IsDerivedFrom(o.type(), T::meta))  
    {
      T t = T::Cast(o);
      t.Accept(v);
      return true;
    }
    return false;
  }

  /* 1. This code has a potential for slowing down dispatching 
        linearly with the number of kinds. This is not accetable for
        large languages. A constant time dispatch technique based on 
        Udm's meta information could be used to do that. Perfect hashing
        (gperf) technique by Doug Schmidt could be used to achieve absolute 
        constant time dispatching.
     2. If hashing (perfect or otherwise) is not used, the order in which
        the dispatchIf occurs is very important. The base classes should
        occur after the derived classes. Otherwise, dispatch will made 
        prematurely.
     3. If abstract UML types don't have their own Accept and Visit_* 
        functions then those classes should not reappear here. 
        It will cause infinite recursion.
  */
  void HFSM::Visitor::Visit_Object(const Udm::Object &o)
  {
    /*    Short Circuit using ||     */
    dispatchIf <RootFolder> (o, *this) ||
    dispatchIf <ContextDFD> (o, *this) || 
    dispatchIf <DataFlow>   (o, *this) ||
    dispatchIf <DataStore>  (o, *this) ||
    dispatchIf <Entity>     (o, *this) ||
    dispatchIf <Process>    (o, *this);
  }

}
