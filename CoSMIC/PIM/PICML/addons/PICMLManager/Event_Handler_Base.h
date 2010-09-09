// -*- C++ -*-

//=============================================================================
/**
 *  @file       Event_Handler_Base.h
 *
 *  $Id:        Event_Handler_Base.h 2453 2010-08-24 12:00:00Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_EVENT_HANDLER_BASE_H_
#define _PICML_MI_EVENT_HANDLER_BASE_H_

#include <set>
#include "game/be/Event_Handler_Impl.h"
#include "game/FCO.h"
#include "game/Connection.h"
#include "game/Project.h"

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

#include "Event_Handler_Config.h"

// Type definition
typedef std::vector <GAME::Reference> Reference_Set;

namespace PICML
{
namespace MI
{

/**
 * @class Event_Handler_Base
 *
 * Contains common objects and implementations
 */
class Event_Handler_Base :
  public GAME::Event_Handler_Impl
{
public:
  /// Default constructor.
  Event_Handler_Base (objectevent_enum e);

  /// Destructor.
  virtual ~Event_Handler_Base (void);

  void set_property_type (GAME::Model & prop, const GAME::FCO & type);

  /// Latest member of the collocation group.
  PICML::MI::Event_Handler_Config * config_;
};

}
}

#endif