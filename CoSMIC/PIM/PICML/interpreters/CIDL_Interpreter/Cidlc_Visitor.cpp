#include "Cidlc_Visitor.h"


namespace PICML
{
  Cidlc_Visitor::Cidlc_Visitor (const std::string& outputPath)
    : outputPath_ (outputPath)
  {
    
  }

  Cidlc_Visitor::~Cidlc_Visitor ()
  {
    
  }

  void Cidlc_Visitor::Visit_RootFolder(const RootFolder&)
  {}

  void Cidlc_Visitor::process_Factory_decl(std::set<PICML::ComponentFactory> &factory)
  {
	  if (factory.size () != 0)
	  {
		  std::set<PICML::ComponentFactory>::iterator iter =
			  factory.begin ();
		  for (; iter != factory.end (); iter ++)
			  Visit_ComponentFactory (*iter);
	  }

	  // Write the cidl files by visiting the components
	  std::map<PICML::Component, std::vector<std::string> >::iterator iter = 
		  this->table_.begin ();
	  for (; iter != this->table_.end (); iter ++)
		  this->Visit_Component ((* iter).first);
  }


  // Visit the File
  void Cidlc_Visitor::Visit_File (const File &file)
  {
	  // Obtain the name of the IDL file 
	  file.GetStrValue ("name", this->idl_file_name_);

	  // check if there are any componentFactory definitions
	  // present
	  std::set<PICML::ComponentFactory> factory = 
		file.ComponentFactory_kind_children();

	  //For each Component Factory Definitions visit the Factory
	  this->process_Factory_decl (factory);

	  // Check for Packages
	  std::set<PICML::Package> packages = 
		  file.Package_kind_children ();

	  if (packages.size () != 0)
	  {
		  for (std::set<PICML::Package>::iterator iter = packages.begin ();
		       iter != packages.end ();
			   iter ++)
			   {
				   // For each iteration set the package size
				   (* iter).GetStrValue ("name", this->package_name_);

				  std::set<PICML::ComponentFactory> p_factory = 
					(* iter).ComponentFactory_kind_children();	

				  this->process_Factory_decl (p_factory);
			   }
	  }
  }

  void 
  Cidlc_Visitor::Visit_ComponentFactory (const ComponentFactory &factory)
  {
	 // 1: Get the name of this Factory
	 std::string factory_name;
	 factory.GetStrValue ("name", factory_name);

	 // Get the Corresponding name of the Component associated with the 
	 // factory
	 const PICML::ManagesComponent conn = factory.dstManagesComponent();
	 PICML::Manageable base = conn.dstManagesComponent_end();

	 // For each connection get the source ComponentFactory
	 std::string kindName = base.type().name ();

	 PICML::Component component;
	 if (kindName == "Component")
		 component = PICML::Component::Cast (base);
	 else 
	 {	
		 PICML::ComponentRef ref = 
			 PICML::ComponentRef::Cast (base);
		 component = ref.ref ();
	 }

	 // Associate the FactoryName with the Component Name
	 std::vector<std::string> values;

	 if (this->table_.find (component) != this->table_.end ())
		 values = this->table_ [component];
	 
	 values.push_back (factory_name);
	 this->table_[component] = values;
  }

  void
  Cidlc_Visitor::Visit_ComponentRef(const ComponentRef& componentRef)
  {
	  PICML::Component component = componentRef.ref ();
	  this->Visit_Component (component);
  }

  void
  Cidlc_Visitor::Visit_Component (const Component& component)
  {
	 // Simple Algorithm to write out the cidlc file
	 // Step 1: Read the names of the homes thats are associated with 
	 //         this component
	 // Step 2: Write out the cidlc files starting from the #ifdef macros
	 //         for each of the home factory components associated
	 // Step 3: Close the cidlc file

     // 1: Obtain the name of the Component and open the .cidl file
	  std::string component_name;
	  component.GetStrValue ("name", component_name);

	  // Outputpath refers to a directory
	  // The target file is : <dir> + "\" + fileName + ".cidl"
	  std::string file_name = this->outputPath_ + "\\" + component_name + ".cidl";
	  std::ofstream file_stream (file_name.c_str ());

	 // 2: Write out the header information onto this file
	 IDLStream idl_writer (file_stream);
	 idl_writer.gen_ifdef_macro (component_name.c_str ());

	 // 3: Write out the Dependent IDL files
	 idl_writer.nl ();
	 idl_writer.gen_cidlc_include (this->idl_file_name_);

	 // 4: Write out the composition declaration
	 idl_writer.nl ();
	 idl_writer.gen_cidlc_composition (component_name);

	 // 5: Obtain the names of the hometypes that manage this
	 //    component instance
	 std::vector<std::string> &factory_names = this->table_[component];
	 for (std::vector<std::string>::iterator iter = factory_names.begin ();
		  iter != factory_names.end ();
		  iter ++)
		  {
			  idl_writer.incr_indent (0);
			  idl_writer.indent ();
			  idl_writer.gen_cidlc_home_decl (component_name);
			  
			  // Write the implements decl
			  std::string home_name;
			  if (this->package_name_.size () != 0)
				  home_name = this->package_name_ + "::" + (* iter);
			  else
				  home_name = (* iter);

			  idl_writer.incr_indent (0);
			  idl_writer.indent ();
			  idl_writer.gen_cidlc_implements_decl (home_name);

			  //Write the manages decl
			  idl_writer.indent ();
			  idl_writer.gen_cidlc_manages_decl (component_name);

			  // Close the home executor decl
			  idl_writer.decr_indent (0);
			  idl_writer.indent ();
			  idl_writer << "};";
			  idl_writer.nl ();

			  // Close the composition decl
			  idl_writer.decr_indent (0);
			  idl_writer.indent ();
			  idl_writer << "};";
			  idl_writer.nl ();
		  }

		  // Write the #endif decl
		  idl_writer.gen_endif (component_name);
  }

  // Predefined Types
  void Cidlc_Visitor::Visit_LongInteger(const LongInteger&)
  {}

  void Cidlc_Visitor::Visit_Boolean(const Boolean&)
  {}

  void Cidlc_Visitor::Visit_ShortInteger(const ShortInteger&)
  {}

  // Implementation Artifact operations

  void Cidlc_Visitor::Visit_ImplementationArtifacts(const ImplementationArtifacts& ia)
  {
    
  }

  void Cidlc_Visitor::Visit_ArtifactContainer(const ArtifactContainer& ac)
  {
    
  }

  void Cidlc_Visitor::Visit_ImplementationArtifact(const ImplementationArtifact& ia)
  {
    
  }

  void Cidlc_Visitor::Visit_ArtifactDependsOn(const ArtifactDependsOn& ado)
  {
    
  }

  void Cidlc_Visitor::Visit_ImplementationArtifactReference(const ImplementationArtifactReference& iar)
  {
    
  }

  void Cidlc_Visitor::Visit_ArtifactExecParameter(const ArtifactExecParameter& param)
  {
    
  }

  void Cidlc_Visitor::Visit_Property(const Property& property)
  {
    
  }

  void Cidlc_Visitor::Visit_DataType(const DataType& type)
  {
    
  }

  void Cidlc_Visitor::Visit_String(const String& str)
  {
    
  }

  void Cidlc_Visitor::Visit_ArtifactDeployRequirement(const ArtifactDeployRequirement&)
  {}

  void Cidlc_Visitor::Visit_ArtifactInfoProperty(const ArtifactInfoProperty&)
  {}

  void Cidlc_Visitor::Visit_ImplementationRequirement(const ImplementationRequirement&)
  {}

  void Cidlc_Visitor::Visit_TopLevelPackages(const TopLevelPackages& tp)
  {
    
  }


  void Cidlc_Visitor::Visit_TopLevelPackageContainer(const TopLevelPackageContainer& tpc)
  {
    
  }

  void Cidlc_Visitor::Visit_TopLevelPackage(const TopLevelPackage& tp)
  {
    
  }

  void Cidlc_Visitor::Visit_package(const package& pkg)
  {
    
  }

  void Cidlc_Visitor::Visit_PackageConfigurationReference(const PackageConfigurationReference& pcr)
  {
    
  }

  void Cidlc_Visitor::Visit_PackageConfigurations(const PackageConfigurations& pcs)
  {
    
  }

  void Cidlc_Visitor::Visit_PackageConfigurationContainer(const PackageConfigurationContainer& pcc)
  {
    
  }

  void Cidlc_Visitor::Visit_PackageConfiguration(const PackageConfiguration& pc)
  {
    
  }

  void Cidlc_Visitor::Visit_PackageConfConfigProperty(const PackageConfConfigProperty&)
  {}

  void Cidlc_Visitor::Visit_PackageConfReference(const PackageConfReference&)
  {}

  void Cidlc_Visitor::Visit_PackageConfSpecializedConfig(const PackageConfSpecializedConfig&)
  {}

  void Cidlc_Visitor::Visit_PackageConfSelectRequirement(const PackageConfSelectRequirement&)
  {}

  void Cidlc_Visitor::Visit_PackageConfBasePackage(const PackageConfBasePackage&)
  {}

  void Cidlc_Visitor::Visit_ComponentPackageReference(const ComponentPackageReference&)
  {}

  void Cidlc_Visitor::Visit_DeploymentPlans(const DeploymentPlans&)
  {}

  void Cidlc_Visitor::Visit_DeploymentPlan(const DeploymentPlan& dp)
  { 
	  
  }

  void Cidlc_Visitor::Visit_InstanceMapping(const InstanceMapping& ins_map)
  {
	  
  }

  void Cidlc_Visitor::Visit_NodeReference(const NodeReference& node_ref)
  {
  }

  // Visit Component Assembly
  void Cidlc_Visitor::Visit_ComponentAssembly (const ComponentAssembly &assmb_ref)
  {
  }

}
