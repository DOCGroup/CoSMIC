// -*- C++ -*-

//=============================================================================
/**
 *  @file       UUID_Event_Handler.h
 *
 *  $Id:        UUID_Event_Handler.h 2453 2010-08-24 12:00:00Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_UUID_EVENT_HANDLER_H_
#define _PICML_MI_UUID_EVENT_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"
#include "game/mga/Model.h"

#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"

namespace PICML
{
namespace MI
{

/**
 * @class UUID_Event_Handler
 *
 * UUID handlers.
 */
class UUID_Event_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  /// Collection of UUIDs for this project.
  typedef ACE_Hash_Map_Manager <std::string,
                                GAME::Mga::FCO,
                                ACE_Null_Mutex> UUID_MANAGER;

  /// Default constructor.
  UUID_Event_Handler (UUID_MANAGER & uuids);

  /// Destructor.
  virtual ~UUID_Event_Handler (void);

  virtual int initialize (GAME::Mga::Project project);

  virtual int handle_project_open (void);

  virtual int handle_project_close (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);

  virtual int handle_object_destroyed (GAME::Mga::Object_in obj);

  virtual int handle_object_attribute (GAME::Mga::Object_in obj);

private:
  bool is_duplicate_uuid (GAME::Mga::FCO_in fco, const std::string & uuid);

  UUID_MANAGER & uuids_;

  GAME::Mga::Project project_;
};

}
}

#endif