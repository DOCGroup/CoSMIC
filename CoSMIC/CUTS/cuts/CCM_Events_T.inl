// $Id$

//=============================================================================
/*
 * CUTS_CCM_Event_T
 */
//=============================================================================

template <typename OBV_TYPE>
CUTS_INLINE
CUTS_CCM_Event_T <OBV_TYPE>::~CUTS_CCM_Event_T (void)
{

}

template <typename OBV_TYPE>
CUTS_INLINE
typename CUTS_CCM_Event_T <OBV_TYPE>::_ptr_type
CUTS_CCM_Event_T <OBV_TYPE>::in (void) const
{
  return this->event_.in ();
}

template <typename OBV_TYPE>
CUTS_INLINE
typename CUTS_CCM_Event_T <OBV_TYPE>::_ptr_type
CUTS_CCM_Event_T <OBV_TYPE>::operator -> (void) const
{
  return this->event_.in ();
}

//=============================================================================
/*
 * CUTS_Event_T
 */
//=============================================================================

template <typename EVENTTYPE>
CUTS_INLINE
::CORBA::Long CUTS_Event_T <EVENTTYPE>::event_id (void)
{
  return CUTS_Event_Info <EVENTTYPE>::event_id_;
}

//=============================================================================
/*
 * CUTS_Event_init_T
 */
//=============================================================================

//
// _downcast
//
template <typename EVENTTYPE>
CUTS_INLINE
CUTS_Event_init_T <EVENTTYPE> *
CUTS_Event_init_T <EVENTTYPE>::_downcast (CORBA::ValueFactoryBase * v)
{
  return dynamic_cast < CUTS_Event_init_T <EVENTTYPE> * > (v);
}

//
// tao_repository_id
//
template <typename EVENTTYPE>
CUTS_INLINE
const char * CUTS_Event_init_T <EVENTTYPE>::tao_repository_id (void)
{
  return Event_Type::_tao_obv_static_repository_id ();
}

