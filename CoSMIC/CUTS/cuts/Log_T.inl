// -*- C++ -*-
// $Id$

//
// CUTS_Log_T
//
template <typename T, typename LOCK>
CUTS_INLINE
CUTS_Log_T <T, LOCK>::CUTS_Log_T (size_t size, bool auto_grow)
: ACE_Array_Base <T> (size),
  used_ (0),
  auto_grow_ (auto_grow)
{

}

//
// ~CUTS_Log_T
//
template <typename T, typename LOCK>
CUTS_INLINE
CUTS_Log_T <T, LOCK>::~CUTS_Log_T (void)
{

}

//
// free_size
//
template <typename T, typename LOCK>
CUTS_INLINE
size_t CUTS_Log_T <T, LOCK>::free_size (void) const
{
  return this->cur_size_ - this->used_;
}

//
// used_size
//
template <typename T, typename LOCK>
CUTS_INLINE
size_t CUTS_Log_T <T, LOCK>::used_size (void) const
{
  return this->used_;
}

//
// reset
//
template <typename T, typename LOCK>
CUTS_INLINE
void CUTS_Log_T <T, LOCK>::reset (void)
{
  this->used_ = 0;
}

//
// lock
//
template <typename T, typename LOCK>
CUTS_INLINE
LOCK & CUTS_Log_T <T, LOCK>::lock (void)
{
  return this->lock_;
}

//
// next_free_record_i
//
template <typename T, typename LOCK>
CUTS_INLINE
T * CUTS_Log_T <T, LOCK>::next_free_record_i (void)
{
  return &(this->array_[this->used_ ++]);
}
