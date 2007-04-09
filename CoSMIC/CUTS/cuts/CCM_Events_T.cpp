// $Id$

#if !defined (__CUTS_INLINE__)
# include "cuts/CCM_Events_T.inl"
#endif

//=============================================================================
/*
 * CUTS_CCM_Event_T
 */
//=============================================================================

template <typename OBV_TYPE>
CUTS_CCM_Event_T <OBV_TYPE>::CUTS_CCM_Event_T (void)
{
  _ptr_type ev = 0;
  ACE_NEW_THROW_EX (ev, OBV_TYPE (), ::CORBA::NO_MEMORY ());
  this->event_ = ev;
}

//=============================================================================
/*
 * CUTS_Event_T
 */
//=============================================================================

template <typename EVENTTYPE>
CUTS_Event_T <EVENTTYPE>::CUTS_Event_T (void)
{

}

template <typename EVENTTYPE>
CUTS_Event_T <EVENTTYPE>::~CUTS_Event_T (void)
{

}

//=============================================================================
/*
 * CUTS_Event_init_T
 */
//=============================================================================

//
// CUTS_Event_init_T
//
template <typename EVENTTYPE>
CUTS_Event_init_T <EVENTTYPE>::CUTS_Event_init_T (void)
{

}

//
// ~CUTS_Event_init_T
//
template <typename EVENTTYPE>
CUTS_Event_init_T <EVENTTYPE>::~CUTS_Event_init_T (void)
{

}

template <typename EVENTTYPE>
CORBA::ValueBase *
CUTS_Event_init_T <EVENTTYPE>::create_for_unmarshal (void)
{
  CORBA::ValueBase *ret_val = 0;
  ACE_NEW_THROW_EX (ret_val, EVENTTYPE, ::CORBA::NO_MEMORY ());
  return ret_val;
}
