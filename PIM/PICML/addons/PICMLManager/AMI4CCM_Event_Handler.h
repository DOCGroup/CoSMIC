// -*- C++ -*-

//=============================================================================
/**
 *  @file       AMI4CCM_Event_Handler.h
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_AMI4CCM_EVENT_HANDLER_H_
#define _PICML_MI_AMI4CCM_EVENT_HANDLER_H_

#include "game/mga/component/Object_Event_Handler.h"

namespace PICML
{
namespace MI
{
/**
 * @class AMI4CCM_Event_Handler
 *
 * Implemenation of the event handler for dealing with ami4ccm. This
 * event handler will auto-generate the necessary artifact so that
 * moders can correctly leverage ami4ccm support in CoSMIC.
 */
class AMI4CCM_Event_Handler :
  public GAME::Mga::Object_Event_Handler
{
public:
  /// Default constructor
  AMI4CCM_Event_Handler (void);

  /// Destructor.
  virtual ~AMI4CCM_Event_Handler (void);

  virtual int handle_object_created (GAME::Mga::Object_in obj);

  virtual int handle_object_attribute (GAME::Mga::Object_in obj);

private:
  /// Helper method to instantiate a AMI4CCM connector.
  int instantiate_connector (GAME::Mga::Object_in obj);
};
}
}

#endif  // !defined _PICML_MI_AMI4CCM_EVENT_HANDLER_H_
