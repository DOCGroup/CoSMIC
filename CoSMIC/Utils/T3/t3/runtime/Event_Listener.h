#ifndef _T3_EVENT_LISTENER_H_
#define _T3_EVENT_LISTENER_H_

#include "Runtime_export.h"
#include "game/Object.h"

class T3_RUNTIME_Export T3_Event_Listener
{
public:
  T3_Event_Listener (void);

  virtual ~T3_Event_Listener (void);

  virtual void handle_open_model (GME::Object &);

  virtual void handle_close_model (GME::Object & obj);

  virtual void handle_new_object (GME::Object & obj);

  virtual void handle_delete_object (GME::Object & obj);
};

#include "Event_Listener.inl"

#endif
