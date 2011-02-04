// -*- C++ -*-

//=============================================================================
/**
 *  @file       CollocationGroup_Event_Handler.h
 *
 *  $Id: CollocationGroup_Event_Handler.h 2482 2010-09-08 04:26:38Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_COLLOCATION_GROUP_EVENT_HANDLER_H_
#define _PICML_MI_COLLOCATION_GROUP_EVENT_HANDLER_H_

#include "Event_Handler_Base.h"

namespace PICML
{
namespace MI
{

/**
 * @class CollocationGroup_Event_Handler
 *
 * This class creates a CollocationGroup and the related references.
 */
class CollocationGroup_Event_Handler :
  public PICML::MI::Event_Handler_Base
{
public:
  /// Default constructor.
  CollocationGroup_Event_Handler (void);

  /// Destructor.
  virtual ~CollocationGroup_Event_Handler (void);

  virtual int handle_object_relation (GAME::Mga::Object_in obj);
};

}
}

#endif