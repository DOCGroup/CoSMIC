// $Id$

namespace GME
{
template <typename T>
GME_INLINE
Event_Sink_T <T>::Event_Sink_T (void)
{

}

template <typename T>
GME_INLINE
Event_Sink_T <T>::~Event_Sink_T (void)
{

}

template <typename T>
GME_INLINE
int Event_Sink_T <T>::
handle_global_event (globalevent_enum global_event)
{
  return S_OK;
}

template <typename T>
GME_INLINE
int Event_Sink_T <T>::
handle_object_event (GME::Object & obj, unsigned long mask)
{
  return S_OK;
}

}
