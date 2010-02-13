// $Id$

#if !defined (__GME_INLINE__)
#include "Event_Sink_T.inl"
#endif

#include "Event_Sink_Impl.h"
#include "game/Object.h"

namespace GME
{
//
// GlobalEvent
//
template <typename T>
STDMETHODIMP Event_Sink_T <T>::GlobalEvent (globalevent_enum global_event)
{
  try
  {
    return this->handle_global_event (global_event) == 0 ? S_OK : S_FALSE;
  }
  catch (GME::Exception & )
  {
    // catch the exception
  }
  catch (...)
  {
    // prevent GME from crashing...
  }

  return S_FALSE;
}

//
// ObjectEvent
//
template <typename T>
STDMETHODIMP Event_Sink_T <T>::
ObjectEvent (IMgaObject * obj, unsigned long mask, VARIANT v)
{
  try
  {
    GME::Object temp_obj (obj);
    return this->handle_object_event (temp_obj, mask) == 0 ? S_OK : S_FALSE;
  }
  catch (GME::Exception & )
  {
    // catch the exception
  }
  catch (...)
  {
    // prevent GME from crashing...
  }

  return S_FALSE;
}

}
