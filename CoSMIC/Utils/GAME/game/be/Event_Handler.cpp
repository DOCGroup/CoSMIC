// $Id$

#include "Event_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Event_Handler.inl"
#endif

namespace GAME
{
//
// initialize
//
GAME_INLINE
int Event_Handler::initialize (GAME::Project & project)
{
  if (0 != this->impl_)
    return this->impl_->initialize (project);

  return 0;
}

//
// GlobalEvent
//
STDMETHODIMP Event_Handler::GlobalEvent (globalevent_enum ev)
{
  if (0 != this->impl_)
    return this->impl_->handle_global_event (ev);

  return S_OK;
}

//
// ObjectEvent
//
STDMETHODIMP Event_Handler::
ObjectEvent (IMgaObject * obj, unsigned long eventmask, VARIANT v)
{
  if (0 != this->impl_)
    return this->impl_->handle_object_event (GAME::Object (obj), eventmask);

  return S_OK;
}

}
