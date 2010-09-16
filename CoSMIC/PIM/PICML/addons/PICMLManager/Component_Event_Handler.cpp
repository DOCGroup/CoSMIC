// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "Component_Event_Handler.h"

#include "Default_Implementation_Generator.h"
#include "Default_Artifact_Generator.h"
#include "Dialogs.h"
#include "Implementation_Configuration.h"
#include "Validation.h"

#include "game/utils/modelgen.h"
#include "game/utils/Point.h"

#include "Utils/Utils.h"

#include "boost/bind.hpp"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include <functional>

namespace PICML
{
namespace MI
{

//
// Component_Event_Handler
//
Component_Event_Handler::Component_Event_Handler (void)
: GAME::Event_Handler_Impl (OBJEVENT_CREATED),
  config_ (ACE_Singleton <PICML::MI::Event_Handler_Config,
                          ACE_Null_Mutex>::instance ())
{

}

//
// ~Component_Event_Handler
//
Component_Event_Handler::~Component_Event_Handler (void)
{

}

//
// handle_object_created
//
int Component_Event_Handler::
handle_object_created (GAME::Object obj)
{
  //if (this->is_importing_)
  //  return 0;

  //// The parent determines if we should move forward. We should
  //// only generate default artifacts for components that appear
  //// in the file.
  //GAME::FCO fco = GAME::FCO::_narrow (obj);
  //GAME::Model parent = fco.parent_model ();
  //const std::string type = parent.meta ().name ();

  //if (!(type == "File" || type == "Package") || is_in_template_module (fco))
  //  return 0;

  //// If the name is "Component", then this means that the
  //// object was manaully added to the model and the default
  //// name was assigned to the object.
  //Implementation_Configuration config;
  //config.type_name_ = obj.name ().c_str ();

  //if (obj.name () == "Component")
  //{
  //  // Allow the end-user to rename the component. This will
  //  // also set the suffixes for the artifacts.
  //  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
  //  Default_Implementation_Dialog new_component (config, ::AfxGetMainWnd ());

  //  if (new_component.DoModal () == IDCANCEL)
  //    return 0;

  //  // Set the name of the component.
  //  obj.name (config.type_name_);
  //}

  //// Make sure the target folder's exist.
  //GAME::Folder root_folder = obj.project ().root_folder ();
  //GAME::Folder artifact_folder, impl_folder;

  //if (GAME::create_if_not (root_folder, "ImplementationArtifacts", artifact_folder,
  //    GAME::contains (boost::bind (std::equal_to <std::string> (),
  //                    config_->artifact_folder_,
  //                    boost::bind (&GAME::Model::name, _1)))))
  //{
  //  artifact_folder.name (config_->artifact_folder_);
  //}

  //if (GAME::create_if_not (root_folder, "ComponentImplementations", impl_folder,
  //    GAME::contains (boost::bind (std::equal_to <std::string> (),
  //                    config_->impl_folder_,
  //                    boost::bind (&GAME::Model::name, _1)))))
  //{
  //  impl_folder.name (config_->impl_folder_);
  //}

  //// Generate the component's artifacts.
  //GAME::Model component = GAME::Model::_narrow (obj);

  //// Generate the component's implementation.
  //Default_Implementation_Generator::meta_info_t meta_info;
  //meta_info.container_type_ = "ComponentImplementationContainer";
  //meta_info.impl_type_ = "MonolithicImplementation";
  //meta_info.implements_type_ = "Implements";
  //meta_info.type_ref_ = "ComponentRef";

  //Default_Implementation_Generator impl_gen (impl_folder,
  //                                           artifact_folder,
  //                                           meta_info);

  //impl_gen.generate (config, component);

  return 0;
}

}
}