#ifndef MOBIES_PICML_H
#define MOBIES_PICML_H
// header file PICML.h generated from diagram PICML
// generated on Tue May 11 01:41:10 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

namespace cadena_scenario
{ 
	 class  EventSource;
	 class  EventSink;
	 class  Receptacle;
	 class  Facet;
	 class  ComponentPort;
};


namespace PICML {

	typedef Udm::Object Object;

	class  ImplementationArtifactReference;
	class  ImplementationArtifacts;
	class  ArtifactDependsOn;
	class  ArtifactDeployRequirement;
	class  ArtifactContainer;
	class  ArtifactExecParameter;
	class  ArtifactInfoProperty;
	class  ImplementationArtifact;
	class  IDLFile;
	class  IDLFiles;
	class  ComponentType;
	class  ComponentTypes;
	class  ComponentConfigProperty;
	class  ComponentInfoProperty;
	class  CommonPortAttrs;
	class  ComponentPropertyDescription;
	class  ComponentProperty;
	class  ComponentContainer;
	class  ImplementationCapability;
	class  ImplementationDependsOn;
	class  Implements;
	class  ComponentImplementations;
	class  ComponentImplementationReference;
	class  ConfigProperty;
	class  InfoProperty;
	class  MonolithprimaryArtifact;
	class  MonolithDeployRequirement;
	class  ComponentImplementation;
	class  ComponentImplementationContainer;
	class  MonolithExecParameter;
	class  MonolithicImplementation;
	class  RequirementBase;
	class  ImplementationRequirement;
	class  Requirement;
	class  ImplementationDependency;
	class  Any;
	class  Property;
	class  SatisfierProperty;
	class  DataType;
	class  RequirementSatisfier;
	class  Capability;
	class  PackageBaseConnection;
	class  PackageReferenceConnection;
	class  PackageConfigurationReference;
	class  PackageConfiguration;
	class  PackageConfigurations;
	class  PackageConfigurationContainer;
	class  PackageConfigurationProperty;
	class  PackageSelectRequirement;
	class  EmitConnector;
	class  ComponentAssembly;
	class  Invocation;
	class  SubComponentSelectRequirement;
	class  SubComponentConfigProperty;
	class  PublishConnector;
	class  OutEventPortPublish;
	class  InEventPortConsume;
	class  ConnectionRequirements;
	class  ComponentPackages;
	class  PackageInterface;
	class  PackageImplementations;
	class  PackageContainer;
	class  PackageConfigProperty;
	class  PackageInfoProperty;
	class  ComponentPackage;
	class  ComponentPackageReference;
	class  TopLevelPackageContainer;
	class  TopLevelPackageFolder;
	class  TopLevelPackage;
	class  TopLevelPackageConn;
	class  EnumerationDef;
	class  EnumValue;
	class  AliasDef;
	class  AggregateDef;
	class  SwitchedAggregateDef;
	class  Label;
	class  Discriminator;
	class  LabelConnection;
	class  BoxedDef;
	class  NamedTypeRef;
	class  EnumRef;
	class  NamedType;
	class  Member;
	class  NoInheritable;
	class  IdTag;
	class  PrefixTag;
	class  GeneralTag;
	class  SpecifyIdTag;
	class  VersionTag;
	class  Prefixable;
	class  Taggable;
	class  ReturnType;
	class  InParameter;
	class  InoutParameter;
	class  OutParameter;
	class  ParameterType;
	class  OperationBase;
	class  Parameter;
	class  HasExceptions;
	class  OnewayOperation;
	class  LookupOperation;
	class  FactoryOperation;
	class  TwowayOperation;
	class  Package;
	class  Type;
	class  ExceptionRef;
	class  FileRef;
	class  ConstantDef;
	class  ExceptionDef;
	class  RequestPort;
	class  EventPort;
	class  EventRef;
	class  ObjectRef;
	class  ProvidedRequestPort;
	class  RequiredRequestPort;
	class  OutEventPort;
	class  InEventPort;
	class  Port;
	class  ComponentDef;
	class  BoundedString;
	class  FixedSizeCollection;
	class  VariableSizeCollection;
	class  AnonymousType;
	class  CollectionType;
	class  PredefinedType;
	class  FixedPoint;
	class  ObjectDef;
	class  ComponentFactory;
	class  Inherits;
	class  EventDef;
	class  ValueDef;
	class  Inheritable;
	class  HasOperations;
	class  SupportsInterfaces;
	class  Supports;
	class  ReadonlyAttribute;
	class  Attribute;
	class  LookupKey;
	class  Manages;
	class  SetException;
	class  ObjectByValue;
	class  GetException;
	class  PrivateFlag;
	class  MakeMemberPrivate;
	class  RootFolder;
	class  MgaObject;

	  void Initialize();

	  void Initialize(const Uml::Diagram &dgr);
	extern  Udm::UdmDiagram diagram;

	class  ImplementationArtifacts :  public Object {
	 public:
		static Uml::Class meta;

		ImplementationArtifacts() { }
		ImplementationArtifacts(Udm::ObjectImpl *impl) : Object(impl) { }
		ImplementationArtifacts(const ImplementationArtifacts &master) : Object(master) { }
		static ImplementationArtifacts Cast(const Object &a) { return __Cast(a, meta); }

		static ImplementationArtifacts Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ImplementationArtifacts CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ImplementationArtifacts CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ImplementationArtifacts> Instances() { return Udm::InstantiatedAttr<PICML::ImplementationArtifacts>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ImplementationArtifacts, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ImplementationArtifacts, Pred>(impl);}

		Udm::DerivedAttr<PICML::ImplementationArtifacts> Derived() { return Udm::DerivedAttr<PICML::ImplementationArtifacts>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ImplementationArtifacts, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ImplementationArtifacts, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ImplementationArtifacts> Archetype() { return Udm::ArchetypeAttr<PICML::ImplementationArtifacts>(impl);}

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_ArtifactContainer_children;
		Udm::ChildrenAttr<PICML::ArtifactContainer> ArtifactContainer_children() const { return Udm::ChildrenAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ArtifactContainer, Pred> ArtifactContainer_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactContainer, Pred>(impl, meta_ArtifactContainer_children); }

		Udm::ChildrenAttr<PICML::ArtifactContainer> ArtifactContainer_kind_children() const { return Udm::ChildrenAttr<PICML::ArtifactContainer>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ArtifactContainer, Pred> ArtifactContainer_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactContainer, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RootFolder_parent;
		Udm::ParentAttr<PICML::RootFolder> RootFolder_parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, meta_RootFolder_parent); }

		Udm::ParentAttr<PICML::RootFolder> parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  IDLFiles :  public Object {
	 public:
		static Uml::Class meta;

		IDLFiles() { }
		IDLFiles(Udm::ObjectImpl *impl) : Object(impl) { }
		IDLFiles(const IDLFiles &master) : Object(master) { }
		static IDLFiles Cast(const Object &a) { return __Cast(a, meta); }

		static IDLFiles Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		IDLFiles CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		IDLFiles CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<IDLFiles> Instances() { return Udm::InstantiatedAttr<PICML::IDLFiles>(impl);}
		template <class Pred> Udm::InstantiatedAttr<IDLFiles, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::IDLFiles, Pred>(impl);}

		Udm::DerivedAttr<PICML::IDLFiles> Derived() { return Udm::DerivedAttr<PICML::IDLFiles>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::IDLFiles, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::IDLFiles, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::IDLFiles> Archetype() { return Udm::ArchetypeAttr<PICML::IDLFiles>(impl);}

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_IDLFile_children;
		Udm::ChildrenAttr<PICML::IDLFile> IDLFile_children() const { return Udm::ChildrenAttr<PICML::IDLFile>(impl, meta_IDLFile_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::IDLFile, Pred> IDLFile_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::IDLFile, Pred>(impl, meta_IDLFile_children); }

		Udm::ChildrenAttr<PICML::IDLFile> IDLFile_kind_children() const { return Udm::ChildrenAttr<PICML::IDLFile>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::IDLFile, Pred> IDLFile_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::IDLFile, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Prefixable> Prefixable_kind_children() const { return Udm::ChildrenAttr<PICML::Prefixable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Prefixable, Pred> Prefixable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Prefixable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RootFolder_parent;
		Udm::ParentAttr<PICML::RootFolder> RootFolder_parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, meta_RootFolder_parent); }

		Udm::ParentAttr<PICML::RootFolder> parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentTypes :  public Object {
	 public:
		static Uml::Class meta;

		ComponentTypes() { }
		ComponentTypes(Udm::ObjectImpl *impl) : Object(impl) { }
		ComponentTypes(const ComponentTypes &master) : Object(master) { }
		static ComponentTypes Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentTypes Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentTypes CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentTypes CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentTypes> Instances() { return Udm::InstantiatedAttr<PICML::ComponentTypes>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentTypes, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentTypes, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentTypes> Derived() { return Udm::DerivedAttr<PICML::ComponentTypes>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentTypes, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentTypes, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentTypes> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentTypes>(impl);}

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_ComponentContainer_children;
		Udm::ChildrenAttr<PICML::ComponentContainer> ComponentContainer_children() const { return Udm::ChildrenAttr<PICML::ComponentContainer>(impl, meta_ComponentContainer_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentContainer, Pred> ComponentContainer_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentContainer, Pred>(impl, meta_ComponentContainer_children); }

		Udm::ChildrenAttr<PICML::ComponentContainer> ComponentContainer_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentContainer>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentContainer, Pred> ComponentContainer_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentContainer, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RootFolder_parent;
		Udm::ParentAttr<PICML::RootFolder> RootFolder_parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, meta_RootFolder_parent); }

		Udm::ParentAttr<PICML::RootFolder> parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentImplementations :  public Object {
	 public:
		static Uml::Class meta;

		ComponentImplementations() { }
		ComponentImplementations(Udm::ObjectImpl *impl) : Object(impl) { }
		ComponentImplementations(const ComponentImplementations &master) : Object(master) { }
		static ComponentImplementations Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentImplementations Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentImplementations CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentImplementations CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentImplementations> Instances() { return Udm::InstantiatedAttr<PICML::ComponentImplementations>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentImplementations, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentImplementations, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentImplementations> Derived() { return Udm::DerivedAttr<PICML::ComponentImplementations>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentImplementations, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentImplementations, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentImplementations> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentImplementations>(impl);}

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_ComponentImplementationContainer_children;
		Udm::ChildrenAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_children() const { return Udm::ChildrenAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentImplementationContainer, Pred> ComponentImplementationContainer_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentImplementationContainer, Pred>(impl, meta_ComponentImplementationContainer_children); }

		Udm::ChildrenAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentImplementationContainer>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentImplementationContainer, Pred> ComponentImplementationContainer_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentImplementationContainer, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RootFolder_parent;
		Udm::ParentAttr<PICML::RootFolder> RootFolder_parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, meta_RootFolder_parent); }

		Udm::ParentAttr<PICML::RootFolder> parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  PackageConfigurations :  public Object {
	 public:
		static Uml::Class meta;

		PackageConfigurations() { }
		PackageConfigurations(Udm::ObjectImpl *impl) : Object(impl) { }
		PackageConfigurations(const PackageConfigurations &master) : Object(master) { }
		static PackageConfigurations Cast(const Object &a) { return __Cast(a, meta); }

		static PackageConfigurations Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageConfigurations CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageConfigurations CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageConfigurations> Instances() { return Udm::InstantiatedAttr<PICML::PackageConfigurations>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageConfigurations, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageConfigurations, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageConfigurations> Derived() { return Udm::DerivedAttr<PICML::PackageConfigurations>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageConfigurations, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageConfigurations, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageConfigurations> Archetype() { return Udm::ArchetypeAttr<PICML::PackageConfigurations>(impl);}

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_PackageConfigurationContainer_children;
		Udm::ChildrenAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_children() const { return Udm::ChildrenAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageConfigurationContainer, Pred> PackageConfigurationContainer_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigurationContainer, Pred>(impl, meta_PackageConfigurationContainer_children); }

		Udm::ChildrenAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_kind_children() const { return Udm::ChildrenAttr<PICML::PackageConfigurationContainer>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageConfigurationContainer, Pred> PackageConfigurationContainer_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigurationContainer, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RootFolder_parent;
		Udm::ParentAttr<PICML::RootFolder> RootFolder_parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, meta_RootFolder_parent); }

		Udm::ParentAttr<PICML::RootFolder> parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentPackages :  public Object {
	 public:
		static Uml::Class meta;

		ComponentPackages() { }
		ComponentPackages(Udm::ObjectImpl *impl) : Object(impl) { }
		ComponentPackages(const ComponentPackages &master) : Object(master) { }
		static ComponentPackages Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentPackages Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentPackages CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentPackages CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentPackages> Instances() { return Udm::InstantiatedAttr<PICML::ComponentPackages>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentPackages, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentPackages, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentPackages> Derived() { return Udm::DerivedAttr<PICML::ComponentPackages>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentPackages, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentPackages, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentPackages> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentPackages>(impl);}

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_PackageContainer_children;
		Udm::ChildrenAttr<PICML::PackageContainer> PackageContainer_children() const { return Udm::ChildrenAttr<PICML::PackageContainer>(impl, meta_PackageContainer_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageContainer, Pred> PackageContainer_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageContainer, Pred>(impl, meta_PackageContainer_children); }

		Udm::ChildrenAttr<PICML::PackageContainer> PackageContainer_kind_children() const { return Udm::ChildrenAttr<PICML::PackageContainer>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageContainer, Pred> PackageContainer_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageContainer, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RootFolder_parent;
		Udm::ParentAttr<PICML::RootFolder> RootFolder_parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, meta_RootFolder_parent); }

		Udm::ParentAttr<PICML::RootFolder> parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  TopLevelPackageFolder :  public Object {
	 public:
		static Uml::Class meta;

		TopLevelPackageFolder() { }
		TopLevelPackageFolder(Udm::ObjectImpl *impl) : Object(impl) { }
		TopLevelPackageFolder(const TopLevelPackageFolder &master) : Object(master) { }
		static TopLevelPackageFolder Cast(const Object &a) { return __Cast(a, meta); }

		static TopLevelPackageFolder Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		TopLevelPackageFolder CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		TopLevelPackageFolder CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<TopLevelPackageFolder> Instances() { return Udm::InstantiatedAttr<PICML::TopLevelPackageFolder>(impl);}
		template <class Pred> Udm::InstantiatedAttr<TopLevelPackageFolder, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::TopLevelPackageFolder, Pred>(impl);}

		Udm::DerivedAttr<PICML::TopLevelPackageFolder> Derived() { return Udm::DerivedAttr<PICML::TopLevelPackageFolder>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::TopLevelPackageFolder, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::TopLevelPackageFolder, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::TopLevelPackageFolder> Archetype() { return Udm::ArchetypeAttr<PICML::TopLevelPackageFolder>(impl);}

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_TopLevelPackageContainer_children;
		Udm::ChildrenAttr<PICML::TopLevelPackageContainer> TopLevelPackageContainer_children() const { return Udm::ChildrenAttr<PICML::TopLevelPackageContainer>(impl, meta_TopLevelPackageContainer_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::TopLevelPackageContainer, Pred> TopLevelPackageContainer_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TopLevelPackageContainer, Pred>(impl, meta_TopLevelPackageContainer_children); }

		Udm::ChildrenAttr<PICML::TopLevelPackageContainer> TopLevelPackageContainer_kind_children() const { return Udm::ChildrenAttr<PICML::TopLevelPackageContainer>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::TopLevelPackageContainer, Pred> TopLevelPackageContainer_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TopLevelPackageContainer, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RootFolder_parent;
		Udm::ParentAttr<PICML::RootFolder> RootFolder_parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, meta_RootFolder_parent); }

		Udm::ParentAttr<PICML::RootFolder> parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  RootFolder :  public Object {
	 public:
		static Uml::Class meta;

		RootFolder() { }
		RootFolder(Udm::ObjectImpl *impl) : Object(impl) { }
		RootFolder(const RootFolder &master) : Object(master) { }
		static RootFolder Cast(const Object &a) { return __Cast(a, meta); }

		static RootFolder Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RootFolder CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RootFolder CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RootFolder> Instances() { return Udm::InstantiatedAttr<PICML::RootFolder>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RootFolder, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::RootFolder, Pred>(impl);}

		Udm::DerivedAttr<PICML::RootFolder> Derived() { return Udm::DerivedAttr<PICML::RootFolder>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::RootFolder, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::RootFolder, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::RootFolder> Archetype() { return Udm::ArchetypeAttr<PICML::RootFolder>(impl);}

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		static Uml::CompositionChildRole meta_IDLFiles_children;
		Udm::ChildrenAttr<PICML::IDLFiles> IDLFiles_children() const { return Udm::ChildrenAttr<PICML::IDLFiles>(impl, meta_IDLFiles_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::IDLFiles, Pred> IDLFiles_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::IDLFiles, Pred>(impl, meta_IDLFiles_children); }

		static Uml::CompositionChildRole meta_ImplementationArtifacts_children;
		Udm::ChildrenAttr<PICML::ImplementationArtifacts> ImplementationArtifacts_children() const { return Udm::ChildrenAttr<PICML::ImplementationArtifacts>(impl, meta_ImplementationArtifacts_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ImplementationArtifacts, Pred> ImplementationArtifacts_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationArtifacts, Pred>(impl, meta_ImplementationArtifacts_children); }

		static Uml::CompositionChildRole meta_ComponentTypes_children;
		Udm::ChildrenAttr<PICML::ComponentTypes> ComponentTypes_children() const { return Udm::ChildrenAttr<PICML::ComponentTypes>(impl, meta_ComponentTypes_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentTypes, Pred> ComponentTypes_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentTypes, Pred>(impl, meta_ComponentTypes_children); }

		static Uml::CompositionChildRole meta_ComponentImplementations_children;
		Udm::ChildrenAttr<PICML::ComponentImplementations> ComponentImplementations_children() const { return Udm::ChildrenAttr<PICML::ComponentImplementations>(impl, meta_ComponentImplementations_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentImplementations, Pred> ComponentImplementations_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentImplementations, Pred>(impl, meta_ComponentImplementations_children); }

		static Uml::CompositionChildRole meta_PackageConfigurations_children;
		Udm::ChildrenAttr<PICML::PackageConfigurations> PackageConfigurations_children() const { return Udm::ChildrenAttr<PICML::PackageConfigurations>(impl, meta_PackageConfigurations_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageConfigurations, Pred> PackageConfigurations_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigurations, Pred>(impl, meta_PackageConfigurations_children); }

		static Uml::CompositionChildRole meta_ComponentPackages_children;
		Udm::ChildrenAttr<PICML::ComponentPackages> ComponentPackages_children() const { return Udm::ChildrenAttr<PICML::ComponentPackages>(impl, meta_ComponentPackages_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentPackages, Pred> ComponentPackages_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackages, Pred>(impl, meta_ComponentPackages_children); }

		static Uml::CompositionChildRole meta_TopLevelPackageFolder_children;
		Udm::ChildrenAttr<PICML::TopLevelPackageFolder> TopLevelPackageFolder_children() const { return Udm::ChildrenAttr<PICML::TopLevelPackageFolder>(impl, meta_TopLevelPackageFolder_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::TopLevelPackageFolder, Pred> TopLevelPackageFolder_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TopLevelPackageFolder, Pred>(impl, meta_TopLevelPackageFolder_children); }

		static Uml::CompositionChildRole meta_RootFolder_children;
		Udm::ChildrenAttr<PICML::RootFolder> RootFolder_children() const { return Udm::ChildrenAttr<PICML::RootFolder>(impl, meta_RootFolder_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::RootFolder, Pred> RootFolder_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RootFolder, Pred>(impl, meta_RootFolder_children); }

		Udm::ChildrenAttr<PICML::ImplementationArtifacts> ImplementationArtifacts_kind_children() const { return Udm::ChildrenAttr<PICML::ImplementationArtifacts>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ImplementationArtifacts, Pred> ImplementationArtifacts_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationArtifacts, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::IDLFiles> IDLFiles_kind_children() const { return Udm::ChildrenAttr<PICML::IDLFiles>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::IDLFiles, Pred> IDLFiles_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::IDLFiles, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentTypes> ComponentTypes_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentTypes>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentTypes, Pred> ComponentTypes_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentTypes, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentImplementations> ComponentImplementations_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentImplementations>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentImplementations, Pred> ComponentImplementations_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentImplementations, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageConfigurations> PackageConfigurations_kind_children() const { return Udm::ChildrenAttr<PICML::PackageConfigurations>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageConfigurations, Pred> PackageConfigurations_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigurations, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentPackages> ComponentPackages_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentPackages>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentPackages, Pred> ComponentPackages_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackages, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::TopLevelPackageFolder> TopLevelPackageFolder_kind_children() const { return Udm::ChildrenAttr<PICML::TopLevelPackageFolder>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::TopLevelPackageFolder, Pred> TopLevelPackageFolder_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TopLevelPackageFolder, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::RootFolder> RootFolder_kind_children() const { return Udm::ChildrenAttr<PICML::RootFolder>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::RootFolder, Pred> RootFolder_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RootFolder, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RootFolder_parent;
		Udm::ParentAttr<PICML::RootFolder> RootFolder_parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, meta_RootFolder_parent); }

		Udm::ParentAttr<PICML::RootFolder> parent() const { return Udm::ParentAttr<PICML::RootFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  MgaObject :  public Object {
	 public:
		static Uml::Class meta;

		MgaObject() { }
		MgaObject(Udm::ObjectImpl *impl) : Object(impl) { }
		MgaObject(const MgaObject &master) : Object(master) { }
		static MgaObject Cast(const Object &a) { return __Cast(a, meta); }

		static MgaObject Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		MgaObject CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		MgaObject CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<MgaObject> Instances() { return Udm::InstantiatedAttr<PICML::MgaObject>(impl);}
		template <class Pred> Udm::InstantiatedAttr<MgaObject, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::MgaObject, Pred>(impl);}

		Udm::DerivedAttr<PICML::MgaObject> Derived() { return Udm::DerivedAttr<PICML::MgaObject>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::MgaObject, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::MgaObject, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::MgaObject> Archetype() { return Udm::ArchetypeAttr<PICML::MgaObject>(impl);}

		static Uml::Attribute meta_position;
		Udm::StringAttr position() const { return Udm::StringAttr(impl, meta_position); }

		static Uml::Attribute meta_name;
		Udm::StringAttr name() const { return Udm::StringAttr(impl, meta_name); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  ImplementationArtifactReference :  public MgaObject {
	 public:
		static Uml::Class meta;

		ImplementationArtifactReference() { }
		ImplementationArtifactReference(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ImplementationArtifactReference(const ImplementationArtifactReference &master) : MgaObject(master) { }
		static ImplementationArtifactReference Cast(const Object &a) { return __Cast(a, meta); }

		static ImplementationArtifactReference Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ImplementationArtifactReference CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ImplementationArtifactReference CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ImplementationArtifactReference> Instances() { return Udm::InstantiatedAttr<PICML::ImplementationArtifactReference>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ImplementationArtifactReference, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ImplementationArtifactReference, Pred>(impl);}

		Udm::DerivedAttr<PICML::ImplementationArtifactReference> Derived() { return Udm::DerivedAttr<PICML::ImplementationArtifactReference>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ImplementationArtifactReference, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ImplementationArtifactReference, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ImplementationArtifactReference> Archetype() { return Udm::ArchetypeAttr<PICML::ImplementationArtifactReference>(impl);}

		static Uml::AssociationRole meta_srcArtifactDependsOn, meta_srcArtifactDependsOn_rev;
		Udm::AClassAssocAttr<PICML::ArtifactDependsOn, PICML::ImplementationArtifact> srcArtifactDependsOn() const { return Udm::AClassAssocAttr<PICML::ArtifactDependsOn, PICML::ImplementationArtifact>(impl, meta_srcArtifactDependsOn, meta_srcArtifactDependsOn_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ArtifactDependsOn, PICML::ImplementationArtifact, Pred> srcArtifactDependsOn_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ArtifactDependsOn, PICML::ImplementationArtifact, Pred>(impl, meta_srcArtifactDependsOn, meta_srcArtifactDependsOn_rev); }

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ImplementationArtifact> ref() const { return Udm::PointerAttr<PICML::ImplementationArtifact>(impl, meta_ref); }

		static Uml::AssociationRole meta_srcMonolithprimaryArtifact, meta_srcMonolithprimaryArtifact_rev;
		Udm::AClassAssocAttr<PICML::MonolithprimaryArtifact, PICML::MonolithicImplementation> srcMonolithprimaryArtifact() const { return Udm::AClassAssocAttr<PICML::MonolithprimaryArtifact, PICML::MonolithicImplementation>(impl, meta_srcMonolithprimaryArtifact, meta_srcMonolithprimaryArtifact_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::MonolithprimaryArtifact, PICML::MonolithicImplementation, Pred> srcMonolithprimaryArtifact_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::MonolithprimaryArtifact, PICML::MonolithicImplementation, Pred>(impl, meta_srcMonolithprimaryArtifact, meta_srcMonolithprimaryArtifact_rev); }

		static Uml::CompositionParentRole meta_ArtifactContainer_parent;
		Udm::ParentAttr<PICML::ArtifactContainer> ArtifactContainer_parent() const { return Udm::ParentAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ArtifactDependsOn :  public MgaObject {
	 public:
		static Uml::Class meta;

		ArtifactDependsOn() { }
		ArtifactDependsOn(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ArtifactDependsOn(const ArtifactDependsOn &master) : MgaObject(master) { }
		static ArtifactDependsOn Cast(const Object &a) { return __Cast(a, meta); }

		static ArtifactDependsOn Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ArtifactDependsOn CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ArtifactDependsOn CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ArtifactDependsOn> Instances() { return Udm::InstantiatedAttr<PICML::ArtifactDependsOn>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ArtifactDependsOn, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ArtifactDependsOn, Pred>(impl);}

		Udm::DerivedAttr<PICML::ArtifactDependsOn> Derived() { return Udm::DerivedAttr<PICML::ArtifactDependsOn>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ArtifactDependsOn, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ArtifactDependsOn, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ArtifactDependsOn> Archetype() { return Udm::ArchetypeAttr<PICML::ArtifactDependsOn>(impl);}

		static Uml::CompositionParentRole meta_ArtifactContainer_parent;
		Udm::ParentAttr<PICML::ArtifactContainer> ArtifactContainer_parent() const { return Udm::ParentAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstArtifactDependsOn_end_;
		Udm::AssocEndAttr<PICML::ImplementationArtifactReference> dstArtifactDependsOn_end() const { return Udm::AssocEndAttr<PICML::ImplementationArtifactReference>(impl, meta_dstArtifactDependsOn_end_); }

		static Uml::AssociationRole meta_srcArtifactDependsOn_end_;
		Udm::AssocEndAttr<PICML::ImplementationArtifact> srcArtifactDependsOn_end() const { return Udm::AssocEndAttr<PICML::ImplementationArtifact>(impl, meta_srcArtifactDependsOn_end_); }

	};

	class  ArtifactDeployRequirement :  public MgaObject {
	 public:
		static Uml::Class meta;

		ArtifactDeployRequirement() { }
		ArtifactDeployRequirement(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ArtifactDeployRequirement(const ArtifactDeployRequirement &master) : MgaObject(master) { }
		static ArtifactDeployRequirement Cast(const Object &a) { return __Cast(a, meta); }

		static ArtifactDeployRequirement Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ArtifactDeployRequirement CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ArtifactDeployRequirement CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ArtifactDeployRequirement> Instances() { return Udm::InstantiatedAttr<PICML::ArtifactDeployRequirement>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ArtifactDeployRequirement, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ArtifactDeployRequirement, Pred>(impl);}

		Udm::DerivedAttr<PICML::ArtifactDeployRequirement> Derived() { return Udm::DerivedAttr<PICML::ArtifactDeployRequirement>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ArtifactDeployRequirement, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ArtifactDeployRequirement, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ArtifactDeployRequirement> Archetype() { return Udm::ArchetypeAttr<PICML::ArtifactDeployRequirement>(impl);}

		static Uml::CompositionParentRole meta_ArtifactContainer_parent;
		Udm::ParentAttr<PICML::ArtifactContainer> ArtifactContainer_parent() const { return Udm::ParentAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstArtifactDeployRequirement_end_;
		Udm::AssocEndAttr<PICML::Requirement> dstArtifactDeployRequirement_end() const { return Udm::AssocEndAttr<PICML::Requirement>(impl, meta_dstArtifactDeployRequirement_end_); }

		static Uml::AssociationRole meta_srcArtifactDeployRequirement_end_;
		Udm::AssocEndAttr<PICML::ImplementationArtifact> srcArtifactDeployRequirement_end() const { return Udm::AssocEndAttr<PICML::ImplementationArtifact>(impl, meta_srcArtifactDeployRequirement_end_); }

	};

	class  ArtifactContainer :  public MgaObject {
	 public:
		static Uml::Class meta;

		ArtifactContainer() { }
		ArtifactContainer(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ArtifactContainer(const ArtifactContainer &master) : MgaObject(master) { }
		static ArtifactContainer Cast(const Object &a) { return __Cast(a, meta); }

		static ArtifactContainer Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ArtifactContainer CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ArtifactContainer CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ArtifactContainer> Instances() { return Udm::InstantiatedAttr<PICML::ArtifactContainer>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ArtifactContainer, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ArtifactContainer, Pred>(impl);}

		Udm::DerivedAttr<PICML::ArtifactContainer> Derived() { return Udm::DerivedAttr<PICML::ArtifactContainer>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ArtifactContainer, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ArtifactContainer, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ArtifactContainer> Archetype() { return Udm::ArchetypeAttr<PICML::ArtifactContainer>(impl);}

		static Uml::CompositionChildRole meta_ImplementationArtifactReference_children;
		Udm::ChildrenAttr<PICML::ImplementationArtifactReference> ImplementationArtifactReference_children() const { return Udm::ChildrenAttr<PICML::ImplementationArtifactReference>(impl, meta_ImplementationArtifactReference_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ImplementationArtifactReference, Pred> ImplementationArtifactReference_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationArtifactReference, Pred>(impl, meta_ImplementationArtifactReference_children); }

		static Uml::CompositionChildRole meta_ArtifactDependsOn_children;
		Udm::ChildrenAttr<PICML::ArtifactDependsOn> ArtifactDependsOn_children() const { return Udm::ChildrenAttr<PICML::ArtifactDependsOn>(impl, meta_ArtifactDependsOn_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ArtifactDependsOn, Pred> ArtifactDependsOn_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactDependsOn, Pred>(impl, meta_ArtifactDependsOn_children); }

		static Uml::CompositionChildRole meta_ArtifactDeployRequirement_children;
		Udm::ChildrenAttr<PICML::ArtifactDeployRequirement> ArtifactDeployRequirement_children() const { return Udm::ChildrenAttr<PICML::ArtifactDeployRequirement>(impl, meta_ArtifactDeployRequirement_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ArtifactDeployRequirement, Pred> ArtifactDeployRequirement_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactDeployRequirement, Pred>(impl, meta_ArtifactDeployRequirement_children); }

		static Uml::CompositionChildRole meta_Requirement_children;
		Udm::ChildrenAttr<PICML::Requirement> Requirement_children() const { return Udm::ChildrenAttr<PICML::Requirement>(impl, meta_Requirement_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Requirement, Pred> Requirement_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Requirement, Pred>(impl, meta_Requirement_children); }

		static Uml::CompositionChildRole meta_ArtifactExecParameter_children;
		Udm::ChildrenAttr<PICML::ArtifactExecParameter> ArtifactExecParameter_children() const { return Udm::ChildrenAttr<PICML::ArtifactExecParameter>(impl, meta_ArtifactExecParameter_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ArtifactExecParameter, Pred> ArtifactExecParameter_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactExecParameter, Pred>(impl, meta_ArtifactExecParameter_children); }

		static Uml::CompositionChildRole meta_ArtifactInfoProperty_children;
		Udm::ChildrenAttr<PICML::ArtifactInfoProperty> ArtifactInfoProperty_children() const { return Udm::ChildrenAttr<PICML::ArtifactInfoProperty>(impl, meta_ArtifactInfoProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ArtifactInfoProperty, Pred> ArtifactInfoProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactInfoProperty, Pred>(impl, meta_ArtifactInfoProperty_children); }

		static Uml::CompositionChildRole meta_Property_children;
		Udm::ChildrenAttr<PICML::Property> Property_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, meta_Property_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, meta_Property_children); }

		static Uml::CompositionChildRole meta_ImplementationArtifact_children;
		Udm::ChildrenAttr<PICML::ImplementationArtifact> ImplementationArtifact_children() const { return Udm::ChildrenAttr<PICML::ImplementationArtifact>(impl, meta_ImplementationArtifact_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ImplementationArtifact, Pred> ImplementationArtifact_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationArtifact, Pred>(impl, meta_ImplementationArtifact_children); }

		Udm::ChildrenAttr<PICML::ImplementationArtifactReference> ImplementationArtifactReference_kind_children() const { return Udm::ChildrenAttr<PICML::ImplementationArtifactReference>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ImplementationArtifactReference, Pred> ImplementationArtifactReference_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationArtifactReference, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ArtifactDependsOn> ArtifactDependsOn_kind_children() const { return Udm::ChildrenAttr<PICML::ArtifactDependsOn>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ArtifactDependsOn, Pred> ArtifactDependsOn_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactDependsOn, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ArtifactDeployRequirement> ArtifactDeployRequirement_kind_children() const { return Udm::ChildrenAttr<PICML::ArtifactDeployRequirement>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ArtifactDeployRequirement, Pred> ArtifactDeployRequirement_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactDeployRequirement, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ArtifactExecParameter> ArtifactExecParameter_kind_children() const { return Udm::ChildrenAttr<PICML::ArtifactExecParameter>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ArtifactExecParameter, Pred> ArtifactExecParameter_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactExecParameter, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ArtifactInfoProperty> ArtifactInfoProperty_kind_children() const { return Udm::ChildrenAttr<PICML::ArtifactInfoProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ArtifactInfoProperty, Pred> ArtifactInfoProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ArtifactInfoProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ImplementationArtifact> ImplementationArtifact_kind_children() const { return Udm::ChildrenAttr<PICML::ImplementationArtifact>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ImplementationArtifact, Pred> ImplementationArtifact_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationArtifact, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::RequirementBase> RequirementBase_kind_children() const { return Udm::ChildrenAttr<PICML::RequirementBase>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::RequirementBase, Pred> RequirementBase_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RequirementBase, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Requirement> Requirement_kind_children() const { return Udm::ChildrenAttr<PICML::Requirement>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Requirement, Pred> Requirement_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Requirement, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Property> Property_kind_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_ImplementationArtifacts_parent;
		Udm::ParentAttr<PICML::ImplementationArtifacts> ImplementationArtifacts_parent() const { return Udm::ParentAttr<PICML::ImplementationArtifacts>(impl, meta_ImplementationArtifacts_parent); }

		Udm::ParentAttr<PICML::ImplementationArtifacts> parent() const { return Udm::ParentAttr<PICML::ImplementationArtifacts>(impl, Udm::NULLPARENTROLE); }
	};

	class  ArtifactExecParameter :  public MgaObject {
	 public:
		static Uml::Class meta;

		ArtifactExecParameter() { }
		ArtifactExecParameter(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ArtifactExecParameter(const ArtifactExecParameter &master) : MgaObject(master) { }
		static ArtifactExecParameter Cast(const Object &a) { return __Cast(a, meta); }

		static ArtifactExecParameter Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ArtifactExecParameter CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ArtifactExecParameter CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ArtifactExecParameter> Instances() { return Udm::InstantiatedAttr<PICML::ArtifactExecParameter>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ArtifactExecParameter, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ArtifactExecParameter, Pred>(impl);}

		Udm::DerivedAttr<PICML::ArtifactExecParameter> Derived() { return Udm::DerivedAttr<PICML::ArtifactExecParameter>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ArtifactExecParameter, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ArtifactExecParameter, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ArtifactExecParameter> Archetype() { return Udm::ArchetypeAttr<PICML::ArtifactExecParameter>(impl);}

		static Uml::CompositionParentRole meta_ArtifactContainer_parent;
		Udm::ParentAttr<PICML::ArtifactContainer> ArtifactContainer_parent() const { return Udm::ParentAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstArtifactExecParameter_end_;
		Udm::AssocEndAttr<PICML::Property> dstArtifactExecParameter_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstArtifactExecParameter_end_); }

		static Uml::AssociationRole meta_srcArtifactExecParameter_end_;
		Udm::AssocEndAttr<PICML::ImplementationArtifact> srcArtifactExecParameter_end() const { return Udm::AssocEndAttr<PICML::ImplementationArtifact>(impl, meta_srcArtifactExecParameter_end_); }

	};

	class  ArtifactInfoProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		ArtifactInfoProperty() { }
		ArtifactInfoProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ArtifactInfoProperty(const ArtifactInfoProperty &master) : MgaObject(master) { }
		static ArtifactInfoProperty Cast(const Object &a) { return __Cast(a, meta); }

		static ArtifactInfoProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ArtifactInfoProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ArtifactInfoProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ArtifactInfoProperty> Instances() { return Udm::InstantiatedAttr<PICML::ArtifactInfoProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ArtifactInfoProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ArtifactInfoProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::ArtifactInfoProperty> Derived() { return Udm::DerivedAttr<PICML::ArtifactInfoProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ArtifactInfoProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ArtifactInfoProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ArtifactInfoProperty> Archetype() { return Udm::ArchetypeAttr<PICML::ArtifactInfoProperty>(impl);}

		static Uml::CompositionParentRole meta_ArtifactContainer_parent;
		Udm::ParentAttr<PICML::ArtifactContainer> ArtifactContainer_parent() const { return Udm::ParentAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstArtifactInfoProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstArtifactInfoProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstArtifactInfoProperty_end_); }

		static Uml::AssociationRole meta_srcArtifactInfoProperty_end_;
		Udm::AssocEndAttr<PICML::ImplementationArtifact> srcArtifactInfoProperty_end() const { return Udm::AssocEndAttr<PICML::ImplementationArtifact>(impl, meta_srcArtifactInfoProperty_end_); }

	};

	class  ImplementationArtifact :  public MgaObject {
	 public:
		static Uml::Class meta;

		ImplementationArtifact() { }
		ImplementationArtifact(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ImplementationArtifact(const ImplementationArtifact &master) : MgaObject(master) { }
		static ImplementationArtifact Cast(const Object &a) { return __Cast(a, meta); }

		static ImplementationArtifact Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ImplementationArtifact CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ImplementationArtifact CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ImplementationArtifact> Instances() { return Udm::InstantiatedAttr<PICML::ImplementationArtifact>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ImplementationArtifact, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ImplementationArtifact, Pred>(impl);}

		Udm::DerivedAttr<PICML::ImplementationArtifact> Derived() { return Udm::DerivedAttr<PICML::ImplementationArtifact>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ImplementationArtifact, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ImplementationArtifact, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ImplementationArtifact> Archetype() { return Udm::ArchetypeAttr<PICML::ImplementationArtifact>(impl);}

		static Uml::AssociationRole meta_dstArtifactDependsOn, meta_dstArtifactDependsOn_rev;
		Udm::AClassAssocAttr<PICML::ArtifactDependsOn, PICML::ImplementationArtifactReference> dstArtifactDependsOn() const { return Udm::AClassAssocAttr<PICML::ArtifactDependsOn, PICML::ImplementationArtifactReference>(impl, meta_dstArtifactDependsOn, meta_dstArtifactDependsOn_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ArtifactDependsOn, PICML::ImplementationArtifactReference, Pred> dstArtifactDependsOn_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ArtifactDependsOn, PICML::ImplementationArtifactReference, Pred>(impl, meta_dstArtifactDependsOn, meta_dstArtifactDependsOn_rev); }

		static Uml::AssociationRole meta_referedbyImplementationArtifactReference;
		Udm::AssocAttr<PICML::ImplementationArtifactReference> referedbyImplementationArtifactReference() const { return Udm::AssocAttr<PICML::ImplementationArtifactReference>(impl, meta_referedbyImplementationArtifactReference); }
		template <class Pred> Udm::AssocAttr<PICML::ImplementationArtifactReference, Pred > referedbyImplementationArtifactReference_sorted(const Pred &) const { return Udm::AssocAttr<PICML::ImplementationArtifactReference, Pred>(impl, meta_referedbyImplementationArtifactReference); }

		static Uml::AssociationRole meta_dstArtifactDeployRequirement, meta_dstArtifactDeployRequirement_rev;
		Udm::AClassAssocAttr<PICML::ArtifactDeployRequirement, PICML::Requirement> dstArtifactDeployRequirement() const { return Udm::AClassAssocAttr<PICML::ArtifactDeployRequirement, PICML::Requirement>(impl, meta_dstArtifactDeployRequirement, meta_dstArtifactDeployRequirement_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ArtifactDeployRequirement, PICML::Requirement, Pred> dstArtifactDeployRequirement_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ArtifactDeployRequirement, PICML::Requirement, Pred>(impl, meta_dstArtifactDeployRequirement, meta_dstArtifactDeployRequirement_rev); }

		static Uml::AssociationRole meta_dstArtifactExecParameter, meta_dstArtifactExecParameter_rev;
		Udm::AClassAssocAttr<PICML::ArtifactExecParameter, PICML::Property> dstArtifactExecParameter() const { return Udm::AClassAssocAttr<PICML::ArtifactExecParameter, PICML::Property>(impl, meta_dstArtifactExecParameter, meta_dstArtifactExecParameter_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ArtifactExecParameter, PICML::Property, Pred> dstArtifactExecParameter_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ArtifactExecParameter, PICML::Property, Pred>(impl, meta_dstArtifactExecParameter, meta_dstArtifactExecParameter_rev); }

		static Uml::AssociationRole meta_dstArtifactInfoProperty, meta_dstArtifactInfoProperty_rev;
		Udm::AClassAssocAttr<PICML::ArtifactInfoProperty, PICML::Property> dstArtifactInfoProperty() const { return Udm::AClassAssocAttr<PICML::ArtifactInfoProperty, PICML::Property>(impl, meta_dstArtifactInfoProperty, meta_dstArtifactInfoProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ArtifactInfoProperty, PICML::Property, Pred> dstArtifactInfoProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ArtifactInfoProperty, PICML::Property, Pred>(impl, meta_dstArtifactInfoProperty, meta_dstArtifactInfoProperty_rev); }

		static Uml::CompositionParentRole meta_ArtifactContainer_parent;
		Udm::ParentAttr<PICML::ArtifactContainer> ArtifactContainer_parent() const { return Udm::ParentAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentType :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentType() { }
		ComponentType(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentType(const ComponentType &master) : MgaObject(master) { }
		static ComponentType Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentType Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentType CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentType CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentType> Instances() { return Udm::InstantiatedAttr<PICML::ComponentType>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentType, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentType, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentType> Derived() { return Udm::DerivedAttr<PICML::ComponentType>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentType, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentType, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentType> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentType>(impl);}

		static Uml::AssociationRole meta_dstComponentConfigProperty, meta_dstComponentConfigProperty_rev;
		Udm::AClassAssocAttr<PICML::ComponentConfigProperty, PICML::Property> dstComponentConfigProperty() const { return Udm::AClassAssocAttr<PICML::ComponentConfigProperty, PICML::Property>(impl, meta_dstComponentConfigProperty, meta_dstComponentConfigProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ComponentConfigProperty, PICML::Property, Pred> dstComponentConfigProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ComponentConfigProperty, PICML::Property, Pred>(impl, meta_dstComponentConfigProperty, meta_dstComponentConfigProperty_rev); }

		static Uml::AssociationRole meta_dstComponentProperty, meta_dstComponentProperty_rev;
		Udm::AClassAssocAttr<PICML::ComponentProperty, PICML::ComponentPropertyDescription> dstComponentProperty() const { return Udm::AClassAssocAttr<PICML::ComponentProperty, PICML::ComponentPropertyDescription>(impl, meta_dstComponentProperty, meta_dstComponentProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ComponentProperty, PICML::ComponentPropertyDescription, Pred> dstComponentProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ComponentProperty, PICML::ComponentPropertyDescription, Pred>(impl, meta_dstComponentProperty, meta_dstComponentProperty_rev); }

		static Uml::AssociationRole meta_dstComponentInfoProperty, meta_dstComponentInfoProperty_rev;
		Udm::AClassAssocAttr<PICML::ComponentInfoProperty, PICML::Property> dstComponentInfoProperty() const { return Udm::AClassAssocAttr<PICML::ComponentInfoProperty, PICML::Property>(impl, meta_dstComponentInfoProperty, meta_dstComponentInfoProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ComponentInfoProperty, PICML::Property, Pred> dstComponentInfoProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ComponentInfoProperty, PICML::Property, Pred>(impl, meta_dstComponentInfoProperty, meta_dstComponentInfoProperty_rev); }

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ComponentDef> ref() const { return Udm::PointerAttr<PICML::ComponentDef>(impl, meta_ref); }

		static Uml::AssociationRole meta_srcImplements, meta_srcImplements_rev;
		Udm::AClassAssocAttr<PICML::Implements, PICML::ComponentImplementation> srcImplements() const { return Udm::AClassAssocAttr<PICML::Implements, PICML::ComponentImplementation>(impl, meta_srcImplements, meta_srcImplements_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::Implements, PICML::ComponentImplementation, Pred> srcImplements_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::Implements, PICML::ComponentImplementation, Pred>(impl, meta_srcImplements, meta_srcImplements_rev); }

		static Uml::AssociationRole meta_srcPackageInterface, meta_srcPackageInterface_rev;
		Udm::AClassPointerAttr<PICML::PackageInterface, PICML::ComponentPackage> srcPackageInterface() const { return Udm::AClassPointerAttr<PICML::PackageInterface, PICML::ComponentPackage>(impl, meta_srcPackageInterface, meta_srcPackageInterface_rev); }

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		static Uml::CompositionParentRole meta_ComponentContainer_parent;
		Udm::ParentAttr<PICML::ComponentContainer> ComponentContainer_parent() const { return Udm::ParentAttr<PICML::ComponentContainer>(impl, meta_ComponentContainer_parent); }

		static Uml::CompositionParentRole meta_PackageContainer_parent;
		Udm::ParentAttr<PICML::PackageContainer> PackageContainer_parent() const { return Udm::ParentAttr<PICML::PackageContainer>(impl, meta_PackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentConfigProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentConfigProperty() { }
		ComponentConfigProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentConfigProperty(const ComponentConfigProperty &master) : MgaObject(master) { }
		static ComponentConfigProperty Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentConfigProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentConfigProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentConfigProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentConfigProperty> Instances() { return Udm::InstantiatedAttr<PICML::ComponentConfigProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentConfigProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentConfigProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentConfigProperty> Derived() { return Udm::DerivedAttr<PICML::ComponentConfigProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentConfigProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentConfigProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentConfigProperty> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentConfigProperty>(impl);}

		static Uml::CompositionParentRole meta_ComponentContainer_parent;
		Udm::ParentAttr<PICML::ComponentContainer> ComponentContainer_parent() const { return Udm::ParentAttr<PICML::ComponentContainer>(impl, meta_ComponentContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_srcComponentConfigProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentType> srcComponentConfigProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentType>(impl, meta_srcComponentConfigProperty_end_); }

		static Uml::AssociationRole meta_dstComponentConfigProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstComponentConfigProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstComponentConfigProperty_end_); }

	};

	class  ComponentInfoProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentInfoProperty() { }
		ComponentInfoProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentInfoProperty(const ComponentInfoProperty &master) : MgaObject(master) { }
		static ComponentInfoProperty Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentInfoProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentInfoProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentInfoProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentInfoProperty> Instances() { return Udm::InstantiatedAttr<PICML::ComponentInfoProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentInfoProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentInfoProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentInfoProperty> Derived() { return Udm::DerivedAttr<PICML::ComponentInfoProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentInfoProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentInfoProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentInfoProperty> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentInfoProperty>(impl);}

		static Uml::CompositionParentRole meta_ComponentContainer_parent;
		Udm::ParentAttr<PICML::ComponentContainer> ComponentContainer_parent() const { return Udm::ParentAttr<PICML::ComponentContainer>(impl, meta_ComponentContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_srcComponentInfoProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentType> srcComponentInfoProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentType>(impl, meta_srcComponentInfoProperty_end_); }

		static Uml::AssociationRole meta_dstComponentInfoProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstComponentInfoProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstComponentInfoProperty_end_); }

	};

	class  CommonPortAttrs :  virtual public MgaObject {
	 public:
		static Uml::Class meta;

		CommonPortAttrs() { }
		CommonPortAttrs(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		CommonPortAttrs(const CommonPortAttrs &master) : MgaObject(master) { }
		static CommonPortAttrs Cast(const Object &a) { return __Cast(a, meta); }

		static CommonPortAttrs Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		CommonPortAttrs CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		CommonPortAttrs CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<CommonPortAttrs> Instances() { return Udm::InstantiatedAttr<PICML::CommonPortAttrs>(impl);}
		template <class Pred> Udm::InstantiatedAttr<CommonPortAttrs, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::CommonPortAttrs, Pred>(impl);}

		Udm::DerivedAttr<PICML::CommonPortAttrs> Derived() { return Udm::DerivedAttr<PICML::CommonPortAttrs>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::CommonPortAttrs, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::CommonPortAttrs, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::CommonPortAttrs> Archetype() { return Udm::ArchetypeAttr<PICML::CommonPortAttrs>(impl);}

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentPropertyDescription :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentPropertyDescription() { }
		ComponentPropertyDescription(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentPropertyDescription(const ComponentPropertyDescription &master) : MgaObject(master) { }
		static ComponentPropertyDescription Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentPropertyDescription Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentPropertyDescription CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentPropertyDescription CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentPropertyDescription> Instances() { return Udm::InstantiatedAttr<PICML::ComponentPropertyDescription>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentPropertyDescription, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentPropertyDescription, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentPropertyDescription> Derived() { return Udm::DerivedAttr<PICML::ComponentPropertyDescription>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentPropertyDescription, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentPropertyDescription, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentPropertyDescription> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentPropertyDescription>(impl);}

		static Uml::AssociationRole meta_srcComponentProperty, meta_srcComponentProperty_rev;
		Udm::AClassAssocAttr<PICML::ComponentProperty, PICML::ComponentType> srcComponentProperty() const { return Udm::AClassAssocAttr<PICML::ComponentProperty, PICML::ComponentType>(impl, meta_srcComponentProperty, meta_srcComponentProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ComponentProperty, PICML::ComponentType, Pred> srcComponentProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ComponentProperty, PICML::ComponentType, Pred>(impl, meta_srcComponentProperty, meta_srcComponentProperty_rev); }

		static Uml::CompositionChildRole meta_DataType_child;
		Udm::ChildAttr<PICML::DataType> DataType_child() const { return Udm::ChildAttr<PICML::DataType>(impl, meta_DataType_child); }

		Udm::ChildrenAttr<PICML::DataType> DataType_kind_children() const { return Udm::ChildrenAttr<PICML::DataType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::DataType, Pred> DataType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::DataType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_ComponentContainer_parent;
		Udm::ParentAttr<PICML::ComponentContainer> ComponentContainer_parent() const { return Udm::ParentAttr<PICML::ComponentContainer>(impl, meta_ComponentContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentProperty() { }
		ComponentProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentProperty(const ComponentProperty &master) : MgaObject(master) { }
		static ComponentProperty Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentProperty> Instances() { return Udm::InstantiatedAttr<PICML::ComponentProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentProperty> Derived() { return Udm::DerivedAttr<PICML::ComponentProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentProperty> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentProperty>(impl);}

		static Uml::CompositionParentRole meta_ComponentContainer_parent;
		Udm::ParentAttr<PICML::ComponentContainer> ComponentContainer_parent() const { return Udm::ParentAttr<PICML::ComponentContainer>(impl, meta_ComponentContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_srcComponentProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentType> srcComponentProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentType>(impl, meta_srcComponentProperty_end_); }

		static Uml::AssociationRole meta_dstComponentProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentPropertyDescription> dstComponentProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentPropertyDescription>(impl, meta_dstComponentProperty_end_); }

	};

	class  ComponentContainer :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentContainer() { }
		ComponentContainer(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentContainer(const ComponentContainer &master) : MgaObject(master) { }
		static ComponentContainer Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentContainer Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentContainer CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentContainer CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentContainer> Instances() { return Udm::InstantiatedAttr<PICML::ComponentContainer>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentContainer, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentContainer, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentContainer> Derived() { return Udm::DerivedAttr<PICML::ComponentContainer>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentContainer, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentContainer, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentContainer> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentContainer>(impl);}

		static Uml::CompositionChildRole meta_Property_children;
		Udm::ChildrenAttr<PICML::Property> Property_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, meta_Property_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, meta_Property_children); }

		static Uml::CompositionChildRole meta_ComponentType_child;
		Udm::ChildAttr<PICML::ComponentType> ComponentType_child() const { return Udm::ChildAttr<PICML::ComponentType>(impl, meta_ComponentType_child); }

		static Uml::CompositionChildRole meta_ComponentConfigProperty_children;
		Udm::ChildrenAttr<PICML::ComponentConfigProperty> ComponentConfigProperty_children() const { return Udm::ChildrenAttr<PICML::ComponentConfigProperty>(impl, meta_ComponentConfigProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentConfigProperty, Pred> ComponentConfigProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentConfigProperty, Pred>(impl, meta_ComponentConfigProperty_children); }

		static Uml::CompositionChildRole meta_ComponentInfoProperty_children;
		Udm::ChildrenAttr<PICML::ComponentInfoProperty> ComponentInfoProperty_children() const { return Udm::ChildrenAttr<PICML::ComponentInfoProperty>(impl, meta_ComponentInfoProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentInfoProperty, Pred> ComponentInfoProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentInfoProperty, Pred>(impl, meta_ComponentInfoProperty_children); }

		static Uml::CompositionChildRole meta_ComponentProperty_children;
		Udm::ChildrenAttr<PICML::ComponentProperty> ComponentProperty_children() const { return Udm::ChildrenAttr<PICML::ComponentProperty>(impl, meta_ComponentProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentProperty, Pred> ComponentProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentProperty, Pred>(impl, meta_ComponentProperty_children); }

		static Uml::CompositionChildRole meta_ComponentPropertyDescription_children;
		Udm::ChildrenAttr<PICML::ComponentPropertyDescription> ComponentPropertyDescription_children() const { return Udm::ChildrenAttr<PICML::ComponentPropertyDescription>(impl, meta_ComponentPropertyDescription_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentPropertyDescription, Pred> ComponentPropertyDescription_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPropertyDescription, Pred>(impl, meta_ComponentPropertyDescription_children); }

		Udm::ChildrenAttr<PICML::ComponentType> ComponentType_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentType, Pred> ComponentType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentConfigProperty> ComponentConfigProperty_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentConfigProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentConfigProperty, Pred> ComponentConfigProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentConfigProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentInfoProperty> ComponentInfoProperty_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentInfoProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentInfoProperty, Pred> ComponentInfoProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentInfoProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentPropertyDescription> ComponentPropertyDescription_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentPropertyDescription>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentPropertyDescription, Pred> ComponentPropertyDescription_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPropertyDescription, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentProperty> ComponentProperty_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentProperty, Pred> ComponentProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Property> Property_kind_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_ComponentTypes_parent;
		Udm::ParentAttr<PICML::ComponentTypes> ComponentTypes_parent() const { return Udm::ParentAttr<PICML::ComponentTypes>(impl, meta_ComponentTypes_parent); }

		Udm::ParentAttr<PICML::ComponentTypes> parent() const { return Udm::ParentAttr<PICML::ComponentTypes>(impl, Udm::NULLPARENTROLE); }
	};

	class  ImplementationCapability :  public MgaObject {
	 public:
		static Uml::Class meta;

		ImplementationCapability() { }
		ImplementationCapability(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ImplementationCapability(const ImplementationCapability &master) : MgaObject(master) { }
		static ImplementationCapability Cast(const Object &a) { return __Cast(a, meta); }

		static ImplementationCapability Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ImplementationCapability CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ImplementationCapability CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ImplementationCapability> Instances() { return Udm::InstantiatedAttr<PICML::ImplementationCapability>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ImplementationCapability, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ImplementationCapability, Pred>(impl);}

		Udm::DerivedAttr<PICML::ImplementationCapability> Derived() { return Udm::DerivedAttr<PICML::ImplementationCapability>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ImplementationCapability, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ImplementationCapability, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ImplementationCapability> Archetype() { return Udm::ArchetypeAttr<PICML::ImplementationCapability>(impl);}

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstImplementationCapability_end_;
		Udm::AssocEndAttr<PICML::Capability> dstImplementationCapability_end() const { return Udm::AssocEndAttr<PICML::Capability>(impl, meta_dstImplementationCapability_end_); }

		static Uml::AssociationRole meta_srcImplementationCapability_end_;
		Udm::AssocEndAttr<PICML::ComponentImplementation> srcImplementationCapability_end() const { return Udm::AssocEndAttr<PICML::ComponentImplementation>(impl, meta_srcImplementationCapability_end_); }

	};

	class  ImplementationDependsOn :  public MgaObject {
	 public:
		static Uml::Class meta;

		ImplementationDependsOn() { }
		ImplementationDependsOn(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ImplementationDependsOn(const ImplementationDependsOn &master) : MgaObject(master) { }
		static ImplementationDependsOn Cast(const Object &a) { return __Cast(a, meta); }

		static ImplementationDependsOn Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ImplementationDependsOn CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ImplementationDependsOn CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ImplementationDependsOn> Instances() { return Udm::InstantiatedAttr<PICML::ImplementationDependsOn>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ImplementationDependsOn, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ImplementationDependsOn, Pred>(impl);}

		Udm::DerivedAttr<PICML::ImplementationDependsOn> Derived() { return Udm::DerivedAttr<PICML::ImplementationDependsOn>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ImplementationDependsOn, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ImplementationDependsOn, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ImplementationDependsOn> Archetype() { return Udm::ArchetypeAttr<PICML::ImplementationDependsOn>(impl);}

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstImplementationDependsOn_end_;
		Udm::AssocEndAttr<PICML::ImplementationDependency> dstImplementationDependsOn_end() const { return Udm::AssocEndAttr<PICML::ImplementationDependency>(impl, meta_dstImplementationDependsOn_end_); }

		static Uml::AssociationRole meta_srcImplementationDependsOn_end_;
		Udm::AssocEndAttr<PICML::ComponentImplementation> srcImplementationDependsOn_end() const { return Udm::AssocEndAttr<PICML::ComponentImplementation>(impl, meta_srcImplementationDependsOn_end_); }

	};

	class  Implements :  public MgaObject {
	 public:
		static Uml::Class meta;

		Implements() { }
		Implements(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Implements(const Implements &master) : MgaObject(master) { }
		static Implements Cast(const Object &a) { return __Cast(a, meta); }

		static Implements Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Implements CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Implements CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Implements> Instances() { return Udm::InstantiatedAttr<PICML::Implements>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Implements, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Implements, Pred>(impl);}

		Udm::DerivedAttr<PICML::Implements> Derived() { return Udm::DerivedAttr<PICML::Implements>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Implements, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Implements, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Implements> Archetype() { return Udm::ArchetypeAttr<PICML::Implements>(impl);}

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstImplements_end_;
		Udm::AssocEndAttr<PICML::ComponentType> dstImplements_end() const { return Udm::AssocEndAttr<PICML::ComponentType>(impl, meta_dstImplements_end_); }

		static Uml::AssociationRole meta_srcImplements_end_;
		Udm::AssocEndAttr<PICML::ComponentImplementation> srcImplements_end() const { return Udm::AssocEndAttr<PICML::ComponentImplementation>(impl, meta_srcImplements_end_); }

	};

	class  ComponentImplementationReference :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentImplementationReference() { }
		ComponentImplementationReference(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentImplementationReference(const ComponentImplementationReference &master) : MgaObject(master) { }
		static ComponentImplementationReference Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentImplementationReference Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentImplementationReference CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentImplementationReference CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentImplementationReference> Instances() { return Udm::InstantiatedAttr<PICML::ComponentImplementationReference>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentImplementationReference, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentImplementationReference, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentImplementationReference> Derived() { return Udm::DerivedAttr<PICML::ComponentImplementationReference>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentImplementationReference, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentImplementationReference, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentImplementationReference> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentImplementationReference>(impl);}

		static Uml::AssociationRole meta_srcPackageImplementations, meta_srcPackageImplementations_rev;
		Udm::AClassAssocAttr<PICML::PackageImplementations, PICML::ComponentPackage> srcPackageImplementations() const { return Udm::AClassAssocAttr<PICML::PackageImplementations, PICML::ComponentPackage>(impl, meta_srcPackageImplementations, meta_srcPackageImplementations_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageImplementations, PICML::ComponentPackage, Pred> srcPackageImplementations_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageImplementations, PICML::ComponentPackage, Pred>(impl, meta_srcPackageImplementations, meta_srcPackageImplementations_rev); }

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ComponentImplementation> ref() const { return Udm::PointerAttr<PICML::ComponentImplementation>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_PackageContainer_parent;
		Udm::ParentAttr<PICML::PackageContainer> PackageContainer_parent() const { return Udm::ParentAttr<PICML::PackageContainer>(impl, meta_PackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ConfigProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		ConfigProperty() { }
		ConfigProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ConfigProperty(const ConfigProperty &master) : MgaObject(master) { }
		static ConfigProperty Cast(const Object &a) { return __Cast(a, meta); }

		static ConfigProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ConfigProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ConfigProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ConfigProperty> Instances() { return Udm::InstantiatedAttr<PICML::ConfigProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ConfigProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ConfigProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::ConfigProperty> Derived() { return Udm::DerivedAttr<PICML::ConfigProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ConfigProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ConfigProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ConfigProperty> Archetype() { return Udm::ArchetypeAttr<PICML::ConfigProperty>(impl);}

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstConfigProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstConfigProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstConfigProperty_end_); }

		static Uml::AssociationRole meta_srcConfigProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentImplementation> srcConfigProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentImplementation>(impl, meta_srcConfigProperty_end_); }

	};

	class  InfoProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		InfoProperty() { }
		InfoProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		InfoProperty(const InfoProperty &master) : MgaObject(master) { }
		static InfoProperty Cast(const Object &a) { return __Cast(a, meta); }

		static InfoProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		InfoProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		InfoProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<InfoProperty> Instances() { return Udm::InstantiatedAttr<PICML::InfoProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<InfoProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::InfoProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::InfoProperty> Derived() { return Udm::DerivedAttr<PICML::InfoProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::InfoProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::InfoProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::InfoProperty> Archetype() { return Udm::ArchetypeAttr<PICML::InfoProperty>(impl);}

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstInfoProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstInfoProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstInfoProperty_end_); }

		static Uml::AssociationRole meta_srcInfoProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentImplementation> srcInfoProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentImplementation>(impl, meta_srcInfoProperty_end_); }

	};

	class  MonolithprimaryArtifact :  public MgaObject {
	 public:
		static Uml::Class meta;

		MonolithprimaryArtifact() { }
		MonolithprimaryArtifact(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		MonolithprimaryArtifact(const MonolithprimaryArtifact &master) : MgaObject(master) { }
		static MonolithprimaryArtifact Cast(const Object &a) { return __Cast(a, meta); }

		static MonolithprimaryArtifact Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		MonolithprimaryArtifact CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		MonolithprimaryArtifact CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<MonolithprimaryArtifact> Instances() { return Udm::InstantiatedAttr<PICML::MonolithprimaryArtifact>(impl);}
		template <class Pred> Udm::InstantiatedAttr<MonolithprimaryArtifact, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::MonolithprimaryArtifact, Pred>(impl);}

		Udm::DerivedAttr<PICML::MonolithprimaryArtifact> Derived() { return Udm::DerivedAttr<PICML::MonolithprimaryArtifact>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::MonolithprimaryArtifact, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::MonolithprimaryArtifact, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::MonolithprimaryArtifact> Archetype() { return Udm::ArchetypeAttr<PICML::MonolithprimaryArtifact>(impl);}

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstMonolithprimaryArtifact_end_;
		Udm::AssocEndAttr<PICML::ImplementationArtifactReference> dstMonolithprimaryArtifact_end() const { return Udm::AssocEndAttr<PICML::ImplementationArtifactReference>(impl, meta_dstMonolithprimaryArtifact_end_); }

		static Uml::AssociationRole meta_srcMonolithprimaryArtifact_end_;
		Udm::AssocEndAttr<PICML::MonolithicImplementation> srcMonolithprimaryArtifact_end() const { return Udm::AssocEndAttr<PICML::MonolithicImplementation>(impl, meta_srcMonolithprimaryArtifact_end_); }

	};

	class  MonolithDeployRequirement :  public MgaObject {
	 public:
		static Uml::Class meta;

		MonolithDeployRequirement() { }
		MonolithDeployRequirement(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		MonolithDeployRequirement(const MonolithDeployRequirement &master) : MgaObject(master) { }
		static MonolithDeployRequirement Cast(const Object &a) { return __Cast(a, meta); }

		static MonolithDeployRequirement Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		MonolithDeployRequirement CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		MonolithDeployRequirement CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<MonolithDeployRequirement> Instances() { return Udm::InstantiatedAttr<PICML::MonolithDeployRequirement>(impl);}
		template <class Pred> Udm::InstantiatedAttr<MonolithDeployRequirement, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::MonolithDeployRequirement, Pred>(impl);}

		Udm::DerivedAttr<PICML::MonolithDeployRequirement> Derived() { return Udm::DerivedAttr<PICML::MonolithDeployRequirement>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::MonolithDeployRequirement, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::MonolithDeployRequirement, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::MonolithDeployRequirement> Archetype() { return Udm::ArchetypeAttr<PICML::MonolithDeployRequirement>(impl);}

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstMonolithDeployRequirement_end_;
		Udm::AssocEndAttr<PICML::ImplementationRequirement> dstMonolithDeployRequirement_end() const { return Udm::AssocEndAttr<PICML::ImplementationRequirement>(impl, meta_dstMonolithDeployRequirement_end_); }

		static Uml::AssociationRole meta_srcMonolithDeployRequirement_end_;
		Udm::AssocEndAttr<PICML::MonolithicImplementation> srcMonolithDeployRequirement_end() const { return Udm::AssocEndAttr<PICML::MonolithicImplementation>(impl, meta_srcMonolithDeployRequirement_end_); }

	};

	class  ComponentImplementation :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentImplementation() { }
		ComponentImplementation(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentImplementation(const ComponentImplementation &master) : MgaObject(master) { }
		static ComponentImplementation Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentImplementation Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentImplementation CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentImplementation CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentImplementation> Instances() { return Udm::InstantiatedAttr<PICML::ComponentImplementation>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentImplementation, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentImplementation, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentImplementation> Derived() { return Udm::DerivedAttr<PICML::ComponentImplementation>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentImplementation, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentImplementation, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentImplementation> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentImplementation>(impl);}

		static Uml::AssociationRole meta_dstImplements, meta_dstImplements_rev;
		Udm::AClassAssocAttr<PICML::Implements, PICML::ComponentType> dstImplements() const { return Udm::AClassAssocAttr<PICML::Implements, PICML::ComponentType>(impl, meta_dstImplements, meta_dstImplements_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::Implements, PICML::ComponentType, Pred> dstImplements_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::Implements, PICML::ComponentType, Pred>(impl, meta_dstImplements, meta_dstImplements_rev); }

		static Uml::AssociationRole meta_dstImplementationCapability, meta_dstImplementationCapability_rev;
		Udm::AClassAssocAttr<PICML::ImplementationCapability, PICML::Capability> dstImplementationCapability() const { return Udm::AClassAssocAttr<PICML::ImplementationCapability, PICML::Capability>(impl, meta_dstImplementationCapability, meta_dstImplementationCapability_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ImplementationCapability, PICML::Capability, Pred> dstImplementationCapability_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ImplementationCapability, PICML::Capability, Pred>(impl, meta_dstImplementationCapability, meta_dstImplementationCapability_rev); }

		static Uml::AssociationRole meta_dstImplementationDependsOn, meta_dstImplementationDependsOn_rev;
		Udm::AClassAssocAttr<PICML::ImplementationDependsOn, PICML::ImplementationDependency> dstImplementationDependsOn() const { return Udm::AClassAssocAttr<PICML::ImplementationDependsOn, PICML::ImplementationDependency>(impl, meta_dstImplementationDependsOn, meta_dstImplementationDependsOn_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ImplementationDependsOn, PICML::ImplementationDependency, Pred> dstImplementationDependsOn_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ImplementationDependsOn, PICML::ImplementationDependency, Pred>(impl, meta_dstImplementationDependsOn, meta_dstImplementationDependsOn_rev); }

		static Uml::AssociationRole meta_referedbyComponentImplementationReference;
		Udm::AssocAttr<PICML::ComponentImplementationReference> referedbyComponentImplementationReference() const { return Udm::AssocAttr<PICML::ComponentImplementationReference>(impl, meta_referedbyComponentImplementationReference); }
		template <class Pred> Udm::AssocAttr<PICML::ComponentImplementationReference, Pred > referedbyComponentImplementationReference_sorted(const Pred &) const { return Udm::AssocAttr<PICML::ComponentImplementationReference, Pred>(impl, meta_referedbyComponentImplementationReference); }

		static Uml::AssociationRole meta_dstConfigProperty, meta_dstConfigProperty_rev;
		Udm::AClassAssocAttr<PICML::ConfigProperty, PICML::Property> dstConfigProperty() const { return Udm::AClassAssocAttr<PICML::ConfigProperty, PICML::Property>(impl, meta_dstConfigProperty, meta_dstConfigProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ConfigProperty, PICML::Property, Pred> dstConfigProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ConfigProperty, PICML::Property, Pred>(impl, meta_dstConfigProperty, meta_dstConfigProperty_rev); }

		static Uml::AssociationRole meta_dstInfoProperty, meta_dstInfoProperty_rev;
		Udm::AClassAssocAttr<PICML::InfoProperty, PICML::Property> dstInfoProperty() const { return Udm::AClassAssocAttr<PICML::InfoProperty, PICML::Property>(impl, meta_dstInfoProperty, meta_dstInfoProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::InfoProperty, PICML::Property, Pred> dstInfoProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::InfoProperty, PICML::Property, Pred>(impl, meta_dstInfoProperty, meta_dstInfoProperty_rev); }

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentImplementationContainer :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentImplementationContainer() { }
		ComponentImplementationContainer(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentImplementationContainer(const ComponentImplementationContainer &master) : MgaObject(master) { }
		static ComponentImplementationContainer Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentImplementationContainer Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentImplementationContainer CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentImplementationContainer CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentImplementationContainer> Instances() { return Udm::InstantiatedAttr<PICML::ComponentImplementationContainer>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentImplementationContainer, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentImplementationContainer, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentImplementationContainer> Derived() { return Udm::DerivedAttr<PICML::ComponentImplementationContainer>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentImplementationContainer, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentImplementationContainer, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentImplementationContainer> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentImplementationContainer>(impl);}

		static Uml::CompositionChildRole meta_ComponentImplementation_child;
		Udm::ChildAttr<PICML::ComponentImplementation> ComponentImplementation_child() const { return Udm::ChildAttr<PICML::ComponentImplementation>(impl, meta_ComponentImplementation_child); }

		static Uml::CompositionChildRole meta_ImplementationRequirement_children;
		Udm::ChildrenAttr<PICML::ImplementationRequirement> ImplementationRequirement_children() const { return Udm::ChildrenAttr<PICML::ImplementationRequirement>(impl, meta_ImplementationRequirement_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ImplementationRequirement, Pred> ImplementationRequirement_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationRequirement, Pred>(impl, meta_ImplementationRequirement_children); }

		static Uml::CompositionChildRole meta_ImplementationDependsOn_children;
		Udm::ChildrenAttr<PICML::ImplementationDependsOn> ImplementationDependsOn_children() const { return Udm::ChildrenAttr<PICML::ImplementationDependsOn>(impl, meta_ImplementationDependsOn_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ImplementationDependsOn, Pred> ImplementationDependsOn_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationDependsOn, Pred>(impl, meta_ImplementationDependsOn_children); }

		static Uml::CompositionChildRole meta_Implements_children;
		Udm::ChildrenAttr<PICML::Implements> Implements_children() const { return Udm::ChildrenAttr<PICML::Implements>(impl, meta_Implements_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Implements, Pred> Implements_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Implements, Pred>(impl, meta_Implements_children); }

		static Uml::CompositionChildRole meta_ComponentType_children;
		Udm::ChildrenAttr<PICML::ComponentType> ComponentType_children() const { return Udm::ChildrenAttr<PICML::ComponentType>(impl, meta_ComponentType_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentType, Pred> ComponentType_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentType, Pred>(impl, meta_ComponentType_children); }

		static Uml::CompositionChildRole meta_MonolithDeployRequirement_children;
		Udm::ChildrenAttr<PICML::MonolithDeployRequirement> MonolithDeployRequirement_children() const { return Udm::ChildrenAttr<PICML::MonolithDeployRequirement>(impl, meta_MonolithDeployRequirement_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::MonolithDeployRequirement, Pred> MonolithDeployRequirement_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MonolithDeployRequirement, Pred>(impl, meta_MonolithDeployRequirement_children); }

		static Uml::CompositionChildRole meta_MonolithprimaryArtifact_children;
		Udm::ChildrenAttr<PICML::MonolithprimaryArtifact> MonolithprimaryArtifact_children() const { return Udm::ChildrenAttr<PICML::MonolithprimaryArtifact>(impl, meta_MonolithprimaryArtifact_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::MonolithprimaryArtifact, Pred> MonolithprimaryArtifact_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MonolithprimaryArtifact, Pred>(impl, meta_MonolithprimaryArtifact_children); }

		static Uml::CompositionChildRole meta_MonolithExecParameter_children;
		Udm::ChildrenAttr<PICML::MonolithExecParameter> MonolithExecParameter_children() const { return Udm::ChildrenAttr<PICML::MonolithExecParameter>(impl, meta_MonolithExecParameter_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::MonolithExecParameter, Pred> MonolithExecParameter_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MonolithExecParameter, Pred>(impl, meta_MonolithExecParameter_children); }

		static Uml::CompositionChildRole meta_ImplementationDependency_children;
		Udm::ChildrenAttr<PICML::ImplementationDependency> ImplementationDependency_children() const { return Udm::ChildrenAttr<PICML::ImplementationDependency>(impl, meta_ImplementationDependency_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ImplementationDependency, Pred> ImplementationDependency_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationDependency, Pred>(impl, meta_ImplementationDependency_children); }

		static Uml::CompositionChildRole meta_ConfigProperty_children;
		Udm::ChildrenAttr<PICML::ConfigProperty> ConfigProperty_children() const { return Udm::ChildrenAttr<PICML::ConfigProperty>(impl, meta_ConfigProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ConfigProperty, Pred> ConfigProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConfigProperty, Pred>(impl, meta_ConfigProperty_children); }

		static Uml::CompositionChildRole meta_ImplementationCapability_children;
		Udm::ChildrenAttr<PICML::ImplementationCapability> ImplementationCapability_children() const { return Udm::ChildrenAttr<PICML::ImplementationCapability>(impl, meta_ImplementationCapability_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ImplementationCapability, Pred> ImplementationCapability_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationCapability, Pred>(impl, meta_ImplementationCapability_children); }

		static Uml::CompositionChildRole meta_InfoProperty_children;
		Udm::ChildrenAttr<PICML::InfoProperty> InfoProperty_children() const { return Udm::ChildrenAttr<PICML::InfoProperty>(impl, meta_InfoProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::InfoProperty, Pred> InfoProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InfoProperty, Pred>(impl, meta_InfoProperty_children); }

		static Uml::CompositionChildRole meta_Property_children;
		Udm::ChildrenAttr<PICML::Property> Property_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, meta_Property_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, meta_Property_children); }

		static Uml::CompositionChildRole meta_Capability_children;
		Udm::ChildrenAttr<PICML::Capability> Capability_children() const { return Udm::ChildrenAttr<PICML::Capability>(impl, meta_Capability_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Capability, Pred> Capability_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Capability, Pred>(impl, meta_Capability_children); }

		Udm::ChildrenAttr<PICML::ComponentType> ComponentType_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentType, Pred> ComponentType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ImplementationCapability> ImplementationCapability_kind_children() const { return Udm::ChildrenAttr<PICML::ImplementationCapability>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ImplementationCapability, Pred> ImplementationCapability_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationCapability, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ImplementationDependsOn> ImplementationDependsOn_kind_children() const { return Udm::ChildrenAttr<PICML::ImplementationDependsOn>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ImplementationDependsOn, Pred> ImplementationDependsOn_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationDependsOn, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Implements> Implements_kind_children() const { return Udm::ChildrenAttr<PICML::Implements>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Implements, Pred> Implements_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Implements, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ConfigProperty> ConfigProperty_kind_children() const { return Udm::ChildrenAttr<PICML::ConfigProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ConfigProperty, Pred> ConfigProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConfigProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::InfoProperty> InfoProperty_kind_children() const { return Udm::ChildrenAttr<PICML::InfoProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::InfoProperty, Pred> InfoProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InfoProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MonolithprimaryArtifact> MonolithprimaryArtifact_kind_children() const { return Udm::ChildrenAttr<PICML::MonolithprimaryArtifact>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MonolithprimaryArtifact, Pred> MonolithprimaryArtifact_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MonolithprimaryArtifact, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MonolithDeployRequirement> MonolithDeployRequirement_kind_children() const { return Udm::ChildrenAttr<PICML::MonolithDeployRequirement>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MonolithDeployRequirement, Pred> MonolithDeployRequirement_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MonolithDeployRequirement, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentImplementation> ComponentImplementation_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentImplementation>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentImplementation, Pred> ComponentImplementation_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentImplementation, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MonolithExecParameter> MonolithExecParameter_kind_children() const { return Udm::ChildrenAttr<PICML::MonolithExecParameter>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MonolithExecParameter, Pred> MonolithExecParameter_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MonolithExecParameter, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MonolithicImplementation> MonolithicImplementation_kind_children() const { return Udm::ChildrenAttr<PICML::MonolithicImplementation>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MonolithicImplementation, Pred> MonolithicImplementation_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MonolithicImplementation, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::RequirementBase> RequirementBase_kind_children() const { return Udm::ChildrenAttr<PICML::RequirementBase>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::RequirementBase, Pred> RequirementBase_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RequirementBase, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ImplementationRequirement> ImplementationRequirement_kind_children() const { return Udm::ChildrenAttr<PICML::ImplementationRequirement>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ImplementationRequirement, Pred> ImplementationRequirement_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationRequirement, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ImplementationDependency> ImplementationDependency_kind_children() const { return Udm::ChildrenAttr<PICML::ImplementationDependency>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ImplementationDependency, Pred> ImplementationDependency_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ImplementationDependency, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Property> Property_kind_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::RequirementSatisfier> RequirementSatisfier_kind_children() const { return Udm::ChildrenAttr<PICML::RequirementSatisfier>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::RequirementSatisfier, Pred> RequirementSatisfier_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RequirementSatisfier, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Capability> Capability_kind_children() const { return Udm::ChildrenAttr<PICML::Capability>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Capability, Pred> Capability_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Capability, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentAssembly> ComponentAssembly_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentAssembly>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentAssembly, Pred> ComponentAssembly_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentAssembly, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_ComponentImplementations_parent;
		Udm::ParentAttr<PICML::ComponentImplementations> ComponentImplementations_parent() const { return Udm::ParentAttr<PICML::ComponentImplementations>(impl, meta_ComponentImplementations_parent); }

		Udm::ParentAttr<PICML::ComponentImplementations> parent() const { return Udm::ParentAttr<PICML::ComponentImplementations>(impl, Udm::NULLPARENTROLE); }
	};

	class  MonolithExecParameter :  public MgaObject {
	 public:
		static Uml::Class meta;

		MonolithExecParameter() { }
		MonolithExecParameter(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		MonolithExecParameter(const MonolithExecParameter &master) : MgaObject(master) { }
		static MonolithExecParameter Cast(const Object &a) { return __Cast(a, meta); }

		static MonolithExecParameter Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		MonolithExecParameter CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		MonolithExecParameter CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<MonolithExecParameter> Instances() { return Udm::InstantiatedAttr<PICML::MonolithExecParameter>(impl);}
		template <class Pred> Udm::InstantiatedAttr<MonolithExecParameter, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::MonolithExecParameter, Pred>(impl);}

		Udm::DerivedAttr<PICML::MonolithExecParameter> Derived() { return Udm::DerivedAttr<PICML::MonolithExecParameter>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::MonolithExecParameter, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::MonolithExecParameter, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::MonolithExecParameter> Archetype() { return Udm::ArchetypeAttr<PICML::MonolithExecParameter>(impl);}

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstMonolithExecParameter_end_;
		Udm::AssocEndAttr<PICML::Property> dstMonolithExecParameter_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstMonolithExecParameter_end_); }

		static Uml::AssociationRole meta_srcMonolithExecParameter_end_;
		Udm::AssocEndAttr<PICML::MonolithicImplementation> srcMonolithExecParameter_end() const { return Udm::AssocEndAttr<PICML::MonolithicImplementation>(impl, meta_srcMonolithExecParameter_end_); }

	};

	class  MonolithicImplementation :  public ComponentImplementation {
	 public:
		static Uml::Class meta;

		MonolithicImplementation() { }
		MonolithicImplementation(Udm::ObjectImpl *impl) : ComponentImplementation(impl) { }
		MonolithicImplementation(const MonolithicImplementation &master) : ComponentImplementation(master) { }
		static MonolithicImplementation Cast(const Object &a) { return __Cast(a, meta); }

		static MonolithicImplementation Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		MonolithicImplementation CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		MonolithicImplementation CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<MonolithicImplementation> Instances() { return Udm::InstantiatedAttr<PICML::MonolithicImplementation>(impl);}
		template <class Pred> Udm::InstantiatedAttr<MonolithicImplementation, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::MonolithicImplementation, Pred>(impl);}

		Udm::DerivedAttr<PICML::MonolithicImplementation> Derived() { return Udm::DerivedAttr<PICML::MonolithicImplementation>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::MonolithicImplementation, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::MonolithicImplementation, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::MonolithicImplementation> Archetype() { return Udm::ArchetypeAttr<PICML::MonolithicImplementation>(impl);}

		static Uml::AssociationRole meta_dstMonolithprimaryArtifact, meta_dstMonolithprimaryArtifact_rev;
		Udm::AClassAssocAttr<PICML::MonolithprimaryArtifact, PICML::ImplementationArtifactReference> dstMonolithprimaryArtifact() const { return Udm::AClassAssocAttr<PICML::MonolithprimaryArtifact, PICML::ImplementationArtifactReference>(impl, meta_dstMonolithprimaryArtifact, meta_dstMonolithprimaryArtifact_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::MonolithprimaryArtifact, PICML::ImplementationArtifactReference, Pred> dstMonolithprimaryArtifact_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::MonolithprimaryArtifact, PICML::ImplementationArtifactReference, Pred>(impl, meta_dstMonolithprimaryArtifact, meta_dstMonolithprimaryArtifact_rev); }

		static Uml::AssociationRole meta_dstMonolithDeployRequirement, meta_dstMonolithDeployRequirement_rev;
		Udm::AClassAssocAttr<PICML::MonolithDeployRequirement, PICML::ImplementationRequirement> dstMonolithDeployRequirement() const { return Udm::AClassAssocAttr<PICML::MonolithDeployRequirement, PICML::ImplementationRequirement>(impl, meta_dstMonolithDeployRequirement, meta_dstMonolithDeployRequirement_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::MonolithDeployRequirement, PICML::ImplementationRequirement, Pred> dstMonolithDeployRequirement_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::MonolithDeployRequirement, PICML::ImplementationRequirement, Pred>(impl, meta_dstMonolithDeployRequirement, meta_dstMonolithDeployRequirement_rev); }

		static Uml::AssociationRole meta_dstMonolithExecParameter, meta_dstMonolithExecParameter_rev;
		Udm::AClassAssocAttr<PICML::MonolithExecParameter, PICML::Property> dstMonolithExecParameter() const { return Udm::AClassAssocAttr<PICML::MonolithExecParameter, PICML::Property>(impl, meta_dstMonolithExecParameter, meta_dstMonolithExecParameter_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::MonolithExecParameter, PICML::Property, Pred> dstMonolithExecParameter_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::MonolithExecParameter, PICML::Property, Pred>(impl, meta_dstMonolithExecParameter, meta_dstMonolithExecParameter_rev); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  RequirementBase :  public MgaObject {
	 public:
		static Uml::Class meta;

		RequirementBase() { }
		RequirementBase(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		RequirementBase(const RequirementBase &master) : MgaObject(master) { }
		static RequirementBase Cast(const Object &a) { return __Cast(a, meta); }

		static RequirementBase Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RequirementBase CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RequirementBase CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RequirementBase> Instances() { return Udm::InstantiatedAttr<PICML::RequirementBase>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RequirementBase, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::RequirementBase, Pred>(impl);}

		Udm::DerivedAttr<PICML::RequirementBase> Derived() { return Udm::DerivedAttr<PICML::RequirementBase>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::RequirementBase, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::RequirementBase, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::RequirementBase> Archetype() { return Udm::ArchetypeAttr<PICML::RequirementBase>(impl);}

		static Uml::CompositionChildRole meta_Property_children;
		Udm::ChildrenAttr<PICML::Property> Property_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, meta_Property_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, meta_Property_children); }

		Udm::ChildrenAttr<PICML::Property> Property_kind_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  ImplementationRequirement :  public RequirementBase {
	 public:
		static Uml::Class meta;

		ImplementationRequirement() { }
		ImplementationRequirement(Udm::ObjectImpl *impl) : RequirementBase(impl) { }
		ImplementationRequirement(const ImplementationRequirement &master) : RequirementBase(master) { }
		static ImplementationRequirement Cast(const Object &a) { return __Cast(a, meta); }

		static ImplementationRequirement Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ImplementationRequirement CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ImplementationRequirement CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ImplementationRequirement> Instances() { return Udm::InstantiatedAttr<PICML::ImplementationRequirement>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ImplementationRequirement, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ImplementationRequirement, Pred>(impl);}

		Udm::DerivedAttr<PICML::ImplementationRequirement> Derived() { return Udm::DerivedAttr<PICML::ImplementationRequirement>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ImplementationRequirement, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ImplementationRequirement, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ImplementationRequirement> Archetype() { return Udm::ArchetypeAttr<PICML::ImplementationRequirement>(impl);}

		static Uml::AssociationRole meta_srcMonolithDeployRequirement, meta_srcMonolithDeployRequirement_rev;
		Udm::AClassAssocAttr<PICML::MonolithDeployRequirement, PICML::MonolithicImplementation> srcMonolithDeployRequirement() const { return Udm::AClassAssocAttr<PICML::MonolithDeployRequirement, PICML::MonolithicImplementation>(impl, meta_srcMonolithDeployRequirement, meta_srcMonolithDeployRequirement_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::MonolithDeployRequirement, PICML::MonolithicImplementation, Pred> srcMonolithDeployRequirement_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::MonolithDeployRequirement, PICML::MonolithicImplementation, Pred>(impl, meta_srcMonolithDeployRequirement, meta_srcMonolithDeployRequirement_rev); }

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Requirement :  public RequirementBase {
	 public:
		static Uml::Class meta;

		Requirement() { }
		Requirement(Udm::ObjectImpl *impl) : RequirementBase(impl) { }
		Requirement(const Requirement &master) : RequirementBase(master) { }
		static Requirement Cast(const Object &a) { return __Cast(a, meta); }

		static Requirement Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Requirement CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Requirement CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Requirement> Instances() { return Udm::InstantiatedAttr<PICML::Requirement>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Requirement, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Requirement, Pred>(impl);}

		Udm::DerivedAttr<PICML::Requirement> Derived() { return Udm::DerivedAttr<PICML::Requirement>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Requirement, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Requirement, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Requirement> Archetype() { return Udm::ArchetypeAttr<PICML::Requirement>(impl);}

		static Uml::AssociationRole meta_srcArtifactDeployRequirement, meta_srcArtifactDeployRequirement_rev;
		Udm::AClassAssocAttr<PICML::ArtifactDeployRequirement, PICML::ImplementationArtifact> srcArtifactDeployRequirement() const { return Udm::AClassAssocAttr<PICML::ArtifactDeployRequirement, PICML::ImplementationArtifact>(impl, meta_srcArtifactDeployRequirement, meta_srcArtifactDeployRequirement_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ArtifactDeployRequirement, PICML::ImplementationArtifact, Pred> srcArtifactDeployRequirement_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ArtifactDeployRequirement, PICML::ImplementationArtifact, Pred>(impl, meta_srcArtifactDeployRequirement, meta_srcArtifactDeployRequirement_rev); }

		static Uml::AssociationRole meta_srcPackageSelectRequirement, meta_srcPackageSelectRequirement_rev;
		Udm::AClassAssocAttr<PICML::PackageSelectRequirement, PICML::PackageConfiguration> srcPackageSelectRequirement() const { return Udm::AClassAssocAttr<PICML::PackageSelectRequirement, PICML::PackageConfiguration>(impl, meta_srcPackageSelectRequirement, meta_srcPackageSelectRequirement_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageSelectRequirement, PICML::PackageConfiguration, Pred> srcPackageSelectRequirement_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageSelectRequirement, PICML::PackageConfiguration, Pred>(impl, meta_srcPackageSelectRequirement, meta_srcPackageSelectRequirement_rev); }

		static Uml::AssociationRole meta_srcConnectionRequirements, meta_srcConnectionRequirements_rev;
		Udm::AClassAssocAttr<PICML::ConnectionRequirements, PICML::PublishConnector> srcConnectionRequirements() const { return Udm::AClassAssocAttr<PICML::ConnectionRequirements, PICML::PublishConnector>(impl, meta_srcConnectionRequirements, meta_srcConnectionRequirements_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ConnectionRequirements, PICML::PublishConnector, Pred> srcConnectionRequirements_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ConnectionRequirements, PICML::PublishConnector, Pred>(impl, meta_srcConnectionRequirements, meta_srcConnectionRequirements_rev); }

		static Uml::AssociationRole meta_srcSubComponentSelectRequirement, meta_srcSubComponentSelectRequirement_rev;
		Udm::AClassAssocAttr<PICML::SubComponentSelectRequirement, PICML::ComponentDef> srcSubComponentSelectRequirement() const { return Udm::AClassAssocAttr<PICML::SubComponentSelectRequirement, PICML::ComponentDef>(impl, meta_srcSubComponentSelectRequirement, meta_srcSubComponentSelectRequirement_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::SubComponentSelectRequirement, PICML::ComponentDef, Pred> srcSubComponentSelectRequirement_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::SubComponentSelectRequirement, PICML::ComponentDef, Pred>(impl, meta_srcSubComponentSelectRequirement, meta_srcSubComponentSelectRequirement_rev); }

		static Uml::CompositionParentRole meta_ArtifactContainer_parent;
		Udm::ParentAttr<PICML::ArtifactContainer> ArtifactContainer_parent() const { return Udm::ParentAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_parent); }

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ImplementationDependency :  public MgaObject {
	 public:
		static Uml::Class meta;

		ImplementationDependency() { }
		ImplementationDependency(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ImplementationDependency(const ImplementationDependency &master) : MgaObject(master) { }
		static ImplementationDependency Cast(const Object &a) { return __Cast(a, meta); }

		static ImplementationDependency Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ImplementationDependency CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ImplementationDependency CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ImplementationDependency> Instances() { return Udm::InstantiatedAttr<PICML::ImplementationDependency>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ImplementationDependency, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ImplementationDependency, Pred>(impl);}

		Udm::DerivedAttr<PICML::ImplementationDependency> Derived() { return Udm::DerivedAttr<PICML::ImplementationDependency>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ImplementationDependency, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ImplementationDependency, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ImplementationDependency> Archetype() { return Udm::ArchetypeAttr<PICML::ImplementationDependency>(impl);}

		static Uml::AssociationRole meta_srcImplementationDependsOn, meta_srcImplementationDependsOn_rev;
		Udm::AClassAssocAttr<PICML::ImplementationDependsOn, PICML::ComponentImplementation> srcImplementationDependsOn() const { return Udm::AClassAssocAttr<PICML::ImplementationDependsOn, PICML::ComponentImplementation>(impl, meta_srcImplementationDependsOn, meta_srcImplementationDependsOn_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ImplementationDependsOn, PICML::ComponentImplementation, Pred> srcImplementationDependsOn_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ImplementationDependsOn, PICML::ComponentImplementation, Pred>(impl, meta_srcImplementationDependsOn, meta_srcImplementationDependsOn_rev); }

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Any :  public MgaObject {
	 public:
		static Uml::Class meta;

		Any() { }
		Any(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Any(const Any &master) : MgaObject(master) { }
		static Any Cast(const Object &a) { return __Cast(a, meta); }

		static Any Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Any CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Any CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Any> Instances() { return Udm::InstantiatedAttr<PICML::Any>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Any, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Any, Pred>(impl);}

		Udm::DerivedAttr<PICML::Any> Derived() { return Udm::DerivedAttr<PICML::Any>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Any, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Any, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Any> Archetype() { return Udm::ArchetypeAttr<PICML::Any>(impl);}

		static Uml::CompositionChildRole meta_DataType_child;
		Udm::ChildAttr<PICML::DataType> DataType_child() const { return Udm::ChildAttr<PICML::DataType>(impl, meta_DataType_child); }

		Udm::ChildrenAttr<PICML::DataType> DataType_kind_children() const { return Udm::ChildrenAttr<PICML::DataType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::DataType, Pred> DataType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::DataType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_SatisfierProperty_parent;
		Udm::ParentAttr<PICML::SatisfierProperty> SatisfierProperty_parent() const { return Udm::ParentAttr<PICML::SatisfierProperty>(impl, meta_SatisfierProperty_parent); }

		static Uml::CompositionParentRole meta_Property_parent;
		Udm::ParentAttr<PICML::Property> Property_parent() const { return Udm::ParentAttr<PICML::Property>(impl, meta_Property_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Property :  public MgaObject {
	 public:
		static Uml::Class meta;

		Property() { }
		Property(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Property(const Property &master) : MgaObject(master) { }
		static Property Cast(const Object &a) { return __Cast(a, meta); }

		static Property Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Property CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Property CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Property> Instances() { return Udm::InstantiatedAttr<PICML::Property>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Property, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Property, Pred>(impl);}

		Udm::DerivedAttr<PICML::Property> Derived() { return Udm::DerivedAttr<PICML::Property>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Property, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Property, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Property> Archetype() { return Udm::ArchetypeAttr<PICML::Property>(impl);}

		static Uml::AssociationRole meta_srcArtifactExecParameter, meta_srcArtifactExecParameter_rev;
		Udm::AClassAssocAttr<PICML::ArtifactExecParameter, PICML::ImplementationArtifact> srcArtifactExecParameter() const { return Udm::AClassAssocAttr<PICML::ArtifactExecParameter, PICML::ImplementationArtifact>(impl, meta_srcArtifactExecParameter, meta_srcArtifactExecParameter_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ArtifactExecParameter, PICML::ImplementationArtifact, Pred> srcArtifactExecParameter_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ArtifactExecParameter, PICML::ImplementationArtifact, Pred>(impl, meta_srcArtifactExecParameter, meta_srcArtifactExecParameter_rev); }

		static Uml::AssociationRole meta_srcArtifactInfoProperty, meta_srcArtifactInfoProperty_rev;
		Udm::AClassAssocAttr<PICML::ArtifactInfoProperty, PICML::ImplementationArtifact> srcArtifactInfoProperty() const { return Udm::AClassAssocAttr<PICML::ArtifactInfoProperty, PICML::ImplementationArtifact>(impl, meta_srcArtifactInfoProperty, meta_srcArtifactInfoProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ArtifactInfoProperty, PICML::ImplementationArtifact, Pred> srcArtifactInfoProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ArtifactInfoProperty, PICML::ImplementationArtifact, Pred>(impl, meta_srcArtifactInfoProperty, meta_srcArtifactInfoProperty_rev); }

		static Uml::AssociationRole meta_srcComponentConfigProperty, meta_srcComponentConfigProperty_rev;
		Udm::AClassAssocAttr<PICML::ComponentConfigProperty, PICML::ComponentType> srcComponentConfigProperty() const { return Udm::AClassAssocAttr<PICML::ComponentConfigProperty, PICML::ComponentType>(impl, meta_srcComponentConfigProperty, meta_srcComponentConfigProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ComponentConfigProperty, PICML::ComponentType, Pred> srcComponentConfigProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ComponentConfigProperty, PICML::ComponentType, Pred>(impl, meta_srcComponentConfigProperty, meta_srcComponentConfigProperty_rev); }

		static Uml::AssociationRole meta_srcComponentInfoProperty, meta_srcComponentInfoProperty_rev;
		Udm::AClassAssocAttr<PICML::ComponentInfoProperty, PICML::ComponentType> srcComponentInfoProperty() const { return Udm::AClassAssocAttr<PICML::ComponentInfoProperty, PICML::ComponentType>(impl, meta_srcComponentInfoProperty, meta_srcComponentInfoProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ComponentInfoProperty, PICML::ComponentType, Pred> srcComponentInfoProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ComponentInfoProperty, PICML::ComponentType, Pred>(impl, meta_srcComponentInfoProperty, meta_srcComponentInfoProperty_rev); }

		static Uml::AssociationRole meta_srcConfigProperty, meta_srcConfigProperty_rev;
		Udm::AClassAssocAttr<PICML::ConfigProperty, PICML::ComponentImplementation> srcConfigProperty() const { return Udm::AClassAssocAttr<PICML::ConfigProperty, PICML::ComponentImplementation>(impl, meta_srcConfigProperty, meta_srcConfigProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ConfigProperty, PICML::ComponentImplementation, Pred> srcConfigProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ConfigProperty, PICML::ComponentImplementation, Pred>(impl, meta_srcConfigProperty, meta_srcConfigProperty_rev); }

		static Uml::AssociationRole meta_srcInfoProperty, meta_srcInfoProperty_rev;
		Udm::AClassAssocAttr<PICML::InfoProperty, PICML::ComponentImplementation> srcInfoProperty() const { return Udm::AClassAssocAttr<PICML::InfoProperty, PICML::ComponentImplementation>(impl, meta_srcInfoProperty, meta_srcInfoProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::InfoProperty, PICML::ComponentImplementation, Pred> srcInfoProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::InfoProperty, PICML::ComponentImplementation, Pred>(impl, meta_srcInfoProperty, meta_srcInfoProperty_rev); }

		static Uml::AssociationRole meta_srcMonolithExecParameter, meta_srcMonolithExecParameter_rev;
		Udm::AClassAssocAttr<PICML::MonolithExecParameter, PICML::MonolithicImplementation> srcMonolithExecParameter() const { return Udm::AClassAssocAttr<PICML::MonolithExecParameter, PICML::MonolithicImplementation>(impl, meta_srcMonolithExecParameter, meta_srcMonolithExecParameter_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::MonolithExecParameter, PICML::MonolithicImplementation, Pred> srcMonolithExecParameter_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::MonolithExecParameter, PICML::MonolithicImplementation, Pred>(impl, meta_srcMonolithExecParameter, meta_srcMonolithExecParameter_rev); }

		static Uml::AssociationRole meta_srcPackageConfigurationProperty, meta_srcPackageConfigurationProperty_rev;
		Udm::AClassAssocAttr<PICML::PackageConfigurationProperty, PICML::PackageConfiguration> srcPackageConfigurationProperty() const { return Udm::AClassAssocAttr<PICML::PackageConfigurationProperty, PICML::PackageConfiguration>(impl, meta_srcPackageConfigurationProperty, meta_srcPackageConfigurationProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageConfigurationProperty, PICML::PackageConfiguration, Pred> srcPackageConfigurationProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageConfigurationProperty, PICML::PackageConfiguration, Pred>(impl, meta_srcPackageConfigurationProperty, meta_srcPackageConfigurationProperty_rev); }

		static Uml::AssociationRole meta_srcPackageConfigProperty, meta_srcPackageConfigProperty_rev;
		Udm::AClassAssocAttr<PICML::PackageConfigProperty, PICML::ComponentPackage> srcPackageConfigProperty() const { return Udm::AClassAssocAttr<PICML::PackageConfigProperty, PICML::ComponentPackage>(impl, meta_srcPackageConfigProperty, meta_srcPackageConfigProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageConfigProperty, PICML::ComponentPackage, Pred> srcPackageConfigProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageConfigProperty, PICML::ComponentPackage, Pred>(impl, meta_srcPackageConfigProperty, meta_srcPackageConfigProperty_rev); }

		static Uml::AssociationRole meta_srcPackageInfoProperty, meta_srcPackageInfoProperty_rev;
		Udm::AClassAssocAttr<PICML::PackageInfoProperty, PICML::ComponentPackage> srcPackageInfoProperty() const { return Udm::AClassAssocAttr<PICML::PackageInfoProperty, PICML::ComponentPackage>(impl, meta_srcPackageInfoProperty, meta_srcPackageInfoProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageInfoProperty, PICML::ComponentPackage, Pred> srcPackageInfoProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageInfoProperty, PICML::ComponentPackage, Pred>(impl, meta_srcPackageInfoProperty, meta_srcPackageInfoProperty_rev); }

		static Uml::AssociationRole meta_srcSubComponentConfigProperty, meta_srcSubComponentConfigProperty_rev;
		Udm::AClassAssocAttr<PICML::SubComponentConfigProperty, PICML::ComponentDef> srcSubComponentConfigProperty() const { return Udm::AClassAssocAttr<PICML::SubComponentConfigProperty, PICML::ComponentDef>(impl, meta_srcSubComponentConfigProperty, meta_srcSubComponentConfigProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::SubComponentConfigProperty, PICML::ComponentDef, Pred> srcSubComponentConfigProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::SubComponentConfigProperty, PICML::ComponentDef, Pred>(impl, meta_srcSubComponentConfigProperty, meta_srcSubComponentConfigProperty_rev); }

		static Uml::CompositionChildRole meta_Any_child;
		Udm::ChildAttr<PICML::Any> Any_child() const { return Udm::ChildAttr<PICML::Any>(impl, meta_Any_child); }

		Udm::ChildrenAttr<PICML::Any> Any_kind_children() const { return Udm::ChildrenAttr<PICML::Any>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Any, Pred> Any_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Any, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_ArtifactContainer_parent;
		Udm::ParentAttr<PICML::ArtifactContainer> ArtifactContainer_parent() const { return Udm::ParentAttr<PICML::ArtifactContainer>(impl, meta_ArtifactContainer_parent); }

		static Uml::CompositionParentRole meta_ComponentContainer_parent;
		Udm::ParentAttr<PICML::ComponentContainer> ComponentContainer_parent() const { return Udm::ParentAttr<PICML::ComponentContainer>(impl, meta_ComponentContainer_parent); }

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		static Uml::CompositionParentRole meta_RequirementBase_parent;
		Udm::ParentAttr<PICML::RequirementBase> RequirementBase_parent() const { return Udm::ParentAttr<PICML::RequirementBase>(impl, meta_RequirementBase_parent); }

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		static Uml::CompositionParentRole meta_PackageContainer_parent;
		Udm::ParentAttr<PICML::PackageContainer> PackageContainer_parent() const { return Udm::ParentAttr<PICML::PackageContainer>(impl, meta_PackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  SatisfierProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		SatisfierProperty() { }
		SatisfierProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		SatisfierProperty(const SatisfierProperty &master) : MgaObject(master) { }
		static SatisfierProperty Cast(const Object &a) { return __Cast(a, meta); }

		static SatisfierProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		SatisfierProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		SatisfierProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<SatisfierProperty> Instances() { return Udm::InstantiatedAttr<PICML::SatisfierProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<SatisfierProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::SatisfierProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::SatisfierProperty> Derived() { return Udm::DerivedAttr<PICML::SatisfierProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::SatisfierProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::SatisfierProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::SatisfierProperty> Archetype() { return Udm::ArchetypeAttr<PICML::SatisfierProperty>(impl);}

		static Uml::CompositionChildRole meta_Any_child;
		Udm::ChildAttr<PICML::Any> Any_child() const { return Udm::ChildAttr<PICML::Any>(impl, meta_Any_child); }

		Udm::ChildrenAttr<PICML::Any> Any_kind_children() const { return Udm::ChildrenAttr<PICML::Any>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Any, Pred> Any_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Any, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_RequirementSatisfier_parent;
		Udm::ParentAttr<PICML::RequirementSatisfier> RequirementSatisfier_parent() const { return Udm::ParentAttr<PICML::RequirementSatisfier>(impl, meta_RequirementSatisfier_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  DataType :  public MgaObject {
	 public:
		static Uml::Class meta;

		DataType() { }
		DataType(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		DataType(const DataType &master) : MgaObject(master) { }
		static DataType Cast(const Object &a) { return __Cast(a, meta); }

		static DataType Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		DataType CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		DataType CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<DataType> Instances() { return Udm::InstantiatedAttr<PICML::DataType>(impl);}
		template <class Pred> Udm::InstantiatedAttr<DataType, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::DataType, Pred>(impl);}

		Udm::DerivedAttr<PICML::DataType> Derived() { return Udm::DerivedAttr<PICML::DataType>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::DataType, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::DataType, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::DataType> Archetype() { return Udm::ArchetypeAttr<PICML::DataType>(impl);}

		static Uml::CompositionChildRole meta_PredefinedType_child;
		Udm::ChildAttr<PICML::PredefinedType> PredefinedType_child() const { return Udm::ChildAttr<PICML::PredefinedType>(impl, meta_PredefinedType_child); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ParameterType> ParameterType_kind_children() const { return Udm::ChildrenAttr<PICML::ParameterType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ParameterType, Pred> ParameterType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ParameterType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Type> Type_kind_children() const { return Udm::ChildrenAttr<PICML::Type>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Type, Pred> Type_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Type, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_Any_parent;
		Udm::ParentAttr<PICML::Any> Any_parent() const { return Udm::ParentAttr<PICML::Any>(impl, meta_Any_parent); }

		static Uml::CompositionParentRole meta_ComponentPropertyDescription_parent;
		Udm::ParentAttr<PICML::ComponentPropertyDescription> ComponentPropertyDescription_parent() const { return Udm::ParentAttr<PICML::ComponentPropertyDescription>(impl, meta_ComponentPropertyDescription_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  RequirementSatisfier :  public MgaObject {
	 public:
		static Uml::Class meta;

		RequirementSatisfier() { }
		RequirementSatisfier(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		RequirementSatisfier(const RequirementSatisfier &master) : MgaObject(master) { }
		static RequirementSatisfier Cast(const Object &a) { return __Cast(a, meta); }

		static RequirementSatisfier Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RequirementSatisfier CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RequirementSatisfier CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RequirementSatisfier> Instances() { return Udm::InstantiatedAttr<PICML::RequirementSatisfier>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RequirementSatisfier, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::RequirementSatisfier, Pred>(impl);}

		Udm::DerivedAttr<PICML::RequirementSatisfier> Derived() { return Udm::DerivedAttr<PICML::RequirementSatisfier>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::RequirementSatisfier, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::RequirementSatisfier, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::RequirementSatisfier> Archetype() { return Udm::ArchetypeAttr<PICML::RequirementSatisfier>(impl);}

		static Uml::CompositionChildRole meta_SatisfierProperty_children;
		Udm::ChildrenAttr<PICML::SatisfierProperty> SatisfierProperty_children() const { return Udm::ChildrenAttr<PICML::SatisfierProperty>(impl, meta_SatisfierProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::SatisfierProperty, Pred> SatisfierProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SatisfierProperty, Pred>(impl, meta_SatisfierProperty_children); }

		Udm::ChildrenAttr<PICML::SatisfierProperty> SatisfierProperty_kind_children() const { return Udm::ChildrenAttr<PICML::SatisfierProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SatisfierProperty, Pred> SatisfierProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SatisfierProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  Capability :  public RequirementSatisfier {
	 public:
		static Uml::Class meta;

		Capability() { }
		Capability(Udm::ObjectImpl *impl) : RequirementSatisfier(impl) { }
		Capability(const Capability &master) : RequirementSatisfier(master) { }
		static Capability Cast(const Object &a) { return __Cast(a, meta); }

		static Capability Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Capability CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Capability CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Capability> Instances() { return Udm::InstantiatedAttr<PICML::Capability>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Capability, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Capability, Pred>(impl);}

		Udm::DerivedAttr<PICML::Capability> Derived() { return Udm::DerivedAttr<PICML::Capability>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Capability, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Capability, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Capability> Archetype() { return Udm::ArchetypeAttr<PICML::Capability>(impl);}

		static Uml::AssociationRole meta_srcImplementationCapability, meta_srcImplementationCapability_rev;
		Udm::AClassAssocAttr<PICML::ImplementationCapability, PICML::ComponentImplementation> srcImplementationCapability() const { return Udm::AClassAssocAttr<PICML::ImplementationCapability, PICML::ComponentImplementation>(impl, meta_srcImplementationCapability, meta_srcImplementationCapability_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ImplementationCapability, PICML::ComponentImplementation, Pred> srcImplementationCapability_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ImplementationCapability, PICML::ComponentImplementation, Pred>(impl, meta_srcImplementationCapability, meta_srcImplementationCapability_rev); }

		static Uml::CompositionParentRole meta_ComponentImplementationContainer_parent;
		Udm::ParentAttr<PICML::ComponentImplementationContainer> ComponentImplementationContainer_parent() const { return Udm::ParentAttr<PICML::ComponentImplementationContainer>(impl, meta_ComponentImplementationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  PackageBaseConnection :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageBaseConnection() { }
		PackageBaseConnection(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageBaseConnection(const PackageBaseConnection &master) : MgaObject(master) { }
		static PackageBaseConnection Cast(const Object &a) { return __Cast(a, meta); }

		static PackageBaseConnection Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageBaseConnection CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageBaseConnection CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageBaseConnection> Instances() { return Udm::InstantiatedAttr<PICML::PackageBaseConnection>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageBaseConnection, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageBaseConnection, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageBaseConnection> Derived() { return Udm::DerivedAttr<PICML::PackageBaseConnection>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageBaseConnection, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageBaseConnection, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageBaseConnection> Archetype() { return Udm::ArchetypeAttr<PICML::PackageBaseConnection>(impl);}

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstPackageBaseConnection_end_;
		Udm::AssocEndAttr<PICML::ComponentPackage> dstPackageBaseConnection_end() const { return Udm::AssocEndAttr<PICML::ComponentPackage>(impl, meta_dstPackageBaseConnection_end_); }

		static Uml::AssociationRole meta_srcPackageBaseConnection_end_;
		Udm::AssocEndAttr<PICML::PackageConfiguration> srcPackageBaseConnection_end() const { return Udm::AssocEndAttr<PICML::PackageConfiguration>(impl, meta_srcPackageBaseConnection_end_); }

	};

	class  PackageReferenceConnection :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageReferenceConnection() { }
		PackageReferenceConnection(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageReferenceConnection(const PackageReferenceConnection &master) : MgaObject(master) { }
		static PackageReferenceConnection Cast(const Object &a) { return __Cast(a, meta); }

		static PackageReferenceConnection Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageReferenceConnection CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageReferenceConnection CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageReferenceConnection> Instances() { return Udm::InstantiatedAttr<PICML::PackageReferenceConnection>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageReferenceConnection, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageReferenceConnection, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageReferenceConnection> Derived() { return Udm::DerivedAttr<PICML::PackageReferenceConnection>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageReferenceConnection, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageReferenceConnection, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageReferenceConnection> Archetype() { return Udm::ArchetypeAttr<PICML::PackageReferenceConnection>(impl);}

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstPackageReferenceConnection_end_;
		Udm::AssocEndAttr<PICML::ComponentPackageReference> dstPackageReferenceConnection_end() const { return Udm::AssocEndAttr<PICML::ComponentPackageReference>(impl, meta_dstPackageReferenceConnection_end_); }

		static Uml::AssociationRole meta_srcPackageReferenceConnection_end_;
		Udm::AssocEndAttr<PICML::PackageConfiguration> srcPackageReferenceConnection_end() const { return Udm::AssocEndAttr<PICML::PackageConfiguration>(impl, meta_srcPackageReferenceConnection_end_); }

	};

	class  PackageConfigurationReference :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageConfigurationReference() { }
		PackageConfigurationReference(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageConfigurationReference(const PackageConfigurationReference &master) : MgaObject(master) { }
		static PackageConfigurationReference Cast(const Object &a) { return __Cast(a, meta); }

		static PackageConfigurationReference Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageConfigurationReference CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageConfigurationReference CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageConfigurationReference> Instances() { return Udm::InstantiatedAttr<PICML::PackageConfigurationReference>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageConfigurationReference, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageConfigurationReference, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageConfigurationReference> Derived() { return Udm::DerivedAttr<PICML::PackageConfigurationReference>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageConfigurationReference, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageConfigurationReference, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageConfigurationReference> Archetype() { return Udm::ArchetypeAttr<PICML::PackageConfigurationReference>(impl);}

		static Uml::AssociationRole meta_srcTopLevelPackageConn, meta_srcTopLevelPackageConn_rev;
		Udm::AClassPointerAttr<PICML::TopLevelPackageConn, PICML::TopLevelPackage> srcTopLevelPackageConn() const { return Udm::AClassPointerAttr<PICML::TopLevelPackageConn, PICML::TopLevelPackage>(impl, meta_srcTopLevelPackageConn, meta_srcTopLevelPackageConn_rev); }

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::PackageConfiguration> ref() const { return Udm::PointerAttr<PICML::PackageConfiguration>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_TopLevelPackageContainer_parent;
		Udm::ParentAttr<PICML::TopLevelPackageContainer> TopLevelPackageContainer_parent() const { return Udm::ParentAttr<PICML::TopLevelPackageContainer>(impl, meta_TopLevelPackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  PackageConfiguration :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageConfiguration() { }
		PackageConfiguration(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageConfiguration(const PackageConfiguration &master) : MgaObject(master) { }
		static PackageConfiguration Cast(const Object &a) { return __Cast(a, meta); }

		static PackageConfiguration Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageConfiguration CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageConfiguration CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageConfiguration> Instances() { return Udm::InstantiatedAttr<PICML::PackageConfiguration>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageConfiguration, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageConfiguration, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageConfiguration> Derived() { return Udm::DerivedAttr<PICML::PackageConfiguration>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageConfiguration, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageConfiguration, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageConfiguration> Archetype() { return Udm::ArchetypeAttr<PICML::PackageConfiguration>(impl);}

		static Uml::AssociationRole meta_dstPackageSelectRequirement, meta_dstPackageSelectRequirement_rev;
		Udm::AClassAssocAttr<PICML::PackageSelectRequirement, PICML::Requirement> dstPackageSelectRequirement() const { return Udm::AClassAssocAttr<PICML::PackageSelectRequirement, PICML::Requirement>(impl, meta_dstPackageSelectRequirement, meta_dstPackageSelectRequirement_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageSelectRequirement, PICML::Requirement, Pred> dstPackageSelectRequirement_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageSelectRequirement, PICML::Requirement, Pred>(impl, meta_dstPackageSelectRequirement, meta_dstPackageSelectRequirement_rev); }

		static Uml::AssociationRole meta_dstPackageConfigurationProperty, meta_dstPackageConfigurationProperty_rev;
		Udm::AClassAssocAttr<PICML::PackageConfigurationProperty, PICML::Property> dstPackageConfigurationProperty() const { return Udm::AClassAssocAttr<PICML::PackageConfigurationProperty, PICML::Property>(impl, meta_dstPackageConfigurationProperty, meta_dstPackageConfigurationProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageConfigurationProperty, PICML::Property, Pred> dstPackageConfigurationProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageConfigurationProperty, PICML::Property, Pred>(impl, meta_dstPackageConfigurationProperty, meta_dstPackageConfigurationProperty_rev); }

		static Uml::AssociationRole meta_dstPackageBaseConnection, meta_dstPackageBaseConnection_rev;
		Udm::AClassAssocAttr<PICML::PackageBaseConnection, PICML::ComponentPackage> dstPackageBaseConnection() const { return Udm::AClassAssocAttr<PICML::PackageBaseConnection, PICML::ComponentPackage>(impl, meta_dstPackageBaseConnection, meta_dstPackageBaseConnection_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageBaseConnection, PICML::ComponentPackage, Pred> dstPackageBaseConnection_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageBaseConnection, PICML::ComponentPackage, Pred>(impl, meta_dstPackageBaseConnection, meta_dstPackageBaseConnection_rev); }

		static Uml::AssociationRole meta_dstPackageReferenceConnection, meta_dstPackageReferenceConnection_rev;
		Udm::AClassAssocAttr<PICML::PackageReferenceConnection, PICML::ComponentPackageReference> dstPackageReferenceConnection() const { return Udm::AClassAssocAttr<PICML::PackageReferenceConnection, PICML::ComponentPackageReference>(impl, meta_dstPackageReferenceConnection, meta_dstPackageReferenceConnection_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageReferenceConnection, PICML::ComponentPackageReference, Pred> dstPackageReferenceConnection_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageReferenceConnection, PICML::ComponentPackageReference, Pred>(impl, meta_dstPackageReferenceConnection, meta_dstPackageReferenceConnection_rev); }

		static Uml::AssociationRole meta_referedbyPackageConfigurationReference;
		Udm::AssocAttr<PICML::PackageConfigurationReference> referedbyPackageConfigurationReference() const { return Udm::AssocAttr<PICML::PackageConfigurationReference>(impl, meta_referedbyPackageConfigurationReference); }
		template <class Pred> Udm::AssocAttr<PICML::PackageConfigurationReference, Pred > referedbyPackageConfigurationReference_sorted(const Pred &) const { return Udm::AssocAttr<PICML::PackageConfigurationReference, Pred>(impl, meta_referedbyPackageConfigurationReference); }

		static Uml::CompositionChildRole meta_specializedConfig;
		Udm::ChildAttr<PICML::PackageConfiguration> specializedConfig() const { return Udm::ChildAttr<PICML::PackageConfiguration>(impl, meta_specializedConfig); }

		Udm::ChildrenAttr<PICML::PackageConfiguration> PackageConfiguration_kind_children() const { return Udm::ChildrenAttr<PICML::PackageConfiguration>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageConfiguration, Pred> PackageConfiguration_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfiguration, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		static Uml::CompositionParentRole meta_specializedConfig_PackageConfiguration_parent;
		Udm::ParentAttr<PICML::PackageConfiguration> specializedConfig_PackageConfiguration_parent() const { return Udm::ParentAttr<PICML::PackageConfiguration>(impl, meta_specializedConfig_PackageConfiguration_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  PackageConfigurationContainer :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageConfigurationContainer() { }
		PackageConfigurationContainer(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageConfigurationContainer(const PackageConfigurationContainer &master) : MgaObject(master) { }
		static PackageConfigurationContainer Cast(const Object &a) { return __Cast(a, meta); }

		static PackageConfigurationContainer Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageConfigurationContainer CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageConfigurationContainer CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageConfigurationContainer> Instances() { return Udm::InstantiatedAttr<PICML::PackageConfigurationContainer>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageConfigurationContainer, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageConfigurationContainer, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageConfigurationContainer> Derived() { return Udm::DerivedAttr<PICML::PackageConfigurationContainer>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageConfigurationContainer, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageConfigurationContainer, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageConfigurationContainer> Archetype() { return Udm::ArchetypeAttr<PICML::PackageConfigurationContainer>(impl);}

		static Uml::CompositionChildRole meta_PackageReferenceConnection_child;
		Udm::ChildAttr<PICML::PackageReferenceConnection> PackageReferenceConnection_child() const { return Udm::ChildAttr<PICML::PackageReferenceConnection>(impl, meta_PackageReferenceConnection_child); }

		static Uml::CompositionChildRole meta_PackageBaseConnection_child;
		Udm::ChildAttr<PICML::PackageBaseConnection> PackageBaseConnection_child() const { return Udm::ChildAttr<PICML::PackageBaseConnection>(impl, meta_PackageBaseConnection_child); }

		static Uml::CompositionChildRole meta_ComponentPackage_children;
		Udm::ChildrenAttr<PICML::ComponentPackage> ComponentPackage_children() const { return Udm::ChildrenAttr<PICML::ComponentPackage>(impl, meta_ComponentPackage_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentPackage, Pred> ComponentPackage_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackage, Pred>(impl, meta_ComponentPackage_children); }

		static Uml::CompositionChildRole meta_ComponentPackageReference_children;
		Udm::ChildrenAttr<PICML::ComponentPackageReference> ComponentPackageReference_children() const { return Udm::ChildrenAttr<PICML::ComponentPackageReference>(impl, meta_ComponentPackageReference_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentPackageReference, Pred> ComponentPackageReference_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackageReference, Pred>(impl, meta_ComponentPackageReference_children); }

		static Uml::CompositionChildRole meta_PackageConfiguration_children;
		Udm::ChildrenAttr<PICML::PackageConfiguration> PackageConfiguration_children() const { return Udm::ChildrenAttr<PICML::PackageConfiguration>(impl, meta_PackageConfiguration_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageConfiguration, Pred> PackageConfiguration_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfiguration, Pred>(impl, meta_PackageConfiguration_children); }

		static Uml::CompositionChildRole meta_PackageConfigurationProperty_children;
		Udm::ChildrenAttr<PICML::PackageConfigurationProperty> PackageConfigurationProperty_children() const { return Udm::ChildrenAttr<PICML::PackageConfigurationProperty>(impl, meta_PackageConfigurationProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageConfigurationProperty, Pred> PackageConfigurationProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigurationProperty, Pred>(impl, meta_PackageConfigurationProperty_children); }

		static Uml::CompositionChildRole meta_PackageSelectRequirement_children;
		Udm::ChildrenAttr<PICML::PackageSelectRequirement> PackageSelectRequirement_children() const { return Udm::ChildrenAttr<PICML::PackageSelectRequirement>(impl, meta_PackageSelectRequirement_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageSelectRequirement, Pred> PackageSelectRequirement_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageSelectRequirement, Pred>(impl, meta_PackageSelectRequirement_children); }

		static Uml::CompositionChildRole meta_Requirement_children;
		Udm::ChildrenAttr<PICML::Requirement> Requirement_children() const { return Udm::ChildrenAttr<PICML::Requirement>(impl, meta_Requirement_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Requirement, Pred> Requirement_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Requirement, Pred>(impl, meta_Requirement_children); }

		static Uml::CompositionChildRole meta_Property_children;
		Udm::ChildrenAttr<PICML::Property> Property_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, meta_Property_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, meta_Property_children); }

		Udm::ChildrenAttr<PICML::RequirementBase> RequirementBase_kind_children() const { return Udm::ChildrenAttr<PICML::RequirementBase>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::RequirementBase, Pred> RequirementBase_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RequirementBase, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Requirement> Requirement_kind_children() const { return Udm::ChildrenAttr<PICML::Requirement>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Requirement, Pred> Requirement_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Requirement, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Property> Property_kind_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageBaseConnection> PackageBaseConnection_kind_children() const { return Udm::ChildrenAttr<PICML::PackageBaseConnection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageBaseConnection, Pred> PackageBaseConnection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageBaseConnection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageReferenceConnection> PackageReferenceConnection_kind_children() const { return Udm::ChildrenAttr<PICML::PackageReferenceConnection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageReferenceConnection, Pred> PackageReferenceConnection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageReferenceConnection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageConfiguration> PackageConfiguration_kind_children() const { return Udm::ChildrenAttr<PICML::PackageConfiguration>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageConfiguration, Pred> PackageConfiguration_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfiguration, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageConfigurationProperty> PackageConfigurationProperty_kind_children() const { return Udm::ChildrenAttr<PICML::PackageConfigurationProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageConfigurationProperty, Pred> PackageConfigurationProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigurationProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageSelectRequirement> PackageSelectRequirement_kind_children() const { return Udm::ChildrenAttr<PICML::PackageSelectRequirement>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageSelectRequirement, Pred> PackageSelectRequirement_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageSelectRequirement, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentPackage> ComponentPackage_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentPackage>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentPackage, Pred> ComponentPackage_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackage, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentPackageReference> ComponentPackageReference_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentPackageReference>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentPackageReference, Pred> ComponentPackageReference_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackageReference, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_PackageConfigurations_parent;
		Udm::ParentAttr<PICML::PackageConfigurations> PackageConfigurations_parent() const { return Udm::ParentAttr<PICML::PackageConfigurations>(impl, meta_PackageConfigurations_parent); }

		Udm::ParentAttr<PICML::PackageConfigurations> parent() const { return Udm::ParentAttr<PICML::PackageConfigurations>(impl, Udm::NULLPARENTROLE); }
	};

	class  PackageConfigurationProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageConfigurationProperty() { }
		PackageConfigurationProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageConfigurationProperty(const PackageConfigurationProperty &master) : MgaObject(master) { }
		static PackageConfigurationProperty Cast(const Object &a) { return __Cast(a, meta); }

		static PackageConfigurationProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageConfigurationProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageConfigurationProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageConfigurationProperty> Instances() { return Udm::InstantiatedAttr<PICML::PackageConfigurationProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageConfigurationProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageConfigurationProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageConfigurationProperty> Derived() { return Udm::DerivedAttr<PICML::PackageConfigurationProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageConfigurationProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageConfigurationProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageConfigurationProperty> Archetype() { return Udm::ArchetypeAttr<PICML::PackageConfigurationProperty>(impl);}

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstPackageConfigurationProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstPackageConfigurationProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstPackageConfigurationProperty_end_); }

		static Uml::AssociationRole meta_srcPackageConfigurationProperty_end_;
		Udm::AssocEndAttr<PICML::PackageConfiguration> srcPackageConfigurationProperty_end() const { return Udm::AssocEndAttr<PICML::PackageConfiguration>(impl, meta_srcPackageConfigurationProperty_end_); }

	};

	class  PackageSelectRequirement :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageSelectRequirement() { }
		PackageSelectRequirement(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageSelectRequirement(const PackageSelectRequirement &master) : MgaObject(master) { }
		static PackageSelectRequirement Cast(const Object &a) { return __Cast(a, meta); }

		static PackageSelectRequirement Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageSelectRequirement CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageSelectRequirement CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageSelectRequirement> Instances() { return Udm::InstantiatedAttr<PICML::PackageSelectRequirement>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageSelectRequirement, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageSelectRequirement, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageSelectRequirement> Derived() { return Udm::DerivedAttr<PICML::PackageSelectRequirement>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageSelectRequirement, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageSelectRequirement, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageSelectRequirement> Archetype() { return Udm::ArchetypeAttr<PICML::PackageSelectRequirement>(impl);}

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstPackageSelectRequirement_end_;
		Udm::AssocEndAttr<PICML::Requirement> dstPackageSelectRequirement_end() const { return Udm::AssocEndAttr<PICML::Requirement>(impl, meta_dstPackageSelectRequirement_end_); }

		static Uml::AssociationRole meta_srcPackageSelectRequirement_end_;
		Udm::AssocEndAttr<PICML::PackageConfiguration> srcPackageSelectRequirement_end() const { return Udm::AssocEndAttr<PICML::PackageConfiguration>(impl, meta_srcPackageSelectRequirement_end_); }

	};

	class  EmitConnector :  public MgaObject {
	 public:
		static Uml::Class meta;

		EmitConnector() { }
		EmitConnector(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		EmitConnector(const EmitConnector &master) : MgaObject(master) { }
		static EmitConnector Cast(const Object &a) { return __Cast(a, meta); }

		static EmitConnector Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EmitConnector CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EmitConnector CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EmitConnector> Instances() { return Udm::InstantiatedAttr<PICML::EmitConnector>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EmitConnector, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::EmitConnector, Pred>(impl);}

		Udm::DerivedAttr<PICML::EmitConnector> Derived() { return Udm::DerivedAttr<PICML::EmitConnector>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::EmitConnector, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::EmitConnector, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::EmitConnector> Archetype() { return Udm::ArchetypeAttr<PICML::EmitConnector>(impl);}

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstEmitConnector_end_;
		Udm::AssocEndAttr<PICML::InEventPort> dstEmitConnector_end() const { return Udm::AssocEndAttr<PICML::InEventPort>(impl, meta_dstEmitConnector_end_); }

		static Uml::AssociationRole meta_srcEmitConnector_end_;
		Udm::AssocEndAttr<PICML::OutEventPort> srcEmitConnector_end() const { return Udm::AssocEndAttr<PICML::OutEventPort>(impl, meta_srcEmitConnector_end_); }

	};

	class  ComponentAssembly :  public ComponentImplementation {
	 public:
		static Uml::Class meta;

		ComponentAssembly() { }
		ComponentAssembly(Udm::ObjectImpl *impl) : ComponentImplementation(impl) { }
		ComponentAssembly(const ComponentAssembly &master) : ComponentImplementation(master) { }
		static ComponentAssembly Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentAssembly Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentAssembly CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentAssembly CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentAssembly> Instances() { return Udm::InstantiatedAttr<PICML::ComponentAssembly>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentAssembly, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentAssembly, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentAssembly> Derived() { return Udm::DerivedAttr<PICML::ComponentAssembly>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentAssembly, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentAssembly, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentAssembly> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentAssembly>(impl);}

		static Uml::CompositionChildRole meta_ComponentDef_children;
		Udm::ChildrenAttr<PICML::ComponentDef> ComponentDef_children() const { return Udm::ChildrenAttr<PICML::ComponentDef>(impl, meta_ComponentDef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentDef, Pred> ComponentDef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentDef, Pred>(impl, meta_ComponentDef_children); }

		static Uml::CompositionChildRole meta_EmitConnector_children;
		Udm::ChildrenAttr<PICML::EmitConnector> EmitConnector_children() const { return Udm::ChildrenAttr<PICML::EmitConnector>(impl, meta_EmitConnector_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::EmitConnector, Pred> EmitConnector_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EmitConnector, Pred>(impl, meta_EmitConnector_children); }

		static Uml::CompositionChildRole meta_ComponentPackage_children;
		Udm::ChildrenAttr<PICML::ComponentPackage> ComponentPackage_children() const { return Udm::ChildrenAttr<PICML::ComponentPackage>(impl, meta_ComponentPackage_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentPackage, Pred> ComponentPackage_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackage, Pred>(impl, meta_ComponentPackage_children); }

		static Uml::CompositionChildRole meta_Invocation_children;
		Udm::ChildrenAttr<PICML::Invocation> Invocation_children() const { return Udm::ChildrenAttr<PICML::Invocation>(impl, meta_Invocation_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Invocation, Pred> Invocation_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Invocation, Pred>(impl, meta_Invocation_children); }

		static Uml::CompositionChildRole meta_SubComponentSelectRequirement_children;
		Udm::ChildrenAttr<PICML::SubComponentSelectRequirement> SubComponentSelectRequirement_children() const { return Udm::ChildrenAttr<PICML::SubComponentSelectRequirement>(impl, meta_SubComponentSelectRequirement_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::SubComponentSelectRequirement, Pred> SubComponentSelectRequirement_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SubComponentSelectRequirement, Pred>(impl, meta_SubComponentSelectRequirement_children); }

		static Uml::CompositionChildRole meta_SubComponentConfigProperty_children;
		Udm::ChildrenAttr<PICML::SubComponentConfigProperty> SubComponentConfigProperty_children() const { return Udm::ChildrenAttr<PICML::SubComponentConfigProperty>(impl, meta_SubComponentConfigProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::SubComponentConfigProperty, Pred> SubComponentConfigProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SubComponentConfigProperty, Pred>(impl, meta_SubComponentConfigProperty_children); }

		static Uml::CompositionChildRole meta_Property_children;
		Udm::ChildrenAttr<PICML::Property> Property_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, meta_Property_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, meta_Property_children); }

		static Uml::CompositionChildRole meta_ComponentPackageReference_children;
		Udm::ChildrenAttr<PICML::ComponentPackageReference> ComponentPackageReference_children() const { return Udm::ChildrenAttr<PICML::ComponentPackageReference>(impl, meta_ComponentPackageReference_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentPackageReference, Pred> ComponentPackageReference_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackageReference, Pred>(impl, meta_ComponentPackageReference_children); }

		static Uml::CompositionChildRole meta_InEventPortConsume_children;
		Udm::ChildrenAttr<PICML::InEventPortConsume> InEventPortConsume_children() const { return Udm::ChildrenAttr<PICML::InEventPortConsume>(impl, meta_InEventPortConsume_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::InEventPortConsume, Pred> InEventPortConsume_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InEventPortConsume, Pred>(impl, meta_InEventPortConsume_children); }

		static Uml::CompositionChildRole meta_OutEventPortPublish_children;
		Udm::ChildrenAttr<PICML::OutEventPortPublish> OutEventPortPublish_children() const { return Udm::ChildrenAttr<PICML::OutEventPortPublish>(impl, meta_OutEventPortPublish_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::OutEventPortPublish, Pred> OutEventPortPublish_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OutEventPortPublish, Pred>(impl, meta_OutEventPortPublish_children); }

		static Uml::CompositionChildRole meta_PublishConnector_children;
		Udm::ChildrenAttr<PICML::PublishConnector> PublishConnector_children() const { return Udm::ChildrenAttr<PICML::PublishConnector>(impl, meta_PublishConnector_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PublishConnector, Pred> PublishConnector_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PublishConnector, Pred>(impl, meta_PublishConnector_children); }

		static Uml::CompositionChildRole meta_ConnectionRequirements_children;
		Udm::ChildrenAttr<PICML::ConnectionRequirements> ConnectionRequirements_children() const { return Udm::ChildrenAttr<PICML::ConnectionRequirements>(impl, meta_ConnectionRequirements_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ConnectionRequirements, Pred> ConnectionRequirements_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConnectionRequirements, Pred>(impl, meta_ConnectionRequirements_children); }

		static Uml::CompositionChildRole meta_Requirement_children;
		Udm::ChildrenAttr<PICML::Requirement> Requirement_children() const { return Udm::ChildrenAttr<PICML::Requirement>(impl, meta_Requirement_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Requirement, Pred> Requirement_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Requirement, Pred>(impl, meta_Requirement_children); }

		Udm::ChildrenAttr<PICML::RequirementBase> RequirementBase_kind_children() const { return Udm::ChildrenAttr<PICML::RequirementBase>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::RequirementBase, Pred> RequirementBase_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RequirementBase, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Requirement> Requirement_kind_children() const { return Udm::ChildrenAttr<PICML::Requirement>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Requirement, Pred> Requirement_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Requirement, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Property> Property_kind_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::EmitConnector> EmitConnector_kind_children() const { return Udm::ChildrenAttr<PICML::EmitConnector>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EmitConnector, Pred> EmitConnector_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EmitConnector, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Invocation> Invocation_kind_children() const { return Udm::ChildrenAttr<PICML::Invocation>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Invocation, Pred> Invocation_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Invocation, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SubComponentSelectRequirement> SubComponentSelectRequirement_kind_children() const { return Udm::ChildrenAttr<PICML::SubComponentSelectRequirement>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SubComponentSelectRequirement, Pred> SubComponentSelectRequirement_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SubComponentSelectRequirement, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SubComponentConfigProperty> SubComponentConfigProperty_kind_children() const { return Udm::ChildrenAttr<PICML::SubComponentConfigProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SubComponentConfigProperty, Pred> SubComponentConfigProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SubComponentConfigProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PublishConnector> PublishConnector_kind_children() const { return Udm::ChildrenAttr<PICML::PublishConnector>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PublishConnector, Pred> PublishConnector_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PublishConnector, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::OutEventPortPublish> OutEventPortPublish_kind_children() const { return Udm::ChildrenAttr<PICML::OutEventPortPublish>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::OutEventPortPublish, Pred> OutEventPortPublish_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OutEventPortPublish, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::InEventPortConsume> InEventPortConsume_kind_children() const { return Udm::ChildrenAttr<PICML::InEventPortConsume>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::InEventPortConsume, Pred> InEventPortConsume_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InEventPortConsume, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ConnectionRequirements> ConnectionRequirements_kind_children() const { return Udm::ChildrenAttr<PICML::ConnectionRequirements>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ConnectionRequirements, Pred> ConnectionRequirements_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConnectionRequirements, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentPackage> ComponentPackage_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentPackage>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentPackage, Pred> ComponentPackage_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackage, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentPackageReference> ComponentPackageReference_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentPackageReference>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentPackageReference, Pred> ComponentPackageReference_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackageReference, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::NamedType> NamedType_kind_children() const { return Udm::ChildrenAttr<PICML::NamedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedType, Pred> NamedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Taggable> Taggable_kind_children() const { return Udm::ChildrenAttr<PICML::Taggable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Taggable, Pred> Taggable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Taggable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Type> Type_kind_children() const { return Udm::ChildrenAttr<PICML::Type>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Type, Pred> Type_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Type, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentDef> ComponentDef_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentDef, Pred> ComponentDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Inheritable> Inheritable_kind_children() const { return Udm::ChildrenAttr<PICML::Inheritable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Inheritable, Pred> Inheritable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Inheritable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SupportsInterfaces> SupportsInterfaces_kind_children() const { return Udm::ChildrenAttr<PICML::SupportsInterfaces>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SupportsInterfaces, Pred> SupportsInterfaces_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SupportsInterfaces, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Invocation :  public MgaObject {
	 public:
		static Uml::Class meta;

		Invocation() { }
		Invocation(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Invocation(const Invocation &master) : MgaObject(master) { }
		static Invocation Cast(const Object &a) { return __Cast(a, meta); }

		static Invocation Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Invocation CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Invocation CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Invocation> Instances() { return Udm::InstantiatedAttr<PICML::Invocation>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Invocation, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Invocation, Pred>(impl);}

		Udm::DerivedAttr<PICML::Invocation> Derived() { return Udm::DerivedAttr<PICML::Invocation>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Invocation, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Invocation, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Invocation> Archetype() { return Udm::ArchetypeAttr<PICML::Invocation>(impl);}

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstInvocation_end_;
		Udm::AssocEndAttr<PICML::ProvidedRequestPort> dstInvocation_end() const { return Udm::AssocEndAttr<PICML::ProvidedRequestPort>(impl, meta_dstInvocation_end_); }

		static Uml::AssociationRole meta_srcInvocation_end_;
		Udm::AssocEndAttr<PICML::RequiredRequestPort> srcInvocation_end() const { return Udm::AssocEndAttr<PICML::RequiredRequestPort>(impl, meta_srcInvocation_end_); }

	};

	class  SubComponentSelectRequirement :  public MgaObject {
	 public:
		static Uml::Class meta;

		SubComponentSelectRequirement() { }
		SubComponentSelectRequirement(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		SubComponentSelectRequirement(const SubComponentSelectRequirement &master) : MgaObject(master) { }
		static SubComponentSelectRequirement Cast(const Object &a) { return __Cast(a, meta); }

		static SubComponentSelectRequirement Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		SubComponentSelectRequirement CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		SubComponentSelectRequirement CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<SubComponentSelectRequirement> Instances() { return Udm::InstantiatedAttr<PICML::SubComponentSelectRequirement>(impl);}
		template <class Pred> Udm::InstantiatedAttr<SubComponentSelectRequirement, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::SubComponentSelectRequirement, Pred>(impl);}

		Udm::DerivedAttr<PICML::SubComponentSelectRequirement> Derived() { return Udm::DerivedAttr<PICML::SubComponentSelectRequirement>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::SubComponentSelectRequirement, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::SubComponentSelectRequirement, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::SubComponentSelectRequirement> Archetype() { return Udm::ArchetypeAttr<PICML::SubComponentSelectRequirement>(impl);}

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstSubComponentSelectRequirement_end_;
		Udm::AssocEndAttr<PICML::Requirement> dstSubComponentSelectRequirement_end() const { return Udm::AssocEndAttr<PICML::Requirement>(impl, meta_dstSubComponentSelectRequirement_end_); }

		static Uml::AssociationRole meta_srcSubComponentSelectRequirement_end_;
		Udm::AssocEndAttr<PICML::ComponentDef> srcSubComponentSelectRequirement_end() const { return Udm::AssocEndAttr<PICML::ComponentDef>(impl, meta_srcSubComponentSelectRequirement_end_); }

	};

	class  SubComponentConfigProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		SubComponentConfigProperty() { }
		SubComponentConfigProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		SubComponentConfigProperty(const SubComponentConfigProperty &master) : MgaObject(master) { }
		static SubComponentConfigProperty Cast(const Object &a) { return __Cast(a, meta); }

		static SubComponentConfigProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		SubComponentConfigProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		SubComponentConfigProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<SubComponentConfigProperty> Instances() { return Udm::InstantiatedAttr<PICML::SubComponentConfigProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<SubComponentConfigProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::SubComponentConfigProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::SubComponentConfigProperty> Derived() { return Udm::DerivedAttr<PICML::SubComponentConfigProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::SubComponentConfigProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::SubComponentConfigProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::SubComponentConfigProperty> Archetype() { return Udm::ArchetypeAttr<PICML::SubComponentConfigProperty>(impl);}

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstSubComponentConfigProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstSubComponentConfigProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstSubComponentConfigProperty_end_); }

		static Uml::AssociationRole meta_srcSubComponentConfigProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentDef> srcSubComponentConfigProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentDef>(impl, meta_srcSubComponentConfigProperty_end_); }

	};

	class  PublishConnector :  public MgaObject {
	 public:
		static Uml::Class meta;

		PublishConnector() { }
		PublishConnector(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PublishConnector(const PublishConnector &master) : MgaObject(master) { }
		static PublishConnector Cast(const Object &a) { return __Cast(a, meta); }

		static PublishConnector Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PublishConnector CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PublishConnector CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PublishConnector> Instances() { return Udm::InstantiatedAttr<PICML::PublishConnector>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PublishConnector, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PublishConnector, Pred>(impl);}

		Udm::DerivedAttr<PICML::PublishConnector> Derived() { return Udm::DerivedAttr<PICML::PublishConnector>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PublishConnector, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PublishConnector, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PublishConnector> Archetype() { return Udm::ArchetypeAttr<PICML::PublishConnector>(impl);}

		static Uml::AssociationRole meta_dstConnectionRequirements, meta_dstConnectionRequirements_rev;
		Udm::AClassAssocAttr<PICML::ConnectionRequirements, PICML::Requirement> dstConnectionRequirements() const { return Udm::AClassAssocAttr<PICML::ConnectionRequirements, PICML::Requirement>(impl, meta_dstConnectionRequirements, meta_dstConnectionRequirements_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::ConnectionRequirements, PICML::Requirement, Pred> dstConnectionRequirements_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::ConnectionRequirements, PICML::Requirement, Pred>(impl, meta_dstConnectionRequirements, meta_dstConnectionRequirements_rev); }

		static Uml::AssociationRole meta_dstInEventPortConsume, meta_dstInEventPortConsume_rev;
		Udm::AClassAssocAttr<PICML::InEventPortConsume, PICML::InEventPort> dstInEventPortConsume() const { return Udm::AClassAssocAttr<PICML::InEventPortConsume, PICML::InEventPort>(impl, meta_dstInEventPortConsume, meta_dstInEventPortConsume_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::InEventPortConsume, PICML::InEventPort, Pred> dstInEventPortConsume_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::InEventPortConsume, PICML::InEventPort, Pred>(impl, meta_dstInEventPortConsume, meta_dstInEventPortConsume_rev); }

		static Uml::AssociationRole meta_srcOutEventPortPublish, meta_srcOutEventPortPublish_rev;
		Udm::AClassAssocAttr<PICML::OutEventPortPublish, PICML::OutEventPort> srcOutEventPortPublish() const { return Udm::AClassAssocAttr<PICML::OutEventPortPublish, PICML::OutEventPort>(impl, meta_srcOutEventPortPublish, meta_srcOutEventPortPublish_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::OutEventPortPublish, PICML::OutEventPort, Pred> srcOutEventPortPublish_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::OutEventPortPublish, PICML::OutEventPort, Pred>(impl, meta_srcOutEventPortPublish, meta_srcOutEventPortPublish_rev); }

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  OutEventPortPublish :  public MgaObject {
	 public:
		static Uml::Class meta;

		OutEventPortPublish() { }
		OutEventPortPublish(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		OutEventPortPublish(const OutEventPortPublish &master) : MgaObject(master) { }
		static OutEventPortPublish Cast(const Object &a) { return __Cast(a, meta); }

		static OutEventPortPublish Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		OutEventPortPublish CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		OutEventPortPublish CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<OutEventPortPublish> Instances() { return Udm::InstantiatedAttr<PICML::OutEventPortPublish>(impl);}
		template <class Pred> Udm::InstantiatedAttr<OutEventPortPublish, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::OutEventPortPublish, Pred>(impl);}

		Udm::DerivedAttr<PICML::OutEventPortPublish> Derived() { return Udm::DerivedAttr<PICML::OutEventPortPublish>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::OutEventPortPublish, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::OutEventPortPublish, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::OutEventPortPublish> Archetype() { return Udm::ArchetypeAttr<PICML::OutEventPortPublish>(impl);}

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstOutEventPortPublish_end_;
		Udm::AssocEndAttr<PICML::PublishConnector> dstOutEventPortPublish_end() const { return Udm::AssocEndAttr<PICML::PublishConnector>(impl, meta_dstOutEventPortPublish_end_); }

		static Uml::AssociationRole meta_srcOutEventPortPublish_end_;
		Udm::AssocEndAttr<PICML::OutEventPort> srcOutEventPortPublish_end() const { return Udm::AssocEndAttr<PICML::OutEventPort>(impl, meta_srcOutEventPortPublish_end_); }

	};

	class  InEventPortConsume :  public MgaObject {
	 public:
		static Uml::Class meta;

		InEventPortConsume() { }
		InEventPortConsume(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		InEventPortConsume(const InEventPortConsume &master) : MgaObject(master) { }
		static InEventPortConsume Cast(const Object &a) { return __Cast(a, meta); }

		static InEventPortConsume Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		InEventPortConsume CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		InEventPortConsume CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<InEventPortConsume> Instances() { return Udm::InstantiatedAttr<PICML::InEventPortConsume>(impl);}
		template <class Pred> Udm::InstantiatedAttr<InEventPortConsume, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::InEventPortConsume, Pred>(impl);}

		Udm::DerivedAttr<PICML::InEventPortConsume> Derived() { return Udm::DerivedAttr<PICML::InEventPortConsume>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::InEventPortConsume, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::InEventPortConsume, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::InEventPortConsume> Archetype() { return Udm::ArchetypeAttr<PICML::InEventPortConsume>(impl);}

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_srcInEventPortConsume_end_;
		Udm::AssocEndAttr<PICML::PublishConnector> srcInEventPortConsume_end() const { return Udm::AssocEndAttr<PICML::PublishConnector>(impl, meta_srcInEventPortConsume_end_); }

		static Uml::AssociationRole meta_dstInEventPortConsume_end_;
		Udm::AssocEndAttr<PICML::InEventPort> dstInEventPortConsume_end() const { return Udm::AssocEndAttr<PICML::InEventPort>(impl, meta_dstInEventPortConsume_end_); }

	};

	class  ConnectionRequirements :  public MgaObject {
	 public:
		static Uml::Class meta;

		ConnectionRequirements() { }
		ConnectionRequirements(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ConnectionRequirements(const ConnectionRequirements &master) : MgaObject(master) { }
		static ConnectionRequirements Cast(const Object &a) { return __Cast(a, meta); }

		static ConnectionRequirements Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ConnectionRequirements CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ConnectionRequirements CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ConnectionRequirements> Instances() { return Udm::InstantiatedAttr<PICML::ConnectionRequirements>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ConnectionRequirements, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ConnectionRequirements, Pred>(impl);}

		Udm::DerivedAttr<PICML::ConnectionRequirements> Derived() { return Udm::DerivedAttr<PICML::ConnectionRequirements>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ConnectionRequirements, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ConnectionRequirements, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ConnectionRequirements> Archetype() { return Udm::ArchetypeAttr<PICML::ConnectionRequirements>(impl);}

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstConnectionRequirements_end_;
		Udm::AssocEndAttr<PICML::Requirement> dstConnectionRequirements_end() const { return Udm::AssocEndAttr<PICML::Requirement>(impl, meta_dstConnectionRequirements_end_); }

		static Uml::AssociationRole meta_srcConnectionRequirements_end_;
		Udm::AssocEndAttr<PICML::PublishConnector> srcConnectionRequirements_end() const { return Udm::AssocEndAttr<PICML::PublishConnector>(impl, meta_srcConnectionRequirements_end_); }

	};

	class  PackageInterface :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageInterface() { }
		PackageInterface(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageInterface(const PackageInterface &master) : MgaObject(master) { }
		static PackageInterface Cast(const Object &a) { return __Cast(a, meta); }

		static PackageInterface Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageInterface CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageInterface CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageInterface> Instances() { return Udm::InstantiatedAttr<PICML::PackageInterface>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageInterface, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageInterface, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageInterface> Derived() { return Udm::DerivedAttr<PICML::PackageInterface>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageInterface, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageInterface, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageInterface> Archetype() { return Udm::ArchetypeAttr<PICML::PackageInterface>(impl);}

		static Uml::CompositionParentRole meta_PackageContainer_parent;
		Udm::ParentAttr<PICML::PackageContainer> PackageContainer_parent() const { return Udm::ParentAttr<PICML::PackageContainer>(impl, meta_PackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstPackageInterface_end_;
		Udm::AssocEndAttr<PICML::ComponentType> dstPackageInterface_end() const { return Udm::AssocEndAttr<PICML::ComponentType>(impl, meta_dstPackageInterface_end_); }

		static Uml::AssociationRole meta_srcPackageInterface_end_;
		Udm::AssocEndAttr<PICML::ComponentPackage> srcPackageInterface_end() const { return Udm::AssocEndAttr<PICML::ComponentPackage>(impl, meta_srcPackageInterface_end_); }

	};

	class  PackageImplementations :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageImplementations() { }
		PackageImplementations(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageImplementations(const PackageImplementations &master) : MgaObject(master) { }
		static PackageImplementations Cast(const Object &a) { return __Cast(a, meta); }

		static PackageImplementations Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageImplementations CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageImplementations CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageImplementations> Instances() { return Udm::InstantiatedAttr<PICML::PackageImplementations>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageImplementations, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageImplementations, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageImplementations> Derived() { return Udm::DerivedAttr<PICML::PackageImplementations>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageImplementations, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageImplementations, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageImplementations> Archetype() { return Udm::ArchetypeAttr<PICML::PackageImplementations>(impl);}

		static Uml::CompositionParentRole meta_PackageContainer_parent;
		Udm::ParentAttr<PICML::PackageContainer> PackageContainer_parent() const { return Udm::ParentAttr<PICML::PackageContainer>(impl, meta_PackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstPackageImplementations_end_;
		Udm::AssocEndAttr<PICML::ComponentImplementationReference> dstPackageImplementations_end() const { return Udm::AssocEndAttr<PICML::ComponentImplementationReference>(impl, meta_dstPackageImplementations_end_); }

		static Uml::AssociationRole meta_srcPackageImplementations_end_;
		Udm::AssocEndAttr<PICML::ComponentPackage> srcPackageImplementations_end() const { return Udm::AssocEndAttr<PICML::ComponentPackage>(impl, meta_srcPackageImplementations_end_); }

	};

	class  PackageContainer :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageContainer() { }
		PackageContainer(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageContainer(const PackageContainer &master) : MgaObject(master) { }
		static PackageContainer Cast(const Object &a) { return __Cast(a, meta); }

		static PackageContainer Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageContainer CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageContainer CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageContainer> Instances() { return Udm::InstantiatedAttr<PICML::PackageContainer>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageContainer, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageContainer, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageContainer> Derived() { return Udm::DerivedAttr<PICML::PackageContainer>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageContainer, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageContainer, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageContainer> Archetype() { return Udm::ArchetypeAttr<PICML::PackageContainer>(impl);}

		static Uml::CompositionChildRole meta_PackageImplementations_children;
		Udm::ChildrenAttr<PICML::PackageImplementations> PackageImplementations_children() const { return Udm::ChildrenAttr<PICML::PackageImplementations>(impl, meta_PackageImplementations_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageImplementations, Pred> PackageImplementations_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageImplementations, Pred>(impl, meta_PackageImplementations_children); }

		static Uml::CompositionChildRole meta_PackageInterface_child;
		Udm::ChildAttr<PICML::PackageInterface> PackageInterface_child() const { return Udm::ChildAttr<PICML::PackageInterface>(impl, meta_PackageInterface_child); }

		static Uml::CompositionChildRole meta_ComponentImplementationReference_children;
		Udm::ChildrenAttr<PICML::ComponentImplementationReference> ComponentImplementationReference_children() const { return Udm::ChildrenAttr<PICML::ComponentImplementationReference>(impl, meta_ComponentImplementationReference_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentImplementationReference, Pred> ComponentImplementationReference_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentImplementationReference, Pred>(impl, meta_ComponentImplementationReference_children); }

		static Uml::CompositionChildRole meta_ComponentType_children;
		Udm::ChildrenAttr<PICML::ComponentType> ComponentType_children() const { return Udm::ChildrenAttr<PICML::ComponentType>(impl, meta_ComponentType_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ComponentType, Pred> ComponentType_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentType, Pred>(impl, meta_ComponentType_children); }

		static Uml::CompositionChildRole meta_PackageConfigProperty_children;
		Udm::ChildrenAttr<PICML::PackageConfigProperty> PackageConfigProperty_children() const { return Udm::ChildrenAttr<PICML::PackageConfigProperty>(impl, meta_PackageConfigProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageConfigProperty, Pred> PackageConfigProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigProperty, Pred>(impl, meta_PackageConfigProperty_children); }

		static Uml::CompositionChildRole meta_Property_children;
		Udm::ChildrenAttr<PICML::Property> Property_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, meta_Property_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, meta_Property_children); }

		static Uml::CompositionChildRole meta_PackageInfoProperty_children;
		Udm::ChildrenAttr<PICML::PackageInfoProperty> PackageInfoProperty_children() const { return Udm::ChildrenAttr<PICML::PackageInfoProperty>(impl, meta_PackageInfoProperty_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageInfoProperty, Pred> PackageInfoProperty_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageInfoProperty, Pred>(impl, meta_PackageInfoProperty_children); }

		static Uml::CompositionChildRole meta_ComponentPackage_child;
		Udm::ChildAttr<PICML::ComponentPackage> ComponentPackage_child() const { return Udm::ChildAttr<PICML::ComponentPackage>(impl, meta_ComponentPackage_child); }

		Udm::ChildrenAttr<PICML::ComponentType> ComponentType_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentType, Pred> ComponentType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentImplementationReference> ComponentImplementationReference_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentImplementationReference>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentImplementationReference, Pred> ComponentImplementationReference_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentImplementationReference, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Property> Property_kind_children() const { return Udm::ChildrenAttr<PICML::Property>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Property, Pred> Property_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Property, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageInterface> PackageInterface_kind_children() const { return Udm::ChildrenAttr<PICML::PackageInterface>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageInterface, Pred> PackageInterface_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageInterface, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageImplementations> PackageImplementations_kind_children() const { return Udm::ChildrenAttr<PICML::PackageImplementations>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageImplementations, Pred> PackageImplementations_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageImplementations, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageConfigProperty> PackageConfigProperty_kind_children() const { return Udm::ChildrenAttr<PICML::PackageConfigProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageConfigProperty, Pred> PackageConfigProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PackageInfoProperty> PackageInfoProperty_kind_children() const { return Udm::ChildrenAttr<PICML::PackageInfoProperty>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageInfoProperty, Pred> PackageInfoProperty_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageInfoProperty, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentPackage> ComponentPackage_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentPackage>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentPackage, Pred> ComponentPackage_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentPackage, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_ComponentPackages_parent;
		Udm::ParentAttr<PICML::ComponentPackages> ComponentPackages_parent() const { return Udm::ParentAttr<PICML::ComponentPackages>(impl, meta_ComponentPackages_parent); }

		Udm::ParentAttr<PICML::ComponentPackages> parent() const { return Udm::ParentAttr<PICML::ComponentPackages>(impl, Udm::NULLPARENTROLE); }
	};

	class  PackageConfigProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageConfigProperty() { }
		PackageConfigProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageConfigProperty(const PackageConfigProperty &master) : MgaObject(master) { }
		static PackageConfigProperty Cast(const Object &a) { return __Cast(a, meta); }

		static PackageConfigProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageConfigProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageConfigProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageConfigProperty> Instances() { return Udm::InstantiatedAttr<PICML::PackageConfigProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageConfigProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageConfigProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageConfigProperty> Derived() { return Udm::DerivedAttr<PICML::PackageConfigProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageConfigProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageConfigProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageConfigProperty> Archetype() { return Udm::ArchetypeAttr<PICML::PackageConfigProperty>(impl);}

		static Uml::CompositionParentRole meta_PackageContainer_parent;
		Udm::ParentAttr<PICML::PackageContainer> PackageContainer_parent() const { return Udm::ParentAttr<PICML::PackageContainer>(impl, meta_PackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstPackageConfigProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstPackageConfigProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstPackageConfigProperty_end_); }

		static Uml::AssociationRole meta_srcPackageConfigProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentPackage> srcPackageConfigProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentPackage>(impl, meta_srcPackageConfigProperty_end_); }

	};

	class  PackageInfoProperty :  public MgaObject {
	 public:
		static Uml::Class meta;

		PackageInfoProperty() { }
		PackageInfoProperty(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PackageInfoProperty(const PackageInfoProperty &master) : MgaObject(master) { }
		static PackageInfoProperty Cast(const Object &a) { return __Cast(a, meta); }

		static PackageInfoProperty Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PackageInfoProperty CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PackageInfoProperty CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PackageInfoProperty> Instances() { return Udm::InstantiatedAttr<PICML::PackageInfoProperty>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PackageInfoProperty, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PackageInfoProperty, Pred>(impl);}

		Udm::DerivedAttr<PICML::PackageInfoProperty> Derived() { return Udm::DerivedAttr<PICML::PackageInfoProperty>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PackageInfoProperty, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PackageInfoProperty, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PackageInfoProperty> Archetype() { return Udm::ArchetypeAttr<PICML::PackageInfoProperty>(impl);}

		static Uml::CompositionParentRole meta_PackageContainer_parent;
		Udm::ParentAttr<PICML::PackageContainer> PackageContainer_parent() const { return Udm::ParentAttr<PICML::PackageContainer>(impl, meta_PackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstPackageInfoProperty_end_;
		Udm::AssocEndAttr<PICML::Property> dstPackageInfoProperty_end() const { return Udm::AssocEndAttr<PICML::Property>(impl, meta_dstPackageInfoProperty_end_); }

		static Uml::AssociationRole meta_srcPackageInfoProperty_end_;
		Udm::AssocEndAttr<PICML::ComponentPackage> srcPackageInfoProperty_end() const { return Udm::AssocEndAttr<PICML::ComponentPackage>(impl, meta_srcPackageInfoProperty_end_); }

	};

	class  ComponentPackage :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentPackage() { }
		ComponentPackage(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentPackage(const ComponentPackage &master) : MgaObject(master) { }
		static ComponentPackage Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentPackage Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentPackage CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentPackage CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentPackage> Instances() { return Udm::InstantiatedAttr<PICML::ComponentPackage>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentPackage, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentPackage, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentPackage> Derived() { return Udm::DerivedAttr<PICML::ComponentPackage>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentPackage, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentPackage, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentPackage> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentPackage>(impl);}

		static Uml::AssociationRole meta_dstPackageInterface, meta_dstPackageInterface_rev;
		Udm::AClassPointerAttr<PICML::PackageInterface, PICML::ComponentType> dstPackageInterface() const { return Udm::AClassPointerAttr<PICML::PackageInterface, PICML::ComponentType>(impl, meta_dstPackageInterface, meta_dstPackageInterface_rev); }

		static Uml::AssociationRole meta_dstPackageImplementations, meta_dstPackageImplementations_rev;
		Udm::AClassAssocAttr<PICML::PackageImplementations, PICML::ComponentImplementationReference> dstPackageImplementations() const { return Udm::AClassAssocAttr<PICML::PackageImplementations, PICML::ComponentImplementationReference>(impl, meta_dstPackageImplementations, meta_dstPackageImplementations_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageImplementations, PICML::ComponentImplementationReference, Pred> dstPackageImplementations_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageImplementations, PICML::ComponentImplementationReference, Pred>(impl, meta_dstPackageImplementations, meta_dstPackageImplementations_rev); }

		static Uml::AssociationRole meta_dstPackageConfigProperty, meta_dstPackageConfigProperty_rev;
		Udm::AClassAssocAttr<PICML::PackageConfigProperty, PICML::Property> dstPackageConfigProperty() const { return Udm::AClassAssocAttr<PICML::PackageConfigProperty, PICML::Property>(impl, meta_dstPackageConfigProperty, meta_dstPackageConfigProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageConfigProperty, PICML::Property, Pred> dstPackageConfigProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageConfigProperty, PICML::Property, Pred>(impl, meta_dstPackageConfigProperty, meta_dstPackageConfigProperty_rev); }

		static Uml::AssociationRole meta_dstPackageInfoProperty, meta_dstPackageInfoProperty_rev;
		Udm::AClassAssocAttr<PICML::PackageInfoProperty, PICML::Property> dstPackageInfoProperty() const { return Udm::AClassAssocAttr<PICML::PackageInfoProperty, PICML::Property>(impl, meta_dstPackageInfoProperty, meta_dstPackageInfoProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageInfoProperty, PICML::Property, Pred> dstPackageInfoProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageInfoProperty, PICML::Property, Pred>(impl, meta_dstPackageInfoProperty, meta_dstPackageInfoProperty_rev); }

		static Uml::AssociationRole meta_srcPackageBaseConnection, meta_srcPackageBaseConnection_rev;
		Udm::AClassAssocAttr<PICML::PackageBaseConnection, PICML::PackageConfiguration> srcPackageBaseConnection() const { return Udm::AClassAssocAttr<PICML::PackageBaseConnection, PICML::PackageConfiguration>(impl, meta_srcPackageBaseConnection, meta_srcPackageBaseConnection_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageBaseConnection, PICML::PackageConfiguration, Pred> srcPackageBaseConnection_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageBaseConnection, PICML::PackageConfiguration, Pred>(impl, meta_srcPackageBaseConnection, meta_srcPackageBaseConnection_rev); }

		static Uml::AssociationRole meta_referedbyComponentPackageReference;
		Udm::AssocAttr<PICML::ComponentPackageReference> referedbyComponentPackageReference() const { return Udm::AssocAttr<PICML::ComponentPackageReference>(impl, meta_referedbyComponentPackageReference); }
		template <class Pred> Udm::AssocAttr<PICML::ComponentPackageReference, Pred > referedbyComponentPackageReference_sorted(const Pred &) const { return Udm::AssocAttr<PICML::ComponentPackageReference, Pred>(impl, meta_referedbyComponentPackageReference); }

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		static Uml::CompositionParentRole meta_PackageContainer_parent;
		Udm::ParentAttr<PICML::PackageContainer> PackageContainer_parent() const { return Udm::ParentAttr<PICML::PackageContainer>(impl, meta_PackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentPackageReference :  public MgaObject {
	 public:
		static Uml::Class meta;

		ComponentPackageReference() { }
		ComponentPackageReference(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ComponentPackageReference(const ComponentPackageReference &master) : MgaObject(master) { }
		static ComponentPackageReference Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentPackageReference Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentPackageReference CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentPackageReference CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentPackageReference> Instances() { return Udm::InstantiatedAttr<PICML::ComponentPackageReference>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentPackageReference, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentPackageReference, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentPackageReference> Derived() { return Udm::DerivedAttr<PICML::ComponentPackageReference>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentPackageReference, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentPackageReference, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentPackageReference> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentPackageReference>(impl);}

		static Uml::AssociationRole meta_srcPackageReferenceConnection, meta_srcPackageReferenceConnection_rev;
		Udm::AClassAssocAttr<PICML::PackageReferenceConnection, PICML::PackageConfiguration> srcPackageReferenceConnection() const { return Udm::AClassAssocAttr<PICML::PackageReferenceConnection, PICML::PackageConfiguration>(impl, meta_srcPackageReferenceConnection, meta_srcPackageReferenceConnection_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::PackageReferenceConnection, PICML::PackageConfiguration, Pred> srcPackageReferenceConnection_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::PackageReferenceConnection, PICML::PackageConfiguration, Pred>(impl, meta_srcPackageReferenceConnection, meta_srcPackageReferenceConnection_rev); }

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ComponentPackage> ref() const { return Udm::PointerAttr<PICML::ComponentPackage>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_PackageConfigurationContainer_parent;
		Udm::ParentAttr<PICML::PackageConfigurationContainer> PackageConfigurationContainer_parent() const { return Udm::ParentAttr<PICML::PackageConfigurationContainer>(impl, meta_PackageConfigurationContainer_parent); }

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  TopLevelPackageContainer :  public MgaObject {
	 public:
		static Uml::Class meta;

		TopLevelPackageContainer() { }
		TopLevelPackageContainer(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		TopLevelPackageContainer(const TopLevelPackageContainer &master) : MgaObject(master) { }
		static TopLevelPackageContainer Cast(const Object &a) { return __Cast(a, meta); }

		static TopLevelPackageContainer Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		TopLevelPackageContainer CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		TopLevelPackageContainer CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<TopLevelPackageContainer> Instances() { return Udm::InstantiatedAttr<PICML::TopLevelPackageContainer>(impl);}
		template <class Pred> Udm::InstantiatedAttr<TopLevelPackageContainer, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::TopLevelPackageContainer, Pred>(impl);}

		Udm::DerivedAttr<PICML::TopLevelPackageContainer> Derived() { return Udm::DerivedAttr<PICML::TopLevelPackageContainer>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::TopLevelPackageContainer, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::TopLevelPackageContainer, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::TopLevelPackageContainer> Archetype() { return Udm::ArchetypeAttr<PICML::TopLevelPackageContainer>(impl);}

		static Uml::CompositionChildRole meta_TopLevelPackage_children;
		Udm::ChildrenAttr<PICML::TopLevelPackage> TopLevelPackage_children() const { return Udm::ChildrenAttr<PICML::TopLevelPackage>(impl, meta_TopLevelPackage_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::TopLevelPackage, Pred> TopLevelPackage_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TopLevelPackage, Pred>(impl, meta_TopLevelPackage_children); }

		static Uml::CompositionChildRole meta_PackageConfigurationReference_children;
		Udm::ChildrenAttr<PICML::PackageConfigurationReference> PackageConfigurationReference_children() const { return Udm::ChildrenAttr<PICML::PackageConfigurationReference>(impl, meta_PackageConfigurationReference_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PackageConfigurationReference, Pred> PackageConfigurationReference_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigurationReference, Pred>(impl, meta_PackageConfigurationReference_children); }

		static Uml::CompositionChildRole meta_TopLevelPackageConn_children;
		Udm::ChildrenAttr<PICML::TopLevelPackageConn> TopLevelPackageConn_children() const { return Udm::ChildrenAttr<PICML::TopLevelPackageConn>(impl, meta_TopLevelPackageConn_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::TopLevelPackageConn, Pred> TopLevelPackageConn_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TopLevelPackageConn, Pred>(impl, meta_TopLevelPackageConn_children); }

		Udm::ChildrenAttr<PICML::PackageConfigurationReference> PackageConfigurationReference_kind_children() const { return Udm::ChildrenAttr<PICML::PackageConfigurationReference>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PackageConfigurationReference, Pred> PackageConfigurationReference_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PackageConfigurationReference, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::TopLevelPackage> TopLevelPackage_kind_children() const { return Udm::ChildrenAttr<PICML::TopLevelPackage>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::TopLevelPackage, Pred> TopLevelPackage_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TopLevelPackage, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::TopLevelPackageConn> TopLevelPackageConn_kind_children() const { return Udm::ChildrenAttr<PICML::TopLevelPackageConn>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::TopLevelPackageConn, Pred> TopLevelPackageConn_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TopLevelPackageConn, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_TopLevelPackageFolder_parent;
		Udm::ParentAttr<PICML::TopLevelPackageFolder> TopLevelPackageFolder_parent() const { return Udm::ParentAttr<PICML::TopLevelPackageFolder>(impl, meta_TopLevelPackageFolder_parent); }

		Udm::ParentAttr<PICML::TopLevelPackageFolder> parent() const { return Udm::ParentAttr<PICML::TopLevelPackageFolder>(impl, Udm::NULLPARENTROLE); }
	};

	class  TopLevelPackage :  public MgaObject {
	 public:
		static Uml::Class meta;

		TopLevelPackage() { }
		TopLevelPackage(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		TopLevelPackage(const TopLevelPackage &master) : MgaObject(master) { }
		static TopLevelPackage Cast(const Object &a) { return __Cast(a, meta); }

		static TopLevelPackage Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		TopLevelPackage CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		TopLevelPackage CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<TopLevelPackage> Instances() { return Udm::InstantiatedAttr<PICML::TopLevelPackage>(impl);}
		template <class Pred> Udm::InstantiatedAttr<TopLevelPackage, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::TopLevelPackage, Pred>(impl);}

		Udm::DerivedAttr<PICML::TopLevelPackage> Derived() { return Udm::DerivedAttr<PICML::TopLevelPackage>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::TopLevelPackage, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::TopLevelPackage, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::TopLevelPackage> Archetype() { return Udm::ArchetypeAttr<PICML::TopLevelPackage>(impl);}

		static Uml::AssociationRole meta_dstTopLevelPackageConn, meta_dstTopLevelPackageConn_rev;
		Udm::AClassPointerAttr<PICML::TopLevelPackageConn, PICML::PackageConfigurationReference> dstTopLevelPackageConn() const { return Udm::AClassPointerAttr<PICML::TopLevelPackageConn, PICML::PackageConfigurationReference>(impl, meta_dstTopLevelPackageConn, meta_dstTopLevelPackageConn_rev); }

		static Uml::CompositionParentRole meta_TopLevelPackageContainer_parent;
		Udm::ParentAttr<PICML::TopLevelPackageContainer> TopLevelPackageContainer_parent() const { return Udm::ParentAttr<PICML::TopLevelPackageContainer>(impl, meta_TopLevelPackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  TopLevelPackageConn :  public MgaObject {
	 public:
		static Uml::Class meta;

		TopLevelPackageConn() { }
		TopLevelPackageConn(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		TopLevelPackageConn(const TopLevelPackageConn &master) : MgaObject(master) { }
		static TopLevelPackageConn Cast(const Object &a) { return __Cast(a, meta); }

		static TopLevelPackageConn Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		TopLevelPackageConn CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		TopLevelPackageConn CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<TopLevelPackageConn> Instances() { return Udm::InstantiatedAttr<PICML::TopLevelPackageConn>(impl);}
		template <class Pred> Udm::InstantiatedAttr<TopLevelPackageConn, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::TopLevelPackageConn, Pred>(impl);}

		Udm::DerivedAttr<PICML::TopLevelPackageConn> Derived() { return Udm::DerivedAttr<PICML::TopLevelPackageConn>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::TopLevelPackageConn, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::TopLevelPackageConn, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::TopLevelPackageConn> Archetype() { return Udm::ArchetypeAttr<PICML::TopLevelPackageConn>(impl);}

		static Uml::CompositionParentRole meta_TopLevelPackageContainer_parent;
		Udm::ParentAttr<PICML::TopLevelPackageContainer> TopLevelPackageContainer_parent() const { return Udm::ParentAttr<PICML::TopLevelPackageContainer>(impl, meta_TopLevelPackageContainer_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstTopLevelPackageConn_end_;
		Udm::AssocEndAttr<PICML::PackageConfigurationReference> dstTopLevelPackageConn_end() const { return Udm::AssocEndAttr<PICML::PackageConfigurationReference>(impl, meta_dstTopLevelPackageConn_end_); }

		static Uml::AssociationRole meta_srcTopLevelPackageConn_end_;
		Udm::AssocEndAttr<PICML::TopLevelPackage> srcTopLevelPackageConn_end() const { return Udm::AssocEndAttr<PICML::TopLevelPackage>(impl, meta_srcTopLevelPackageConn_end_); }

	};

	class  EnumValue :  public MgaObject {
	 public:
		static Uml::Class meta;

		EnumValue() { }
		EnumValue(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		EnumValue(const EnumValue &master) : MgaObject(master) { }
		static EnumValue Cast(const Object &a) { return __Cast(a, meta); }

		static EnumValue Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EnumValue CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EnumValue CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EnumValue> Instances() { return Udm::InstantiatedAttr<PICML::EnumValue>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EnumValue, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::EnumValue, Pred>(impl);}

		Udm::DerivedAttr<PICML::EnumValue> Derived() { return Udm::DerivedAttr<PICML::EnumValue>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::EnumValue, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::EnumValue, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::EnumValue> Archetype() { return Udm::ArchetypeAttr<PICML::EnumValue>(impl);}

		static Uml::CompositionParentRole meta_EnumerationDef_parent;
		Udm::ParentAttr<PICML::EnumerationDef> EnumerationDef_parent() const { return Udm::ParentAttr<PICML::EnumerationDef>(impl, meta_EnumerationDef_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Label :  public MgaObject {
	 public:
		static Uml::Class meta;

		Label() { }
		Label(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Label(const Label &master) : MgaObject(master) { }
		static Label Cast(const Object &a) { return __Cast(a, meta); }

		static Label Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Label CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Label CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Label> Instances() { return Udm::InstantiatedAttr<PICML::Label>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Label, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Label, Pred>(impl);}

		Udm::DerivedAttr<PICML::Label> Derived() { return Udm::DerivedAttr<PICML::Label>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Label, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Label, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Label> Archetype() { return Udm::ArchetypeAttr<PICML::Label>(impl);}

		static Uml::AssociationRole meta_srcLabelConnection, meta_srcLabelConnection_rev;
		Udm::AClassPointerAttr<PICML::LabelConnection, PICML::Member> srcLabelConnection() const { return Udm::AClassPointerAttr<PICML::LabelConnection, PICML::Member>(impl, meta_srcLabelConnection, meta_srcLabelConnection_rev); }

		static Uml::CompositionParentRole meta_SwitchedAggregateDef_parent;
		Udm::ParentAttr<PICML::SwitchedAggregateDef> SwitchedAggregateDef_parent() const { return Udm::ParentAttr<PICML::SwitchedAggregateDef>(impl, meta_SwitchedAggregateDef_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Discriminator :  public MgaObject {
	 public:
		static Uml::Class meta;

		Discriminator() { }
		Discriminator(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Discriminator(const Discriminator &master) : MgaObject(master) { }
		static Discriminator Cast(const Object &a) { return __Cast(a, meta); }

		static Discriminator Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Discriminator CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Discriminator CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Discriminator> Instances() { return Udm::InstantiatedAttr<PICML::Discriminator>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Discriminator, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Discriminator, Pred>(impl);}

		Udm::DerivedAttr<PICML::Discriminator> Derived() { return Udm::DerivedAttr<PICML::Discriminator>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Discriminator, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Discriminator, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Discriminator> Archetype() { return Udm::ArchetypeAttr<PICML::Discriminator>(impl);}

		static Uml::CompositionChildRole meta_EnumRef_child;
		Udm::ChildAttr<PICML::EnumRef> EnumRef_child() const { return Udm::ChildAttr<PICML::EnumRef>(impl, meta_EnumRef_child); }

		static Uml::CompositionChildRole meta_PredefinedType_child;
		Udm::ChildAttr<PICML::PredefinedType> PredefinedType_child() const { return Udm::ChildAttr<PICML::PredefinedType>(impl, meta_PredefinedType_child); }

		Udm::ChildrenAttr<PICML::EnumRef> EnumRef_kind_children() const { return Udm::ChildrenAttr<PICML::EnumRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EnumRef, Pred> EnumRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EnumRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ParameterType> ParameterType_kind_children() const { return Udm::ChildrenAttr<PICML::ParameterType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ParameterType, Pred> ParameterType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ParameterType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Type> Type_kind_children() const { return Udm::ChildrenAttr<PICML::Type>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Type, Pred> Type_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Type, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_SwitchedAggregateDef_parent;
		Udm::ParentAttr<PICML::SwitchedAggregateDef> SwitchedAggregateDef_parent() const { return Udm::ParentAttr<PICML::SwitchedAggregateDef>(impl, meta_SwitchedAggregateDef_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  LabelConnection :  public MgaObject {
	 public:
		static Uml::Class meta;

		LabelConnection() { }
		LabelConnection(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		LabelConnection(const LabelConnection &master) : MgaObject(master) { }
		static LabelConnection Cast(const Object &a) { return __Cast(a, meta); }

		static LabelConnection Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		LabelConnection CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		LabelConnection CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<LabelConnection> Instances() { return Udm::InstantiatedAttr<PICML::LabelConnection>(impl);}
		template <class Pred> Udm::InstantiatedAttr<LabelConnection, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::LabelConnection, Pred>(impl);}

		Udm::DerivedAttr<PICML::LabelConnection> Derived() { return Udm::DerivedAttr<PICML::LabelConnection>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::LabelConnection, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::LabelConnection, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::LabelConnection> Archetype() { return Udm::ArchetypeAttr<PICML::LabelConnection>(impl);}

		static Uml::CompositionParentRole meta_SwitchedAggregateDef_parent;
		Udm::ParentAttr<PICML::SwitchedAggregateDef> SwitchedAggregateDef_parent() const { return Udm::ParentAttr<PICML::SwitchedAggregateDef>(impl, meta_SwitchedAggregateDef_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_dstLabelConnection_end_;
		Udm::AssocEndAttr<PICML::Label> dstLabelConnection_end() const { return Udm::AssocEndAttr<PICML::Label>(impl, meta_dstLabelConnection_end_); }

		static Uml::AssociationRole meta_srcLabelConnection_end_;
		Udm::AssocEndAttr<PICML::Member> srcLabelConnection_end() const { return Udm::AssocEndAttr<PICML::Member>(impl, meta_srcLabelConnection_end_); }

	};

	class  EnumRef :  public MgaObject {
	 public:
		static Uml::Class meta;

		EnumRef() { }
		EnumRef(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		EnumRef(const EnumRef &master) : MgaObject(master) { }
		static EnumRef Cast(const Object &a) { return __Cast(a, meta); }

		static EnumRef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EnumRef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EnumRef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EnumRef> Instances() { return Udm::InstantiatedAttr<PICML::EnumRef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EnumRef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::EnumRef, Pred>(impl);}

		Udm::DerivedAttr<PICML::EnumRef> Derived() { return Udm::DerivedAttr<PICML::EnumRef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::EnumRef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::EnumRef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::EnumRef> Archetype() { return Udm::ArchetypeAttr<PICML::EnumRef>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::EnumerationDef> ref() const { return Udm::PointerAttr<PICML::EnumerationDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_Discriminator_parent;
		Udm::ParentAttr<PICML::Discriminator> Discriminator_parent() const { return Udm::ParentAttr<PICML::Discriminator>(impl, meta_Discriminator_parent); }

		static Uml::CompositionParentRole meta_ConstantDef_parent;
		Udm::ParentAttr<PICML::ConstantDef> ConstantDef_parent() const { return Udm::ParentAttr<PICML::ConstantDef>(impl, meta_ConstantDef_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Member :  virtual public MgaObject {
	 public:
		static Uml::Class meta;

		Member() { }
		Member(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Member(const Member &master) : MgaObject(master) { }
		static Member Cast(const Object &a) { return __Cast(a, meta); }

		static Member Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Member CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Member CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Member> Instances() { return Udm::InstantiatedAttr<PICML::Member>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Member, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Member, Pred>(impl);}

		Udm::DerivedAttr<PICML::Member> Derived() { return Udm::DerivedAttr<PICML::Member>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Member, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Member, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Member> Archetype() { return Udm::ArchetypeAttr<PICML::Member>(impl);}

		static Uml::AssociationRole meta_dstLabelConnection, meta_dstLabelConnection_rev;
		Udm::AClassAssocAttr<PICML::LabelConnection, PICML::Label> dstLabelConnection() const { return Udm::AClassAssocAttr<PICML::LabelConnection, PICML::Label>(impl, meta_dstLabelConnection, meta_dstLabelConnection_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::LabelConnection, PICML::Label, Pred> dstLabelConnection_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::LabelConnection, PICML::Label, Pred>(impl, meta_dstLabelConnection, meta_dstLabelConnection_rev); }

		static Uml::AssociationRole meta_dstMakeMemberPrivate, meta_dstMakeMemberPrivate_rev;
		Udm::AClassPointerAttr<PICML::MakeMemberPrivate, PICML::PrivateFlag> dstMakeMemberPrivate() const { return Udm::AClassPointerAttr<PICML::MakeMemberPrivate, PICML::PrivateFlag>(impl, meta_dstMakeMemberPrivate, meta_dstMakeMemberPrivate_rev); }

		static Uml::CompositionParentRole meta_AliasDef_parent;
		Udm::ParentAttr<PICML::AliasDef> AliasDef_parent() const { return Udm::ParentAttr<PICML::AliasDef>(impl, meta_AliasDef_parent); }

		static Uml::CompositionParentRole meta_AggregateDef_parent;
		Udm::ParentAttr<PICML::AggregateDef> AggregateDef_parent() const { return Udm::ParentAttr<PICML::AggregateDef>(impl, meta_AggregateDef_parent); }

		static Uml::CompositionParentRole meta_SwitchedAggregateDef_parent;
		Udm::ParentAttr<PICML::SwitchedAggregateDef> SwitchedAggregateDef_parent() const { return Udm::ParentAttr<PICML::SwitchedAggregateDef>(impl, meta_SwitchedAggregateDef_parent); }

		static Uml::CompositionParentRole meta_BoxedDef_parent;
		Udm::ParentAttr<PICML::BoxedDef> BoxedDef_parent() const { return Udm::ParentAttr<PICML::BoxedDef>(impl, meta_BoxedDef_parent); }

		static Uml::CompositionParentRole meta_ExceptionDef_parent;
		Udm::ParentAttr<PICML::ExceptionDef> ExceptionDef_parent() const { return Udm::ParentAttr<PICML::ExceptionDef>(impl, meta_ExceptionDef_parent); }

		static Uml::CompositionParentRole meta_CollectionType_parent;
		Udm::ParentAttr<PICML::CollectionType> CollectionType_parent() const { return Udm::ParentAttr<PICML::CollectionType>(impl, meta_CollectionType_parent); }

		static Uml::CompositionParentRole meta_ReadonlyAttribute_parent;
		Udm::ParentAttr<PICML::ReadonlyAttribute> ReadonlyAttribute_parent() const { return Udm::ParentAttr<PICML::ReadonlyAttribute>(impl, meta_ReadonlyAttribute_parent); }

		static Uml::CompositionParentRole meta_ObjectByValue_parent;
		Udm::ParentAttr<PICML::ObjectByValue> ObjectByValue_parent() const { return Udm::ParentAttr<PICML::ObjectByValue>(impl, meta_ObjectByValue_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  IdTag :  public MgaObject {
	 public:
		static Uml::Class meta;

		IdTag() { }
		IdTag(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		IdTag(const IdTag &master) : MgaObject(master) { }
		static IdTag Cast(const Object &a) { return __Cast(a, meta); }

		static IdTag Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		IdTag CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		IdTag CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<IdTag> Instances() { return Udm::InstantiatedAttr<PICML::IdTag>(impl);}
		template <class Pred> Udm::InstantiatedAttr<IdTag, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::IdTag, Pred>(impl);}

		Udm::DerivedAttr<PICML::IdTag> Derived() { return Udm::DerivedAttr<PICML::IdTag>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::IdTag, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::IdTag, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::IdTag> Archetype() { return Udm::ArchetypeAttr<PICML::IdTag>(impl);}

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  PrefixTag :  public IdTag {
	 public:
		static Uml::Class meta;

		PrefixTag() { }
		PrefixTag(Udm::ObjectImpl *impl) : IdTag(impl) { }
		PrefixTag(const PrefixTag &master) : IdTag(master) { }
		static PrefixTag Cast(const Object &a) { return __Cast(a, meta); }

		static PrefixTag Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PrefixTag CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PrefixTag CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PrefixTag> Instances() { return Udm::InstantiatedAttr<PICML::PrefixTag>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PrefixTag, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PrefixTag, Pred>(impl);}

		Udm::DerivedAttr<PICML::PrefixTag> Derived() { return Udm::DerivedAttr<PICML::PrefixTag>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PrefixTag, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PrefixTag, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PrefixTag> Archetype() { return Udm::ArchetypeAttr<PICML::PrefixTag>(impl);}

		static Uml::CompositionParentRole meta_Prefixable_parent;
		Udm::ParentAttr<PICML::Prefixable> Prefixable_parent() const { return Udm::ParentAttr<PICML::Prefixable>(impl, meta_Prefixable_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  GeneralTag :  public IdTag {
	 public:
		static Uml::Class meta;

		GeneralTag() { }
		GeneralTag(Udm::ObjectImpl *impl) : IdTag(impl) { }
		GeneralTag(const GeneralTag &master) : IdTag(master) { }
		static GeneralTag Cast(const Object &a) { return __Cast(a, meta); }

		static GeneralTag Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		GeneralTag CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		GeneralTag CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<GeneralTag> Instances() { return Udm::InstantiatedAttr<PICML::GeneralTag>(impl);}
		template <class Pred> Udm::InstantiatedAttr<GeneralTag, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::GeneralTag, Pred>(impl);}

		Udm::DerivedAttr<PICML::GeneralTag> Derived() { return Udm::DerivedAttr<PICML::GeneralTag>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::GeneralTag, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::GeneralTag, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::GeneralTag> Archetype() { return Udm::ArchetypeAttr<PICML::GeneralTag>(impl);}

		static Uml::CompositionParentRole meta_Taggable_parent;
		Udm::ParentAttr<PICML::Taggable> Taggable_parent() const { return Udm::ParentAttr<PICML::Taggable>(impl, meta_Taggable_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  SpecifyIdTag :  public GeneralTag {
	 public:
		static Uml::Class meta;

		SpecifyIdTag() { }
		SpecifyIdTag(Udm::ObjectImpl *impl) : GeneralTag(impl) { }
		SpecifyIdTag(const SpecifyIdTag &master) : GeneralTag(master) { }
		static SpecifyIdTag Cast(const Object &a) { return __Cast(a, meta); }

		static SpecifyIdTag Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		SpecifyIdTag CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		SpecifyIdTag CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<SpecifyIdTag> Instances() { return Udm::InstantiatedAttr<PICML::SpecifyIdTag>(impl);}
		template <class Pred> Udm::InstantiatedAttr<SpecifyIdTag, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::SpecifyIdTag, Pred>(impl);}

		Udm::DerivedAttr<PICML::SpecifyIdTag> Derived() { return Udm::DerivedAttr<PICML::SpecifyIdTag>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::SpecifyIdTag, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::SpecifyIdTag, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::SpecifyIdTag> Archetype() { return Udm::ArchetypeAttr<PICML::SpecifyIdTag>(impl);}

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  VersionTag :  public GeneralTag {
	 public:
		static Uml::Class meta;

		VersionTag() { }
		VersionTag(Udm::ObjectImpl *impl) : GeneralTag(impl) { }
		VersionTag(const VersionTag &master) : GeneralTag(master) { }
		static VersionTag Cast(const Object &a) { return __Cast(a, meta); }

		static VersionTag Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		VersionTag CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		VersionTag CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<VersionTag> Instances() { return Udm::InstantiatedAttr<PICML::VersionTag>(impl);}
		template <class Pred> Udm::InstantiatedAttr<VersionTag, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::VersionTag, Pred>(impl);}

		Udm::DerivedAttr<PICML::VersionTag> Derived() { return Udm::DerivedAttr<PICML::VersionTag>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::VersionTag, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::VersionTag, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::VersionTag> Archetype() { return Udm::ArchetypeAttr<PICML::VersionTag>(impl);}

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Prefixable :  virtual public MgaObject {
	 public:
		static Uml::Class meta;

		Prefixable() { }
		Prefixable(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Prefixable(const Prefixable &master) : MgaObject(master) { }
		static Prefixable Cast(const Object &a) { return __Cast(a, meta); }

		static Prefixable Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Prefixable CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Prefixable CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Prefixable> Instances() { return Udm::InstantiatedAttr<PICML::Prefixable>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Prefixable, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Prefixable, Pred>(impl);}

		Udm::DerivedAttr<PICML::Prefixable> Derived() { return Udm::DerivedAttr<PICML::Prefixable>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Prefixable, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Prefixable, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Prefixable> Archetype() { return Udm::ArchetypeAttr<PICML::Prefixable>(impl);}

		static Uml::CompositionChildRole meta_PrefixTag_child;
		Udm::ChildAttr<PICML::PrefixTag> PrefixTag_child() const { return Udm::ChildAttr<PICML::PrefixTag>(impl, meta_PrefixTag_child); }

		Udm::ChildrenAttr<PICML::IdTag> IdTag_kind_children() const { return Udm::ChildrenAttr<PICML::IdTag>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::IdTag, Pred> IdTag_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::IdTag, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PrefixTag> PrefixTag_kind_children() const { return Udm::ChildrenAttr<PICML::PrefixTag>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PrefixTag, Pred> PrefixTag_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PrefixTag, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  IDLFile :  public Prefixable {
	 public:
		static Uml::Class meta;

		IDLFile() { }
		IDLFile(Udm::ObjectImpl *impl) : Prefixable(impl), MgaObject(impl) { }
		IDLFile(const IDLFile &master) : Prefixable(master), MgaObject(master) { }
		static IDLFile Cast(const Object &a) { return __Cast(a, meta); }

		static IDLFile Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		IDLFile CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		IDLFile CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<IDLFile> Instances() { return Udm::InstantiatedAttr<PICML::IDLFile>(impl);}
		template <class Pred> Udm::InstantiatedAttr<IDLFile, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::IDLFile, Pred>(impl);}

		Udm::DerivedAttr<PICML::IDLFile> Derived() { return Udm::DerivedAttr<PICML::IDLFile>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::IDLFile, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::IDLFile, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::IDLFile> Archetype() { return Udm::ArchetypeAttr<PICML::IDLFile>(impl);}

		static Uml::AssociationRole meta_referedbyFileRef;
		Udm::AssocAttr<PICML::FileRef> referedbyFileRef() const { return Udm::AssocAttr<PICML::FileRef>(impl, meta_referedbyFileRef); }
		template <class Pred> Udm::AssocAttr<PICML::FileRef, Pred > referedbyFileRef_sorted(const Pred &) const { return Udm::AssocAttr<PICML::FileRef, Pred>(impl, meta_referedbyFileRef); }

		static Uml::CompositionChildRole meta_Package_children;
		Udm::ChildrenAttr<PICML::Package> Package_children() const { return Udm::ChildrenAttr<PICML::Package>(impl, meta_Package_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Package, Pred> Package_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Package, Pred>(impl, meta_Package_children); }

		static Uml::CompositionChildRole meta_ConstantDef_children;
		Udm::ChildrenAttr<PICML::ConstantDef> ConstantDef_children() const { return Udm::ChildrenAttr<PICML::ConstantDef>(impl, meta_ConstantDef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ConstantDef, Pred> ConstantDef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConstantDef, Pred>(impl, meta_ConstantDef_children); }

		static Uml::CompositionChildRole meta_ExceptionDef_children;
		Udm::ChildrenAttr<PICML::ExceptionDef> ExceptionDef_children() const { return Udm::ChildrenAttr<PICML::ExceptionDef>(impl, meta_ExceptionDef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ExceptionDef, Pred> ExceptionDef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ExceptionDef, Pred>(impl, meta_ExceptionDef_children); }

		static Uml::CompositionChildRole meta_NamedType_children;
		Udm::ChildrenAttr<PICML::NamedType> NamedType_children() const { return Udm::ChildrenAttr<PICML::NamedType>(impl, meta_NamedType_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::NamedType, Pred> NamedType_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedType, Pred>(impl, meta_NamedType_children); }

		static Uml::CompositionChildRole meta_FileRef_children;
		Udm::ChildrenAttr<PICML::FileRef> FileRef_children() const { return Udm::ChildrenAttr<PICML::FileRef>(impl, meta_FileRef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::FileRef, Pred> FileRef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FileRef, Pred>(impl, meta_FileRef_children); }

		Udm::ChildrenAttr<PICML::EnumerationDef> EnumerationDef_kind_children() const { return Udm::ChildrenAttr<PICML::EnumerationDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EnumerationDef, Pred> EnumerationDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EnumerationDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AliasDef> AliasDef_kind_children() const { return Udm::ChildrenAttr<PICML::AliasDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AliasDef, Pred> AliasDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AliasDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AggregateDef> AggregateDef_kind_children() const { return Udm::ChildrenAttr<PICML::AggregateDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AggregateDef, Pred> AggregateDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AggregateDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SwitchedAggregateDef> SwitchedAggregateDef_kind_children() const { return Udm::ChildrenAttr<PICML::SwitchedAggregateDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SwitchedAggregateDef, Pred> SwitchedAggregateDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SwitchedAggregateDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoxedDef> BoxedDef_kind_children() const { return Udm::ChildrenAttr<PICML::BoxedDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoxedDef, Pred> BoxedDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoxedDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::NamedType> NamedType_kind_children() const { return Udm::ChildrenAttr<PICML::NamedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedType, Pred> NamedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::NoInheritable> NoInheritable_kind_children() const { return Udm::ChildrenAttr<PICML::NoInheritable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NoInheritable, Pred> NoInheritable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NoInheritable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Prefixable> Prefixable_kind_children() const { return Udm::ChildrenAttr<PICML::Prefixable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Prefixable, Pred> Prefixable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Prefixable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Taggable> Taggable_kind_children() const { return Udm::ChildrenAttr<PICML::Taggable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Taggable, Pred> Taggable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Taggable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Package> Package_kind_children() const { return Udm::ChildrenAttr<PICML::Package>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Package, Pred> Package_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Package, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Type> Type_kind_children() const { return Udm::ChildrenAttr<PICML::Type>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Type, Pred> Type_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Type, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FileRef> FileRef_kind_children() const { return Udm::ChildrenAttr<PICML::FileRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FileRef, Pred> FileRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FileRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ConstantDef> ConstantDef_kind_children() const { return Udm::ChildrenAttr<PICML::ConstantDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ConstantDef, Pred> ConstantDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConstantDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ExceptionDef> ExceptionDef_kind_children() const { return Udm::ChildrenAttr<PICML::ExceptionDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ExceptionDef, Pred> ExceptionDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ExceptionDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentDef> ComponentDef_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentDef, Pred> ComponentDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ObjectDef> ObjectDef_kind_children() const { return Udm::ChildrenAttr<PICML::ObjectDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ObjectDef, Pred> ObjectDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ObjectDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentFactory> ComponentFactory_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentFactory>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentFactory, Pred> ComponentFactory_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentFactory, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::EventDef> EventDef_kind_children() const { return Udm::ChildrenAttr<PICML::EventDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EventDef, Pred> EventDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EventDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ValueDef> ValueDef_kind_children() const { return Udm::ChildrenAttr<PICML::ValueDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ValueDef, Pred> ValueDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ValueDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Inheritable> Inheritable_kind_children() const { return Udm::ChildrenAttr<PICML::Inheritable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Inheritable, Pred> Inheritable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Inheritable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::HasOperations> HasOperations_kind_children() const { return Udm::ChildrenAttr<PICML::HasOperations>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::HasOperations, Pred> HasOperations_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::HasOperations, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SupportsInterfaces> SupportsInterfaces_kind_children() const { return Udm::ChildrenAttr<PICML::SupportsInterfaces>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SupportsInterfaces, Pred> SupportsInterfaces_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SupportsInterfaces, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ObjectByValue> ObjectByValue_kind_children() const { return Udm::ChildrenAttr<PICML::ObjectByValue>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ObjectByValue, Pred> ObjectByValue_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ObjectByValue, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_IDLFiles_parent;
		Udm::ParentAttr<PICML::IDLFiles> IDLFiles_parent() const { return Udm::ParentAttr<PICML::IDLFiles>(impl, meta_IDLFiles_parent); }

		Udm::ParentAttr<PICML::IDLFiles> parent() const { return Udm::ParentAttr<PICML::IDLFiles>(impl, Udm::NULLPARENTROLE); }
	};

	class  Taggable :  virtual public MgaObject {
	 public:
		static Uml::Class meta;

		Taggable() { }
		Taggable(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Taggable(const Taggable &master) : MgaObject(master) { }
		static Taggable Cast(const Object &a) { return __Cast(a, meta); }

		static Taggable Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Taggable CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Taggable CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Taggable> Instances() { return Udm::InstantiatedAttr<PICML::Taggable>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Taggable, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Taggable, Pred>(impl);}

		Udm::DerivedAttr<PICML::Taggable> Derived() { return Udm::DerivedAttr<PICML::Taggable>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Taggable, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Taggable, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Taggable> Archetype() { return Udm::ArchetypeAttr<PICML::Taggable>(impl);}

		static Uml::CompositionChildRole meta_GeneralTag_child;
		Udm::ChildAttr<PICML::GeneralTag> GeneralTag_child() const { return Udm::ChildAttr<PICML::GeneralTag>(impl, meta_GeneralTag_child); }

		Udm::ChildrenAttr<PICML::IdTag> IdTag_kind_children() const { return Udm::ChildrenAttr<PICML::IdTag>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::IdTag, Pred> IdTag_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::IdTag, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::GeneralTag> GeneralTag_kind_children() const { return Udm::ChildrenAttr<PICML::GeneralTag>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::GeneralTag, Pred> GeneralTag_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::GeneralTag, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SpecifyIdTag> SpecifyIdTag_kind_children() const { return Udm::ChildrenAttr<PICML::SpecifyIdTag>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SpecifyIdTag, Pred> SpecifyIdTag_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SpecifyIdTag, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VersionTag> VersionTag_kind_children() const { return Udm::ChildrenAttr<PICML::VersionTag>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VersionTag, Pred> VersionTag_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VersionTag, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  ParameterType :  virtual public MgaObject {
	 public:
		static Uml::Class meta;

		ParameterType() { }
		ParameterType(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ParameterType(const ParameterType &master) : MgaObject(master) { }
		static ParameterType Cast(const Object &a) { return __Cast(a, meta); }

		static ParameterType Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ParameterType CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ParameterType CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ParameterType> Instances() { return Udm::InstantiatedAttr<PICML::ParameterType>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ParameterType, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ParameterType, Pred>(impl);}

		Udm::DerivedAttr<PICML::ParameterType> Derived() { return Udm::DerivedAttr<PICML::ParameterType>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ParameterType, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ParameterType, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ParameterType> Archetype() { return Udm::ArchetypeAttr<PICML::ParameterType>(impl);}

		static Uml::CompositionParentRole meta_Parameter_parent;
		Udm::ParentAttr<PICML::Parameter> Parameter_parent() const { return Udm::ParentAttr<PICML::Parameter>(impl, meta_Parameter_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  NamedTypeRef :  public Member, public ParameterType {
	 public:
		static Uml::Class meta;

		NamedTypeRef() { }
		NamedTypeRef(Udm::ObjectImpl *impl) : Member(impl),ParameterType(impl), MgaObject(impl) { }
		NamedTypeRef(const NamedTypeRef &master) : Member(master),ParameterType(master), MgaObject(master) { }
		static NamedTypeRef Cast(const Object &a) { return __Cast(a, meta); }

		static NamedTypeRef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		NamedTypeRef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		NamedTypeRef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<NamedTypeRef> Instances() { return Udm::InstantiatedAttr<PICML::NamedTypeRef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<NamedTypeRef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::NamedTypeRef, Pred>(impl);}

		Udm::DerivedAttr<PICML::NamedTypeRef> Derived() { return Udm::DerivedAttr<PICML::NamedTypeRef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::NamedTypeRef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::NamedTypeRef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::NamedTypeRef> Archetype() { return Udm::ArchetypeAttr<PICML::NamedTypeRef>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::NamedType> ref() const { return Udm::PointerAttr<PICML::NamedType>(impl, meta_ref); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  OperationBase :  public Taggable {
	 public:
		static Uml::Class meta;

		OperationBase() { }
		OperationBase(Udm::ObjectImpl *impl) : Taggable(impl), MgaObject(impl) { }
		OperationBase(const OperationBase &master) : Taggable(master), MgaObject(master) { }
		static OperationBase Cast(const Object &a) { return __Cast(a, meta); }

		static OperationBase Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		OperationBase CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		OperationBase CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<OperationBase> Instances() { return Udm::InstantiatedAttr<PICML::OperationBase>(impl);}
		template <class Pred> Udm::InstantiatedAttr<OperationBase, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::OperationBase, Pred>(impl);}

		Udm::DerivedAttr<PICML::OperationBase> Derived() { return Udm::DerivedAttr<PICML::OperationBase>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::OperationBase, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::OperationBase, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::OperationBase> Archetype() { return Udm::ArchetypeAttr<PICML::OperationBase>(impl);}

		static Uml::CompositionChildRole meta_InParameter_children;
		Udm::ChildrenAttr<PICML::InParameter> InParameter_children() const { return Udm::ChildrenAttr<PICML::InParameter>(impl, meta_InParameter_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::InParameter, Pred> InParameter_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InParameter, Pred>(impl, meta_InParameter_children); }

		Udm::ChildrenAttr<PICML::InParameter> InParameter_kind_children() const { return Udm::ChildrenAttr<PICML::InParameter>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::InParameter, Pred> InParameter_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InParameter, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Parameter> Parameter_kind_children() const { return Udm::ChildrenAttr<PICML::Parameter>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Parameter, Pred> Parameter_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Parameter, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  Parameter :  public MgaObject {
	 public:
		static Uml::Class meta;

		Parameter() { }
		Parameter(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Parameter(const Parameter &master) : MgaObject(master) { }
		static Parameter Cast(const Object &a) { return __Cast(a, meta); }

		static Parameter Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Parameter CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Parameter CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Parameter> Instances() { return Udm::InstantiatedAttr<PICML::Parameter>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Parameter, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Parameter, Pred>(impl);}

		Udm::DerivedAttr<PICML::Parameter> Derived() { return Udm::DerivedAttr<PICML::Parameter>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Parameter, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Parameter, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Parameter> Archetype() { return Udm::ArchetypeAttr<PICML::Parameter>(impl);}

		static Uml::CompositionChildRole meta_ParameterType_child;
		Udm::ChildAttr<PICML::ParameterType> ParameterType_child() const { return Udm::ChildAttr<PICML::ParameterType>(impl, meta_ParameterType_child); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ParameterType> ParameterType_kind_children() const { return Udm::ChildrenAttr<PICML::ParameterType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ParameterType, Pred> ParameterType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ParameterType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  ReturnType :  public Parameter {
	 public:
		static Uml::Class meta;

		ReturnType() { }
		ReturnType(Udm::ObjectImpl *impl) : Parameter(impl) { }
		ReturnType(const ReturnType &master) : Parameter(master) { }
		static ReturnType Cast(const Object &a) { return __Cast(a, meta); }

		static ReturnType Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ReturnType CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ReturnType CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ReturnType> Instances() { return Udm::InstantiatedAttr<PICML::ReturnType>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ReturnType, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ReturnType, Pred>(impl);}

		Udm::DerivedAttr<PICML::ReturnType> Derived() { return Udm::DerivedAttr<PICML::ReturnType>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ReturnType, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ReturnType, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ReturnType> Archetype() { return Udm::ArchetypeAttr<PICML::ReturnType>(impl);}

		static Uml::CompositionParentRole meta_TwowayOperation_parent;
		Udm::ParentAttr<PICML::TwowayOperation> TwowayOperation_parent() const { return Udm::ParentAttr<PICML::TwowayOperation>(impl, meta_TwowayOperation_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  InParameter :  public Parameter {
	 public:
		static Uml::Class meta;

		InParameter() { }
		InParameter(Udm::ObjectImpl *impl) : Parameter(impl) { }
		InParameter(const InParameter &master) : Parameter(master) { }
		static InParameter Cast(const Object &a) { return __Cast(a, meta); }

		static InParameter Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		InParameter CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		InParameter CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<InParameter> Instances() { return Udm::InstantiatedAttr<PICML::InParameter>(impl);}
		template <class Pred> Udm::InstantiatedAttr<InParameter, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::InParameter, Pred>(impl);}

		Udm::DerivedAttr<PICML::InParameter> Derived() { return Udm::DerivedAttr<PICML::InParameter>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::InParameter, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::InParameter, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::InParameter> Archetype() { return Udm::ArchetypeAttr<PICML::InParameter>(impl);}

		static Uml::CompositionParentRole meta_OperationBase_parent;
		Udm::ParentAttr<PICML::OperationBase> OperationBase_parent() const { return Udm::ParentAttr<PICML::OperationBase>(impl, meta_OperationBase_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  InoutParameter :  public Parameter {
	 public:
		static Uml::Class meta;

		InoutParameter() { }
		InoutParameter(Udm::ObjectImpl *impl) : Parameter(impl) { }
		InoutParameter(const InoutParameter &master) : Parameter(master) { }
		static InoutParameter Cast(const Object &a) { return __Cast(a, meta); }

		static InoutParameter Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		InoutParameter CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		InoutParameter CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<InoutParameter> Instances() { return Udm::InstantiatedAttr<PICML::InoutParameter>(impl);}
		template <class Pred> Udm::InstantiatedAttr<InoutParameter, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::InoutParameter, Pred>(impl);}

		Udm::DerivedAttr<PICML::InoutParameter> Derived() { return Udm::DerivedAttr<PICML::InoutParameter>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::InoutParameter, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::InoutParameter, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::InoutParameter> Archetype() { return Udm::ArchetypeAttr<PICML::InoutParameter>(impl);}

		static Uml::CompositionParentRole meta_TwowayOperation_parent;
		Udm::ParentAttr<PICML::TwowayOperation> TwowayOperation_parent() const { return Udm::ParentAttr<PICML::TwowayOperation>(impl, meta_TwowayOperation_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  OutParameter :  public Parameter {
	 public:
		static Uml::Class meta;

		OutParameter() { }
		OutParameter(Udm::ObjectImpl *impl) : Parameter(impl) { }
		OutParameter(const OutParameter &master) : Parameter(master) { }
		static OutParameter Cast(const Object &a) { return __Cast(a, meta); }

		static OutParameter Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		OutParameter CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		OutParameter CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<OutParameter> Instances() { return Udm::InstantiatedAttr<PICML::OutParameter>(impl);}
		template <class Pred> Udm::InstantiatedAttr<OutParameter, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::OutParameter, Pred>(impl);}

		Udm::DerivedAttr<PICML::OutParameter> Derived() { return Udm::DerivedAttr<PICML::OutParameter>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::OutParameter, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::OutParameter, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::OutParameter> Archetype() { return Udm::ArchetypeAttr<PICML::OutParameter>(impl);}

		static Uml::CompositionParentRole meta_TwowayOperation_parent;
		Udm::ParentAttr<PICML::TwowayOperation> TwowayOperation_parent() const { return Udm::ParentAttr<PICML::TwowayOperation>(impl, meta_TwowayOperation_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  HasExceptions :  public OperationBase {
	 public:
		static Uml::Class meta;

		HasExceptions() { }
		HasExceptions(Udm::ObjectImpl *impl) : OperationBase(impl), MgaObject(impl) { }
		HasExceptions(const HasExceptions &master) : OperationBase(master), MgaObject(master) { }
		static HasExceptions Cast(const Object &a) { return __Cast(a, meta); }

		static HasExceptions Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		HasExceptions CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		HasExceptions CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<HasExceptions> Instances() { return Udm::InstantiatedAttr<PICML::HasExceptions>(impl);}
		template <class Pred> Udm::InstantiatedAttr<HasExceptions, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::HasExceptions, Pred>(impl);}

		Udm::DerivedAttr<PICML::HasExceptions> Derived() { return Udm::DerivedAttr<PICML::HasExceptions>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::HasExceptions, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::HasExceptions, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::HasExceptions> Archetype() { return Udm::ArchetypeAttr<PICML::HasExceptions>(impl);}

		static Uml::CompositionChildRole meta_ExceptionRef_children;
		Udm::ChildrenAttr<PICML::ExceptionRef> ExceptionRef_children() const { return Udm::ChildrenAttr<PICML::ExceptionRef>(impl, meta_ExceptionRef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ExceptionRef, Pred> ExceptionRef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ExceptionRef, Pred>(impl, meta_ExceptionRef_children); }

		Udm::ChildrenAttr<PICML::ExceptionRef> ExceptionRef_kind_children() const { return Udm::ChildrenAttr<PICML::ExceptionRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ExceptionRef, Pred> ExceptionRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ExceptionRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  OnewayOperation :  public OperationBase {
	 public:
		static Uml::Class meta;

		OnewayOperation() { }
		OnewayOperation(Udm::ObjectImpl *impl) : OperationBase(impl), MgaObject(impl) { }
		OnewayOperation(const OnewayOperation &master) : OperationBase(master), MgaObject(master) { }
		static OnewayOperation Cast(const Object &a) { return __Cast(a, meta); }

		static OnewayOperation Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		OnewayOperation CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		OnewayOperation CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<OnewayOperation> Instances() { return Udm::InstantiatedAttr<PICML::OnewayOperation>(impl);}
		template <class Pred> Udm::InstantiatedAttr<OnewayOperation, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::OnewayOperation, Pred>(impl);}

		Udm::DerivedAttr<PICML::OnewayOperation> Derived() { return Udm::DerivedAttr<PICML::OnewayOperation>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::OnewayOperation, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::OnewayOperation, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::OnewayOperation> Archetype() { return Udm::ArchetypeAttr<PICML::OnewayOperation>(impl);}

		static Uml::CompositionParentRole meta_HasOperations_parent;
		Udm::ParentAttr<PICML::HasOperations> HasOperations_parent() const { return Udm::ParentAttr<PICML::HasOperations>(impl, meta_HasOperations_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  LookupOperation :  public HasExceptions {
	 public:
		static Uml::Class meta;

		LookupOperation() { }
		LookupOperation(Udm::ObjectImpl *impl) : HasExceptions(impl), MgaObject(impl) { }
		LookupOperation(const LookupOperation &master) : HasExceptions(master), MgaObject(master) { }
		static LookupOperation Cast(const Object &a) { return __Cast(a, meta); }

		static LookupOperation Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		LookupOperation CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		LookupOperation CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<LookupOperation> Instances() { return Udm::InstantiatedAttr<PICML::LookupOperation>(impl);}
		template <class Pred> Udm::InstantiatedAttr<LookupOperation, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::LookupOperation, Pred>(impl);}

		Udm::DerivedAttr<PICML::LookupOperation> Derived() { return Udm::DerivedAttr<PICML::LookupOperation>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::LookupOperation, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::LookupOperation, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::LookupOperation> Archetype() { return Udm::ArchetypeAttr<PICML::LookupOperation>(impl);}

		static Uml::CompositionParentRole meta_ComponentFactory_parent;
		Udm::ParentAttr<PICML::ComponentFactory> ComponentFactory_parent() const { return Udm::ParentAttr<PICML::ComponentFactory>(impl, meta_ComponentFactory_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  FactoryOperation :  public HasExceptions {
	 public:
		static Uml::Class meta;

		FactoryOperation() { }
		FactoryOperation(Udm::ObjectImpl *impl) : HasExceptions(impl), MgaObject(impl) { }
		FactoryOperation(const FactoryOperation &master) : HasExceptions(master), MgaObject(master) { }
		static FactoryOperation Cast(const Object &a) { return __Cast(a, meta); }

		static FactoryOperation Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		FactoryOperation CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		FactoryOperation CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<FactoryOperation> Instances() { return Udm::InstantiatedAttr<PICML::FactoryOperation>(impl);}
		template <class Pred> Udm::InstantiatedAttr<FactoryOperation, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::FactoryOperation, Pred>(impl);}

		Udm::DerivedAttr<PICML::FactoryOperation> Derived() { return Udm::DerivedAttr<PICML::FactoryOperation>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::FactoryOperation, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::FactoryOperation, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::FactoryOperation> Archetype() { return Udm::ArchetypeAttr<PICML::FactoryOperation>(impl);}

		static Uml::CompositionParentRole meta_ObjectByValue_parent;
		Udm::ParentAttr<PICML::ObjectByValue> ObjectByValue_parent() const { return Udm::ParentAttr<PICML::ObjectByValue>(impl, meta_ObjectByValue_parent); }

		static Uml::CompositionParentRole meta_ComponentFactory_parent;
		Udm::ParentAttr<PICML::ComponentFactory> ComponentFactory_parent() const { return Udm::ParentAttr<PICML::ComponentFactory>(impl, meta_ComponentFactory_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  TwowayOperation :  public HasExceptions {
	 public:
		static Uml::Class meta;

		TwowayOperation() { }
		TwowayOperation(Udm::ObjectImpl *impl) : HasExceptions(impl), MgaObject(impl) { }
		TwowayOperation(const TwowayOperation &master) : HasExceptions(master), MgaObject(master) { }
		static TwowayOperation Cast(const Object &a) { return __Cast(a, meta); }

		static TwowayOperation Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		TwowayOperation CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		TwowayOperation CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<TwowayOperation> Instances() { return Udm::InstantiatedAttr<PICML::TwowayOperation>(impl);}
		template <class Pred> Udm::InstantiatedAttr<TwowayOperation, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::TwowayOperation, Pred>(impl);}

		Udm::DerivedAttr<PICML::TwowayOperation> Derived() { return Udm::DerivedAttr<PICML::TwowayOperation>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::TwowayOperation, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::TwowayOperation, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::TwowayOperation> Archetype() { return Udm::ArchetypeAttr<PICML::TwowayOperation>(impl);}

		static Uml::CompositionChildRole meta_OutParameter_children;
		Udm::ChildrenAttr<PICML::OutParameter> OutParameter_children() const { return Udm::ChildrenAttr<PICML::OutParameter>(impl, meta_OutParameter_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::OutParameter, Pred> OutParameter_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OutParameter, Pred>(impl, meta_OutParameter_children); }

		static Uml::CompositionChildRole meta_InoutParameter_children;
		Udm::ChildrenAttr<PICML::InoutParameter> InoutParameter_children() const { return Udm::ChildrenAttr<PICML::InoutParameter>(impl, meta_InoutParameter_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::InoutParameter, Pred> InoutParameter_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InoutParameter, Pred>(impl, meta_InoutParameter_children); }

		static Uml::CompositionChildRole meta_ReturnType_children;
		Udm::ChildrenAttr<PICML::ReturnType> ReturnType_children() const { return Udm::ChildrenAttr<PICML::ReturnType>(impl, meta_ReturnType_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ReturnType, Pred> ReturnType_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ReturnType, Pred>(impl, meta_ReturnType_children); }

		Udm::ChildrenAttr<PICML::ReturnType> ReturnType_kind_children() const { return Udm::ChildrenAttr<PICML::ReturnType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ReturnType, Pred> ReturnType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ReturnType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::InoutParameter> InoutParameter_kind_children() const { return Udm::ChildrenAttr<PICML::InoutParameter>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::InoutParameter, Pred> InoutParameter_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InoutParameter, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::OutParameter> OutParameter_kind_children() const { return Udm::ChildrenAttr<PICML::OutParameter>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::OutParameter, Pred> OutParameter_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OutParameter, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Parameter> Parameter_kind_children() const { return Udm::ChildrenAttr<PICML::Parameter>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Parameter, Pred> Parameter_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Parameter, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_HasOperations_parent;
		Udm::ParentAttr<PICML::HasOperations> HasOperations_parent() const { return Udm::ParentAttr<PICML::HasOperations>(impl, meta_HasOperations_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Package :  public Prefixable, public Taggable {
	 public:
		static Uml::Class meta;

		Package() { }
		Package(Udm::ObjectImpl *impl) : Prefixable(impl),Taggable(impl), MgaObject(impl) { }
		Package(const Package &master) : Prefixable(master),Taggable(master), MgaObject(master) { }
		static Package Cast(const Object &a) { return __Cast(a, meta); }

		static Package Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Package CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Package CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Package> Instances() { return Udm::InstantiatedAttr<PICML::Package>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Package, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Package, Pred>(impl);}

		Udm::DerivedAttr<PICML::Package> Derived() { return Udm::DerivedAttr<PICML::Package>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Package, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Package, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Package> Archetype() { return Udm::ArchetypeAttr<PICML::Package>(impl);}

		static Uml::CompositionChildRole meta_ConstantDef_children;
		Udm::ChildrenAttr<PICML::ConstantDef> ConstantDef_children() const { return Udm::ChildrenAttr<PICML::ConstantDef>(impl, meta_ConstantDef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ConstantDef, Pred> ConstantDef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConstantDef, Pred>(impl, meta_ConstantDef_children); }

		static Uml::CompositionChildRole meta_Package_children;
		Udm::ChildrenAttr<PICML::Package> Package_children() const { return Udm::ChildrenAttr<PICML::Package>(impl, meta_Package_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Package, Pred> Package_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Package, Pred>(impl, meta_Package_children); }

		static Uml::CompositionChildRole meta_ExceptionDef_children;
		Udm::ChildrenAttr<PICML::ExceptionDef> ExceptionDef_children() const { return Udm::ChildrenAttr<PICML::ExceptionDef>(impl, meta_ExceptionDef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ExceptionDef, Pred> ExceptionDef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ExceptionDef, Pred>(impl, meta_ExceptionDef_children); }

		static Uml::CompositionChildRole meta_NamedType_children;
		Udm::ChildrenAttr<PICML::NamedType> NamedType_children() const { return Udm::ChildrenAttr<PICML::NamedType>(impl, meta_NamedType_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::NamedType, Pred> NamedType_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedType, Pred>(impl, meta_NamedType_children); }

		Udm::ChildrenAttr<PICML::EnumerationDef> EnumerationDef_kind_children() const { return Udm::ChildrenAttr<PICML::EnumerationDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EnumerationDef, Pred> EnumerationDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EnumerationDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AliasDef> AliasDef_kind_children() const { return Udm::ChildrenAttr<PICML::AliasDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AliasDef, Pred> AliasDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AliasDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AggregateDef> AggregateDef_kind_children() const { return Udm::ChildrenAttr<PICML::AggregateDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AggregateDef, Pred> AggregateDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AggregateDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SwitchedAggregateDef> SwitchedAggregateDef_kind_children() const { return Udm::ChildrenAttr<PICML::SwitchedAggregateDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SwitchedAggregateDef, Pred> SwitchedAggregateDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SwitchedAggregateDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoxedDef> BoxedDef_kind_children() const { return Udm::ChildrenAttr<PICML::BoxedDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoxedDef, Pred> BoxedDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoxedDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::NamedType> NamedType_kind_children() const { return Udm::ChildrenAttr<PICML::NamedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedType, Pred> NamedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::NoInheritable> NoInheritable_kind_children() const { return Udm::ChildrenAttr<PICML::NoInheritable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NoInheritable, Pred> NoInheritable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NoInheritable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Prefixable> Prefixable_kind_children() const { return Udm::ChildrenAttr<PICML::Prefixable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Prefixable, Pred> Prefixable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Prefixable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Taggable> Taggable_kind_children() const { return Udm::ChildrenAttr<PICML::Taggable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Taggable, Pred> Taggable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Taggable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Package> Package_kind_children() const { return Udm::ChildrenAttr<PICML::Package>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Package, Pred> Package_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Package, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Type> Type_kind_children() const { return Udm::ChildrenAttr<PICML::Type>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Type, Pred> Type_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Type, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ConstantDef> ConstantDef_kind_children() const { return Udm::ChildrenAttr<PICML::ConstantDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ConstantDef, Pred> ConstantDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConstantDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ExceptionDef> ExceptionDef_kind_children() const { return Udm::ChildrenAttr<PICML::ExceptionDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ExceptionDef, Pred> ExceptionDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ExceptionDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentDef> ComponentDef_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentDef, Pred> ComponentDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ObjectDef> ObjectDef_kind_children() const { return Udm::ChildrenAttr<PICML::ObjectDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ObjectDef, Pred> ObjectDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ObjectDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ComponentFactory> ComponentFactory_kind_children() const { return Udm::ChildrenAttr<PICML::ComponentFactory>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ComponentFactory, Pred> ComponentFactory_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ComponentFactory, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::EventDef> EventDef_kind_children() const { return Udm::ChildrenAttr<PICML::EventDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EventDef, Pred> EventDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EventDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ValueDef> ValueDef_kind_children() const { return Udm::ChildrenAttr<PICML::ValueDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ValueDef, Pred> ValueDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ValueDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Inheritable> Inheritable_kind_children() const { return Udm::ChildrenAttr<PICML::Inheritable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Inheritable, Pred> Inheritable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Inheritable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::HasOperations> HasOperations_kind_children() const { return Udm::ChildrenAttr<PICML::HasOperations>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::HasOperations, Pred> HasOperations_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::HasOperations, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SupportsInterfaces> SupportsInterfaces_kind_children() const { return Udm::ChildrenAttr<PICML::SupportsInterfaces>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SupportsInterfaces, Pred> SupportsInterfaces_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SupportsInterfaces, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ObjectByValue> ObjectByValue_kind_children() const { return Udm::ChildrenAttr<PICML::ObjectByValue>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ObjectByValue, Pred> ObjectByValue_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ObjectByValue, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_IDLFile_parent;
		Udm::ParentAttr<PICML::IDLFile> IDLFile_parent() const { return Udm::ParentAttr<PICML::IDLFile>(impl, meta_IDLFile_parent); }

		static Uml::CompositionParentRole meta_Package_parent;
		Udm::ParentAttr<PICML::Package> Package_parent() const { return Udm::ParentAttr<PICML::Package>(impl, meta_Package_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Type :  virtual public MgaObject {
	 public:
		static Uml::Class meta;

		Type() { }
		Type(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Type(const Type &master) : MgaObject(master) { }
		static Type Cast(const Object &a) { return __Cast(a, meta); }

		static Type Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Type CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Type CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Type> Instances() { return Udm::InstantiatedAttr<PICML::Type>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Type, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Type, Pred>(impl);}

		Udm::DerivedAttr<PICML::Type> Derived() { return Udm::DerivedAttr<PICML::Type>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Type, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Type, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Type> Archetype() { return Udm::ArchetypeAttr<PICML::Type>(impl);}

		Udm::ParentAttr<Udm::Object> parent() const { return Udm::ParentAttr<Udm::Object>(impl, Udm::NULLPARENTROLE); }
	};

	class  NamedType :  public Taggable, public Type {
	 public:
		static Uml::Class meta;

		NamedType() { }
		NamedType(Udm::ObjectImpl *impl) : Taggable(impl),Type(impl), MgaObject(impl) { }
		NamedType(const NamedType &master) : Taggable(master),Type(master), MgaObject(master) { }
		static NamedType Cast(const Object &a) { return __Cast(a, meta); }

		static NamedType Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		NamedType CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		NamedType CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<NamedType> Instances() { return Udm::InstantiatedAttr<PICML::NamedType>(impl);}
		template <class Pred> Udm::InstantiatedAttr<NamedType, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::NamedType, Pred>(impl);}

		Udm::DerivedAttr<PICML::NamedType> Derived() { return Udm::DerivedAttr<PICML::NamedType>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::NamedType, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::NamedType, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::NamedType> Archetype() { return Udm::ArchetypeAttr<PICML::NamedType>(impl);}

		static Uml::AssociationRole meta_referedbyNamedTypeRef;
		Udm::AssocAttr<PICML::NamedTypeRef> referedbyNamedTypeRef() const { return Udm::AssocAttr<PICML::NamedTypeRef>(impl, meta_referedbyNamedTypeRef); }
		template <class Pred> Udm::AssocAttr<PICML::NamedTypeRef, Pred > referedbyNamedTypeRef_sorted(const Pred &) const { return Udm::AssocAttr<PICML::NamedTypeRef, Pred>(impl, meta_referedbyNamedTypeRef); }

		static Uml::CompositionParentRole meta_IDLFile_parent;
		Udm::ParentAttr<PICML::IDLFile> IDLFile_parent() const { return Udm::ParentAttr<PICML::IDLFile>(impl, meta_IDLFile_parent); }

		static Uml::CompositionParentRole meta_Package_parent;
		Udm::ParentAttr<PICML::Package> Package_parent() const { return Udm::ParentAttr<PICML::Package>(impl, meta_Package_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  BoxedDef :  public NamedType {
	 public:
		static Uml::Class meta;

		BoxedDef() { }
		BoxedDef(Udm::ObjectImpl *impl) : NamedType(impl), MgaObject(impl) { }
		BoxedDef(const BoxedDef &master) : NamedType(master), MgaObject(master) { }
		static BoxedDef Cast(const Object &a) { return __Cast(a, meta); }

		static BoxedDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		BoxedDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		BoxedDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<BoxedDef> Instances() { return Udm::InstantiatedAttr<PICML::BoxedDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<BoxedDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::BoxedDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::BoxedDef> Derived() { return Udm::DerivedAttr<PICML::BoxedDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::BoxedDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::BoxedDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::BoxedDef> Archetype() { return Udm::ArchetypeAttr<PICML::BoxedDef>(impl);}

		static Uml::CompositionChildRole meta_Member_child;
		Udm::ChildAttr<PICML::Member> Member_child() const { return Udm::ChildAttr<PICML::Member>(impl, meta_Member_child); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedSizeCollection> FixedSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::FixedSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred> FixedSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VariableSizeCollection> VariableSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::VariableSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred> VariableSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::CollectionType> CollectionType_kind_children() const { return Udm::ChildrenAttr<PICML::CollectionType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CollectionType, Pred> CollectionType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CollectionType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  NoInheritable :  public NamedType {
	 public:
		static Uml::Class meta;

		NoInheritable() { }
		NoInheritable(Udm::ObjectImpl *impl) : NamedType(impl), MgaObject(impl) { }
		NoInheritable(const NoInheritable &master) : NamedType(master), MgaObject(master) { }
		static NoInheritable Cast(const Object &a) { return __Cast(a, meta); }

		static NoInheritable Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		NoInheritable CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		NoInheritable CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<NoInheritable> Instances() { return Udm::InstantiatedAttr<PICML::NoInheritable>(impl);}
		template <class Pred> Udm::InstantiatedAttr<NoInheritable, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::NoInheritable, Pred>(impl);}

		Udm::DerivedAttr<PICML::NoInheritable> Derived() { return Udm::DerivedAttr<PICML::NoInheritable>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::NoInheritable, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::NoInheritable, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::NoInheritable> Archetype() { return Udm::ArchetypeAttr<PICML::NoInheritable>(impl);}

		static Uml::CompositionParentRole meta_HasOperations_parent;
		Udm::ParentAttr<PICML::HasOperations> HasOperations_parent() const { return Udm::ParentAttr<PICML::HasOperations>(impl, meta_HasOperations_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  EnumerationDef :  public NoInheritable {
	 public:
		static Uml::Class meta;

		EnumerationDef() { }
		EnumerationDef(Udm::ObjectImpl *impl) : NoInheritable(impl), MgaObject(impl) { }
		EnumerationDef(const EnumerationDef &master) : NoInheritable(master), MgaObject(master) { }
		static EnumerationDef Cast(const Object &a) { return __Cast(a, meta); }

		static EnumerationDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EnumerationDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EnumerationDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EnumerationDef> Instances() { return Udm::InstantiatedAttr<PICML::EnumerationDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EnumerationDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::EnumerationDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::EnumerationDef> Derived() { return Udm::DerivedAttr<PICML::EnumerationDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::EnumerationDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::EnumerationDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::EnumerationDef> Archetype() { return Udm::ArchetypeAttr<PICML::EnumerationDef>(impl);}

		static Uml::AssociationRole meta_referedbyEnumRef;
		Udm::AssocAttr<PICML::EnumRef> referedbyEnumRef() const { return Udm::AssocAttr<PICML::EnumRef>(impl, meta_referedbyEnumRef); }
		template <class Pred> Udm::AssocAttr<PICML::EnumRef, Pred > referedbyEnumRef_sorted(const Pred &) const { return Udm::AssocAttr<PICML::EnumRef, Pred>(impl, meta_referedbyEnumRef); }

		static Uml::CompositionChildRole meta_EnumValue_children;
		Udm::ChildrenAttr<PICML::EnumValue> EnumValue_children() const { return Udm::ChildrenAttr<PICML::EnumValue>(impl, meta_EnumValue_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::EnumValue, Pred> EnumValue_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EnumValue, Pred>(impl, meta_EnumValue_children); }

		Udm::ChildrenAttr<PICML::EnumValue> EnumValue_kind_children() const { return Udm::ChildrenAttr<PICML::EnumValue>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EnumValue, Pred> EnumValue_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EnumValue, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  AliasDef :  public NoInheritable {
	 public:
		static Uml::Class meta;

		AliasDef() { }
		AliasDef(Udm::ObjectImpl *impl) : NoInheritable(impl), MgaObject(impl) { }
		AliasDef(const AliasDef &master) : NoInheritable(master), MgaObject(master) { }
		static AliasDef Cast(const Object &a) { return __Cast(a, meta); }

		static AliasDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		AliasDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		AliasDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<AliasDef> Instances() { return Udm::InstantiatedAttr<PICML::AliasDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<AliasDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::AliasDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::AliasDef> Derived() { return Udm::DerivedAttr<PICML::AliasDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::AliasDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::AliasDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::AliasDef> Archetype() { return Udm::ArchetypeAttr<PICML::AliasDef>(impl);}

		static Uml::CompositionChildRole meta_Member_child;
		Udm::ChildAttr<PICML::Member> Member_child() const { return Udm::ChildAttr<PICML::Member>(impl, meta_Member_child); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedSizeCollection> FixedSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::FixedSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred> FixedSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VariableSizeCollection> VariableSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::VariableSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred> VariableSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::CollectionType> CollectionType_kind_children() const { return Udm::ChildrenAttr<PICML::CollectionType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CollectionType, Pred> CollectionType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CollectionType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  AggregateDef :  public NoInheritable {
	 public:
		static Uml::Class meta;

		AggregateDef() { }
		AggregateDef(Udm::ObjectImpl *impl) : NoInheritable(impl), MgaObject(impl) { }
		AggregateDef(const AggregateDef &master) : NoInheritable(master), MgaObject(master) { }
		static AggregateDef Cast(const Object &a) { return __Cast(a, meta); }

		static AggregateDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		AggregateDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		AggregateDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<AggregateDef> Instances() { return Udm::InstantiatedAttr<PICML::AggregateDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<AggregateDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::AggregateDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::AggregateDef> Derived() { return Udm::DerivedAttr<PICML::AggregateDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::AggregateDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::AggregateDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::AggregateDef> Archetype() { return Udm::ArchetypeAttr<PICML::AggregateDef>(impl);}

		static Uml::CompositionChildRole meta_Member_children;
		Udm::ChildrenAttr<PICML::Member> Member_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, meta_Member_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, meta_Member_children); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedSizeCollection> FixedSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::FixedSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred> FixedSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VariableSizeCollection> VariableSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::VariableSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred> VariableSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::CollectionType> CollectionType_kind_children() const { return Udm::ChildrenAttr<PICML::CollectionType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CollectionType, Pred> CollectionType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CollectionType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  SwitchedAggregateDef :  public NoInheritable {
	 public:
		static Uml::Class meta;

		SwitchedAggregateDef() { }
		SwitchedAggregateDef(Udm::ObjectImpl *impl) : NoInheritable(impl), MgaObject(impl) { }
		SwitchedAggregateDef(const SwitchedAggregateDef &master) : NoInheritable(master), MgaObject(master) { }
		static SwitchedAggregateDef Cast(const Object &a) { return __Cast(a, meta); }

		static SwitchedAggregateDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		SwitchedAggregateDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		SwitchedAggregateDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<SwitchedAggregateDef> Instances() { return Udm::InstantiatedAttr<PICML::SwitchedAggregateDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<SwitchedAggregateDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::SwitchedAggregateDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::SwitchedAggregateDef> Derived() { return Udm::DerivedAttr<PICML::SwitchedAggregateDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::SwitchedAggregateDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::SwitchedAggregateDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::SwitchedAggregateDef> Archetype() { return Udm::ArchetypeAttr<PICML::SwitchedAggregateDef>(impl);}

		static Uml::CompositionChildRole meta_LabelConnection_children;
		Udm::ChildrenAttr<PICML::LabelConnection> LabelConnection_children() const { return Udm::ChildrenAttr<PICML::LabelConnection>(impl, meta_LabelConnection_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::LabelConnection, Pred> LabelConnection_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::LabelConnection, Pred>(impl, meta_LabelConnection_children); }

		static Uml::CompositionChildRole meta_Discriminator_child;
		Udm::ChildAttr<PICML::Discriminator> Discriminator_child() const { return Udm::ChildAttr<PICML::Discriminator>(impl, meta_Discriminator_child); }

		static Uml::CompositionChildRole meta_Label_children;
		Udm::ChildrenAttr<PICML::Label> Label_children() const { return Udm::ChildrenAttr<PICML::Label>(impl, meta_Label_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Label, Pred> Label_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Label, Pred>(impl, meta_Label_children); }

		static Uml::CompositionChildRole meta_Member_children;
		Udm::ChildrenAttr<PICML::Member> Member_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, meta_Member_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, meta_Member_children); }

		Udm::ChildrenAttr<PICML::Label> Label_kind_children() const { return Udm::ChildrenAttr<PICML::Label>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Label, Pred> Label_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Label, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Discriminator> Discriminator_kind_children() const { return Udm::ChildrenAttr<PICML::Discriminator>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Discriminator, Pred> Discriminator_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Discriminator, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::LabelConnection> LabelConnection_kind_children() const { return Udm::ChildrenAttr<PICML::LabelConnection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::LabelConnection, Pred> LabelConnection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::LabelConnection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedSizeCollection> FixedSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::FixedSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred> FixedSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VariableSizeCollection> VariableSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::VariableSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred> VariableSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::CollectionType> CollectionType_kind_children() const { return Udm::ChildrenAttr<PICML::CollectionType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CollectionType, Pred> CollectionType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CollectionType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ExceptionRef :  public MgaObject {
	 public:
		static Uml::Class meta;

		ExceptionRef() { }
		ExceptionRef(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ExceptionRef(const ExceptionRef &master) : MgaObject(master) { }
		static ExceptionRef Cast(const Object &a) { return __Cast(a, meta); }

		static ExceptionRef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ExceptionRef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ExceptionRef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ExceptionRef> Instances() { return Udm::InstantiatedAttr<PICML::ExceptionRef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ExceptionRef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ExceptionRef, Pred>(impl);}

		Udm::DerivedAttr<PICML::ExceptionRef> Derived() { return Udm::DerivedAttr<PICML::ExceptionRef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ExceptionRef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ExceptionRef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ExceptionRef> Archetype() { return Udm::ArchetypeAttr<PICML::ExceptionRef>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ExceptionDef> ref() const { return Udm::PointerAttr<PICML::ExceptionDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_HasExceptions_parent;
		Udm::ParentAttr<PICML::HasExceptions> HasExceptions_parent() const { return Udm::ParentAttr<PICML::HasExceptions>(impl, meta_HasExceptions_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  FileRef :  public MgaObject {
	 public:
		static Uml::Class meta;

		FileRef() { }
		FileRef(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		FileRef(const FileRef &master) : MgaObject(master) { }
		static FileRef Cast(const Object &a) { return __Cast(a, meta); }

		static FileRef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		FileRef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		FileRef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<FileRef> Instances() { return Udm::InstantiatedAttr<PICML::FileRef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<FileRef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::FileRef, Pred>(impl);}

		Udm::DerivedAttr<PICML::FileRef> Derived() { return Udm::DerivedAttr<PICML::FileRef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::FileRef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::FileRef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::FileRef> Archetype() { return Udm::ArchetypeAttr<PICML::FileRef>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::IDLFile> ref() const { return Udm::PointerAttr<PICML::IDLFile>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_IDLFile_parent;
		Udm::ParentAttr<PICML::IDLFile> IDLFile_parent() const { return Udm::ParentAttr<PICML::IDLFile>(impl, meta_IDLFile_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ConstantDef :  public Taggable {
	 public:
		static Uml::Class meta;

		ConstantDef() { }
		ConstantDef(Udm::ObjectImpl *impl) : Taggable(impl), MgaObject(impl) { }
		ConstantDef(const ConstantDef &master) : Taggable(master), MgaObject(master) { }
		static ConstantDef Cast(const Object &a) { return __Cast(a, meta); }

		static ConstantDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ConstantDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ConstantDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ConstantDef> Instances() { return Udm::InstantiatedAttr<PICML::ConstantDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ConstantDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ConstantDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::ConstantDef> Derived() { return Udm::DerivedAttr<PICML::ConstantDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ConstantDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ConstantDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ConstantDef> Archetype() { return Udm::ArchetypeAttr<PICML::ConstantDef>(impl);}

		static Uml::Attribute meta_value;
		Udm::StringAttr value() const { return Udm::StringAttr(impl, meta_value); }

		static Uml::CompositionChildRole meta_BoundedString_child;
		Udm::ChildAttr<PICML::BoundedString> BoundedString_child() const { return Udm::ChildAttr<PICML::BoundedString>(impl, meta_BoundedString_child); }

		static Uml::CompositionChildRole meta_PredefinedType_child;
		Udm::ChildAttr<PICML::PredefinedType> PredefinedType_child() const { return Udm::ChildAttr<PICML::PredefinedType>(impl, meta_PredefinedType_child); }

		static Uml::CompositionChildRole meta_EnumRef_child;
		Udm::ChildAttr<PICML::EnumRef> EnumRef_child() const { return Udm::ChildAttr<PICML::EnumRef>(impl, meta_EnumRef_child); }

		static Uml::CompositionChildRole meta_FixedPoint_child;
		Udm::ChildAttr<PICML::FixedPoint> FixedPoint_child() const { return Udm::ChildAttr<PICML::FixedPoint>(impl, meta_FixedPoint_child); }

		Udm::ChildrenAttr<PICML::EnumRef> EnumRef_kind_children() const { return Udm::ChildrenAttr<PICML::EnumRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EnumRef, Pred> EnumRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EnumRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ParameterType> ParameterType_kind_children() const { return Udm::ChildrenAttr<PICML::ParameterType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ParameterType, Pred> ParameterType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ParameterType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Type> Type_kind_children() const { return Udm::ChildrenAttr<PICML::Type>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Type, Pred> Type_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Type, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_IDLFile_parent;
		Udm::ParentAttr<PICML::IDLFile> IDLFile_parent() const { return Udm::ParentAttr<PICML::IDLFile>(impl, meta_IDLFile_parent); }

		static Uml::CompositionParentRole meta_Package_parent;
		Udm::ParentAttr<PICML::Package> Package_parent() const { return Udm::ParentAttr<PICML::Package>(impl, meta_Package_parent); }

		static Uml::CompositionParentRole meta_HasOperations_parent;
		Udm::ParentAttr<PICML::HasOperations> HasOperations_parent() const { return Udm::ParentAttr<PICML::HasOperations>(impl, meta_HasOperations_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ExceptionDef :  public Taggable {
	 public:
		static Uml::Class meta;

		ExceptionDef() { }
		ExceptionDef(Udm::ObjectImpl *impl) : Taggable(impl), MgaObject(impl) { }
		ExceptionDef(const ExceptionDef &master) : Taggable(master), MgaObject(master) { }
		static ExceptionDef Cast(const Object &a) { return __Cast(a, meta); }

		static ExceptionDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ExceptionDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ExceptionDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ExceptionDef> Instances() { return Udm::InstantiatedAttr<PICML::ExceptionDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ExceptionDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ExceptionDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::ExceptionDef> Derived() { return Udm::DerivedAttr<PICML::ExceptionDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ExceptionDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ExceptionDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ExceptionDef> Archetype() { return Udm::ArchetypeAttr<PICML::ExceptionDef>(impl);}

		static Uml::AssociationRole meta_referedbyExceptionRef;
		Udm::AssocAttr<PICML::ExceptionRef> referedbyExceptionRef() const { return Udm::AssocAttr<PICML::ExceptionRef>(impl, meta_referedbyExceptionRef); }
		template <class Pred> Udm::AssocAttr<PICML::ExceptionRef, Pred > referedbyExceptionRef_sorted(const Pred &) const { return Udm::AssocAttr<PICML::ExceptionRef, Pred>(impl, meta_referedbyExceptionRef); }

		static Uml::AssociationRole meta_referedbySetException;
		Udm::AssocAttr<PICML::SetException> referedbySetException() const { return Udm::AssocAttr<PICML::SetException>(impl, meta_referedbySetException); }
		template <class Pred> Udm::AssocAttr<PICML::SetException, Pred > referedbySetException_sorted(const Pred &) const { return Udm::AssocAttr<PICML::SetException, Pred>(impl, meta_referedbySetException); }

		static Uml::AssociationRole meta_referedbyGetException;
		Udm::AssocAttr<PICML::GetException> referedbyGetException() const { return Udm::AssocAttr<PICML::GetException>(impl, meta_referedbyGetException); }
		template <class Pred> Udm::AssocAttr<PICML::GetException, Pred > referedbyGetException_sorted(const Pred &) const { return Udm::AssocAttr<PICML::GetException, Pred>(impl, meta_referedbyGetException); }

		static Uml::CompositionChildRole meta_Member_children;
		Udm::ChildrenAttr<PICML::Member> Member_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, meta_Member_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, meta_Member_children); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedSizeCollection> FixedSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::FixedSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred> FixedSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VariableSizeCollection> VariableSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::VariableSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred> VariableSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::CollectionType> CollectionType_kind_children() const { return Udm::ChildrenAttr<PICML::CollectionType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CollectionType, Pred> CollectionType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CollectionType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_IDLFile_parent;
		Udm::ParentAttr<PICML::IDLFile> IDLFile_parent() const { return Udm::ParentAttr<PICML::IDLFile>(impl, meta_IDLFile_parent); }

		static Uml::CompositionParentRole meta_Package_parent;
		Udm::ParentAttr<PICML::Package> Package_parent() const { return Udm::ParentAttr<PICML::Package>(impl, meta_Package_parent); }

		static Uml::CompositionParentRole meta_HasOperations_parent;
		Udm::ParentAttr<PICML::HasOperations> HasOperations_parent() const { return Udm::ParentAttr<PICML::HasOperations>(impl, meta_HasOperations_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventRef :  public MgaObject {
	 public:
		static Uml::Class meta;

		EventRef() { }
		EventRef(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		EventRef(const EventRef &master) : MgaObject(master) { }
		static EventRef Cast(const Object &a) { return __Cast(a, meta); }

		static EventRef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventRef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventRef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventRef> Instances() { return Udm::InstantiatedAttr<PICML::EventRef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EventRef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::EventRef, Pred>(impl);}

		Udm::DerivedAttr<PICML::EventRef> Derived() { return Udm::DerivedAttr<PICML::EventRef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::EventRef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::EventRef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::EventRef> Archetype() { return Udm::ArchetypeAttr<PICML::EventRef>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::EventDef> ref() const { return Udm::PointerAttr<PICML::EventDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_EventPort_parent;
		Udm::ParentAttr<PICML::EventPort> EventPort_parent() const { return Udm::ParentAttr<PICML::EventPort>(impl, meta_EventPort_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ObjectRef :  public MgaObject {
	 public:
		static Uml::Class meta;

		ObjectRef() { }
		ObjectRef(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ObjectRef(const ObjectRef &master) : MgaObject(master) { }
		static ObjectRef Cast(const Object &a) { return __Cast(a, meta); }

		static ObjectRef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ObjectRef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ObjectRef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ObjectRef> Instances() { return Udm::InstantiatedAttr<PICML::ObjectRef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ObjectRef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ObjectRef, Pred>(impl);}

		Udm::DerivedAttr<PICML::ObjectRef> Derived() { return Udm::DerivedAttr<PICML::ObjectRef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ObjectRef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ObjectRef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ObjectRef> Archetype() { return Udm::ArchetypeAttr<PICML::ObjectRef>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ObjectDef> ref() const { return Udm::PointerAttr<PICML::ObjectDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_RequestPort_parent;
		Udm::ParentAttr<PICML::RequestPort> RequestPort_parent() const { return Udm::ParentAttr<PICML::RequestPort>(impl, meta_RequestPort_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Port :  public CommonPortAttrs, public Taggable {
	 public:
		static Uml::Class meta;

		Port() { }
		Port(Udm::ObjectImpl *impl) : CommonPortAttrs(impl),Taggable(impl), MgaObject(impl) { }
		Port(const Port &master) : CommonPortAttrs(master),Taggable(master), MgaObject(master) { }
		static Port Cast(const Object &a) { return __Cast(a, meta); }

		static Port Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Port CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Port CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Port> Instances() { return Udm::InstantiatedAttr<PICML::Port>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Port, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Port, Pred>(impl);}

		Udm::DerivedAttr<PICML::Port> Derived() { return Udm::DerivedAttr<PICML::Port>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Port, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Port, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Port> Archetype() { return Udm::ArchetypeAttr<PICML::Port>(impl);}

		static Uml::AssociationRole meta_cadenaPort;
		Udm::CrossAssocAttr<cadena_scenario::ComponentPort> cadenaPort() const { return Udm::CrossAssocAttr<cadena_scenario::ComponentPort>(impl, meta_cadenaPort); }
		template<class Pred> Udm::CrossAssocAttr<cadena_scenario::ComponentPort, Pred> cadenaPort_sorted(const Pred &) const { return Udm::CrossAssocAttr<cadena_scenario::ComponentPort, Pred>(impl, meta_cadenaPort); }

		static Uml::CompositionParentRole meta_ComponentDef_parent;
		Udm::ParentAttr<PICML::ComponentDef> ComponentDef_parent() const { return Udm::ParentAttr<PICML::ComponentDef>(impl, meta_ComponentDef_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  RequestPort :  public Port {
	 public:
		static Uml::Class meta;

		RequestPort() { }
		RequestPort(Udm::ObjectImpl *impl) : Port(impl), MgaObject(impl) { }
		RequestPort(const RequestPort &master) : Port(master), MgaObject(master) { }
		static RequestPort Cast(const Object &a) { return __Cast(a, meta); }

		static RequestPort Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RequestPort CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RequestPort CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RequestPort> Instances() { return Udm::InstantiatedAttr<PICML::RequestPort>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RequestPort, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::RequestPort, Pred>(impl);}

		Udm::DerivedAttr<PICML::RequestPort> Derived() { return Udm::DerivedAttr<PICML::RequestPort>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::RequestPort, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::RequestPort, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::RequestPort> Archetype() { return Udm::ArchetypeAttr<PICML::RequestPort>(impl);}

		static Uml::CompositionChildRole meta_ObjectRef_child;
		Udm::ChildAttr<PICML::ObjectRef> ObjectRef_child() const { return Udm::ChildAttr<PICML::ObjectRef>(impl, meta_ObjectRef_child); }

		Udm::ChildrenAttr<PICML::ObjectRef> ObjectRef_kind_children() const { return Udm::ChildrenAttr<PICML::ObjectRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ObjectRef, Pred> ObjectRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ObjectRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventPort :  public Port {
	 public:
		static Uml::Class meta;

		EventPort() { }
		EventPort(Udm::ObjectImpl *impl) : Port(impl), MgaObject(impl) { }
		EventPort(const EventPort &master) : Port(master), MgaObject(master) { }
		static EventPort Cast(const Object &a) { return __Cast(a, meta); }

		static EventPort Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventPort CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventPort CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventPort> Instances() { return Udm::InstantiatedAttr<PICML::EventPort>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EventPort, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::EventPort, Pred>(impl);}

		Udm::DerivedAttr<PICML::EventPort> Derived() { return Udm::DerivedAttr<PICML::EventPort>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::EventPort, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::EventPort, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::EventPort> Archetype() { return Udm::ArchetypeAttr<PICML::EventPort>(impl);}

		static Uml::CompositionChildRole meta_EventRef_child;
		Udm::ChildAttr<PICML::EventRef> EventRef_child() const { return Udm::ChildAttr<PICML::EventRef>(impl, meta_EventRef_child); }

		Udm::ChildrenAttr<PICML::EventRef> EventRef_kind_children() const { return Udm::ChildrenAttr<PICML::EventRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EventRef, Pred> EventRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EventRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ProvidedRequestPort :  public RequestPort {
	 public:
		static Uml::Class meta;

		ProvidedRequestPort() { }
		ProvidedRequestPort(Udm::ObjectImpl *impl) : RequestPort(impl), MgaObject(impl) { }
		ProvidedRequestPort(const ProvidedRequestPort &master) : RequestPort(master), MgaObject(master) { }
		static ProvidedRequestPort Cast(const Object &a) { return __Cast(a, meta); }

		static ProvidedRequestPort Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ProvidedRequestPort CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ProvidedRequestPort CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ProvidedRequestPort> Instances() { return Udm::InstantiatedAttr<PICML::ProvidedRequestPort>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ProvidedRequestPort, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ProvidedRequestPort, Pred>(impl);}

		Udm::DerivedAttr<PICML::ProvidedRequestPort> Derived() { return Udm::DerivedAttr<PICML::ProvidedRequestPort>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ProvidedRequestPort, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ProvidedRequestPort, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ProvidedRequestPort> Archetype() { return Udm::ArchetypeAttr<PICML::ProvidedRequestPort>(impl);}

		static Uml::AssociationRole meta_srcInvocation, meta_srcInvocation_rev;
		Udm::AClassAssocAttr<PICML::Invocation, PICML::RequiredRequestPort> srcInvocation() const { return Udm::AClassAssocAttr<PICML::Invocation, PICML::RequiredRequestPort>(impl, meta_srcInvocation, meta_srcInvocation_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::Invocation, PICML::RequiredRequestPort, Pred> srcInvocation_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::Invocation, PICML::RequiredRequestPort, Pred>(impl, meta_srcInvocation, meta_srcInvocation_rev); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  RequiredRequestPort :  public RequestPort {
	 public:
		static Uml::Class meta;

		RequiredRequestPort() { }
		RequiredRequestPort(Udm::ObjectImpl *impl) : RequestPort(impl), MgaObject(impl) { }
		RequiredRequestPort(const RequiredRequestPort &master) : RequestPort(master), MgaObject(master) { }
		static RequiredRequestPort Cast(const Object &a) { return __Cast(a, meta); }

		static RequiredRequestPort Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		RequiredRequestPort CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		RequiredRequestPort CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<RequiredRequestPort> Instances() { return Udm::InstantiatedAttr<PICML::RequiredRequestPort>(impl);}
		template <class Pred> Udm::InstantiatedAttr<RequiredRequestPort, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::RequiredRequestPort, Pred>(impl);}

		Udm::DerivedAttr<PICML::RequiredRequestPort> Derived() { return Udm::DerivedAttr<PICML::RequiredRequestPort>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::RequiredRequestPort, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::RequiredRequestPort, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::RequiredRequestPort> Archetype() { return Udm::ArchetypeAttr<PICML::RequiredRequestPort>(impl);}

		static Uml::Attribute meta_multiple_connections;
		Udm::BooleanAttr multiple_connections() const { return Udm::BooleanAttr(impl, meta_multiple_connections); }

		static Uml::AssociationRole meta_dstInvocation, meta_dstInvocation_rev;
		Udm::AClassAssocAttr<PICML::Invocation, PICML::ProvidedRequestPort> dstInvocation() const { return Udm::AClassAssocAttr<PICML::Invocation, PICML::ProvidedRequestPort>(impl, meta_dstInvocation, meta_dstInvocation_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::Invocation, PICML::ProvidedRequestPort, Pred> dstInvocation_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::Invocation, PICML::ProvidedRequestPort, Pred>(impl, meta_dstInvocation, meta_dstInvocation_rev); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  OutEventPort :  public EventPort {
	 public:
		static Uml::Class meta;

		OutEventPort() { }
		OutEventPort(Udm::ObjectImpl *impl) : EventPort(impl), MgaObject(impl) { }
		OutEventPort(const OutEventPort &master) : EventPort(master), MgaObject(master) { }
		static OutEventPort Cast(const Object &a) { return __Cast(a, meta); }

		static OutEventPort Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		OutEventPort CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		OutEventPort CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<OutEventPort> Instances() { return Udm::InstantiatedAttr<PICML::OutEventPort>(impl);}
		template <class Pred> Udm::InstantiatedAttr<OutEventPort, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::OutEventPort, Pred>(impl);}

		Udm::DerivedAttr<PICML::OutEventPort> Derived() { return Udm::DerivedAttr<PICML::OutEventPort>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::OutEventPort, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::OutEventPort, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::OutEventPort> Archetype() { return Udm::ArchetypeAttr<PICML::OutEventPort>(impl);}

		static Uml::Attribute meta_single_destination;
		Udm::BooleanAttr single_destination() const { return Udm::BooleanAttr(impl, meta_single_destination); }

		static Uml::AssociationRole meta_dstEmitConnector, meta_dstEmitConnector_rev;
		Udm::AClassPointerAttr<PICML::EmitConnector, PICML::InEventPort> dstEmitConnector() const { return Udm::AClassPointerAttr<PICML::EmitConnector, PICML::InEventPort>(impl, meta_dstEmitConnector, meta_dstEmitConnector_rev); }

		static Uml::AssociationRole meta_dstOutEventPortPublish, meta_dstOutEventPortPublish_rev;
		Udm::AClassAssocAttr<PICML::OutEventPortPublish, PICML::PublishConnector> dstOutEventPortPublish() const { return Udm::AClassAssocAttr<PICML::OutEventPortPublish, PICML::PublishConnector>(impl, meta_dstOutEventPortPublish, meta_dstOutEventPortPublish_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::OutEventPortPublish, PICML::PublishConnector, Pred> dstOutEventPortPublish_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::OutEventPortPublish, PICML::PublishConnector, Pred>(impl, meta_dstOutEventPortPublish, meta_dstOutEventPortPublish_rev); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  InEventPort :  public EventPort {
	 public:
		static Uml::Class meta;

		InEventPort() { }
		InEventPort(Udm::ObjectImpl *impl) : EventPort(impl), MgaObject(impl) { }
		InEventPort(const InEventPort &master) : EventPort(master), MgaObject(master) { }
		static InEventPort Cast(const Object &a) { return __Cast(a, meta); }

		static InEventPort Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		InEventPort CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		InEventPort CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<InEventPort> Instances() { return Udm::InstantiatedAttr<PICML::InEventPort>(impl);}
		template <class Pred> Udm::InstantiatedAttr<InEventPort, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::InEventPort, Pred>(impl);}

		Udm::DerivedAttr<PICML::InEventPort> Derived() { return Udm::DerivedAttr<PICML::InEventPort>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::InEventPort, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::InEventPort, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::InEventPort> Archetype() { return Udm::ArchetypeAttr<PICML::InEventPort>(impl);}

		static Uml::AssociationRole meta_srcEmitConnector, meta_srcEmitConnector_rev;
		Udm::AClassPointerAttr<PICML::EmitConnector, PICML::OutEventPort> srcEmitConnector() const { return Udm::AClassPointerAttr<PICML::EmitConnector, PICML::OutEventPort>(impl, meta_srcEmitConnector, meta_srcEmitConnector_rev); }

		static Uml::AssociationRole meta_srcInEventPortConsume, meta_srcInEventPortConsume_rev;
		Udm::AClassAssocAttr<PICML::InEventPortConsume, PICML::PublishConnector> srcInEventPortConsume() const { return Udm::AClassAssocAttr<PICML::InEventPortConsume, PICML::PublishConnector>(impl, meta_srcInEventPortConsume, meta_srcInEventPortConsume_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::InEventPortConsume, PICML::PublishConnector, Pred> srcInEventPortConsume_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::InEventPortConsume, PICML::PublishConnector, Pred>(impl, meta_srcInEventPortConsume, meta_srcInEventPortConsume_rev); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  AnonymousType :  public Member, public Type {
	 public:
		static Uml::Class meta;

		AnonymousType() { }
		AnonymousType(Udm::ObjectImpl *impl) : Member(impl),Type(impl), MgaObject(impl) { }
		AnonymousType(const AnonymousType &master) : Member(master),Type(master), MgaObject(master) { }
		static AnonymousType Cast(const Object &a) { return __Cast(a, meta); }

		static AnonymousType Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		AnonymousType CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		AnonymousType CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<AnonymousType> Instances() { return Udm::InstantiatedAttr<PICML::AnonymousType>(impl);}
		template <class Pred> Udm::InstantiatedAttr<AnonymousType, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::AnonymousType, Pred>(impl);}

		Udm::DerivedAttr<PICML::AnonymousType> Derived() { return Udm::DerivedAttr<PICML::AnonymousType>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::AnonymousType, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::AnonymousType, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::AnonymousType> Archetype() { return Udm::ArchetypeAttr<PICML::AnonymousType>(impl);}

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  BoundedString :  public AnonymousType {
	 public:
		static Uml::Class meta;

		BoundedString() { }
		BoundedString(Udm::ObjectImpl *impl) : AnonymousType(impl), MgaObject(impl) { }
		BoundedString(const BoundedString &master) : AnonymousType(master), MgaObject(master) { }
		static BoundedString Cast(const Object &a) { return __Cast(a, meta); }

		static BoundedString Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		BoundedString CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		BoundedString CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<BoundedString> Instances() { return Udm::InstantiatedAttr<PICML::BoundedString>(impl);}
		template <class Pred> Udm::InstantiatedAttr<BoundedString, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::BoundedString, Pred>(impl);}

		Udm::DerivedAttr<PICML::BoundedString> Derived() { return Udm::DerivedAttr<PICML::BoundedString>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::BoundedString, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::BoundedString, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::BoundedString> Archetype() { return Udm::ArchetypeAttr<PICML::BoundedString>(impl);}

		static Uml::Attribute meta_wide;
		Udm::BooleanAttr wide() const { return Udm::BooleanAttr(impl, meta_wide); }

		static Uml::Attribute meta_bound;
		Udm::IntegerAttr bound() const { return Udm::IntegerAttr(impl, meta_bound); }

		static Uml::CompositionParentRole meta_ConstantDef_parent;
		Udm::ParentAttr<PICML::ConstantDef> ConstantDef_parent() const { return Udm::ParentAttr<PICML::ConstantDef>(impl, meta_ConstantDef_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  CollectionType :  public AnonymousType {
	 public:
		static Uml::Class meta;

		CollectionType() { }
		CollectionType(Udm::ObjectImpl *impl) : AnonymousType(impl), MgaObject(impl) { }
		CollectionType(const CollectionType &master) : AnonymousType(master), MgaObject(master) { }
		static CollectionType Cast(const Object &a) { return __Cast(a, meta); }

		static CollectionType Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		CollectionType CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		CollectionType CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<CollectionType> Instances() { return Udm::InstantiatedAttr<PICML::CollectionType>(impl);}
		template <class Pred> Udm::InstantiatedAttr<CollectionType, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::CollectionType, Pred>(impl);}

		Udm::DerivedAttr<PICML::CollectionType> Derived() { return Udm::DerivedAttr<PICML::CollectionType>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::CollectionType, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::CollectionType, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::CollectionType> Archetype() { return Udm::ArchetypeAttr<PICML::CollectionType>(impl);}

		static Uml::Attribute meta_bound;
		Udm::IntegerAttr bound() const { return Udm::IntegerAttr(impl, meta_bound); }

		static Uml::CompositionChildRole meta_Member_child;
		Udm::ChildAttr<PICML::Member> Member_child() const { return Udm::ChildAttr<PICML::Member>(impl, meta_Member_child); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedSizeCollection> FixedSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::FixedSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred> FixedSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VariableSizeCollection> VariableSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::VariableSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred> VariableSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::CollectionType> CollectionType_kind_children() const { return Udm::ChildrenAttr<PICML::CollectionType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CollectionType, Pred> CollectionType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CollectionType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  FixedSizeCollection :  public CollectionType {
	 public:
		static Uml::Class meta;

		FixedSizeCollection() { }
		FixedSizeCollection(Udm::ObjectImpl *impl) : CollectionType(impl), MgaObject(impl) { }
		FixedSizeCollection(const FixedSizeCollection &master) : CollectionType(master), MgaObject(master) { }
		static FixedSizeCollection Cast(const Object &a) { return __Cast(a, meta); }

		static FixedSizeCollection Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		FixedSizeCollection CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		FixedSizeCollection CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<FixedSizeCollection> Instances() { return Udm::InstantiatedAttr<PICML::FixedSizeCollection>(impl);}
		template <class Pred> Udm::InstantiatedAttr<FixedSizeCollection, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::FixedSizeCollection, Pred>(impl);}

		Udm::DerivedAttr<PICML::FixedSizeCollection> Derived() { return Udm::DerivedAttr<PICML::FixedSizeCollection>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::FixedSizeCollection, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::FixedSizeCollection, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::FixedSizeCollection> Archetype() { return Udm::ArchetypeAttr<PICML::FixedSizeCollection>(impl);}

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  VariableSizeCollection :  public CollectionType {
	 public:
		static Uml::Class meta;

		VariableSizeCollection() { }
		VariableSizeCollection(Udm::ObjectImpl *impl) : CollectionType(impl), MgaObject(impl) { }
		VariableSizeCollection(const VariableSizeCollection &master) : CollectionType(master), MgaObject(master) { }
		static VariableSizeCollection Cast(const Object &a) { return __Cast(a, meta); }

		static VariableSizeCollection Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		VariableSizeCollection CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		VariableSizeCollection CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<VariableSizeCollection> Instances() { return Udm::InstantiatedAttr<PICML::VariableSizeCollection>(impl);}
		template <class Pred> Udm::InstantiatedAttr<VariableSizeCollection, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::VariableSizeCollection, Pred>(impl);}

		Udm::DerivedAttr<PICML::VariableSizeCollection> Derived() { return Udm::DerivedAttr<PICML::VariableSizeCollection>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::VariableSizeCollection, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::VariableSizeCollection, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::VariableSizeCollection> Archetype() { return Udm::ArchetypeAttr<PICML::VariableSizeCollection>(impl);}

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  PredefinedType :  public ParameterType, public AnonymousType {
	 public:
		static Uml::Class meta;

		PredefinedType() { }
		PredefinedType(Udm::ObjectImpl *impl) : ParameterType(impl),AnonymousType(impl), MgaObject(impl) { }
		PredefinedType(const PredefinedType &master) : ParameterType(master),AnonymousType(master), MgaObject(master) { }
		static PredefinedType Cast(const Object &a) { return __Cast(a, meta); }

		static PredefinedType Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PredefinedType CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PredefinedType CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PredefinedType> Instances() { return Udm::InstantiatedAttr<PICML::PredefinedType>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PredefinedType, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PredefinedType, Pred>(impl);}

		Udm::DerivedAttr<PICML::PredefinedType> Derived() { return Udm::DerivedAttr<PICML::PredefinedType>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PredefinedType, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PredefinedType, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PredefinedType> Archetype() { return Udm::ArchetypeAttr<PICML::PredefinedType>(impl);}

		static Uml::Attribute meta_which_type;
		Udm::StringAttr which_type() const { return Udm::StringAttr(impl, meta_which_type); }

		static Uml::CompositionParentRole meta_Discriminator_parent;
		Udm::ParentAttr<PICML::Discriminator> Discriminator_parent() const { return Udm::ParentAttr<PICML::Discriminator>(impl, meta_Discriminator_parent); }

		static Uml::CompositionParentRole meta_ConstantDef_parent;
		Udm::ParentAttr<PICML::ConstantDef> ConstantDef_parent() const { return Udm::ParentAttr<PICML::ConstantDef>(impl, meta_ConstantDef_parent); }

		static Uml::CompositionParentRole meta_DataType_parent;
		Udm::ParentAttr<PICML::DataType> DataType_parent() const { return Udm::ParentAttr<PICML::DataType>(impl, meta_DataType_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  FixedPoint :  public AnonymousType {
	 public:
		static Uml::Class meta;

		FixedPoint() { }
		FixedPoint(Udm::ObjectImpl *impl) : AnonymousType(impl), MgaObject(impl) { }
		FixedPoint(const FixedPoint &master) : AnonymousType(master), MgaObject(master) { }
		static FixedPoint Cast(const Object &a) { return __Cast(a, meta); }

		static FixedPoint Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		FixedPoint CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		FixedPoint CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<FixedPoint> Instances() { return Udm::InstantiatedAttr<PICML::FixedPoint>(impl);}
		template <class Pred> Udm::InstantiatedAttr<FixedPoint, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::FixedPoint, Pred>(impl);}

		Udm::DerivedAttr<PICML::FixedPoint> Derived() { return Udm::DerivedAttr<PICML::FixedPoint>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::FixedPoint, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::FixedPoint, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::FixedPoint> Archetype() { return Udm::ArchetypeAttr<PICML::FixedPoint>(impl);}

		static Uml::Attribute meta_total_digits;
		Udm::IntegerAttr total_digits() const { return Udm::IntegerAttr(impl, meta_total_digits); }

		static Uml::Attribute meta_decimal_digits;
		Udm::IntegerAttr decimal_digits() const { return Udm::IntegerAttr(impl, meta_decimal_digits); }

		static Uml::CompositionParentRole meta_ConstantDef_parent;
		Udm::ParentAttr<PICML::ConstantDef> ConstantDef_parent() const { return Udm::ParentAttr<PICML::ConstantDef>(impl, meta_ConstantDef_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Inherits :  public MgaObject {
	 public:
		static Uml::Class meta;

		Inherits() { }
		Inherits(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Inherits(const Inherits &master) : MgaObject(master) { }
		static Inherits Cast(const Object &a) { return __Cast(a, meta); }

		static Inherits Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Inherits CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Inherits CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Inherits> Instances() { return Udm::InstantiatedAttr<PICML::Inherits>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Inherits, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Inherits, Pred>(impl);}

		Udm::DerivedAttr<PICML::Inherits> Derived() { return Udm::DerivedAttr<PICML::Inherits>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Inherits, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Inherits, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Inherits> Archetype() { return Udm::ArchetypeAttr<PICML::Inherits>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::Inheritable> ref() const { return Udm::PointerAttr<PICML::Inheritable>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_Inheritable_parent;
		Udm::ParentAttr<PICML::Inheritable> Inheritable_parent() const { return Udm::ParentAttr<PICML::Inheritable>(impl, meta_Inheritable_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Inheritable :  public NamedType {
	 public:
		static Uml::Class meta;

		Inheritable() { }
		Inheritable(Udm::ObjectImpl *impl) : NamedType(impl), MgaObject(impl) { }
		Inheritable(const Inheritable &master) : NamedType(master), MgaObject(master) { }
		static Inheritable Cast(const Object &a) { return __Cast(a, meta); }

		static Inheritable Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Inheritable CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Inheritable CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Inheritable> Instances() { return Udm::InstantiatedAttr<PICML::Inheritable>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Inheritable, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Inheritable, Pred>(impl);}

		Udm::DerivedAttr<PICML::Inheritable> Derived() { return Udm::DerivedAttr<PICML::Inheritable>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Inheritable, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Inheritable, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Inheritable> Archetype() { return Udm::ArchetypeAttr<PICML::Inheritable>(impl);}

		static Uml::AssociationRole meta_referedbyInherits;
		Udm::AssocAttr<PICML::Inherits> referedbyInherits() const { return Udm::AssocAttr<PICML::Inherits>(impl, meta_referedbyInherits); }
		template <class Pred> Udm::AssocAttr<PICML::Inherits, Pred > referedbyInherits_sorted(const Pred &) const { return Udm::AssocAttr<PICML::Inherits, Pred>(impl, meta_referedbyInherits); }

		static Uml::CompositionChildRole meta_ReadonlyAttribute_children;
		Udm::ChildrenAttr<PICML::ReadonlyAttribute> ReadonlyAttribute_children() const { return Udm::ChildrenAttr<PICML::ReadonlyAttribute>(impl, meta_ReadonlyAttribute_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ReadonlyAttribute, Pred> ReadonlyAttribute_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ReadonlyAttribute, Pred>(impl, meta_ReadonlyAttribute_children); }

		static Uml::CompositionChildRole meta_Inherits_children;
		Udm::ChildrenAttr<PICML::Inherits> Inherits_children() const { return Udm::ChildrenAttr<PICML::Inherits>(impl, meta_Inherits_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Inherits, Pred> Inherits_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Inherits, Pred>(impl, meta_Inherits_children); }

		Udm::ChildrenAttr<PICML::Inherits> Inherits_kind_children() const { return Udm::ChildrenAttr<PICML::Inherits>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Inherits, Pred> Inherits_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Inherits, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ReadonlyAttribute> ReadonlyAttribute_kind_children() const { return Udm::ChildrenAttr<PICML::ReadonlyAttribute>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ReadonlyAttribute, Pred> ReadonlyAttribute_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ReadonlyAttribute, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Attribute> Attribute_kind_children() const { return Udm::ChildrenAttr<PICML::Attribute>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Attribute, Pred> Attribute_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Attribute, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  HasOperations :  virtual public Inheritable {
	 public:
		static Uml::Class meta;

		HasOperations() { }
		HasOperations(Udm::ObjectImpl *impl) : Inheritable(impl), MgaObject(impl) { }
		HasOperations(const HasOperations &master) : Inheritable(master), MgaObject(master) { }
		static HasOperations Cast(const Object &a) { return __Cast(a, meta); }

		static HasOperations Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		HasOperations CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		HasOperations CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<HasOperations> Instances() { return Udm::InstantiatedAttr<PICML::HasOperations>(impl);}
		template <class Pred> Udm::InstantiatedAttr<HasOperations, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::HasOperations, Pred>(impl);}

		Udm::DerivedAttr<PICML::HasOperations> Derived() { return Udm::DerivedAttr<PICML::HasOperations>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::HasOperations, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::HasOperations, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::HasOperations> Archetype() { return Udm::ArchetypeAttr<PICML::HasOperations>(impl);}

		static Uml::CompositionChildRole meta_TwowayOperation_children;
		Udm::ChildrenAttr<PICML::TwowayOperation> TwowayOperation_children() const { return Udm::ChildrenAttr<PICML::TwowayOperation>(impl, meta_TwowayOperation_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::TwowayOperation, Pred> TwowayOperation_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TwowayOperation, Pred>(impl, meta_TwowayOperation_children); }

		static Uml::CompositionChildRole meta_OnewayOperation_children;
		Udm::ChildrenAttr<PICML::OnewayOperation> OnewayOperation_children() const { return Udm::ChildrenAttr<PICML::OnewayOperation>(impl, meta_OnewayOperation_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::OnewayOperation, Pred> OnewayOperation_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OnewayOperation, Pred>(impl, meta_OnewayOperation_children); }

		static Uml::CompositionChildRole meta_NoInheritable_children;
		Udm::ChildrenAttr<PICML::NoInheritable> NoInheritable_children() const { return Udm::ChildrenAttr<PICML::NoInheritable>(impl, meta_NoInheritable_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::NoInheritable, Pred> NoInheritable_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NoInheritable, Pred>(impl, meta_NoInheritable_children); }

		static Uml::CompositionChildRole meta_ConstantDef_children;
		Udm::ChildrenAttr<PICML::ConstantDef> ConstantDef_children() const { return Udm::ChildrenAttr<PICML::ConstantDef>(impl, meta_ConstantDef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ConstantDef, Pred> ConstantDef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConstantDef, Pred>(impl, meta_ConstantDef_children); }

		static Uml::CompositionChildRole meta_ExceptionDef_children;
		Udm::ChildrenAttr<PICML::ExceptionDef> ExceptionDef_children() const { return Udm::ChildrenAttr<PICML::ExceptionDef>(impl, meta_ExceptionDef_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::ExceptionDef, Pred> ExceptionDef_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ExceptionDef, Pred>(impl, meta_ExceptionDef_children); }

		Udm::ChildrenAttr<PICML::EnumerationDef> EnumerationDef_kind_children() const { return Udm::ChildrenAttr<PICML::EnumerationDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EnumerationDef, Pred> EnumerationDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EnumerationDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AliasDef> AliasDef_kind_children() const { return Udm::ChildrenAttr<PICML::AliasDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AliasDef, Pred> AliasDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AliasDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AggregateDef> AggregateDef_kind_children() const { return Udm::ChildrenAttr<PICML::AggregateDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AggregateDef, Pred> AggregateDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AggregateDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::SwitchedAggregateDef> SwitchedAggregateDef_kind_children() const { return Udm::ChildrenAttr<PICML::SwitchedAggregateDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SwitchedAggregateDef, Pred> SwitchedAggregateDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SwitchedAggregateDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::NamedType> NamedType_kind_children() const { return Udm::ChildrenAttr<PICML::NamedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedType, Pred> NamedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::NoInheritable> NoInheritable_kind_children() const { return Udm::ChildrenAttr<PICML::NoInheritable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NoInheritable, Pred> NoInheritable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NoInheritable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Taggable> Taggable_kind_children() const { return Udm::ChildrenAttr<PICML::Taggable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Taggable, Pred> Taggable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Taggable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::OperationBase> OperationBase_kind_children() const { return Udm::ChildrenAttr<PICML::OperationBase>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::OperationBase, Pred> OperationBase_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OperationBase, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::HasExceptions> HasExceptions_kind_children() const { return Udm::ChildrenAttr<PICML::HasExceptions>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::HasExceptions, Pred> HasExceptions_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::HasExceptions, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::OnewayOperation> OnewayOperation_kind_children() const { return Udm::ChildrenAttr<PICML::OnewayOperation>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::OnewayOperation, Pred> OnewayOperation_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OnewayOperation, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::TwowayOperation> TwowayOperation_kind_children() const { return Udm::ChildrenAttr<PICML::TwowayOperation>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::TwowayOperation, Pred> TwowayOperation_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::TwowayOperation, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Type> Type_kind_children() const { return Udm::ChildrenAttr<PICML::Type>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Type, Pred> Type_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Type, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ConstantDef> ConstantDef_kind_children() const { return Udm::ChildrenAttr<PICML::ConstantDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ConstantDef, Pred> ConstantDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ConstantDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ExceptionDef> ExceptionDef_kind_children() const { return Udm::ChildrenAttr<PICML::ExceptionDef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ExceptionDef, Pred> ExceptionDef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ExceptionDef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ObjectDef :  public Prefixable, public HasOperations {
	 public:
		static Uml::Class meta;

		ObjectDef() { }
		ObjectDef(Udm::ObjectImpl *impl) : Prefixable(impl),HasOperations(impl), Inheritable(impl), MgaObject(impl) { }
		ObjectDef(const ObjectDef &master) : Prefixable(master),HasOperations(master), Inheritable(master), MgaObject(master) { }
		static ObjectDef Cast(const Object &a) { return __Cast(a, meta); }

		static ObjectDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ObjectDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ObjectDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ObjectDef> Instances() { return Udm::InstantiatedAttr<PICML::ObjectDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ObjectDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ObjectDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::ObjectDef> Derived() { return Udm::DerivedAttr<PICML::ObjectDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ObjectDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ObjectDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ObjectDef> Archetype() { return Udm::ArchetypeAttr<PICML::ObjectDef>(impl);}

		static Uml::Attribute meta_local;
		Udm::BooleanAttr local() const { return Udm::BooleanAttr(impl, meta_local); }

		static Uml::Attribute meta_abstract;
		Udm::BooleanAttr abstract() const { return Udm::BooleanAttr(impl, meta_abstract); }

		static Uml::AssociationRole meta_referedbyObjectRef;
		Udm::AssocAttr<PICML::ObjectRef> referedbyObjectRef() const { return Udm::AssocAttr<PICML::ObjectRef>(impl, meta_referedbyObjectRef); }
		template <class Pred> Udm::AssocAttr<PICML::ObjectRef, Pred > referedbyObjectRef_sorted(const Pred &) const { return Udm::AssocAttr<PICML::ObjectRef, Pred>(impl, meta_referedbyObjectRef); }

		static Uml::AssociationRole meta_referedbySupports;
		Udm::AssocAttr<PICML::Supports> referedbySupports() const { return Udm::AssocAttr<PICML::Supports>(impl, meta_referedbySupports); }
		template <class Pred> Udm::AssocAttr<PICML::Supports, Pred > referedbySupports_sorted(const Pred &) const { return Udm::AssocAttr<PICML::Supports, Pred>(impl, meta_referedbySupports); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  SupportsInterfaces :  virtual public Inheritable {
	 public:
		static Uml::Class meta;

		SupportsInterfaces() { }
		SupportsInterfaces(Udm::ObjectImpl *impl) : Inheritable(impl), MgaObject(impl) { }
		SupportsInterfaces(const SupportsInterfaces &master) : Inheritable(master), MgaObject(master) { }
		static SupportsInterfaces Cast(const Object &a) { return __Cast(a, meta); }

		static SupportsInterfaces Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		SupportsInterfaces CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		SupportsInterfaces CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<SupportsInterfaces> Instances() { return Udm::InstantiatedAttr<PICML::SupportsInterfaces>(impl);}
		template <class Pred> Udm::InstantiatedAttr<SupportsInterfaces, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::SupportsInterfaces, Pred>(impl);}

		Udm::DerivedAttr<PICML::SupportsInterfaces> Derived() { return Udm::DerivedAttr<PICML::SupportsInterfaces>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::SupportsInterfaces, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::SupportsInterfaces, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::SupportsInterfaces> Archetype() { return Udm::ArchetypeAttr<PICML::SupportsInterfaces>(impl);}

		static Uml::CompositionChildRole meta_Supports_children;
		Udm::ChildrenAttr<PICML::Supports> Supports_children() const { return Udm::ChildrenAttr<PICML::Supports>(impl, meta_Supports_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Supports, Pred> Supports_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Supports, Pred>(impl, meta_Supports_children); }

		Udm::ChildrenAttr<PICML::Supports> Supports_kind_children() const { return Udm::ChildrenAttr<PICML::Supports>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Supports, Pred> Supports_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Supports, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentDef :  public SupportsInterfaces {
	 public:
		static Uml::Class meta;

		ComponentDef() { }
		ComponentDef(Udm::ObjectImpl *impl) : SupportsInterfaces(impl), Inheritable(impl), MgaObject(impl) { }
		ComponentDef(const ComponentDef &master) : SupportsInterfaces(master), Inheritable(master), MgaObject(master) { }
		static ComponentDef Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentDef> Instances() { return Udm::InstantiatedAttr<PICML::ComponentDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentDef> Derived() { return Udm::DerivedAttr<PICML::ComponentDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentDef> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentDef>(impl);}

		static Uml::AssociationRole meta_referedbyComponentType;
		Udm::AssocAttr<PICML::ComponentType> referedbyComponentType() const { return Udm::AssocAttr<PICML::ComponentType>(impl, meta_referedbyComponentType); }
		template <class Pred> Udm::AssocAttr<PICML::ComponentType, Pred > referedbyComponentType_sorted(const Pred &) const { return Udm::AssocAttr<PICML::ComponentType, Pred>(impl, meta_referedbyComponentType); }

		static Uml::AssociationRole meta_dstSubComponentSelectRequirement, meta_dstSubComponentSelectRequirement_rev;
		Udm::AClassAssocAttr<PICML::SubComponentSelectRequirement, PICML::Requirement> dstSubComponentSelectRequirement() const { return Udm::AClassAssocAttr<PICML::SubComponentSelectRequirement, PICML::Requirement>(impl, meta_dstSubComponentSelectRequirement, meta_dstSubComponentSelectRequirement_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::SubComponentSelectRequirement, PICML::Requirement, Pred> dstSubComponentSelectRequirement_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::SubComponentSelectRequirement, PICML::Requirement, Pred>(impl, meta_dstSubComponentSelectRequirement, meta_dstSubComponentSelectRequirement_rev); }

		static Uml::AssociationRole meta_dstSubComponentConfigProperty, meta_dstSubComponentConfigProperty_rev;
		Udm::AClassAssocAttr<PICML::SubComponentConfigProperty, PICML::Property> dstSubComponentConfigProperty() const { return Udm::AClassAssocAttr<PICML::SubComponentConfigProperty, PICML::Property>(impl, meta_dstSubComponentConfigProperty, meta_dstSubComponentConfigProperty_rev); }
		template<class Pred> Udm::AClassAssocAttr<PICML::SubComponentConfigProperty, PICML::Property, Pred> dstSubComponentConfigProperty_sorted(const Pred &) const { return Udm::AClassAssocAttr<PICML::SubComponentConfigProperty, PICML::Property, Pred>(impl, meta_dstSubComponentConfigProperty, meta_dstSubComponentConfigProperty_rev); }

		static Uml::AssociationRole meta_referedbyManages;
		Udm::AssocAttr<PICML::Manages> referedbyManages() const { return Udm::AssocAttr<PICML::Manages>(impl, meta_referedbyManages); }
		template <class Pred> Udm::AssocAttr<PICML::Manages, Pred > referedbyManages_sorted(const Pred &) const { return Udm::AssocAttr<PICML::Manages, Pred>(impl, meta_referedbyManages); }

		static Uml::CompositionChildRole meta_Port_children;
		Udm::ChildrenAttr<PICML::Port> Port_children() const { return Udm::ChildrenAttr<PICML::Port>(impl, meta_Port_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Port, Pred> Port_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Port, Pred>(impl, meta_Port_children); }

		Udm::ChildrenAttr<PICML::CommonPortAttrs> CommonPortAttrs_kind_children() const { return Udm::ChildrenAttr<PICML::CommonPortAttrs>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CommonPortAttrs, Pred> CommonPortAttrs_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CommonPortAttrs, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Taggable> Taggable_kind_children() const { return Udm::ChildrenAttr<PICML::Taggable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Taggable, Pred> Taggable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Taggable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::RequestPort> RequestPort_kind_children() const { return Udm::ChildrenAttr<PICML::RequestPort>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::RequestPort, Pred> RequestPort_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RequestPort, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::EventPort> EventPort_kind_children() const { return Udm::ChildrenAttr<PICML::EventPort>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::EventPort, Pred> EventPort_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::EventPort, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::ProvidedRequestPort> ProvidedRequestPort_kind_children() const { return Udm::ChildrenAttr<PICML::ProvidedRequestPort>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::ProvidedRequestPort, Pred> ProvidedRequestPort_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::ProvidedRequestPort, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::RequiredRequestPort> RequiredRequestPort_kind_children() const { return Udm::ChildrenAttr<PICML::RequiredRequestPort>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::RequiredRequestPort, Pred> RequiredRequestPort_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::RequiredRequestPort, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::OutEventPort> OutEventPort_kind_children() const { return Udm::ChildrenAttr<PICML::OutEventPort>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::OutEventPort, Pred> OutEventPort_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OutEventPort, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::InEventPort> InEventPort_kind_children() const { return Udm::ChildrenAttr<PICML::InEventPort>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::InEventPort, Pred> InEventPort_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::InEventPort, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Port> Port_kind_children() const { return Udm::ChildrenAttr<PICML::Port>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Port, Pred> Port_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Port, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_ComponentAssembly_parent;
		Udm::ParentAttr<PICML::ComponentAssembly> ComponentAssembly_parent() const { return Udm::ParentAttr<PICML::ComponentAssembly>(impl, meta_ComponentAssembly_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ComponentFactory :  public HasOperations, public SupportsInterfaces {
	 public:
		static Uml::Class meta;

		ComponentFactory() { }
		ComponentFactory(Udm::ObjectImpl *impl) : HasOperations(impl),SupportsInterfaces(impl), Inheritable(impl), MgaObject(impl) { }
		ComponentFactory(const ComponentFactory &master) : HasOperations(master),SupportsInterfaces(master), Inheritable(master), MgaObject(master) { }
		static ComponentFactory Cast(const Object &a) { return __Cast(a, meta); }

		static ComponentFactory Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ComponentFactory CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ComponentFactory CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ComponentFactory> Instances() { return Udm::InstantiatedAttr<PICML::ComponentFactory>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ComponentFactory, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ComponentFactory, Pred>(impl);}

		Udm::DerivedAttr<PICML::ComponentFactory> Derived() { return Udm::DerivedAttr<PICML::ComponentFactory>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ComponentFactory, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ComponentFactory, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ComponentFactory> Archetype() { return Udm::ArchetypeAttr<PICML::ComponentFactory>(impl);}

		static Uml::CompositionChildRole meta_Manages_child;
		Udm::ChildAttr<PICML::Manages> Manages_child() const { return Udm::ChildAttr<PICML::Manages>(impl, meta_Manages_child); }

		static Uml::CompositionChildRole meta_LookupKey_child;
		Udm::ChildAttr<PICML::LookupKey> LookupKey_child() const { return Udm::ChildAttr<PICML::LookupKey>(impl, meta_LookupKey_child); }

		static Uml::CompositionChildRole meta_LookupOperation_children;
		Udm::ChildrenAttr<PICML::LookupOperation> LookupOperation_children() const { return Udm::ChildrenAttr<PICML::LookupOperation>(impl, meta_LookupOperation_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::LookupOperation, Pred> LookupOperation_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::LookupOperation, Pred>(impl, meta_LookupOperation_children); }

		static Uml::CompositionChildRole meta_FactoryOperation_children;
		Udm::ChildrenAttr<PICML::FactoryOperation> FactoryOperation_children() const { return Udm::ChildrenAttr<PICML::FactoryOperation>(impl, meta_FactoryOperation_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::FactoryOperation, Pred> FactoryOperation_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FactoryOperation, Pred>(impl, meta_FactoryOperation_children); }

		Udm::ChildrenAttr<PICML::Taggable> Taggable_kind_children() const { return Udm::ChildrenAttr<PICML::Taggable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Taggable, Pred> Taggable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Taggable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::OperationBase> OperationBase_kind_children() const { return Udm::ChildrenAttr<PICML::OperationBase>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::OperationBase, Pred> OperationBase_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OperationBase, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::HasExceptions> HasExceptions_kind_children() const { return Udm::ChildrenAttr<PICML::HasExceptions>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::HasExceptions, Pred> HasExceptions_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::HasExceptions, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::LookupOperation> LookupOperation_kind_children() const { return Udm::ChildrenAttr<PICML::LookupOperation>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::LookupOperation, Pred> LookupOperation_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::LookupOperation, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FactoryOperation> FactoryOperation_kind_children() const { return Udm::ChildrenAttr<PICML::FactoryOperation>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FactoryOperation, Pred> FactoryOperation_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FactoryOperation, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::LookupKey> LookupKey_kind_children() const { return Udm::ChildrenAttr<PICML::LookupKey>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::LookupKey, Pred> LookupKey_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::LookupKey, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Manages> Manages_kind_children() const { return Udm::ChildrenAttr<PICML::Manages>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Manages, Pred> Manages_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Manages, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Supports :  public MgaObject {
	 public:
		static Uml::Class meta;

		Supports() { }
		Supports(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Supports(const Supports &master) : MgaObject(master) { }
		static Supports Cast(const Object &a) { return __Cast(a, meta); }

		static Supports Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Supports CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Supports CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Supports> Instances() { return Udm::InstantiatedAttr<PICML::Supports>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Supports, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Supports, Pred>(impl);}

		Udm::DerivedAttr<PICML::Supports> Derived() { return Udm::DerivedAttr<PICML::Supports>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Supports, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Supports, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Supports> Archetype() { return Udm::ArchetypeAttr<PICML::Supports>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ObjectDef> ref() const { return Udm::PointerAttr<PICML::ObjectDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_SupportsInterfaces_parent;
		Udm::ParentAttr<PICML::SupportsInterfaces> SupportsInterfaces_parent() const { return Udm::ParentAttr<PICML::SupportsInterfaces>(impl, meta_SupportsInterfaces_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ReadonlyAttribute :  virtual public MgaObject {
	 public:
		static Uml::Class meta;

		ReadonlyAttribute() { }
		ReadonlyAttribute(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		ReadonlyAttribute(const ReadonlyAttribute &master) : MgaObject(master) { }
		static ReadonlyAttribute Cast(const Object &a) { return __Cast(a, meta); }

		static ReadonlyAttribute Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ReadonlyAttribute CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ReadonlyAttribute CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ReadonlyAttribute> Instances() { return Udm::InstantiatedAttr<PICML::ReadonlyAttribute>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ReadonlyAttribute, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ReadonlyAttribute, Pred>(impl);}

		Udm::DerivedAttr<PICML::ReadonlyAttribute> Derived() { return Udm::DerivedAttr<PICML::ReadonlyAttribute>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ReadonlyAttribute, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ReadonlyAttribute, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ReadonlyAttribute> Archetype() { return Udm::ArchetypeAttr<PICML::ReadonlyAttribute>(impl);}

		static Uml::CompositionChildRole meta_GetException_children;
		Udm::ChildrenAttr<PICML::GetException> GetException_children() const { return Udm::ChildrenAttr<PICML::GetException>(impl, meta_GetException_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::GetException, Pred> GetException_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::GetException, Pred>(impl, meta_GetException_children); }

		static Uml::CompositionChildRole meta_Member_child;
		Udm::ChildAttr<PICML::Member> Member_child() const { return Udm::ChildAttr<PICML::Member>(impl, meta_Member_child); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedSizeCollection> FixedSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::FixedSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred> FixedSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VariableSizeCollection> VariableSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::VariableSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred> VariableSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::CollectionType> CollectionType_kind_children() const { return Udm::ChildrenAttr<PICML::CollectionType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CollectionType, Pred> CollectionType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CollectionType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::GetException> GetException_kind_children() const { return Udm::ChildrenAttr<PICML::GetException>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::GetException, Pred> GetException_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::GetException, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		static Uml::CompositionParentRole meta_Inheritable_parent;
		Udm::ParentAttr<PICML::Inheritable> Inheritable_parent() const { return Udm::ParentAttr<PICML::Inheritable>(impl, meta_Inheritable_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Attribute :  public Taggable, public ReadonlyAttribute {
	 public:
		static Uml::Class meta;

		Attribute() { }
		Attribute(Udm::ObjectImpl *impl) : Taggable(impl),ReadonlyAttribute(impl), MgaObject(impl) { }
		Attribute(const Attribute &master) : Taggable(master),ReadonlyAttribute(master), MgaObject(master) { }
		static Attribute Cast(const Object &a) { return __Cast(a, meta); }

		static Attribute Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Attribute CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Attribute CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Attribute> Instances() { return Udm::InstantiatedAttr<PICML::Attribute>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Attribute, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Attribute, Pred>(impl);}

		Udm::DerivedAttr<PICML::Attribute> Derived() { return Udm::DerivedAttr<PICML::Attribute>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Attribute, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Attribute, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Attribute> Archetype() { return Udm::ArchetypeAttr<PICML::Attribute>(impl);}

		static Uml::CompositionChildRole meta_SetException_children;
		Udm::ChildrenAttr<PICML::SetException> SetException_children() const { return Udm::ChildrenAttr<PICML::SetException>(impl, meta_SetException_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::SetException, Pred> SetException_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SetException, Pred>(impl, meta_SetException_children); }

		Udm::ChildrenAttr<PICML::SetException> SetException_kind_children() const { return Udm::ChildrenAttr<PICML::SetException>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::SetException, Pred> SetException_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::SetException, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  LookupKey :  public MgaObject {
	 public:
		static Uml::Class meta;

		LookupKey() { }
		LookupKey(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		LookupKey(const LookupKey &master) : MgaObject(master) { }
		static LookupKey Cast(const Object &a) { return __Cast(a, meta); }

		static LookupKey Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		LookupKey CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		LookupKey CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<LookupKey> Instances() { return Udm::InstantiatedAttr<PICML::LookupKey>(impl);}
		template <class Pred> Udm::InstantiatedAttr<LookupKey, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::LookupKey, Pred>(impl);}

		Udm::DerivedAttr<PICML::LookupKey> Derived() { return Udm::DerivedAttr<PICML::LookupKey>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::LookupKey, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::LookupKey, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::LookupKey> Archetype() { return Udm::ArchetypeAttr<PICML::LookupKey>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ValueDef> ref() const { return Udm::PointerAttr<PICML::ValueDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_ComponentFactory_parent;
		Udm::ParentAttr<PICML::ComponentFactory> ComponentFactory_parent() const { return Udm::ParentAttr<PICML::ComponentFactory>(impl, meta_ComponentFactory_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  Manages :  public MgaObject {
	 public:
		static Uml::Class meta;

		Manages() { }
		Manages(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		Manages(const Manages &master) : MgaObject(master) { }
		static Manages Cast(const Object &a) { return __Cast(a, meta); }

		static Manages Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		Manages CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		Manages CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<Manages> Instances() { return Udm::InstantiatedAttr<PICML::Manages>(impl);}
		template <class Pred> Udm::InstantiatedAttr<Manages, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::Manages, Pred>(impl);}

		Udm::DerivedAttr<PICML::Manages> Derived() { return Udm::DerivedAttr<PICML::Manages>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::Manages, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::Manages, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::Manages> Archetype() { return Udm::ArchetypeAttr<PICML::Manages>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ComponentDef> ref() const { return Udm::PointerAttr<PICML::ComponentDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_ComponentFactory_parent;
		Udm::ParentAttr<PICML::ComponentFactory> ComponentFactory_parent() const { return Udm::ParentAttr<PICML::ComponentFactory>(impl, meta_ComponentFactory_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  SetException :  public MgaObject {
	 public:
		static Uml::Class meta;

		SetException() { }
		SetException(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		SetException(const SetException &master) : MgaObject(master) { }
		static SetException Cast(const Object &a) { return __Cast(a, meta); }

		static SetException Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		SetException CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		SetException CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<SetException> Instances() { return Udm::InstantiatedAttr<PICML::SetException>(impl);}
		template <class Pred> Udm::InstantiatedAttr<SetException, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::SetException, Pred>(impl);}

		Udm::DerivedAttr<PICML::SetException> Derived() { return Udm::DerivedAttr<PICML::SetException>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::SetException, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::SetException, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::SetException> Archetype() { return Udm::ArchetypeAttr<PICML::SetException>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ExceptionDef> ref() const { return Udm::PointerAttr<PICML::ExceptionDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_Attribute_parent;
		Udm::ParentAttr<PICML::Attribute> Attribute_parent() const { return Udm::ParentAttr<PICML::Attribute>(impl, meta_Attribute_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ObjectByValue :  public Prefixable, public HasOperations, public SupportsInterfaces {
	 public:
		static Uml::Class meta;

		ObjectByValue() { }
		ObjectByValue(Udm::ObjectImpl *impl) : Prefixable(impl),HasOperations(impl),SupportsInterfaces(impl), Inheritable(impl), MgaObject(impl) { }
		ObjectByValue(const ObjectByValue &master) : Prefixable(master),HasOperations(master),SupportsInterfaces(master), Inheritable(master), MgaObject(master) { }
		static ObjectByValue Cast(const Object &a) { return __Cast(a, meta); }

		static ObjectByValue Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ObjectByValue CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ObjectByValue CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ObjectByValue> Instances() { return Udm::InstantiatedAttr<PICML::ObjectByValue>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ObjectByValue, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ObjectByValue, Pred>(impl);}

		Udm::DerivedAttr<PICML::ObjectByValue> Derived() { return Udm::DerivedAttr<PICML::ObjectByValue>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ObjectByValue, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ObjectByValue, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ObjectByValue> Archetype() { return Udm::ArchetypeAttr<PICML::ObjectByValue>(impl);}

		static Uml::Attribute meta_custom;
		Udm::BooleanAttr custom() const { return Udm::BooleanAttr(impl, meta_custom); }

		static Uml::Attribute meta_abstract;
		Udm::BooleanAttr abstract() const { return Udm::BooleanAttr(impl, meta_abstract); }

		static Uml::Attribute meta_truncatable;
		Udm::BooleanAttr truncatable() const { return Udm::BooleanAttr(impl, meta_truncatable); }

		static Uml::CompositionChildRole meta_Member_children;
		Udm::ChildrenAttr<PICML::Member> Member_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, meta_Member_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, meta_Member_children); }

		static Uml::CompositionChildRole meta_FactoryOperation_children;
		Udm::ChildrenAttr<PICML::FactoryOperation> FactoryOperation_children() const { return Udm::ChildrenAttr<PICML::FactoryOperation>(impl, meta_FactoryOperation_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::FactoryOperation, Pred> FactoryOperation_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FactoryOperation, Pred>(impl, meta_FactoryOperation_children); }

		static Uml::CompositionChildRole meta_PrivateFlag_children;
		Udm::ChildrenAttr<PICML::PrivateFlag> PrivateFlag_children() const { return Udm::ChildrenAttr<PICML::PrivateFlag>(impl, meta_PrivateFlag_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::PrivateFlag, Pred> PrivateFlag_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PrivateFlag, Pred>(impl, meta_PrivateFlag_children); }

		static Uml::CompositionChildRole meta_MakeMemberPrivate_children;
		Udm::ChildrenAttr<PICML::MakeMemberPrivate> MakeMemberPrivate_children() const { return Udm::ChildrenAttr<PICML::MakeMemberPrivate>(impl, meta_MakeMemberPrivate_children); }
		 template <class Pred> Udm::ChildrenAttr<PICML::MakeMemberPrivate, Pred> MakeMemberPrivate_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MakeMemberPrivate, Pred>(impl, meta_MakeMemberPrivate_children); }

		Udm::ChildrenAttr<PICML::NamedTypeRef> NamedTypeRef_kind_children() const { return Udm::ChildrenAttr<PICML::NamedTypeRef>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::NamedTypeRef, Pred> NamedTypeRef_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::NamedTypeRef, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Member> Member_kind_children() const { return Udm::ChildrenAttr<PICML::Member>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Member, Pred> Member_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Member, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::Taggable> Taggable_kind_children() const { return Udm::ChildrenAttr<PICML::Taggable>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::Taggable, Pred> Taggable_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::Taggable, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::OperationBase> OperationBase_kind_children() const { return Udm::ChildrenAttr<PICML::OperationBase>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::OperationBase, Pred> OperationBase_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::OperationBase, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::HasExceptions> HasExceptions_kind_children() const { return Udm::ChildrenAttr<PICML::HasExceptions>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::HasExceptions, Pred> HasExceptions_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::HasExceptions, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FactoryOperation> FactoryOperation_kind_children() const { return Udm::ChildrenAttr<PICML::FactoryOperation>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FactoryOperation, Pred> FactoryOperation_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FactoryOperation, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::BoundedString> BoundedString_kind_children() const { return Udm::ChildrenAttr<PICML::BoundedString>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::BoundedString, Pred> BoundedString_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::BoundedString, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedSizeCollection> FixedSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::FixedSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred> FixedSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::VariableSizeCollection> VariableSizeCollection_kind_children() const { return Udm::ChildrenAttr<PICML::VariableSizeCollection>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred> VariableSizeCollection_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::VariableSizeCollection, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::AnonymousType> AnonymousType_kind_children() const { return Udm::ChildrenAttr<PICML::AnonymousType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::AnonymousType, Pred> AnonymousType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::AnonymousType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::CollectionType> CollectionType_kind_children() const { return Udm::ChildrenAttr<PICML::CollectionType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::CollectionType, Pred> CollectionType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::CollectionType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PredefinedType> PredefinedType_kind_children() const { return Udm::ChildrenAttr<PICML::PredefinedType>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PredefinedType, Pred> PredefinedType_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PredefinedType, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::FixedPoint> FixedPoint_kind_children() const { return Udm::ChildrenAttr<PICML::FixedPoint>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::FixedPoint, Pred> FixedPoint_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::FixedPoint, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::PrivateFlag> PrivateFlag_kind_children() const { return Udm::ChildrenAttr<PICML::PrivateFlag>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::PrivateFlag, Pred> PrivateFlag_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::PrivateFlag, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MakeMemberPrivate> MakeMemberPrivate_kind_children() const { return Udm::ChildrenAttr<PICML::MakeMemberPrivate>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MakeMemberPrivate, Pred> MakeMemberPrivate_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MakeMemberPrivate, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ChildrenAttr<PICML::MgaObject> MgaObject_kind_children() const { return Udm::ChildrenAttr<PICML::MgaObject>(impl, Udm::NULLCHILDROLE); }
		template<class Pred> Udm::ChildrenAttr<PICML::MgaObject, Pred> MgaObject_kind_children_sorted(const Pred &) const { return Udm::ChildrenAttr<PICML::MgaObject, Pred>(impl, Udm::NULLCHILDROLE); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  EventDef :  public ObjectByValue {
	 public:
		static Uml::Class meta;

		EventDef() { }
		EventDef(Udm::ObjectImpl *impl) : ObjectByValue(impl), Inheritable(impl), MgaObject(impl) { }
		EventDef(const EventDef &master) : ObjectByValue(master), Inheritable(master), MgaObject(master) { }
		static EventDef Cast(const Object &a) { return __Cast(a, meta); }

		static EventDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		EventDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		EventDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<EventDef> Instances() { return Udm::InstantiatedAttr<PICML::EventDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<EventDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::EventDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::EventDef> Derived() { return Udm::DerivedAttr<PICML::EventDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::EventDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::EventDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::EventDef> Archetype() { return Udm::ArchetypeAttr<PICML::EventDef>(impl);}

		static Uml::AssociationRole meta_referedbyEventRef;
		Udm::AssocAttr<PICML::EventRef> referedbyEventRef() const { return Udm::AssocAttr<PICML::EventRef>(impl, meta_referedbyEventRef); }
		template <class Pred> Udm::AssocAttr<PICML::EventRef, Pred > referedbyEventRef_sorted(const Pred &) const { return Udm::AssocAttr<PICML::EventRef, Pred>(impl, meta_referedbyEventRef); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  ValueDef :  public ObjectByValue {
	 public:
		static Uml::Class meta;

		ValueDef() { }
		ValueDef(Udm::ObjectImpl *impl) : ObjectByValue(impl), Inheritable(impl), MgaObject(impl) { }
		ValueDef(const ValueDef &master) : ObjectByValue(master), Inheritable(master), MgaObject(master) { }
		static ValueDef Cast(const Object &a) { return __Cast(a, meta); }

		static ValueDef Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		ValueDef CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		ValueDef CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<ValueDef> Instances() { return Udm::InstantiatedAttr<PICML::ValueDef>(impl);}
		template <class Pred> Udm::InstantiatedAttr<ValueDef, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::ValueDef, Pred>(impl);}

		Udm::DerivedAttr<PICML::ValueDef> Derived() { return Udm::DerivedAttr<PICML::ValueDef>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::ValueDef, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::ValueDef, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::ValueDef> Archetype() { return Udm::ArchetypeAttr<PICML::ValueDef>(impl);}

		static Uml::AssociationRole meta_referedbyLookupKey;
		Udm::AssocAttr<PICML::LookupKey> referedbyLookupKey() const { return Udm::AssocAttr<PICML::LookupKey>(impl, meta_referedbyLookupKey); }
		template <class Pred> Udm::AssocAttr<PICML::LookupKey, Pred > referedbyLookupKey_sorted(const Pred &) const { return Udm::AssocAttr<PICML::LookupKey, Pred>(impl, meta_referedbyLookupKey); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  GetException :  public MgaObject {
	 public:
		static Uml::Class meta;

		GetException() { }
		GetException(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		GetException(const GetException &master) : MgaObject(master) { }
		static GetException Cast(const Object &a) { return __Cast(a, meta); }

		static GetException Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		GetException CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		GetException CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<GetException> Instances() { return Udm::InstantiatedAttr<PICML::GetException>(impl);}
		template <class Pred> Udm::InstantiatedAttr<GetException, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::GetException, Pred>(impl);}

		Udm::DerivedAttr<PICML::GetException> Derived() { return Udm::DerivedAttr<PICML::GetException>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::GetException, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::GetException, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::GetException> Archetype() { return Udm::ArchetypeAttr<PICML::GetException>(impl);}

		static Uml::AssociationRole meta_ref;
		Udm::PointerAttr<PICML::ExceptionDef> ref() const { return Udm::PointerAttr<PICML::ExceptionDef>(impl, meta_ref); }

		static Uml::CompositionParentRole meta_ReadonlyAttribute_parent;
		Udm::ParentAttr<PICML::ReadonlyAttribute> ReadonlyAttribute_parent() const { return Udm::ParentAttr<PICML::ReadonlyAttribute>(impl, meta_ReadonlyAttribute_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  PrivateFlag :  public MgaObject {
	 public:
		static Uml::Class meta;

		PrivateFlag() { }
		PrivateFlag(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		PrivateFlag(const PrivateFlag &master) : MgaObject(master) { }
		static PrivateFlag Cast(const Object &a) { return __Cast(a, meta); }

		static PrivateFlag Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		PrivateFlag CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		PrivateFlag CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<PrivateFlag> Instances() { return Udm::InstantiatedAttr<PICML::PrivateFlag>(impl);}
		template <class Pred> Udm::InstantiatedAttr<PrivateFlag, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::PrivateFlag, Pred>(impl);}

		Udm::DerivedAttr<PICML::PrivateFlag> Derived() { return Udm::DerivedAttr<PICML::PrivateFlag>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::PrivateFlag, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::PrivateFlag, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::PrivateFlag> Archetype() { return Udm::ArchetypeAttr<PICML::PrivateFlag>(impl);}

		static Uml::AssociationRole meta_srcMakeMemberPrivate, meta_srcMakeMemberPrivate_rev;
		Udm::AClassPointerAttr<PICML::MakeMemberPrivate, PICML::Member> srcMakeMemberPrivate() const { return Udm::AClassPointerAttr<PICML::MakeMemberPrivate, PICML::Member>(impl, meta_srcMakeMemberPrivate, meta_srcMakeMemberPrivate_rev); }

		static Uml::CompositionParentRole meta_ObjectByValue_parent;
		Udm::ParentAttr<PICML::ObjectByValue> ObjectByValue_parent() const { return Udm::ParentAttr<PICML::ObjectByValue>(impl, meta_ObjectByValue_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
	};

	class  MakeMemberPrivate :  public MgaObject {
	 public:
		static Uml::Class meta;

		MakeMemberPrivate() { }
		MakeMemberPrivate(Udm::ObjectImpl *impl) : MgaObject(impl) { }
		MakeMemberPrivate(const MakeMemberPrivate &master) : MgaObject(master) { }
		static MakeMemberPrivate Cast(const Object &a) { return __Cast(a, meta); }

		static MakeMemberPrivate Create(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role); }

		MakeMemberPrivate CreateInstance(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl); }

		MakeMemberPrivate CreateDerived(const Object &parent, const Uml::CompositionChildRole &role = Udm::NULLCHILDROLE) { return __Create(meta, parent, role, impl, true); }

		Udm::InstantiatedAttr<MakeMemberPrivate> Instances() { return Udm::InstantiatedAttr<PICML::MakeMemberPrivate>(impl);}
		template <class Pred> Udm::InstantiatedAttr<MakeMemberPrivate, Pred> Instances_sorted(const Pred &) { return Udm::InstantiatedAttr<PICML::MakeMemberPrivate, Pred>(impl);}

		Udm::DerivedAttr<PICML::MakeMemberPrivate> Derived() { return Udm::DerivedAttr<PICML::MakeMemberPrivate>(impl);}
		template <class Pred> Udm::DerivedAttr<PICML::MakeMemberPrivate, Pred> Derived_sorted(const Pred &) { return Udm::DerivedAttr<PICML::MakeMemberPrivate, Pred>(impl);}

		Udm::ArchetypeAttr<PICML::MakeMemberPrivate> Archetype() { return Udm::ArchetypeAttr<PICML::MakeMemberPrivate>(impl);}

		static Uml::CompositionParentRole meta_ObjectByValue_parent;
		Udm::ParentAttr<PICML::ObjectByValue> ObjectByValue_parent() const { return Udm::ParentAttr<PICML::ObjectByValue>(impl, meta_ObjectByValue_parent); }

		Udm::ParentAttr<PICML::MgaObject> parent() const { return Udm::ParentAttr<PICML::MgaObject>(impl, Udm::NULLPARENTROLE); }
		static Uml::AssociationRole meta_srcMakeMemberPrivate_end_;
		Udm::AssocEndAttr<PICML::Member> srcMakeMemberPrivate_end() const { return Udm::AssocEndAttr<PICML::Member>(impl, meta_srcMakeMemberPrivate_end_); }

		static Uml::AssociationRole meta_dstMakeMemberPrivate_end_;
		Udm::AssocEndAttr<PICML::PrivateFlag> dstMakeMemberPrivate_end() const { return Udm::AssocEndAttr<PICML::PrivateFlag>(impl, meta_dstMakeMemberPrivate_end_); }

	};

}

#endif //MOBIES_PICML_H
