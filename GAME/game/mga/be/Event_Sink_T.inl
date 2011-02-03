// $Id$

namespace GAME
{
template <typename T>
GAME_INLINE
Event_Sink_T <T>::Event_Sink_T (void)
{

}

template <typename T>
GAME_INLINE
Event_Sink_T <T>::~Event_Sink_T (void)
{

}

template <typename T>
GAME_INLINE
int Event_Sink_T <T>::
handle_global_event (globalevent_enum global_event)
{
  return S_OK;
}

template <typename T>
GAME_INLINE
int Event_Sink_T <T>::
handle_object_event (GAME::Object & obj, unsigned long mask)
{
  return S_OK;
}

}
