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
// reset_configuration
//
void Event_Handler_Config::reset (void)
{
  this->artifact_folder_ = "ImplementationArtifacts";
  this->impl_folder_ = "ComponentImplementations";
}

}
}