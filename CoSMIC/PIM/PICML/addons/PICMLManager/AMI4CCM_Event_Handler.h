// -*- C++ -*-

//=============================================================================
/**
 *  @file       AMI4CCM_Event_Handler.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_AMI4CCM_EVENT_HANDLER_H_
#define _PICML_MI_AMI4CCM_EVENT_HANDLER_H_

#include "game/be/Event_Handler_Impl.h"

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
class AMI4CCM_Event_Handler : public GAME::Event_Handler_Impl
{
public:
  /// Default constructor
  AMI4CCM_Event_Handler (void);

  /// Destructor.
  virtual ~AMI4CCM_Event_Handler (void);

  virtual int handle_object_attribute (GAME::Object obj);
};
}
}

#endif  // !defined _PICML_MI_AMI4CCM_EVENT_HANDLER_H_
