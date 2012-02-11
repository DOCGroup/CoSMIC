// $Id$

#if !defined (__GAME_INLINE__)
#include "Addon_Impl_T.inl"
#endif

#include "Event_Sink.h"
#include "game/mga/Project.h"

namespace GAME
{
namespace Mga
{

//
// Addon_Impl_T
//
template <typename T, typename SINK>
Addon_Impl_T <T, SINK>::~Addon_Impl_T (void)
{
  //// Close the sink object, and then destroy the add-on.
  //this->sink_->close ();

  if (this->addon_)
  {
    // Destroy the addon. Once this is done, we have to detach
    // from both CComPtr since it destroys their objects as well.
    this->addon_->Destroy ();

    this->addon_.Detach ();
    this->sink_.Detach ();
  }
}

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
    this->sink_.Attach (new CComObject <Event_Sink> ());
    this->sink_->set_event_handler (&this->impl_);

    // Register the event handler with GME.
    VERIFY_HRESULT (proj->CreateAddOn (this->sink_, &this->addon_));
    VERIFY_HRESULT (this->addon_->put_EventMask (this->impl_.event_mask ()));

    return this->sink_->initialize (GAME::Mga::Project (proj));
  }
  catch (...)
  {
    return E_FAIL;
  }
}

//
// Enable
//
template <typename T, typename SINK>
STDMETHODIMP Addon_Impl_T <T, SINK>::Enable (VARIANT_BOOL enable)
{
  try
  {
    bool state = enable == VARIANT_TRUE ? true : false;
    this->sink_->enable (state);

    return S_OK;
  }
  catch (...)
  {
    return E_FAIL;
  }
}

}
}
