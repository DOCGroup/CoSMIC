// $Id$

#include "CoWorkEr_Generator.h"
#include "CUTS_Project.h"
#include "UDM_Utility_T.h"
#include "Uml.h"
#include "boost/bind.hpp"
#include <stack>
#include <sstream>

// Static decl.
static const std::string COWORKER_SUFFIX ("_CoWorkEr");

// Static decl.
static const std::string COWORKER_RECEPTACLE ("cuts_testing_service");

// Static decl.
static const std::string COWORKER_PROXY_IMPL ("cuts_proxy_impl");

// Static decl.
static const std::string CUTS_PREFIX ("CUTS_");

// Static decl.
static const std::string CUTS_FILE ("cuts/");

// Static decl.
static const std::string
COWORKER_INTERFACE_FOLDER ("CoWorkEr_InterfaceDefinitions");

static const std::string
COWORKER_ARTIFACT_FOLDER ("CoWorkEr_ImplementationArtifacts");

static const std::string
COWORKER_IMPLEMENTATION_FOLDER ("CoWorkEr_ComponentImplementations");

static const std::string
COWORKER_PACKAGE_FOLDER ("CoWorkEr_ComponentPackages");

//
// CUTS_CoWorkEr_Generator
//
CUTS_CoWorkEr_Generator::CUTS_CoWorkEr_Generator (void)
{

}

//
// ~CUTS_CoWorkEr_Generator
//
CUTS_CoWorkEr_Generator::~CUTS_CoWorkEr_Generator (void)
{

}

//
// Visit_RootFolder
//
void CUTS_CoWorkEr_Generator::
Visit_RootFolder (const PICML::RootFolder & root)
{
  // Get all the <PICML::InterfaceDefinitions> elements.
  typedef std::vector <PICML::InterfaceDefinitions> IDefs_Set;
  IDefs_Set idefs = root.InterfaceDefinitions_children ();

  // We need to locate the <CoWorkEr_InterfaceDefinitions> folder
  // or create one since this is where all the <CoWorkErs> will be
  // placed.
  if (create_element_if_not_exist (idefs,
                                   Find_Element_By_Name <
                                      PICML::InterfaceDefinitions> (
                                      COWORKER_INTERFACE_FOLDER),
                                   root,
                                   Udm::NULLCHILDROLE,
                                   this->coworker_idefs_))
  {
    this->coworker_idefs_.SetStrValue ("name", COWORKER_INTERFACE_FOLDER);
  }

  typedef std::vector <PICML::ImplementationArtifacts> Artifacts_Set;
  Artifacts_Set artifacts = root.ImplementationArtifacts_children ();

  // We need to locate the <CoWorkEr_InterfaceDefinitions> folder
  // or create one since this is where all the <CoWorkErs> will be
  // placed.
  if (create_element_if_not_exist (artifacts,
                                   Find_Element_By_Name <
                                      PICML::ImplementationArtifacts> (
                                      COWORKER_ARTIFACT_FOLDER),
                                   root,
                                   Udm::NULLCHILDROLE,
                                   this->coworker_artifacts_))
  {
    this->coworker_artifacts_.SetStrValue ("name", COWORKER_ARTIFACT_FOLDER);
  }

  typedef std::vector <PICML::ComponentImplementations> Implementations_Set;
  Implementations_Set impls = root.ComponentImplementations_children ();

  // We need to locate the <CoWorkEr_InterfaceDefinitions> folder
  // or create one since this is where all the <CoWorkErs> will be
  // placed.
  if (create_element_if_not_exist (impls,
                                   Find_Element_By_Name <
                                      PICML::ComponentImplementations> (
                                      COWORKER_IMPLEMENTATION_FOLDER),
                                   root,
                                   Udm::NULLCHILDROLE,
                                   this->coworker_implementations_))
  {
    this->coworker_implementations_.
      SetStrValue ("name", COWORKER_IMPLEMENTATION_FOLDER);
  }

  typedef std::vector <PICML::ComponentPackages> Packages_Set;
  Packages_Set packages = root.ComponentPackages_children ();

  // We need to locate the <CoWorkEr_InterfaceDefinitions> folder
  // or create one since this is where all the <CoWorkErs> will be
  // placed.
  if (create_element_if_not_exist (packages,
                                   Find_Element_By_Name <
                                      PICML::ComponentPackages> (
                                      COWORKER_PACKAGE_FOLDER),
                                   root,
                                   Udm::NULLCHILDROLE,
                                   this->coworker_packages_))
  {
    this->coworker_packages_.
      SetStrValue ("name", COWORKER_PACKAGE_FOLDER);
  }

  this->Visit_RootFolder_i (root);
}

//
// Visit_InterfaceDefinitions
//
void CUTS_CoWorkEr_Generator::
Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions & idefs)
{
  // Get all the <PICML::File> elements in this folder.
  typedef std::vector <PICML::File> File_Set;

  File_Set files = idefs.File_children ();
  File_Set coworker_files = this->coworker_idefs_.File_children ();
  PICML::File coworker_file;

  for (File_Set::iterator iter = files.begin ();
       iter != files.end ();
       iter ++)
  {
    // We ingore any string's (i.e., filenames) that contains 'cuts/'
    std::string name = iter->name ();

    if (name.find (CUTS_FILE) != std::string::npos)
      continue;

    // Get the <CoWorkEr> equivalent <PICML::File>. If we do not
    // find it we need to create a new one.
    name += COWORKER_SUFFIX;
    if (create_element_if_not_exist (coworker_files,
                                     Find_Element_By_Name <PICML::File> (
                                     name),
                                     this->coworker_idefs_,
                                     Udm::NULLCHILDROLE,
                                     coworker_file))
    {
      coworker_file.SetStrValue ("name", name);
    }

    // Reset the number of <coworker_count_> before we start parsing this
    // file. This will determine if this IDL files is necessary.
    this->coworker_parent_ = coworker_file;
    this->coworker_count_ = 0;

    iter->Accept (*this);

    // Delete the parent if there are not <coworkers_>.
    if (this->coworker_count_ == 0)
      this->coworker_parent_.DeleteObject ();
  }
}

//
// Visit_File
//
void CUTS_CoWorkEr_Generator::Visit_File (const PICML::File & file)
{
  // Visit the contents of this file.
  this->visit_file_and_package (file);

  if (this->coworker_count_ > 0)
  {
    // Let's create an explicit file reference to the <cuts/CUTS> file. We
    // need to make sure one does not already exist in the <coworker_parent_>
    // model which is really a <PICML::File> element.

    typedef std::vector <PICML::FileRef> FileRef_Set;
    FileRef_Set filerefs =
      Udm::ChildrenAttr <PICML::FileRef> (this->coworker_parent_.__impl (),
                                          Udm::NULLCHILDROLE);
    PICML::File file;
    FileRef_Set::iterator iter;

    // Try and locate the <cuts/CUTS> file reference in the current
    // collection of file references.
    for (iter = filerefs.begin (); iter != filerefs.end (); iter ++)
    {
      file = PICML::File::Cast (iter->ref ());

      if (file == CUTS_Project::instance ()->get_cuts_file ())
        break;
    }

    if (iter == filerefs.end ())
    {
      // Create a file reference since one doesn't exist.
      PICML::FileRef fileref =
        PICML::FileRef::Create (this->coworker_parent_);

      fileref.ref () = CUTS_Project::instance ()->get_cuts_file ();
    }
  }
}

//
// Visit_Package
//
void CUTS_CoWorkEr_Generator::
Visit_Package (const PICML::Package & package)
{
  this->visit_file_and_package (package);
}

//
// Visit_Component
//
void CUTS_CoWorkEr_Generator::
Visit_Component (const PICML::Component & component)
{
  // Get all the <PICML::ProvidedRequestPort> for this component.
  typedef std::vector <PICML::RequiredRequestPort> Receptacle_Set;

  Receptacle_Set receptacles =
    this->coworker_.RequiredRequestPort_kind_children ();

  // 1. We need to locate the <cuts_testing_service> receptacles. This
  //    receptacle allows the benchmark data collector to connect to the
  //    component collect metrics.
  PICML::RequiredRequestPort testing_service;

  if (create_element_if_not_exist (receptacles,
                                   Find_Element_By_Name <
                                      PICML::RequiredRequestPort> (
                                      COWORKER_RECEPTACLE),
                                   this->coworker_,
                                   Udm::NULLCHILDROLE,
                                   testing_service))
  {
    testing_service.SetStrValue ("name", COWORKER_RECEPTACLE);
  }

  // Now that we have a testing service receptacle, we need to
  // verify that is is indeed connected to a testing service object.
  PICML::Object testsvc = PICML::Object::Cast (testing_service.ref ());

  if (testsvc != CUTS_Project::instance ()->get_testing_service ())
    testing_service.ref () = CUTS_Project::instance ()->get_testing_service ();

  // 2. We need to locate the <cuts_proxy_impl> attribute. This attribute
  //    the proxy to load the correct implementation.
  typedef std::vector <PICML::Attribute> Attribute_Set;
  Attribute_Set attributes = component.Attribute_kind_children ();

  PICML::Attribute proxy_impl;

  if (create_element_if_not_exist (attributes,
                                   Find_Element_By_Name <
                                      PICML::Attribute> (
                                      COWORKER_PROXY_IMPL),
                                   this->coworker_,
                                   Udm::NULLCHILDROLE,
                                   proxy_impl))
  {
    proxy_impl.SetStrValue ("name", COWORKER_PROXY_IMPL);
  }

  // We now need to verify that the attribute is a string type.
  PICML::AttributeMember member = proxy_impl.AttributeMember_child ();

  if (member == Udm::null)
    member = PICML::AttributeMember::Create (proxy_impl);

  PICML::MemberType mtype = member.ref ();

  if (mtype == Udm::null || mtype.type () != PICML::String::meta)
    member.ref () = CUTS_Project::instance ()->get_string_type ();

  // 3. Lastly, we need to create a home for this <coworker_>. The home
  //    must be a subtype of the real components home.
  typedef std::set <PICML::ManagesComponent> Manages_Set;
  Manages_Set manages = component.srcManagesComponent ();

  // We can stop if we don't have any connection.
  //
  // @@ TODO verify the component isn't referenced since the home
  //    could be connected to the reference.
  if (manages.empty ())
    return;

  PICML::ComponentFactory factory =
    manages.begin ()->srcManagesComponent_end ();

  Manages_Set coworker_manages = this->coworker_.srcManagesComponent ();

  // There is no need to continue if we already have a factory attached
  // to the <coworker_>.

  // @@todo We need make sure the factory of the coworker component is
  //        an instance of the real component's factory.
  if (coworker_manages.empty ())
  {
    // Create the factory for the <coworker_>. We need to set the name of
    // the factory as well.
    this->coworker_factory_ =
      PICML::ComponentFactory::Create (this->coworker_parent_);

    std::string factname = (std::string)factory.name () + COWORKER_SUFFIX;
    this->coworker_factory_.SetStrValue ("name", factname);

    // Create the <Inherits> element to for the <coworker_factory_>.
    PICML::Inherits inherits =
      PICML::Inherits::Create (this->coworker_factory_);
    inherits.SetStrValue ("name", factory.name ());
    inherits.ref () = factory;

    // Create the connection between <cfactory> and <coworker_>
    PICML::ManagesComponent manages_conn =
      PICML::ManagesComponent::Create (this->coworker_parent_);

    manages_conn.dstManagesComponent_end () = this->coworker_;
    manages_conn.srcManagesComponent_end () = this->coworker_factory_;

    // Set the position of the factory.
    this->coworker_factory_.position () = factory.position ();
  }
}

//
// visit_file_and_package
//
void CUTS_CoWorkEr_Generator::
visit_file_and_package (const Udm::Object & object)
{
  // Get all the <Component> elements at this level and create a
  // duplicate copy of them in the <coworker_parent_>.
  typedef std::vector <PICML::Component> Component_Set;

  Component_Set components =
    Udm::ChildrenAttr <PICML::Component> (object.__impl (),
                                          Udm::NULLCHILDROLE);

  Component_Set coworker_components =
    Udm::ChildrenAttr <PICML::Component> (this->coworker_parent_.__impl (),
                                          Udm::NULLCHILDROLE);

  for (Component_Set::iterator iter = components.begin ();
       iter != components.end ();
       iter ++)
  {
    //@@ There has to be a better way to determine if the found
    //   coworker is a subtype of <*iter>.

    // Construct the name of the coworker.
    std::string name = (std::string)iter->name () + COWORKER_SUFFIX;

    // Try and find this element in the <coworker_components>.
    Component_Set::iterator citer =
      std::find_if (coworker_components.begin (),
                    coworker_components.end (),
                    Find_Element_By_Name <PICML::Component> (name));

    if (citer == coworker_components.end ())
    {
      // Create the coworker element. This new element is a subtype
      // of the actual component.
      this->coworker_ = iter->CreateDerived (this->coworker_parent_);
      this->coworker_.SetStrValue ("name", name);
    }
    else
      this->coworker_ = *iter;

    this->coworker_.position () = iter->position ();

    // Increment the <coworker_count_> and visit this component. We
    // need add the necessary elements to the component to make it a
    // true coworker.
    ++ this->coworker_count_;
    iter->Accept (*this);

    // Generate the artifacts and implemenation for <coworker_>.
    Artifact_Set artifacts;
    PICML::MonolithicImplementation monolithic;

    this->generate_artifacts (artifacts);
    this->generate_monolithic_implementation (artifacts, monolithic);
    this->generate_monolithic_package (monolithic);
  }

  // New that we have handle all the components at this level, we can
  // handle all the packages. So, get all the <PICML::Package> elements
  // in <object>.
  typedef std::vector <PICML::Package> Package_Set;

  Package_Set packages =
    Udm::ChildrenAttr <PICML::Package> (
    object.__impl (), Udm::NULLCHILDROLE);

  // Get the current <PICML::Package> elements in <coworker_parent_>.
  Package_Set coworker_packages =
    Udm::ChildrenAttr <PICML::Package> (
    this->coworker_parent_.__impl (), Udm::NULLCHILDROLE);

  PICML::Package coworker_package;

  // Let's make sure all the package elements in <packages> exists
  // in <coworker_parent_>.
  for (Package_Set::iterator package_iter = packages.begin ();
       package_iter != packages.end ();
       package_iter ++)
  {
    // We need to either find the correct package, or create the
    // package if we can't find it.
    std::string package_name = package_iter->name ();

    if (create_element_if_not_exist (coworker_packages,
                                     Find_Element_By_Name <PICML::Package> (
                                     package_name),
                                     this->coworker_parent_,
                                     Udm::NULLCHILDROLE,
                                     coworker_package))
    {
      coworker_package.SetStrValue ("name", package_name);
    }

    // Save everything before we visit this package.
    size_t prev_coworker_count = this->coworker_count_;

    Udm::Object prev_coworker_parent = this->coworker_parent_;
    this->coworker_parent_ = coworker_package;

    package_iter->Accept (*this);

    // If we haven't created any new <coworker_count_>, we can delete
    // this package.
    if (prev_coworker_count == this->coworker_count_)
      this->coworker_parent_.DeleteObject ();

    // Restore the <coworker_parent_>.
    this->coworker_parent_ = prev_coworker_parent;
  }
}

//
// Visit_RootFolder_i
//
void CUTS_CoWorkEr_Generator::
Visit_RootFolder_i (const PICML::RootFolder & root)
{
  // Get all the <PICML::InterfaceDefinitions> elements.
  typedef std::vector <PICML::InterfaceDefinitions> IDefs_Set;
  IDefs_Set idefs = root.InterfaceDefinitions_children ();

  // We need to visit all the <PICML::InterfaceDefinitions> and generate
  // the <CoWorkEr> elements for all <PICML::Component> elements.
  for (IDefs_Set::iterator iter = idefs.begin ();
       iter != idefs.end ();
       iter ++)
  {
    // We need to ingore the "CoWorkEr_InterfaceDefinitions" folder and
    // any folder that begins w/ "CUTS_".
    std::string name = iter->name ();

    if (name != COWORKER_INTERFACE_FOLDER &&
        name.find (CUTS_PREFIX) == std::string::npos)
    {
      iter->Accept (*this);
    }
  }

  // We need to visit all the attached libraries.
  typedef std::vector <PICML::RootFolder> RootFolder_Set;
  RootFolder_Set roots = root.RootFolder_children ();

  std::for_each (roots.begin (),
                 roots.end (),
                 boost::bind (&CUTS_CoWorkEr_Generator::Visit_RootFolder_i,
                              this,
                              _1));
}

//
// generate_artifacts
//
void CUTS_CoWorkEr_Generator::generate_artifacts (Artifact_Set & artifacts)
{
  // Get all the CoWorkEr artifact containers from the model. We need
  // to create one for the current <coworker_>.
  typedef std::vector <PICML::ArtifactContainer> ArtifactContainer_Set;
  ArtifactContainer_Set containers =
    this->coworker_artifacts_.ArtifactContainer_children ();

  std::string scope = this->get_scope (this->coworker_, "_");
  std::string container_name = scope + (std::string) this->coworker_.name ();

  PICML::ArtifactContainer container;

  if (create_element_if_not_exist (containers,
                                   Find_Element_By_Name <
                                   PICML::ArtifactContainer> (
                                   container_name),
                                   this->coworker_artifacts_,
                                   Udm::NULLCHILDROLE,
                                   container))
  {
    container.SetStrValue ("name", container_name);
  }

  // Create the artifacts for the <coworker_> in <container>.
  typedef std::vector <PICML::ImplementationArtifact> Artifact_Set;
  Artifact_Set artifacts_set = container.ImplementationArtifact_children ();

  PICML::ImplementationArtifact artifact;
  char * suffix[3] = {"_stub", "_svnt", "_exec"};
  char * positions[3] = {"(140,150)", "(375,75)", "(375,235)"};

  char * entrypoint[3] = {0, "_Servant", "_Impl"};
  char * entrypoint_positions[3] = {0, "(545,125)", "(545,300)"};

  artifacts.resize (3);

  for (size_t i = 0; i < 3; i ++)
  {
    std::string artifact_name = container_name + suffix[i];

    if (create_element_if_not_exist (artifacts_set,
                                     Find_Element_By_Name <
                                     PICML::ImplementationArtifact> (
                                     artifact_name),
                                     container,
                                     Udm::NULLCHILDROLE,
                                     artifact))
    {
      artifact.SetStrValue ("name", artifact_name);
    }

    // Store the artifact.
    artifact.location () = artifact_name;
    artifact.position () = positions[i];
    artifacts[i] = artifact;

    typedef std::set <PICML::ArtifactDependency> ArtifactDependency_Set;
    ArtifactDependency_Set depends = artifact.srcArtifactDependency ();

    for (size_t j = 0; j < i; j ++)
    {
      // Make sure the <_svnt> has the correct dependencies.
      ArtifactDependency_Set::iterator iter;

      for (iter = depends.begin (); iter != depends.end (); iter ++)
      {
        // Get the artifact we are reference and determine if this
        // artifact is the same as the one we have already created.
        // The artifacts denend on the ones below it.
        artifact = iter->dstArtifactDependency_end ();
        if (artifact == artifacts[j])
          break;

        // This dependency apparently is invalid, so delete it.
        iter->DeleteObject ();
      }

      if (iter == depends.end ())
      {
        // Create the dependency _svnt -> _stub.
        PICML::ArtifactDependency dependency =
          PICML::ArtifactDependency::Create (container);

        dependency.srcArtifactDependency_end () = artifacts[i];
        dependency.dstArtifactDependency_end () = artifacts[j];
      }
    }

    // We need to create the entry point for the artifact. This is only
    // necessry if we are working w/ a _svnt or _stub (i.e., i > 0).
    if (entrypoint[i] != 0)
    {
      // Create the entryPoint property.
      PICML::Property property = PICML::Property::Create (container);
      property.SetStrValue ("name", "entryPoint");
      property.position () = entrypoint_positions[i];

      // Set the entryPoint for the property.
      std::ostringstream value;
      value
        << "create_"
        << scope << (std::string) this->coworker_factory_.name ()
        << entrypoint[i];

      property.DataValue () = value.str ();

      // Create its datatype, which is a String. We are going to us
      // the String type provided by CUTS.
      PICML::DataType datatype = PICML::DataType::Create (property);
      PICML::String strtype = CUTS_Project::instance ()->get_string_type ();

      datatype.ref () = strtype;
      datatype.SetStrValue ("name", strtype.type ().name ());

      // Connect the config property to the correct artifact.
      PICML::ArtifactExecParameter param =
        PICML::ArtifactExecParameter::Create (container);

      param.srcArtifactExecParameter_end () = artifacts[i];
      param.dstArtifactExecParameter_end () = property;
    }
  }
}

//
// get_scope
//
std::string CUTS_CoWorkEr_Generator::
get_scope (const Udm::Object & object, const std::string & separator)
{
  std::stack <Udm::Object> levels;
  Udm::Object parent = object.GetParent ();

  // Push all the objects onto the stack until we reach the
  // file element.
  while (parent.type () != PICML::File::meta)
  {
    levels.push (parent);
    parent = parent.GetParent ();
  }

  std::string scope;
  std::string name;

  // Pop all the objects from the stack and write their name
  // to <scope> in reverse order.

  while (!levels.empty ())
  {
    levels.top ().GetStrValue ("name", name);
    scope += name + separator;
    levels.pop ();
  }

  return scope;
}

//
// generate_monolithic_implementation
//
void CUTS_CoWorkEr_Generator::
generate_monolithic_implementation (
  const Artifact_Set & artifacts,
  PICML::MonolithicImplementation & monolithic)
{
  // Generate the scope for this monolithic. The scope is going to
  // reflect its location on disk.
  std::string scope = this->get_scope (this->coworker_, "/");
  std::string container_name = scope + (std::string) this->coworker_.name ();

  // Get all the containers that have been defined.
  typedef std::vector <PICML::ComponentImplementationContainer> Container_Set;

  Container_Set containers =
    this->coworker_implementations_.
    ComponentImplementationContainer_children ();

  PICML::ComponentImplementationContainer container;

  if (create_element_if_not_exist (containers,
                                   Find_Element_By_Name <
                                   PICML::ComponentImplementationContainer> (
                                   container_name),
                                   this->coworker_implementations_,
                                   Udm::NULLCHILDROLE,
                                   container))
  {
    container.SetStrValue ("name", container_name);
  }

  // First, let's create the MonolithicImplementation. This will be the
  // target for all the elements we create in this container.
  std::string monolithic_name =
    (std::string)this->coworker_.name () + "_Impl";

  monolithic =
    PICML::MonolithicImplementation::Create (container);
  monolithic.SetStrValue ("name", monolithic_name);
  monolithic.position () = "(184,198)";

  typedef std::vector <PICML::ImplementationArtifactReference> ArtifactRef_Set;
  ArtifactRef_Set artifact_refs =
    container.ImplementationArtifactReference_children ();

  std::string artifact_name;
  PICML::ImplementationArtifactReference artifact_ref;

  size_t artifact_position_x = 475;
  size_t artifact_position_y = 100;
  size_t artifact_position_delta_y = 100;

  // Create reference to this implementations artifacts.
  for (Artifact_Set::const_iterator iter = artifacts.begin ();
       iter != artifacts.end ();
       iter ++)
  {
    iter->GetStrValue ("name", artifact_name);

    if (create_element_if_not_exist (artifact_refs,
                                     Find_Element_By_Name <
                                     PICML::ImplementationArtifactReference> (
                                     artifact_name),
                                     container,
                                     Udm::NULLCHILDROLE,
                                     artifact_ref))
    {
      artifact_ref.SetStrValue ("name", artifact_name);
    }

    // Make sure we are point to the correct reference.
    PICML::ImplementationArtifact artifact = artifact_ref.ref ();

    if (artifact != *iter)
      artifact_ref.ref () = *iter;

    // Position the artifact correctly on the palette.
    std::ostringstream position;
    position
      << "(" << artifact_position_x << ","
      << artifact_position_y << ")";

    artifact_ref.position () = position.str ();
    artifact_position_y += artifact_position_delta_y;

    // Create the <primaryArtifact> connection between the <monolithic>
    // and the <artifact_ref>.
    PICML::MonolithprimaryArtifact primaryArtifact =
      PICML::MonolithprimaryArtifact::Create (container);

    primaryArtifact.srcMonolithprimaryArtifact_end () = monolithic;
    primaryArtifact.dstMonolithprimaryArtifact_end () = artifact_ref;
  }

  // Create reference to the component that we are realizing. We need
  // to ensure that whatever reference exist in this container points
  // the correct component (CoWorkEr).
  PICML::ComponentRef component_ref = container.ComponentRef_child ();

  if (component_ref == Udm::null)
    component_ref = PICML::ComponentRef::Create (container);

  component_ref.SetStrValue ("name", this->coworker_.name ());
  PICML::Component component = component_ref.ref ();

  if (component != this->coworker_)
    component_ref.ref () = this->coworker_;

  component_ref.position () = "(125,20)";

  // Create the <Implements> connection between the <monolithic>
  // an the <component_ref>.
  PICML::Implements implements = PICML::Implements::Create (container);
  implements.srcImplements_end () = monolithic;
  implements.dstImplements_end () = component_ref;
}

//
// generate_monolithic_package
//
void CUTS_CoWorkEr_Generator::
generate_monolithic_package (
  const PICML::MonolithicImplementation & monolithic)
{
  std::string scope = this->get_scope (this->coworker_, "_");
  std::string container_name = scope + (std::string) this->coworker_.name ();

  // Get all the package containers.
  typedef std::vector <PICML::PackageContainer> Container_Set;
  Container_Set packages =
    this->coworker_packages_.PackageContainer_children ();

  PICML::PackageContainer container;

  if (create_element_if_not_exist (packages,
                                   Find_Element_By_Name <
                                   PICML::PackageContainer> (container_name),
                                   this->coworker_packages_,
                                   Udm::NULLCHILDROLE,
                                   container))
  {
    container.SetStrValue ("name", container_name);
  }

  // Create the <package> for the implementation if it does not exist.
  // Also, make sure the name of the <package> is the same as the
  // container.
  PICML::ComponentPackage package = container.ComponentPackage_child ();
  if (package == Udm::null)
    package = PICML::ComponentPackage::Create (container);

  package.SetStrValue ("name", container_name);
  package.position () = "(200,100)";

  // Verfiy the implemenation points to <monolithic>. If there isn't
  // an implementation associated with this package, then we need to
  // create one.
  typedef std::set <PICML::Implementation> Implementation_Set;
  Implementation_Set implementation = package.dstImplementation ();
  PICML::ComponentImplementationReference implref;

  if (!implementation.empty ())
  {
    //// Get the reference object.
    //implref = implementation.dstImplementation_end ();

    //try
    //{
    //  // Verify the reference is pointing to the correct
    //  // monolithic implementation.
    //  PICML::MonolithicImplementation mono =
    //    PICML::MonolithicImplementation::Cast (implref.ref ());

    //  if (mono != monolithic)
    //    implref.ref () = monolithic;
    //}
    //catch (...)
    //{
    //  implref.ref () = monolithic;
    //}
  }
  else
  {
    // Create the component implementation reference object.
    implref = PICML::ComponentImplementationReference::Create (container);
    implref.SetStrValue ("name", monolithic.name ());
    implref.ref () = monolithic;

    // We need to create a <implementation> connection.
    PICML::Implementation impl = PICML::Implementation::Create (container);
    impl.srcImplementation_end () = package;
    impl.dstImplementation_end () = implref;
  }

  // Position the monolithic implementation reference.
  implref.position () = "(138,250)";

  // Make sure the package has a package interface.
  PICML::PackageInterface pkg_interface = package.dstPackageInterface ();
  PICML::ComponentRef component_ref;

  if (pkg_interface != Udm::null)
  {
    // Since we have a package interface connection, we need to
    // verify it the component reference refers to <coworker_>.
    component_ref = pkg_interface.dstPackageInterface_end ();
    PICML::Component component = component_ref.ref ();

    if (component != this->coworker_)
      component_ref.ref () = this->coworker_;
  }
  else
  {
    // Create a component reference for the package interface.
    component_ref = PICML::ComponentRef::Create (container);
    component_ref.SetStrValue ("name", this->coworker_.name ());
    component_ref.ref () = this->coworker_;

    // Create the package interface connection.
    pkg_interface = PICML::PackageInterface::Create (container);
    pkg_interface.srcPackageInterface_end () = package;
    pkg_interface.dstPackageInterface_end () = component_ref;
  }

  // Position the component reference.
  component_ref.position () = "(400,175)";
}
