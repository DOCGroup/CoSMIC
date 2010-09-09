// $Id$

#include "StdAfx.h"
#include "Event_Handler_Config.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"


namespace PICML
{
namespace MI
{

//
// Event_Handler_Config
//
Event_Handler_Config::Event_Handler_Config ()
: impl_folder_ ("ComponentImplementations"),
  artifact_folder_ ("ImplementationArtifacts")
{

}

//
// ~Event_Handler_Config
//
Event_Handler_Config::~Event_Handler_Config (void)
{

}

//
// set_artifact_folder
//
void Event_Handler_Config::set_artifact_folder (const std::string & name)
{
  this->artifact_folder_ = name;
}

//
// set_implementation_folder
//
void Event_Handler_Config::set_implementation_folder (const std::string & name)
{
  this->impl_folder_ = name;
}

//
// reset_configuration
//
void Event_Handler_Config::reset_configuration (void)
{
  this->artifact_folder_ = "ImplementationArtifacts";
  this->impl_folder_ = "ComponentImplementations";
}

}
}