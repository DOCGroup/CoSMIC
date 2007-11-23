// $Id$

#include "CoWorkEr_Generator.h"
#include "CUTS_Project.h"
#include "modelgen.h"

#include "Uml.h"
#include "boost/bind.hpp"
#include <stack>
#include <sstream>
#include <functional>

// Static decl.
static const char * COWORKER_SUFFIX = "_CoWorkEr";

// Static decl.
static const char * COWORKER_RECEPTACLE = "cuts_testing_service";

// Static decl.
static const char * COWORKER_PROXY_IMPL = "cuts_proxy_impl";

// Static decl.
static const char * CUTS_PREFIX = "CUTS_";

// Static decl.
static const char * CUTS_FILE = "cuts/";

// Static decl.
static const std::string
COWORKER_INTERFACE_FOLDER ("CoWorkEr_InterfaceDefinitions");

static const std::string
COWORKER_ARTIFACT_FOLDER ("CoWorkEr_ImplementationArtifacts");

static const std::string
COWORKER_IMPLEMENTATION_FOLDER ("CoWorkEr_ComponentImplementations");

static const std::string
COWORKER_PACKAGE_FOLDER ("CoWorkEr_ComponentPackages");

//=============================================================================
/**
 * @class has_entrypoint
 *
 * Functor that searches a collection of executor parameters to search
 * for a particular entrypoint.
 */
//=============================================================================

class has_entrypoint
{
public:
  /// Type definition for a collection of artifact executor params.
  typedef std::set <
    PICML::ArtifactExecParameter>
    ArtifactExecParameter_Set;

  /**
   * Initializing constructor.
   *
   * @param[in]       entrypoint        Entrypoint in question.
   */
  has_entrypoint (const std::string & entrypoint)
    : entrypoint_ (entrypoint)
  {

  }

  /**
   * Functor that allows the struct to be used with Udm::contains.
   *
   * @param[in]       params            Source parameters.
   * @param[out]      property          Found property.
   */
  bool operator () (const ArtifactExecParameter_Set & params,
                    PICML::Property & property)
  {
    this->property_ = &property;

    ArtifactExecParameter_Set::const_iterator iter =
      std::find_if (params.begin (), params.end (),
                    boost::bind (&has_entrypoint::is_valid, this, _1));

    return iter != params.end ();
  }

private:
  /**
   *
   */
  bool is_valid (const PICML::ArtifactExecParameter & param)
  {
    // Get the property at the end of this connection.
    PICML::Property property = param.dstArtifactExecParameter_end ();

    if (std::string (property.name ()) == std::string ("entryPoint") &&
        std::string (property.DataValue ()) == this->entrypoint_)
    {
      // Save the property.
      if (this->property_ != 0)
        *this->property_ = property;

      return true;
    }

    return false;
  }

private:
  /// Entrypoint in question.
  const std::string & entrypoint_;

  /// Storage location of the found property.
  PICML::Property * property_;
};

//=============================================================================
/**
 * @class has_implementation
 *
 * Functor that searchs through a collection of implementation connections
 * to determine if one is connected to a specific monolithic implementation.
 */
//=============================================================================

class has_implementation
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     monolithic      Monolithic implementation in question.
   */
  has_implementation (const PICML::MonolithicImplementation & monolithic)
    : monolithic_ (monolithic)
  {

  }


  /**
   * Functor for usage as a predicate in the modelgen library.
   *
   * @param[in]     impls           Collection of implementation connections.
   * @param[out]    impl            Holds the located implemenation.
   */
  bool operator () (const std::set <PICML::Implementation> & impls,
                    PICML::Implementation & impl)
  {
    std::set <PICML::Implementation>::const_iterator iter =
      std::find_if (impls.begin (),
                    impls.end (),
                    boost::bind (&has_implementation::is_valid,
                                 this,
                                 _1));

    if (iter != impls.end ())
    {
      impl = *iter;
      return true;
    }
    else
      return false;
  }

private:
  /**
   * Helper method that tests the validity of a implementation connection.
   * The connection is valid if it's connected to a element that references
   * the target implemenation.
   *
   * @param[in]         impl          Implementation in question.
   */
  bool is_valid (const PICML::Implementation & impl)
  {
    PICML::ComponentImplementationReference ref = impl.dstImplementation_end ();
    return PICML::MonolithicImplementation::Cast (ref.ref ()) == this->monolithic_;
  }

  /// The target implementation of the search.
  const PICML::MonolithicImplementation & monolithic_;
};

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
  // Find or create the CoWorkEr_InterfaceDefinitions folder.
  if (Udm::create_if_not (root, this->coworker_idefs_,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     COWORKER_INTERFACE_FOLDER,
                     boost::bind (&PICML::InterfaceDefinitions::name, _1)))))
  {
    this->coworker_idefs_.
      SetStrValue ("name", COWORKER_INTERFACE_FOLDER);
  }

  // Find or create the CoWorkEr_ImplementationArtifacts folder.
  if (Udm::create_if_not (root, this->coworker_artifacts_,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     COWORKER_ARTIFACT_FOLDER,
                     boost::bind (&PICML::ImplementationArtifacts::name, _1)))))
  {
    this->coworker_artifacts_.
      SetStrValue ("name", COWORKER_ARTIFACT_FOLDER);
  }

  // Find or create the CoWorkEr_ComponentImplementations folder.
  if (Udm::create_if_not (root, this->coworker_implementations_,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     COWORKER_IMPLEMENTATION_FOLDER,
                     boost::bind (&PICML::ComponentImplementations::name, _1)))))
  {
    this->coworker_implementations_.
      SetStrValue ("name", COWORKER_IMPLEMENTATION_FOLDER);
  }

  // Find or create the CoWorkEr_ComponentPackages folder.
  if (Udm::create_if_not (root, this->coworker_packages_,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     COWORKER_PACKAGE_FOLDER,
                     boost::bind (&PICML::ComponentPackages::name, _1)))))
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
  typedef std::vector <PICML::File> File_Set;

  // We need to make a duplicate copy of all the files in the project. The
  // duplicate files will contain all the CoWorkEr components.
  File_Set files = idefs.File_children ();
  File_Set coworker_files = this->coworker_idefs_.File_children ();

  std::for_each (files.begin (),
                 files.end (),
                 boost::bind (&CUTS_CoWorkEr_Generator::find_interface_definitions_i,
                              boost::ref (*this),
                              coworker_files,
                              _1));
}

//
// find_interface_definitions_i
//
void CUTS_CoWorkEr_Generator::
find_interface_definitions_i (const std::vector <PICML::File> & fileset,
                              const PICML::File & srcfile)
{
  // We ingore any string's (i.e., filenames) that begin with 'cuts/'. We
  // assume that all files that begin w/ cuts/ are auto generated. We
  // therefore do not want to duplicate elements we created.
  std::string name = srcfile.name ();
  if (name.find (CUTS_FILE) != std::string::npos)
    return;

  // Prepare the name of the file.
  PICML::File coworker_file;
  name += COWORKER_SUFFIX;

  // Find or create the CoWorkEr IDL file.
  if (Udm::create_if_not (this->coworker_idefs_, fileset, coworker_file,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     name,
                     boost::bind (&PICML::File::name, _1)))))
  {
    coworker_file.SetStrValue ("name", name);
  }

  // Reset the number of <coworker_count_> before we start parsing this
  // file. This will determine if this IDL files is necessary.
  this->coworker_parent_ = coworker_file;
  this->coworker_count_  = 0;

  const_cast <PICML::File &> (srcfile).Accept (*this);

  // Delete the parent if there are not <coworkers_>.
  if (this->coworker_count_ == 0)
    this->coworker_parent_.DeleteObject ();
}

//
// Visit_File
//
void CUTS_CoWorkEr_Generator::
Visit_File (const PICML::File & file)
{
  // Visit the contents of this file.
  this->visit_file_and_package (file);

  if (this->coworker_count_ > 0)
  {
    // Let's create an explicit file reference to the <cuts/CUTS> file. We
    // need to make sure one does not already exist in the <coworker_parent_>
    // model which is really a <PICML::File> element.

    PICML::FileRef fileref;

    if (Udm::create_if_not (this->coworker_parent_, fileref,
        Udm::contains (boost::bind (std::equal_to <PICML::File> (),
                       CUTS_BE_PROJECT ()->get_cuts_file (),
                       boost::bind (&PICML::FileRef::ref, _1)))))
    {
      fileref.ref () = CUTS_BE_PROJECT ()->get_cuts_file ();
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

  if (create_if_not (component, testing_service,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     COWORKER_RECEPTACLE,
                     boost::bind (&PICML::RequiredRequestPort::name, _1)))))
  {
    testing_service.SetStrValue ("name", COWORKER_RECEPTACLE);
  }

  // Now that we have a testing service receptacle, we need to
  // verify that is is indeed connected to a testing service object.
  PICML::Object testsvc = PICML::Object::Cast (testing_service.ref ());

  if (testsvc != CUTS_BE_PROJECT ()->get_testing_service ())
    testing_service.ref () = CUTS_BE_PROJECT ()->get_testing_service ();

  // 2. We need to locate the <cuts_proxy_impl> attribute. This attribute
  //    the proxy to load the correct implementation.
  typedef std::vector <PICML::Attribute> Attribute_Set;
  Attribute_Set attributes = component.Attribute_kind_children ();

  PICML::Attribute proxy_impl;

  if (create_if_not (component, proxy_impl,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     COWORKER_PROXY_IMPL,
                     boost::bind (&PICML::Attribute::name, _1)))))
  {
    proxy_impl.SetStrValue ("name", COWORKER_PROXY_IMPL);
  }

  // We now need to verify that the attribute is a string type.
  PICML::AttributeMember member = proxy_impl.AttributeMember_child ();

  if (member == Udm::null)
    member = PICML::AttributeMember::Create (proxy_impl);

  PICML::MemberType mtype = member.ref ();

  if (mtype != CUTS_BE_PROJECT ()->get_string_type ())
    member.ref () = CUTS_BE_PROJECT ()->get_string_type ();

  // 2.1 We need to locate the <name> attribute. This attribute
  //     is the human readable name of the component.
  PICML::Attribute coworker_name;

  if (create_if_not (component, coworker_name,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     "cuts_name",
                     boost::bind (&PICML::Attribute::name, _1)))))
  {
    coworker_name.SetStrValue ("name", "cuts_name");
  }

  member = coworker_name.AttributeMember_child ();

  if (member == Udm::null)
    member = PICML::AttributeMember::Create (coworker_name);

  mtype = member.ref ();

  if (mtype != CUTS_BE_PROJECT ()->get_string_type ())
    member.ref () = CUTS_BE_PROJECT ()->get_string_type ();

  // 3. Lastly, we need to create a home for this <coworker_>. The home
  //    must be a subtype of the real components home.
  PICML::Component basetype = PICML::Component::Cast (component.archetype ());

  typedef std::set <PICML::ManagesComponent> Manages_Set;
  Manages_Set manages = basetype.srcManagesComponent ();

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

    std::string factory_name = (std::string) factory.name () + COWORKER_SUFFIX;
    this->coworker_factory_.SetStrValue ("name", factory_name);

    // Create the <Inherits> element to for the <coworker_factory_>.
    PICML::Inherits inherits = PICML::Inherits::Create (this->coworker_factory_);
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
  else
  {
    // Right now we are making the assumption that there is only
    // only component factory allowed. Eventually, this will need
    // the change once we fix the ambiguity problem w/ determining
    // which ComponetFactory creates which MonolithicImplementation
    // when multiple ComponentFactorys are managing the same component.
    PICML::ManagesComponent manages = *coworker_manages.begin ();
    this->coworker_factory_ = manages.srcManagesComponent_end ();
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

  std::for_each (components.begin (),
                 components.end (),
                 boost::bind (&CUTS_CoWorkEr_Generator::find_component_i,
                              this,
                              coworker_components,
                              _1));

  // New that we have handle all the components at this level, we can
  // handle all the packages. So, get all the <PICML::Package> elements
  // in <object>.
  typedef std::vector <PICML::Package> Package_Set;

  Package_Set packages =
    Udm::ChildrenAttr <PICML::Package> (object.__impl (), Udm::NULLCHILDROLE);

  // Get the current <PICML::Package> elements in <coworker_parent_>.
  Package_Set coworker_packages =
    Udm::ChildrenAttr <PICML::Package> (
    this->coworker_parent_.__impl (), Udm::NULLCHILDROLE);

  // Let's make sure all the package elements in <packages> exists
  // in <coworker_parent_>.
  std::for_each (packages.begin (),
                 packages.end (),
                 boost::bind (&CUTS_CoWorkEr_Generator::find_package_i,
                              boost::ref (*this),
                              coworker_packages,
                              _1));
}

//
// find_component_i
//
void CUTS_CoWorkEr_Generator::
find_component_i (const std::vector <PICML::Component> & component_set,
                  const PICML::Component & src_component)
{
  // Construct the name of the coworker.
  std::string name = (std::string) src_component.name () + COWORKER_SUFFIX;

  if (Udm::create_subtype_if_not (this->coworker_parent_, component_set,
      const_cast <PICML::Component &> (src_component), this->coworker_,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     name, boost::bind (&PICML::Component::name, _1)))))
  {
    this->coworker_.SetStrValue ("name", name);
  }

  if (this->coworker_ != Udm::null)
  {
    // Update the position of the CoWorkEr.
    this->coworker_.position () = src_component.position ();
    this->coworker_count_ ++;

    // We need to add elements to make it a true coworker.
    this->coworker_.Accept (*this);

    // Generate the artifacts and implemenation for <coworker_>.
    Artifact_Set artifacts;
    PICML::MonolithicImplementation monolithic;

    this->generate_artifacts (artifacts);
    this->generate_monolithic_implementation (artifacts, monolithic);
    this->generate_monolithic_package (monolithic);
  }
}

//
// Visit_Package_i
//
void CUTS_CoWorkEr_Generator::
find_package_i (const std::vector <PICML::Package> & target_pkgset,
                const PICML::Package & srcpkg)
{
  // We need to either find the correct package, or create the
  // package if we can't find it.
  PICML::Package package;
  std::string package_name = srcpkg.name ();

  if (Udm::create_if_not (this->coworker_parent_, target_pkgset, package,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     package_name,
                     boost::bind (&PICML::Package::name, _1)))))
  {
    package.SetStrValue ("name", package_name);
  }

  // Update the position of the new package.
  package.position () = srcpkg.position ();

  // Save everything before we visit this package.
  size_t prev_count = this->coworker_count_;
  Udm::Object prev_parent = this->coworker_parent_;

  // Set the corrent parent then visit the package.
  this->coworker_parent_ = package;
  const_cast <PICML::Package &> (srcpkg).Accept (*this);

  // We can delete this package if we haven't recreated anything.
  if (prev_count == this->coworker_count_)
    this->coworker_parent_.DeleteObject ();

  // Restore the previous parent, but not the count.
  this->coworker_parent_ = prev_parent;
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

  if (Udm::create_if_not (this->coworker_artifacts_, containers, container,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     container_name,
                     boost::bind (&PICML::ArtifactContainer::name, _1)))))
  {
    container.SetStrValue ("name", container_name);
  }

  // Create the artifacts for the <coworker_> in <container>.
  typedef std::vector <PICML::ImplementationArtifact> Artifact_Set;
  Artifact_Set artifacts_set = container.ImplementationArtifact_children ();

  PICML::ImplementationArtifact artifact;
  char * suffix[2] = {"_svnt", "_exec"};
  char * positions[2] = {"(375,75)", "(375,235)"};

  char * entrypoint[2] = {"_Servant", "_Impl"};
  char * entrypoint_positions[2] = {"(545,125)", "(545,300)"};

  artifacts.resize (2);

  for (size_t i = 0; i < artifacts.size (); i ++)
  {
    std::string artifact_name = container_name + suffix[i];

    if (Udm::create_if_not (container, artifacts_set, artifact,
        Udm::contains (boost::bind (std::equal_to <std::string> (),
                       artifact_name,
                       boost::bind (&PICML::ImplementationArtifact::name, _1)))))
    {
      artifact.SetStrValue ("name", artifact_name);
    }

    // Update the artifact's information and store it.
    artifact.location () = artifact_name;
    artifact.position () = positions[i];
    artifacts[i] = artifact;

    typedef std::set <PICML::ArtifactDependency> ArtifactDependency_Set;

    ArtifactDependency_Set::iterator iter;
    ArtifactDependency_Set depends = artifact.dstArtifactDependency ();

    // Make sure the artifact has the correct dependencies.
    for (size_t j = 0; j < i; j ++)
    {
      for (iter = depends.begin (); iter != depends.end (); iter ++)
      {
        // Get the artifact we are referencing and determine if this
        // artifact is the same as the one we have already created.
        artifact = iter->dstArtifactDependency_end ();

        if (artifact == artifacts[j])
          break;

        // This dependency apparently is invalid, so delete it.
        iter->DeleteObject ();
      }

      if (iter == depends.end ())
      {
        // Create the dependency.
        PICML::ArtifactDependency dependency =
          PICML::ArtifactDependency::Create (container);

        dependency.srcArtifactDependency_end () = artifacts[i];
        dependency.dstArtifactDependency_end () = artifacts[j];
      }
    }

    if (entrypoint[i] != 0)
    {
      // Create the entrypoint's name.
      string entrypoint_value =
        std::string ("create_") + scope +
        std::string (this->coworker_factory_.name ()) + entrypoint[i];

      // Determine if the artifact already has the entrypoint.
      typedef std::set <PICML::ArtifactExecParameter> ExecParam_Set;
      ExecParam_Set params = artifacts[i].dstArtifactExecParameter ();

      PICML::Property property;

      if (Udm::create_if_not (container, params, property,
                              has_entrypoint (entrypoint_value)))
      {
        // Set the attributes for the entryPoint property.
        property.name () = "entryPoint";
        property.DataValue () = entrypoint_value;

        // Connect the property to the artifact.
        PICML::ArtifactExecParameter param =
          PICML::ArtifactExecParameter::Create (container);

        param.srcArtifactExecParameter_end () = artifacts[i];
        param.dstArtifactExecParameter_end () = property;
      }

      property.position () = entrypoint_positions[i];

      // Create its datatype, which is a String. We are going to us
      // the String type provided by CUTS.
      PICML::DataType datatype = property.DataType_child ();
      const PICML::String & string_type = CUTS_BE_PROJECT ()->get_string_type ();

      if (datatype == Udm::null)
      {
        datatype = PICML::DataType::Create (property);
        datatype.name () = string_type.name ();
      }

      if (PICML::String::Cast (datatype.ref ()) != string_type)
        datatype.ref () = string_type;
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
generate_monolithic_implementation (const Artifact_Set & artifacts,
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

  if (Udm::create_if_not (this->coworker_implementations_, containers, container,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     container_name,
                     boost::bind (&PICML::ComponentImplementationContainer::name,
                                  _1)))))
  {
    container.SetStrValue ("name", container_name);
  }

  // First, let's create the MonolithicImplementation. This will be the
  // target for all the elements we create in this container.
  std::string monolithic_name =
    (std::string)this->coworker_.name () + "_Impl";

  if (Udm::create_if_not (container, monolithic,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     monolithic_name,
                     boost::bind (&PICML::MonolithicImplementation::name,
                                  _1)))))
  {
    monolithic.name () = monolithic_name;
  }

  monolithic.position () = "(184,198)";

  typedef std::vector <PICML::ImplementationArtifactReference> ArtifactRef_Set;
  ArtifactRef_Set artifact_refs = container.ImplementationArtifactReference_children ();

  std::string artifact_name;
  PICML::ImplementationArtifactReference artifact_ref;

  this->artifact_position_x_ = 475;
  this->artifact_position_y_ = 100;
  this->artifact_position_delta_y_ = 100;

  // Create reference to this implementations artifacts.
  std::for_each (artifacts.begin (),
                 artifacts.end (),
                 boost::bind (&CUTS_CoWorkEr_Generator::find_artifact_i,
                              this,
                              container,
                              monolithic,
                              artifact_refs,
                              _1));

  // Create reference to the component that we are implementing. We need
  // to ensure that whatever reference exist in this container points
  // the correct component (CoWorkEr).

  PICML::ComponentRef component_ref;

  if (Udm::create_if_not (container, component_ref,
      Udm::contains (boost::bind (std::equal_to <PICML::Component> (),
                     this->coworker_,
                     boost::bind (&PICML::ComponentRef::ref, _1)))))
  {
    component_ref.ref () = this->coworker_;
  }

  component_ref.name () = this->coworker_.name ();
  component_ref.position () = "(125,20)";

  // Create the <Implements> connection between the <monolithic>
  // an the <component_ref>.
  PICML::Implements implements = container.Implements_child ();

  if (implements == Udm::null)
    implements = PICML::Implements::Create (container);

  PICML::MonolithicImplementation impl =
    PICML::MonolithicImplementation::Cast (implements.srcImplements_end ());

  if (impl != monolithic)
    implements.srcImplements_end () = monolithic;

  if (PICML::ComponentRef (implements.dstImplements_end ()) != component_ref)
    implements.dstImplements_end () = component_ref;
}

//
// find_artifact_i
//
void CUTS_CoWorkEr_Generator::
find_artifact_i (PICML::ComponentImplementationContainer & container,
                 const PICML::MonolithicImplementation & monolithic,
                 const std::vector <PICML::ImplementationArtifactReference> & refs,
                 const PICML::ImplementationArtifact & artifact)
{
  PICML::ImplementationArtifactReference artifact_ref;
  std::string artifact_name = artifact.name ();

  if (Udm::create_if_not (container, artifact_ref,
      Udm::contains (boost::bind (std::equal_to <PICML::ImplementationArtifact> (),
                     artifact,
                     boost::bind (&PICML::ImplementationArtifactReference::ref,
                                  _1)))))
  {
    // Reference the target artifact since we don't already have a
    // connection to it.
    artifact_ref.ref () = artifact;
  }

  // Regardless, we are going to make sure the names are the same.
  artifact_ref.SetStrValue ("name", artifact_name);

  // Position the artifact correctly on the palette.
  std::ostringstream position;
  position
    << "(" << this->artifact_position_x_ << ","
    << this->artifact_position_y_ << ")";

  artifact_ref.position () = position.str ();
  this->artifact_position_y_ += this->artifact_position_delta_y_;

  // Create the <MonolithprimaryArtifact> connection between the <monolithic>
  // and the <artifact_ref>.
  PICML::MonolithprimaryArtifact primaryArtifact;

  if (Udm::create_if_not (container, primaryArtifact,
      Udm::contains (boost::bind (std::logical_and <bool> (),
                       boost::bind (std::equal_to <PICML::MonolithicImplementation> (),
                         monolithic,
                         boost::bind (&PICML::MonolithprimaryArtifact::srcMonolithprimaryArtifact_end, _1)),
                       boost::bind (std::equal_to <PICML::ImplementationArtifactReference> (),
                         artifact_ref,
                         boost::bind (&PICML::MonolithprimaryArtifact::dstMonolithprimaryArtifact_end, _1))))))
  {
    primaryArtifact.srcMonolithprimaryArtifact_end () = monolithic;
    primaryArtifact.dstMonolithprimaryArtifact_end () = artifact_ref;
  }
}

//
// generate_monolithic_package
//
void CUTS_CoWorkEr_Generator::
generate_monolithic_package (const PICML::MonolithicImplementation & monolithic)
{
  std::string scope = this->get_scope (this->coworker_, "_");
  std::string container_name = scope + (std::string) this->coworker_.name ();

  // Get all the package containers.
  typedef std::vector <PICML::PackageContainer> Container_Set;
  Container_Set packages = this->coworker_packages_.PackageContainer_children ();

  PICML::PackageContainer container;

  if (Udm::create_if_not (this->coworker_packages_, packages, container,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     container_name,
                     boost::bind (&PICML::PackageContainer::name, _1)))))
  {
    container.name () = container_name;
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
  Implementation_Set implementations = package.dstImplementation ();

  PICML::Implementation implementation;
  PICML::ComponentImplementationReference implref;

  if (Udm::create_if_not (container, implementations, implementation,
      has_implementation (monolithic)))
  {
    implref = PICML::ComponentImplementationReference::Create (container);
    implref.ref () = monolithic;

    implementation.srcImplementation_end () = package;
    implementation.dstImplementation_end () = implref;
  }
  else
    implref = implementation.dstImplementation_end ();

  // Position the monolithic implementation reference.
  implref.name () = monolithic.name ();
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
