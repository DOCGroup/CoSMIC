// -*- C++ -*-

//=============================================================================
/**
 * @file    EventHandler_T.h
 *
 * $Id$
 */
//=============================================================================

#ifndef _CUTS_EVENT_HANDLER_T_H_
#define _CUTS_EVENT_HANDLER_T_H_

#include "cuts/EventGuard.h"

template <typename COMPONENT>
class CUTS_Export CUTS_Event_Handler_T
{
public:
  typedef COMPONENT Component_Type;

  CUTS_Event_Handler_T (void);

  virtual ~CUTS_Event_Handler_T (void);

  void handle_event (long id);

  bool register_guard (const char *name, 
                       CUTS_Event_Guard_T <Component_Type> * work);

  void unregister_guard (const char * name);
};

#endif  // !defined _CUTS_EVENT_HANDLER_T_H_
