// -*- C++ -*-

//=============================================================================
/**
 *  @file       Event_Config.h
 *
 *  $Id:        Event_Handler_Config.h 2453 2010-08-24 12:00:00Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_EVENT_HANDLER_CONFIG_H_
#define _PICML_MI_EVENT_HANDLER_CONFIG_H_

#include "game/GAME.h"

#include <set>

namespace PICML
{
namespace MI
{

/**
* @class Event_Handler_Config
*
* 
*/
class Event_Handler_Config
{
public:
  Event_Handler_Config ();

  ~Event_Handler_Config ();

  void set_implementation_folder (const std::string & name);
  void set_artifact_folder (const std::string & name);
  void reset_configuration (void);

  std::string impl_folder_;

  std::string artifact_folder_;

  /// Latest member of the collocation group.
  GAME::FCO cg_member_;

  /// Collection of pending FCO's to validate.
  std::vector <GAME::FCO> pending_;

  /// Interface pointer to the hosting project.
  GAME::Project project_;
};

}
}

#endif