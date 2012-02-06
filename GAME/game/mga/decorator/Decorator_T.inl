// -*- C++ -*-
// $Id$

#include "game/mga/Project.h"
#include "game/mga/MetaPart.h"
#include "game/mga/FCO.h"

namespace GAME
{
namespace Mga
{

//
// Decorator_T
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
Decorator_T <T, pclsid>::Decorator_T (void)
: impl_ptr_ (&impl_),
  is_init_ (false),
  is_loc_set_ (false)
{

}

//
// ~Decorator_T
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
Decorator_T <T, pclsid>::~Decorator_T (void)
{

}

//
// GetMnemonic
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::GetMnemonic (BSTR *mnemonic)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  return S_OK;
}

//
// Draw
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::Draw (HDC hdc)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  try
  {
    std::auto_ptr <Gdiplus::Graphics> g (Gdiplus::Graphics::FromHDC (hdc));
    return this->impl_.draw (g.get ());
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// DrawEx
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::DrawEx (HDC hdc, ULONGLONG graphics)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  try
  {
    Gdiplus::Graphics * g = reinterpret_cast <Gdiplus::Graphics *> (graphics);
    return this->impl_.draw (g);
  }
  catch (const GAME::Mga::Failed_Result & )
  {

  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// GetFeatures
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::GetFeatures (feature_code *feat)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  *feat = this->impl_.features ();
  return S_OK;
}

//
// SetActive
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::SetActive (VARIANT_BOOL isActive)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  bool is_active = isActive == VARIANT_TRUE ? true : false;
  this->impl_.set_active (is_active);
  return S_OK;
}

//
// GetPreferredSize
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::GetPreferredSize (long* sx, long* sy)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  try
  {
    return 0 == this->impl_.get_preferred_size (*sx, *sy) ? S_OK : S_FALSE;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

//
// SaveState
//
template <typename T, const CLSID * pclsid>
STDMETHODIMP Decorator_T <T, pclsid>::SaveState (void)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  return 0 == this->impl_.save_state () ? S_OK : S_FALSE;
}

//
// SetSelected
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::SetSelected (VARIANT_BOOL vbIsSelected)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  bool is_selected = vbIsSelected == VARIANT_TRUE ? true : false;
  this->impl_.set_selected (is_selected);

  return S_OK;
}

//
// OperationCanceled
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::OperationCanceled (void)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  return this->impl_.operation_canceled ();
}

//
// GetLabelLocation
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::
GetLabelLocation (long *sx, long *sy, long *ex, long *ey)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  if (!this->is_loc_set_)
    return E_DECORATOR_LOCISNOTSET;

  return 0 == this->impl_.get_label_location (*sx, *sy, *ex, *ey) ? S_OK : S_FALSE;
}

//
// SetLocation
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::
SetLocation (long sx, long sy, long ex, long ey)
{
  if (!this->is_init_)
    return E_DECORATOR_UNINITIALIZED;

  try
  {
    GAME::Mga::Rect location (sx, sy, ex, ey);
    this->impl_.set_location (location);
    this->is_loc_set_ = true;

    return S_OK;
  }
  catch (...)
  {

  }

  return S_FALSE;
}

}
}
