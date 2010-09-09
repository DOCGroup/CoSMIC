// -*- C++ -*-
// $Id: ComponentInstance_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "Component_Event_Handler.h"

#include "game/utils/modelgen.h"
#include "game/utils/Point.h"

#include "Dialogs.h"
#include "DefaultImplementationGenerator.h"
#include "DefaultArtifactGenerator.h"
#include "NewComponentConfig.h"

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
  if (!this->is_importing_)
  {
    // The parent determines if we should move forward. We should
    // only generate default artifacts for components that appear
    // in the file.
    GAME::Object parent = obj.parent ();
    std::string type = parent.meta ().name ();

    if ((type == "File" || type == "Package"))
    {
      // If the name is "Component", then this means that the
      // object was manaully added to the model and the default
      // name was assigned to the object.
      NewComponentConfig config;
      config.component_name_ = obj.name ().c_str ();

      if (obj.name () == "Component")
      {
        // Allow the end-user to rename the component. This will
        // also set the suffixes for the artifacts.
        AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
        NewComponentDialog new_component (config, ::AfxGetMainWnd ());

        if (new_component.DoModal () == IDCANCEL)
          return 0;

        // Set the name of the component.
        obj.name (config.component_name_.c_str ());
      }

      // Make sure the target folder's exist.
      GAME::Folder root_folder = obj.project ().root_folder ();
      GAME::Folder artifact_folder, impl_folder;

      if (GAME::create_if_not (root_folder, "ImplementationArtifacts", artifact_folder,
          GAME::contains (boost::bind (std::equal_to <std::string> (),
                          config_->artifact_folder_,
                          boost::bind (&GAME::Model::name, _1)))))
      {
        artifact_folder.name (config_->artifact_folder_);
      }

      if (GAME::create_if_not (root_folder, "ComponentImplementations", impl_folder,
          GAME::contains (boost::bind (std::equal_to <std::string> (),
                          config_->impl_folder_,
                          boost::bind (&GAME::Model::name, _1)))))
      {
        impl_folder.name (config_->impl_folder_);
      }

      // Generate the component's artifacts.
      GAME::Model component = GAME::Model::_narrow (obj);
      DefaultArtifactGenerator artifact_gen (artifact_folder);

      if (artifact_gen.generate (config, component))
      {
        // Generate the component's implementation.
        DefaultImplementationGenerator impl_gen (artifact_gen, impl_folder);
        impl_gen.generate (component);
      }
    }
  }

  return 0;
}

}
}