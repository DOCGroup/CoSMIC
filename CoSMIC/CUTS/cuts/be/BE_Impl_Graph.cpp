// $Id$

#include "BE_Impl_Graph.h"
#include "BE_Preprocessor.h"
#include "CoWorkEr_Cache.h"

// UDM headers
#include "Uml.h"

// BOOST headers
#include "boost/bind.hpp"

//
// CUTS_BE_Impl_Graph
//
CUTS_BE_Impl_Graph::CUTS_BE_Impl_Graph (void)
: current_impl_ (0)
{

}

//
// ~CUTS_BE_Impl_Graph
//
CUTS_BE_Impl_Graph::~CUTS_BE_Impl_Graph (void)
{

}

//
// Visit_ComponentImplementationContainer
//
void CUTS_BE_Impl_Graph::
Visit_ComponentImplementationContainer (
const PICML::ComponentImplementationContainer & container)
{
  // Get the <current_impl_> for this container.
  this->find (container.name (), this->current_impl_);

  // Get all the monolithic implemenations in this <container>.
  typedef std::vector <PICML::MonolithicImplementation> MonoImpl_Set;
  MonoImpl_Set monoimpls = container.MonolithicImplementation_kind_children ();

  // Visit all the monolithic implementations.
  std::for_each (monoimpls.begin (),
                 monoimpls.end (),
                 boost::bind (&MonoImpl_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_MonolithicImplementation
//
void CUTS_BE_Impl_Graph::
Visit_MonolithicImplementation (
const PICML::MonolithicImplementation & monoimpl)
{
  PICML::Implements implements = monoimpl.dstImplements ();

  if (implements != Udm::null)
  {
    PICML::ComponentRef ref = implements.dstImplements_end ();
    PICML::Component component = ref.ref ();

    if (component != Udm::null)
      component.Accept (*this);
  }

  typedef std::set <PICML::MonolithprimaryArtifact> PrimaryArtifact_Set;
  PrimaryArtifact_Set primaries = monoimpl.dstMonolithprimaryArtifact ();

  std::for_each (primaries.begin (),
                 primaries.end (),
                 boost::bind (&PrimaryArtifact_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_Component
//
void CUTS_BE_Impl_Graph::
Visit_Component (const PICML::Component & component)
{
  // Maybe this component we are generating is a proxy-enabled
  // component. If this is the case, we need to save this info
  // the generators.
  this->current_impl_->is_proxy_ =
   CUTS_CoWorkEr_Cache::instance ()->is_coworker (component);

  // Let's locate the parent file of this <component>.
  PICML::MgaObject parent = component.parent ();

  while (parent.type () != PICML::File::meta)
    parent = PICML::MgaObject::Cast (parent.parent ());

  // We are going to preprocess this file as well.
  CUTS_BE_PREPROCESSOR ()->preprocess (PICML::File::Cast (parent));

  // Ok, let's locate the previous preprocess node so that we can
  // add it to the reference set for the current implementation node.

  const CUTS_BE_IDL_Node * idl_node = 0;

  if (CUTS_BE_PREPROCESSOR ()->stubs ().find (parent.name (), idl_node))
    this->current_impl_->references_.insert (idl_node);

  // Now, let's continue with the preprocessing by visiting all
  // the workers that are defined in this component. This is
  // necessary since to properly generate the implementation
  // code and project files.
  typedef std::vector <PICML::WorkerType> WorkerType_Set;
  WorkerType_Set workers = component.WorkerType_kind_children ();

  std::for_each (workers.begin (),
                 workers.end (),
                 boost::bind (&WorkerType_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));
}

//
// Visit_WorkerType
//
void CUTS_BE_Impl_Graph::
Visit_WorkerType (const PICML::WorkerType & worker_type)
{
  PICML::Worker worker = worker_type.ref ();

  if (worker != Udm::null)
    worker.Accept (*this);
}

//
// Visit_Worker
//
void CUTS_BE_Impl_Graph::
Visit_Worker (const PICML::Worker & worker)
{
  // We need to locate the parent file for this worker. This may
  // mean iterating over muliple packages before finding the file.
  PICML::MgaObject parent = worker.parent ();

  while (parent.type () != PICML::WorkerFile::meta)
    parent = PICML::MgaObject::Cast (parent.parent ());

  PICML::WorkerFile::Cast (parent).Accept (*this);
}

//
// Visit_WorkerFile
//
void CUTS_BE_Impl_Graph::
Visit_WorkerFile (const PICML::WorkerFile & file)
{
  // Add the name of the worker to the collection of
  // include files for this node.
  this->current_impl_->include_.insert (file.name ());

  // Add the location of this worker, if the string is not
  // empty, to the collection of include directories.
  std::string location = file.Location ();

  if (!location.empty ())
    this->current_impl_->include_paths_.insert (location);

  // Visit the library hosting the file.
  PICML::WorkerLibrary library = file.WorkerLibrary_parent ();
  library.Accept (*this);
}

//
// Visit_WorkerFile
//
void CUTS_BE_Impl_Graph::
Visit_WorkerLibrary (const PICML::WorkerLibrary & library)
{
  // Add the name of the library to the collection of
  // import libraries for this node.
  this->current_impl_->lib_.insert (library.name ());

  // Add the location of this library, if the string is not
  // empty, to the collection of import library directories.
  std::string location = library.Location ();

  if (!location.empty ())
    this->current_impl_->lib_paths_.insert (location);
}

//
// Visit_MonolithprimaryArtifact
//
void CUTS_BE_Impl_Graph::
Visit_MonolithprimaryArtifact (const PICML::MonolithprimaryArtifact & primary)
{
  PICML::ImplementationArtifactReference ref =
    primary.dstMonolithprimaryArtifact_end ();

  PICML::ImplementationArtifact artifact = ref.ref ();

  if (artifact != Udm::null)
    this->current_impl_->artifacts_.insert (artifact);
}

