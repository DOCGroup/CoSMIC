// $Id$

#if !defined (__GAME_INLINE__)
#include "Addon_Impl_T.inl"
#endif

#include "Event_Handler.h"
#include "game/Project.h"

namespace GAME
{
//
// initialize
//
template <typename T, typename SINK>
STDMETHODIMP Addon_Impl_T <T, SINK>::Initialize (IMgaProject * proj)
{
  // First, pass control to the base class.
  HRESULT hr = ComponentEx_Impl_T <T>::Initialize (proj);

  if (FAILED (hr))
    return hr;

  try
  {
    // Create a new event handler for this add-on.
    Event_Handler * handler = new CComObject <Event_Handler> ();
    handler->attach (&this->impl_);
    this->sink_.Attach (handler);

    // Register the event handler with GME.
    VERIFY_HRESULT (proj->CreateAddOn (this->sink_, &this->addon_));
    VERIFY_HRESULT (this->addon_->put_EventMask (this->impl_.event_mask ()));

    return handler->initialize (GAME::Project (proj));
  }
  catch (...)
  {
    return S_FALSE;
  }
}

//
// Addon_Impl_T
//
template <typename T, typename SINK>
Addon_Impl_T <T, SINK>::~Addon_Impl_T (void)
{
  if (this->addon_)
  {
    HRESULT hr = this->addon_->Destroy ();

    if (hr == S_OK)
      this->sink_.Detach ();
  }
}

}
