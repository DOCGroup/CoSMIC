// -*- C++ -*-
// $Id$

namespace GAME
{
//
// Decorator_T
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
Decorator_T <T, pclsid>::Decorator_T (void)
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
// Initialize
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::
Initialize (IMgaProject *project, IMgaMetaPart *metaPart, IMgaFCO *obj)
{
  GAME::Project proj (project);
  GAME::Meta::Part part (metaPart);
  GAME::FCO fco (obj);

  return this->impl_.initialize (proj, part, obj) == 0 ? S_OK : E_DECORATOR_INIT_WITH_NULL;
}

//
// InitializeEx
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::
InitializeEx (IMgaProject* project,
              IMgaMetaPart* pPart, 
              IMgaFCO* pFCO,
              IMgaCommonDecoratorEvents* eventSink, 
              ULONGLONG parentWnd)
{
  GAME::Project proj (project);
  GAME::Meta::Part part (pPart);
  GAME::FCO fco (pFCO);

  return this->impl_.initialize (proj, part, fco, eventSink, parentWnd);
}

//
// Destroy
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::Destroy (void)
{
  this->impl_.destroy ();
  return S_OK;
}

//
// GetMnemonic
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::GetMnemonic (BSTR *mnemonic)
{
  return S_OK;
}

//
// GetFeatures
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::GetFeatures (feature_code *feat)
{
  *feat = this->impl_.features ();
  return S_OK;
}

//
// SetActive
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::SetActive (VARIANT_BOOL isActive)
{
  bool is_active = isActive == VARIANT_TRUE ? true : false;
  this->impl_.set_active (is_active);
  return S_OK;
}

//
// GetPreferredSize
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::GetPreferredSize (long* sx, long* sy)
{
  return 0 == this->impl_.get_preferred_size (*sx, *sy) ? S_OK : S_FALSE;
}

//
// SaveState
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::SaveState (void)
{
  return 0 == this->impl_.save_state () ? S_OK : S_FALSE;
}

//
// SetSelected
//
template <typename T, const CLSID * pclsid>
GAME_INLINE
STDMETHODIMP Decorator_T <T, pclsid>::SetSelected (VARIANT_BOOL vbIsSelected)
{
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
  GAME::utils::Rect location (sx, sy, ex, ey);
  this->impl_.location (location);
  return S_OK;
}

}
