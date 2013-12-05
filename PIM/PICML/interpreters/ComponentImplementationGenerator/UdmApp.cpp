// $Id$

#include "StdAfx.h"
#pragma warning( disable : 4290 )

#include "UdmStatic.h"
#include "UmlExt.h"
#include "UdmUtil.h"

#include "UdmApp.h"
#include "UdmConfig.h"

#include "PICML/PICML.h"
#include "boost/bind.hpp"
#include <algorithm>

#include "BE_ComponentImplementationGenerator.h"
#include "Utils/UDM/modelgen.h"

#define DEFAULT_COMPONENT_IMPLENTATIONS_NAME    "ComponentImplementations"
#define DEFAULT_IMPLENTATION_ARTIFACTS_NAME     "ImplementationArtifacts"

//
// Initialize
//
int CUdmApp::Initialize (void)
{
  return 0;
}

/*
Remarks to CUdmApp::UdmMain(...):
0. The p_backend points to an already open backend, and the framework
closes it automatically. DO NOT OPEN OR CLOSE IT! To commit changes
use p_backend->CommitEditSequence(). To abort changes use
p_backend->AbortEditSequence(). To save changes to a different file
use p_backend->SaveAs() or p_backend->CloseAs().

1. Focus is the currently open model.

2. The possible values for param (from GME DecoratorLib.h
component_startmode_enum):
GME_MAIN_START    =   0,
GME_BROWSER_START    =   1,
GME_CONTEXT_START    =   2,
GME_EMBEDDED_START    =   3,
GME_MENU_START    =  16,
GME_BGCONTEXT_START  =  18,
GME_ICON_START    =  32,
METAMODEL_CHECK_SYNTAX  = 101

3. The framework catches all the exceptions and reports the error in a
message box, clean up and close the transactions aborting the changes.
You can override this behavior by catching udm_exception. Use
udm_exception::what() to form an error message.
*/

//
// CUdmApp
//
CUdmApp::CUdmApp (void)
{

}

//
// ~CUdmApp
//
CUdmApp::~CUdmApp (void)
{

}

//
// UdmMain
//
void CUdmApp::
UdmMain (Udm::DataNetwork * p_backend,
         Udm::Object focusObject,
         std::set <Udm::Object> selected,
         long param)
{
  // Allow the user to select which components we should generate. Otherwise,
  // we can just assume that the components of interest are already selected.
  if (selected.empty ())
    return;

  // Convert selected objects into Components, and remove those objects
  // that are not components.
  std::vector <PICML::Component> components;

  for (std::set <Udm::Object>::iterator iter = selected.begin (), iter_end = selected.end ();
       iter != iter_end;
       ++ iter)
  {
    if (iter->type () == PICML::Component::meta)
      components.push_back (PICML::Component::Cast (*iter));
  }


  // Get the target directory for generating component implementations. We
  // assume they are to begenerated into the following directory:
  //
  //   RootFolder/ComponentImplementations
  //
  PICML::RootFolder root_folder = PICML::RootFolder::Cast (p_backend->GetRootObject ());

  // Make sure the target implementation folder exists.
  PICML::ComponentImplementations impl_folder;

  if (Udm::create_if_not (root_folder, impl_folder,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     DEFAULT_COMPONENT_IMPLENTATIONS_NAME,
                     boost::bind (&PICML::ComponentImplementations::name, _1)))))
  {
    impl_folder.name () = DEFAULT_COMPONENT_IMPLENTATIONS_NAME;
  }

  // Make sure the target implementation artifact's folder exists.
  PICML::ImplementationArtifacts artifact_folder;

  if (Udm::create_if_not (root_folder, artifact_folder,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     DEFAULT_IMPLENTATION_ARTIFACTS_NAME,
                     boost::bind (&PICML::ImplementationArtifacts::name, _1)))))
  {
    artifact_folder.name () = DEFAULT_IMPLENTATION_ARTIFACTS_NAME;
  }

  // Generate default implementations for selected components.
  PICML_BE::ComponentImplementationGenerator generator (impl_folder, artifact_folder);

  std::for_each (components.begin (),
                 components.end (),
                 boost::bind (&PICML::Component::Accept,
                              _1,
                              generator));
}

